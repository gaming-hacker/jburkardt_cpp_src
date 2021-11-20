# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "hankel_cholesky.hpp"

//****************************************************************************80

double *hankel_cholesky_upper ( int n, double h[] )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL_CHOLESKY_UPPER computes the upper Cholesky factor of a Hankel matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 January 2017
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    James Phillips,
//    The triangular decomposition of Hankel matrices,
//    Mathematics of Computation,
//    Volume 25, Number 115, July 1971, pages 599-602.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double H[2*N-1], the values defining the antidiagonals.
//
//    Output, double HANKEL_CHOLESKY_UPPER[N*N], the upper triangular 
//    Cholesky factor.
//
{
  double a;
  double b;
  double *c;
  int i;
  int j;
  double *r;
  double t;

  c = new double[(2*n-1)*(2*n-1)];

  for ( j = 0; j < 2 * n - 1; j++ )
  {
    c[0+j*(2*n-1)] = h[j];
  }

  for ( i = 0; i < n - 1; i++ )
  {
    if ( i == 0 )
    {
      a = c[0+1*(2*n-1)] / c[0+0*(2*n-1)];
      b = 0.0;
    }
    else
    {
      a = c[i+(i+1)*(2*n-1)] / c[i+i*(2*n-1)] - c[i-1+i*(2*n-1)] / c[i-1+(i-1)*(2*n-1)];
      b = c[i+i*(2*n-1)] / c[i-1+(i-1)*(2*n-1)];
    }

    for ( j = i + 1; j < 2 * n - i - 2; j++ )
    {
      c[i+1+j*(2*n-1)] = c[i+(j+1)*(2*n-1)] - a * c[i+j*(2*n-1)];
      if ( 0 < i )
      {
        c[i+1+j*(2*n-1)] = c[i+1+j*(2*n-1)] - b * c[i-1+j*(2*n-1)];
      }
    }
  }

  r = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      r[i+j*n] = c[i+j*(2*n-1)];
    }
  }
//
//  Normalize.
//  This will fail if H is not positive definite.
//
  for ( i = 0; i < n; i++ )
  {
    t = sqrt ( r[i+i*n] );
    for ( j = 0; j < i; j++ )
    {
      r[i+j*n] = 0.0;
    }
    for ( j = i; j < n; j++ )
    {
      r[i+j*n] = r[i+j*n] / t;
    }
  }

  delete [] c;

  return r;
}
//****************************************************************************80

double *hankel_spd_cholesky_lower ( int n, double lii[], double liim1[] )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL_SPD_CHOLESKY_LOWER returns L such that L*L' is Hankel SPD.
//
//  Discussion:
//
//    In other words, H = L * L' is a symmetric positive definite matrix
//    with the property that H is constant along antidiagonals, so that
//
//      H(I+J) = h(k-1), for 1 <= I, J <= N, 1 <= K <= 2*N-1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 January 2017
//
//  Author:
//
//    S Al-Homidan, M Alshahrani.
//    C++ implementation by John Burkardt.
//
//  Reference:
//
//    S Al-Homidan, M Alshahrani,
//    Positive Definite Hankel Matrices Using Cholesky Factorization,
//    Computational Methods in Applied Mathematics,
//    Volume 9, Number 3, pages 221-225, 2009.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double LII[N], values to be used in L(I,I), 
//    for 1 <= I <= N.
//
//    Input, double LIIM1[N-1], values to be used in L(I+1,I) 
//    for 1 <= I <= N-1.
//
//    Output, double HANKEL_SPD_CHOLESKY_LOWER[N,N], the lower 
//    Cholesky factor.
//
{
  double alpha;
  double beta;
  int i;
  int j;
  double *l;
  int q;
  int r;
  int s;
  int t;

  l = r8mat_zeros_new ( n, n );

  for ( i = 0; i < n; i++ )
  {
    l[i+i*n] = lii[i];
  }

  for ( i = 0; i < n - 1; i++ )
  {
    l[i+1+i*n] = liim1[i];
  }

  for ( i = 2; i < n; i++ )
  {
    for ( j = 0; j < i - 1; j++ )
    {
      if ( ( ( i + j ) % 2 ) == 0 )
      {
        q = ( i + j ) / 2;
        r = q;
      }
      else
      {
        q = ( i + j - 1 ) / 2;
        r = q + 1;
      }

      alpha = 0.0;
      for ( s = 0; s <= q; s++ )
      {
        alpha = alpha + l[q+s*n] * l[r+s*n];
      }

      beta = 0.0;
      for ( t = 0; t < j; t++ )
      {
        beta = beta + l[i+t*n] * l[j+t*n];
      }

      l[i+j*n] = ( alpha - beta ) / l[j+j*n];
    }
  }

  return l;
}
//****************************************************************************80

double r8_epsilon ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_EPSILON returns the R8 roundoff unit.
//
//  Discussion:
//
//    The roundoff unit is a number R which is a power of 2 with the
//    property that, to the precision of the computer's arithmetic,
//      1 < 1 + R
//    but
//      1 = ( 1 + R / 2 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 September 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double R8_EPSILON, the R8 round-off unit.
//
{
  const double value = 2.220446049250313E-016;

  return value;
}
//****************************************************************************80

