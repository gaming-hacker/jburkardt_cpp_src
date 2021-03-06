# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int main ( int argc, char *argv[] );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for MATVEC.
//
//  Discussion:
//
//    MATVEC uses MPI to compute a matrix-vector product b = A * x.
//
//    This is the simple self-scheduling version.  Each worker is given 
//    a copy of x, and then is fed one row of A.  As soon as it computes 
//    B(I) = A(I,1:N)*x(1:N), it is given another column of A, unless
//    there are no more, in which case it is sent a "terminate" message. 
//    Thus, a faster process will be given more work to do.
//
//    By using allocatable arrays, the amount of memory used has been
//    controlled.  The master process allocates A and x, but the worker
//    processes only allocate enough memory for one row of A, and x.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 June 2016
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Gropp, Ewing Lusk, Anthony Skjellum,
//    Using MPI: Portable Parallel Programming with the
//    Message-Passing Interface,
//    Second Edition,
//    MIT Press, 1999,
//    ISBN: 0262571323.
//
//    Snir, Otto, Huss-Lederman, Walker, Dongarra,
//    MPI - The Complete Reference,
//    Volume 1, The MPI Core,
//    second edition,
//    MIT Press, 1998.
//
{
  double *a;
  double *a_row;
  double ans;
  double *b;
  int dest;
  int dummy;
  int i;
  int id;
  int ierr;
  int j;
  int j_one;
  int k;
  int m;
  static int master = 0;
  int n;
  int num_rows;
  int num_workers;
  int p;
  double r8_pi = 3.141592653589793;
  MPI_Status status;
  int tag;
  int tag_done;
  double *x;
//
//  Initialize MPI.
//
  ierr = MPI_Init ( &argc, &argv );

  if ( ierr != 0 )
  {
    cout << "\n";
    cout << "MATVEC:\n";
    cout << "  MPI_Init returned ierr = " << ierr << "\n";
    exit ( 1 );
  }
//
//  Get this processor's ID.
//
  ierr = MPI_Comm_rank ( MPI_COMM_WORLD, &id );
//
//  Get the number of processors.
//
  ierr = MPI_Comm_size ( MPI_COMM_WORLD, &p );

  if ( id == 0 ) 
  {
    timestamp ( );
    cout << "\n";
    cout << "MATVEC - Master process:\n";
    cout << "  C++ version\n";
    cout << "  An MPI example program to compute\n";
    cout << "  a matrix-vector product b = A * x.\n";
    cout << "\n";
    cout << "  Compiled on " << __DATE__ " at " << __TIME__ "\n";
    cout << "\n";
    cout << "  The number of processes is " << p << ".\n";
  }
  cout << "\n";
  cout << "Process " << id << " is active.\n";

  m = 100;
  n = 50;

  tag_done = m + 1;

  if ( id == 0 ) 
  {
    cout << "\n";
    cout << "  The number of rows is    " << m << "\n";
    cout << "  The number of columns is " << n << "\n";
  }
//
//  The master process allocates and initializes A and x.
//
//  Because we are dynamically allocating A, we can't use 2D array double
//  indexing, so we have to figure out where we are on our own.
//
  if ( id == 0 )
  {
    a = new double[m*n];
    x = new double[n];
    b = new double[m];

    k = 0;
    for ( i = 1; i <= m; i++ ) 
    {
      for ( j = 1; j <= n; j++ )
      {
        a[k] = sqrt ( 2.0 / ( double ) ( n + 1 ) ) 
          * sin ( ( double ) ( i * j ) * r8_pi / ( double ) ( n + 1 ) );
        k = k + 1;
      }
    }
//
//  X is specially chosen so that b = A * x is known in advance.
//  The value of B will be zero, except that entry J_ONE will be 1.
//  Pick any value of J_ONE between 1 and M.
//
    j_one = 17;
    for ( i = 0; i < n; i++ )
    {
      x[i] = sqrt ( 2.0 / ( double ) ( n + 1 ) ) 
        * sin ( ( double ) ( ( i + 1 ) * j_one ) * r8_pi / ( double ) ( n + 1 ) );
    }

    cout << "\n";
    cout << "MATVEC - Master process:\n";
    cout << "  Vector x\n";
    cout << "\n";
    for ( i = 0; i < n; i++ )
    {
      cout << setw(6) << i << "  "
           << setw(10) << x[i] << "\n";
    }
  }
//
//  Worker processes set aside room for one row of A, and for the 
//  vector x.
//
  else
  {
    a_row = new double[n];
    x = new double[n];
  }
//
//  Process 0 broadcasts the vector X to the other processes.
//
  ierr = MPI_Bcast ( x, n, MPI_DOUBLE, master, MPI_COMM_WORLD );

  if ( id == 0 )
//
//  Process 0 sends one row of A to all the other processes.
//
//  If we were using standard 2D array storage, the entries of
//  the row would be contiguous; using pointers, we have ended up
//  in the same situation.  As long as the entries are contiguous,
//  we can use a simple standard datatype with MPI_Send.  
//
//  The situation would require a little more work if we tried
//  to send a column of data instead of a row.
//
  {
    num_rows = 0;

    for ( i = 1; i <= p-1; i++ )
    {
      dest = i;
      tag = num_rows;
      k = num_rows * n;

      ierr = MPI_Send ( a+k, n, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD );

      num_rows = num_rows + 1;
    }
     
    num_workers = p-1;

    for ( ; ; )
    {
      ierr = MPI_Recv ( &ans, 1, MPI_DOUBLE, MPI_ANY_SOURCE,
        MPI_ANY_TAG, MPI_COMM_WORLD, &status );

      tag = status.MPI_TAG;
      b[tag] = ans;

      if ( num_rows < m )
      {
        num_rows = num_rows + 1;
        dest = status.MPI_SOURCE;
        tag = num_rows;
        k = num_rows * n;

        ierr = MPI_Send ( a+k, n, MPI_DOUBLE, dest, tag, MPI_COMM_WORLD );
      }
      else
      {
        num_workers = num_workers - 1;
        dummy = 0;
        dest = status.MPI_SOURCE;
        tag = tag_done;

        ierr = MPI_Send ( &dummy, 1, MPI_INT, dest, tag, MPI_COMM_WORLD );

        if ( num_workers == 0 )
        {
          cout << "  Process " << id << " shutting down.\n";
          break;
        }
      }

    }

    delete [] a;
    delete [] x;
  }
//
//  Each worker process repeatedly receives rows of A (with TAG indicating
//  which row it is), computes dot products A(I,1:N) * X(1:N) and returns
//  the result (and TAG), until receiving the "DONE" message.
//
  else
  {
    for ( ; ; )
    {
      ierr = MPI_Recv ( a_row, n, MPI_DOUBLE, master, MPI_ANY_TAG,
        MPI_COMM_WORLD, &status );

      tag = status.MPI_TAG;

      if ( tag == tag_done ) 
      {
        cout << "  Process " << id << " shutting down.\n";
        break;
      }

      ans = 0.0;
      for ( i = 0; i < n; i++ )
      {
        ans = ans + a_row[i] * x[i];
      }

      ierr = MPI_Send ( &ans, 1, MPI_DOUBLE, master, tag, MPI_COMM_WORLD );
    }

    delete [] a_row;
    delete [] x;
  }
//
//  Print out the answer.
//
  if ( id == 0 ) 
  {
    cout << "\n";
    cout << "MATVEC - Master process:\n";
    cout << "  Product vector b = A * x\n";
    cout << "  (Should be zero, except for a 1 in entry " << j_one-1 << "\n";
    cout << "\n";
    for ( i = 0; i < m; i++ )
    {
      cout << setw(4) << i << "  "
           << setw(10) << b[i] << "\n";
    }

    delete [] b;
  }
//
//  Terminate MPI.
//
  MPI_Finalize ( );
//
//  Terminate.
//
  if ( id == 0 ) 
  {
    cout << "\n";
    cout << "MATVEC - Master process:\n";
    cout << "  Normal end of execution.\n";
    cout << "\n";
    timestamp ( );
  }
  return 0;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    31 May 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    None
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
