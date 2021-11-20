# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int main ( int argc, char *argv[] );
double f ( double x );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for INTERVALS.
//
//  Discussion:
//
//    INTERVALS uses MPI routines to multiprocess a computational task.
//
//    We have a function F(X), an interval [XMIN,XMAX], 
//    and a value N.
//
//    We define N equally spaced points in the interval,
//
//      X(I) = ( ( N - I     ) * XMIN 
//             + (     I - 1 ) * XMAX ) 
//             / ( N     - 1 )
//
//    We thus have N-1 subintervals.
//
//    We assume we have N processors available.
//
//    Processor 0 is designated the master processor, assigned
//    to estimating the integral of F(X) over the entire
//    interval [ X(1), X(N) ].
//
//    For I = 1 to N-1, processor I is assigned the subinterval
//
//      [ X(I), X(I+1) ]
//
//    and then estimates the integral Q(I) of F(X) over that
//    subinterval.
//
//    COMMUNICATION:
//
//    Processor 0 communicates to processor I the endpoints of 
//    the interval it is assigned, and the number of sample points
//    to use in that interval.
//
//    Processor I communicates to processor 0 the computed value of
//    Q(I).
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
  double end_time;
  int i;
  int id;
  int ierr;
  int m;
  int p;
  double r8_pi = 3.141592653589793238462643;
  int process;
  double q_global;
  double q_local;
  int received;
  int source;
  double start_time;
  MPI_Status status;
  int tag;
  int target;
  double x;
  double xb[2];
  double x_max = 1.0;
  double x_min = 0.0;
//
//  Establish the MPI environment.
//
  ierr = MPI_Init ( &argc, &argv );

  if ( ierr != 0 )
  {
    cout << "\n";
    cout << "INTERVALS_MPI - Fatal error!";
    cout << "  MPI_Init returned ierr = " << ierr << "\n";
    exit ( 1 );
  }
//
//  Determine this processes's rank.
//
  ierr = MPI_Comm_rank ( MPI_COMM_WORLD, &id );
//
//  Get the number of processes.
//
  ierr = MPI_Comm_size ( MPI_COMM_WORLD, &p );
//
//  Say hello (once), and shut down right away unless we
//  have at least 2 processes available.
//
  if ( id == 0 )
  {
    timestamp ( );
    cout << "\n";
    cout << "INTERVALS - Master process:\n";
    cout << "  C++ version\n";
    cout << "\n";
    cout << "  An MPI example program,\n";
    cout << "  A quadrature over an interval is done by\n";
    cout << "  assigning subintervals to processes.\n";
    cout << "\n";
    cout << "  The number of processes is " << p << "\n";

    start_time = MPI_Wtime ( );

    if ( p <= 1 )
    {
      cout << "\n";
      cout << "INTERVALS - Master process:\n";
      cout << "  Need at least 2 processes!\n";
      MPI_Finalize ( );
      cout << "\n";
      cout << "INTERVALS - Master process:\n";
      cout << "  Abnormal end of execution.\n";
      exit ( 1 );
    }
  }

  cout << "\n";
  cout << "Process " << id << ": Active!\n";
//
//  Every process could figure out the endpoints of its interval
//  on its own.  But we want to demonstrate communication.  So we
//  assume that the assignment of processes to intervals is done
//  only by the master process, which then tells each process
//  what job it is to do.
//
  if ( id == 0 )
  {
    for ( process = 1; process <= p-1; process++ )
    {
      xb[0] = ( ( double ) ( p - process     ) * x_min   
              + ( double ) (     process - 1 ) * x_max ) 
              / ( double ) ( p           - 1 );

      xb[1] = ( ( double ) ( p - process - 1 ) * x_min   
              + ( double ) (     process     ) * x_max ) 
              / ( double ) ( p           - 1 );
 
      target = process;
      tag = 1;

      ierr = MPI_Send ( xb, 2, MPI_DOUBLE, target, tag, MPI_COMM_WORLD );
    }
  }
  else
  {
    source = 0;
    tag = 1;

    ierr = MPI_Recv ( xb, 2, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, &status );
  }
//
//  Wait here until everyone has gotten their assignment.
//
  ierr = MPI_Barrier ( MPI_COMM_WORLD );

  if ( id == 0 )
  {
    cout << "\n";
    cout << "INTERVALS - Master process:\n";
    cout << "  Subintervals have been assigned.\n";
  }
//
//  Every process needs to be told the number of points to use.
//  Since this is the same value for everybody, we use a broadcast.
//  Again, we are doing it in this roundabout way to emphasize that
//  the choice for M could really be made at runtime, by processor 0,
//  and then sent out to the others.
//
  m = 100;
  source = 0;

  ierr = MPI_Bcast ( &m, 1, MPI_INT, source, MPI_COMM_WORLD );
//
//  Now, every process EXCEPT 0 computes its estimate of the 
//  integral over its subinterval, and sends the result back
//  to process 0.
//
  if ( id != 0 )
  {  
    q_local = 0.0;

    for ( i = 1; i <= m; i++ )
    {
      x = ( ( double ) ( 2 * m - 2 * i + 1 ) * xb[0]   
          + ( double ) (         2 * i - 1 ) * xb[1] ) 
          / ( double ) ( 2 * m             );

      q_local = q_local + f ( x );
    }

    q_local = q_local * ( xb[1] - xb[0] ) / ( double ) ( m );

    target = 0;
    tag = 2;

    ierr = MPI_Send ( &q_local, 1, MPI_DOUBLE, target, tag, MPI_COMM_WORLD );
  }
//
//  Process 0 expects to receive N-1 partial results.
//
  else
  {
    received = 0;
    q_global = 0.0;

    while ( received < p - 1 )
    {
      source = MPI_ANY_SOURCE;
      tag = 2;

      ierr = MPI_Recv ( &q_local, 1, MPI_DOUBLE, source, tag, MPI_COMM_WORLD, 
        &status );

      q_global = q_global + q_local;
      received = received + 1;
    }
  }
//
//  The master process prints the answer.
//
  if ( id == 0 )
  {
    cout << "\n";
    cout << "INTERVALS - Master process:\n";
    cout << "  Estimate for PI is " << q_global         << "\n";
    cout << "  Error is           " << q_global - r8_pi << "\n";

    end_time = MPI_Wtime ( );

    cout << "\n";
    cout << "  Elapsed wall clock seconds = " 
         << end_time - start_time << "\n";
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
    cout << "INTERVALS - Master process:\n";         
    cout << "  Normal end of execution.\n";
    cout << "\n";
    timestamp ( );   
  }
  return 0;
}
//****************************************************************************80

double f ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F evaluates the function F(X) which we are integrating.
//
//  Discussion:
//
//    Integral ( 0 <= X <= 1 ) 1/(1+X*X) dX = PI/4
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 March 2006
//
//  Author:
//
//    John Burkardt
//
{
  double value;

  value = 4.0 / ( 1.0 + x * x );

  return value;
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