double *r8mat_cholesky_factor ( int n, double a[], int &flag )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_CHOLESKY_FACTOR computes the Cholesky factor of a symmetric R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//    The matrix must be symmetric and positive semidefinite.
//
//    For a positive semidefinite symmetric matrix A, the Cholesky factorization
//    is a lower triangular matrix L such that:
//
//      A = L * L'
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 November 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of rows and columns of the matrix A.
//
//    Input, double A[N*N], the N by N matrix.
//
//    Output, int &FLAG, an error flag.
//    0, no error occurred.
//    1, the matrix is not positive definite.
//    2, the matrix is not nonnegative definite.
//
//    Output, double R8MAT_CHOLESKY_FACTOR[N*N], the N by N lower triangular
//    Cholesky factor.
//
{
  double *c;
  int i;
  int j;
  int k;
  double sum2;
  double tol;

  flag = 0;
  tol = sqrt ( r8_epsilon ( ) );

  c = r8mat_copy_new ( n, n, a );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      c[i+j*n] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      sum2 = c[j+i*n];
      for ( k = 0; k < j; k++ )
      {
        sum2 = sum2 - c[j+k*n] * c[i+k*n];
      }
      if ( i == j )
      {
        if ( 0.0 < sum2 )
        {
          c[i+j*n] = sqrt ( sum2 );
        }
        else if ( sum2 < - tol )
        {
          flag = 2;
          cerr << "\n";
          cerr << "R8MAT_CHOLESKY_FACTOR - Fatal error!\n";
          cerr << "  Matrix is not nonnegative definite.\n";
          cerr << "  Diagonal I = " << i << "\n";
          cerr << "  SUM2 = " << sum2 << "\n";
          exit ( 1 );
        }
        else
        {
          flag = 1;
          c[i+j*n] = 0.0;
        }
      }
      else
      {

        if ( c[j+j*n] != 0.0 )
        {
          c[i+j*n] = sum2 / c[j+j*n];
        }
        else
        {
          c[i+j*n] = 0.0;
        }
      }
    }
  }

  return c;
}
//****************************************************************************80

double *r8mat_cholesky_factor_upper ( int n, double a[], int &flag )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_CHOLESKY_FACTOR_UPPER: upper Cholesky factor of a symmetric R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//    The matrix must be symmetric and positive semidefinite.
//
//    For a positive semidefinite symmetric matrix A, the Cholesky factorization
//    is an upper triangular matrix R such that:
//
//      A = R' * R
//
//    Note that the usual Cholesky factor is a LOWER triangular matrix L
//    such that
//
//      A = L * L'
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 August 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of rows and columns of the matrix A.
//
//    Input, double A[N*N], the N by N matrix.
//
//    Output, int &FLAG, an error flag.
//    0, no error occurred.
//    1, the matrix is not positive definite.  A NULL factor is returned.
//
//    Output, double R8MAT_CHOLESKY_FACTOR[N*N], the N by N upper triangular
//    Cholesky factor.
//
{
  double *c;
  int i;
  int j;
  int k;
  double sum2;

  flag = 0;

  c = r8mat_copy_new ( n, n, a );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      c[j+i*n] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      sum2 = c[i+j*n];
      for ( k = 0; k < j; k++ )
      {
        sum2 = sum2 - c[k+j*n] * c[k+i*n];
      }
      if ( i == j )
      {
        if ( sum2 <= 0.0 )
        {
          flag = 1;
          return NULL;
        }
        c[j+i*n] = sqrt ( sum2 );
      }
      else
      {
        if ( c[j+j*n] != 0.0 )
        {
          c[j+i*n] = sum2 / c[j+j*n];
        }
        else
        {
          c[j+i*n] = 0.0;
        }
      }
    }
  }

  return c;
}
//****************************************************************************80

double *r8mat_copy_new ( int m, int n, double a1[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_COPY_NEW copies one R8MAT to a "new" R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8's, which
//    may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, double A1[M*N], the matrix to be copied.
//
//    Output, double R8MAT_COPY_NEW[M*N], the copy of A1.
//
{
  double *a2;
  int i;
  int j;

  a2 = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }
  return a2;
}
//****************************************************************************80

double *r8mat_mmt_new ( int n1, int n2, int n3, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_MMT_NEW computes C = A * B'.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//    For this routine, the result is returned as the function value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 November 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N1, N2, N3, the order of the matrices.
//
//    Input, double A[N1*N2], double B[N3*N2], the matrices to multiply.
//
//    Output, double R8MAT_MMT_NEW[N1*N3], the product matrix C = A * B'.
//
{
  double *c;
  int i;
  int j;
  int k;

  c = new double[n1*n3];

  for ( i = 0; i < n1; i++ )
  {
    for ( j = 0; j < n3; j++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[i+k*n1] * b[j+k*n3];
      }
    }
  }

  return c;
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

double *r8mat_zeros_new ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_ZEROS_NEW returns a new zeroed R8MAT.
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
//    03 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Output, double R8MAT_ZEROS_NEW[M*N], the new zeroed matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = 0.0;
    }
  }
  return a;
}
//****************************************************************************80

double *r8vec_uniform_01_new ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01_NEW returns a new unit pseudorandom R8VEC.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
//      u = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Second Edition,
//    Springer, 1987,
//    ISBN: 0387964673,
//    LC: QA76.9.C65.B73.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, December 1986, pages 362-376.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998,
//    ISBN: 0471134031,
//    LC: T57.62.H37.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, Number 2, 1969, pages 136-143.
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input/output, int &SEED, a seed for the random number generator.
//
//    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
//
{
  int i;
  const int i4_huge = 2147483647;
  int k;
  double *r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8VEC_UNIFORM_01_NEW - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  r = new double[n];

  for ( i = 0; i < n; i++ )
  {
    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )
    {
      seed = seed + i4_huge;
    }

    r[i] = ( double ) ( seed ) * 4.656612875E-10;
  }

  return r;
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
