# include <cmath>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "asa082.hpp"

//****************************************************************************80

void detq ( double a[], int n, double *d, int *ifault )

//****************************************************************************80
//
//  Purpose:
//
//    detq computes the determinant of an orthogonal matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 January 2020
//
//  Author:
//
//    Original FORTRAN77 version by J C Gower.
//    This C++ version by John Burkardt
//
//  Reference:
//
//    J C Gower,
//    Algorithm AS 82:
//    The determinant of an orthogonal matrix,
//    Applied Statistics,
//    Volume 24, Number 1, 1975, page 150-153.
//
//  Input:
//
//    double A[N*N], the orthogonal matrix stored by rows or columns.
//
//    int N, the order of the matrix.
//
//  Output:
//
//    double *D, the determinant of A.
//
//    integer *IFAULT, 
//    0, no error occurred.
//    1, an error was detected.
//
{
  double *a2;
  int i;
  int j;
  int k;
  int p;
  int q;
  int r;
  int s;
  double tol;
  double x;
  double y;

  *d = 0.0;
  *ifault = 0;
  tol = 0.0001;

  if ( n <= 0 )
  {
    cout << "\n";
    cout << "detq - Fatal error!\n";
    cout << "  n <= 0\n";
    *ifault = 1;
    return;
  }

  a2 = new double[n*n];

  for ( k = 0; k < n * n; k++ )
  {
    a2[k] = a[k];
  }

  *d = 1.0;
  r = 0;

  for ( k = 2; k <= n + 1; k++ )
  {
    q = r;
    x = a2[r];
    if ( x < 0.0 )
    {
      y = - 1.0;
    }
    else
    {
      y = + 1.0;
    }
    *d = *d * y;
    y = - 1.0 / ( x + y );
    x = fabs ( x ) - 1.0;

    if ( tol < fabs ( x ) )
    {
      if ( 0.0 < x )
      {
        cout << "\n";
        cout << "detq - Fatal error!\n";
        cout << "  x < 0.0\n";
        cout << "  x = " << x << "\n";
        *ifault = 1;
        return;
      }

      if ( k == n + 1 )
      {
        cout << "\n";
        cout << "detq - Fatal error!\n";
        cout << "  k == n + 1\n";
        *ifault = 1;
        return;
      }

      for ( i = k; i <= n; i++ )
      {
        q = q + n;
        x = a2[q] * y;
        p = r;
        s = q;
        for ( j = k; j <= n; j++ )
        {
          p = p + 1;
          s = s + 1;
          a2[s] = a2[s] + x * a2[p];
        }
      }
    }
    r = r + n + 1;
  }

  delete [] a2;

  return;
}
//****************************************************************************80

void r8mat_print ( int m, int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT prints an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//    Entry A(I,J) is stored as A[I+J*M]
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows in A.
//
//    Input, int N, the number of columns in A.
//
//    Input, double A[M*N], the M by N matrix.
//
//    Input, string TITLE, a title.
//
{
  r8mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
//****************************************************************************80

void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT_SOME prints some of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Input, int ILO, JLO, IHI, JHI, designate the first row and
//    column, and the last row and column to be printed.
//
//    Input, string TITLE, a title.
//
{
# define INCX 5

  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  cout << "\n";
  cout << title << "\n";

  if ( m <= 0 || n <= 0 )
  {
    cout << "\n";
    cout << "  (None)\n";
    return;
  }
//
//  Print the columns of the matrix, in strips of 5.
//
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    if ( n < j2hi )
    {
      j2hi = n;
    }
    if ( jhi < j2hi )
    {
      j2hi = jhi;
    }
    cout << "\n";
//
//  For each column J in the current range...
//
//  Write the header.
//
    cout << "  Col:    ";
    for ( j = j2lo; j <= j2hi; j++ )
    {
      cout << setw(7) << j - 1 << "       ";
    }
    cout << "\n";
    cout << "  Row\n";
    cout << "\n";
//
//  Determine the range of the rows in this strip.
//
    if ( 1 < ilo )
    {
      i2lo = ilo;
    }
    else
    {
      i2lo = 1;
    }
    if ( ihi < m )
    {
      i2hi = ihi;
    }
    else
    {
      i2hi = m;
    }

    for ( i = i2lo; i <= i2hi; i++ )
    {
//
//  Print out (up to) 5 entries in row I, that lie in the current strip.
//
      cout << setw(5) << i - 1 << ": ";
      for ( j = j2lo; j <= j2hi; j++ )
      {
        cout << setw(12) << a[i-1+(j-1)*m] << "  ";
      }
      cout << "\n";
    }
  }

  return;
# undef INCX
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

