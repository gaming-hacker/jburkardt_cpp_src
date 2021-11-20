# include <cmath>
# include <complex>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "test_mat.hpp"

//****************************************************************************80

double *a123 ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123() returns the A123 matrix.
//
//  Example:
//
//    1 2 3
//    4 5 6
//    7 8 9
//
//  Properties:
//
//    A is integral.
//
//    A is not symmetric.
//
//    A is singular.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    double *A123[3,3], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[3*3];

  k = 0;
  for ( i = 0; i < 3; i++ )
  {
    for ( j = 0; j < 3; j++ )
    {
      k = k + 1;
      a[i+j*3] = ( double ) ( k );
    }
  }

  return a;
}
//****************************************************************************80

double a123_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_determinant() returns the determinant of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double VALUE, the determinant.
//
{
  double value;

  value = 0.0;

  return value;
}
//****************************************************************************80

double *a123_eigen_left ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_eigen_left() returns the left eigenvectors of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double A123_EIGEN_LEFT[3*3], the left eigenvector matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  double a_save[3*3] = {
  -0.464547273387671, 
  -0.882905959653586, 
   0.408248290463862, 
  -0.570795531228578, 
  -0.239520420054206, 
  -0.816496580927726, 
  -0.677043789069485, 
   0.403865119545174, 
   0.408248290463863 };
    
  a = r8mat_copy_new ( 3, 3, a_save );

  return a;
}
//****************************************************************************80

double *a123_eigen_right ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_eigen_right() returns the right eigenvectors of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double A123_EIGEN_RIGHT[3*3], the right eigenvector matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  double a_save[3*3] = {
  -0.231970687246286, 
  -0.525322093301234, 
  -0.818673499356181, 
  -0.785830238742067, 
  -0.086751339256628, 
   0.612327560228810, 
   0.408248290463864, 
  -0.816496580927726, 
   0.408248290463863 };
    
  a = r8mat_copy_new ( 3, 3, a_save );

  return a;
}
//****************************************************************************80

double *a123_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_eigenvalues returns the eigenvalues of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double A123_EIGENVALUES[3], the eigenvalues.
//
{
  double *lambda;
  double lambda_save[3] = {
    16.116843969807043, -1.116843969807043, 0.0 };

  lambda = r8vec_copy_new ( 3, lambda_save );

  return lambda;
}
//****************************************************************************80

double *a123_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_inverse() returns the pseudo-inverse of the A123 matrix.
//
//  Example:
//
//    -0.638888888888888  -0.166666666666666   0.305555555555555
//    -0.055555555555556   0.000000000000000   0.055555555555556
//     0.527777777777777   0.166666666666666  -0.194444444444444
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double A123_INVERSE[3*3], the matrix.
//
{
  double *b;
  double b_save[3*3] = {
  -0.638888888888888, -0.055555555555556,  0.527777777777777, 
  -0.166666666666666,  0.000000000000000,  0.166666666666666, 
   0.305555555555555,  0.055555555555556, -0.194444444444444 };

  b = r8mat_copy_new ( 3, 3, b_save );

  return b;
}
//****************************************************************************80

double *a123_null_left ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_null_left() returns a left null vector of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double A123_NULL_LEFT[3], a left null vector.
//
{
  double *x;
  double x_save[3] = { 1.0, -2.0, 1.0 };

  x = r8vec_copy_new ( 3, x_save );

  return x;
}
//****************************************************************************80

double *a123_null_right ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_null_right() returns a right null vector of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double A123_NULL_RIGHT[3], the vector.
//
{
  double *x;
  double x_save[3] = { 1.0, -2.0, 1.0 };

  x = r8vec_copy_new ( 3, x_save );

  return x;
}
//****************************************************************************80

void a123_plu ( double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    a123_plu() returns the PLU factors of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double P[3*3], L[3*3], U[3*3], the PLU factors.
//
{
  double l_save[3*3] = {
   1.0,  0.142857142857143, 0.571428571428571, 
   0.0,  1.00,              0.5, 
   0.0,  0.00,              1.0 };
  double p_save[3*3] = {
    0.0,  0.0,  1.0, 
    1.0,  0.0,  0.0, 
    0.0,  1.0,  0.0 };
  double u_save[3*3] = {
    7.0,  0.00,               0.0, 
    8.0,  0.857142857142857,  0.0, 
    9.0,  1.714285714285714,  0.0 };

  r8mat_copy ( 3, 3, l_save, l );
  r8mat_copy ( 3, 3, p_save, p );
  r8mat_copy ( 3, 3, u_save, u );

  return;
}
//****************************************************************************80

void a123_qr ( double q[], double r[] )

//****************************************************************************80
//
//  Purpose:
//
//    a123_qr() returns the QR factors of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double Q[3*3], R[3*3], the QR factors.
//
{
  double q_save[3*3] = {
    -0.123091490979333, -0.492365963917331, -0.861640436855329, 
     0.904534033733291,  0.301511344577763, -0.301511344577763, 
     0.408248290463862, -0.816496580927726,  0.408248290463863 };
  double r_save[3*3] = {
     -8.124038404635959, 0.0,               0.0, 
     -9.601136296387955, 0.904534033733293, 0.0, 
    -11.078234188139948, 1.809068067466585, 0.0 };

  r8mat_copy ( 3, 3, q_save, q );
  r8mat_copy ( 3, 3, r_save, r );

  return;
}
//****************************************************************************80

double *a123_rhs ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_rhs() returns the A123 right hand side.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double A123_RHS[3], the right hand side vector.
//
{
  static double b_save[3] = { 10.0, 28.0, 46.0 };
  double *b;

  b = r8vec_copy_new ( 3, b_save );

  return b;
}
//****************************************************************************80

double *a123_solution ( )

//****************************************************************************80
//
//  Purpose:
//
//    a123_solution() returns the A123 solution vector.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, A123_SOLUTION[3], the solution.
//
{
  double *x;
  static double x_save[3] = { 3.0, 2.0, 1.0 };

  x = r8vec_copy_new ( 3, x_save );

  return x;
}
//****************************************************************************80

void a123_svd ( double u[], double s[], double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    a123_svd() returns the SVD factors of the A123 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    Output, double U[3*3], S[3*3], V[3*3], the SVD factors.
//
{
  double s_save[3*3] = {
    16.848103352614210,   0.0,                0.0, 
                   0.0,   1.068369514554710,  0.0, 
                   0.0,   0.0,                0.0 };
  double u_save[3*3] = {
  -0.214837238368397,  -0.520587389464737,  -0.826337540561078,
   0.887230688346371,   0.249643952988297,  -0.387942782369774, 
   0.408248290463863,  -0.816496580927726,   0.408248290463863 };
  double v_save[3*3] = {
  -0.479671177877772,  -0.572367793972062,  -0.665064410066353, 
  -0.776690990321560,  -0.075686470104559,   0.625318050112443, 
  -0.408248290463863,   0.816496580927726,  -0.408248290463863 };

  r8mat_copy ( 3, 3, s_save, s );
  r8mat_copy ( 3, 3, u_save, u );
  r8mat_copy ( 3, 3, v_save, v );

  return;
}
//****************************************************************************80

double *aegerter ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    AEGERTER returns the AEGERTER matrix.
//
//  Formula:
//
//    if ( I == N )
//      A(I,J) = J
//    else if ( J == N )
//      A(I,J) = I
//    else if ( I == J )
//      A(I,J) = 1
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//    1  0  0  0  1
//    0  1  0  0  2
//    0  0  1  0  3
//    0  0  0  1  4
//    1  2  3  4  5
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is border-banded.
//
//    det ( A ) = N * ( - 2 * N * N + 3 * N + 5 ) / 6
//
//    A has N-2 eigenvalues equal to 1.
//
//    The other two eigenvalues are
//
//      ( N + 1 + sqrt ( ( N + 1 )^2 - 4 * det ( A ) ) ) / 2
//      ( N + 1 - sqrt ( ( N + 1 )^2 - 4 * det ( A ) ) ) / 2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    MJ Aegerter,
//    Construction of a Set of Test Matrices,
//    Communications of the ACM,
//    Volume 2, Number 8, August 1959, pages 10-12.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double AEGERTER[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i == n )
      {
        a[i-1+(j-1)*n] = ( double ) ( j );
      }
      else if ( j == n )
      {
        a[i-1+(j-1)*n] = ( double ) ( i );
      }
      else if ( i == j )
      {
        a[i-1+(j-1)*n] = 1.0;
      }
      else
      {
        a[i-1+(j-1)*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double aegerter_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    AEGERTER_CONDITION returns the L1 condition of the AEGERTER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 April 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double AEGERTER_CONDITION, the L1 condition number.
//
{
  double a_norm;
  double *b;
  double b_norm;
  double value;

  a_norm = ( double ) ( ( ( n + 1 ) * n ) / 2 );

  b = aegerter_inverse ( n );
  b_norm = r8mat_norm_l1 ( n, n, b );

  value = a_norm * b_norm;
//
//  Free memory.
//
  delete [] b;

  return value;
}
//****************************************************************************80

double aegerter_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    AEGERTER_DETERMINANT returns the determinant of the AEGERTER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double AEGERTER_DETERMINANT, the determinant.
//
{
  double determ;

  determ = ( double ) ( n - ( ( n - 1 ) * n * ( 2 * n - 1 ) ) / 6 );

  return determ;
}
//****************************************************************************80

double *aegerter_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    AEGERTER_EIGENVALUES returns the eigenvalues of the AEGERTER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double AEGERTER_EIGENVALUES[N], the eigenvalues.
//
{
  double determ;
  int i;
  double *lambda;
  double np1;

  lambda = new double[n];

  determ = ( double ) ( n - ( ( n - 1 ) * n * ( 2 * n - 1 ) ) / 6 );
  np1 = ( double ) ( n + 1 );

  lambda[0]     = 0.5 * ( np1 - sqrt ( np1 * np1 - 4.0 * determ ) );
  for ( i = 1; i < n - 1; i++ )
  {
    lambda[i] = 1.0;
  }
  lambda[n-1] = 0.5 * ( np1 + sqrt ( np1 * np1 - 4.0 * determ ) );

  return lambda;
}
//****************************************************************************80

double *aegerter_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    AEGERTER_INVERSE returns the inverse of the AEGERTER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double AEGERTER_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n - 1; i++ )
  {
    for ( j = 1; j <= n - 1; j++ )
    {
      if ( i == j )
      {
        a[i-1+(j-1)*n] = 1.0 - ( double ) ( i * j ) / ( double ) ( n * n );
      }
      else
      {
        a[i-1+(j-1)*n] =     - ( double ) ( i * j ) / ( double ) ( n * n );
      }
    }
  }

  for ( i = 1; i <= n - 1; i++ )
  {
    a[i-1+(n-1)*n] = ( double ) ( i ) / ( double ) ( n * n );
  }

  for ( j = 1; j <= n - 1; j++ )
  {
    a[n-1+(j-1)*n] = ( double ) ( j ) / ( double ) ( n * n );
  }

  a[n-1+(n-1)*n] = - 1.0 / ( double ) ( n * n );

  return a;
}
//****************************************************************************80

double *anticirculant ( int m, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    ANTICIRCULANT returns an ANTICIRCULANT matrix.
//
//  Formula:
//
//    K = 1 + mod ( J + I - 2, N )
//    A(I,J) = X(K)
//
//  Example:
//
//    M = 4, N = 5, X = ( 1, 2, 3, 4, 5 )
//
//    1  2  3  4  5
//    2  3  4  5  1
//    3  4  5  1  2
//    4  5  1  2  3
//
//    M = 5, N = 4, X = ( 1, 2, 3, 4 )
//
//    1  2  3  4
//    2  3  4  5
//    3  4  5  1
//    4  5  1  2
//    1  2  3  4
//
//  Properties:
//
//    A is a special Hankel matrix in which the diagonals "wrap around".
//
//    A is symmetric: A' = A.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double X[N], the vector that defines A.
//
//    Output, double ANTICIRCULANT[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[m*n];

  for ( i = 1; i <= m; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      k = ( ( j + i - 2 ) % n );
      a[i-1+(j-1)*m] = x[k];
    }
  }
  return a;
}
//****************************************************************************80

double anticirculant_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    ANTICIRCULANT_DETERMINANT: determinant of the ANTICIRCULANT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the values in the first row of A.
//
//    Output, double ANTICIRCULANT_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int j;
  complex <double> *lambda;
  complex <double> *w;

  w = c8vec_unity ( n );
  lambda = new complex <double>[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = x[n-1];
  }

  for ( i = n - 2; 0 <= i; i-- )
  {
    for ( j = 0; j < n; j++ )
    {
      lambda[j] = lambda[j] * w[j] + x[i];
    }
  }
//
//  First eigenvalue is "special".
//
  determ = real ( lambda[0] );
//
//  Eigenvalues 2, 3     through ( N + 1 ) / 2 are paired with complex conjugates.
//
  for ( i = 1; i < ( n + 1 ) / 2; i++ )
  {
    determ = determ * pow ( abs ( lambda[i] ), 2 );
  }
//
//  If N is even, there is another unpaired eigenvalue.
//
  if ( ( n % 2 ) == 0 )
  {
    determ = determ * real ( lambda[(n/2)] );
  }
//
//  This is actually the determinant of the CIRCULANT matrix.
//  We have to perform ( N - 1 ) / 2 row interchanges to get 
//  to the anticirculant matrix.
//
  determ = r8_mop ( ( n - 1 ) / 2 ) * determ;
//
//  Free memory.
//
  delete [] lambda;
  delete [] w;

  return determ;
}
//****************************************************************************80

double *antihadamard ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    ANTIHADAMARD returns an approximate ANTIHADAMARD matrix.
//
//  Discussion:
//
//    An Anti-Hadamard matrix is one whose elements are all 0 or 1,
//    and for which the Frobenius norm of the inverse is as large as
//    possible.  This routine returns a matrix for which the Frobenius norm
//    of the inverse is large, though not necessarily maximal.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = 1
//    else if ( I < J and mod ( I + J, 2 ) = 1 )
//      A(I,J) = 1
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//    1 1 0 1 0
//    0 1 1 0 1
//    0 0 1 1 0
//    0 0 0 1 1
//    0 0 0 0 1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is upper triangular.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a zero-one matrix.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    LAMBDA(1:N) = 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Ronald Graham, Neal Sloane,
//    Anti-Hadamard Matrices,
//    Linear Algebra and Applications,
//    Volume 62, November 1984, pages 113-137.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double ANTIHADAMARD[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j < i )
      {
        a[i+j*n] = 0.0;
      }
      else if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else if ( ( ( i + j ) % 2 ) == 1 )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double antihadamard_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    ANTIHADAMARD_DETERMINANT returns the determinant of the ANTIHADAMARD matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 October 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double ANTIHADAMARD_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *antisymmetric_random ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    ANTIsymmetric_random returns an ANTISYMMETRIC matrix.
//
//  Example:
//
//    N = 5
//
//     0.0000  -0.1096   0.0813   0.9248   -0.0793
//     0.1096   0.0000   0.1830   0.1502    0.8244
//    -0.0813  -0.1830   0.0000   0.0899   -0.2137
//    -0.9248  -0.1502  -0.0899   0.0000   -0.4804
//     0.0793  -0.8244   0.2137   0.4804    0.0000
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is antisymmetric: A' = -A.
//
//    Because A is antisymmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    The diagonal of A is zero.
//
//    All the eigenvalues of A are imaginary.
//
//    if N is odd, then det ( A ) = 0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double ANTIsymmetric_random[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int seed;

  a = new double[n*n];

  seed = key;
  for ( i = 0; i < n; i++ )
  {
    a[i+i*n] = 0.0;
    for ( j = i + 1; j < n; j++ )
    {
      a[i+j*n] = 2.0 * r8_uniform_01 ( seed ) - 1.0;
      a[j+i*n] = - a[i+j*n];
    }
  }
  return a;
}
//****************************************************************************80

double *archimedes ( )

//****************************************************************************80
//
//  Purpose:
//
//    ARCHIMEDES returns the ARCHIMEDES matrix.
//
//  Formula:
//
//      6   -5    0   -6    0    0    0    0
//      0   20   -9  -20    0    0    0    0
//    -13    0   42  -42    0    0    0    0
//      0   -7    0    0   12   -7    0    0
//      0    0   -9    0    0   20   -9    0
//      0    0    0  -11    0    0   30  -11
//    -13    0    0    0  -13    0    0   42
//
//  Discussion:
//
//    "The sun god had a herd of cattle, consisting of bulls and cows,
//    one part of which was white, a second black, a third spotted, and
//    a fourth brown.  Among the bulls, the number of white ones was
//    one half plus one third the number of the black greater than
//    the brown; the number of the black, one quarter plus one fifth
//    the number of the spotted greater than the brown; the number of
//    the spotted, one sixth and one seventh the number of the white
//    greater than the brown.  Among the cows, the number of white ones
//    was one third plus one quarter of the total black cattle; the number
//    of the black, one quarter plus one fifth the total of the spotted
//    cattle; the number of spotted, one fifth plus one sixth the total
//    of the brown cattle; the number of the brown, one sixth plus one
//    seventh the total of the white cattle.  What was the composition
//    of the herd?"
//
//    The 7 relations involving the 8 numbers W, X, Y, Z, w, x, y, z,
//    have the form:
//
//      W = ( 5/ 6) *   X + Z
//      X = ( 9/20) *   Y + Z
//      Y = (13/42) *   W + Z
//      w = ( 7/12) * ( X + x )
//      x = ( 9/20) * ( Y + y )
//      y = (11/30) * ( Z + z )
//      z = (13/42) * ( W + w )
//
//    These equations may be multiplied through to an integral form
//    that is embodied in the above matrix.
//
//    A more complicated second part of the problem imposes additional
//    constraints (W+X must be square, Y+Z must be a triangular number).
//
//  Properties:
//
//    A is integral: int ( A ) = A.
//
//    A has full row rank.
//
//    It is desired to know a solution X in positive integers of
//
//      A * X = 0.
//
//    The null space of A is spanned by multiples of the null vector:
//
//      [ 10,366,482 ]
//      [  7,460,514 ]
//      [  7,358,060 ]
//      [  4,149,387 ]
//      [  7,206,360 ]
//      [  4,893,246 ]
//      [  3,515,820 ]
//      [  5,439,213 ]
//
//    and this is the smallest positive integer solution of the
//    equation A * X = 0.
//
//    Thus, for the "simple" part of Archimedes's problem, the total number
//    of cattle of the Sun is 50,389,082.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Eric Weisstein,
//    CRC Concise Encyclopedia of Mathematics,
//    CRC Press, 2002,
//    Second edition,
//    ISBN: 1584883472,
//    LC: QA5.W45
//
//  Parameters:
//
//    Output, double ARCHIMEDES[7*8], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[7*8] = {
    6.0,   0.0, -13.0,  0.0,  0.0,   0.0, -13.0, 
   -5.0,  20.0,   0.0, -7.0,  0.0,   0.0,   0.0, 
    0.0,  -9.0,  42.0,  0.0, -9.0,   0.0,   0.0, 
   -6.0, -20.0, -42.0,  0.0,  0.0, -11.0,   0.0, 
    0.0,   0.0,   0.0, 12.0,  0.0,   0.0, -13.0, 
    0.0,   0.0,   0.0, -7.0, 20.0,   0.0,   0.0, 
    0.0,   0.0,   0.0,  0.0, -9.0,  30.0,   0.0, 
    0.0,   0.0,   0.0,  0.0,  0.0, -11.0,  42.0 };

  a = r8mat_copy_new ( 7, 8, a_save );

  return a;
}
//****************************************************************************80

double *archimedes_null_right ( )

//****************************************************************************80
//
//  Purpose:
//
//    ARCHIMEDES_NULL_RIGHT returns a right null vector for the ARCHIMEDES matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double ARCHIMEDES_NULL_RIGHT[8], the null vector.
//
{
  int n = 8;
  double *x;
  static double x_save[8] = {
       10366482.0, 7460514.0, 7358060.0, 4149387.0, 
        7206360.0, 4893246.0, 3515820.0, 5439213.0 };

  x = r8vec_copy_new ( n, x_save );

  return x;
}
//****************************************************************************80

double *bab ( int n, double alpha, double beta )

//****************************************************************************80
//
//  Purpose:
//
//    BAB returns the BAB matrix.
//
//  Discussion:
//
//    The name is meant to suggest the pattern "B  A  B" formed by
//    the nonzero entries in a general row of the matrix.
//
//  Example:
//
//    N = 5
//    ALPHA = 5, BETA = 2
//
//    5  2  .  .  .
//    2  5  2  .  .
//    .  2  5  2  .
//    .  .  2  5  2
//    .  .  .  2  5
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    CM da Fonseca, J Petronilho,
//    Explicit Inverses of Some Tridiagonal Matrices,
//    Linear Algebra and Its Applications,
//    Volume 325, 2001, pages 7-21.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, BETA, the parameters.
//
//    Output, double BAB[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = alpha;
      }
      else if ( i == j + 1 || i == j - 1 )
      {
        a[i+j*n] = beta;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double bab_condition ( int n, double alpha, double beta )

//****************************************************************************80
//
//  Purpose:
//
//    BAB_CONDITION returns the L1 condition of the BAB matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, BETA, the parameters.
//
//    Output, double BAB_CONDITION, the L1 condition number.
//
{
  double a_norm;
  double *b;
  double b_norm;
  double value;

  if ( n == 1 )
  {
    a_norm = fabs ( alpha );
  }
  else if ( n == 2 )
  {
    a_norm = fabs ( alpha ) + fabs ( beta );
  }
  else
  {
    a_norm = fabs ( alpha ) + 2.0 * fabs ( beta );
  }

  b = bab_inverse ( n, alpha, beta );
  b_norm = r8mat_norm_l1 ( n, n, b );
  
  value = a_norm * b_norm;
//
//  Free memory.
//
  delete [] b;

  return value;
}
//****************************************************************************80

double bab_determinant ( int n, double alpha, double beta )

//****************************************************************************80
//
//  Purpose:
//
//    BAB_DETERMINANT returns the determinant of the BAB matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, BETA, the parameters.
//
//    Output, double BAB_DETERMINANT, the determinant.
//
{
  double determ;
  double determ_nm1;
  double determ_nm2;
  int i;

  determ_nm1 = alpha;

  if ( n == 1 )
  {
    determ = determ_nm1;
    return determ;
  }

  determ_nm2 = determ_nm1;
  determ_nm1 = alpha * alpha - beta * beta;

  if ( n == 2 )
  {
    determ = determ_nm1;
    return determ;
  }

  for ( i = n - 2; 1 <= i; i-- )
  {
    determ = alpha * determ_nm1 - beta * beta * determ_nm2;
    determ_nm2 = determ_nm1;
    determ_nm1 = determ;
  }
 
  return determ;
}
//****************************************************************************80

double *bab_eigen_right ( int n, double alpha, double beta )

//****************************************************************************80
//
//  Purpose:
//
//    BAB_EIGEN_RIGHT returns the right eigenvectors of the BAB matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, BETA, the parameters.
//
//    Output, double BAB_EIGEN_RIGHT[N*N], the right eigenvector matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( ( i + 1 ) * ( j + 1 ) ) 
        * r8_pi / ( double ) ( n + 1 );
      a[i+j*n] = sqrt ( 2.0 / ( double ) ( n + 1 ) ) * sin ( angle );
    }
  }
  return a;
}
//****************************************************************************80

double *bab_eigenvalues ( int n, double alpha, double beta )

//****************************************************************************80
//
//  Purpose:
//
//    BAB_EIGENVALUES returns the eigenvalues of the BAB matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, BETA, the parameters.
//
//    Output, double BAB_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  int i;
  double *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 1 );
    lambda[i] = alpha + 2.0 * beta * cos ( angle );
  }

  return lambda;
}
//****************************************************************************80

double *bab_inverse ( int n, double alpha, double beta )

//****************************************************************************80
//
//  Purpose:
//
//    BAB_INVERSE returns the inverse of the BAB matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, BETA, the parameters.
//
//    Output, double BAB_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double *u;
  double x;

  if ( beta == 0.0 )
  {
    if ( alpha == 0.0 )
    {
      cerr << "\n";
      cerr << "BAB_INVERSE - Fatal error!\n";
      cerr << "  ALPHA = BETA = 0.\n";
      exit ( 1 );
    }

    a = new double[n*n];

    for ( i = 0; i < n; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        if ( i == j )
        {
          a[i+j*n] = 1.0 / alpha;
        }
        else
        {
          a[i+j*n] = 0.0;
        }
      }
    }
  }
  else
  {
    x = 0.5 * alpha / beta;

    u = cheby_u_polynomial ( n, x );

    a = new double[n*n];

    for ( i = 1; i <= n; i++ )
    {
      for ( j = 1; j <= i; j++ )
      {
        a[i-1+(j-1)*n] = r8_mop ( i + j ) * u[j-1] * u[n-i] / u[n] / beta;
      }
      for ( j = i + 1; j <= n; j++ )
      {
        a[i-1+(j-1)*n] = r8_mop ( i + j ) * u[i-1] * u[n-j] / u[n] / beta;
      }
    }
    delete [] u;
  }

  return a;
}
//****************************************************************************80

double *bauer ( )

//****************************************************************************80
//
//  Purpose:
//
//    BAUER returns the BAUER matrix.
//
//  Example:
//
//    -74   80  18 -11  -4  -8
//     14  -69  21  28   0   7
//     66  -72  -5   7   1   4
//    -12   66 -30 -23   3  -3
//      3    8  -7  -4   1   0
//      4  -12   4   4   0   1
//
//  Properties:
//
//    The matrix is integral.
//
//    The inverse matrix is integral.
//
//    The matrix is ill-conditioned.
//
//    The determinant is 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Virginia Klema, Alan Laub,
//    The Singular Value Decomposition: Its Computation and Some Applications,
//    IEEE Transactions on Automatic Control,
//    Volume 25, Number 2, April 1980.
//
//  Parameters:
//
//    Output, double BAUER[6,6], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  double a_save[6*6] = {
   -74.0,   14.0,   66.0,  -12.0,    3.0,    4.0, 
    80.0,  -69.0,  -72.0,   66.0,    8.0,  -12.0, 
    18.0,   21.0,   -5.0,  -30.0,   -7.0,    4.0, 
   -11.0,   28.0,    7.0,  -23.0,   -4.0,    4.0, 
    -4.0,    0.0,    1.0,    3.0,    1.0,    0.0, 
    -8.0,    7.0,    4.0,   -3.0,    0.0,    1.0 };

  a = r8mat_copy_new ( 6, 6, a_save );
  
  return a;
}
//****************************************************************************80

double bauer_condition ( )

//****************************************************************************80
//
//  Purpose:
//
//    BAUER_CONDITION returns the L1 condition of the BAUER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double VALUE, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 307.0;
  b_norm = 27781.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double bauer_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    BAUER_DETERMINANT returns the determinant of the BAUER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double VALUE, the determinant.
//
{
  double value;

  value = 1.0;

  return value;
}
//****************************************************************************80

double *bauer_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    BAUER_INVERSE returns the inverse of the BAUER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double BAUER_INVERSE[6*6], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  double a_save[6*6] = {
      1.0,     0.0,    -2.0,    15.0,    43.0,    -56.0, 
      0.0,     1.0,     2.0,   -12.0,   -42.0,     52.0, 
     -7.0,     7.0,    29.0,  -192.0,  -600.0,    764.0, 
    -40.0,    35.0,   155.0, -1034.0, -3211.0,   4096.0, 
    131.0,  -112.0,  -502.0,  3354.0, 10406.0, -13276.0, 
    -84.0,    70.0,   319.0, -2130.0, -6595.0,   8421.0 };

  a = r8mat_copy_new ( 6, 6, a_save );

  return a;
}
//****************************************************************************80

double *bernstein ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BERNSTEIN returns the BERNSTEIN matrix.
//
//  Discussion:
//
//    The Bernstein matrix of order N is an NxN matrix A which can be used to
//    transform a vector of power basis coefficients C representing a polynomial 
//    P(X) to a corresponding Bernstein basis coefficient vector B:
//
//      B = A * C
//
//    The N power basis vectors are ordered as (1,X,X^2,...X^(N-1)) and the N 
//    Bernstein basis vectors as ((1-X)^(N-1), X*(1-X)^(N-2),...,X^(N-1)).
//
//  Example:
//
//    N = 5
//
//    1    -4     6    -4     1
//    0     4   -12    12    -4
//    0     0     6   -12     6
//    0     0     0     4    -4
//    0     0     0     0     1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BERNSTEIN[N*N], the Bernstein matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*n] = r8_mop ( j - i ) * r8_choose ( n - 1 - i, j - i ) 
        * r8_choose ( n - 1, i );
    }
  }

  return a;
}
//****************************************************************************80

double bernstein_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BERNSTEIN_DETERMINANT returns the determinant of the BERNSTEIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BERNSTEIN_DETERMINANT, the determinant.
//
{
  int i;
  double value;

  value = 1.0;
  for ( i = 0; i < n; i++ )
  {
    value = value * r8_choose ( n - 1, i );
  }

  return value;
}
//****************************************************************************80

double *bernstein_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BERNSTEIN_INVERSE returns the inverse of the BERNSTEIN matrix.
//
//  Discussion:
//
//    The inverse Bernstein matrix of order N is an NxN matrix A which can 
//    be used to transform a vector of Bernstein basis coefficients B
//    representing a polynomial P(X) to a corresponding power basis 
//    coefficient vector C:
//
//      C = A * B
//
//    The N power basis vectors are ordered as (1,X,X^2,...X^(N-1)) and the N 
//    Bernstein basis vectors as ((1-X)^(N-1), X*(1_X)^(N-2),...,X^(N-1)).
//
//  Example:
//
//    N = 5
//
//   1.0000    1.0000    1.0000    1.0000    1.0000
//        0    0.2500    0.5000    0.7500    1.0000
//        0         0    0.1667    0.5000    1.0000
//        0         0         0    0.2500    1.0000
//        0         0         0         0    1.0000
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BERNSTEIN_INVERSE[N*N], the inverse Bernstein matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*n] = r8_choose ( j, i ) / r8_choose ( n - 1, i );
    }
  }

  return a;
}
//****************************************************************************80

double *bernstein_poly_01 ( int n, double x )

//****************************************************************************80
//
//  Purpose:
//
//    BERNSTEIN_POLY_01 evaluates the Bernstein polynomials based in [0,1].
//
//  Discussion:
//
//    The Bernstein polynomials are assumed to be based on [0,1].
//
//    The formula is:
//
//      B(N,I)(X) = [N!/(I!*(N-I)!)] * (1-X)^(N-I) * X^I
//
//  First values:
//
//    B(0,0)(X) = 1
//
//    B(1,0)(X) =      1-X
//    B(1,1)(X) =                X
//
//    B(2,0)(X) =     (1-X)^2
//    B(2,1)(X) = 2 * (1-X)    * X
//    B(2,2)(X) =                X^2
//
//    B(3,0)(X) =     (1-X)^3
//    B(3,1)(X) = 3 * (1-X)^2 * X
//    B(3,2)(X) = 3 * (1-X)   * X^2
//    B(3,3)(X) =               X^3
//
//    B(4,0)(X) =     (1-X)^4
//    B(4,1)(X) = 4 * (1-X)^3 * X
//    B(4,2)(X) = 6 * (1-X)^2 * X^2
//    B(4,3)(X) = 4 * (1-X)   * X^3
//    B(4,4)(X) =               X^4
//
//  Special values:
//
//    B(N,I)(X) has a unique maximum value at X = I/N.
//
//    B(N,I)(X) has an I-fold zero at 0 and and N-I fold zero at 1.
//
//    B(N,I)(1/2) = C(N,K) / 2^N
//
//    For a fixed X and N, the polynomials add up to 1:
//
//      Sum ( 0 <= I <= N ) B(N,I)(X) = 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the degree of the Bernstein polynomials 
//    to be used.  For any N, there is a set of N+1 Bernstein polynomials,
//    each of degree N, which form a basis for polynomials on [0,1].
//
//    Input, double X, the evaluation point.
//
//    Output, double BERNSTEIN_POLY[N+1], the values of the N+1 
//    Bernstein polynomials at X.
//
{
  double *bern;
  int i;
  int j;

  bern = new double[n+1];

  if ( n == 0 )
  {
    bern[0] = 1.0;
  }
  else if ( 0 < n )
  {
    bern[0] = 1.0 - x;
    bern[1] = x;
 
    for ( i = 2; i <= n; i++ )
    {
      bern[i] = x * bern[i-1];
      for ( j = i - 1; 1 <= j; j-- )
      {
        bern[j] =         x   * bern[j-1] 
                + ( 1.0 - x ) * bern[j];
      }
      bern[0] = ( 1.0 - x ) * bern[0];
    }
  }
  return bern;
}
//****************************************************************************80

double *bernstein_vandermonde ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BERNSTEIN_VANDERMONDE returns the Bernstein Vandermonde matrix.
//
//  Discussion:
//
//    The Bernstein Vandermonde matrix of order N is constructed by
//    evaluating the N Bernstein polynomials of degree N-1 at N equally
//    spaced points between 0 and 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 December 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BERNSTEIN_VANDERMONDE[N*N], the Bernstein Vandermonde matrix.
//
{
  double *b;
  int i;
  int j;
  double *v;
  double x;

  v = new double[n*n];

  if ( n == 1 )
  {
    v[0+0*1] = 1.0;
    return v;
  }

  for ( i = 0; i < n; i++ )
  {
    x = ( double ) ( i ) / ( double ) ( n - 1 );
    b = bernstein_poly_01 ( n - 1, x );
    for ( j = 0; j < n; j++ )
    {
      v[i+j*n] = b[j];
    }
    delete [] b;
  }

  return v;
}
//****************************************************************************80

double *bimarkov_random ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    BIMARKOV_RANDOM returns a BIMARKOV matrix.
//
//  Discussion:
//
//    A Bimarkov matrix is also known as a doubly stochastic matrix.
//
//  Example:
//
//    N = 5
//
//    1/5   1/5   1/5   1/5   1/5
//    1/2   1/2    0     0     0
//    1/6   1/6   2/3    0     0
//    1/12  1/12  1/12  3/4    0
//    1/20  1/20  1/20  1/20  4/5
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    0 <= A(I,J) <= 1.0 for every I and J.
//
//    A has constant row sum 1.
//
//    Because it has a constant row sum of 1,
//    A has an eigenvalue of 1
//    and a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has constant column sum 1.
//
//    Because it has a constant column sum of 1,
//    A has an eigenvalue of 1
//    and a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    All the eigenvalues of A have modulus 1.
//
//    The eigenvalue 1 lies on the boundary of all the Gershgorin
//    row or column sum disks.
//
//    Every doubly stochastic matrix is a combination
//      A = w1 * P1 + w2 * P2 + ... + wk * Pk
//    of permutation matrices, with positive weights w that sum to 1.
//    (Birkhoff's theorem, see Horn and Johnson.)
//
//    A is a Markov matrix.
//
//    A is a transition matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Roger Horn, Charles Johnson,
//    Matrix Analysis,
//    Cambridge, 1985,
//    ISBN: 0-521-38632-2,
//    LC: QA188.H66.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output,double BIMARKOV_RANDOM[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
//
//  Get a random orthogonal matrix.
//
  a = orthogonal_random ( n, key );
//
//  Square each entry.
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = a[i+j*n] * a[i+j*n];
    }
  }
  return a;
}
//****************************************************************************80

double *bis ( double alpha, double beta, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIS returns the BIS matrix.
//
//  Discussion:
//
//    The BIS matrix is a bidiagonal scalar matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = ALPHA
//    else if ( J = I + 1 )
//      A(I,J) = BETA
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 7, BETA = 2, M = 5, N = 4
//
//    7  2  0  0
//    0  7  2  0
//    0  0  7  2
//    0  0  0  7
//    0  0  0  0
//
//  Properties:
//
//    A is bidiagonal.
//
//    Because A is bidiagonal, it has property A (bipartite).
//
//    A is upper triangular.
//
//    A is banded with bandwidth 2.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is generally not symmetric: A' /= A.
//
//    A is nonsingular if and only if ALPHA is nonzero.
//
//    det ( A ) = ALPHA^N.
//
//    LAMBDA(1:N) = ALPHA.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, the scalars which define the
//    diagonal and first superdiagonal of the matrix.
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double BIS[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[m*n];

  for ( i = 1; i <= m; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( j == i )
      {
        a[i-1+(j-1)*m] = alpha;
      }
      else if ( j == i + 1 )
      {
        a[i-1+(j-1)*m] = beta;
      }
      else
      {
        a[i-1+(j-1)*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double bis_condition ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIS_CONDITION returns the L1 condition of the BIS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, the scalars which define the
//    diagonal and first superdiagonal of the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double BIS_CONDITION, the L1 condition of the matrix.
//
{
  double a_norm;
  double b_norm;
  double ba;
  double value;

  a_norm = fabs ( alpha ) + fabs ( beta );
  ba = fabs ( beta / alpha );
  b_norm = ( pow ( ba, n ) - 1.0 ) / ( ba - 1.0 ) / fabs ( alpha );
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double bis_determinant ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIS_DETERMINANT returns the determinant of the BIS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, the scalars which define the
//    diagonal and first superdiagonal of the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double BIS_DETERMINANT, the determinant of the matrix.
//
{
  double determ;

  determ = pow ( alpha, n );

  return determ;
}
//****************************************************************************80

double *bis_eigenvalues ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIS_EIGENVALUES returns the eigenvalues of the BIS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, the scalars which define the
//    diagonal and first superdiagonal of the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double BIS_EIGENVALUES[N], the eigenvalues of the matrix.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = alpha;
  }
  return lambda;
}
//****************************************************************************80

double *bis_inverse ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIS_INVERSE returns the inverse of the BIS matrix.
//
//  Formula:
//
//    if ( I <= J )
//      A(I,J) = (-BETA)^(J-I) / ALPHA^(J+1-I)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 7.0, BETA = 2.0, N = 4
//
//    0.1429   -0.0408    0.0117   -0.0033
//        0     0.1429   -0.0408    0.0117
//        0          0    0.1429   -0.0408
//        0          0         0    0.1429
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is upper triangular
//
//    A is Toeplitz: constant along diagonals.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    det ( A ) = (1/ALPHA)^N.
//
//    LAMBDA(1:N) = 1 / ALPHA.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, the scalars which define the
//    diagonal and first superdiagonal of the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double BIS_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( alpha == 0.0 )
  {
    cerr << "\n";
    cerr << "BIS_INVERSE - Fatal error.\n";
    cerr << "  The input parameter ALPHA was 0.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i <= j )
      {
        a[i+j*n] = pow ( - beta / alpha, j - i ) / alpha;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *biw ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIW returns the BIW matrix.
//
//  Discussion:
//
//    BIW is a bidiagonal matrix of Wilkinson.   Originally, this matrix
//    was considered for N = 100.
//
//  Formula:
//
//    if ( I == J )
//      A(I,J) = 0.5 + I / ( 10 * N )
//    else if ( J == I+1 )
//      A(I,J) = -1.0
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//    0.52 -1.00  0.00  0.00  0.00
//    0.00  0.54 -1.00  0.00  0.00
//    0.00  0.00  0.56 -1.00  0.00
//    0.00  0.00  0.00  0.58 -1.00
//    0.00  0.00  0.00  0.00  0.60
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BIW[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n; i++ )
  {
    a[i+i*n] = 0.5 + ( double ) ( i + 1 ) / ( double ) ( 10 * n );
  }

  for ( i = 0; i < n - 1; i++ )
  {
    a[i+(i+1)*n] = - 1.0;
  }

  return a;
}
//****************************************************************************80

double biw_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIW_CONDITION computes the L1 condition of the BIW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double VALUE, the L1 condition.
//
{
  double a_norm;
  double aii;
  double b_norm;
  double bij;
  int i;
  int j;
  double value;

  if ( n == 1 )
  {
    a_norm = 0.6;
  }
  else
  {
    a_norm = 1.6;
  }

  b_norm = 0.0;
  j = n;
  for ( i = n; 1 <= i; i-- )
  {
    aii = 0.5 + ( double ) ( i ) / ( double ) ( 10 * n );
    if ( i == j )
    {
      bij = 1.0 / aii;
    }
    else if ( i < j )
    {
      bij = bij / aii;
    }
    b_norm = b_norm + fabs ( bij );
  }

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double biw_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIW_DETERMINANT computes the determinant of the BIW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BIW_DETERMINANT, the determinant.
//
{
  int i;
  double value;

  value = 1.0;
  for ( i = 0; i < n; i++ )
  {
    value = value * ( 0.5 + ( double ) ( i + 1 ) / ( double ) ( 10 * n ) );
  }

  return value;
}
//****************************************************************************80

double *biw_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BIW_INVERSE returns the inverse of the BIW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BIW_INVERSE[N,N], the matrix.
//
{
  double aii;
  double aiip1;
  double *b;
  int i;
  int j;
 
  b = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      b[i+j*n] = 0.0;
    }
  }

  for ( j = n - 1; 0 <= j; j-- )
  {
    for ( i = n - 1; 0 <= i; i-- )
    {
      aii = 0.5 + ( double ) ( i + 1 ) / ( double ) ( 10 * n );
      aiip1 = -1.0;

      if ( i == j )
      {
        b[i+j*n] = 1.0 / aii;
      }
      else if ( i < j )
      {
        b[i+j*n] = - aiip1 * b[i+1+j*n] / aii;
      }
    }
  }

  return b;
}
//****************************************************************************80

double *bodewig ( )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG returns the BODEWIG matrix.
//
//  Example:
//
//    2   1   3   4
//    1  -3   1   5
//    3   1   6  -2
//    4   5  -2  -1
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is symmetric: A' = A.
//
//    det ( A ) = 568.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, double BODEWIG[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
    2.0,  1.0,  3.0,  4.0, 
    1.0, -3.0,  1.0,  5.0, 
    3.0,  1.0,  6.0, -2.0, 
    4.0,  5.0, -2.0, -1.0 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double bodewig_condition ( )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG_CONDITION returns the L1 condition of the BODEWIG matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double BODEWIG_CONDITION, the L1 condition.
//
{
  double cond;

  cond = 10.436619718309862;

  return cond;
}
//****************************************************************************80

double bodewig_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG_DETERMINANT returns the determinant of the BODEWIG matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double BODEWIG_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 568.0;

  return determ;
}
//****************************************************************************80

double *bodewig_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG_EIGENVALUES returns the eigenvalues of the BODEWIG matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double BODEWIG_EIGENVALUES[4], the eigenvalues.
//
{
  double *lambda;
  static double lambda_save[4] = {
    -8.028578352396531, 
     7.932904717870018, 
     5.668864372830019, 
    -1.573190738303506 };

  lambda = r8vec_copy_new ( 4, lambda_save );

  return lambda;
}
//****************************************************************************80

double *bodewig_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG_INVERSE returns the inverse of the BODEWIG matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double BODEWIG_INVERSE[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
    -139.0/ 568.0,  165.0/ 568.0,  79.0/ 568.0,  111.0/ 568.0, 
     165.0/ 568.0, -155.0/ 568.0, -57.0/ 568.0,   -1.0/ 568.0, 
      79.0/ 568.0,  -57.0/ 568.0,  45.0/ 568.0,  -59.0/ 568.0, 
     111.0/ 568.0,   -1.0/ 568.0, -59.0/ 568.0,  -11.0/ 568.0  };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

void bodewig_plu ( double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG_PLU returns the PLU factors of the BODEWIG matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double P[4*4], L[4*4], U[4*4], the PLU factors.
//
{
//
//  Note that the matrix entries are listed by column.
//
  static double l_save[4*4] = {
   1.0, 0.25, 0.75,              0.50, 
   0.0, 1.00, 0.647058823529412, 0.352941176470588, 
   0.0, 0.00, 1.0,               0.531531531531532, 
   0.0, 0.00, 0.0,               1.0 };
  static double p_save[4*4] = {
    0.0,  0.0,  0.0,  1.0, 
    0.0,  1.0,  0.0,  0.0, 
    0.0,  0.0,  1.0,  0.0, 
    1.0,  0.0,  0.0,  0.0 };
  static double u_save[4*4] = {
    4.0,  0.00,  0.0,               0.0, 
    5.0, -4.25,  0.00,              0.0, 
   -2.0,  1.50,  6.529411764705882, 0.0, 
   -1.0,  5.25, -4.647058823529412, 5.117117117117118 };

  r8mat_copy ( 4, 4, l_save, l );
  r8mat_copy ( 4, 4, p_save, p );
  r8mat_copy ( 4, 4, u_save, u );

  return;
}
//****************************************************************************80

double *bodewig_rhs ( )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG_RHS returns the BODEWIG right hand side.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double BODEWIG_RHS[4], the right hand side vector.
//
{
  double *b;
  static double b_save[4] = { 29.0, 18.0, 15.0, 4.0 };

  b = r8vec_copy_new ( 4, b_save );

  return b;
}
//****************************************************************************80

double *bodewig_eigen_right ( )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG_EIGEN_RIGHT returns the right eigenvectors of the BODEWIG matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double BODEWIG_EIGEN_RIGHT[4*4], the right eigenvector matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
   0.263462395147524,  
   0.659040718046439,
  -0.199633529128396,
  -0.675573350827063,
   0.560144509774526,
   0.211632763260098,
   0.776708263894565,
   0.195381612446620,
   0.378702689441644,
   0.362419048574935,
  -0.537935161097828,
   0.660198809976478,
  -0.688047939843040,
   0.624122855455373,
   0.259800864702728,
   0.263750269148100 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double *bodewig_solution ( )

//****************************************************************************80
//
//  Purpose:
//
//    BODEWIG_SOLUTION returns the BODEWIG_SOLUTION
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, BODEWIG_SOLUTION[4], the solution.
//
{
  double *x;
  static double x_save[4] = { 1.0, 2.0, 3.0, 4.0 };

  x = r8vec_copy_new ( 4, x_save );

  return x;
}
//****************************************************************************80

double *boothroyd ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BOOTHROYD returns the BOOTHROYD matrix.
//
//  Formula:
//
//    A(I,J) = C(N+I-1,I-1) * C(N-1,N-J) * N / ( I + J - 1 )
//
//  Example:
//
//    N = 5
//
//     5    10    10     5     1
//    15    40    45    24     5
//    35   105   126    70    15
//    70   224   280   160    35
//   126   420   540   315    70
//
//  Properties:
//
//    A is not symmetric.
//
//    A is positive definite.
//
//    det ( A ) = 1.
//
//    The inverse matrix has the same entries, but with alternating sign.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Boothroyd,
//    Algorithm 274:
//    Generation of Hilbert Derived Test Matrix,
//    Communications of the ACM,
//    Volume 9, Number 1, January 1966, page 11.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BOOTHROYD[N*N] the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      a[i-1+(j-1)*n] = r8_choose ( n + i - 1, i - 1 ) 
        * r8_choose ( n - 1, n - j ) * ( double ) ( n ) 
       / ( double ) ( i + j - 1 );
    }
  }
  return a;
}
//****************************************************************************80

double boothroyd_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BOOTHROYD_CONDITION returns the L1 condition of the BOOTHROYD matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BOOTHROYD_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  int i;
  int j;
  double s;
  double value;

  a_norm = 0.0;
  for ( j = 1; j <= n; j++ )
  {
    s = 0.0;
    for ( i = 1; i <= n; i++ )
    {
      s = s + r8_choose ( n + i - 1, i - 1 ) * r8_choose ( n - 1, n - j ) 
        * ( double ) ( n ) / ( double ) ( i + j - 1 );
    }
    if ( a_norm < s )
    {
      a_norm = s;
    }
  }

  b_norm = a_norm;

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double boothroyd_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BOOTHROYD_DETERMINANT returns the determinant of the BOOTHROYD matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BOOTHROYD_DETERMINANT, the determinant.
//
{
  double value;

  value = 1.0;

  return value;
}
//****************************************************************************80

double *boothroyd_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BOOTHROYD_INVERSE returns the inverse of the BOOTHROYD matrix.
//
//  Example:
//
//    N = 5
//
//      5   -10    10    -5     1
//    -15    40   -45    24    -5
//     35  -105   126   -70    15
//    -70   224  -280   160   -35
//    126  -420   540  -315    70
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BOOTHROYD_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      a[i-1+(j-1)*n] = r8_mop ( i + j ) * r8_choose ( n + i - 1, i - 1 ) 
        * r8_choose ( n - 1, n - j ) * ( double ) ( n ) 
        / ( double ) ( i + j - 1 );
    }
  }
  return a;
}
//****************************************************************************80

double *borderband ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BORDERBAND returns the BORDERBAND matrix.
//
//  Formula:
//
//    If ( I = J )
//      A(I,I) = 1
//    else if ( I = N )
//      A(N,J) = 2^(1-J)
//    else if ( J = N )
//      A(I,N) = 2^(1-I)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//     1  0   0   0   1
//     0  1   0   0  1/2
//     0  0   1   0  1/4
//     0  0   0   1  1/8
//     1 1/2 1/4 1/8  1
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    A is border-banded.
//
//    A has N-2 eigenvalues of 1.
//
//    det ( A ) = 1 - sum ( 1 <= I <= N-1 ) 2^(2-2*I)
//
//    For N = 2, A is singular.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BORDERBAND[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i == j )
      {
        a[i-1+(j-1)*n] = 1.0;
      }
      else if ( j == n )
      {
        a[i-1+(j-1)*n] = pow ( 2.0, 1 - i );
      }
      else if ( i == n )
      {
        a[i-1+(j-1)*n] = pow ( 2.0, 1 - j );
      }
      else
      {
        a[i-1+(j-1)*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double borderband_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BORDERBAND_DETERMINANT returns the determinant of the BORDERBAND matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BORDERBAND_DETERMINANT, the determinant.
//
{
  double determ;
  int i;

  determ = 0.0;
  for ( i = 1; i <= n - 1; i++ )
  {
    determ = determ - pow ( 2.0, 2 - 2 * i );
  }
  determ = determ + 1.0;

  return determ;
}
//****************************************************************************80

double *borderband_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    BORDERBAND_INVERSE returns the inverse of the BORDERBAND matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double BORDERBAND_INVERSE[N*N], the inverse matrix.
//
{
  double *a;
  double *l;
  double *l_inverse;
  double *lp_inverse;
  double *p;
  double *p_inverse;
  double *u;
  double *u_inverse;

  p = new double[n*n];
  l = new double[n*n];
  u = new double[n*n];

  borderband_plu ( n, p, l, u );

  p_inverse = r8mat_transpose_new ( n, n, p );

  l_inverse = tri_l1_inverse ( n, l );

  lp_inverse = r8mat_mm_new ( n, n, n, l_inverse, p_inverse );

  u_inverse = tri_u_inverse ( n, u );

  a = r8mat_mm_new ( n, n, n, u_inverse, lp_inverse );
//
//  Free memory.
//
  delete [] l;
  delete [] l_inverse;
  delete [] lp_inverse;
  delete [] p;
  delete [] p_inverse;
  delete [] u;
  delete [] u_inverse;

  return a;
}
//****************************************************************************80

void borderband_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    BORDERBAND_PLU returns the PLU factors of the BORDERBAND matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;
  int k;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        l[i+j*n] = 1.0;
      }
      else if ( i == n - 1 )
      {
        l[i+j*n] = pow ( 2.0, - j );
      }
      else
      {
        l[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == n - 1 && j == n - 1 )
      {
        u[i+j*n] = 0.0;
        for ( k = 1; k < n - 1; k++ )
        {
          u[i+j*n] = u[i+j*n] - pow ( 2.0, - 2 * k );
        }
      }
      else if ( i == j )
      {
        u[i+j*n] = 1.0;
      }
      else if ( j == n - 1 )
      {
        u[i+j*n] = pow ( 2.0, - i );
      }
      else
      {
        u[i+j*n] = 0.0;
      }
    }
  }

  return;
}
//****************************************************************************80

void bvec_next_grlex ( int n, int bvec[] )

//****************************************************************************80
//
//  Purpose:
//
//    BVEC_NEXT generates the next binary vector in GRLEX order.
//
//  Discussion:
//
//    N = 3
//
//    Input      Output
//    -----      ------
//    0 0 0  =>  0 0 1
//    0 0 1  =>  0 1 0
//    0 1 0  =>  1 0 0
//    1 0 0  =>  0 1 1
//    0 1 1  =>  1 0 1
//    1 0 1  =>  1 1 0
//    1 1 0  =>  1 1 1
//    1 1 1  =>  0 0 0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the dimension of the vectors.
//
//    int BVEC[N], a vector.  
//
//  Output:
//
//    int BVEC[N], the successor to the input vector.  
//
{
  int i;
  int o;
  int s;
  int z;
//
//  Initialize locations of 0 and 1.
//
  if ( bvec[0] == 0 )
  {
    z = 0;
    o = -1;
  }
  else
  {
    z = -1;
    o = 0;
  }
//
//  Moving from right to left, search for a "1", preceded by a "0".
//
  for ( i = n - 1; 1 <= i; i-- )
  {
    if ( bvec[i] == 1 )
    {
      o = i;
      if ( bvec[i-1] == 0 )
      {
        z = i - 1;
        break;
      }
    }
  }
//
//  BVEC = 0
//
  if ( o == -1 )
  {
    bvec[n-1] = 1;
  }
//
//  01 never occurs.  So for sure, B(1) = 1.
//
  else if ( z == -1 )
  {
    s = 0;
    for ( i = 0; i < n; i++ )
    {
      s = s + bvec[i];
    }
    if ( s == n )
    {
      for ( i = 0; i < n; i++ )
      {
        bvec[i] = 0;
      }
    }
    else
    {
      for ( i = 0; i < n - s - 1; i++ )
      {
        bvec[i] = 0;
      }
      for ( i = n - s - 1; i < n; i++ )
      {
        bvec[i] = 1;
      }
    }
  }
//
//  Found the rightmost "01" string.
//  Replace it by "10".
//  Shift following 1's to the right.
//
  else
  {
    bvec[z] = 1;
    bvec[o] = 0;
    s = 0;
    for ( i = o + 1; i < n; i++ )
    {
      s = s + bvec[i];
    }
    for ( i = o + 1; i < n - s; i++ )
    {
      bvec[i] = 0;
    }
    for ( i = n - s; i < n; i++ )
    {
      bvec[i] = 1;
    }
  }

  return;
}
//****************************************************************************80

double c8_abs ( complex <double> x )

//****************************************************************************80
//
//  Purpose:
//
//    C8_ABS returns the absolute value of a C8.
//
//  Discussion:
//
//    A C8 is a double precision complex value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, complex <double> X, the value to be handled.
//
//    Output, double C8_ABS, the absolute value of X.
//
{
  double value;

  value = sqrt ( pow ( real ( x ), 2 ) 
               + pow ( imag ( x ), 2 ) );

  return value;
}
//****************************************************************************80

complex <double> c8_i ( )

//****************************************************************************80
//
//  Purpose:
//
//    C8_I returns the value of the imaginary unit, i as a C8.
//
//  Discussion:
//
//    A C8 is a double precision complex value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, complex <double> C8_I, the value of complex i.
//
{
  complex <double> value;

  value = complex <double> ( 0.0, 1.0 );

  return value;
}
//****************************************************************************80

bool c8_le_l2 ( complex <double> x, complex <double> y )

//****************************************************************************80
//
//  Purpose:
//
//    C8_LE_L2 := X <= Y for C8 values, and the L2 norm.
//
//  Discussion:
//
//    A C8 is a complex double precision value.
//
//    The L2 norm can be defined here as:
//
//      C8_NORM_L2(X) = sqrt ( ( real (X) )^2 + ( imag (X) )^2 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, complex <double> X, Y, the values to be compared.
//
//    Output, bool C8_LE_L2, is TRUE if X <= Y.
//
{
  bool value;

  if ( pow ( real ( x ), 2 ) + pow ( imag ( x ), 2 ) <= 
       pow ( real ( y ), 2 ) + pow ( imag ( y ), 2 ) )
  {
    value = true;
  }
  else
  {
    value = false;
  }
  return value;
}
//****************************************************************************80

complex <double> c8_normal_01 ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    C8_NORMAL_01 returns a unit pseudonormal C8.
//
//  Discussion:
//
//    A C8 is a double precision complex value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    int &SEED, a seed for the random number generator.
//
//    Output, complex <double> C8_NORMAL_01, a unit pseudornormal value.
//
//  Output:
//
//    int &SEED, an updated seed.
//
{
  const double r8_pi = 3.141592653589793;
  double v1;
  double v2;
  double x_c;
  double x_r;
  complex <double> value;

  v1 = r8_uniform_01 ( seed );
  v2 = r8_uniform_01 ( seed );

  x_r = sqrt ( - 2.0 * log ( v1 ) ) * cos ( 2.0 * r8_pi * v2 );
  x_c = sqrt ( - 2.0 * log ( v1 ) ) * sin ( 2.0 * r8_pi * v2 );

  value = complex <double> ( x_r, x_c );

  return value;
}
//****************************************************************************80

complex <double> c8_one ( )

//****************************************************************************80
//
//  Purpose:
//
//    C8_ONE returns the value of complex 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, complex <double> C8_ONE, the value of complex 1.
//
{
  complex <double> value;

  value = complex <double> ( 1.0, 0.0 );

  return value;
}
//****************************************************************************80

void c8_swap ( complex <double> *x, complex <double> *y )

//****************************************************************************80
//
//  Purpose:
//
//    C8_SWAP swaps two C8's.
//
//  Discussion:
//
//    A C8 is a double precision complex value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    complex <double> *X, *Y, two values.
//
//  Output:
//
//    complex <double> *X, *Y, the values have been interchanged.
//
{
  complex <double> z;

   z = *x; 
  *x = *y;
  *y =  z;

  return;
}
//****************************************************************************80

complex <double> c8_uniform_01 ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    C8_UNIFORM_01 returns a unit pseudorandom C8.
//
//  Discussion:
//
//    A C8 is a double precision complex value.
//
//    The angle should be uniformly distributed between 0 and 2 * PI,
//    the square root of the radius uniformly distributed between 0 and 1.
//
//    This results in a uniform distribution of values in the unit circle.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    int &SEED, the "seed" value, which should NOT be 0.
//
//  Output:
//
//    Output, complex <double> C8_UNIFORM_01, a pseudorandom complex value.
//
//    int &SEED, an updated seed.
{
  double r;
  int k;
  const double r8_pi = 3.141592653589793;
  double theta;
  complex <double> value;

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )
  {
    seed = seed + 2147483647;
  }

  r = sqrt ( ( double ) ( seed ) * 4.656612875E-10 );

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )
  {
    seed = seed + 2147483647;
  }

  theta = 2.0 * r8_pi * ( ( double ) ( seed ) * 4.656612875E-10 );

  value = r * complex <double> ( cos ( theta ), sin ( theta ) );

  return value;
}
//****************************************************************************80

complex <double> c8_zero ( )

//****************************************************************************80
//
//  Purpose:
//
//    C8_ZERO returns the value of 0 as a C8.
//
//  Discussion:
//
//    A C8 is a double precision complex value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, complex <double> C8_ZERO, the value of complex 0.
//
{
  complex <double> value;

  value = complex <double> ( 0.0, 0.0 );

  return value;
}
//****************************************************************************80

complex <double> *c8mat_copy_new ( int m, int n, complex <double> a1[] )

//****************************************************************************80
//
//  Purpose:
//
//    C8MAT_COPY_NEW copies one C8MAT to a "new" C8MAT.
//
//  Discussion:
//
//    An C8MAT is a doubly dimensioned array of complex double precision values, 
//    which may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, complex <double> A1[M*N], the matrix to be copied.
//
//    Output, complex <double> C8MAT_COPY_NEW[M*N], the copy of A1.
//
{
  complex <double> *a2;
  int i;
  int j;

  a2 = new complex <double>[m*n];

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

complex <double> *c8mat_identity ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    C8MAT_IDENTITY sets a C8MAT to the identity.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> C8MAT_IDENTITY[N*N], the matrix.
//
{
  complex <double> *a;
  int i;
  int j;

  a = new complex <double> [n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = complex <double> ( 1.0, 0.0 );
      }
      else
      {
        a[i+j*n] = complex <double> ( 0.0, 0.0 );
      }
    }
  }
  return a;
}
//****************************************************************************80

double c8mat_is_eigen_right ( int n, int k, complex <double> a[], 
  complex <double> x[], complex <double> lambda[] )

//****************************************************************************80
//
//  Purpose:
//
//    c8mat_is_eigen_right(): error in a complex right eigensystem.
//
//  Discussion:
//
//    A C8MAT is a matrix of complex doubles.
//
//    This routine computes the Frobenius norm of
//
//      A * X - X * LAMBDA
//
//    where
//
//      A is an N by N matrix,
//      X is an N by K matrix (each of K columns is an eigenvector)
//      LAMBDA is a K by K diagonal matrix of eigenvalues.
//
//    This routine assumes that A, X and LAMBDA are all complex.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//    int K, the number of eigenvectors.
//    K is usually 1 or N.
//
//    complex <double> A[N*N], the matrix.
//
//    complex <double> X[N*K], the K eigenvectors.
//
//    complex <double> LAMBDA[K], the K eigenvalues.
//
//  Output:
//
//    double C8MAT_IS_EIGEN_RIGHT, the Frobenius norm
//    of the difference matrix A * X - X * LAMBDA, which would be exactly zero
//    if X and LAMBDA were exact eigenvectors and eigenvalues of A.
//
{
  complex <double> *c;
  double error_frobenius;
  int i;
  int j;
//
//  C = A * X
//
  c = c8mat_mm_new ( n, n, k, a, x );
//
//  C = C - LAMBDA * X
//
  for ( j = 0; j < k; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      c[i+j*n] = c[i+j*n] - lambda[j] * x[i+j*n];
    }
  }

  error_frobenius = c8mat_norm_fro ( n, k, c );
//
//  Free memory.
//
  delete [] c;

  return error_frobenius;
}
//****************************************************************************80

complex <double> *c8mat_mm_new ( int n1, int n2, int n3, complex <double> a[], 
  complex <double> b[] )

//****************************************************************************80
//
//  Purpose:
//
//    C8MAT_MM_NEW multiplies two C8MAT's.
//
//  Discussion:
//
//    A C8MAT is a doubly dimensioned array of C8 values, stored as a vector
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
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N1, N2, N3, the order of the matrices.
//
//    Input, complex <double> A[N1*N2], complex <double> B[N2*N3], 
//    the matrices to multiply.
//
//    Output, complex <double> C[N1*N3], the product matrix C = A * B.
//
{
  complex <double> *c;
  int i;
  int j;
  int k;

  c = new complex <double> [n1*n3];

  for ( i = 0; i < n1; i ++ )
  {
    for ( j = 0; j < n3; j++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[i+k*n1] * b[k+j*n2];
      }
    }
  }
  return c;
}
//****************************************************************************80

double c8mat_norm_fro ( int m, int n, complex <double> a[] )

//****************************************************************************80
//
//  Purpose:
//
//    C8MAT_NORM_FRO returns the Frobenius norm of a C8MAT.
//
//  Discussion:
//
//    The Frobenius norm is defined as
//
//      C8MAT_NORM_FRO = sqrt (
//        sum ( 1 <= I <= M ) Sum ( 1 <= J <= N ) |A(I,J)| )
//
//    The matrix Frobenius-norm is not derived from a vector norm, but
//    is compatible with the vector L2 norm, so that:
//
//      c8vec_norm_l2 ( A*x ) <= c8mat_norm_fro ( A ) * c8vec_norm_l2 ( x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, complex <double> A[M*N], the matrix.
//
//    Output, double C8MAT_NORM_FRO, the Frobenius norm of A.
//
{
  int i;
  int j;
  double value;

  value = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      value = value + pow ( real ( a[i+j*m] ), 2 )
                    + pow ( imag ( a[i+j*m] ), 2 );
    }
  }
  value = sqrt ( value );

  return value;
}
//****************************************************************************80

void c8mat_print ( int m, int n, complex <double> a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    C8MAT_PRINT prints a C8MAT.
//
//  Discussion:
//
//    A C8MAT is a matrix of double precision complex values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix.
//
//    Input, complex <double> A[M*N], the matrix.
//
//    Input, string TITLE, a title.
//
{
  c8mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
//****************************************************************************80

void c8mat_print_some ( int m, int n, complex <double> a[], int ilo, int jlo, 
  int ihi, int jhi, string title )

//****************************************************************************80
//
//  Purpose:
//
//    C8MAT_PRINT_SOME prints some of a C8MAT.
//
//  Discussion:
//
//    A C8MAT is a matrix of double precision complex values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix.
//
//    Input, complex <double> A[M*N], the matrix.
//
//    Input, int ILO, JLO, IHI, JHI, the first row and
//    column, and the last row and column to be printed.
//
//    Input, string TITLE, a title.
//
{
  complex <double> c;
  int i;
  int i2hi;
  int i2lo;
  int inc;
  int incx = 4;
  int j;
  int j2;
  int j2hi;
  int j2lo;

  cout << "\n";
  cout << title << "\n";
//
//  Print the columns of the matrix, in strips of INCX.
//
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + incx )
  {
    j2hi = j2lo + incx - 1;
    j2hi = i4_min ( j2hi, n );
    j2hi = i4_min ( j2hi, jhi );

    inc = j2hi + 1 - j2lo;

    cout << "\n";
    cout << "  Col: ";
    for ( j = j2lo; j <= j2hi; j++ )
    {
      j2 = j + 1 - j2lo;
      cout << "          " << setw(10) << j;
    }
    cout << "\n";
    cout << "  Row\n";
    cout << "  ---\n";
//
//  Determine the range of the rows in this strip.
//
    i2lo = i4_max ( ilo, 1 );
    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )
    {
//
//  Print out (up to) INCX entries in row I, that lie in the current strip.
//
      for ( j2 = 1; j2 <= inc; j2++ )
      {
        j = j2lo - 1 + j2;
        c = a[i-1+(j-1)*m];
        cout << "  " << setw(8) << real ( c )
             << "  " << setw(8) << imag ( c );
      }
      cout << "\n";
    }
  }

  return;
}
//****************************************************************************80

complex <double> *c8mat_uniform_01 ( int m, int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    C8MAT_UNIFORM_01 returns a unit pseudorandom C8MAT.
//
//  Discussion:
//
//    A C8MAT is a matrix of double precision complex values.
//
//    The angles should be uniformly distributed between 0 and 2 * PI,
//    the square roots of the radius uniformly distributed between 0 and 1.
//
//    This results in a uniform distribution of values in the unit circle.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int M, N, the number of rows and columns in the matrix.
//
//    int &SEED, the "seed" value, which should NOT be 0.
//
//  Output:
//
//    complex <double> C[M*N], the pseudorandom complex matrix.
//
//    int &SEED, an updated seed.
//
{
  complex <double> *c;
  int i;
  int j;
  double r;
  int k;
  const double r8_pi = 3.141592653589793;
  double theta;

  c = new complex <double> [m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )
      {
        seed = seed + 2147483647;
      }

      r = sqrt ( ( double ) ( seed ) * 4.656612875E-10 );

      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )
      {
        seed = seed + 2147483647;
      }

      theta = 2.0 * r8_pi * ( ( double ) ( seed ) * 4.656612875E-10 );

      c[i+j*m] = r * complex <double> ( cos ( theta ), sin ( theta ) );
    }
  }

  return c;
}
//****************************************************************************80

complex <double> *c8mat_zero_new ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    C8MAT_ZERO_NEW returns a new zeroed C8MAT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Output, complex <double> C8MAT_ZERO[M*N], the new zeroed matrix.
//
{
  complex <double> *a;
  int i;
  int j;

  a = new complex <double>[m*n];

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

complex <double> *c8vec_copy_new ( int n, complex <double> a1[] )

//****************************************************************************80
//
//  Purpose:
//
//    C8VEC_COPY_NEW copies a C8VEC to a "new" C8VEC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input, complex <double> A1[N], the vector to be copied.
//
//    Output, complex <double> C8VEC_COPY_NEW[N], the copy of A1.
//
{
  complex <double> *a2;
  int i;

  a2 = new complex <double>[n];

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return a2;
}
//****************************************************************************80

double c8vec_norm_l2 ( int n, complex <double> a[] )

//****************************************************************************80
//
//  Purpose:
//
//    C8VEC_NORM_L2 returns the L2 norm of a C8VEC.
//
//  Discussion:
//
//    The vector L2 norm is defined as:
//
//      value = sqrt ( sum ( 1 <= I <= N ) conjg ( A(I) ) * A(I) ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in A.
//
//    Input, complex <double> A[N], the vector whose L2 norm is desired.
//
//    Output, double C8VEC_NORM_L2, the L2 norm of A.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value 
          + real ( a[i] ) * real ( a[i] ) 
          + imag ( a[i] ) * imag ( a[i] );
  }
  value = sqrt ( value );

  return value;
}
//****************************************************************************80

void c8vec_print ( int n, complex <double> a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    C8VEC_PRINT prints a C8VEC, with an optional title.
//
//  Discussion:
//
//    A C8VEC is a vector of double precision complex values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, complex <double> A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(6) << i+1
         << "  " << real ( a[i] )
         << "  " << imag ( a[i] ) << "\n";
  }

  return;
}
//****************************************************************************80

complex <double> *c8vec_uniform_01 ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    C8VEC_UNIFORM_01 returns a unit C8VEC.
//
//  Discussion:
//
//    A C8VEC is a vector of double precision complex values.
//
//    The angles should be uniformly distributed between 0 and 2 * PI,
//    the square roots of the radius uniformly distributed between 0 and 1.
//
//    This results in a uniform distribution of values in the unit circle.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of values to compute.
//
//    int &SEED, the "seed" value, which should NOT be 0.
//
//  Output:
//
//    complex <double> C8VEC_UNIFORM_01[N], the pseudorandom complex vector.
//
//    int &SEED, an updated seed.
//
{
  complex <double> *c;
  int i;
  double r;
  int k;
  const double r8_pi = 3.141592653589793;
  double theta;

  c = new complex <double> [n];

  for ( i = 0; i < n; i++ )
  {
    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )
    {
      seed = seed + 2147483647;
    }

    r = sqrt ( ( double ) ( seed ) * 4.656612875E-10 );

    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )
    {
      seed = seed + 2147483647;
    }

    theta = 2.0 * r8_pi * ( ( double ) ( seed ) * 4.656612875E-10 );

    c[i] = r * complex <double> ( cos ( theta ), sin ( theta ) );
  }

  return c;
}
//****************************************************************************80

complex <double> *c8vec_unity ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    C8VEC_UNITY returns the N roots of unity in a C8VEC.
//
//  Discussion:
//
//    A C8VEC is a vector of double precision complex values.
//
//    X(1:N) = exp ( 2 * PI * (0:N-1) / N )
//
//    X(1:N)^N = ( (1,0), (1,0), ..., (1,0) ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of elements of A.
//
//    Output, complex <double> C8VEC_UNITY[N], the N roots of unity.
//
{
  complex <double> *a;
  int i;
  const double r8_pi = 3.141592653589793;
  double theta;

  a = new complex <double> [n];

  for ( i = 0; i < n; i++ )
  {
    theta = r8_pi * ( double ) ( 2 * i ) / ( double ) ( n );
    a[i] = complex <double> ( cos ( theta ), sin ( theta ) );
  }

  return a;
}
//****************************************************************************80

double *carry ( int n, int alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CARRY returns the CARRY matrix.
//
//  Discussion:
//
//    We assume that arithmetic is being done in base ALPHA.  We are adding
//    a column of N digits base ALPHA, as part of adding N random numbers.
//    We know the carry digit, between 0 and N-1, that is being carried into the
//    column sum (the incarry digit), and we want to know the probability of
//    the various carry digits 0 through N-1 (the outcarry digit) that could
//    be carried out of the column sum.
//
//    The carry matrix summarizes this data.  The entry A(I,J) represents
//    the probability that, given that the incarry digit is I-1, the
//    outcarry digit will be J-1.
//
//  Formula:
//
//    A(I,J) = ( 1 / ALPHA )^N * sum ( 0 <= K <= J-1 - floor ( I-1 / ALPHA ) )
//      (-1)^K * C(N+1,K) * C(N-I+(J-K)*ALPHA, N )
//
//  Example:
//
//    ALPHA = 10, N = 4
//
//    0.0715 0.5280 0.3795 0.0210
//    0.0495 0.4840 0.4335 0.0330
//    0.0330 0.4335 0.4840 0.0495
//    0.0210 0.3795 0.5280 0.0715
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is a Markov matrix.
//
//    A is centrosymmetric: A(I,J) = A(N+1-I,N+1-J).
//
//    LAMBDA(I) = 1 / ALPHA^(I-1)
//
//    det ( A ) = 1 / ALPHA^((N*(N-1))/2)
//
//    The eigenvectors do not depend on ALPHA.
//
//    A is generally not normal: A' * A /= A * A'.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Holte,
//    Carries, Combinatorics, and an Amazing Matrix,
//    The American Mathematical Monthly,
//    Volume 104, Number 2, February 1997, pages 138-149.
//
//  Parameters:
//
//    Input, int ALPHA, the numeric base being used in the addition.
//
//    Input, int N, the order of the matrix.
//
//    Output, double CARRY[N*N], the matrix.
//
{
  double *a;
  double c1;
  double c2;
  int i;
  int j;
  int k;
  double temp;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      temp = 0.0;
      for ( k = 0; k <= j - ( i / alpha ); k++ )
      {
        c1 = r8_choose ( n + 1, k );
        c2 = r8_choose ( n - ( i + 1 ) + ( j + 1 - k ) * alpha, n );
        temp = temp + r8_mop ( k ) * c1 * c2;
      }
      a[i+j*n] = temp / ( double ) ( i4_power ( alpha, n ) );
    }
  }
  return a;
}
//****************************************************************************80

double carry_determinant ( int n, int alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CARRY_DETERMINANT returns the determinant of the CARRY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int ALPHA, the numeric base being used in the addition.
//
//    Output, double CARRY_DETERMINANT, the determinant.
//
{
  double determ;
  int power;

  power = ( n * ( n - 1 ) ) / 2;
  determ = 1.0 / ( double ) ( i4_power ( alpha, power ) );

  return determ;
}
//****************************************************************************80

double *carry_eigen_left ( int n, int alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CARRY_EIGEN_LEFT returns the left eigenvectors of the CARRY matrix.
//
//  Formula:
//
//    A(I,J) = sum ( 0 <= K <= J-1 )
//      (-1)^K * C(N+1,K) * ( J - K )^(N+1-I)
//
//  Example:
//
//    N = 4
//
//    1  11  11   1
//    1   3  -3  -1
//    1  -1  -1   1
//    1  -3   3  -1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    Column 1 is all 1's, and column N is (-1)^(I+1).
//
//    The top row is proportional to a row of Eulerian numbers, and
//    can be normalized to represent the stationary probablities
//    for the carrying process when adding N random numbers.
//
//    The bottom row is proportional to a row of Pascal's triangle,
//    with alternating signs.
//
//    The product of the left and right eigenvector matrices of
//    order N is N! times the identity.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Holte,
//    Carries, Combinatorics, and an Amazing Matrix,
//    The American Mathematical Monthly,
//    Volume 104, Number 2, February 1997, pages 138-149.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int ALPHA, the numeric base being used in the addition.
//
//    Output, double CARRY_EIGEN_LEFT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
      for ( k = 0; k <= j; k++ )
      {
        a[i+j*n] = a[i+j*n] + r8_mop ( k ) * r8_choose ( n + 1, k ) 
          * ( double ) ( i4_power ( j + 1 - k, n - i ) );
      }
    }
  }

  return a;
}
//****************************************************************************80

double *carry_eigen_right ( int n, int alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CARRY_EIGEN_RIGHT returns the right eigenvectors of the CARRY matrix.
//
//  Discussion:
//
//    A(I,J) = sum ( N+1-J) <= K <= N )
//      S1(N,K) * C(K,N+1-J) ( N - I )^(K-N+J-1)
//
//    where S1(N,K) is a signed Sterling number of the first kind.
//
//  Example:
//
//    N = 4
//
//    1   6  11   6
//    1   2  -1  -2
//    1  -2  -1   2
//    1  -6  11  -6
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    The first column is all 1's.
//
//    The last column is reciprocals of binomial coefficients with
//    alternating sign multiplied by (N-1)!.
//
//    The top and bottom rows are the unsigned and signed Stirling numbers
//    of the first kind.
//
//    The entries in the J-th column are a degree (J-1) polynomial
//    in the row index I.  (Column 1 is constant, the first difference
//    in column 2 is constant, the second difference in column 3 is
//    constant, and so on.)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Holte,
//    Carries, Combinatorics, and an Amazing Matrix,
//    The American Mathematical Monthly,
//    Volume 104, Number 2, February 1997, pages 138-149..
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int ALPHA, the numeric base being used in the addition.
//
//    Output, double CARRY_EIGEN_RIGHT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  double *s1;

  a = new double[n*n];

  s1 = stirling ( n, n );

  for ( j = 1; j <= n; j++ )
  {
    for ( i = 1; i <= n; i++ )
    {
      a[(i-1)+(j-1)*n] = 0.0;
      for ( k = n + 1 - j; k <= n; k++ )
      {
        if ( n - i == 0 && k - n + j - 1 == 0 )
        {
          a[(i-1)+(j-1)*n] = a[(i-1)+(j-1)*n] 
            + s1[n-1+(k-1)*n] * r8_choose ( k, n + 1 - j );
        }
        else
        {
          a[(i-1)+(j-1)*n] = a[(i-1)+(j-1)*n] 
            + s1[n-1+(k-1)*n] * r8_choose ( k, n + 1 - j ) 
            * ( double ) ( i4_power ( n - i, k - n + j - 1 ) );
        }
      }
    }
  }
//
//  Free memory.
//
  delete [] s1;

  return a;
}
//****************************************************************************80

double *carry_eigenvalues ( int n, int alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CARRY_EIGENVALUES returns the eigenvalues of the CARRY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int ALPHA, the numeric base being used in the addition.
//
//    Output, double CARRY_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = 1.0 / ( double ) ( i4_power ( alpha, i ) );
  }
  return lambda;
}
//****************************************************************************80

double *carry_inverse ( int n, int alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CARRY_INVERSE returns the inverse of the CARRY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int ALPHA, the numeric base being used in the addition.
//
//    Output, double CARRY_INVERSE[N*N], the matrix.
//
{
  double *a;
  double *d;
  int i;
  int j;
  double t;
  double *u;
  double *v;

  v = carry_eigen_left ( n, alpha );

  d = carry_eigenvalues ( n, alpha );

  u = carry_eigen_right ( n, alpha );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      v[i+j*n] = v[i+j*n] / d[i];
    }
  } 

  a = r8mat_mm_new ( n, n, n, u, v );

  t = r8_factorial ( n );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = a[i+j*n] / t;
    }
  }
//
//  Free memory.
//
  delete [] d;
  delete [] u;
  delete [] v;

  return a;
}
//****************************************************************************80

double *cauchy ( int n, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    CAUCHY returns the CAUCHY matrix.
//
//  Formula:
//
//    A(I,J) = 1.0 / ( X(I) + Y(J) )
//
//  Example:
//
//    N = 5, X = ( 1, 3, 5, 8, 7 ), Y = ( 2, 4, 6, 10, 9 )
//
//    1/3  1/5  1/7  1/11 1/10
//    1/5  1/7  1/9  1/13 1/12
//    1/7  1/9  1/11 1/15 1/14
//    1/10 1/12 1/14 1/18 1/17
//    1/9  1/11 1/13 1/17 1/16
//
//    or, in decimal form,
//
//    0.333333      0.200000      0.142857      0.0909091     0.100000
//    0.200000      0.142857      0.111111      0.0769231     0.0833333
//    0.142857      0.111111      0.0909091     0.0666667     0.0714286
//    0.100000      0.0833333     0.0714286     0.0555556     0.0588235
//    0.111111      0.0909091     0.0769231     0.0588235     0.0625000
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is totally positive if 0 < X(1) < ... < X(N) and 0 < Y1 < ... < Y(N).
//
//    A will be singular if any X(I) equals X(J), or
//    any Y(I) equals Y(J), or if any X(I)+Y(J) equals zero.
//
//    A is generally not normal: A' * A /= A * A'.
//
//    The Hilbert matrix is a special case of the Cauchy matrix.
//
//    The Parter matrix is a special case of the Cauchy matrix.
//
//    The Ris or "ding-dong" matrix is a special case of the Cauchy matrix.
//
//    det ( A ) = product ( 1 <= I < J <= N ) ( X(J) - X(I) )* ( Y(J) - Y(I) )
//           / product ( 1 <= I <= N, 1 <= J <= N ) ( X(I) + Y(J) )
//
//    The inverse of A is
//
//      INVERSE(A)(I,J) = product ( 1 <= K <= N ) [ (X(J)+Y(K)) * (X(K)+Y(I)) ] /
//            [ (X(J)+Y(I)) * product ( 1 <= K <= N, K /= J ) (X(J)-X(K))
//                          * product ( 1 <= K <= N, K /= I ) (Y(I)-Y(K)) ]
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Nicholas Higham,
//    Accuracy and Stability of Numerical Algorithms,
//    SIAM, 1996.
//
//    Donald Knuth,
//    The Art of Computer Programming,
//    Volume 1, Fundamental Algorithms, Second Edition
//    Addison-Wesley, Reading, Massachusetts, 1973, page 36.
//
//    Olga Taussky, Marvin Marcus,
//    Eigenvalues of finite matrices,
//    in Survey of Numerical Analysis, 
//    Edited by John Todd,
//    McGraw-Hill, pages 279-313, 1962.
//
//    Evgeny Tyrtyshnikov,
//    Cauchy-Toeplitz matrices and some applications,
//    Linear Algebra and Applications,
//    Volume 149, 1991, pages 1-18.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], Y[N], vectors that determine the matrix.
//
//    Output, double CAUCHY[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( x[i] + y[j] == 0.0 )
      {
        cerr << "\n";
        cerr << "CAUCHY - Fatal error!\n";
        cerr << "  The denominator X(I)+Y(J) was zero\n";
        cerr << "  for I = " << i << "\n";
        cerr << "  X(I)  = " << x[i] << "\n";
        cerr << "  and J = " << j << "\n";
        cerr << "  Y(J)  = " << y[j] << "\n";
        exit ( 1 );
      }
      a[i+j*n] = 1.0 / ( x[i] + y[j] );
    }
  }
  return a;
}
//****************************************************************************80

double cauchy_determinant ( int n, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    CAUCHY_DETERMINANT returns the determinant of the CAUCHY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], Y[N], vectors that determine the matrix.
//
//    Output, double CAUCHY_DETERMINANT, the determinant.
//
{
  double bottom;
  double determ;
  int i;
  int j;
  double top;

  top = 1.0;
  for ( i = 0; i < n; i++ )
  {
    for ( j = i + 1; j < n; j++ )
    {
      top = top * ( x[j] - x[i] ) * ( y[j] - y[i] );
    }
  }

  bottom = 1.0;
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      bottom = bottom * ( x[i] + y[j] );
    }
  }
  determ = top / bottom;

  return determ;
}
//****************************************************************************80

double *cauchy_inverse ( int n, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    CAUCHY_INVERSE returns the inverse of the CAUCHY matrix.
//
//  Formula:
//
//    A(I,J) = product ( 1 <= K <= N ) [(X(J)+Y(K))*(X(K)+Y(I))] /
//      [ (X(J)+Y(I)) * product ( 1 <= K <= N, K /= J ) (X(J)-X(K))
//                    * product ( 1 <= K <= N, K /= I ) (Y(I)-Y(K)) ]
//
//  Example:
//
//    N = 5, X = ( 1, 3, 5, 8, 7 ), Y = ( 2, 4, 6, 10, 9 )
//
//       241.70      -2591.37       9136.23      10327.50     -17092.97
//     -2382.19      30405.38    -116727.19    -141372.00     229729.52
//      6451.76     -89667.70     362119.56     459459.00    -737048.81
//     10683.11    -161528.55     690983.38     929857.44   -1466576.75
//    -14960.00     222767.98    -942480.06   -1253376.00    1983696.00
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    The sum of the entries of A equals the sum of the entries of X and Y.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Donald Knuth,
//    The Art of Computer Programming,
//    Volume 1, Fundamental Algorithms, Second Edition,
//    Addison-Wesley, Reading, Massachusetts, 1973, page 36.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], Y[N], vectors that determine the matrix.
//    The following conditions on X and Y must hold:
//
//      X(I)+Y(J) must not be zero for any I and J;
//      X(I) must never equal X(J);
//      Y(I) must never equal Y(J).
//
//    Output, double CAUCHY_INVERSE[N*N], the matrix.
//
{
  double *a;
  double bot1;
  double bot2;
  int i;
  int j;
  int k;
  double top;

  a = new double[n*n];
//
//  Check the data.
//
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( x[i] + y[j] == 0.0 )
      {
        cerr << "\n";
        cerr << "CAUCHY_INVERSE - Fatal error!\n";
        cerr << "  The denominator X(I)+Y(J) was zero\n";
        cerr << "  for I = " << i << "\n";
        cerr << "  and J = " << j << "\n";
        exit ( 1 );
      }

      if ( i != j && x[i] == x[j] )
      {
        cerr << "\n";
        cerr << "CAUCHY_INVERSE - Fatal error!\n";
        cerr << "  X(I) equals X(J)\n";
        cerr << "  for I = " << i << "\n";
        cerr << "  and J = " << j << "\n";
        exit ( 1 );
      }

      if ( i != j && y[i] == y[j] )
      {
        cerr << "\n";
        cerr << "CAUCHY_INVERSE - Fatal error!\n";
        cerr << "  Y(I) equals Y(J)\n";
        cerr << "  for I = " << i << "\n";
        cerr << "  and J = " << j << "\n";
        exit ( 1 );
      }
    }
  }

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      top = 1.0;
      bot1 = 1.0;
      bot2 = 1.0;

      for ( k = 0; k < n; k++ )
      {
        top = top * ( x[j] + y[k] ) * ( x[k] + y[i] );

        if ( k != j )
        {
          bot1 = bot1 * ( x[j] - x[k] );
        }

        if ( k != i )
        {
          bot2 = bot2 * ( y[i] - y[k] );
        }
      }
      a[i+j*n] = top / ( ( x[j] + y[i] ) * bot1 * bot2 );
    }
  }

  return a;
}
//****************************************************************************80

double *cheby_diff1 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_DIFF1 returns the CHEBY_DIFF1 matrix.
//
//  Example:
//
//    N = 6
//
//    8.5000 -10.4721   2.8944  -1.5279   1.1056  -0.5000
//    2.6180  -1.1708  -2.0000   0.8944  -0.6810   0.2764
//   -0.7236   2.0000  -0.1708   1.6180   0.8944  -0.3820
//    0.3820  -0.8944   1.6180   0.1708  -2.0000   0.7236
//   -0.2764   0.6180  -0.8944   2.0000   1.1708  -2.6180
//    0.5000  -1.1056   1.5279  -2.8944  10.4721  -8.5000
//
//  Properties:
//
//    If 1 < N, then det ( A ) = 0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Lloyd Trefethen,
//    Spectral Methods in MATLAB,
//    SIAM, 2000, page 54.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_DIFF1[N*N], the matrix.
//
{
  double *a;
  double *c;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;
  double *x;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = new double[n*n];

  if ( n == 1 )
  {
    a[0+0*n] = 1.0;
    return a;
  }

  c = new double[n];
  c[0] = 2.0;
  for ( i = 1; i < n - 1; i++ )
  {
    c[i] = 1.0;
  }
  c[n-1] = 2.0;
//
//  Get the Chebyshev points.
//
  x = new double[n];

  for ( i = 0; i < n; i++ )
  {
    x[i] = cos ( r8_pi * ( double ) ( i ) / ( double ) ( n - 1 ) );
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i != j )
      {
        a[i+j*n] = r8_mop ( i + j ) * c[i] / ( c[j] * ( x[i] - x[j] ) );
      }
      else if ( i == 0 )
      {
        a[i+j*n] =  ( double ) ( 2 * ( n - 1 ) * ( n - 1 ) + 1 ) / 6.0;
      }
      else if ( i == n - 1 )
      {
        a[i+j*n] = - ( double ) ( 2 * ( n - 1 ) * ( n - 1 ) + 1 ) / 6.0;
      }
      else
      {
        a[i+j*n] = - 0.5 * x[i] / ( 1.0 - x[i] * x[i] ); 
      }
    }
  }
//
//  Free memory.
//
  delete [] c;
  delete [] x;

  return a;
}
//****************************************************************************80

double cheby_diff1_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    cheby_diff1_determinant returns the determinant of the CHEBY_DIFF1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 May 2020
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//  Output:
//
//    double CHEBY_DIFF1_DETERMINANT, the determinant.
//
{
  double value;

  if ( n == 1 )
  {
    value = 1.0;
  }
  else
  {
    value = 0.0;
  }

  return value;
}
//****************************************************************************80

double *cheby_diff1_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_DIFF1_NULL_LEFT returns a left null vector of the CHEBY_DIFF1 matrix.
//
//  Discussion:
//
//    The matrix only has a (nonzero) null vector when M is odd.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double CHEBY1_NULL_LEFT[M], the null vector.
//
{
  int i;
  double t;
  double *x;
  
  x = new double[m];

  if ( ( m % 2 ) == 1 )
  {
    x[0] = 1.0;
    t = -2.0;
    for ( i = 1; i < m - 1; i++ )
    {
      x[i] = t;
      t = - t;
    }
    x[m-1] = 1.0;
  }
  else
  {
    for ( i = 0; i < m; i++ )
    {
      x[i] = 0.0;
    }
  }
  return x;
}
//****************************************************************************80

double *cheby_diff1_null_right ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_DIFF1_NULL_RIGHT returns a right null vector of the CHEBY_DIFF1 matrix.
//
//  Discussion:
//
//    The matrix only has a (nonzero) null vector when N is odd.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double CHEBY1_NULL_RIGHT[N], the null vector.
//
{
  int i;
  double *x;
  
  x = new double[n];

  if ( ( n % 2 ) == 1 )
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = 1.0;
    }
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = 0.0;
    }
  }
  return x;
}
//****************************************************************************80

double *cheby_t ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_T returns the CHEBY_T matrix.
//
//  Discussion
//
//    CHEBY_T is the Chebyshev T matrix, associated with the Chebyshev
//    "T" polynomials, or Chebyshev polynomials of the first kind.
//
//  Example:
//
//    N = 11
//
//    1  .   .    .    .    .    .    .     .   .   .
//    .  1   .    .    .    .    .    .     .   .   .
//   -1  .   2    .    .    .    .    .     .   .   .
//    . -3   .    4    .    .    .    .     .   .   .
//    1  .  -8    .    8    .    .    .     .   .   .
//    .  5   .  -20    .   16    .    .     .   .   .
//   -1  .  18    .  -48    .   32    .     .   .   .
//    . -7   .   56    . -112    .   64     .   .   .
//    1  . -32    .  160    . -256    .   128   .   .
//    .  9   . -120    .  432    . -576     . 256   .
//   -1  .  50    . -400    . 1120    . -1280   . 512
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is reducible.
//
//    A is lower triangular.
//
//    Each row of A sums to 1.
//
//    det ( A ) = 2^( (N-1) * (N-2) / 2 )
//
//    A is not normal: A' * A /= A * A'.
//
//    For I = 1:
//      LAMBDA(1) = 1
//    For 1 < I
//      LAMBDA(I) = 2^(I-2)
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_T[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = r8mat_zero_new ( n, n );

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+1*n] = 1.0;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    j = 0;
    a[i+j*n] = - a[i-2+j*n];
    for ( j = 1; j < n; j++ )
    {
      a[i+j*n] = 2.0 * a[i-1+(j-1)*n] - a[i-2+j*n];
    }
  }
  return a;
}
//****************************************************************************80

double cheby_t_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_T_DETERMINANT returns the determinant of the CHEBY_T matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_DETERMINANT, the determinant.
//
{
  double determ;
  int power;

  power = ( ( n - 1 ) * ( n - 2 ) ) / 2;

  determ = ( double ) i4_power ( 2, power );

  return determ;
}
//****************************************************************************80

double *cheby_t_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_T_INVERSE returns the inverse of the CHEBY_T matrix.
//
//  Example:
//
//    N = 11
//
//      1   .   .  .   .  .  .  .  .  .  .
//      .   1   .  .   .  .  .  .  .  .  .
//      1   .   1  .   .  .  .  .  .  .  .  /   2
//      .   3   .  1   .  .  .  .  .  .  .  /   4
//      3   .   4  .   1  .  .  .  .  .  .  /   8
//      .  10   .  5   .  1  .  .  .  .  .  /  16
//     10   .  15  .   6  .  1  .  .  .  .  /  32
//      .  35   . 21   .  7  .  1  .  .  .  /  64
//     35   .  56  .  28  .  8  .  1  .  .  / 128
//      . 126   . 84   . 36  .  9  .  1  .  / 256
//    126   . 210  . 120  . 45  . 10  .  1  / 512
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_T_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = r8mat_zero_new ( n, n );

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+1*n] = 1.0;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    j = 0;
    a[i+j*n] = a[i-1+(j+1)*n] / 2.0;
    j = 1;
    a[i+j*n] = ( 2.0 * a[i-1+(j-1)*n] + a[i-1+(j+1)*n] ) / 2.0;
    for ( j = 2; j < n - 1; j++ )
    {
      a[i+j*n] = ( a[i-1+(j-1)*n] + a[i-1+(j+1)*n] ) / 2.0;
    }
    j = n - 1;
    a[i+j*n] = a[i-1+(j-1)*n] / 2.0;
  }
  return a;
}
//****************************************************************************80

double *cheby_u ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_U returns the CHEBY_U matrix.
//
//  Discussion
//
//    CHEBY_T is the Chebyshev T matrix, associated with the Chebyshev
//    "T" polynomials, or Chebyshev polynomials of the first kind.
//
//  Example:
//
//    N = 11
//
//    1  .   .    .    .    .    .     .     .   .    .
//    .  2   .    .    .    .    .     .     .   .    .
//   -1  .   4    .    .    .    .     .     .   .    .
//    . -4   .    8    .    .    .     .     .   .    .
//    1  . -12    .   16    .    .     .     .   .    .
//    .  6   .  -32    .   32    .     .     .   .    .
//   -1  .  24    .  -80    .   64     .     .   .    .
//    . -8   .   80    . -192    .   128     .   .    .
//    1  . -40    .  240    . -448     .   256   .    .
//    . 10   . -160    .  672    . -1024     . 512    .
//   -1  .  60    . -560    . 1792     . -2304   . 1024
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is generally not normal: A' * A /= A * A'.
//
//    A is lower triangular.
//
//    A is reducible.
//
//    The entries of row N sum to N.
//
//    det ( A ) = 2^((N*(N-1))/2).
//
//    LAMBDA(I) = 2^(I-1)
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_U[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = r8mat_zero_new ( n, n );

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+1*n] = 2.0;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    j = 0;
    a[i+j*n] = - a[i-2+j*n];
    for ( j = 1; j < n; j++ )
    {
      a[i+j*n] = 2.0 * a[i-1+(j-1)*n] - a[i-2+j*n];
    }
  }
  return a;
}
//****************************************************************************80

double cheby_u_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_U_DETERMINANT returns the determinant of the CHEBY_U matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_U_DETERMINANT, the determinant.
//
{
  double determ;
  int power;

  power = ( n * ( n - 1 ) ) / 2;

  determ = ( double ) i4_power ( 2, power );

  return determ;
}
//****************************************************************************80

double *cheby_u_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_U_INVERSE returns the inverse of the CHEBY_U matrix.
//
//  Example:
//
//    N = 11
//
//      1   .   .  .   .  .  .  .  .  .  .
//      .   1   .  .   .  .  .  .  .  .  .  /    2
//      1   .   1  .   .  .  .  .  .  .  .  /    4
//      .   2   .  1   .  .  .  .  .  .  .  /    8
//      2   .   3  .   1  .  .  .  .  .  .  /   16
//      .   5   .  4   .  1  .  .  .  .  .  /   32
//      5   .   9  .   5  .  1  .  .  .  .  /   64
//      .  14   . 14   .  6  .  1  .  .  .  /  128
//     14   .  28  .  20  .  7  .  1  .  .  /  256
//      .  42   . 48   . 27  .  8  .  1  .  /  512
//     42   .  90  .  75  . 35  .  9  .  1  / 1024
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double A[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = r8mat_zero_new ( n, n );

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+1*n] = 0.5;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    j = 0;
    a[i+j*n] = a[i-1+(j+1)*n] / 2.0;
    for ( j = 1; j < n - 1; j++ )
    {
      a[i+j*n] = ( a[i-1+(j-1)*n] + a[i-1+(j+1)*n] ) / 2.0;
    }
    j = n - 1;
    a[i+j*n] = a[i-1+(j-1)*n] / 2.0;
  }
  return a;
}
//****************************************************************************80

double *cheby_u_polynomial ( int n, double x )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_U_POLYNOMIAL evaluates the Chebyshev polynomials of the second kind.
//
//  Differential equation:
//
//    (1-X*X) Y'' - 3 X Y' + N (N+2) Y = 0
//
//  Formula:
//
//    If |X| <= 1, then
//
//      U(N)(X) = sin ( (N+1) * arccos(X) ) / sqrt ( 1 - X^2 )
//              = sin ( (N+1) * arccos(X) ) / sin ( arccos(X) )
//
//    else
//
//      U(N)(X) = sinh ( (N+1) * arccosh(X) ) / sinh ( arccosh(X) )
//
//  First terms:
//
//    U(0)(X) =   1
//    U(1)(X) =   2 X
//    U(2)(X) =   4 X^2 -   1
//    U(3)(X) =   8 X^3 -   4 X
//    U(4)(X) =  16 X^4 -  12 X^2 +  1
//    U(5)(X) =  32 X^5 -  32 X^3 +  6 X
//    U(6)(X) =  64 X^6 -  80 X^4 + 24 X^2 - 1
//    U(7)(X) = 128 X^7 - 192 X^5 + 80 X^3 - 8X
//
//  Orthogonality:
//
//    For integration over [-1,1] with weight
//
//      W(X) = sqrt(1-X*X), 
//
//    we have
//
//      < U(I)(X), U(J)(X) > = integral ( -1 <= X <= 1 ) W(X) U(I)(X) U(J)(X) dX 
//
//    then the result is:
//
//      < U(I)(X), U(J)(X) >  =  0    if I /= J
//      < U(I)(X), U(J)(X) >  =  PI/2 if I == J
//
//  Recursion:
//
//    U(0)(X) = 1,
//    U(1)(X) = 2 * X,
//    U(N)(X) = 2 * X * U(N-1)(X) - U(N-2)(X)
//
//  Special values:
//
//    U(N)(1) = N + 1
//    U(2N)(0) = (-1)^N
//    U(2N+1)(0) = 0
//    U(N)(X) = (-1)^N * U(N)(-X)
//
//  Zeroes:
//
//    M-th zero of U(N)(X) is X = cos( M*PI/(N+1)), M = 1 to N
//
//  Extrema:
//
//    M-th extremum of U(N)(X) is X = cos( M*PI/N), M = 0 to N
//
//  Norm:
//
//    Integral ( -1 <= X <= 1 ) ( 1 - X^2 ) * U(N)(X)^2 dX = PI/2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Milton Abramowitz, Irene Stegun,
//    Handbook of Mathematical Functions,
//    National Bureau of Standards, 1964,
//    ISBN: 0-486-61272-4,
//    LC: QA47.A34.
//
//  Parameters:
//
//    Input, int N, the highest polynomial to compute.
//
//    Input, double X, the point at which the polynomials 
//    are to be computed.
//
//    Output, double CHEBY_U_POLYNOMIAL[N+1], the values of the N+1 Chebyshev
//    polynomials.
//
{
  double *cx;
  int i;

  if ( n < 0 )
  {
    return NULL;
  }

  cx = new double[n+1];

  cx[0] = 1.0;

  if ( n < 1 )
  {
    return cx;
  }

  cx[1] = 2.0 * x;

  for ( i = 2; i <= n; i++ )
  {
    cx[i] = 2.0 * x * cx[i-1] - cx[i-2];
  }
 
  return cx;
}
//****************************************************************************80

double *cheby_van1 ( int m, double a, double b, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_VAN1 returns the CHEBY_VAN1 matrix.
//
//  Discussion:
//
//    Normally, the Chebyshev polynomials are defined on -1 <= XI <= +1.
//    Here, we assume the Chebyshev polynomials have been defined on the
//    interval A <= X <= B, using the mapping
//      XI = ( - ( B - X ) + ( X - A ) ) / ( B - A )
//    so that
//      ChebyAB(A,B;X) = Cheby(XI).
//
//    if ( I == 1 ) then
//      V(1,1:N) = 1;
//    elseif ( I == 2 ) then
//      V(2,1:N) = XI(1:N);
//    else
//      V(I,1:N) = 2.0 * XI(1:N) * V(I-1,1:N) - V(I-2,1:N);
//
//  Example:
//
//    N = 5, A = -1, B = +1, X = ( 1, 2, 3, 4, 5 )
//
//    1  1   1    1    1
//    1  2   3    4    5
//    1  7  17   31   49
//    1 26  99  244  485
//    1 97 577 1921 4801
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 April 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Nicholas Higham,
//    Stability analysis of algorithms for solving confluent
//    Vandermonde-like systems,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 11, 1990, pages 23-41.
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//
//    Input, double A, B, the interval.
//
//    Input, int N, the number of columns of the matrix.
//
//    Input, double X[N], the vector that defines the matrix.
//
//    Output, double CHEBY_VAN1[M*N], the matrix.
//
{
  int i;
  int j;
  double *v;
  double xi;

  v = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    xi = ( - ( b - x[j] ) + ( x[j] - a ) ) / ( b - a );
    for ( i = 0; i < m; i++ )
    {
      if ( i == 0 )
      {
        v[i+j*m] = 1.0;
      }
      else if ( i == 1 )
      {
        v[i+j*m] = xi;
      }
      else
      {
        v[i+j*m] = 2.0 * xi * v[i-1+j*m] - v[i-2+j*m];
      }
    }
  }
  return v;
}
//****************************************************************************80

double *cheby_van2 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_VAN2 returns the CHEBY_VAN2 matrix.
//
//  Discussion:
//
//    The formula for this matrix has been slightly modified, by a scaling
//    factor, in order to make it closer to its inverse.
//
//    A(I,J) = ( 1 / sqrt ( N - 1 ) ) * cos ( (I-1) * (J-1) * PI / (N-1) )
//
//  Example:
//
//    N = 4
//
//                 1      1           1           1
//    1/sqrt(3) *  1  COS(PI/3)   COS(2*PI/3) COS(3*PI/3)
//                 1  COS(2*PI/3) COS(4*PI/3) COS(6*PI/3)
//                 1  COS(3*PI/3) COS(6*PI/3) COS(9*PI/3)
//
//    or, in decimal,
//
//    0.5774    0.5774    0.5774    0.5774
//    0.5774    0.2887   -0.2887   -0.5774
//    0.5774   -0.2887   -0.2887    0.5774
//    0.5774   -0.5774    0.5774   -0.5774
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    The entries of A are based on the extrema of the Chebyshev
//    polynomial T(n-1).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_VAN2[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  if ( n == 1 )
  {
    a[0+0*n] = 1.0;
    return a;
  }
  
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( i * j ) * r8_pi / ( double ) ( n - 1 );
      a[i+j*n] = cos ( angle );
    }
  }
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = a[i+j*n] / sqrt ( ( double ) ( n - 1 ) );
    }
  }
  return a;
}
//****************************************************************************80

double cheby_van2_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_VAN2_DETERMINANT returns the determinant of the CHEBY_VAN2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_VAN2_DETERMINANT, the determinant.
//
{
  double determ;

  if ( n <= 0 )
  {
    determ = 0.0;
  }
  else if ( n == 1 )
  {
    determ = 1.0;
  }
  else
  {
    determ = r8_mop ( n / 2 ) * sqrt ( pow ( 2.0, 4 - n ) );
  }
  return determ;
}
//****************************************************************************80

double *cheby_van2_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_VAN2_INVERSE returns the inverse of the CHEBY_VAN2 matrix.
//
//  Discussion:
//
//    if ( I == 1 or N ) .and. ( J == 1 or N ) then
//      A(I,J) = ( 1 / (2*sqrt(N-1)) ) * cos ( (I-1) * (J-1) * PI / (N-1) )
//    else if ( I == 1 or N ) .or. ( J == 1 or N ) then
//      A(I,J) = ( 1 / (  sqrt(N-1)) ) * cos ( (I-1) * (J-1) * PI / (N-1) )
//    else
//      A(I,J) = ( 2 /    sqrt(N-1)  ) * cos ( (I-1) * (J-1) * PI / (N-1) )
//
//
//  Example:
//
//    N = 4
//
//                1/2    1             1           1/2
//    1/sqrt(3) *  1   2*COS(PI/3)   2*COS(2*PI/3)       COS(3*PI/3)
//                 1   2*COS(2*PI/3) 2*COS(4*PI/3)       COS(6*PI/3)
//                1/2    COS(3*PI/3)   COS(6*PI/3) 1/2 * COS(9*PI/3)
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    The entries of A are based on the extrema of the Chebyshev
//    polynomial T(n-1).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_VAN2_INVERSE[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  if ( n == 1 )
  {
    a[0+0*n] = 1.0;
    return a;
  }
  
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( i * j ) * r8_pi / ( double ) ( n - 1 );
      a[i+j*n] = cos ( angle );
    }
  }
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 2.0 * a[i+j*n] / sqrt ( ( double ) ( n - 1 ) );
    }
  }
  for ( j = 0; j < n; j++ )
  {
    a[0+j*n]   = 0.5 * a[0+j*n];
    a[n-1+j*n] = 0.5 * a[n-1+j*n];
  }
  for ( i = 0; i < n; i++ )
  {
    a[i+0*n]     = 0.5 * a[i+0*n];
    a[i+(n-1)*n] = 0.5 * a[i+(n-1)*n];
  }
  return a;
}
//****************************************************************************80

double *cheby_van3 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_VAN3 returns the CHEBY_VAN3 matrix.
//
//  Discussion:
//
//    A(I,J) = cos ( (I-1) * (J-1/2) * PI / N )
//
//  Example:
//
//    N = 4
//
//        1            1           1            1
//    COS(  PI/8)  COS(3*PI/8) COS( 5*PI/8) COS( 7*PI/8)
//    COS(2*PI/8)  COS(6*PI/8) COS(10*PI/8) COS(14*PI/8)
//    COS(3*PI/8)  COS(9*PI/8) COS(15*PI/8) COS(21*PI/8)
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is "almost" orthogonal.  A * A' = a diagonal matrix.
//
//    The entries of A are based on the zeros of the Chebyshev polynomial T(n).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_VAN3[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( i * ( 2 * j + 1 ) ) * r8_pi / ( double ) ( 2 * n );
      a[i+j*n] = cos ( angle );
    }
  }
  return a;
}
//****************************************************************************80

double cheby_van3_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_VAN3_DETERMINANT returns the determinant of the CHEBY_VAN3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_VAN3_DETERMINANT, the determinant.
//
{
  double determ;

  determ = r8_mop ( n + 1 ) * sqrt (  ( double ) ( i4_power ( n, n ) ) )
    / sqrt ( pow ( 2.0, n - 1 ) );

  return determ;
}
//****************************************************************************80

double *cheby_van3_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_VAN3_INVERSE returns the inverse of the CHEBY_VAN3 matrix.
//
//  Discussion:
//
//    if J == 1 then
//      A(I,J) = (1/N) * cos ( (I-1/2) * (J-1) * PI / N )
//    else if 1 < J then
//      A(I,J) = (2/N) * cos ( (I-1/2) * (J-1) * PI / N )
//
//  Example:
//
//    N = 4
//
//    1/4  1/2 cos(  PI/8)  1/2 cos( 2*PI/8)  1/2 cos( 3*PI/8)
//    1/4  1/2 cos(3*PI/8)  1/2 cos( 6*PI/8)  1/2 cos( 9*PI/8)
//    1/4  1/2 cos(5*PI/8)  1/2 cos(10*PI/8)  1/2 cos(15*PI/8)
//    1/4  1/2 cos(7*PI/8)  1/2 cos(14*PI/8)  1/2 cos(21*PI/8)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHEBY_VAN3_INVERSE[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( ( 2 * i + 1 ) * j ) * r8_pi 
            / ( double ) ( 2 * n );

      a[i+j*n] = cos ( angle ) / ( double ) ( n );
    }
  }

  for ( j = 1; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 2.0 * a[i+j*n];
    }
  }
  return a;
}
//****************************************************************************80

double *chow ( double alpha, double beta, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHOW returns the CHOW matrix.
//
//  Discussion:
//
//    By making ALPHA small compared with BETA, the eigenvalues can
//    all be made very close to BETA, and this is useful as a test
//    of eigenvalue computing routines.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = ALPHA + BETA
//    else if ( J <= I + 1 ) then
//      A(I,J) = ALPHA^(I+1-J)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 2, BETA = 3, M = 5, N = 5
//
//     5  1  0  0  0
//     4  5  1  0  0
//     8  4  5  1  0
//    16  8  4  5  1
//    32 16  8  4  5
//
//    ALPHA = ALPHA, BETA = BETA, M = 5, N = 5
//
//    ALPHA+BETA 1          0          0          0
//    ALPHA^2    ALPHA+BETA 1          0          0
//    ALPHA^3    ALPHA^2    ALPHA+BETA 1          0
//    ALPHA^4    ALPHA^3    ALPHA^2    ALPHA+BETA 1
//    ALPHA^5    ALPHA^4    ALPHA^3    ALPHA^2    ALPHA+BETA
//
//  Properties:
//
//    A is Toeplitz: constant along diagonals.
//
//    A is lower Hessenberg.
//
//    A is generally not symmetric: A' /= A.
//
//    If ALPHA is 0.0, then A is singular if and only if BETA is 0.0.
//
//    If BETA is 0.0, then A will be singular if 1 < N.
//
//    If BETA is 0.0 and N = 1, then A will be singular if ALPHA is 0.0.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    For 1 <= I < N-(N+1)/2,
//
//      LAMBDA(I) = BETA + 4 * ALPHA * cos ( i * pi / ( N+2 ) )^2,
//
//    For N-(N+1)/2+1 <= I <= N
//
//      LAMBDA(I) = BETA
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    TS Chow,
//    A class of Hessenberg matrices with known eigenvalues and inverses,
//    SIAM Review,
//    Volume 11, Number 3, 1969, pages 391-395.
//
//    Graeme Fairweather,
//    On the eigenvalues and eigenvectors of a class of Hessenberg matrices,
//    SIAM Review,
//    Volume 13, Number 2, 1971, pages 220-221.
//
//  Parameters:
//
//    Input, double ALPHA, the ALPHA value.  A typical value is 1.0.
//
//    Input, double BETA, the BETA value.  A typical value is 0.0.
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double CHOW[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[m*n];

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i == j - 1 )
      {
        a[i+j*m] = 1.0;
      }
      else if ( i == j )
      {
        a[i+j*m] = alpha + beta;
      }
      else if ( j + 1 <= i )
      {
        a[i+j*m] = pow ( alpha, i + 1 - j );
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double chow_determinant ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHOW_DETERMINANT returns the determinant of the CHOW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the ALPHA value.  A typical value is 1.0.
//
//    Input, double BETA, the BETA value.  A typical value is 0.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHOW_DETERMINANT, the determinant.
//
{
  double angle;
  double determ;
  int i;
  int k;
  const double r8_pi = 3.141592653589793;

  determ = 1.0;

  k = n - ( n / 2 );

  for ( i = 0; i < k; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 2 );
    determ = determ * ( beta + 4.0 * alpha * cos ( angle ) * cos ( angle ) );
  }

  determ = determ * pow ( beta, n - k );

  return determ;
}
//****************************************************************************80

double *chow_eigenvalues ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHOW_EIGENVALUES returns the eigenvalues of the CHOW matrix.
//
//  Example:
//
//    ALPHA = 2, BETA = 3, N = 5
//
//    9.49395943
//    6.10991621
//    3.0
//    3.0
//    3.0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the ALPHA value.  A typical value is 1.0.
//
//    Input, double BETA, the BETA value.  A typical value is 0.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHOW_EIGENVALUES[N], the eigenvalues of A.
//
{
  double angle;
  int i;
  int k;
  double *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new double[n];

  k = n - ( n + 1 ) / 2;

  for ( i = 0; i < k; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 2 );
    lambda[i] = beta + 4.0 * alpha * cos ( angle ) * cos ( angle );
  }

  for ( i = k; i < n; i++ )
  {
    lambda[i] = beta;
  }
  return lambda;
}
//****************************************************************************80

double *chow_inverse ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHOW_INVERSE returns the inverse of the CHOW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the ALPHA value.  A typical value is 1.0.
//
//    Input, double BETA, the BETA value.  A typical value is 0.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHOW_INVERSE[N*N], the matrix.
//
{
  double *a;
  double *d;
  double *dp;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  if ( 0.0 == alpha && beta == 0.0 )
  {
    cerr << "\n";
    cerr << "CHOW_INVERSE - Fatal error!\n";
    cerr << "  The Chow matrix is not invertible, because\n";
    cerr << "  ALPHA = 0 and BETA = 0.\n";
    exit ( 1 );
  }
  else if ( 0.0 == alpha && beta != 0.0 )
  {
    for ( i = 0; i < n; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        if ( i <= j )
        {
          a[i+j*n] = r8_mop ( j - i ) / pow ( beta, j - i + 1 );
        }
        else
        {
          a[i+j*n] = 0.0;
        }
      }
    }
    return a;
  }
  else if ( 0.0 != alpha && beta == 0.0 )
  {
    if ( 1 < n )
    {
      cerr << "\n";
      cerr << "CHOW_INVERSE - Fatal error!\n";
      cerr << "  The Chow matrix is not invertible, because\n";
      cerr << "  BETA = 0 and 1 < N.\n";
      exit ( 1 );
    }
    else
    {
      a[0+0*n] = 1.0 / alpha;
      return a;
    }
  }
//
//  General case.
//
  d = new double[n+1];

  d[0] = 1.0;
  d[1] = beta;
  for ( i = 2; i <= n; i++ )
  {
    d[i] = beta * d[i-1] + alpha * beta * d[i-2];
  }

  dp = new double[n+2];

  dp[0] = 1.0 / beta;
  dp[1] = 1.0;
  dp[2] = alpha + beta;
  for ( i = 3; i <= n + 1; i++ )
  {
    dp[i] = d[i-1] + alpha * d[i-2];
  }

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      a[i+j*n] = - alpha * pow ( alpha * beta, i - j ) * dp[j] * d[n-i-1] / dp[n+1];
    }
    for ( j = i; j < n; j++ )
    {
      a[i+j*n] = r8_mop ( i + j ) * dp[i+1] * d[n-j] / ( beta * dp[n+1] );
    }
  }
//
//  Free memory.
//
  delete [] d;
  delete [] dp;

  return a;
}
//****************************************************************************80

double *chow_eigen_left ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHOW_EIGEN_LEFT returns the left eigenvectors for the CHOW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the ALPHA value.  A typical value is 1.0.
//
//    Input, double BETA, the BETA value.  A typical value is 0.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHOW_EIGEN_LEFT[N*N], the left eigenvector matrix.
//
{
  double angle;
  int i;
  int j;
  int k;
  const double r8_pi = 3.141592653589793;
  double *v;

  v = new double[n*n];

  k = n - ( n + 1 ) / 2;

  for ( i = 0; i < k; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 2 );
    for ( j = 0; j < n; j++ )
    {
      v[i+j*n] = pow ( alpha, n - j - 1 ) * pow ( 2.0, n - j - 2 ) 
        * pow ( cos ( angle ),  n - j ) 
        * sin ( ( double ) ( n - j + 1 ) * angle ) / sin ( angle );
    }
  }

  for ( i = k; i < n; i++ )
  {
    for ( j = 0; j < n - 2; j++ )
    {
      v[i+j*n] = 0.0;
    }
    v[i+(n-2)*n] = - alpha;
    v[i+(n-1)*n] = 1.0;
  }
  return v;
}
//****************************************************************************80

double *chow_eigen_right ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CHOW_EIGEN_RIGHT returns the right eigenvectors for the CHOW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the ALPHA value.  A typical value is 1.0.
//
//    Input, double BETA, the BETA value.  A typical value is 0.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double CHOW_EIGEN_RIGHT[N*N], the right eigenvector matrix.
//
{
  double angle;
  int i;
  int j;
  int k;
  const double r8_pi = 3.141592653589793;
  double *u;

  u = new double[n*n];

  k = n - ( n + 1 ) / 2;

  for ( j = 0; j < k; j++ )
  {
    angle = ( double ) ( j + 1 ) * r8_pi / ( double ) ( n + 2 );
    for ( i = 0; i < n; i++ )
    {
      u[i+j*n] = pow ( alpha, i ) * pow ( 2.0, i - 1 ) 
        * pow ( cos ( angle ), i - 1 ) 
        * sin ( ( double ) ( i + 2 ) * angle ) / sin ( angle );
    }
  }

  for ( j = k; j < n; j++ )
  {
    u[0+j*n] = 1.0;
    u[1+j*n] = - alpha;
    for ( i = 2; i < n; i++ )
    {
      u[i+j*n] = 0.0;
    }
  }

  return u;
}
//****************************************************************************80

double *circulant ( int m, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCULANT returns the CIRCULANT matrix.
//
//  Formula:
//
//    K = 1 + mod ( J-I, N )
//    A(I,J) = X(K)
//
//  Example:
//
//    M = 4, N = 4, X = ( 1, 2, 3, 4 )
//
//    1  2  3  4
//    4  1  2  3
//    3  4  1  2
//    2  3  4  1
//
//    M = 4, N = 5, X = ( 1, 2, 3, 4, 5 )
//
//    1  2  3  4  5
//    5  1  2  3  4
//    4  5  1  2  3
//    3  4  5  1  2
//
//    M = 5, N = 4, X = ( 1, 2, 3, 4 )
//
//    1  2  3  4
//    5  1  2  3
//    4  5  1  2
//    3  4  5  1
//    1  2  3  4
//
//  Discussion:
//
//    Westlake lists the following "special" circulants:
//
//      B2, X = ( T^2, 1, 2, ..., T, T+1, T, T-1, ..., 1 ),
//      with T = ( N - 2 ) / 2;
//
//      B3, X = ( N+1, 1, 1, ..., 1 );
//
//      B5, X = ( 1, 2, 3, ..., N ).
//
//  Properties:
//
//    The product of two circulant matrices is a circulant matrix.
//
//    The transpose of a circulant matrix is a circulant matrix.
//
//    A circulant matrix C, whose first row is (c1, c2, ..., cn), can be
//    written as a polynomial in the upshift matrix U:
//
//      C = c1 * I + c2 * U + c3 * U^2 + ... + cn * U^(n-1).
//
//    A is a circulant: each row is shifted once to get the next row.
//
//    A is generally not symmetric: A' /= A.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A commutes with any other circulant matrix.
//
//    A is normal.
//
//    The transpose of A is also a circulant matrix.
//
//    A has constant row sums.
//
//    Because A has constant row sums,
//    it has an eigenvalue with this value,
//    and a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has constant column sums.
//
//    Because A has constant column sums,
//    it has an eigenvalue with this value,
//    and a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    The inverse of A is also a circulant matrix.
//
//    The Fourier matrix is the eigenvector matrix for every circulant matrix.
//
//    Because the Fourier matrix F diagonalizes A, the inverse (or
//    pseudoinverse, if any LAMBDA is zero) can be written
//
//      inverse ( A ) = (F*) * 1/LAMBDA * F
//
//    A is symmetric if, for all I, X(I+1) = X(N-I+1).
//
//    If R is an N-th root of unity, that is, R is a complex number such
//    that R^N = 1, then
//
//      Y = X(1) + X(2)*R + X(3)*R^2 + ... + X(N)*R^(N-1)
//
//    is an eigenvalue of A, with eigenvector
//
//     ( 1, R, R^2, ..., R^(N-1) )
//
//    and left eigenvector
//
//      ( R^(N-1), R^(N-2), ..., R^2, R, 1 ).
//
//    Although there are exactly N distinct roots of unity, the circulant
//    may have repeated eigenvalues, because of the behavior of the polynomial.
//    However, the matrix is guaranteed to have N linearly independent
//    eigenvectors.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Philip Davis,
//    Circulant Matrices,
//    Second Edition,
//    Chelsea, 1994,
//    ISBN13: 978-0828403384,
//    LC: QA188.D37.
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double X[N], the values in the first row of A.
//
//    Output, double CIRCULANT[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = i4_modp ( j - i, n );
      a[i+j*m] = x[k];
    }
  }
  return a;
}
//****************************************************************************80

double circulant_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCULANT_DETERMINANT returns the determinant of the CIRCULANT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the values in the first row of A.
//
//    Output, double CIRCULANT_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int j;
  complex <double> *lambda;
  complex <double> *w;

  w = c8vec_unity ( n );

  lambda = new complex <double>[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = x[n-1];
  }

  for ( i = n - 2; 0 <= i; i-- )
  {
    for ( j = 0; j < n; j++ )
    {
      lambda[j] = lambda[j] * w[j] + x[i];
    }
  }
//
//  First eigenvalue is "special".
//
  determ = real ( lambda[0] );
//
//  Eigenvalues 2, 3     through ( N + 1 ) / 2 are paired with complex conjugates.
//
  for ( i = 1; i < ( n + 1 ) / 2; i++ )
  {
    determ = determ * pow ( c8_abs ( lambda[i] ), 2 );
  }
//
//  If N is even, there is another unpaired eigenvalue.
//
  if ( ( n % 2 ) == 0 )
  {
    determ = determ * real ( lambda[n/2] );
  }
//
//  Free memory.
//
  delete [] lambda;
  delete [] w;

  return determ;
}
//****************************************************************************80

complex <double> *circulant_eigenvalues ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCULANT_EIGENVALUES returns the eigenvalues of the CIRCULANT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the values in the first row of A.
//
//    Output, complex <double> CIRCULANT_LAMBDA[N], the eigenvalues.
//
{
  int i;
  int j;
  complex <double> *lambda;
  complex <double> *w;

  w = c8vec_unity ( n );

  lambda = new complex <double>[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = x[n-1];
  }
  for ( i = n - 2; 0 <= i; i-- )
  {
    for ( j = 0; j < n; j++ )
    {
      lambda[j] = lambda[j] * w[j] + x[i];
    }
  }
//
//  Free memory.
//
  delete [] w;

  return lambda;
}
//****************************************************************************80

double *circulant_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCULANT_INVERSE returns the inverse of the CIRCULANT matrix.
//
//  Discussion:
//
//    The Moore Penrose generalized inverse is computed, so even if
//    the circulant is singular, this routine returns a usable result.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the values that define the circulant matrix.
//
//    Output, double CIRCULANT_INVERSE[N*N], the matrix.
//
{
  double *a;
  complex <double> *b;
  complex <double> *bf;
  complex <double> *f;
  complex <double> *fbf;
  int i;
  int j;
  int k;
  complex <double> *lambda;

  lambda = circulant_eigenvalues ( n, x );

  b = c8mat_zero_new ( n, n );

  for ( i = 0; i < n; i++ )
  {
    if ( lambda[i] != 0.0 )
    {
      b[i+i*n] = 1.0 / conj ( lambda[i] );
    }
  }

  f = fourier ( n );

  bf = c8mat_zero_new ( n, n );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      for ( k = 0; k < n; k++ )
      {
        bf[i+j*n] = bf[i+j*n] + b[i+k*n] * f[k+j*n];
      }
    }
  }

  fbf = c8mat_zero_new ( n, n );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      for ( k = 0; k < n; k++ )
      {
        fbf[i+j*n] = fbf[i+j*n] + conj ( f[k+i*n] ) * bf[k+j*n];
      }
    }
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = real ( fbf[i+j*n] );
    }
  }
//
//  Free memory.
//
  delete [] b;
  delete [] bf;
  delete [] f;
  delete [] fbf;
  delete [] lambda;

  return a;
}
//****************************************************************************80

double *circulant2 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCULANT2 returns the CIRCULANT2 matrix.
//
//  Formula:
//
//    K = 1 + mod ( J-I, N )
//    A(I,J) = K
//
//  Example:
//
//    N = 5
//
//    1  2  3  4  5
//    5  1  2  3  4
//    4  5  1  2  3
//    3  4  5  1  2
//    2  3  4  5  1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is a circulant: each row is shifted once to get the next row.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A commutes with any other circulant.
//
//    A is normal.
//
//    The inverse of A is a circulant matrix.
//
//    The eigenvector matrix is the Fourier matrix.
//
//    A has constant row sums.
//
//    Because A has constant row sums,
//    it has an eigenvalue with this value,
//    and a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has constant column sums.
//
//    Because A has constant column sums,
//    it has an eigenvalue with this value,
//    and a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    If R is an N-th root of unity, that is, R is a complex number such
//    that R^N = 1, then
//
//      Y = 1 + 2*R + 3*R^2 + ... + N*R^(N-1)
//
//    is an eigenvalue of A, with eigenvector
//
//     ( 1, R, R^2, ..., R^(N-1) )
//
//    and left eigenvector
//
//      ( R^(N-1), R^(N-2), ..., R^2, R, 1 ).
//
//    Although there are exactly N distinct roots of unity, the circulant
//    may have repeated eigenvalues, because of the behavior of the polynomial.
//    However, the matrix is guaranteed to have N linearly independent
//    eigenvectors.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Philip Davis,
//    Circulant Matrices,
//    Second Edition,
//    Chelsea, 1994,
//    ISBN13: 978-0828403384,
//    LC: QA188.D37.
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CIRCULANT2[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      k = 1 + i4_modp ( j - i, n );
      a[i+j*n] = ( double ) ( k );
    }
  }
  return a;
}
//****************************************************************************80

double circulant2_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCULANT2_DETERMINANT returns the determinant of the CIRCULANT2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CIRCULANT2_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int j;
  complex <double> *lambda;
  complex <double> *w;

  w = c8vec_unity ( n );

  lambda = new complex <double> [n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = complex <double> ( n, 0 );
  }

  for ( i = n - 1; 1 <= i; i-- )
  {
    for ( j = 0; j < n; j++ )
    {
      lambda[j] = lambda[j] * w[j] + complex <double> ( i, 0 );
    }
  }
//
//  First eigenvalue is "special".
//
  determ = real ( lambda[0] );
//
//  Eigenvalues 2, 3, through ( N + 1 ) / 2 are paired with complex conjugates.
//
  for ( i = 1; i < ( n + 1 ) / 2; i++ )
  {
    determ = determ * pow ( abs ( lambda[i] ), 2 );
  }
//
//  If N is even, there is another unpaired eigenvalue.
//
  if ( ( n % 2 ) == 0 )
  {
    determ = determ * real ( lambda[(n/2)] );
  }
//
//  Free memory.
//
  delete [] lambda;
  delete [] w;

  return determ;
}
//****************************************************************************80

complex <double> *circulant2_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCULANT2_EIGENVALUES returns the eigenvalues of the CIRCULANT2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> CIRCULANT2_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  int j;
  complex <double> *lambda;
  complex <double> *w;

  lambda = new complex <double>[n];
  for ( i = 0; i < n; i++ )
  {
    lambda[i] = complex <double> ( n, 0 );
  }

  w = c8vec_unity ( n );


  for ( i = n - 1; 1 <= i; i-- )
  {
    for ( j = 0; j < n; j++ )
    {
      lambda[j] = lambda[j] * w[j] + complex <double> ( i, 0 );
    }
  }
//
//  Free memory.
//
  delete [] w;

  return lambda;
}
//****************************************************************************80

double *circulant2_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CIRCULANT2_INVERSE returns the inverse of the CIRCULANT2 matrix.
//
//  Discussion:
//
//    The Moore Penrose generalized inverse is computed, so even if
//    the circulant is singular, this routine returns a usable result.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CIRCULANT2_INVERSE[N*N], the matrix.
//
{
  double *a;
  complex <double> *b;
  complex <double> *bf;
  complex <double> *f;
  complex <double> *fct;
  complex <double> *fctbf;
  int i;
  int j;
  complex <double> *lambda;

  lambda = circulant2_eigenvalues ( n );

  b = new complex <double>[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      b[i+j*n] = c8_zero ( );
    }
  }

  for ( i = 0; i < n; i++ )
  {
    if ( lambda[i] != c8_zero ( ) )
    {
      b[i+i*n] = 1.0 / conj ( lambda[i] );
    }
  }

  f = fourier ( n );

  bf = c8mat_mm_new ( n, n, n, b, f );

  fct = new complex <double>[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      fct[i+j*n] = conj ( f[j+i*n] );
    }
  }

  fctbf = c8mat_mm_new ( n, n, n, fct, bf );

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = real ( fctbf[i+j*n] );
    }
  }
//
//  Free memory.
//
  delete [] b;
  delete [] bf;
  delete [] f;
  delete [] fct;
  delete [] fctbf;
  delete [] lambda;

  return a;
}
//****************************************************************************80

double *clement1 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CLEMENT1 returns the CLEMENT1 matrix.
//
//  Formula:
//
//    if ( J = I + 1 )
//      A(I,J) = sqrt(I*(N-I))
//    else if ( I = J + 1 )
//      A(I,J) = sqrt(J*(N-J))
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//       .    sqrt(4)    .       .       .
//    sqrt(4)    .    sqrt(6)    .       .
//       .    sqrt(6)    .    sqrt(6)    .
//       .       .    sqrt(6)    .    sqrt(4)
//       .       .       .    sqrt(4)    .
//
//  Properties:
//
//    A is tridiagonal.
//
//    A is banded, with bandwidth 3.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    The diagonal of A is zero.
//
//    A is singular if N is odd.
//
//    About 64 percent of the entries of the inverse of A are zero.
//
//    The eigenvalues are plus and minus the numbers
//
//      N-1, N-3, N-5, ..., (1 or 0).
//
//    If N is even,
//
//      det ( A ) = (-1)^(N/2) * (N-1) * (N+1)^(N/2)
//
//    and if N is odd,
//
//      det ( A ) = 0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Clement,
//    A class of triple-diagonal matrices for test purposes,
//    SIAM Review,
//    Volume 1, 1959, pages 50-52.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CLEMENT1[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( j == i + 1 )
      {
        a[i-1+(j-1)*n] = sqrt ( ( double ) ( i * ( n - i ) ) );
      }
      else if ( i == j + 1 )
      {
        a[i-1+(j-1)*n] = sqrt ( ( double ) ( j * ( n - j ) ) );
      }
      else
      {
        a[i-1+(j-1)*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double clement1_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CLEMENT1_DETERMINANT returns the determinant of the CLEMENT1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CLEMENT1_DETERMINANT, the determinant.
//
{
  double determ;
  int i;

  if ( ( n % 2 ) == 1 )
  {
    determ = 0.0;
  }
  else
  {
    determ = 1.0;
    for ( i = 1; i <= n - 1; i = i + 2 )
    {
      determ = determ * ( double ) ( i * ( n - i ) );
    }

    if ( ( ( n / 2 ) % 2 ) == 1 ) 
    {
      determ = - determ;
    }
  }
  return determ;
}
//****************************************************************************80

double *clement1_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CLEMENT1_EIGENVALUES returns the eigenvalues of the CLEMENT1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CLEMENT1_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = ( double ) ( - n + 1 + 2 * i );
  }

  return lambda;
}
//****************************************************************************80

double *clement1_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CLEMENT1_INVERSE returns the inverse of the CLEMENT1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.  N must not be odd.
//
//    Output, double CLEMENT1_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double prod;

  if ( ( n % 2 ) == 1 )
  {
    cerr << "\n";
    cerr << "CLEMENT1_INVERSE - Fatal error!\n";
    cerr << "  The Clement matrix is singular for odd N.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 1; i <= n; i++ )
  {
    if ( ( i % 2 ) == 1 )
    {
      for ( j = i; j <= n - 1; j = j + 2 )
      {
        if ( j == i )
        {
          prod = 1.0 / sqrt ( ( double ) ( j * ( n - j ) ) );
        }
        else
        {
          prod = - prod 
            * sqrt ( ( double ) ( ( j - 1 ) * ( n + 1 - j ) ) ) 
            / sqrt ( ( double ) ( j * ( n - j ) ) );
        }
        a[i-1+j*n] = prod;
        a[j+(i-1)*n] = prod;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *clement2 ( int n, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    CLEMENT2 returns the CLEMENT2 matrix.
//
//  Formula:
//
//    if ( J = I + 1 )
//      A(I,J) = X(I)
//    else if ( I = J + 1 )
//      A(I,J) = Y(J)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5, X and Y arbitrary:
//
//       .   X(1)    .     .     .
//     Y(1)   .    X(2)    .     .
//       .   Y(2)    .   X(3)    .
//       .     .   Y(3)    .   X(4)
//       .     .     .   Y(4)    .
//
//    N = 5, X=(1,2,3,4), Y=(5,6,7,8):
//
//       .     1     .     .     .
//       5     .     2     .     .
//       .     6     .     3     .
//       .     .     7     .     4
//       .     .     .     8     .
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    The Clement1 and Clement2 matrices are special cases of this one.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 3.
//
//    The diagonal of A is zero.
//
//    A is singular if N is odd.
//
//    About 64 percent of the entries of the inverse of A are zero.
//
//    If N is even,
//      det ( A ) = (-1)^(N/2) * product ( 1 <= I <= N/2 )
//        ( X(2*I-1) * Y(2*I-1) )
//    and if N is odd,
//      det ( A ) = 0.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//     07 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Clement,
//    A class of triple-diagonal matrices for test purposes,
//    SIAM Review,
//    Volume 1, 1959, pages 50-52.
//
//    Alan Edelman, Eric Kostlan,
//    The road from Kac's matrix to Kac's random polynomials.
//    In Proceedings of the Fifth SIAM Conference on Applied Linear Algebra,
//    edited by John Lewis,
//    SIAM, 1994, pages 503-507.
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Olga Taussky, John Todd,
//    Another look at a matrix of Mark Kac,
//    Linear Algebra and Applications,
//    Volume 150, 1991, pages 341-360.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N-1], Y[N-1], the first super and
//    subdiagonals of the matrix A.
//
//    Output, double CLEMENT2[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( j == i + 1 )
      {
        a[i+j*n] = x[i];
      }
      else if ( i == j + 1 )
      {
        a[i+j*n] = y[j];
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double clement2_determinant ( int n, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    CLEMENT2_DETERMINANT returns the determinant of the CLEMENT2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//     07 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X(N-1), Y(N-1), the first super and
//    subdiagonals of the matrix A.
//
//    Output, double CLEMENT2_DETERMINANT, the determinant of A.
//
{
  double determ;
  int i;

  if ( ( n % 2 ) == 1 )
  {
    determ = 0.0;
  }
  else
  {
    determ = 1.0;
    for ( i = 0; i < n - 1; i = i + 2 )
    {
      determ = determ * x[i] * y[i];
    }

    if ( ( ( n / 2 ) % 2 ) == 1 )
    {
      determ = - determ;
    }
  }
  return determ;
}
//****************************************************************************80

double *clement2_inverse ( int n, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    CLEMENT2_INVERSE returns the inverse of the CLEMENT2 matrix.
//
//  Example:
//
//    N = 6, X and Y arbitrary:
//
//     0                1/Y1 0         -X2/(Y1*Y3) 0   X2*X4/(Y1*Y3*Y5)
//     1/X1             0    0          0          0    0
//     0                0    0          1/Y3       0   -X4/(Y3*Y5)
//    -Y2/(X1*X3)       0    1/X3       0          0    0
//     0                0    0          0          0    1/Y5
//     Y2*Y4/(X1*X3*X5) 0   -Y4/(X3*X5) 0          1/X5 0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Clement,
//    A class of triple-diagonal matrices for test purposes,
//    SIAM Review,
//    Volume 1, 1959, pages 50-52.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.  N must not be odd.
//
//    Input, double X[N-1], Y[N-1], the first super and
//    subdiagonals of the matrix A.  None of the entries
//    of X or Y may be zero.
//
//    Output, double CLEMENT2_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double prod1;
  double prod2;

  if ( ( n % 2 ) == 1 )
  {
    cerr << "\n";
    cerr << "CLEMENT2_INVERSE - Fatal error!\n";
    cerr << "  The Clement matrix is singular for odd N.\n";
    exit ( 1 );
  }

  for ( i = 0; i < n - 1 ; i++ )
  {
    if ( x[i] == 0.0 )
    {
      cerr << "\n";
      cerr << "CLEMENT2_INVERSE - Fatal error!\n";
      cerr << "  The matrix is singular\n";
      cerr << "  X[" << i <<"] = 0\n";
      exit ( 1 );
    }
    else if ( y[i] == 0.0 )
    {
      cerr << "\n";
      cerr << "CLEMENT2_INVERSE - Fatal error!\n";
      cerr << "  The matrix is singular\n";
      cerr << "  Y[" << i <<"] = 0\n";
      exit ( 1 );
    }
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n; i++ )
  {
    if ( ( i % 2 ) == 0 )
    {
      for ( j = i; j < n - 1; j = j + 2 )
      {
        if ( j == i )
        {
          prod1 = 1.0 / y[j];
          prod2 = 1.0 / x[j];
        }
        else
        {
          prod1 = - prod1 * x[j-1] / y[j];
          prod2 = - prod2 * y[j-1] / x[j];
        }
        a[i+(j+1)*n] = prod1;
        a[j+1+i*n] = prod2;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *colleague ( int n, double c[] )

//****************************************************************************80
//
//  Purpose:
//
//    COLLEAGUE returns the COLLEAGUE matrix.
//
//  Discussion:
//
//    The colleague matrix is an analog of the companion matrix, adapted
//    for use with polynomials represented by a sum of Chebyshev polynomials.
//
//    Let the N-th degree polynomial be defined by
//
//      P(X) = C(N)*T_N(X) + C(N-1)*T_(N-1)(X) + ... + C(1)*T1(X) + C(0)*T0(X)
//
//    where T_I(X) is the I-th Chebyshev polynomial.
//
//    Then the roots of P(X) are the eigenvalues of the colleague matrix A(C):
//
//        0   1   0   ...  0                        0    0    0   ...   0
//       1/2  0  1/2  ...  0                        0    0    0   ...   0
//        0  1/2  0   ...  0      - 1/(2*C(N)) *    0    0    0   ...   0
//       ... ... ...  ... ...                      ...  ...  ...  ...  ...
//       ... ... ...   0  1/2                      ...  ...  ...  ...   0
//       ... ... ...  1/2  0                       C(0) C(1) C(2) ... C(N-1)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    I J Good,
//    The Colleague Matrix: A Chebyshev Analogue of the Companion Matrix,
//    The Quarterly Journal of Mathematics,
//    Volume 12, Number 1, 1961, pages 61-68.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double C[0:N], the coefficients of the polynomial.
//
//    Output, double COLLEAGUE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  if ( n == 1 )
  {
    a[0+0*n] = - c[0] / c[1];
  }
  else
  {
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n; i++ )
      {
        if ( i == 0 && j == 1 )
        {
          a[i+j*n] = 1.0;
        }
        else if ( j == i - 1 || j == i + 1 )
        {
          a[i+j*n] = 0.5;
        }
        else
        {
          a[i+j*n] = 0.0;
        }
      }
    }
    for ( j = 0; j < n; j++ )
    {
      a[n-1+j*n] = a[n-1+j*n] - 0.5 * c[j] / c[n];
    }
  }
  return a;
}
//****************************************************************************80

double *combin ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    COMBIN returns the COMBIN matrix.
//
//  Discussion:
//
//    This matrix is known as the combinatorial matrix.
//
//  Formula:
//
//    If ( I = J ) then
//      A(I,J) = ALPHA + BETA
//    else
//      A(I,J) = BETA
//
//  Example:
//
//    N = 5, ALPHA = 2, BETA = 3
//
//    5 3 3 3 3
//    3 5 3 3 3
//    3 3 5 3 3
//    3 3 3 5 3
//    3 3 3 3 5
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    det ( A ) = ALPHA^(N-1) * ( ALPHA + N * BETA ).
//
//    A has constant row sums.
//
//    Because A has constant row sums,
//    it has an eigenvalue with this value,
//    and a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has constant column sums.
//
//    Because A has constant column sums,
//    it has an eigenvalue with this value,
//    and a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    LAMBDA(1:N-1) = ALPHA,
//    LAMBDA(N) = ALPHA + N * BETA.
//
//    The eigenvector associated with LAMBDA(N) is (1,1,1,...,1)/sqrt(N).
//
//    The other N-1 eigenvectors are simply any (orthonormal) basis
//    for the space perpendicular to (1,1,1,...,1).
//
//    A is nonsingular if ALPHA /= 0 and ALPHA + N * BETA /= 0.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Donald Knuth,
//    The Art of Computer Programming,
//    Volume 1, Fundamental Algorithms, Second Edition,
//    Addison-Wesley, Reading, Massachusetts, 1973, page 36.
//
//  Parameters:
//
//    Input, double ALPHA, BETA, scalars that define A.
//
//    Input, int N, the order of the matrix.
//
//    Output, double COMBIN[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = alpha + beta;
      }
      else
      {
        a[i+j*n] = beta;
      }
    }
  }
  return a;
}
//****************************************************************************80

double combin_condition ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    COMBIN_CONDITION returns the L1 condition of the COMBIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, scalars that define A.
//
//    Input, int N, the order of the matrix.
//
//    Output, double COMBIN_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double b_norm_bot;
  double b_norm_top;
  double cond;

  a_norm = fabs ( alpha + beta ) + ( double ) ( n - 1 ) * fabs ( beta );

  b_norm_top = fabs ( alpha + ( double ) ( n - 1 ) * beta ) 
    + ( double ) ( n - 1 ) * fabs ( beta );

  b_norm_bot = fabs ( alpha * ( alpha + ( double ) ( n ) * beta ) );

  b_norm = b_norm_top / b_norm_bot;

  cond = a_norm * b_norm;

  return cond;
}
//****************************************************************************80

double combin_determinant ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    COMBIN_DETERMINANT returns the determinant of the COMBIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, scalars that define A.
//
//    Input, int N, the order of the matrix.
//
//    Output, double COMBIN_DETERMINANT, the determinant.
//
{
  double determ;

  determ = pow ( alpha, n - 1 ) * ( alpha + ( double ) ( n ) * beta );

  return determ;
}
//****************************************************************************80

double *combin_eigenvalues ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    COMBIN_EIGENVALUES returns the eigenvalues of the COMBIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, scalars that define A.
//
//    Input, int N, the order of the matrix.
//
//    Output, double COMBIN_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n - 1; i++ )
  {
    lambda[i] = alpha;
  }
  lambda[n-1] = alpha + ( double ) ( n ) * beta;

  return lambda;
}
//****************************************************************************80

double *combin_inverse ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    COMBIN_INVERSE returns the inverse of the COMBIN matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = (ALPHA+(N-1)*BETA) / (ALPHA*(ALPHA+N*BETA))
//    else
//      A(I,J) =             - BETA / (ALPHA*(ALPHA+N*BETA))
//
//  Example:
//
//    N = 5, ALPHA = 2, BETA = 3
//
//           14 -3 -3 -3 -3
//           -3 14 -3 -3 -3
//   1/34 *  -3 -3 14 -3 -3
//           -3 -3 -3 14 -3
//           -3 -3 -3 -3 14
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    A is Toeplitz: constant along diagonals.
//
//    det ( A ) = 1 / (ALPHA^(N-1) * (ALPHA+N*BETA)).
//
//    A is well defined if ALPHA /= 0 and ALPHA+N*BETA /= 0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Donald Knuth,
//    The Art of Computer Programming,
//    Volume 1, Fundamental Algorithms, Second Edition,
//    Addison-Wesley, Reading, Massachusetts, 1973, page 36.
//
//  Parameters:
//
//    Input, double ALPHA, BETA, scalars that define the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double COMBIN_INVERSE[N*N], the matrix.
//
{
  double *a;
  double bot;
  int i;
  int j;

  if ( alpha == 0.0 )
  {
    cerr << "\n";
    cerr << "COMBIN_INVERSE - Fatal error!\n";
    cerr << "  The entries of the matrix are undefined\n";
    cerr << "  because ALPHA = 0.\n";
    exit ( 1 );
  }
  else if ( alpha + n * beta == 0.0 )
  {
    cerr << "\n";
    cerr << "COMBIN_INVERSE - Fatal error!\n";
    cerr << "  The entries of the matrix are undefined\n";
    cerr << "  because ALPHA+N*BETA is zero.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  bot = alpha * ( alpha + ( double ) ( n ) * beta );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = ( alpha + ( double ) ( n - 1 ) * beta ) / bot;
      }
      else
      {
        a[i+j*n] = - beta / bot;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *combin_eigen_right ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    COMBIN_EIGEN_RIGHT returns the right eigenvectors of the COMBIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, scalars that define A.
//
//    Input, int N, the order of the matrix.
//
//    Output, double COMBIN_EIGEN_RIGHT[N*N], the right eigenvectors.
//
{
  int i;
  int j;
  double *x;

  x = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j < n - 1 )
      {
        if ( i == 0 )
        {
          x[i+j*n] = 1.0;
        }
        else if ( i == j + 1 )
        {
          x[i+j*n] = - 1.0;
        }
        else
        {
          x[i+j*n] = 0.0;
        }
      }
      else
      {
        x[i+j*n] = 1.0;
      }
    }
  }
  return x;
}
//****************************************************************************80

double *companion ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    COMPANION returns the COMPANION matrix.
//
//  Discussion:
//
//    Let the monic N-th degree polynomial be defined by
//
//      P(t) = t^N + X(N)*t^N-1 + X(N-1)*t^N-1 + ... + X(2)*t + X(1)
//
//    Then
//
//      A(1,J) = X(N+1-J) for J=1 to N
//      A(I,I-1) = 1      for I=2 to N
//      A(I,J) = 0        otherwise
//
//    A is called the companion matrix of the polynomial P(t), and the
//    characteristic equation of A is P(t) = 0.
//
//    Matrices of this form are also called Frobenius matrices.
//
//    The determinant of a matrix is unaffected by being transposed,
//    and only possibly changes sign if the rows are "reflected", so
//    there are actually many possible ways to write a companion matrix:
//
//    A B C D  A 1 0 0  0 1 0 0  0 0 1 0  0 0 1 A
//    1 0 0 0  B 0 1 0  0 0 1 0  0 1 0 0  0 1 0 B
//    0 1 0 0  C 0 0 1  0 0 0 1  1 0 0 0  1 0 0 C
//    0 0 1 0  D 0 0 0  D C B A  A B C D  0 0 0 D
//
//  Example:
//
//    N = 5, X = ( 1, 2, 3, 4, 5 )
//
//    5 4 3 2 1
//    1 0 0 0 0
//    0 1 0 0 0
//    0 0 1 0 0
//    0 0 0 1 0
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is nonsingular if and only if X(1) is nonzero.
//
//    The eigenvalues of A are the roots of P(t) = 0.
//
//    If LAMBDA is an eigenvalue of A, then a corresponding eigenvector is
//      ( 1, LAMBDA, LAMBDA^2, ..., LAMBDA^(N-1) ).
//
//    If LAMBDA is an eigenvalue of multiplicity 2, then a second 
//    corresponding generalized eigenvector is
//
//      ( 0, 1, 2 * LAMBDA, ..., (N-1)*LAMBDA^(N-2) ).
//
//    For higher multiplicities, repeatedly differentiate with respect to LAMBDA.
//
//    Any matrix with characteristic polynomial P(t) is similar to A.
//
//    det ( A ) = +/- X(1).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gene Golub, Charles Van Loan,
//    Matrix Computations, second edition,
//    Johns Hopkins University Press, Baltimore, Maryland, 1989,
//    section 7.4.6.
//
//    Charles Kenney, Alan Laub,
//    Controllability and stability radii for companion form systems,
//    Math. Control Signals Systems,
//    Volume 1, 1988, pages 239-256.
//
//    James Wilkinson,
//    The Algebraic Eigenvalue Problem,
//    Oxford University Press,
//    1965, page 12.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the coefficients of the polynomial 
//    which define A.
//
//    Output, double COMPANION[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 )
      {
        a[i+j*n] = x[n-1-j];
      }
      else if ( i == j + 1 )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double companion_condition ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    COMPANION_CONDITION returns the L1 condition of the COMPANION matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the coefficients of the polynomial 
//    which define A.
//
//    Output, double COMPANION_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  int i;
  double t;
  double value;

  a_norm = fabs ( x[0] );
  for ( i = 1; i < n; i++ )
  {
    t = 1.0 + fabs ( x[i] );
    if ( a_norm < t )
    {
      a_norm = t;
    }
  }

  b_norm = 1.0 / fabs ( x[0] );
  for ( i = 1; i < n; i++ )
  {
    t = 1.0 + fabs ( x[i] / x[0] );
    if ( b_norm < t )
    {
      b_norm = t;
    }
  }

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double companion_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    COMPANION_DETERMINANT returns the determinant of the COMPANION matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the coefficients of the polynomial 
//    which define A.
//
//    Output, double COMPANION_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( n % 2 ) == 1 )
  {
    determ = + x[0];
  }
  else
  {
    determ = - x[0];
  }
  return determ;
}
//****************************************************************************80

double complete_symmetric_poly ( int n, int r, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    COMPLETE_SYMMETRIC_POLY evaluates a complete symmetric polynomial.
//
//  Discussion:
//
//    N\R  0   1         2               3
//      +--------------------------------------------------------
//    0 |  1   0         0               0
//    1 |  1   X1        X1^2            X1^3
//    2 |  1   X1+X2     X1^2+X1X2+X2^2  X1^3+X1^2X2+X1X2^2+X2^3
//    3 |  1   X1+X2+X3  ...
//
//    If X = ( 1, 2, 3, 4, 5, ... ) then
//
//    N\R  0     1     2     3     4 ...
//      +--------------------------------------------------------
//    0 |  1     0     0     0     0
//    1 |  1     1     1     1     1
//    2 |  1     3     7    15    31
//    3 |  1     6    25    90   301
//    4 |  1    10    65   350  1701
//    5 |  1    15   140  1050  6951
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 November 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of variables.
//    0 <= N.
//
//    Input, int R, the degree of the polynomial.
//    0 <= R.
//
//    Input, double X[N], the value of the variables.
//
//    Output, double COMPLETE_SYMMETRIC_POLY, the value of TAU(N,R)(X).
//
{
  int i;
  int nn;
  int rr;
  double *tau;
  double value;

  if ( n < 0 )
  {
    cerr << "\n";
    cerr << "COMPLETE_SYMMETRIC_POLY - Fatal error!\n";
    cerr << "  N < 0.\n";
    exit ( 1 );
  }

  if ( r < 0 )
  {
    cerr << "\n";
    cerr << "COMPLETE_SYMMETRIC_POLY - Fatal error!\n";
    cerr << "  R < 0.\n";
    exit ( 1 );
  }

  tau = new double[1+i4_max(n,r)];

  for ( i = 0; i <= i4_max ( n, r ); i++ )
  {
    tau[i] = 0.0;
  }

  tau[0] = 1.0;
  for ( nn = 1; nn <= n; nn++ )
  {
    for ( rr = 1; rr <= r; rr++ )
    {
      tau[rr] = tau[rr] + x[nn-1] * tau[rr-1];
    }
  }

  value = tau[r];
//
//  Free memory.
//
  delete [] tau;

  return value;
}
//****************************************************************************80

double *companion_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    COMPANION_INVERSE returns the inverse of the COMPANION matrix.
//
//  Example:
//
//    N = 5, X = ( 1, 2, 3, 4, 5 )
//
//    0    1    0    0    0
//    0    0    1    0    0
//    0    0    0    1    0
//    0    0    0    0    1
//   1/1 -5/1 -4/1 -3/1 -2/1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gene Golub, Charles Van Loan,
//    Matrix Computations, second edition,
//    Johns Hopkins University Press, Baltimore, Maryland, 1989,
//    section 7.4.6.
//
//    Charles Kenney, Alan Laub,
//    Controllability and stability radii for companion form systems,
//    Math. Control Signals Systems,
//    Volume 1, 1988, pages 239-256.
//
//    James Wilkinson,
//    The Algebraic Eigenvalue Problem,
//    Oxford University Press,
//    1965, page 12.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the coefficients of the polynomial 
//    which define the matrix.  X(1) must not be zero.
//
//    Output, double COMPANION_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == n - 1 )
      {
        if ( j == 0 )
        {
          a[i+j*n] = 1.0 / x[0];
        }
        else
        {
          a[i+j*n] = - x[n-j] / x[0];
        }
      }
      else if ( i == j - 1 )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

complex <double> *complex3 ( )

//****************************************************************************80
//
//  Purpose:
//
//    COMPLEX3 returns the COMPLEX3 matrix.
//
//  Formula:
//
//    1        1 + 2i     2 + 10i
//    1 + i        3i    -5 + 14i
//    1 + i        5i    -8 + 20i
//
//  Properties:
//
//    A is complex.
//
//    A is complex integral.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, complex <double> COMPLEX3[3*3], the matrix.
//
{
  complex <double> *a;
//
//  Note that the matrix entries are listed by column.
//
  static complex <double> a_save[3*3] = {
    complex <double> (  1.0,  0.0 ),
    complex <double> (  1.0,  1.0 ),
    complex <double> (  1.0,  1.0 ),
    complex <double> (  1.0,  2.0 ),
    complex <double> (  0.0,  3.0 ),
    complex <double> (  0.0,  5.0 ),
    complex <double> (  2.0, 10.0 ),
    complex <double> ( -5.0, 14.0 ),
    complex <double> ( -8.0, 20.0 ) };

  a = c8mat_copy_new ( 3, 3, a_save );

  return a;
}
//****************************************************************************80

complex <double> *complex3_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    COMPLEX3_INVERSE returns the inverse of the COMPLEX3 matrix.
//
//  Formula:
//
//      10 +  i    -2 + 6i    -3 - 2i
//       9 - 3i         8i    -3 - 2i
//      -2 + 2i    -1 - 2i     1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, complex <double> COMPLEX3_INVERSE[3*3], the matrix.
//
{
  complex <double> *a;
//
//  Note that the matrix entries are listed by column.
//
  static complex <double> a_save[3*3] = {
    complex <double> ( 10.0,  1.0 ),
    complex <double> (  9.0, -3.0 ),
    complex <double> ( -2.0,  2.0 ),
    complex <double> ( -2.0,  6.0 ),
    complex <double> (  0.0,  8.0 ),
    complex <double> ( -1.0, -2.0 ),
    complex <double> ( -3.0, -2.0 ),
    complex <double> ( -3.0, -2.0 ),
    complex <double> (  1.0,  0.0 ) };

  a = c8mat_copy_new ( 3, 3, a_save );

  return a;
}
//****************************************************************************80

double *complex_i ( )

//****************************************************************************80
//
//  Purpose:
//
//    COMPLEX_I returns the COMPLEX_I matrix.
//
//  Discussion:
//
//    This is a real matrix, that has some properties similar to the
//    imaginary unit.
//
//  Formula:
//
//    0 1
//   -1 0
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is anti-involutory: A * A = - I
//
//    A * A * A * A = I
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double COMPLEX_I[2*2], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[2*2] = { 0.0, -1.0, 1.0, 0.0 };

  a = r8mat_copy_new ( 2, 2, a_save );

  return a;
}
//****************************************************************************80

double complex_i_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    COMPLEX_I_DETERMINANT returns the determinant of the COMPLEX_I matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double COMPLEX_I_DETERMINANT, the determinant.
//
{
  double determ;

  determ = + 1.0;

  return determ;
}
//****************************************************************************80

double *complex_i_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    COMPLEX_I_INVERSE returns the inverse of the COMPLEX_I matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double COMPLEX_I_INVERSE[2*2], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[2*2] = { 0.0, 1.0, -1.0, 0.0 };

  a = r8mat_copy_new ( 2, 2, a_save );

  return a;
}
//****************************************************************************80

double *conex1 ( double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX1 returns the CONEX1 matrix.
//
//  Discussion:
//
//    The CONEX1 matrix is a counterexample to the LINPACK condition
//    number estimator RCOND available in the LINPACK routine DGECO.
//
//  Formula:
//
//    1  -1 -2*ALPHA   0
//    0   1    ALPHA    -ALPHA
//    0   1  1+ALPHA  -1-ALPHA
//    0   0  0           ALPHA
//
//  Example:
//
//    ALPHA = 100
//
//    1  -1  -200     0
//    0   1   100  -100
//    0   1   101  -101
//    0   0     0   100
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Alan Cline, RK Rew,
//    A set of counterexamples to three condition number estimators,
//    SIAM Journal on Scientific and Statistical Computing,
//    Volume 4, 1983, pages 602-611.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining A.  
//    A common value is 100.0.
//
//    Output, double CONEX1[4*4], the matrix.
//
{
  double *a;
  int n = 4;

  a = new double[n*n];

  a[0+0*n] = 1.0;
  a[1+0*n] = 0.0;
  a[2+0*n] = 0.0;
  a[3+0*n] = 0.0;

  a[0+1*n] = -1.0;
  a[1+1*n] = 1.0;
  a[2+1*n] = 1.0;
  a[3+1*n] = 0.0;

  a[0+2*n] = -2.0 * alpha;
  a[1+2*n] = alpha;
  a[2+2*n] = 1.0 + alpha;
  a[3+2*n] = 0.0;

  a[0+3*n] = 0.0;
  a[1+3*n] = -alpha;
  a[2+3*n] = -1.0 - alpha;
  a[3+3*n] = alpha;

  return a;
}
//****************************************************************************80

double conex1_condition ( double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX1_CONDITION returns the L1 condition of the CONEX1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining A.  
//
//    Output, double CONEX1_CONDITION, the L1 condition number.
//
{
  double a_norm;
  double b_norm;
  double v1;
  double v2;
  double v3;
  double value;

  a_norm = r8_max ( 3.0, 3.0 * fabs ( alpha ) + fabs ( 1.0 + alpha ) );
  v1 = fabs ( 1.0 - alpha ) + fabs ( 1.0 + alpha ) + 1.0;
  v2 = 2.0 * fabs ( alpha ) + 1.0;
  v3 = 2.0 + 2.0 / fabs ( alpha );
  b_norm = r8_max ( v1, r8_max ( v2, v3 ) );
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double conex1_determinant ( double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX1_DETERMINANT returns the determinant of the CONEX1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining A.  
//
//    Output, double CONEX1_DETERMINANT, the determinant.
//
{
  double determ;

  determ = alpha;

  return determ;
}
//****************************************************************************80

double *conex1_inverse ( double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX1_INVERSE returns the inverse of the CONEX1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining A.  
//
//    Output, double CONEX1_INVERSE[4*4], the matrix.
//
{
  double *a;
  int n = 4;

  a = new double[n*n];

  a[0+0*n] =  1.0;
  a[1+0*n] =  0.0;
  a[2+0*n] =  0.0;
  a[3+0*n] =  0.0;

  a[0+1*n] =  1.0 - alpha;
  a[1+1*n] =  1.0 + alpha;
  a[2+1*n] = -1.0;
  a[3+1*n] =  0.0;

  a[0+2*n] =        alpha;
  a[1+2*n] =      - alpha;
  a[2+2*n] =  1.0;
  a[3+2*n] =  0.0;

  a[0+3*n] =  2.0;
  a[1+3*n] =  0.0;
  a[2+3*n] =  1.0 / alpha;
  a[3+3*n] =  1.0 / alpha;

  return a;
}
//****************************************************************************80

double *conex2 ( double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX2 returns the CONEX2 matrix.
//
//  Formula:
//
//    1   1-1/ALPHA^2  -2
//    0   1/ALPHA      -1/ALPHA
//    0   0             1
//
//  Example:
//
//    ALPHA = 100
//
//    1  0.9999  -2
//    0  0.01    -0.01
//    0  0        1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is upper triangular.
//
//    det ( A ) = 1 / ALPHA.
//
//    LAMBDA = ( 1, 1/ALPHA, 1 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Alan Cline, RK Rew,
//    A set of counterexamples to three condition number estimators,
//    SIAM Journal on Scientific and Statistical Computing,
//    Volume 4, 1983, pages 602-611.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining A.  
//    A common value is 100.0.  ALPHA must not be zero.
//
//    Output, double CONEX2[3*3], the matrix.
//
{
  double *a;
  int n = 3;

  a = new double[n*n];

  if ( alpha == 0.0 )
  {
    cerr << "\n";
    cerr << "CONEX2 - Fatal error!\n";
    cerr << "  The input value of ALPHA was zero.\n";
    exit ( 1 );
  }

  a[0+0*n] =  1.0;
  a[1+0*n] =  0.0;
  a[2+0*n] =  0.0;

  a[0+1*n] = ( alpha - 1.0 ) * ( alpha + 1.0 ) / alpha / alpha;
  a[1+1*n] =  1.0 / alpha;
  a[2+1*n] =  0.0;

  a[0+2*n] = -2.0;
  a[1+2*n] = -1.0 / alpha;
  a[2+2*n] =  1.0;

  return a;
}
//****************************************************************************80

double conex2_condition ( double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX2_CONDITION returns the L1 condition of the CONEX2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining A.  
//
//    Output, double CONEX2_CONDITION, the L1 condition number.
//
{
  double a_norm;
  double b_norm;
  double c1;
  double c2;
  double c3;
  double value;

  c1 = 1.0;
  c2 = fabs ( 1.0 - 1.0 / alpha / alpha ) + 1.0 / fabs ( alpha );
  c3 = 3.0 + 1.0 / fabs ( alpha );
  a_norm = r8_max ( c1, r8_max ( c2, c3 ) );
  c1 = 1.0;
  c2 = fabs ( ( 1.0 - alpha * alpha ) / alpha ) + fabs ( alpha );
  c3 = fabs ( ( 1.0 + alpha * alpha ) / alpha / alpha ) + 2.0;
  b_norm = r8_max ( c1, r8_max ( c2, c3 ) );
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double conex2_determinant ( double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX2_DETERMINANT returns the determinant of the CONEX2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining A.  
//
//    Output, double CONEX2_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0 / alpha;

  return determ;
}
//****************************************************************************80

double *conex2_inverse ( double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX2_INVERSE returns the inverse of the CONEX2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining A.  
//    A common value is 100.0.  ALPHA must not be zero.
//
//    Output, double CONEX2_INVERSE[3*3], the matrix.
//
{
  double *a;
  int n = 3;

  a = new double[n*n];

  if ( alpha == 0.0 )
  {
    cerr << "\n";
    cerr << "CONEX2_INVERSE - Fatal error!\n";
    cerr << "  The input value of ALPHA was zero.\n";
    exit ( 1 );
  }

  a[0+0*n] = 1.0;
  a[1+0*n] = 0.0;
  a[2+0*n] = 0.0;

  a[0+1*n] = ( 1.0 - alpha ) * ( 1.0 + alpha ) / alpha;
  a[1+1*n] = alpha;
  a[2+1*n] = 0.0;

  a[0+2*n] = ( 1.0 + alpha * alpha ) / alpha / alpha;
  a[1+2*n] = 1.0;
  a[2+2*n] = 1.0;

  return a;
}
//****************************************************************************80

double *conex3 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX3 returns the CONEX3 matrix.
//
//  Formula:
//
//    if ( I = J and I < N )
//      A(I,J) =  1.0 for 1<=I<N
//    else if ( I = J = N )
//      A(I,J) = -1.0
//    else if ( J < I )
//      A(I,J) = -1.0
//    else
//      A(I,J) =  0.0
//
//  Example:
//
//    N = 5
//
//     1  0  0  0  0
//    -1  1  0  0  0
//    -1 -1  1  0  0
//    -1 -1 -1  1  0
//    -1 -1 -1 -1 -1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is lower triangular.
//
//    det ( A ) = -1.
//
//    A is unimodular.
//
//    LAMBDA = ( 1, 1, 1, 1, -1 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Alan Cline, RK Rew,
//    A set of counterexamples to three condition number estimators,
//    SIAM Journal on Scientific and Statistical Computing,
//    Volume 4, 1983, pages 602-611.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CONEX3[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j < i )
      {
        a[i+j*n] = - 1.0;
      }
      else if ( j == i && i != n - 1 )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == i && i == n - 1 )
      {
        a[i+j*n] = - 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double conex3_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX3_CONDITION returns the L1 condition of the CONEX3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CONEX3_CONDITION, the L1 condition number.
//
{
  double value;

  value = ( double ) ( n ) * pow ( 2.0, n - 1 );

  return value;
}
//****************************************************************************80

double conex3_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX3_DETERMINANT returns the determinant of the CONEX3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CONEX3_DETERMINANT, the determinant.
//
{
  double determ;

  determ = - 1.0;

  return determ;
}
//****************************************************************************80

double *conex3_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX3_INVERSE returns the inverse of the CONEX3 matrix.
//
//  Example:
//
//    N = 5
//
//     1  0  0  0  0
//     1  1  0  0  0
//     2  1  1  0  0
//     4  2  1  1  0
//    -8 -4 -2 -1 -1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Alan Cline, RK Rew,
//    A set of counterexamples to three condition number estimators,
//    SIAM Journal on Scientific and Statistical Computing,
//    Volume 4, 1983, pages 602-611.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CONEX3_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i < n - 1 )
      {
        if ( j < i )
        {
          a[i+j*n] = pow ( 2.0, i - j - 1 );
        }
        else if ( i == j )
        {
          a[i+j*n] = 1.0;
        }
        else
        {
          a[i+j*n] = 0.0;
        }
	  }
      else if ( i == n - 1 )
      {
        if ( j < i )
        {
          a[i+j*n] = - pow ( 2.0, i - j - 1 );
        }
        else
        {
          a[i+j*n] = - 1.0;
        }
      }
    }
  }
  return a;
}
//****************************************************************************80

double *conex4 ( )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX4 returns the CONEX4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double CONEX4[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
     7.0,  6.0,  5.0,  5.0,
    10.0,  8.0,  7.0,  7.0,
     8.0, 10.0,  9.0,  6.0,
     7.0,  9.0, 10.0,  5.0 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double conex4_condition ( )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX4_CONDITION returns the L1 condition of the CONEX4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double CONEX4_CONDITION, the L1 condition number.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 33.0;
  b_norm = 136.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double conex4_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX4_DETERMINANT returns the determinant of the CONEX4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double CONEX4_DETERMINANT, the determinant.
//
{
  double determ;

  determ = - 1.0;

  return determ;
}
//****************************************************************************80

double *conex4_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    CONEX4_INVERSE returns the inverse of the CONEX4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double CONEX4_INVERSE[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
   -41.0,  25.0,  10.0, -6.0,
   -17.0,  10.0,   5.0, -3.0,
    10.0,  -6.0,  -3.0,  2.0,
    68.0, -41.0, -17.0, 10.0 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double *conference ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CONFERENCE returns the CONFERENCE matrix.
//
//  Discussion:
//
//    A conference matrix is a square matrix A of order N, with a zero
//    diagonal, and only 1's and -1's on the offdiagonal, with the property
//    that:
//
//      A * A' = (N-1) * I.
//
//    The algorithm employed here is only valid when N - 1
//    is an odd prime, or a power of an odd prime.
//
//    Conference matrices have a relationship with Hadamard matrices:
//
//      If mod ( P, 4 ) == 3, A is antisymmetric, and
//        I + A is hadamard;
//      Else A is symmetric, and
//        (   I + A, - I + A )
//        ( - I + A, - I - A) is Hadamard.
//
//  Example:
//
//    N = 8
//
//     0  1  1  1  1  1  1  1
//    -1  0 -1 -1  1 -1  1  1
//    -1  1  0 -1 -1  1 -1  1
//    -1  1  1  0 -1 -1  1 -1
//    -1 -1  1  1  0 -1 -1  1
//    -1  1 -1  1  1  0 -1 -1
//    -1 -1  1 -1  1  1  0 -1
//    -1 -1 -1  1 -1  1  1  0
//
//  Properties:
//
//    If N-1 is prime, then A[2:N,2:N] is a circulant matrix.
//
//    If N-1 = 1 mod 4, then A is symmetric.
//
//    If N-1 = 3 mod 4, then A is antisymmetric.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.  N-1 must be an odd prime,
//    or a power of an odd prime.
//
//    Output, double CONFERENCE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int l;
  int nm1;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 && j == 0 )
      {
        a[i+j*n] = 0.0;
      }
      else if ( i == 0 )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == 0 )
      {
        if ( ( ( n - 1 ) % 4 ) == 1 )
        {
          a[i+j*n] = 1.0;
        }
        else
        {
          a[i+j*n] = -1.0;
        }
      }
      else
      {
        nm1 = n - 1;
        l = legendre_symbol ( i - j, nm1 );
        a[i+j*n] = ( double ) ( l );
      }
    }
  }
  return a;
}
//****************************************************************************80

double conference_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CONFERENCE_DETERMINANT returns the determinant of the CONFERENCE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.  N-1 must be an odd prime,
//    or a power of an odd prime.
//
//    Output, double CONFERENCE_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( ( n - 1 ) % 4 ) == 1 )
  {
    determ = - sqrt ( ( double ) i4_power ( n - 1, n ) );
  }
  else
  {
    determ = + sqrt ( ( double ) i4_power ( n - 1, n ) );
  }

  return determ;
}
//****************************************************************************80

double *conference_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CONFERENCE_INVERSE returns the inverse of the CONFERENCE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double A[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int l;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 && j == 0 )
      {
        a[i+j*n] = 0.0;
      }
      else if ( i == 0 )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == 0 )
      {
        if ( ( ( n - 1 ) % 4 ) == 1 )
        {
          a[i+j*n] = 1.0;
        }
        else
        {
          a[i+j*n] = - 1.0;
        }
      }
      else
      {
        l = legendre_symbol ( i - j, n - 1 );
        a[i+j*n] = ( double ) ( l );
      }
    }
  }
  if ( ( ( n - 1 ) % 4 ) == 3 )
  {
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n; i++ )
      {
        a[i+j*n] = - a[i+j*n];
      }
    }
  }

  if ( 1 < n )
  {
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n; i++ )
      {
        a[i+j*n] = a[i+j*n] / ( double ) ( n - 1 );
      }
    }
  }

  return a;
}
//****************************************************************************80

double *creation ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CREATION returns the CREATION matrix.
//
//  Example:
//
//    M = 5, N = 5
//
//    0  0  0  0  0
//    1  0  0  0  0
//    0  2  0  0  0
//    0  0  3  0  0
//    0  0  0  4  0
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is strictly lower triangular.
//
//    A is generally not symmetric: A' /= A.
//
//    A is singular.
//
//    A has the null vector ( 0, 0, ..., 0, 1 ).
//
//    det ( A ) = 0.
//
//    LAMBDA(1:N) = 0
//
//    A is zero except for the first lower diagonal. A^2 is zero except for
//    the second lower diagonal.  A^(N-1) is the last nonzero power of A,
//    with a single nonzero entry in the (N,1) position.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double CREATION[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int jhi;

  a = r8mat_zero_new ( m, n );

  jhi = i4_min ( n, m - 1 );

  for ( j = 0; j < jhi; j++ )
  {
    i = j + 1;
    a[i+j*m] = ( double ) ( j + 1 );
  }
  return a;
}
//****************************************************************************80

double creation_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    CREATION_DETERMINANT returns the determinant of the CREATION matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double CREATION_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 0.0;

  return determ;
}
//****************************************************************************80

double *creation_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CREATION_NULL_LEFT returns a left null vector of the CREATION matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double CREATION_NULL_LEFT[M], the null vector.
//
{
  double *x;

  x = r8vec_zero_new ( m );
  x[0] = 1.0;

  return x;
}
//****************************************************************************80

double *creation_null_right ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    CREATION_NULL_RIGHT returns a right null vector of the CREATION matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double CREATION_NULL_RIGHT[N], the null vector.
//
{
  double *x;

  x = r8vec_zero_new ( n );
  x[n-1] = 1.0;

  return x;
}
//****************************************************************************80

double *cycol_random ( int m, int n, int k, int key )

//****************************************************************************80
//
//  Purpose:
//
//    CYCOL_RANDOM returns the CYCOL_RANDOM matrix.
//
//  Discussion:
//
//    This matrix is an example of a K-cyclical column matrix.
//
//    A K-cyclical column matrix has the property that the first K columns
//    of the matrix are repeated.  Thus,
//
//      A(I,J) = arbitrary, for J <= K.
//      A(I,J+L*K) = A(I,J) for L = 2, 3, ...
//
//  Example:
//
//    K = 2, M = 4, N = 5
//
//    0.1  0.2  0.1  0.2  0.1
//    0.3  0.4  0.3  0.4  0.3
//    0.7  0.2  0.7  0.2  0.7
//    0.1  0.8  0.1  0.8  0.1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A has rank at most K.
//
//    A can lead to underflow problems for Gauss elimination.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    NA Digest,
//    Volume 89, Issue 3, 22 January 1989.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, int K, the number of distinct columns to form.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double CYCOL_RANDOM[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int jj;
  int seed;

  a = new double[m*n];

  seed = key;

  for ( j = 0; j < k; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = r8_uniform_01 ( seed );
    }
  }

  for ( j = k; j < n; j++ )
  {
    jj = ( j % k );
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = a[i+jj*m];
    }
  }
  return a;
}
//****************************************************************************80

double *daub2 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB2 returns the DAUB2 matrix.
//
//  Discussion:
//
//    The DAUB2 matrix is the Daubechies wavelet transformation matrix 
//    with 2 coefficients.
//
//    The DAUB2 matrix is also known as the Haar matrix.
//
//  Properties:
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be at least 2 and a multiple of 2.
//
//    Output, double DAUB2[N*N], the matrix.
//
{
  double *a;
  double c0;
  double c1;
  int i;
  int j;

  if ( n < 2 || ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "DAUB2 - Fatal error!\n";
    cerr << "  N must be at least 2 and a multiple of 2.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  c0 = sqrt ( 2.0 ) / 2.0;
  c1 = sqrt ( 2.0 ) / 2.0;

  for ( i = 0; i < n - 1; i = i + 2 )
  {
    a[i+   i   *n] =   c0;
    a[i+  (i+1)*n] =   c1;

    a[i+1+ i   *n] =   c1;
    a[i+1+(i+1)*n] = - c0;
  }

  return a;
}
//****************************************************************************80

double daub2_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB2_CONDITION returns the L1 condition of the DAUB2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB2_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double c0;
  double c1;
  double value;

  c0 = sqrt ( 2.0 ) / 2.0;
  c1 = sqrt ( 2.0 ) / 2.0;

  a_norm = fabs ( c0 ) + fabs ( c1 );
  b_norm = a_norm;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double daub2_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB2_DETERMINANT returns the determinant of the DAUB2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB2_DETERMINANT, the determinant.
//
{
  double determ;

  determ = + 1.0;

  return determ;
}
//****************************************************************************80

double *daub2_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB2_INVERSE returns the inverse of the DAUB2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB2_INVERSE[N*N], the matrix.
//
{
  double *a;
  double *b;

  b = daub2 ( n );

  a = r8mat_transpose_new ( n, n, b );
//
//  Free memory.
//
  delete [] b;

  return a;
}
//****************************************************************************80

double *daub4 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB4 returns the DAUB4 matrix.
//
//  Discussion:
//
//    The DAUB4 matrix is the Daubechies wavelet transformation matrix 
//    with 4 coefficients.
//
//  Properties:
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be at least 4 and a multiple of 2.
//
//    Output, double DAUB4[N*N], the matrix.
//
{
  double *a;
  double c0;
  double c1;
  double c2;
  double c3;
  int i;
  int j;

  if ( n < 4 || ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "DAUB4 - Fatal error!\n";
    cerr << "  N must be at least 4 and a multiple of 2.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  c0 = ( 1.0 + sqrt ( 3.0 ) ) / sqrt ( 32.0 );
  c1 = ( 3.0 + sqrt ( 3.0 ) ) / sqrt ( 32.0 );
  c2 = ( 3.0 - sqrt ( 3.0 ) ) / sqrt ( 32.0 );
  c3 = ( 1.0 - sqrt ( 3.0 ) ) / sqrt ( 32.0 );

  for ( i = 0; i < n - 1; i = i + 2 )
  {
    a[i+(i)*n]                  =   c0;
    a[i+(i+1)*n]                =   c1;
    a[i+i4_wrap(i+2,0,n-1)*n]   =   c2;
    a[i+i4_wrap(i+3,0,n-1)*n]   =   c3;

    a[i+1+(i)*n]                =   c3;
    a[i+1+(i+1)*n]              = - c2;
    a[i+1+i4_wrap(i+2,0,n-1)*n] =   c1;
    a[i+1+i4_wrap(i+3,0,n-1)*n] = - c0;
  }

  return a;
}
//****************************************************************************80

double daub4_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB4_CONDITION returns the L1 condition of the DAUB4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB4_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double c0;
  double c1;
  double c2;
  double c3;
  double value;

  c0 = ( 1.0 + sqrt ( 3.0 ) ) / sqrt ( 32.0 );
  c1 = ( 3.0 + sqrt ( 3.0 ) ) / sqrt ( 32.0 );
  c2 = ( 3.0 - sqrt ( 3.0 ) ) / sqrt ( 32.0 );
  c3 = ( 1.0 - sqrt ( 3.0 ) ) / sqrt ( 32.0 );

  a_norm = fabs ( c0 ) + fabs ( c1 ) + fabs ( c2 ) + fabs ( c3 );
  b_norm = a_norm;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double daub4_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB4_DETERMINANT returns the determinant of the DAUB4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB4_DETERM, the determinant.
//
{
  double determ;

  determ = - 1.0;

  return determ;
}
//****************************************************************************80

double *daub4_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB4_INVERSE returns the inverse of the DAUB4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB4_INVERSE[N*N], the matrix.
//
{
  double *a;
  double *b;

  b = daub4 ( n );

  a = r8mat_transpose_new ( n, n, b );
//
//  Free memory.
//
  delete [] b;

  return a;
}
//****************************************************************************80

double *daub6 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB6 returns the DAUB6 matrix.
//
//  Discussion:
//
//    The DAUB6 matrix is the Daubechies wavelet transformation matrix 
//    with 6 coefficients.
//
//  Properties:
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be at least 6, and a multiple of 2.
//
//    Output, double DAUB6[N*N], the matrix.
//
{
  double *a;
  double c0;
  double c1;
  double c2;
  double c3;
  double c4;
  double c5;
  int i;
  int j;

  if ( n < 6 || ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "DAUB6 - Fatal error!\n";
    cerr << "  N must be at least 6, and a multiple of 2.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  c0 =  1.0 + sqrt ( 10.0 ) +       sqrt ( 5.0 + sqrt ( 40.0 ) );
  c1 =  5.0 + sqrt ( 10.0 ) + 3.0 * sqrt ( 5.0 + sqrt ( 40.0 ) );
  c2 = 10.0 - sqrt ( 40.0 ) + 2.0 * sqrt ( 5.0 + sqrt ( 40.0 ) );
  c3 = 10.0 - sqrt ( 40.0 ) - 2.0 * sqrt ( 5.0 + sqrt ( 40.0 ) );
  c4 =  5.0 + sqrt ( 10.0 ) - 3.0 * sqrt ( 5.0 + sqrt ( 40.0 ) );
  c5 =  1.0 + sqrt ( 10.0 ) -       sqrt ( 5.0 + sqrt ( 40.0 ) );

  c0 = c0 / sqrt ( 512.0 );
  c1 = c1 / sqrt ( 512.0 );
  c2 = c2 / sqrt ( 512.0 );
  c3 = c3 / sqrt ( 512.0 );
  c4 = c4 / sqrt ( 512.0 );
  c5 = c5 / sqrt ( 512.0 );

  for ( i = 0; i < n - 1; i = i + 2 )
  {

    a[i+(i)*n]                  =   c0;
    a[i+(i+1)*n]                =   c1;
    a[i+i4_wrap(i+2,0,n-1)*n]   =   c2;
    a[i+i4_wrap(i+3,0,n-1)*n]   =   c3;
    a[i+i4_wrap(i+4,0,n-1)*n]   =   c4;
    a[i+i4_wrap(i+5,0,n-1)*n]   =   c5;

    a[i+1+(i)*n]                =   c5;
    a[i+1+(i+1)*n]              = - c4;
    a[i+1+i4_wrap(i+2,0,n-1)*n] =   c3;
    a[i+1+i4_wrap(i+3,0,n-1)*n] = - c2;
    a[i+1+i4_wrap(i+4,0,n-1)*n] =   c1;
    a[i+1+i4_wrap(i+5,0,n-1)*n] = - c0;
  }

  return a;
}
//****************************************************************************80

double daub6_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB6_CONDITION returns the L1 condition of the DAUB6 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB6_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double c0;
  double c1;
  double c2;
  double c3;
  double c4;
  double c5;
  double value;

  c0 =  1.0 + sqrt ( 10.0 ) +       sqrt ( 5.0 + sqrt ( 40.0 ) );
  c1 =  5.0 + sqrt ( 10.0 ) + 3.0 * sqrt ( 5.0 + sqrt ( 40.0 ) );
  c2 = 10.0 - sqrt ( 40.0 ) + 2.0 * sqrt ( 5.0 + sqrt ( 40.0 ) );
  c3 = 10.0 - sqrt ( 40.0 ) - 2.0 * sqrt ( 5.0 + sqrt ( 40.0 ) );
  c4 =  5.0 + sqrt ( 10.0 ) - 3.0 * sqrt ( 5.0 + sqrt ( 40.0 ) );
  c5 =  1.0 + sqrt ( 10.0 ) -       sqrt ( 5.0 + sqrt ( 40.0 ) );

  c0 = c0 / sqrt ( 512.0 );
  c1 = c1 / sqrt ( 512.0 );
  c2 = c2 / sqrt ( 512.0 );
  c3 = c3 / sqrt ( 512.0 );
  c4 = c4 / sqrt ( 512.0 );
  c5 = c5 / sqrt ( 512.0 );

  a_norm = 
      fabs ( c0 ) + fabs ( c1 )
    + fabs ( c2 ) + fabs ( c3 )
    + fabs ( c4 ) + fabs ( c5 );
  b_norm = a_norm;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double daub6_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB6_DETERMINANT returns the determinant of the DAUB6 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB6_DETERM, the determinant.
//
{
  double determ;

  determ = + 1.0;

  return determ;
}
//****************************************************************************80

double *daub6_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB6_INVERSE returns the inverse of the DAUB6 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB6_INVERSE[N*N], the matrix.
//
{
  double *a;
  double *b;

  b = daub6 ( n );

  a = r8mat_transpose_new ( n, n, b );
//
//  Free memory.
//
  delete [] b;

  return a;
}
//****************************************************************************80

double *daub8 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB8 returns the DAUB8 matrix.
//
//  Discussion:
//
//    The DAUB8 matrix is the Daubechies wavelet transformation matrix 
//    with 8 coefficients.
//
//  Properties:
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gilbert Strang, Truong Nguyen,
//    Wavelets and Filter Banks,
//    Wellesley-Cambridge Press, 1997,
//    ISBN: 0-9614088-7-1,
//    LC: TK7872.F5S79 / QA403.3.S87
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be at least 8, and a multiple of 2.
//
//    Output, double DAUB8[N*N], the matrix.
//
{
  double *a;
  double c[8] = {
    0.2303778133088964,
    0.7148465705529154,
    0.6308807679298587,
   -0.0279837694168599,
   -0.1870348117190931,
    0.0308413818355607,
    0.0328830116668852,
   -0.0105974017850690 };
  int i;
  int j;

  if ( n < 8 || ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "DAUB8 - Fatal error!\n";
    cerr << "  N must be at least 8, and a multiple of 2.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n - 1; i = i + 2 )
  {
    a[i+(i)*n]                  =   c[0];
    a[i+(i+1)*n]                =   c[1];
    a[i+i4_wrap(i+2,0,n-1)*n]   =   c[2];
    a[i+i4_wrap(i+3,0,n-1)*n]   =   c[3];
    a[i+i4_wrap(i+4,0,n-1)*n]   =   c[4];
    a[i+i4_wrap(i+5,0,n-1)*n]   =   c[5];
    a[i+i4_wrap(i+6,0,n-1)*n]   =   c[6];
    a[i+i4_wrap(i+7,0,n-1)*n]   =   c[7];

    a[i+1+(i)*n]                =   c[7];
    a[i+1+(i+1)*n]              = - c[6];
    a[i+1+i4_wrap(i+2,0,n-1)*n] =   c[5];
    a[i+1+i4_wrap(i+3,0,n-1)*n] = - c[4];
    a[i+1+i4_wrap(i+4,0,n-1)*n] =   c[3];
    a[i+1+i4_wrap(i+5,0,n-1)*n] = - c[2];
    a[i+1+i4_wrap(i+6,0,n-1)*n] =   c[1];
    a[i+1+i4_wrap(i+7,0,n-1)*n] = - c[0];
  }

  return a;
}
//****************************************************************************80

double daub8_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB8_CONDITION returns the L1 condition of the DAUB8 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB8_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double c[8] = {
    0.2303778133088964,
    0.7148465705529154,
    0.6308807679298587,
   -0.0279837694168599,
   -0.1870348117190931,
    0.0308413818355607,
    0.0328830116668852,
   -0.0105974017850690 };
  double value;

  a_norm = r8vec_asum ( 8, c );
  b_norm = a_norm;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double daub8_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB8_DETERMINANT returns the determinant of the DAUB8 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB8_DETERM, the determinant.
//
{
  double determ;

  determ = - 1.0;

  return determ;
}
//****************************************************************************80

double *daub8_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB8_INVERSE returns the inverse of the DAUB8 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB8_INVERSE[N*N], the matrix.
//
{
  double *a;
  double *b;

  b = daub8 ( n );

  a = r8mat_transpose_new ( n, n, b );
//
//  Free memory.
//
  delete [] b;

  return a;
}
//****************************************************************************80

double *daub10 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB10 returns the DAUB10 matrix.
//
//  Discussion:
//
//    The DAUB10 matrix is the Daubechies wavelet transformation matrix 
//    with 10 coefficients.
//
//    Note that in the reference, the coefficient 0.0775714938400459D+00 
//    is given incorrectly, with the "8" misrepresented as a "0".
//
//  Properties:
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gilbert Strang, Truong Nguyen,
//    Wavelets and Filter Banks,
//    Wellesley-Cambridge Press, 1997,
//    ISBN: 0-9614088-7-1,
//    LC: TK7872.F5S79 / QA403.3.S87
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be at least 10, and a multiple of 2.
//
//    Output, double DAUB[10*10], the matrix.
//
{
  double *a;
  double c[10] = {
    0.1601023979741929,
    0.6038292697971895,
    0.7243085284377726,
    0.1384281459013203,
   -0.2422948870663823,
   -0.0322448695846381,
    0.0775714938400459,
   -0.0062414902127983,
   -0.0125807519990820,
    0.0033357252854738 };
  int i;
  int j;

  if ( n < 10 || ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "DAUB10 - Fatal error!\n";
    cerr << "  N must be at least 10, and a multiple of 2.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n - 1; i = i + 2 )
  {
    a[i+(i)*n]                    =   c[0];
    a[i+(i+1)*n]                  =   c[1];
    a[i+(i4_wrap(i+2,0,n-1))*n]   =   c[2];
    a[i+(i4_wrap(i+3,0,n-1))*n]   =   c[3];
    a[i+(i4_wrap(i+4,0,n-1))*n]   =   c[4];
    a[i+(i4_wrap(i+5,0,n-1))*n]   =   c[5];
    a[i+(i4_wrap(i+6,0,n-1))*n]   =   c[6];
    a[i+(i4_wrap(i+7,0,n-1))*n]   =   c[7];
    a[i+(i4_wrap(i+8,0,n-1))*n]   =   c[8];
    a[i+(i4_wrap(i+9,0,n-1))*n]   =   c[9];

    a[i+1+(i)*n]                  =   c[9];
    a[i+1+(i+1)*n]                = - c[8];
    a[i+1+(i4_wrap(i+2,0,n-1))*n] =   c[7];
    a[i+1+(i4_wrap(i+3,0,n-1))*n] = - c[6];
    a[i+1+(i4_wrap(i+4,0,n-1))*n] =   c[5];
    a[i+1+(i4_wrap(i+5,0,n-1))*n] = - c[4];
    a[i+1+(i4_wrap(i+6,0,n-1))*n] =   c[3];
    a[i+1+(i4_wrap(i+7,0,n-1))*n] = - c[2];
    a[i+1+(i4_wrap(i+8,0,n-1))*n] =   c[1];
    a[i+1+(i4_wrap(i+9,0,n-1))*n] = - c[0];
  }

  return a;
}
//****************************************************************************80

double daub10_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB10_CONDITION returns the L1 condition of the DAUB10 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB10_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double c[10] = {
    0.1601023979741929,
    0.6038292697971895,
    0.7243085284377726,
    0.1384281459013203,
   -0.2422948870663823,
   -0.0322448695846381,
    0.0775714938400459,
   -0.0062414902127983,
   -0.0125807519990820,
    0.0033357252854738 };
  double value;

  a_norm = r8vec_asum ( 10, c );
  b_norm = a_norm;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double daub10_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB10_DETERMINANT returns the determinant of the DAUB10 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB10_DETERM, the determinant.
//
{
  double determ;

  determ = + 1.0;

  return determ;
}
//****************************************************************************80

double *daub10_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB10_INVERSE returns the inverse of the DAUB10 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB10_INVERSE[N*N], the matrix.
//
{
  double *a;
  double *b;

  b = daub10 ( n );

  a = r8mat_transpose_new ( n, n, b );
//
//  Free memory.
//
  delete [] b;

  return a;
}
//****************************************************************************80

double *daub12 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB12 returns the DAUB12 matrix.
//
//  Discussion:
//
//    The DAUB12 matrix is the Daubechies wavelet transformation matrix 
//    with 12 coefficients.
//
//  Properties:
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gilbert Strang, Truong Nguyen,
//    Wavelets and Filter Banks,
//    Wellesley-Cambridge Press, 1997,
//    ISBN: 0-9614088-7-1,
//    LC: TK7872.F5S79 / QA403.3.S87
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be at least 12, and a multiple of 2.
//
//    Output, double DAUB12[N*N], the matrix.
//
{
  double *a;
  double c[12] = {
    0.1115407433501095,
    0.4946238903984533,
    0.7511339080210959,
    0.3152503517091982,
   -0.2262646939654400,
   -0.1297668675672625,
    0.0975016055873225,
    0.0275228655303053,
   -0.0315820393174862,
    0.0005538422011614,
    0.0047772575109455,
   -0.0010773010853085 };
  int i;
  int j;

  if ( n < 12 || ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "DAUB12 - Fatal error!\n";
    cerr << "  N must be at least 12, and a multiple of 2.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n - 1; i = i + 2 )
  {
    a[i+(i)*n]                     =    c[0];
    a[i+(i+1)*n]                   =    c[1];
    a[i+(i4_wrap(i+ 2,0,n-1))*n]   =    c[2];
    a[i+(i4_wrap(i+ 3,0,n-1))*n]   =    c[3];
    a[i+(i4_wrap(i+ 4,0,n-1))*n]   =    c[4];
    a[i+(i4_wrap(i+ 5,0,n-1))*n]   =    c[5];
    a[i+(i4_wrap(i+ 6,0,n-1))*n]   =    c[6];
    a[i+(i4_wrap(i+ 7,0,n-1))*n]   =    c[7];
    a[i+(i4_wrap(i+ 8,0,n-1))*n]   =    c[8];
    a[i+(i4_wrap(i+ 9,0,n-1))*n]   =    c[9];
    a[i+(i4_wrap(i+10,0,n-1))*n]   =   c[10];
    a[i+(i4_wrap(i+11,0,n-1))*n]   =   c[11];

    a[i+1+(i)*n]                   =   c[11];
    a[i+1+(i+1)*n]                 = - c[10];
    a[i+1+(i4_wrap(i+ 2,0,n-1))*n] =    c[9];
    a[i+1+(i4_wrap(i+ 3,0,n-1))*n] =  - c[8];
    a[i+1+(i4_wrap(i+ 4,0,n-1))*n] =    c[7];
    a[i+1+(i4_wrap(i+ 5,0,n-1))*n] =  - c[6];
    a[i+1+(i4_wrap(i+ 6,0,n-1))*n] =    c[5];
    a[i+1+(i4_wrap(i+ 7,0,n-1))*n] =  - c[4];
    a[i+1+(i4_wrap(i+ 8,0,n-1))*n] =    c[3];
    a[i+1+(i4_wrap(i+ 9,0,n-1))*n] =  - c[2];
    a[i+1+(i4_wrap(i+10,0,n-1))*n] =    c[1];
    a[i+1+(i4_wrap(i+11,0,n-1))*n] =  - c[0];
  }

  return a;
}
//****************************************************************************80

double daub12_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB12_CONDITION returns the L1 condition of the DAUB12 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB12_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double c[12] = {
    0.1115407433501095,
    0.4946238903984533,
    0.7511339080210959,
    0.3152503517091982,
   -0.2262646939654400,
   -0.1297668675672625,
    0.0975016055873225,
    0.0275228655303053,
   -0.0315820393174862,
    0.0005538422011614,
    0.0047772575109455,
   -0.0010773010853085 };
  double value;

  a_norm = r8vec_asum ( 12, c );
  b_norm = a_norm;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double daub12_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB12_DETERMINANT returns the determinant of the DAUB12 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB12_DETERM, the determinant.
//
{
  double determ;

  determ = - 1.0;

  return determ;
}
//****************************************************************************80

double *daub12_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DAUB12_INVERSE returns the inverse of the DAUB12 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DAUB12_INVERSE[N*N], the matrix.
//
{
  double *a;
  double *b;

  b = daub12 ( n );

  a = r8mat_transpose_new ( n, n, b );
//
//  Free memory.
//
  delete [] b;

  return a;
}
//****************************************************************************80

double *diagonal ( int m, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    DIAGONAL returns the DIAGONAL matrix.
//
//  Discussion:
//
//    if ( I = J )
//      A(I,J) = X(I)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    M = 5, N = 5, X = ( 1, 2, 3, 4, 5 )
//
//    1 0 0 0 0
//    0 2 0 0 0
//    0 0 3 0 0
//    0 0 0 4 0
//    0 0 0 0 5
//
//  Properties:
//
//    A is banded, with bandwidth 1.
//
//    A is nonsingular if, and only if, each X(I) is nonzero.
//
//    The inverse of A is a diagonal matrix with diagonal values 1/X(I).
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    LAMBDA(1:N) = X(1:N).
//
//    The matrix of eigenvectors of A is the identity matrix.
//
//    det ( A ) = product ( 1 <= I <= N ) X(I).
//
//    Because A is diagonal, it has property A (bipartite).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double X[min(M,N)], the diagonal entries of A.
//
//    Output, double DIAGONAL[M*N], the matrix.
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
      if ( i == j )
      {
        a[i+j*m] = x[i];
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }

  return a;
}
//****************************************************************************80

double diagonal_condition ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    DIAGONAL_CONDITION returns the L1 condition of the DIAGONAL matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the diagonal entries of A.
//
//    Output, double DIAGONAL_CONDITION, the L1 condition.
//
{
  double cond;

  cond = r8vec_amax ( n, x ) / r8vec_amin ( n, x );

  return cond;
}
//****************************************************************************80

double diagonal_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    DIAGONAL_DETERMINANT returns the determinant of the DIAGONAL matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the diagonal entries.
//
//    Output, double DIAGONAL_DETERMINANT, the determinant.
//
{
  double determ;
  int i;

  determ = 1.0;
  for ( i = 0; i < n; i++ )
  {
    determ = determ * x[i];
  }
  return determ;
}
//****************************************************************************80

double *diagonal_eigen_left ( int n, double d[] )

//****************************************************************************80
//
//  Purpose:
//
//    DIAGONAL_EIGEN_LEFT returns left eigenvectors of the DIAGONAL matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double D[N], the diagonal entries.
//
//    Output, double DIAGONAL_EIGEN_LEFT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *diagonal_eigen_right ( int n, double d[] )

//****************************************************************************80
//
//  Purpose:
//
//    DIAGONAL_EIGEN_RIGHT returns right eigenvectors of the DIAGONAL matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double D[N], the diagonal entries.
//
//    Output, double DIAGONAL_EIGEN_RIGHT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *diagonal_eigenvalues ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    DIAGONAL_EIGENVALUES returns the eigenvalues of the DIAGONAL matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the diagonal entries of A.
//
//    Output, double DIAGONAL_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = x[i];
  }
  return lambda;
}
//****************************************************************************80

double *diagonal_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    DIAGONAL_INVERSE returns the inverse of the DIAGONAL matrix.
//
//  Discussion:
//
//    The diagonal entries must be nonzero.
//
//  Example:
//
//    M = 5, N = 5, X = ( 1, 2, 3, 4, 5 )
//
//    1  0   0   0   0
//    0 1/2  0   0   0
//    0  0  1/3  0   0
//    0  0   0  1/4  0
//    0  0   0   0  1/5
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N , the order of the matrix..
//
//    Input, double X[N], the diagonal entries of the matrix.
//
//    Output, double DIAGONAL_INVERSE[N*N], the inverse of the matrix.
//
{
  double *a;
  int i;
  int j;

  for ( i = 0; i < n; i++ )
  {
    if ( x[i] == 0.0 )
    {
      cerr << "\n";
      cerr << "DIAGONAL_INVERSE - Fatal error!\n";
      cerr << "  Matrix is not invertible.\n";
      exit ( 1 );
    }
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0 / x[i];
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *dif1 ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1 returns the DIF1 matrix.
//
//  Discussion:
//
//    This matrix is known as the first difference matrix.
//
//    For a set of N points X(I) with equal spacing H, and a set of data
//    values Y(I) associated with those points, the product 
//    1/(2*H) * A * Y returns an approximation to the first derivative
//    of Y(X) at the interior points X(2:N-1).
//
//  Example:
//
//    N = 5
//
//    0 +1  .  .  .
//   -1  0 +1  .  .
//    . -1  0 +1  .
//    .  . -1  0 +1
//    .  .  . -1  0
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is antisymmetric: A' = -A.
//
//    Because A is antisymmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    If N is even, then A is nonsingular.
//    If N is odd, then A is singular.
//
//    If N is even, det ( A ) = 1.0.
//    If N is odd, det ( A ) = 0.0.
//
//    If N is odd, a null vector is ( 1, 0, 1, 0, ..., 1, 0, 1 )..
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double DIF1[M*N], the matrix.
//
{
  double *a;
  int i;

  a = r8mat_zero_new ( m, n );

  for ( i = 0; i < m; i++ )
  {
    if ( 0 < i )
    {
      a[i+(i-1)*m] = - 1.0;
    }
    if ( i < n - 1 )
    {
      a[i+(i+1)*m] = + 1.0;
    }
  }
  return a;
}
//****************************************************************************80

double dif1_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1_DETERMINANT returns the determinant of the DIF1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF1_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( n % 2 ) == 0 )
  {
    determ = 1.0;
  }
  else
  {
    determ = 0.0;
  }
  return determ;
}
//****************************************************************************80

complex <double> *dif1_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1_EIGENVALUES returns the eigenvalues of the DIF1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> DIF1_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  int i;
  complex <double> *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new complex <double>[n];
 
  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 1 );
    lambda[i] = complex <double> ( 0.0, 2.0 * cos ( angle ) );
  }
  return lambda;
}
//****************************************************************************80

double *dif1_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1_INVERSE returns the inverse of the DIF1 matrix.
//
//  Discussion:
//
//    The inverse only exists when N is even.
//
//  Example:
//
//    N = 8
//
//    0 -1  0 -1  0 -1  0 -1
//    1  0  0  0  0  0  0  0
//    0  0  0 -1  0 -1  0 -1
//    1  0  1  0  0  0  0  0
//    0  0  0  0  0 -1  0 -1
//    1  0  1  0  1  0  0  0
//    0  0  0  0  0  0  0 -1
//    1  0  1  0  1  0  1  0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF1_INVERSE[N,N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "DIF1_INVERSE - Fatal error!\n";
    cerr << "  Inverse only exists for N even.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n - 1; i = i + 2 )
  {
    for ( j = i + 1; j < n; j = j + 2 )
    {
      a[i+j*n] = -1.0;
    }
  }

  for ( i = 1; i < n; i = i + 2 )
  {
    for ( j = 0; j < i; j = j + 2 )
    {
      a[i+j*n] = 1.0;
    }
  }

  return a;
}
//****************************************************************************80

double *dif1_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1_NULL_LEFT returns a left null vector of the DIF1 matrix.
//
//  Discussion:
//
//    The null vector only exists if M is odd.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double DIF1_NULL_LEFT[M], the null vector.
//
{
  int i;
  double *x;

  if ( ( m % 2 ) == 0 )
  {
    cerr << "\n";
    cerr << "DIF1_NULL_LEFT - Fatal error!\n";
    cerr << "  The matrix is not singular for even M.\n";
    exit ( 1 );
  }

  x = new double[m];

  for ( i = 0; i < m; i = i + 2 )
  {
    x[i]   = 1.0;
  }
  for ( i = 1; i < m; i = i + 2 )
  {
    x[i] = 0.0;
  }
  return x;
}
//****************************************************************************80

double *dif1_null_right ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1_NULL_RIGHT returns a right null vector of the DIF1 matrix.
//
//  Discussion:
//
//    The null vector only exists if N is odd.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double DIF1_NULL_RIGHT[N], the null vector.
//
{
  int i;
  double *x;

  if ( ( n % 2 ) == 0 )
  {
    cerr << "\n";
    cerr << "DIF1_NULL_RIGHT - Fatal error!\n";
    cerr << "  The matrix is not singular for even N.\n";
    exit ( 1 );
  }

  x = new double[n];

  for ( i = 0; i < n; i = i + 2 )
  {
    x[i]   = 1.0;
  }
  for ( i = 1; i < n; i = i + 2 )
  {
    x[i] = 0.0;
  }
  return x;
}
//****************************************************************************80

double *dif1cyclic ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1CYCLIC returns the DIF1CYCLIC matrix.
//
//  Example:
//
//    N = 5
//
//    0 +1  .  . -1
//   -1  0 +1  .  .
//    . -1  0 +1  .
//    .  . -1  0 +1
//   +1  .  . -1  0
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is antisymmetric: A' = -A.
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    Because A is antisymmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A has constant row sum = 0.
//
//    Because it has a constant row sum of 0,
//    A has an eigenvalue of 0, and
//    a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has constant column sum = 0.
//
//    Because it has a constant column sum of 0,
//    A has an eigenvalue of 0, and
//    a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF1CYCLIC[N*N], the matrix.
//
{
  double *a;
  int i;
  int im1;
  int ip1;

  a = r8mat_zero_new ( n, n );

  for ( i = 0; i < n; i++ )
  {
    im1 = i4_wrap ( i - 1, 0, n - 1 );
    a[i+im1*n] = - 1.0;

    ip1 = i4_wrap ( i + 1, 0, n - 1 );
    a[i+ip1*n] = +1.0;
  }
  return a;
}
//****************************************************************************80

double dif1cyclic_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1CYCLIC_DETERMINANT: determinant of the DIF1CYCLIC matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF1CYCLIC_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 0.0;

  return determ;
}
//****************************************************************************80

double *dif1cyclic_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1CYCLIC_NULL_LEFT returns a left null vectorr of the DIF1CYCLIC matrix.
//
//  Discussion:
//
//    (1,1,1,...,1) is always a null vector.
//
//    If M is even,
//
//    (A,B,A,B,A,B,...,A,B) is also a null vector, for any A and B.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double DIF1CYCLIC_NULL_LEFT[M], the null vector.
//
{
  double a = 1.0;
  double b = 2.0;
  int i;
  double *x;

  x = new double[m];

  if ( ( m % 2 ) != 0 )
  {
    for ( i = 0; i < m; i++ )
    {
      x[i] = 1.0;
    }
  }
  else
  {
    for ( i = 0; i < m; i = i + 2 )
    {
      x[i]   = a;
      x[i+1] = b;
    }
  }
  return x;
}
//****************************************************************************80

double *dif1cyclic_null_right ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF1CYCLIC_NULL_RIGHT returns a right null vectorr of the DIF1CYCLIC matrix.
//
//  Discussion:
//
//    (1,1,1,...,1) is always a null vector.
//
//    If N is even,
//
//    (A,B,A,B,A,B,...,A,B) is also a null vector, for any A and B.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double DIF1CYCLIC_NULL_RIGHT[N], the null vector.
//
{
  double a = 1.0;
  double b = 2.0;
  int i;
  double *x;

  x = new double[n];

  if ( ( n % 2 ) != 0 )
  {
    for ( i = 0; i < n; i++ )
    {
      x[i] = 1.0;
    }
  }
  else
  {
    for ( i = 0; i < n; i = i + 2 )
    {
      x[i]   = a;
      x[i+1] = b;
    }
  }
  return x;
}
//****************************************************************************80

double *dif2 ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2 returns the DIF2 matrix.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  .  .
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//    .  .  . -1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is positive definite.
//
//    A is an M matrix.
//
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//
//    A has an LU factorization A = L * U, without pivoting.
//
//      The matrix L is lower bidiagonal with subdiagonal elements:
//
//        L(I+1,I) = -I/(I+1)
//
//      The matrix U is upper bidiagonal, with diagonal elements
//
//        U(I,I) = (I+1)/I
//
//      and superdiagonal elements which are all -1.
//
//    A has a Cholesky factorization A = L * L', with L lower bidiagonal.
//
//      L(I,I) =    sqrt ( (I+1) / I )
//      L(I,I-1) = -sqrt ( (I-1) / I )
//
//    The eigenvalues are
//
//      LAMBDA(I) = 2 + 2 * COS(I*PI/(N+1))
//                = 4 SIN^2(I*PI/(2*N+2))
//
//    The corresponding eigenvector X(I) has entries
//
//       X(I)(J) = sqrt(2/(N+1)) * sin ( I*J*PI/(N+1) ).
//
//    Simple linear systems:
//
//      x = (1,1,1,...,1,1),   A*x=(1,0,0,...,0,1)
//
//      x = (1,2,3,...,n-1,n), A*x=(0,0,0,...,0,n+1)
//
//    det ( A ) = N + 1.
//
//    The value of the determinant can be seen by induction,
//    and expanding the determinant across the first row:
//
//      det ( A(N) ) = 2 * det ( A(N-1) ) - (-1) * (-1) * det ( A(N-2) )
//                = 2 * N - (N-1)
//                = N + 1
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Morris Newman, John Todd,
//    Example A8,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double DIF2[M*N], the matrix.
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
      if ( j == i - 1 )
      {
        a[i+j*m] = -1.0;
      }
      else if ( j == i )
      {
        a[i+j*m] = 2.0;
      }
      else if ( j == i + 1 )
      {
        a[i+j*m] = -1.0;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }

  return a;
}
//****************************************************************************80

double dif2_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_CONDITION returns the L1 condition of the DIF2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  int i;
  int j;
  double t;
  double value;

  if ( n == 1 )
  {
    a_norm = 2.0;
  }
  else if ( n == 2 )
  {
    a_norm = 3.0;
  }
  else
  {
    a_norm = 4.0;
  }

  b_norm = 0.0;
  for ( j = 1; j <= n; j++ )
  {
    t = 0.0;
    for ( i = 1; i <= n; i++ )
    {
      if ( i <= j )
      {
        t = t + ( double ) ( i * ( n - j + 1 ) ) / ( double ) ( n + 1 );
      }
      else
      {
        t = t + ( double ) ( j * ( n - i + 1 ) ) / ( double ) ( n + 1 );
      }
    }
    b_norm = r8_max ( b_norm, t );
  }

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double dif2_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_DETERMINANT returns the determinant of the DIF2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2_DETERMINANT, the determinant of the matrix.
//
{
  double determ;

  determ = ( double ) ( n + 1 );

  return determ;
}
//****************************************************************************80

double *dif2_eigen_right ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_EIGEN_RIGHT returns the right eigenvectors of the DIF2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2_EIGEN_RIGHT[N*N], the right eigenvector matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( ( i + 1 ) * ( j + 1 ) ) 
        * r8_pi / ( double ) ( n + 1 );
      a[i+j*n] = sqrt ( 2.0 / ( double ) ( n + 1 ) ) * sin ( angle );
    }
  }
  return a;
}
//****************************************************************************80

double *dif2_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_EIGENVALUES returns the eigenvalues of the DIF2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2_EIGENVALUES[N] the eigenvalues.
//
{
  double angle;
  double *lambda;
  int i;
  const double r8_pi = 3.141592653589793;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( 2 * ( n + 1 ) );
    lambda[i] = 4.0 * sin ( angle ) * sin ( angle );
  }
  return lambda;
}
//****************************************************************************80

double *dif2_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_INVERSE returns the inverse of the DIF2 matrix.
//
//  Formula:
//
//    if ( I <= J )
//      A(I,J) = I * (N-J+1) / (N+1)
//    else
//      A(I,J) = J * (N-I+1) / (N+1)
//
//  Example:
//
//    N = 4
//
//            4 3 2 1
//    (1/5) * 3 6 4 2
//            2 4 6 3
//            1 2 3 4
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    det ( A ) = 1 / ( N + 1 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i <= j )
      {
        a[i+j*n] = ( double ) ( ( i + 1 ) * ( n - j ) ) / ( double ) ( n + 1 );
      }
      else
      {
        a[i+j*n] = ( double ) ( ( j + 1 ) * ( n - i ) ) / ( double ) ( n + 1 );
      }
    }
  }
  return a;
}
//****************************************************************************80

double *dif2_llt ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_LLT returns the lower triangular Cholesky factor of the DIF2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2_LLT[N*N], the matrix.
//
{
  double *a;
  int i;

  a = r8mat_zero_new ( n, n );

  for ( i = 0; i < n; i++ )
  {
    a[i+i*n] = sqrt ( ( double ) ( i + 2 ) ) 
             / sqrt ( ( double ) ( i + 1 ) );
  }

  for ( i = 1; i < n; i++ )
  {
    a[i+(i-1)*n] = - sqrt ( ( double ) ( i     ) ) 
                   / sqrt ( ( double ) ( i + 1 ) );
  }

  return a;
}
//****************************************************************************80

void dif2_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_PLU returns the PLU factors of the DIF2 matrix.
//
//  Discussion:
//
//    A = P * L * U
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the pivot
//    matrix, the unit lower triangular matrix, and the upper
//    triangular matrix that form the PLU factoriztion of A.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        l[i+j*n] = 1.0;
      }
      else if ( i - 1 == j )
      {
        l[i+j*n] = - ( double ) ( i ) / ( double ) ( i + 1 );
      }
      else
      {
        l[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        u[i+j*n] = ( double ) ( i + 2 ) / ( double ) ( i + 1 );
      }
      else if ( i + 1 == j )
      {
        u[i+j*n] = -1.0;
      }
      else
      {
        u[i+j*n] = 0.0;
      }
    }
  }
  return;
}
//****************************************************************************80

double *dif2_rhs ( int m, int k )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_RHS returns the DIF2 right hand side.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the row dimension.
//
//    Input, int K, the column dimension ( should be 2).
//
//    Output, double DIF2_RHS[M*K], the right hand side matrix.
//
{
  double *b;
  int i;

  b = new double[m*k];

  b[0+0*m]= 1.0;
  for ( i = 1; i < m - 1; i++ )
  {
    b[i+0*m] = 0.0;
  }
  b[m-1+0*m] = 1.0;

  for ( i = 0; i < m - 1; i++ )
  {
    b[i+1*m] = 0.0;
  }
  b[m-1+1*m] = ( double ) ( m + 1 );

  return b;
}
//****************************************************************************80

double *dif2_rtr ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_RTR returns the upper triangular Cholesky factor of the DIF2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 August 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2_RTR[N*N], the matrix.
//
{
  double *a;
  int i;

  a = r8mat_zero_new ( n, n );

  for ( i = 0; i < n; i++ )
  {
    a[i+i*n] = sqrt ( ( double ) ( i + 2 ) ) 
             / sqrt ( ( double ) ( i + 1 ) );
  }

  for ( i = 1; i < n; i++ )
  {
    a[i-1+i*n] = - sqrt ( ( double ) ( i     ) ) 
                 / sqrt ( ( double ) ( i + 1 ) );
  }

  return a;
}
//****************************************************************************80

double *dif2_solution ( int n, int k )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2_SOLUTION returns the DIF2 solution matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the row dimension.
//
//    Input, int K, the column dimension ( should be 2).
//
//    Output, double DIF2_SOLUTION[N*K], the solution matrix.
//
{
  int i;
  double *x;

  x = new double[n*k];

  for ( i = 0; i < n; i++ )
  {
    x[i+0*n] = 1.0;
  }

  for ( i = 0; i < n; i++ )
  {
    x[i+1*n] = ( double ) ( i + 1 );
  }
  return x;
}
//****************************************************************************80

double *dif2cyclic ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2CYCLIC returns the DIF2CYCLIC matrix.
//
//  Example:
//
//    N = 5
//
//    2 -1  .  . -1
//   -1  2 -1  .  .
//    . -1  2 -1  .
//    .  . -1  2 -1
//   -1  .  . -1  2
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is centrosymmetric: A(I,J) = A(N+1-I,N+1-J).
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    A is (weakly) row diagonally dominant.
//
//    A is (weakly) column diagonally dominant.
//
//    A is singular.
//
//    det ( A ) = 0.
//
//    A is cyclic tridiagonal.
//
//    A is Toeplitz: constant along diagonals.
//
//    A has constant row sum = 0.
//
//    Because it has a constant row sum of 0,
//    A has an eigenvalue of 0, and
//    a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has constant column sum = 0.
//
//    Because it has a constant column sum of 0,
//    A has an eigenvalue of 0, and
//    a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2CYCLIC[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( ( ( n + i - j ) % n ) == 1 )
      {
        a[i+j*n] = -1.0;
      }
      else if ( j == i )
      {
        a[i+j*n] = 2.0;
      }
      else if ( ( ( n + j - i ) % n ) == 1 )
      {
        a[i+j*n] = -1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double dif2cyclic_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2CYCLIC_DETERMINANT: determinant of the DIF2CYCLIC matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DIF2CYCLIC_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 0.0;

  return determ;
}
//****************************************************************************80

double *dif2cyclic_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2CYCLIC_NULL_LEFT returns a left null vector of the DIF2CYCLIC matrix.
//
//  Discussion:
//
//    X(1:M) = 1 is a null vector.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double DIF2CYCLIC_NULL_LEFT[M], the null vector.
//
{
  int i;
  double *x;

  x = new double[m];

  for ( i = 0; i < m; i++ )
  {
    x[i] = 1.0;
  }
  return x;
}
//****************************************************************************80

double *dif2cyclic_null_right ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DIF2CYCLIC_NULL_RIGHT returns a right null vector of the DIF2CYCLIC matrix.
//
//  Discussion:
//
//    X(1:N) = 1 is a null vector.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double DIF2CYCLIC_NULL_RIGHT[N], the null vector.
//
{
  int i;
  double *x;

  x = new double[n];

  for ( i = 0; i < n; i++ )
  {
    x[i] = 1.0;
  }
  return x;
}
//****************************************************************************80

double *dorr ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DORR returns the DORR matrix.
//
//  Formula:
//
//    if ( I <= (N+1) / 2 )
//
//      if ( J = I - 1 )
//        A[i+j*n] = - ALPHA * (N+1)^2
//      else if ( J = I )
//        A[i+j*n] = 2 * ALPHA * (N+1)^2 + 0.5 * (N+1) - I
//      else if ( J = I + 1 )
//        A[i+j*n] = - ALPHA * (N+1)^2 - 0.5 * (N+1) + I
//      else
//        A[i+j*n] = 0
//
//    else
//
//      if ( J = I - 1 )
//        A[i+j*n] = - ALPHA * (N+1)^2 + 0.5 * (N+1) - I
//      else if ( J = I )
//        A[i+j*n] = 2 * ALPHA * (N+1)^2 - 0.5 * (N+1) + I
//      else if ( J = I + 1 )
//        A[i+j*n] = - ALPHA * (N+1)^2
//      else
//        A[i+j*n] = 0
//
//  Example:
//
//    ALPHA = 7, N = 5
//
//     506 -254    0    0    0
//    -252  505 -253    0    0
//       0 -252  504 -252    0
//       0    0 -253  505 -252
//       0    0    0 -254  506
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is row diagonally dominant, since the absolute value of the diagonal
//    entry always equals ( or exceeds, I = 1 and N ) the sum of the
//    absolute values of the two off diagonal row entries.
//
//    A is irreducibly diagonally dominant, and hence nonsingular.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 3.
//
//    A is an M matrix.
//
//    0 < INVERSE(A).
//
//    A is centrosymmetric: A[i+j*n] = A(N+1-I,N+1-J).
//
//    A is symmetrizable.  There is a positive definite diagonal matrix
//    D so that INVERSE(D)*A*D is symmetric.
//
//    The eigenvalues of A are positive, so the matrix
//    INVERSE(D)*A*D is positive definite.
//
//    The Gauss-Seidel and Jacobi iterative methods for solving
//    A*x = b both converge.  Furthermore, if RHO(GS) is the
//    spectral radius of the Gauss-Seidel iteration matrix, and
//    RHO(J) the spectral radius of the Jacobi iteration matrix,
//    then RHO(GS) = RHO(J)^2 < 1.
//
//    A is ill-conditioned for small values of ALPHA.  The
//    test case used N = 100, and ALPHA=0.01, 0.003, 0.001 and
//    1.0D-10.  The matrix A was already very ill-conditioned for
//    ALPHA = 0.003, with the minimum eigenvalue being 1.8D-12, and
//    the maximum one being 199.87.
//
//    The columns of INVERSE(A) vary greatly in norm.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Fred Dorr,
//    An example of ill-conditioning in the numerical solution of
//    singular perturbation problems,
//    Mathematics of Computation,
//    Volume 25, Number 114, 1971, pages 271-283.
//
//  Parameters:
//
//    Input, double ALPHA, scalar that defines the matrix.
//    A typical value of ALPHA is 0.01.
//
//    Input, int N, the order of the matrix.
//
//    Output, double DORR[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double np1_r8;

  a = new double[n*n];

  np1_r8 = ( double ) ( n + 1 );

  for ( j = 1; j <= n; j++ )
  {
    for ( i = 1; i <= n; i++ )
    {
      if ( i <= ( n + 1 ) / 2 )
      {
        if ( j == i - 1 )
        {
          a[i-1+(j-1)*n] = - alpha * pow ( np1_r8, 2 ); 
        }
        else if ( j == i )
        {
          a[i-1+(j-1)*n] = 2.0 * alpha * pow ( np1_r8, 2 ) + 0.5 * np1_r8 
           - ( double ) ( i );
        }
        else if ( j == i + 1 )
        {
          a[i-1+(j-1)*n] = - alpha * pow ( np1_r8, 2 ) - 0.5 * np1_r8 
            + ( double ) ( i );
        }
        else
        {
          a[i-1+(j-1)*n] = 0.0;
        }
      }
      else
      {
        if ( j == i - 1 )
        {
          a[i-1+(j-1)*n] = - alpha * pow ( np1_r8, 2 ) + 0.5 * np1_r8 
            - ( double ) ( i );
        }
        else if ( j == i )
        {
          a[i-1+(j-1)*n] = 2.0 * alpha * pow ( np1_r8, 2 ) - 0.5 * np1_r8 
            + ( double ) ( i );
        }
        else if ( j == i + 1 )
        {
          a[i-1+(j-1)*n] = - alpha * pow ( np1_r8, 2 );
        }
        else
        {
          a[i-1+(j-1)*n] = 0.0;
        }
      }
    }
  }
  return a;
}
//****************************************************************************80

double dorr_determinant ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DORR_DETERMINANT computes the determinant of the DORR matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, scalar that defines the matrix.
//    A typical value of ALPHA is 0.01.
//
//    Input, int N, the order of the matrix.
//
//    Output, double DORR_DETERMINANT, the determinant.
//
{
  double determ_nm1;
  double determ_nm2;
  int i;
  int j;
  double np1_r8;
  double value;
  double *x;
  double *y;
  double *z;
//
//  Form the three diagonals.
//
  x = new double[n-1];
  y = new double[n];
  z = new double[n-1];

  np1_r8 = ( double ) ( n + 1 );

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i <= ( n + 1 ) / 2 )
      {
        if ( j == i - 1 )
        {
          x[i-2] = - alpha * pow ( np1_r8, 2 ); 
        }
        else if ( j == i )
        {
          y[i-1] = 2.0 * alpha * pow ( np1_r8, 2 ) + 0.5 * np1_r8 
           - ( double ) ( i );
        }
        else if ( j == i + 1 )
        {
          z[i-1] = - alpha * pow ( np1_r8, 2 ) - 0.5 * np1_r8 
            + ( double ) ( i );
        }
      }
      else
      {
        if ( j == i - 1 )
        {
          x[i-2] = - alpha * pow ( np1_r8, 2 ) + 0.5 * np1_r8 
            - ( double ) ( i );
        }
        else if ( j == i )
        {
          y[i-1] = 2.0 * alpha * pow ( np1_r8, 2 ) - 0.5 * np1_r8 
            + ( double ) ( i );
        }
        else if ( j == i + 1 )
        {
          z[i-1] = - alpha * pow ( np1_r8, 2 );
        }
      }
    }
  }
//
//  Compute the determinant.
//
  determ_nm1 = y[n-1];
  value = determ_nm1;

  if ( 1 < n )
  {
    determ_nm2 = determ_nm1;
    determ_nm1 = y[n-2] * y[n-1] - z[n-2] * x[n-2];

    value = determ_nm1;

    for ( i = n - 3; 0 <= i; i-- )
    {
      value = y[i] * determ_nm1 - z[i] * x[i] * determ_nm2;
      determ_nm2 = determ_nm1;
      determ_nm1 = value;
    }
  }
//
//  Free memory.
//
  delete [] x;
  delete [] y;
  delete [] z;

  return value;
}
//****************************************************************************80

double *dorr_inverse ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    DORR_INVERSE returns the inverse of the DORR matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    CM daFonseca, J Petronilho,
//    Explicit Inverses of Some Tridiagonal Matrices,
//    Linear Algebra and Its Applications,
//    Volume 325, 2001, pages 7-21.
//
//  Parameters:
//
//    Input, double ALPHA, scalar that defines the matrix.
//    A typical value of ALPHA is 0.01.
//
//    Input, int N, the order of the matrix.
//
//    Output, double DORR_INVERSE[N*N], the inverse of the matrix.
//
{
  double *a;
  double *d;
  double *e;
  int i;
  int j;
  double np1_r8;
  double *x;
  double *y;
  double *z;
//
//  Form the three diagonals.
//
  x = new double[n-1];
  y = new double[n];
  z = new double[n-1];

  np1_r8 = ( double ) ( n + 1 );

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i <= ( n + 1 ) / 2 )
      {
        if ( j == i - 1 )
        {
          x[i-2] = - alpha * pow ( np1_r8, 2 ); 
        }
        else if ( j == i )
        {
          y[i-1] = 2.0 * alpha * pow ( np1_r8, 2 ) + 0.5 * np1_r8 
            - ( double ) ( i );
        }
        else if ( j == i + 1 )
        {
          z[i-1] = - alpha * pow ( np1_r8, 2 ) - 0.5 * np1_r8 
            + ( double ) ( i );
        }
      }
      else
      {
        if ( j == i - 1 )
        {
          x[i-2] = - alpha * pow ( np1_r8, 2 ) + 0.5 * np1_r8 
            - ( double ) ( i );
        }
        else if ( j == i )
        {
          y[i-1] = 2.0 * alpha * pow ( np1_r8, 2 ) - 0.5 * np1_r8 
            + ( double ) ( i );
        }
        else if ( j == i + 1 )
        {
          z[i-1] = - alpha * pow ( np1_r8, 2 );
        }
      }
    }
  }
//
//  Compute the inverse.
//
  a = new double[n];

  d = new double[n];

  d[n-1] = y[n-1];
  for ( i = n - 2; 0 <= i; i-- )
  {
    d[i] = y[i] - x[i] * z[i]/ d[i+1];
  }

  e = new double[n];

  e[0] = y[0];
  for ( i = 1; i < n; i++ )
  {
    e[i] = y[i] - x[i-1] * z[i-1] / e[i-1];
  }

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j <= i; j++ )
    {
      a[i+j*n] = r8_mop ( i + j ) 
        * r8vec_product ( i - j, x+j ) 
        * r8vec_product ( n - i - 1, d+i+1 ) 
        / r8vec_product ( n - j, e+j );
    }
    for ( j = i + 1; j < n; j++ )
    {
      a[i+j*n] = r8_mop ( i + j ) 
        * r8vec_product ( j - i, z+i) 
        * r8vec_product ( n - j - 1, d+j+1) 
        / r8vec_product ( n - i, e+i);
    }
  }
//
//  Free memory.
//
  delete [] d;
  delete [] e;
  delete [] x;
  delete [] y;
  delete [] z;

  return a;
}
//****************************************************************************80

double *downshift ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DOWNSHIFT returns the DOWNSHIFT matrix.
//
//  Formula:
//
//    if ( I-J == 1 mod ( n ) )
//      A(I,J) = 1
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 4
//
//    0 0 0 1
//    1 0 0 0
//    0 1 0 0
//    0 0 1 0
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a zero/one matrix.
//
//    A is generally not symmetric: A' /= A.
//
//    A is nonsingular.
//
//    A is a permutation matrix.
//
//    det ( A ) = (-1)^(N-1)
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//    A is an N-th root of the identity matrix.
//    Therefore, the inverse of A = A^(N-1).
//
//    Any circulant matrix generated by a column vector v can be regarded as
//    the Krylov matrix ( v, A*v, A^2*V, ..., A^(N-1)*v).
//
//    The inverse of A is the upshift operator.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DOWNSHIFT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i4_modp ( i - j, n ) == 1 )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double downshift_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DOWNSHIFT_CONDITION returns the L1 condition of the DOWNSHIFT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DOWNSHIFT_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 1.0;
  b_norm = 1.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double downshift_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DOWNSHIFT_DETERMINANT returns the determinant of the DOWNSHIFT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DOWNSHIFT_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( n % 2 ) == 0 )
  {
    determ = - 1.0;
  }
  else
  {
    determ = + 1.0;
  }
  return determ;
}
//****************************************************************************80

complex <double> *downshift_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DOWNSHIFT_EIGENVALUES returns the eigenvalues of the DOWNSHIFT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> DOWNSHIFT_EIGENVALUES[N], the eigenvalues.
//
{
  complex <double> *lambda;

  lambda = c8vec_unity ( n );

  return lambda;
}
//****************************************************************************80

double *downshift_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    DOWNSHIFT_INVERSE returns the inverse of the DOWNSHIFT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DOWNSHIFT[N*N], the inverse.
//
{
  double *a;

  a = upshift ( n );

  return a;
}
//****************************************************************************80

double *eberlein ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    EBERLEIN returns the EBERLEIN matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = - ( 2 * I - 1 ) * ( N - 1 ) - ( I - 1 ) * ALPHA + 2 * ( I - 1 )^2
//    else if ( J = I + 1 )
//      A(I,J) = I * ( N + ALPHA - I )
//    else if ( J = I - 1 )
//      A(I,J) = ( I - 1 ) * ( N - I + 1 )
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5, ALPHA = 2
//
//    -4   6   0   0   0
//     4 -12  10   0   0
//     0   6 -16  12   0
//     0   0   6 -16  12
//     0   0   0   4 -12
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    The matrix is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 3.
//
//    The sum of the entries in any row except the last one is ALPHA.
//
//    The sum of the entries in the last row is -(N-1)*ALPHA.
//
//    The sum of the entries in any column is zero.
//
//    A is singular.
//
//    det ( A ) = 0
//
//    A has the LEFT null vector ( 1, 1, ..., 1 ).
//
//    LAMBDA(I) = - ( I - 1 ) * ( ALPHA + I ).
//
//    Left eigenvectors are
//
//      V^J(I) = 1/COMB(N-1,I-1) * sum ( 0 <= K <= min ( I, J ) ) [ (-1)**K *
//        COMB(N-1-K,N-I) * COMB(J-1,K) * COMB(ALPHA+J-1+K, K )
//
//    For ALPHA = -2, ..., -2*(N-1), the matrix is defective with two or more
//    pairs of eigenvectors coalescing.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Patricia Eberlein,
//    A Two-Parameter Test Matrix,
//    Mathematics of Computation,
//    Volume 18, 1964, pages 296-298.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int N, the order of the matrix.
//
//    Output, double EBERLEIN[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 1; j <= n; j++ )
  {
    for ( i = 1; i <= n; i++ )
    {
      if ( j == i )
      {
        a[i-1+(j-1)*n] = - ( ( double ) ( ( 2 * i - 1 ) * ( n - 1 ) ) 
          + ( double ) ( i - 1 ) * alpha 
          - ( double ) ( 2 * ( i - 1 ) * ( i - 1 ) ) );
      }
      else if ( j == i + 1 )
      {
        a[i-1+(j-1)*n] = ( double ) ( i ) * ( ( double ) ( n - i ) + alpha );
      }
      else if ( j == i - 1 )
      {
        a[i-1+(j-1)*n] = ( double ) ( ( i - 1 ) * ( n - i + 1 ) );
      }
      else
      {
        a[i-1+(j-1)*n] = 0.0;
      }
    }
  }

  return a;
} 
//****************************************************************************80

double eberlein_determinant ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    EBERLEIN_DETERMINANT returns the determinant of the EBERLEIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int N, the order of the matrix.
//
//    Output, double EBERLEIN_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 0.0;

  return determ;
}
//****************************************************************************80

double *eberlein_eigenvalues ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    EBERLEIN_EIGENVALUES returns the eigenvalues of the EBERLEIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int N, the order of the matrix.
//
//    Output, double EBERLEIN_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = - ( double ) ( i ) * ( alpha + ( double ) ( i + 1 ) );
  }

  return lambda;
}
//****************************************************************************80

double *eberlein_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    EBERLEIN_NULL returns a left null vector of the EBERLEIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double EBERLEIN_NULL_LEFT[M], the null vector.
//
{
  int i;
  double *x;

  x = new double[m];

  for ( i = 0; i < m; i++ )
  {
    x[i] = 1.0;
  }

  return x;
}
//****************************************************************************80

double *eulerian ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    EULERIAN returns the EULERIAN matrix.
//
//  Discussion:
//
//    A run in a permutation is a sequence of consecutive ascending values.
//
//    E(I,J) is the number of permutations of I objects which contain
//    exactly J runs.
//
//  Example:
//
//     N = 7
//
//     1     0     0     0     0     0     0
//     1     1     0     0     0     0     0
//     1     4     1     0     0     0     0
//     1    11    11     1     0     0     0
//     1    26    66    26     1     0     0
//     1    57   302   302    57     1     0
//     1   120  1191  2416  1191   120     1
//
//  Recursion:
//
//    E(I,J) = J * E(I-1,J) + (I-J+1) * E(I-1,J-1).
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is nonnegative.
//
//    A is unit lower triangular.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    LAMBDA(1:N) = 1.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Dennis Stanton, Dennis White,
//    Constructive Combinatorics,
//    Springer Verlag, 1986.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double EULERIAN[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[m*n];

  a[0+0*m] = 1.0;
  for ( j = 1; j < n; j++ )
  {
    a[0+j*m] = 0.0;
  }

  for ( i = 1; i < m; i++ )
  {
    a[i+0*m] = 1.0;
    for ( j = 1; j < n; j++ )
    {
      a[i+j*m] = ( double ) ( j + 1 ) * a[i-1+j*m] 
        + ( double ) ( i - j + 1 ) * a[i-1+(j-1)*m];
    }
  }

  return a;
}
//****************************************************************************80

double eulerian_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    EULERIAN_DETERMINANT returns the determinant of the EULERIAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double EULERIAN_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *eulerian_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    EULERIAN_INVERSE computes the inverse of the EULERIAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double EULERIAN_INVERSE[N*N], the inverse of the Eulerian matrix.
//
{
  double *a;
  double *b;
  int i;
  int j;
  int k;
  double temp;
//
//  Set up the Eulerian matrix.
//
  b = eulerian ( n, n );
//
//  Compute the inverse A of a unit lower triangular matrix B.
//
  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i < j )
      {
        a[i+j*n] = 0.0;
      }
      else if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j < i )
      {
        temp = 0.0;
        for ( k = j; k < i; k++ )
        {
          temp = temp + b[i+k*n] * a[k+j*n];
        }
        a[i+j*n] = - temp;
      }
    }
  }
//
//  Free memory.
//
  delete [] b;

  return a;
}
//****************************************************************************80

double *exchange ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    EXCHANGE returns the EXCHANGE matrix.
//
//  Formula:
//
//    if ( I + J = N + 1 )
//      A(I,J) = 1
//    else
//      A(I,J) = 0
//
//  Example:
//
//    M = 4, N = 5
//
//    0 0 0 0 1
//    0 0 0 1 0
//    0 0 1 0 0
//    0 1 0 0 0
//
//    M = 5, N = 5
//
//    0 0 0 0 1
//    0 0 0 1 0
//    0 0 1 0 0
//    0 1 0 0 0
//    1 0 0 0 0
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a zero/one matrix.
//
//    A is nonsingular.
//
//    A is a permutation matrix.
//
//    A has property A.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//    A is involutory: A * A = I.
//
//    A is a square root of the identity matrix.
//
//    A is orthogonal: A' * A = A * A' = I.
//
//    det ( A ) = ( -1 )^(N/2).
//
//    There are N/2 eigenvalues of -1, and (N+1)/2 eigenvalues of 1.
//
//    For each pair of distinct vector indices I1 and I2 that sum to N+1, there
//    is an eigenvector which has a 1 in the I1 and I2 positions and 0 elsewhere,
//    and there is an eigenvector for -1, with a 1 in the I1 position and a -1
//    in the I2 position.  If N is odd, then there is a single eigenvector
//    associated with the index I1 = (N+1)/2, having a 1 in that index and zero
//    elsewhere, associated with the eigenvalue 1.
//
//    If H is a Hankel matrix, then J*H and H*J are Toepliz matrices.
//
//    If T is a Toeplitz matrix, then J*T and T*J are Hankel matrices.
//
//    The exchange matrix is also called:
//    * the "counter-identity matrix",
//    * the "anti-identity matrix",
//    * the "reversal matrix".
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double EXCHANGE[M*N], the matrix.
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
      if ( i + j == n - 1 )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double exchange_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    EXCHANGE_CONDITION returns the L1 condition of the EXCHANGE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double EXCHANGE_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 1.0;
  b_norm = 1.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double exchange_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    EXCHANGE_DETERMINANT returns the determinant of the EXCHANGE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double EXCHANGE_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( ( n / 2 ) % 2 ) == 0 )
  {
    determ = 1.0;
  }
  else
  {
    determ = - 1.0;
  }

  return determ;
}
//****************************************************************************80

double *exchange_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    EXCHANGE_EIGENVALUES returns the eigenvalues of the EXCHANGE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double EXCHANGE_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < ( n / 2 ); i++ )
  {
    lambda[i] = - 1.0;
  }
  for ( i = ( n / 2 ); i < n; i++ )
  {
    lambda[i] = 1.0;
  }

  return lambda;
}
//****************************************************************************80

double *exchange_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    EXCHANGE_INVERSE returns the inverse of the EXCHANGE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double EXCHANGE_INVERSE[N*N], the matrix.
//
{
  double *a;

  a = exchange ( n, n );

  return a;
}
//****************************************************************************80

double *exchange_eigen_right ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    EXCHANGE_EIGEN_RIGHT returns the right eigenvectors of the EXCHANGE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double EXCHANGE_EIGEN_RIGHT[N*N], the eigenvector matrix.
//
{
  int i;
  int j;
  int n2;
  double *x;

  x = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      x[i+j*n] = 0.0;
    }
  }
  n2 = n / 2;

  for ( j = 0; j < n2; j++ )
  {
    i = n - 1 - j;

    x[j+j*n] =  1.0;
    x[i+j*n] = -1.0;

    x[j+i*n] =  1.0;
    x[i+i*n] =  1.0;
  }

  if ( ( n % 2 ) == 1 )
  {
    x[n2+n2*n] = 1.0;
  }

  return x;
}
//****************************************************************************80

double *fibonacci1 ( int n, double f1, double f2 )

//****************************************************************************80
//
//  Purpose:
//
//    FIBONACCI1 returns the FIBONACCI1 matrix.
//
//  Example:
//
//    N = 5
//    F1 = 1, F2 = 2
//
//    1  2  3  5  8
//    2  3  5  8 13
//    3  5  8 13 21
//    5  8 13 21 34
//    8 13 21 34 55
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    If F1 and F2 are integral, then so is A.
//
//    If A is integral, then det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//    If B is the Fibonacci iteration matrix:
//
//      B * A(F1,F2) = A(F2,F2+F1) = A(F2,F3)
//
//    and in general,
//
//      B^N * A(F1,F2) = A(F(N+1),F(N+2))
//
//    For 2 < N, the matrix is singular, because row 3 is the sum
//    of row 1 and row 2.
//
//    For 2 <= N,
//      rank ( A ) = 2
//
//    If N = 1, then
//      det ( A ) = 1
//    else if N = 2 then
//      det ( A ) = -1
//    else if 1 < N then
//      det ( A ) = 0
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double F1, F2, the first two elements of the sequence
//    that will generate the Fibonacci sequence.
//
//    Output, double FIBONACCI1[N*N], the matrix.
//
{
  double *a;
  double fn;
  double fnm1;
  double fnm2;
  int i;
  int j;
  int k;

  a = new double[n*n];

  a[0+0*n] = f1;
  a[1+0*n] = f2;
  a[0+1*n] = f2;

  fnm2 = f1;
  fnm1 = f2;
  fn   = fnm1 + fnm2;

  for ( k = 2; k <= n + n - 2; k++ )
  {   
    i = i4_min ( k,     n - 1 );
    j = i4_max ( 0, k - n + 1 );

    while ( 0 <= i && j < n )
    {
      a[i+j*n] = fn;
      i = i - 1;
      j = j + 1;
    }

    fnm2 = fnm1;
    fnm1 = fn;
    fn   = fnm1 + fnm2;
  }
  return a;
}
//****************************************************************************80

double fibonacci1_determinant ( int n, double f1, double f2 )

//****************************************************************************80
//
//  Purpose:
//
//    FIBONACCI1_DETERMINANT returns the determinant of the FIBONACCI1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double F1, F2, the first two elements of the sequence
//    that will generate the Fibonacci sequence.
//
//    Output, double FIBONACCI1_DETERMINANT, the determinant.
//
{
  double determ;

  if ( n == 1 )
  {
    determ = 1.0;
  }
  else if ( n == 2 )
  {
    determ = -1.0;
  }
  else
  {
    determ = 0.0;
  }

  return determ;
}
//****************************************************************************80

double *fibonacci1_null_left ( int m, int n, double f1, double f2 )

//****************************************************************************80
//
//  Purpose:
//
//    FIBONACCI1_NULL_LEFT returns a left null vector of the FIBONACCI1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double F1, F2, the first two elements of the sequence
//    that will generate the Fibonacci sequence.
//
//    Output, double FIBONACCI1_NULL_LEFT[M], a null vector.
//
{
  int i;
  double *x;

  if ( m < 3 )
  {
    cerr << "\n";
    cerr << "FIBONACCI1_NULL_LEFT - Fatal error!\n";
    cerr << "  3 <= M is required.\n";
    exit ( 1 );
  }

  x = new double[m];

  for ( i = 1; i <= m - 3; i++ )
  {
    x[i-1] = 0.0;
  }
  x[m-3] = - 1.0;
  x[m-2] = - 1.0;
  x[m-1] = + 1.0;

  return x;
}
//****************************************************************************80

double *fibonacci1_null_right ( int m, int n, double f1, double f2 )

//****************************************************************************80
//
//  Purpose:
//
//    FIBONACCI1_NULL_RIGHT returns a right null vector of the FIBONACCI1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double F1, F2, the first two elements of the sequence
//    that will generate the Fibonacci sequence.
//
//    Output, double FIBONACCI1_NULL_RIGHT[N], a null vector.
//
{
  int i;
  double *x;

  if ( n < 3 )
  {
    cerr << "\n";
    cerr << "FIBONACCI1_NULL_RIGHT - Fatal error!\n";
    cerr << "  3 <= N is required.\n";
    exit ( 1 );
  }

  x = new double[n];

  for ( i = 1; i <= n - 3; i++ )
  {
    x[i-1] = 0.0;
  }
  x[n-3] = - 1.0;
  x[n-2] = - 1.0;
  x[n-1] = + 1.0;

  return x;
}
//****************************************************************************80

double *fibonacci2_matrix ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    fibonacci2_matrix() returns the FIBONACCI2 matrix.
//
//  Example:
//
//    N = 5
//
//    0 1 0 0 0
//    1 1 0 0 0
//    0 1 1 0 0
//    0 0 1 1 0
//    0 0 0 1 1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 3.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a zero/one matrix.
//
//    If N = 1 then
//      det ( A ) = 0
//    else
//      det ( A ) = -1
//
//    If 1 < N, then A is unimodular.
//
//    When applied to a Fibonacci1 matrix B, the Fibonacci2 matrix
//    A produces the "next" Fibonacci1 matrix C = A*B.
//
//    Let PHI be the golden ratio (1+sqrt(5))/2.
//
//    For 2 <= N, the eigenvalues and eigenvectors are:
//
//    LAMBDA(1)     = PHI,     vector = (1,PHI,PHI^2,...PHI^(N-1));
//    LAMBDA(2:N-1) = 1        vector = (0,0,0,...,0,1);
//    LAMBDA(N)     = 1 - PHI. vector = (1,1-PHI,(1-PHI)^2,...(1-PHI)^(N-1));
//
//    Note that there is only one eigenvector corresponding to 1.
//    Hence, for 3 < N, the matrix is defective.  This fact means, 
//    for instance, that the convergence of the eigenvector in the power 
//    method will be very slow.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 May 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//  Output:
//
//    double FIBONACCI2[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i == 1 )
      {
        if ( j == 2 )
        {
          a[i-1+(j-1)*n] = 1.0;
        }
        else
        {
          a[i-1+(j-1)*n] = 0.0;
        }
      }
      else
      {
        if ( j == i - 1 || j == i )
        {
          a[i-1+(j-1)*n] = 1.0;
        }
        else
        {
          a[i-1+(j-1)*n] = 0.0;
        }
      }
    }
  }
  return a;
}
//****************************************************************************80

double fibonacci2_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    fibonacci2_condition() returns the L1 condition of the FIBONACCI2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//  Output:
//
//    double FIBONACCI2_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  if ( n == 1 )
  {
    cout << "\n";
    cout << "FIBONACCI2_CONDITION - Fatal error!\n";
    cout << "  The condition number is infinite for N=1\n";
    exit ( 1 );
  }

  if ( n == 1 )
  {
    a_norm = 0.0;
  }
  else if ( n == 2 )
  {
    a_norm = 2.0;
  }
  else
  {
    a_norm = 3.0;
  }
  b_norm = ( double ) ( n );
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double fibonacci2_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    fibonacci2_determinant(): determinant of the FIBONACCI2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 May 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//  Output:
//
//    double FIBONACCI2_DETERMINANT, the determinant.
//
{
  double determ;

  if ( n == 1 )
  {
    determ = 0.0;
  }
  else
  {
    determ = -1.0;
  }
  return determ;
}
//****************************************************************************80

double *fibonacci2_eigen_right ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    fibonacci2_eigen_right(): right eigenvectors of the FIBONACCI2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 May 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//  Output:
//
//    double FIBONACCI2_EIGEN_RIGHT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double p;
  double phi;

  a = new double[n*n];

  phi = ( 1.0 + sqrt ( 5.0 ) ) / 2.0;
//
//  Column 1.
//
  j = 0;
  p = 1.0;
  for ( i = 0; i < n; i++ )
  {
    a[i+j*n] = p;
    p = p * phi;
  }
//
//  Columns 2:N-1
//
  for ( j = 1; j <= n - 2; j++ )
  {
    for ( i = 0; i < n - 1; i++ )
    {
      a[i+j*n] = 0.0;
    }
    i = n - 1;
    a[i+j*n] = 1.0;
  }
//
//  Column N
//
  j = n - 1;
  p = 1.0;
  for ( i = 0; i < n; i++ )
  {
    a[i+j*n] = p;
    p = p * ( 1.0 - phi );
  }

  return a;
}
//****************************************************************************80

double *fibonacci2_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    fibonacci2_eigenvalues() returns the eigenvalues of the FIBONACCI2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//  Output:
//
//    double FIBONACCI2_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;
  double phi;

  lambda = new double[n];

  if ( n == 1 )
  {
    lambda[0] = 0.0;
  }
  else
  {
    phi = 0.5 * ( 1.0 + sqrt ( 5.0 ) );

    lambda[0] = phi;
    for ( i = 2; i < n; i++ )
    {
      lambda[i-1] = 1.0;
    }
    lambda[n-1] = 1.0 - phi;
  }
  return lambda;
}
//****************************************************************************80

double *fibonacci2_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    fibonacci2_inverse() returns the inverse of the FIBONACCI2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//  Output:
//
//    double FIBONACCI2_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double s;

  if ( n == 1 )
  {
    cerr << "\n";
    cerr << "FIBONACCI2_INVERSE - Fatal error!\n";
    cerr << "  The inverse does not exist for N = 1.\n";
    exit ( 1 );
  }

  a = new double[n*n];
//
//  Column 1.
//
  j = 1;
  s = - 1.0;
  for ( i = 1; i <= n; i++ )
  {
    a[i-1+(j-1)*n] = s;
    s = - s;
  }
//
//  Column 2
//
  j = 2;
  a[1-1+(j-1)*n] = 1.0;
  for ( i = 2; i <= n; i++ )
  {
    a[i-1+(j-1)*n] = 0.0;
  }
//
//  Columns 3:N
//
  for ( j = 3; j <= n; j++ )
  {
    for ( i = 1; i <= j - 1; i++ )
    {
      a[i-1+(j-1)*n] = 0.0;
    }
    s = 1.0;
    for ( i = j; i <= n; i++ )
    {
      a[i-1+(j-1)*n] = s;
      s = - s;
    }
  }
  return a;
}
//****************************************************************************80

double *fibonacci3 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FIBONACCI3 returns the FIBONACCI3 matrix.
//
//  Example:
//
//    N = 5
//
//    1 -1  0  0  0
//    1  1 -1  0  0
//    0  1  1 -1  0
//    0  0  1  1 -1
//    0  0  0  1  1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 3.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    The determinant of A is the Fibonacci number F(N+1).
//
//    A is a special case of the TRIS tridiagonal scalar matrix.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FIBONACCI3[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( j == i - 1 || j == i )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == i + 1 )
      {
        a[i+j*n] = - 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double fibonacci3_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FIBONACCI3_DETERMINANT returns the determinant of the FIBONACCI3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FIBONACCI3_DETERMINANT, the determinant.
//
{
  double determ;
  int f1;
  int f2;
  int f3;
  int i;

  f1 = 0;
  f2 = 0;
  f3 = 1;

  for ( i = 1; i <= n; i++ )
  {
    f1 = f2;
    f2 = f3;
    f3 = f1 + f2;
  }
  determ = ( double ) ( f3 );

  return determ;
}
//****************************************************************************80

complex <double> *fibonacci3_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FIBONACCI3_EIGENVALUES returns the eigenvalues of the FIBONACCI3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> FIBONACCI3_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  int i;
  complex <double> *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new complex <double>[n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 1 );
    lambda[i] = complex <double> ( 1.0, 2.0 * cos ( angle ) );
  }

  return lambda;
}
//****************************************************************************80

double *fibonacci3_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FIBONACCI3_INVERSE returns the inverse of the FIBONACCI3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    CM daFonseca, J Petronilho,
//    Explicit Inverses of Some Tridiagonal Matrices,
//    Linear Algebra and Its Applications,
//    Volume 325, 2001, pages 7-21.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FIBONACCI3_INVERSE[N*N], the inverse of the matrix.
//
{
  double *a;
  double *d;
  int i;
  int j;

  d = new double[n];

  d[n-1] = 1.0;
  for ( i = n - 2; 0 <= i; i-- )
  {
    d[i] = 1.0 + 1.0 / d[i+1];
  }

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j <= i; j++ )
    {
      a[i+j*n] = r8_mop ( i + j ) 
        * r8vec_product ( n - 1 - i, d + i + 1 ) 
        / r8vec_product ( n - j, d );
    }
    for ( j = i + 1; j < n; j++ )
    {
      a[i+j*n] =  
          r8vec_product ( n - 1 - j, d + j + 1 ) 
        / r8vec_product ( n - i, d );
    }
  }
//
//  Free memory.
//
  delete [] d;

  return a;
}
//****************************************************************************80

double *fiedler ( int m, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    FIEDLER returns the FIEDLER matrix.
//
//  Discussion:
//
//    See page 159 of the Todd reference.
//
//  Formula:
//
//    A(I,J) = abs ( X(I) - X(J) )
//
//  Example:
//
//    M = 5, N = 5, X = ( 1, 2, 3, 5, 9 )
//
//    0  1  2  4  8
//    1  0  1  3  7
//    2  1  0  2  6
//    4  3  2  0  4
//    8  7  6  4  0
//
//  Properties:
//
//    A has a zero diagonal.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    det ( A ) = (-1)^N * 2^(N-2)
//      * ( X(1) - X(N) ) * product ( 2 <= I <= N ) ( X(I) - X(I-1) ).
//
//    NOTE: the formula for the determinant seems to be correct only
//    if the X's are sorted in ascending order//
//
//    A is nonsingular if the X(I) are distinct.
//
//    The inverse is cyclic tridiagonal; that is, it is tridiagonal, except
//    for nonzero (1,N) and (N,1) entries.
//
//    A has a dominant positive eigenvalue, and all others are negative.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gabor Szego,
//    Solution to problem 3705,
//    American Mathematical Monthly,
//    Volume 43, Number 4, 1936, pages 246-259.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double X[ max (M,N) ], the values that define A.
//
//    Output, double FIEDLER[M*N], the matrix.
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
      a[i+j*m] = fabs ( x[i] - x[j] );
    }
  }

  return a;
}
//****************************************************************************80

double fiedler_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    FIEDLER_DETERMINANT returns the determinant of the FIEDLER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the values that define A.
//
//    Output, double FIEDLER_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int j;
  double t;
  double *y;

  y = new double[n];

  determ = pow ( 2.0, n - 2 );

  if ( ( n % 2 ) == 1 )
  {
    determ = - determ;
  }

  for ( i = 0; i < n; i++ )
  {
    y[i] = x[i];
  }

  for ( i = 0; i < n - 1; i++ )
  {
    for ( j = i + 1; j < n; j++ )
    {
      if ( y[j] < y[i] )
      {
        t    = y[j];
        y[j] = y[i];
        y[i] = t;
        determ = - determ;
      }
    }
  }

  determ = determ * ( y[n-1] - y[0] );

  for ( i = 1; i < n; i++ )
  {
    determ = determ * ( y[i] - y[i-1] );
  }
//
//  Free memory.
//
  delete [] y;

  return determ;
}
//****************************************************************************80

double *fiedler_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    FIEDLER_INVERSE returns the inverse of the FIEDLER matrix.
//
//  Discussion:
//
//    This routine is only correct if the X values are in ascending (or
//    descending) order.  It would be a simple matter to handle the general
//    case but I have not set that up.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the values that define A.
//    For this routine, it is assumed that the X values are sorted.
//
//    Output, double FIEDLER_INVERSE[N*N], the matrix.
//
{
  double *a;
  double d1;
  double d2;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  d1 = 0.5 / ( x[n-1] - x[0] );
  d2 = 0.5 / ( x[0]   - x[1] );

  a[0+(n-1)*n] = + d1;
  a[0+ 0   *n] = + d1 + d2;
  a[0+ 1   *n] =      - d2;

  for ( i = 1; i < n - 1; i++ )
  {
    d1 = 0.5 / ( x[i-1] - x[i] );
    d2 = 0.5 / ( x[i] - x[i+1] );
    a[i+(i-1)*n] = - d1;
    a[i+ i   *n] = + d1 + d2;
    a[i+(i+1)*n] =      - d2;
  }

  d1 = 0.5 / ( x[n-2] - x[n-1] );
  d2 = 0.5 / ( x[n-1] - x[0] );

  a[n-1+(n-2)*n] = - d1;
  a[n-1+(n-1)*n]   =   d1 + d2;
  a[n-1+   0 *n]   =      + d2;

  return a;
}
//****************************************************************************80

double *forsythe ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    FORSYTHE returns the FORSYTHE matrix.
//
//  Discussion:
//
//    The Forsythe matrix represents a Jordan canonical matrix, perturbed
//    by a rank one update.
//
//  Formula:
//
//    If ( I = J )
//      A(I,J) = BETA
//    else if ( J = I + 1 )
//      A(I,J) = 1
//    else if ( I = N and J = 1 ) then
//      A(I,J) = ALPHA
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 2, BETA = 3, N = 5
//
//    3 1 0 0 0
//    0 3 1 0 0
//    0 0 3 1 0
//    0 0 0 3 1
//    2 0 0 0 3
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    The characteristic equation of A is
//
//      ( BETA - LAMBDA )^N - (-1)^N*ALPHA = 0
//
//    The eigenvalues of A are
//
//      LAMBDA(I) = BETA
//        + abs ( ALPHA )^1/N * exp ( 2 * I * PI * sqrt ( - 1 ) / N )
//
//    Gregory and Karney consider the special case where BETA is 0,
//    and ALPHA is a "small" value.  In that case, the characteristic
//    equation is LAMBDA^N - ALPHA = 0, and the eigenvalues are the
//    N-th root of ALPHA times the N roots of unity.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, double ALPHA, BETA, define the matrix.  A typical 
//    value of ALPHA is the square root of the machine precision; a typical
//    value of BETA is 0.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double FORSYTHE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == i )
      {
        a[i+j*n] = beta;
      }
      else if ( j == i + 1 )
      {
        a[i+j*n]= 1.0;
      }
      else if ( i == n - 1 && j == 0 )
      {
        a[i+j*n] = alpha;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double forsythe_determinant ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    FORSYTHE_DETERMINANT returns the determinant of the FORSYTHE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, define the matrix.  A typical 
//    value of ALPHA is the square root of the machine precision; a typical
//    value of BETA is 0.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double FORSYTHE_DETERMINANT, the determinant.
//
{
  double value;

  value = r8_mop ( n - 1 ) * alpha + pow ( beta, n );

  return value;
}
//****************************************************************************80

complex <double> *forsythe_eigenvalues ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    FORSYTHE_EIGENVALUES returns the eigenvalues of the FORSYTHE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, BETA, define the matrix.  A typical 
//    value of ALPHA is the square root of the machine precision; a typical
//    value of BETA is 0.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> FORSYTHE_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  complex <double> c8_i;
  int i;
  complex <double> *lambda;
  const double r8_pi = 3.141592653589793;
  complex <double> w;

  c8_i = complex <double> ( 0.0, 1.0 );

  lambda = new complex <double> [n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( 2 * ( i + 1 ) ) * r8_pi / ( double ) ( n );
    w = exp ( c8_i * angle );
    lambda[i] = beta + pow ( fabs ( alpha ), 1.0 / ( double ) ( n ) ) * w;
  }

  return lambda;
}
//****************************************************************************80

double *forsythe_inverse ( double alpha, double beta, int n )

//****************************************************************************80
//
//  Purpose:
//
//    FORSYTHE_INVERSE returns the inverse of the Forsythe matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, double ALPHA, BETA, define the matrix.
//    The Forsythe matrix does not have an inverse if both ALPHA and BETA are zero.
//
//    Input, int N, the order of the matrix.
//
//    Output, double FORSYTHE_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double z;

  a = new double[n*n];

  if ( beta == 0.0 && alpha == 0.0 )
  {
    cerr << "\n";
    cerr << "FORSYTHE_INVERSE - Fatal error!\n";
    cerr << "  The Forsythe matrix is not invertible if\n";
    cerr << "  both ALPHA and BETA are 0.\n";
    exit ( 1 );
  }
  else if ( beta == 0.0 )
  {
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n; i++ )
      { 
        if ( j == n - 1 )
        {
          a[i+j*n] = 1.0 / alpha;
        }
        else if ( j == i - 1 )
        {
          a[i+j*n] = 1.0;
        }
        else
        {
          a[i+j*n] = 0.0;
        }
      }
    }
  }
//
//  Set up the original Jordan matrix as B.
//
  else
  {
//
//  Compute inverse of unperturbed Jordan matrix.
//
    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n; i++ )
      { 
        if ( i <= j )
        {
          a[i+j*n] =  - pow ( - 1.0 / beta, j + 1 - i );
        }
        else
        {
          a[i+j*n] = 0.0;
        }
      }
    }
//
//  Add rank one perturbation.
//
    z = - 1.0 / beta;

    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < n; i++ )
      {
        a[i+j*n] = a[i+j*n] - alpha * pow ( z, n + 1 + j - i )  
        / ( 1.0 - alpha * pow ( z, n ) );
      }
    }
  }
  return a;
}
//****************************************************************************80

complex <double> *fourier ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER returns the FOURIER matrix.
//
//  Discussion:
//
//    Multiplication of a vector of data by A is equivalent to
//    computing the discrete Fourier transform of the data.  Multiplication by
//    the Hermitian (complex-conjugate-transpose) of A is equivalent
//    to computing the inverse discrete Fourier transform.
//
//  Formula:
//
//    A(I,J) = exp ( 2 * PI * sqrt ( -1 ) * (I-1) * (J-1) / N ) / sqrt ( N )
//
//    or
//
//      A(I,J) = W^((I-1)*(J-1)) / sqrt(N)
//
//    where W is the N-th root of unity.
//
//  Example:
//
//    N = 3
//
//                 1  1  1
//    1/sqrt(3) *  1  J  K
//                 1  K  J
//
//    where
//
//      J = EXP(2*PI*EYE/3) = cos ( 2*PI/3 ) + EYE * sin ( 2 * PI / 3 )
//      K = EXP(4*PI*EYE/3) = cos ( 4*PI/3 ) + EYE * sin ( 4 * PI / 3 )
//
//    or, using the root of unity form, with W = the fourth root of unity,
//
//    N = 4
//
//                1  1     1     1            1  1   1   1
//                1  W     W^2   W^3          1  W  -1  -W
//    1/sqrt(4) * 1  W^2   W^4   W^6  = 1/2 * 1 -1   1  -1
//                1  W^3   W^6   W^9          1 -W  -1   W
//
//  Properties:
//
//    A is complex.
//
//    A is symmetric: A' = A.
//
//    A is unitary, that is, the inverse of A is the complex
//    conjugate of A: INVERSE(A) = CONJUGATE(A)
//
//    The fourth power of A is the identity, that is, A*A*A*A = I.
//
//    The eigenvalues of A must have the values +1, -1, +i or -i.
//
//    A is a Vandermonde matrix based on the N roots of unity, scaled
//    by sqrt(N).
//
//    A is the eigenvector matrix of any circulant matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 October 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> FOURIER[N*N], the Fourier matrix.
//
{
  complex <double> *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new complex <double>[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = 2.0 * r8_pi * ( double ) ( i * j ) / ( double ) ( n );

      a[i+j*n] = exp ( c8_i ( ) * angle ) / sqrt ( ( double ) ( n ) );
    }
  }
  return a;
}
//****************************************************************************80

complex <double> fourier_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_DETERMINANT returns the determinant of the FOURIER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> FOURIER_DETERMINENT, the determinant.
//
{
  complex <double> determ;

       if ( ( n % 8 ) == 0 || ( n % 8 ) == 7 )
  {
    determ = complex <double> (  0.0,  1.0 );
  }
  else if ( ( n % 8 ) == 1 || ( n % 8 ) == 6 )
  {
    determ = complex <double> (  1.0,  0.0 );
  }
  else if ( ( n % 8 ) == 2 || ( n % 8 ) == 5 )
  {
    determ = complex <double> ( -1.0,  0.0 );
  }
  else if ( ( n % 8 ) == 3 || ( n % 8 ) == 4 )
  {
    determ = complex <double> (  0.0, -1.0 );
  }
  return determ;
}
//****************************************************************************80

complex <double> *fourier_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_EIGENVALUES returns the eigenvalues of the FOURIER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> FOURIER_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  complex <double> *lambda;

  lambda = new complex <double>[n];

  lambda[0] = 1.0;

  for ( i = 1; i < n; i = i + 1 )
  {
    lambda[i] = complex <double> ( - 1.0,   0.0 );
  }
  for ( i = 2; i < n; i = i + 1 )
  {
    lambda[i] = complex <double> (   0.0,   1.0 );
  }
  for ( i = 3; i < n; i = i + 1 )
  {
    lambda[i] = complex <double> (   1.0,   0.0 );
  }
  for ( i = 4; i < n; i = i + 1 )
  {
    lambda[i] = complex <double> (   0.0, - 1.0 );
  }
  return lambda;
}
//****************************************************************************80

complex <double> *fourier_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_INVERSE returns the inverse of the FOURIER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, complex <double> FOURIER_INVERSE[N*N], the matrix.
//
{
  complex <double> *a;
  int i;
  int j;
  complex <double> t;

  a = fourier ( n );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      t        = conj ( a[i+j*n] );
      a[i+j*n] = conj ( a[j+i*n] );
      a[j+i*n] = t;
    }
  }
  return a;
}
//****************************************************************************80

double *fourier_cosine ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_COSINE returns the FOURIER_COSINE matrix.
//
//  Discussion:
//
//    The matrix is related to the discrete Fourier Cosine Transform.
//
//  Example:
//
//    N = 5
//
//    0.447214      0.447214      0.447214      0.447214      0.447214
//    0.601501      0.371748      0.000000     -0.371748     -0.601501
//    0.511667     -0.195440     -0.632456     -0.195439      0.511667
//    0.371748     -0.601501      0.000000      0.601501     -0.371748
//    0.195439     -0.511667      0.632456     -0.511668      0.195439
//
//  Properties:
//
//    A * A' = I.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 October 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FOURIER_COSINE[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    i = 0;
    a[i+j*n] = 1.0 / sqrt ( ( double ) ( n ) );
    for ( i = 1; i < n; i++ )
    {
      angle = ( double ) ( i * ( 2 * j + 1 ) ) * r8_pi / ( double ) ( 2 * n );
      a[i+j*n] = sqrt ( 2.0 ) * cos ( angle ) / sqrt ( ( double ) ( n ) );
    }
  }
  return a;
}
//****************************************************************************80

double fourier_cosine_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_COSINE_DETERMINANT: determinant of the FOURIER_COSINE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FOURIER_COSINE_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( n % 2 ) == 1 )
  {
    determ = + 1.0;
  }
  else
  {
    determ = - 1.0;
  }
  return determ;
}
//****************************************************************************80

double *fourier_cosine_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_COSINE_INVERSE returns the inverse of the FOURIER_COSINE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 October 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FOURIER_COSINE_INVERSE[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    i = 0;
    a[j+i*n] = 1.0 / sqrt ( ( double ) ( n ) );
    for ( i = 1; i < n; i++ )
    {
      angle = ( double ) ( i * ( 2 * j + 1 ) ) * r8_pi / ( double ) ( 2 * n );
      a[j+i*n] = sqrt ( 2.0 ) * cos ( angle ) / sqrt ( ( double ) ( n ) );
    }
  }
  return a;
}
//****************************************************************************80

double *fourier_sine ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_SINE returns the FOURIER_SINE matrix.
//
//  Discussion:
//
//    The matrix is related to the discrete Fourier Sine Transform.
//
//    This matrix is occasionally known as the "Newman" matrix.
//
//  Formula:
//
//    A(I,J) = sqrt ( 2 / (N+1) ) * SIN ( I * J * PI / (N+1) )
//
//  Example:
//
//    N = 5
//
//     0.288675     0.5    0.577350    0.5    0.288675
//     0.5          0.5    0.0        -0.5   -0.5
//     0.577350     0.0   -0.577350    0.0    0.577350
//     0.5         -0.5    0.0         0.5   -0.5
//     0.288675    -0.5    0.577350   -0.5    0.288675
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is orthogonal: A' * A = A * A' = I.
//
//    A is involutory: A * A = I.
//
//    A is generally not positive definite.
//
//    All eigenvalues of A have absolute value 1.
//
//    A is the eigenvector matrix of the second difference matrix (-1,2,-1).
//
//    A can be used to compute the Discrete Fourier Sine Transform of
//    a set of data X,
//       DFST ( X ) = A * X
//    A second multiplication by A recovers the original data.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Nicholas Higham, Desmond Higham,
//    Large growth factors in Gaussian elimination with pivoting,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 10, 1989, pages 155-164.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, FOURIER_SINE[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( ( i + 1 ) * ( j + 1 ) ) * r8_pi 
            / ( double ) ( n + 1 );
      a[i+j*n] = sin ( angle ) * sqrt ( 2.0 / ( double ) ( n + 1 ) );
    }
  }
  return a;
}
//****************************************************************************80

double fourier_sine_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_SINE_DETERMINANT returns the determinant of the FOURIER_SINE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FOURIER_SINE_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( n % 2 ) == 1 )
  {
    determ = + 1.0;
  }
  else
  {
    determ = - 1.0;
  }
  return determ;
}
//****************************************************************************80

double *fourier_sine_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FOURIER_SINE_INVERSE returns the inverse of the FOURIER_SINE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Nicholas Higham, Desmond Higham,
//    Large growth factors in Gaussian elimination with pivoting,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 10, 1989, pages 155-164.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FOURIER_SINE_INVERSE[N*N], the matrix.
//
{
  double *a;

  a = fourier_sine ( n );

  return a;
}
//****************************************************************************80

double *frank ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FRANK returns the FRANK matrix.
//
//  Formula:
//
//    if ( I <= J )
//      A(I,J) = N+1-J
//    else if ( J = I-1 )
//      A(I,J) = N-J
//    else
//      A(I,J) = 0.0
//
//  Example:
//
//    N = 5
//
//    5 4 3 2 1
//    4 4 3 2 1
//    . 3 3 2 1
//    . . 2 2 1
//    . . . 1 1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is upper Hessenberg.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    The eigenvalues of A are related to the zeros of the Hermite
//    polynomials.
//
//    The eigenvalues of A are real and positive, and occur in reciprocal
//    pairs, LAMBDA and 1/LAMBDA.
//
//    if N is odd, then 1 is an eigenvalue.
//
//    For N = 12, the eigenvalues of A range from 32.2 to 0.031, with
//    the smaller eigenvalues having a condition number of 10^7,
//    meaning that a change in the matrix of order 10^(-7) can
//    result in a change in the eigenvalue of order 1.  The actual
//    eigenvalues are:
//
//      0.031028060644010
//      0.049507429185278
//      0.081227659240405
//      0.143646519769220
//      0.284749720558478
//      0.6435053190048555
//      1.55398870913210790
//      3.511855948580757194
//      6.961533085567122113
//     12.311077408868526120
//     20.198988645877079428
//     32.228891501572160750
//
//    The (N/2) smaller eigenvalues of A are ill-conditioned.
//
//    For large N, the computation of the determinant of A
//    comes out very far from its correct value of 1.
//
//    Simple linear systems:
//      x = (0,0,0,...,1),   A*x = (1,1,1,...,1)
//      x = (1,1,1,...,1),   A*x = ( n*(n+1)/2 (entry 1), 
//                                  (n+1-i)*(n+4-i)/2 (entries i = 2 to n)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Patricia Eberlein,
//    A note on the matrices denoted by $B n$,
//    SIAM Journal on Applied Mathematics,
//    Volume 20, 1971, pages 87-92.
//
//    WL Frank,
//    Computing eigenvalues of complex matrices by determinant
//    evaluation, and by methods of Danilewski and Wielandt,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, 1958, pages 378-392.
//
//    Gene Golub, James Wilkinson,
//    Ill-conditioned eigensystems and the computation of the Jordan
//    canonical form,
//    SIAM Review,
//    Volume 18, Number 4, 1976, pages 578-619.
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Heinz Rutishauser,
//    On test matrices,
//    Programmation en Mathematiques Numeriques, 
//    Editions Centre Nat. Recherche Sci., Paris, 165,
//    1966, pages 349-365.
//
//    James Varah,
//    A generalization of the Frank matrix,
//    SIAM Journal on Scientific and Statistical Computing,
//    Volume 7, 1986, pages 835-839.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//    James Wilkinson,
//    Error analysis of floating-point computation,
//    Numerische Mathematik,
//    Volume 2, 1960, pages 319-340.
//
//    James Wilkinson,
//    The Algebraic Eigenvalue Problem,
//    Oxford University Press, 1965, pages 92-93.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FRANK[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i <= j )
      {
        a[i-1+(j-1)*n] = ( double ) ( n + 1 - j );
      }
      else if ( j == i - 1 )
      {
        a[i-1+(j-1)*n] = ( double ) ( n - j );
      }
      else
      {
        a[i-1+(j-1)*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double frank_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FRANK_DETERMINANT returns the determinant of the FRANK matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FRANK_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *frank_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FRANK_EIGENVALUES returns the eigenvalues of the Frank matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 April 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    James Varah,
//    A generalization of the Frank matrix,
//    SIAM Journal on Scientific and Statistical Computing,
//    Volume 7, Number 3, August 1986, pages 835-839.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FRANK_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = hermite_roots ( n );
  for ( i = 0; i < n; i++ )
  {
    lambda[i] = lambda[i] * sqrt ( 2.0 );
  }
  for ( i = 0; i < n; i++ )
  {
    lambda[i] = pow ( 
      0.5 * lambda[i] + sqrt ( 0.25 * lambda[i] * lambda[i] + 1.0 ), 2 );
  }
  return lambda;
}
//****************************************************************************80

double *frank_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    FRANK_INVERSE returns the inverse of the FRANK matrix.
//
//  Formula:
//
//    if ( I = J-1 ) then
//      A(I,J) = -1
//    else if ( I = J ) then
//      if ( I = 1 ) then
//        A(I,J) = 1
//      else
//        A(I,J) = N + 2 - I
//    else if ( J < I ) then
//      A(I,J) = - (N+1-I) * A(I-1,J)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//     1  -1  0  0  0
//    -4   5 -1  0  0
//    12 -15  4 -1  0
//   -24  30 -8  3 -1
//    24 -30  8 -3  2
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is lower Hessenberg.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double FRANK_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 1; i <= n; i++ )
  {
    for ( j = 1; j <= n; j++ )
    {
      if ( i == j -  1 )
      {
        a[i-1+(j-1)*n] = - 1.0;
      }
      else if ( i == j )
      {
        if ( i == 1 )
        {
          a[i-1+(j-1)*n] = 1.0;
        }
        else
        {
          a[i-1+(j-1)*n] = ( double ) ( n + 2 - i );
        }
      }
      else if ( j < i )
      {
        a[i-1+(j-1)*n] = - ( double ) ( n + 1 - i ) * a[i-2+(j-1)*n];
      }
      else
      {
        a[i-1+(j-1)*n] = 0.0;
      }
    }
  }

  return a;
}
//****************************************************************************80

double *frank_rhs ( int m, int k )

//****************************************************************************80
//
//  Purpose:
//
//    FRANK_RHS returns the FRANK right hand side.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the row dimension.
//
//    Input, int K, the column dimension ( should be 2).
//
//    Output, double FRANK_RHS[M*K], the right hand side matrix.
//
{
  double *b;
  int i;

  b = new double[m*k];

  for ( i = 0; i < m; i++ )
  {
    b[i+0*m] = 1.0;
  }

  b[0+1*m] = ( double ) ( ( m * ( m + 1 ) ) / 2 );
  for ( i = 2; i <= m; i++ )
  {
    b[i-1+1*m] = ( double ) ( ( ( m + 1 - i ) * ( m + 4 - i ) ) / 2 );
  }

  return b;
}
//****************************************************************************80

double *frank_solution ( int n, int k )

//****************************************************************************80
//
//  Purpose:
//
//    FRANK_SOLUTION returns the FRANK solution matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the row dimension.
//
//    Input, int K, the column dimension ( should be 2).
//
//    Output, double FRANK_SOLUTION[N*K], the solution matrix.
//
{
  int i;
  double *x;

  x = new double[n*k];

  for ( i = 0; i < n - 1; i++ )
  {
    x[i+0*n] = 0.0;
  }
  x[n-1+0*n] = 1.0;

  for ( i = 0; i < n; i++ )
  {
    x[i+1*n] = 1.0;
  }

  return x;
}
//****************************************************************************80

double *gfpp ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    GFPP returns the GFPP matrix.
//
//  Discussion:
//
//    The GFPP matrix has a maximal growth factor for Gauss elimination.
//
//  Formula:
//
//    if ( I = J or J = N )
//      A(I,J) = 1.0
//    else if ( J < I )
//      A(I,J) = - abs ( ALPHA )
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5, ALPHA = 1
//
//    A =
//
//    1     0     0     0     1
//   -1     1     0     0     1
//   -1    -1     1     0     1
//   -1    -1    -1     1     1
//   -1    -1    -1    -1     1
//
//    P = Identity
//
//    L =
//
//    1     0     0     0     0
//   -1     1     0     0     0
//   -1    -1     1     0     0
//   -1    -1    -1     1     0
//   -1    -1    -1    -1     1
//
//    U =
//
//    1     0     0     0     1
//    0     1     0     0     2
//    0     0     1     0     4
//    0     0     0     1     8
//    0     0     0     0    16
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    If ALPHA is between 0 and 1, then Gaussian elimination with partial
//    pivoting yields a controllable growth factor of (1+ALPHA)^(N-1).
//    and a P factor which is the identity, an L factor equal to the lower
//    triangle of A, and an U factor which is equal to the identity matrix,
//    except that the last column is
//
//      [ 1, ALPHA+1, (ALPHA+1)^2, ...(ALPHA+1)^N-1 ].
//
//    If ALPHA is not between 0 and 1, then Gauss elimination WITHOUT
//    pivoting will yield the same pivot growth factor and PLU factorization
//    just described, but Gauss elimination with partial pivoting will not.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Nicholas Higham, Desmond Higham,
//    Large growth factors in Gaussian elimination with pivoting,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 10, 1989, pages 155-164.
//
//    Lloyd Trefethen, David Bau,
//    Numerical Linear Algebra,
//    SIAM, 1997, pages 165-166.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, determines subdiagonal elements.
//
//    Output, double GFPP[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j || j == n - 1 )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j < i )
      {
        a[i+j*n] = - fabs ( alpha );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double gfpp_condition ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    GFPP_CONDITION returns the L1 condition of the GFPP matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, determines subdiagonal elements.
//
//    Output, double GFPP_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 1.0 + ( double ) ( n - 1 ) * fabs ( alpha );
  b_norm = 1.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double gfpp_determinant ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    GFPP_DETERMINANT returns the determinant of the GFPP matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, determines subdiagonal elements.
//
//    Output, double GFPP_DETERMINANT, the determinant.
//
{
  double value;

  value = pow ( 1.0 + fabs ( alpha ), n - 1 );

  return value;
}
//****************************************************************************80

double *gfpp_inverse ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    GFPP_INVERSE returns the inverse of the GFPP matrix.
//
//  Example:
//
//    N = 5, ALPHA = 1
//
//    0.5000   -0.2500   -0.1250   -0.0625   -0.0625
//         0    0.5000   -0.2500   -0.1250   -0.1250
//         0         0    0.5000   -0.2500   -0.2500
//         0         0         0    0.5000   -0.5000
//    0.5000    0.2500    0.1250    0.0625    0.0625
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, determines subdiagonal elements.
//
//    Output, double GFPP_INVERSE[N*N], the inverse matrix.
//
{
  double *a;
  double *l;
  double *l_inverse;
  double *lp_inverse;
  double *p;
  double *p_inverse;
  double *u;
  double *u_inverse;

  p = new double[n*n];
  l = new double[n*n];
  u = new double[n*n];

  gfpp_plu ( n, alpha, p, l, u );

  p_inverse = r8mat_transpose_new ( n, n, p );

  l_inverse = tri_l1_inverse ( n, l );

  lp_inverse = r8mat_mm_new ( n, n, n, l_inverse, p_inverse );

  u_inverse = tri_u_inverse ( n, u );

  a = r8mat_mm_new ( n, n, n, u_inverse, lp_inverse );
//
//  Free memory.
//
  delete [] l;
  delete [] l_inverse;
  delete [] lp_inverse;
  delete [] p;
  delete [] p_inverse;
  delete [] u;
  delete [] u_inverse;
 
  return a;
}
//****************************************************************************80

void gfpp_plu ( int n, double alpha, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    GFPP_PLU returns the PLU factorization of the GFPP matrix.
//
//  Discussion
//
//    This factorization assumes that Gaussian elimination is performed
//    without pivoting.  If ALPHA is not between 0 and 1, then the
//    PLU factors returned here will not be the PLU factors derived
//    from Gaussian elimination with pivoting.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, determines subdiagonal elements.
//
//    Output, double P[N*N], L[N*N], U[N*N], the P, L, U factors
//    of the matrix.
//
{
  int i;
  int j;
  double u_sum;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      l[i+j*n] = 0.0;
    }
    i = j;
    l[i+j*n] = 1.0;
    for ( i = j + 1; i < n; i++ )
    {
      l[i+j*n] = - fabs ( alpha );
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        u[i+j*n] = 1.0;
      }
      else
      {
        u[i+j*n] = 0.0;
      }
    }
  }
  
  u[0+(n-1)*n] = 1.0;
  u_sum = 1.0;
  for ( i = 1; i < n; i++ )
  {
    u[i+(n-1)*n] = 1.0 + fabs ( alpha ) * u_sum;
    u_sum = u_sum + u[i+(n-1)*n];
  }

  return;
}
//****************************************************************************80

double *givens ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    GIVENS returns the GIVENS matrix.
//
//  Discussion:
//
//    Note that this is NOT the "Givens rotation matrix".  This
//    seems to be more commonly known as the Moler matrix.
//
//  Formula:
//
//    A(I,J) = 2 * min ( I, J ) - 1
//
//  Example:
//
//    N = 5
//
//    1 1 1 1 1
//    1 3 3 3 3
//    1 3 5 5 5
//    1 3 5 7 7
//    1 3 5 7 9
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is positive definite.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    The inverse of A is tridiagonal.
//
//    A has a simple Cholesky factorization.
//
//    A has eigenvalues
//
//      LAMBDA(I) = 0.5 * sec ( ( 2 * I - 1 ) * PI / ( 4 * N ) )^2
//
//    The condition number P(A) is approximately 16 N^2 / PI^2.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Morris Newman, John Todd,
//    Example A9,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double GIVENS[M*N], the matrix.
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
      a[i+j*m] = ( double ) ( 2 * i4_min ( i, j ) + 1 );
    }
  }
  return a;
}
//****************************************************************************80

double givens_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GIVENS_CONDITION returns the L1 condition of the GIVENS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double GIVENS_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = ( double ) ( n * n );

  if ( n == 1 )
  {
    b_norm = 1.0;
  }
  else
  {
    b_norm = 2.0;
  }

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double givens_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GIVENS_DETERMINANT returns the determinant of the GIVENS matrix.
//
//  Discussion:
//
//    Since a formula for the eigenvalues is known, we compute the
//    determinant as the product of those values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double GIVENS_DETERMINANT, the determinant.
//
{
  double angle;
  int i;
  const double r8_pi = 3.141592653589793;
  double value;

  value = 1.0;

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( 2 * i + 1 ) * r8_pi / ( double ) ( 4 * n );
    value = value * 0.5 / pow ( cos ( angle ), 2 );
  }

  return value;
}
//****************************************************************************80

double *givens_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GIVENS_EIGENVALUES returns the eigenvalues of the GIVENS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double GIVENS_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  int i;
  double *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( 2 * i + 1 ) * r8_pi / ( double ) ( 4 * n );
    lambda[i] = 0.5 / pow ( cos ( angle ), 2 );
  }
  return lambda;
}
//****************************************************************************80

double *givens_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GIVENS_INVERSE returns the inverse of the GIVENS matrix.
//
//  Formula:
//
//    if ( I = J = 1 )
//      A(I,J) = 1.5
//    else if ( I = J < N )
//      A(I,J) = 1.0
//    else if ( I = J = N )
//      A(I,J) = 0.5
//    else if ( J = I + 1 or J = I - 1 )
//      A(I,J) = -0.5
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//           3 -1  0  0  0
//          -1  2 -1  0  0
//    1/2 *  0 -1  2 -1  0
//           0  0 -1  2 -1
//           0  0  0 -1  1
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double GIVENS_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        if ( i == 0 )
        {
          a[i+j*n] = 1.5;
        }
        else if ( i < n - 1 )
        {
          a[i+j*n] = 1.0;
        }
        else
        {
          a[i+j*n] = 0.5;
        }
      }
      else if ( i == j + 1 )
      {
        a[i+j*n] = - 0.5;
      }
      else if ( i == j - 1 )
      {
        a[i+j*n] = - 0.5;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//*****************************************************************************/

double *givens_llt ( int n )

//*****************************************************************************/
//
//  Purpose:
//
//    GIVENS_LLT returns the Cholesky factor of the GIVENS matrix.
//
//  Example:
//
//    N = 5
//
//    1    0        0        0       0
//    1  sqrt(2)    0        0       0
//    1  sqrt(2)  sqrt(2)    0       0
//    1  sqrt(2)  sqrt(2)  sqrt(2)   0
//    1  sqrt(2)  sqrt(2)  sqrt(2) sqrt(2)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double GIVENS_LLT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  j = 0;
  for ( i = 0; i < n; i++ )
  {
    a[i+j*n] = 1.0;
  }

  for ( i = 0; i < n; i++ )
  {
    for ( j = 1; j <= i; j++ )
    {
      a[i+j*n] = sqrt ( 2.0 );
    }
    for ( j = i + 1; j < n; j++ )
    {
      a[i+j*n] = 0.0;
    }
  }
  return a;
}
//****************************************************************************80

void givens_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    GIVENS_PLU returns the PLU factors of the GIVENS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      l[i+j*n] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      l[i+j*n] = 1.0;
    }
  }

  i = 0;
  for ( j = 0; j < n; j++ )
  {
    u[i+j*n] = 1.0;
  }

  for ( i = 1; i < n; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      u[i+j*n] = 0.0;
    }
    for ( j = i; j < n; j++ )
    {
      u[i+j*n] = 2.0;
    }
  }

  return;
}
//****************************************************************************80

double *gk316 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GK316 returns the GK316 matrix.
//
//  Formula:
//
//    if ( I == N )
//      A(I,J) = J
//    else if ( J == N )
//      A(I,J) = I
//    else if ( I == J )
//      A(I,J) = 1.0
//    else
//      A(I,J) = 0.0
//
//  Example:
//
//    N = 5
//
//     1  0  0  0  1
//     0  1  0  0  2
//     0  0  1  0  3
//     0  0  0  1  4
//     1  2  3  4  5
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A has property A (the first set is 1:N-1, the second is just N).
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    det ( A ) = - N * ( N + 1 ) * ( 2 * N - 5 ) / 6.
//
//    N-2 eigenvalues are equal to 1, while the remaining eigenvalues
//    are the roots of X^2 - (N+1)*X - N*(N+1)*(2*N-5)/6 = 0.
//
//    A is border-banded.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Aegerter,
//    Construction of a Set of Test Matrices,
//    Communications of the ACM,
//    Volume 2, Number 8, 1959, pages 10-12.
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double GK316[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == n - 1 )
      {
        a[i+j*n] = ( double ) ( j + 1 );
      }
      else if ( j == n - 1 )
      {
        a[i+j*n] = ( double ) ( i + 1 );
      }
      else if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double gk316_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GK316_DETERMINANT returns the determinant of the GK316 matrix.
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
//    Input, int N, the order of the matrix.
//
//    Output, double GK316_DETERMINANT, the determinant..
//
{
  double determ;

  determ = - ( double ) ( n * ( n + 1 ) * ( 2 * n - 5 ) ) / 6.0;

  return determ;
}
//****************************************************************************80

double *gk316_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GK316_EIGENVALUES returns the eigenvalues of the GK316 matrix.
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
//    Input, int N, the order of the matrix.
//
//    Output, double GK316_EIGENVALUES[N], the eigenvalues.
//
{
  double a;
  double b;
  double c;
  int i;
  double *lambda;

  lambda = new double[n];

  if ( n == 1 )
  {
    lambda[0] = 1.0;
  }
  else
  {
    for ( i = 0; i < n - 2; i++ )
    {
      lambda[i] = 1.0;
    }
    a = 1.0;
    b = - ( double ) ( n + 1 );
    c = - ( double ) ( n * ( n + 1 ) * ( 2 * n - 5 ) ) / 6.0;

    lambda[n-2] = ( - b + sqrt ( b * b - 4.0 * a * c ) ) / ( 2.0 * a );
    lambda[n-1] = ( - b - sqrt ( b * b - 4.0 * a * c ) ) / ( 2.0 * a );
  }
  return lambda;
}
//****************************************************************************80

double *gk316_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GK316_INVERSE returns the inverse of the GK316 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double GK316_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double t;

  a = new double[n*n];

  t = 6.0 / ( double ) ( n * ( n + 1 ) * ( 2 * n - 5 ) );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j && i < n - 1 )
      {
        a[i+j*n] = 1.0 - t * ( double ) ( ( i + 1 ) * ( i + 1 ) );
      }
      else if ( i == j && i == n - 1 )
      {
        a[i+j*n] = - t;
      }
      else if ( i < n - 1 && j < n - 1 )
      {
        a[i+j*n] = - t * ( double ) ( ( i + 1 ) * ( j + 1 ) );
      }
      else if ( i == n - 1 )
      {
        a[i+j*n] = t * ( double ) ( j + 1 );
      }
      else if ( j == n - 1 )
      {
        a[i+j*n] = t * ( double ) ( i + 1 );
      }
    }
  }
  return a;
}
//****************************************************************************80

double *gk323 ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    GK323 returns the GK323 matrix.
//
//  Discussion:
//
//    This matrix is occasionally known as the "Todd" matrix.
//
//  Formula:
//
//    A(I,J) = abs ( I - J )
//
//  Example:
//
//    N = 5
//
//     0  1  2  3  4
//     1  0  1  2  3
//     2  1  0  1  2
//     3  2  1  0  1
//     4  3  2  1  0
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a special case of the Fiedler matrix.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    det ( A ) = (-1)^(N-1) * 2^(N-2) * ( N - 1 ).
//
//    A has a dominant positive eigenvalue, and N-1 real negative eigenvalues.
//
//    If N = 2 mod 4, then -1 is an eigenvalue, with an eigenvector
//    of the form ( 1, -1, -1, 1, 1, -1, -1, 1, ... ).
//
//    The family of matrices is nested as a function of N.
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
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double GK322[M*N], the matrix.
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
      a[i+j*m] = ( double ) ( abs ( i - j ) );
    }
  }
  return a;
}
//****************************************************************************80

double gk323_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GK323_DETERMINANT returns the determinant of the GK323 matrix.
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
//    Input, int N, the order of the matrix.
//
//    Output, double GK322_DETERMINANT, the determinant.
//
{
  double determ;

  determ = r8_mop ( n - 1 ) 
    * ( double ) ( i4_power ( 2,  n - 2 ) * ( n - 1 ) );

  return determ;
}
//****************************************************************************80

double *gk323_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    GK323_INVERSE returns the inverse of the GK323 matrix.
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
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
//    Input, int N, the order of the matrix.
//
//    Output, double GK323_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {

      if ( i == j )
      {
        if ( i == 0 || i == n - 1 )
        {
          a[i+j*n] = - 0.5 * ( double ) ( n - 2 ) / ( double ) ( n - 1 );
        }
        else
        {
          a[i+j*n] = - 1.0;
        }
      }
      else if ( i == j + 1 || i == j - 1 )
      {
        a[i+j*n] = 0.5;
      }
      else if ( i == 0 && j == n - 1 )
      {
        a[i+j*n] = 0.5 / ( double ) ( n - 1 );
      }
      else if ( i == n - 1 && j == 0 )
      {
        a[i+j*n] = 0.5 / ( double ) ( n - 1 );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *gk324 ( int m, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    GK324 returns the GK324 matrix.
//
//  Discussion:
//
//    This is Gregory and Karney example matrix 3.24.
//
//  Example:
//
//    M = N = 5
//
//    X = ( 11, 12, 13, 14 )
//
//     1  1  1  1  1
//    11  1  1  1  1
//    11 12  1  1  1
//    11 12 13  1  1
//    11 12 13 14  1
//
//  Properties:
//
//    The family of matrices is nested as a function of N.
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
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, 
//    * double X[N-1], the first N-1 entries of the
//      last row, if M <= N, 
//    or 
//    * double X[N], the N entries of the last row,
//      if N < M.
//
//    Output, double GK324[M*N], the matrix.
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
      if ( i <= j )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = x[j];
      }
    }
  }
  return a;
}
//****************************************************************************80

double gk324_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    GK324_DETERMINANT returns the determinant of the GK324 matrix.
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
//    Input, int N, the order of the matrix.
//
//    Input, double X[N-1], the first N-1 entries of the
//    last row.
//
//    Output, double GK324_DETERMINANT, the determinant.
//
{
  double determ;
  int i;

  determ = 1.0;
  for ( i = 0; i < n - 1; i++ )
  {
    determ = determ * ( 1.0 - x[i] );
  }
  return determ;
}
//****************************************************************************80

double *gk324_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    GK324_INVERSE returns the inverse of the GK324 matrix.
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
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N-1], the first N-1 entries of the
//    last row.
//
//    Output, double GK324_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i < n - 1 )
      {
        if ( j < i )
        {
          a[i+j*n] = 0.0;
        }
        else if ( j == i )
        {
          a[i+j*n] = 1.0 / ( 1.0 - x[i] );
        }
        else if ( j == i + 1 )
        {
          a[i+j*n] = - 1.0 / ( 1.0 - x[i] );
        }
        else if ( i + 1 < j )
        {
          a[i+j*n] = 0.0;
        }
      }
      else if ( i == n - 1 )
      {
        if ( j == 0 )
        {
          a[i+j*n] = - x[0] / ( 1.0 - x[0] );
        }
        else if ( j < n - 1 )
        {
          a[i+j*n] = ( x[j-1] - x[j] ) 
                 / ( 1.0 - x[j] ) / ( 1.0 - x[j-1] );
        }
        else if ( j == n - 1 )
        {
          a[i+j*n] = 1.0 / ( 1.0 - x[n-2] );
        }
      }
    }
  }
  return a;
}
//****************************************************************************80

double *grcar ( int m, int n, int k )

//****************************************************************************80
//
//  Purpose:
//
//    GRCAR returns the GRCAR matrix.
//
//  Formula:
//
//    if ( I == J+1 )
//      A(I,J) = -1.0
//    else if ( I <= J .and. J <= I + K ) then
//      A(I,J) = 1.0
//    else
//      A(I,J) = 0.0
//
//  Example:
//
//    M = 5, N = 5, K = 2
//
//     1  1  1  0  0
//    -1  1  1  1  0
//     0 -1  1  1  1
//     0  0 -1  1  1
//     0  0  0 -1  1
//
//  Properties:
//
//    The diagonal and first K superdiagonals are 1, while the first
//    subdiagonal is -1.
//
//    A is banded, with bandwidth K+2.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is upper Hessenberg.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is generally not symmetric: A' /= A.
//
//    The eigenvalues are sensitive.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joseph Grcar,
//    Operator coefficient methods for linear equations,
//    Technical Report SAND89-8691, 
//    Sandia National Laboratories, 
//    Albuquerque, New Mexico, 1989.
//
//    NM Nachtigal, Lothar Reichel, Lloyd Trefethen,
//    A hybrid GMRES algorithm for nonsymmetric linear systems,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 13, 1992, pages 796-825.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, int K, the number of superdiagonals of 1's.  
//     0 <= K <= N-1.
//
//    Output, double GRCAR[M*N], the matrix.
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
      if ( i == j + 1 )
      {
        a[i+j*m] = -1.0;
      }
      else if ( i <= j && j <= i + k )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *hadamard ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    HADAMARD returns the HADAMARD matrix.
//
//  Discussion:
//
//    A Hadamard matrix is a square matrix A of order N, whose entries are
//    only +1's or -1's, with the property that:
//
//      A * A' = N * I.
//
//    A Hadamard matrix must be of order 1, 2, or else a multiple of 4.
//    It is not known whether a Hadamard matrix exists for every multiple
//    of 4.
//
//    The method used here allows the user to request a Hadamard matrix
//    of any rectangular order, M by N.  The algorithm then essentially
//    finds the largest powers of 2 that are less than or equal to M and
//    N, and produces a Hadamard-like matrix in that space, setting the
//    rest of the matrix to 0.  Thus, the matrix returned by this routine
//    is only a Hadamard matrix if M = N = a power of 2.
//
//  Formula:
//
//    The following recursive formula is used to produce a series of
//    Hadamard matrices of increasing size.
//
//    H(0) = [1]
//
//    H(1) = [ H(0)  H(0) ] = [ 1  1]
//           [ H(0) -H(0) ]   [ 1 -1]
//
//    H(2) = [ H(1)  H(1) ] = [ 1  1  1  1]
//           [ H(1) -H(1) ]   [ 1 -1  1 -1]
//                            [ 1  1 -1 -1]
//                            [ 1 -1 -1  1]
//
//    and so on.
//
//  Properties:
//
//    All entries of a Hadamard matrix are either +1 or -1.  Matrices
//    produced by this routine will be +1 or -1 up to a certain row
//    and column, beyond which the entries will be zero.
//
//    The Hadamard matrices produced by this routine have the property
//    that the first row and column are entirely 1's, although this
//    is not a requirement for a Hadamard matrix.
//
//    The matrices produced by this algorithm are (loosely) symmetric,
//    although that is not required for a Hadamard matrix.
//
//    Hadamard matrices exhibit the maximum possible relative growth of pivot
//    elements during Gaussian elimination with complete pivoting.
//
//    The inverse of a Hadamard matrix of order N is A itself,
//    scaled by 1.0/N.  Thus 1.0/sqrt(N) times a Hadamard matrix
//    yields a symmetric matrix which is its own inverse, or
//    "involutory".
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    William Pratt,
//    Digital Image Processing,
//    John Wiley and Sons, 1978.
//
//    Herbert Ryser,
//    Combinatorial Mathematics,
//    John Wiley and Sons, 1963.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double HADAMARD[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int nn;

  if ( m <= 0 )
  {
    cerr << "\n";
    cerr << "HADAMARD - Fatal error!\n";
    cerr << "  Input value of M = " << m << "\n";
    cerr << "  but M must be positive.\n";
    exit ( 1 );
  }

  if ( n <= 0 )
  {
    cerr << "\n";
    cerr << "HADAMARD - Fatal error!\n";
    cerr << "  Input value of N = " << n << "\n";
    cerr << "  but N must be positive.\n";
    exit ( 1 );
  }

  a = new double[m*n];

  a[0+0*m] = 1.0;

  nn = 1;

  while ( nn < n || nn < m )
  {
    for ( i = 0; i < nn; i++ )
    {
      for ( j = 0; j < nn; j++ )
      {
        if ( i + 1 <= m && j + 1 + nn <= n )
        {
          if ( 2 * nn <= n )
          {
            a[i+(j+nn)*m] = a[i+j*m];
          }
          else
          {
            a[i+(j+nn)*m] = 0.0;
          }
        }

        if ( i + 1 + nn <= m && j + 1 <= n ) 
        {
          if ( 2 * nn <= m )
          {
            a[i+nn+j*m] = a[i+j*m];
          }
          else
          {
            a[i+nn+j*m] = 0.0;
          }
        }

        if ( i + 1 + nn <= m && j + 1 + nn <= n )
        {
          if ( 2 * nn <= m && 2 * nn <= n )
          {
            a[i+nn+(j+nn)*m] = - a[i+j*m];
          }
          else
          {
            a[i+nn+(j+nn)*m] = 0.0;
          }
        }
      }
    }
    nn = 2 * nn;
  }
  return a;
}
//****************************************************************************80

double *hamming ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    HAMMING computes the HAMMING matrix.
//
//  Example:
//
//    M = 3, N = 7
//
//    1 1 1 0 1 0 0
//    1 1 0 1 0 1 0
//    1 0 1 1 0 0 1
//
//    7 6 5 3 4 2 1 <-- binary interpretation of columns
//
//  Discussion:
//
//    For a given order M, the Hamming matrix is a rectangular array
//    of M rows and (2^M)-1 columns.  The entries of the matrix are
//    0 and 1.  The columns of A should be interpreted as the binary
//    representations of the integers between 1 and (2^M)-1.
//
//    We can also think of the columns as representing nonempty subsets
//    of an M set.  With this perspective, the columns of the matrix
//    are listed by order of size of subset.  For a given size, the columns
//    are ordered lexicographically.
//
//    The Hamming matrix can be viewed as an embodiment of the Hamming
//    code.  The nonsingleton columns correspond to data bits, and the
//    singleton columns correspond to check bits.  Each row of the
//    matrix represents a condition that the data bits and check bits
//    must satisfy.
//
//  Properties:
//
//    A has full row rank.
//
//    The last M columns of A contain the M by M identity matrix.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a zero-one matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//    N must be equal to (2^M)-1.
//
//    Output, double HAMMING[M*N], the matrix.
//
{
  double *a;
  int *b;
  int i;
  int j;

  if ( n != i4_power ( 2, m ) - 1 )
  {
    cerr << "\n";
    cerr << "HAMMING - Fatal error!\n";
    cerr << "  M = " << m << "\n";
    cerr << "  N = " << n << "\n";
    cerr << "  but N = 2^M-1 is required.\n";
    exit ( 1 );
  }

  a = r8mat_zero_new ( m, n );

  b = new int[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0;
  }

  for ( j = n - 1; 0 <= j; j-- )
  {
    bvec_next_grlex ( m, b );
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( b[i] );
    }
  }

  delete [] b;

  return a;
}
//*****************************************************************************/

double *hamming_null_right ( int m, int n )

//*****************************************************************************/
//
//  Purpose:
//
//    HAMMING_NULL_RIGHT returns a right null vector of the HAMMING matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double HAMMING_NULL_RIGHT[N], a null vector
//
{
  int j;
  double *x;
 
  if ( n != ( i4_power ( 2, m ) - 1 ) )
  {
    cerr << "\n";
    cerr << "HAMMING_NULL_RIGHT - Fatal error!\n";
    cerr << "  M = " << m << "\n";
    cerr << "  N = " << n << "\n";
    cerr << "  but N = 2^M-1 is required.\n";
    exit ( 1 );
  }

  if ( m < 2 )
  {
    cerr << "\n";
    cerr << "HAMMING_NULL_RIGHT - Fatal error!\n";
    cerr << "  M must be at least 2.\n";
    exit ( 1 );
  }

  x = new double[n];

  x[0] =  1.0;
  for ( j = 1; j < n - m; j++ )
  {
    x[j] = 0.0;
  }
  for ( j = n - m; j < n; j++ )
  {
    x[j] = -1.0;
  }

  return x;
}
//****************************************************************************80

double *hankel ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL returns the HANKEL matrix.
//
//  Formula:
//
//    A(I,J) = X(I+J-1)
//
//  Example:
//
//    N = 5, X = ( 1, 2, 3, 4, 5, 6, 7, 8, 9 )
//
//    1  2  3  4  5
//    2  3  4  5  6
//    3  4  5  6  7
//    4  5  6  7  8
//    5  6  7  8  9
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[2*N-1], the vector that defines A.
//
//    Output, double HANKEL[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = x[j+i];
    }
  }
  return a;
}
//****************************************************************************80

double *hankel_n ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL_N returns the HANKEL_N matrix.
//
//  Formula:
//
//    A(I,J) = I+J-1 for I+J-1 <= N
//           = 0     otherwise 
//
//  Example:
//
//    N = 5
//
//    1  2  3  4  5
//    2  3  4  5  0
//    3  4  5  0  0
//    4  5  0  0  0
//    5  0  0  0  0
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//    determinant ( A ) = (-1)^(N/2) * N^N
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HANKEL_N[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n - j; i++ )
    {
      a[i+j*n] = ( double ) ( i + j + 1 );
    }
    for ( i = n - j; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  return a;
}
//****************************************************************************80

double hankel_n_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL_N_CONDITION returns the L1 condition of the HANKEL_N matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double VALUE, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  int i;
  int j;
  double *v;
  double value;

  v = new double[n];
 
  v[0] = 1.0 / ( double ) ( n );
  for ( i = 1; i < n; i++ )
  {
    v[i] = 0.0;
    for ( j = 0; j < i; j++ )
    {
      v[i] = v[i] - ( double ) ( n + j - i ) * v[j];
    }
    v[i] = v[i] / ( double ) ( n ); 
  }

  a_norm = ( double ) ( ( n * ( n + 1 ) ) / 2 );
  b_norm = 0.0;
  for ( i = 0; i < n; i++ )
  {
    b_norm = b_norm + fabs ( v[i] );
  }
  value = a_norm * b_norm;

  delete [] v;

  return value;
}
//****************************************************************************80

double hankel_n_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL_N_DETERMINANT returns the determinant of the HANKEL_N matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double DETERM, the determinant.
//
{
  double determ;

  determ = r8_mop ( n / 2 ) * ( double ) ( i4_power ( n, n ) );

  return determ;
}
//****************************************************************************80

double *hankel_n_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL_N_INVERSE returns the inverse of the HANKEL_N matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HANKEL_N_INVERSE[N*N], the matrix.
//
{
  double *b;
  int i;
  int j;
  double *v;

  v = new double[n];

  v[0] = 1.0 / ( double ) ( n );
  for ( i = 1; i < n; i++ )
  {
    v[i] = 0.0;
    for ( j = 0; j < i; j++ )
    {
      v[i] = v[i] - ( double ) ( n + j - i ) * v[j];
    }
    v[i] = v[i] / ( double ) ( n ); 
  }

  b = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n - 1 - j; i++ )
    {
      b[i+j*n] = 0.0;
    }
    for ( i = n - 1 - j; i < n; i++ )
    {
      b[i+j*n] = v[i+j-n+1];
    }
  }
//
//  Free memory.
//
  delete [] v;

  return b;
}
//****************************************************************************80

double *hanowa ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    HANOWA returns the HANOWA matrix.
//
//  Formula:
//
//    If ( I = J )
//      A(I,J) = ALPHA
//    else if ( I <= N/2 and J = I + N/2 )
//      A(I,J) = -I
//    else if ( N/2 < I and J = I - N/2 )
//      A(I,J) = I-N/2
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 17, N = 6
//
//    17  0  0 -1  0  0
//     0 17  0  0 -2  0
//     0  0 17  0  0 -3
//     1  0  0 17  0  0
//     0  2  0  0 17  0
//     0  0  3  0  0 17
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is nonsingular.
//
//    A is antisymmetric: A' = -A.
//
//    Because A is antisymmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A has complex eigenvalues
//
//      LAMBDA(2*I-1) = ALPHA + I * sqrt ( -1 )
//      LAMBDA(2*I)   = ALPHA - I * sqrt ( -1 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    E Hairer, SP Norsett, G Wanner,
//    Solving Ordinary Differential Equations I: Nonstiff Problems,
//    Springer Verlag, 1987, pages 86-87.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining the Hanowa matrix.  A
//    typical value is -1.0.
//
//    Input, int N, the order of the matrix.  N must be even.
//
//    Output, double HANOWA[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "HANOWA - Fatal error!\n";
    cerr << "  Input N = " << n << "\n";
    cerr << "  but N must be a multiple of 2.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = alpha;
      }
      else if ( i + 1 <= n/2 && j == i + n / 2 )
      {
        a[i+j*n] = - ( double ) ( i + 1 );
      }
      else if ( n / 2 < i + 1 && j == i - n / 2 )
      {
        a[i+j*n] = ( double ) ( i + 1 - n / 2 );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double hanowa_determinant ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    HANOWA_DETERMINANT returns the determinant of the HANOWA matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining the Hanowa matrix.  A
//    typical value is -1.0.
//
//    Input, int N, the order of the matrix.  N must be even.
//
//    Output, double HANOWA_DETERMINANT, the determinant.
//
{
  double determ;
  int i;

  if ( ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "HANOWA_DETERMINANT - Fatal error!\n";
    cerr << "  Input N = " << n << "\n";
    cerr << "  but N must be a multiple of 2.\n";
    exit ( 1 );
  }

  determ = 1.0;

  for ( i = 1; i <= n / 2; i++ )
  {
    determ = determ * ( alpha * alpha + ( double ) ( i * i ) );
  }

  return determ;
}
//****************************************************************************80

complex <double> *hanowa_eigenvalues ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    HANOWA_EIGENVALUES returns the eigenvalues of the HANOWA matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining the Hanowa matrix.  A
//    typical value is -1.0.
//
//    Input, int N, the order of the matrix.  N must be even.
//
//    Output, complex <double> HANOWA_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  complex <double> *lambda;

  if ( ( n % 2 ) != 0 )
  {
    cerr << "\n";
    cerr << "HANOWA_EIGENVALUES - Fatal error!\n";
    cerr << "  Input N = " << n << "\n";
    cerr << "  but N must be a multiple of 2.\n";
    exit ( 1 );
  }
  lambda = new complex <double>[n];

  for ( i = 1; i <= n / 2; i++ )
  {
    lambda[2*i-2] = complex <double> ( alpha,   i );
    lambda[2*i-1] = complex <double> ( alpha, - i );
  }
  return lambda;
}
//****************************************************************************80

double *hanowa_inverse ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    HANOWA_INVERSE returns the inverse of the Hanowa matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining the Hanowa matrix.  A
//    typical value is -1.0.
//
//    Input, int N, the order of A.  N must be even.
//
//    Output, double HANOWA_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  double i_r8;
  int j;
  int n2;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  n2 = n / 2;

  for ( i = 0; i < n2; i++ )
  {
    i_r8 = ( double ) ( i + 1 );

    a[i   +i*n]      =   alpha / ( alpha * alpha + i_r8 * i_r8 );
    a[i+n2+i*n]      = - i_r8  / ( alpha * alpha + i_r8 * i_r8 );

    a[i+n2+(i+n2)*n] =   alpha / ( alpha * alpha + i_r8 * i_r8 );
    a[i   +(i+n2)*n] = + i_r8  / ( alpha * alpha + i_r8 * i_r8 );
  }
  return a;
}
//****************************************************************************80

double *harman ( )

//****************************************************************************80
//
//  Purpose:
//
//    HARMAN returns the HARMAN matrix.
//
//  Formula:
//
//   1.00  0.85  0.81  0.86  0.47  0.40  0.30  0.38
//   0.85  1.00  0.88  0.83  0.38  0.33  0.28  0.41
//   0.81  0.88  1.00  0.80  0.38  0.32  0.24  0.34
//   0.86  0.83  0.80  1.00  0.44  0.33  0.33  0.36
//   0.47  0.38  0.38  0.44  1.00  0.76  0.73  0.63
//   0.40  0.33  0.32  0.33  0.76  1.00  0.58  0.58
//   0.30  0.28  0.24  0.33  0.73  0.58  1.00  0.54
//   0.38  0.41  0.34  0.36  0.63  0.58  0.54  1.00
//
//  Properties:
//
//    A is symmetric.
//
//    A is a correlation matrix for 8 physical variables measured
//    for 305 girls.
//
//    The rows and columns of the matrix correspond to the variables
//    1) height
//    2) arm span
//    3) length of forearm
//    4) length of lower leg
//    5) weight
//    6) bitrochanteric diameter
//    7) chest girth
//    8) chest width
//
//    The largest two eigenvalues are 
//
//      LAMBDA(1) = 4.67 
//
//    with eigenvector
//
//      V(1) = 0.40, 0.39, 0.38, 0.39, 0.35, 0.31, 0.29, 0.31
//
//    and 
//
//      LAMBDA(2)= 1.77
//
//    with eigevector
//
//      V(2) = 0.28 0.33 0.34 0.30 -0.39, -0.40 -0.44 -0.31
//
//    The best rank 2 approximation to the matrix, in the least squares
//    sense, is
//
//      [ V(1) V(2) ] * Diag ( LAMBDA(1), LAMBDA(2) ) * [ V(1) V(2) ]'
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 June 2002
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    HH Harman,
//    Modern Factor Analysis,
//    The University of Chicago Press, 1960.
//
//    Lawrence Huber, Jacqueline Meulman, Willem Heiser,
//    Two Purposes for Matrix Factorization: A Historical Appraisal,
//    SIAM Review,
//    Volume 41, Number 1, pages 68-82.
//
//  Parameters:
//
//    Output, double HARMAN[8*8], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[8*8] = {
    1.00, 0.85, 0.81, 0.86, 0.47, 0.40, 0.30, 0.38, 
    0.85, 1.00, 0.88, 0.83, 0.38, 0.33, 0.28, 0.41, 
    0.81, 0.88, 1.00, 0.80, 0.38, 0.32, 0.24, 0.34, 
    0.86, 0.83, 0.80, 1.00, 0.44, 0.33, 0.33, 0.36, 
    0.47, 0.38, 0.38, 0.44, 1.00, 0.76, 0.73, 0.63, 
    0.40, 0.33, 0.32, 0.33, 0.76, 1.00, 0.58, 0.58, 
    0.30, 0.28, 0.24, 0.33, 0.73, 0.58, 1.00, 0.54, 
    0.38, 0.41, 0.34, 0.36, 0.63, 0.58, 0.54, 1.00 };

  a = r8mat_copy_new ( 8, 8, a_save );

  return a;
}
//****************************************************************************80

double harman_condition ( )

//****************************************************************************80
//
//  Purpose:
//
//    HARMAN_CONDITION returns the L1 condition of the HARMAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double HARMAN_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 5.07;
  b_norm = 15.200976381839961;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double harman_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    HARMAN_DETERMINANT returns the determinant of the HARMAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 October 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HARMAN_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 0.0009547789295599994;

  return determ;
}
//****************************************************************************80

double *harman_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    HARMAN_EIGENVALUES returns the eigenvalues of the HARMAN matrix.
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
//    Output, double HARMAN_EIGENVALUES[8], the eigenvalues.
//
{
  double *lambda;
  static double lambda_save[8] = { 
   0.099201798857265, 
   0.133696389888429, 
   0.186209771388667, 
   0.230071772282960, 
   0.422934636563082, 
   0.479706233283900, 
   1.770649533376934, 
   4.677529864358766 };

  lambda = r8vec_copy_new ( 8, lambda_save );

  return lambda;
}
//****************************************************************************80

double *harman_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    HARMAN_INVERSE returns the inverse of the HARMAN matrix.
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
//    Output, double HARMAN_INVERSE[8*8], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[8*8] = {
   5.505750442924552,  -2.024827472733320, 
  -0.525564377998213,  -2.414725599885703, 
  -0.742871704140835,  -0.432339085897328, 
   0.506363394364808,   0.231316810459756, 
  -2.024827472733320,   6.632253606390529, 
  -3.266421707396942,  -1.157009948040102, 
   0.941928425100928,   0.010152122779319, 
  -0.318255180872113,  -0.850127918526706, 
  -0.525564377998213,  -3.266421707396943, 
   4.945029645612116,  -0.799896971199349, 
  -0.384019974978888,  -0.082141525217929, 
   0.342191583208235,   0.250391407726364, 
  -2.414725599885702,  -1.157009948040101, 
  -0.799896971199349,   4.769523661962869, 
  -0.343306754780455,   0.462478615948815, 
  -0.415704081428472,   0.119432120786903, 
  -0.742871704140835,   0.941928425100928, 
  -0.384019974978887,  -0.343306754780455, 
   3.941357428629264,  -1.549806320843210, 
  -1.467270532044103,  -0.641583610147637, 
  -0.432339085897328,   0.010152122779319, 
  -0.082141525217929,   0.462478615948815, 
  -1.549806320843210,   2.524233450449795, 
  -0.122867685019045,  -0.399766570085388, 
   0.506363394364808,  -0.318255180872113, 
   0.342191583208235,  -0.415704081428472, 
  -1.467270532044103,  -0.122867685019045, 
   2.276170982094793,  -0.262113772509967, 
   0.231316810459756,  -0.850127918526706, 
   0.250391407726364,   0.119432120786903, 
  -0.641583610147637,  -0.399766570085388, 
  -0.262113772509967,   1.910127138708912 };

  a = r8mat_copy_new ( 8, 8, a_save );

  return a;
}
//****************************************************************************80

double *hartley ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HARTLEY returns the HARTLEY matrix.
//
//  Formula:
//
//    A(I,J) = SIN ( 2*PI*(i-1)*(j-1)/N ) + COS( 2*PI*(i-1)*(j-1)/N )
//
//  Example:
//
//    N = 5
//
//    1.0000    1.0000    1.0000    1.0000    1.0000
//    1.0000    1.2601   -0.2212   -1.3968   -0.6420
//    1.0000   -0.2212   -0.6420    1.2601   -1.3968
//    1.0000   -1.3968    1.2601   -0.6420   -0.2212
//    1.0000   -0.6420   -1.3968   -0.2212    1.2601
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A arises in the Hartley transform.
//
//    A * A = N * I, in other words, A is "almost" involutory,
//    and inverse ( A ) = ( 1 / N ) * A.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    D Bini, P Favati,
//    On a matrix algebra related to the discrete Hartley transform,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 14, 1993, pages 500-507.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HARTLEY[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = 2.0 * r8_pi * ( double) ( i * j ) / ( double ) ( n );
      a[i+j*n] = sin ( angle ) + cos ( angle );
    }
  }
  return a;
}
//****************************************************************************80

double hartley_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HARTLEY_CONDITION returns the L1 condition of the HARTLEY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HARTLEY_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = ( double ) ( n );
  b_norm = 1.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double hartley_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HARTLEY_DETERMINANT returns the determinant of the HARTLEY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HARTLEY_DETERMINANT, the determinant.
//
{
  double determ;

  determ = sqrt ( ( double ) i4_power ( n, n ) );

  if ( n % 4 != 1 )
  {
    determ = - determ;
  }

  return determ;
}
//****************************************************************************80

double *hartley_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HARTLEY_INVERSE returns the inverse of the HARTLEY matrix.
//
//  Formula:
//
//    A(I,J) = (1/N) * SIN ( 2*PI*(i-1)*(j-1)/N ) + COS( 2*PI*(i-1)*(j-1)/N )
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    D Bini, P Favati,
//    On a matrix algebra related to the discrete Hartley transform,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 14, 1993, pages 500-507.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HARTLEY_INVERSE[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = 2.0 * r8_pi * ( double ) ( i * j ) / ( double ) ( n );
      a[i+j*n] = ( sin ( angle ) + cos ( angle ) ) / ( double ) ( n );
    }
  }
  return a;
}
//****************************************************************************80

double *helmert ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HELMERT returns the HELMERT matrix.
//
//  Formula:
//
//    If I = 1 then
//      A(I,J) = 1 / sqrt ( N )
//    else if J < I then
//      A(I,J) = 1 / sqrt ( I * ( I - 1 ) )
//    else if J = I then
//      A(I,J) = (1-I) / sqrt ( I * ( I - 1 ) )
//    else
//      A(I,J) = 0
//
//  Discussion:
//
//    The matrix given above by Helmert is the classic example of
//    a family of matrices which are now called Helmertian or
//    Helmert matrices.
//
//    A matrix is a (standard) Helmert matrix if it is orthogonal,
//    and the elements which are above the diagonal and below the
//    first row are zero.
//
//    If the elements of the first row are all strictly positive,
//    then the matrix is a strictly Helmertian matrix.
//
//    It is possible to require in addition that all elements below
//    the diagonal be strictly positive, but in the reference, this
//    condition is discarded as being cumbersome and not useful.
//
//    A Helmert matrix can be regarded as a change of basis matrix
//    between a pair of orthonormal coordinate bases.  The first row
//    gives the coordinates of the first new basis vector in the old
//    basis.  Each later row describes combinations of (an increasingly
//    extensive set of) old basis vectors that constitute the new
//    basis vectors.
//
//    Helmert matrices have important applications in statistics.
//
//  Example:
//
//    N = 5
//
//    0.4472    0.4472    0.4472    0.4472    0.4472
//    0.7071   -0.7071         0         0         0
//    0.4082    0.4082   -0.8165         0         0
//    0.2887    0.2887    0.2887   -0.8660         0
//    0.2236    0.2236    0.2236    0.2236   -0.8944
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is orthogonal: A' * A = A * A' = I.
//
//    Because A is orthogonal, it is normal: A' * A = A * A'.
//
//    A is not symmetric: A' /= A.
//
//    det ( A ) = (-1)^(N+1)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    HO Lancaster,
//    The Helmert Matrices,
//    American Mathematical Monthly,
//    Volume 72, 1965, pages 4-12.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HELMERT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];
//
//  A begins with the first row, diagonal, and lower triangle set to 1.
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 )
      {
        a[i+j*n] = 1.0 / sqrt ( ( double ) ( n ) );
      }
      else if ( j < i )
      {
        a[i+j*n] = 1.0 / sqrt ( ( double ) ( i * ( i + 1 ) ) );
      }
      else if ( i == j )
      {
        a[i+j*n] = - sqrt ( ( double ) ( i     ) )
                   / sqrt ( ( double ) ( i + 1 ) );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double helmert_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HELMERT_DETERMINANT returns the determinant of the HELMERT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HELMERT_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( n % 2 ) == 0 )
  {
    determ = -1.0;
  }
  else
  {
    determ = +1.0;
  }

  return determ;
}
//****************************************************************************80

double *helmert_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HELMERT_INVERSE returns the inverse of the HELMERT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HELMERT_INVERSE[N*N], the inverse matrix.
//
{
  double *a;

  a = helmert ( n );

  r8mat_transpose_in_place ( n, a );

  return a;
}
//****************************************************************************80

double *helmert2 ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    HELMERT2 returns the HELMERT2 matrix.
//
//  Formula:
//
//    Row 1 = the vector, divided by its L2 norm.
//
//    Row 2 is computed by the requirements that it be orthogonal to row 1,
//    be nonzero only from columns 1 to 2, and have a negative diagonal.
//
//    Row 3 is computed by the requirements that it be orthogonal to
//    rows 1 and 2, be nonzero only from columns 1 to 3, and have a
//    negative diagonal, and so on.
//
//  Properties:
//
//    The first row of A should be the vector X, divided by its L2 norm.
//
//    A is orthogonal: A' * A = A * A' = I.
//
//    A is not symmetric: A' /= A.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    HO Lancaster,
//    The Helmert Matrices,
//    American Mathematical Monthly,
//    Volume 72, 1965, pages 4-12.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the vector that defines the first row.
//    X must not have 0 L2 norm, and its first entry must not be 0.
//
//    Output, double HELMERT2[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double s;
  double *w;
  double x_norm_l2;

  a = new double[n*n];
  w = new double[n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }
  x_norm_l2 = r8vec_norm_l2 ( n, x );

  if ( x_norm_l2 == 0.0 )
  {
    cerr << "\n";
    cerr << "HELMERT2 - Fatal error!\n";
    cerr << "  Input vector has zero L2 norm.\n";
    exit ( 1 );
  }

  if ( x[0] == 0.0 )
  {
    cerr << "\n";
    cerr << "HELMERT2 - Fatal error!\n";
    cerr << "  Input vector has X[0] = 0.\n";
    exit ( 1 );
  }

  for ( i = 0; i < n; i++ )
  {
    w[i] = pow ( x[i] / x_norm_l2, 2 );
  }

  for ( j = 0; j < n; j++ )
  {
    a[0+j*n] = sqrt ( w[j] );
  }

  for ( i = 1; i < n; i++ )
  {
    s = 0.0;
    for ( j = 0; j < i; j++ )
    {
      s = s + w[j];
    }
    for ( j = 0; j < i; j++ )
    {
      a[i+j*n] = sqrt ( w[i] * w[j] / ( s + w[i] ) / s );
    }
    a[i+i*n] = - sqrt ( s / ( s + w[i] ) );
  }
//
//  Free memory.
//
  delete [] w;

  return a;
}
//****************************************************************************80

double *helmert2_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    HELMERT2_INVERSE returns the inverse of the HELMERT2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the vector that defines the first row.
//
//    Output, double *HELMERT2_INVERSE[N*N], the inverse matrix.
//
{
  double *a;

  a = helmert2 ( n, x );

  r8mat_transpose_in_place ( n, a );

  return a;
}
//****************************************************************************80

double *hermite ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HERMITE returns the HERMITE matrix.
//
//  Example:
//
//    N = 11
//
//        1     .      .      .       .     .      .     .      .   .    .
//        .     2      .      .       .     .      .     .      .   .    .
//       -2     .      4      .       .     .      .     .      .   .    .
//        .   -12      .      8       .     .      .     .      .   .    .
//       12     .    -48      .      16     .      .     .      .   .    .
//        .   120      .   -160       .    32      .     .      .   .    .
//     -120     .    720      .    -480     .     64     .      .   .    .
//        . -1680      .   3360       . -1344      .   128      .   .    .
//     1680     . -13440      .   13440     .  -3584     .    256   .    .
//        . 30240      . -80640       . 48384      . -9216      . 512    .
//   -30240     . 302400      . -403200     . 161280     . -23040   . 1024
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is lower triangular.
//
//    det ( A ) = 2^((N*(N-1))/2)
//
//    LAMBDA(I) = 2^(I-1).
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is reducible.
//
//    Successive diagonals are zero, positive, zero, negative.
//
//    A is generally not normal: A' * A /= A * A'.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HERMITE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+1*n] = 2.0;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( j == 0 )
      {
        a[i+j*n] =                      - 2.0 
          * ( double ) ( i - 1 ) * a[i-2+j*n];
      }
      else
      {
        a[i+j*n] = 2.0 * a[i-1+(j-1)*n] - 2.0 
          * ( double ) ( i - 1 ) * a[i-2+j*n];
      }
    }
  }

  return a;
}
//****************************************************************************80

double hermite_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HERMITE_DETERMINANT returns the determinant of the HERMITE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HERMITE_DETERMINANT, the determinant.
//
{
  double determ;
  int power;

  power = ( n * ( n - 1 ) ) / 2;
  determ = ( double ) ( i4_power ( 2, power ) );

  return determ;
}
//****************************************************************************80

double *hermite_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HERMITE_INVERSE returns the inverse of the HERMITE matrix.
//
//  Example:
//
//    N = 11
//
//        1     .     .     .     .    .    .  .  . . .
//        .     1     .     .     .    .    .  .  . . .  /    2
//        2     .     1     .     .    .    .  .  . . .  /    4
//        .     6     .     1     .    .    .  .  . . .  /    8
//       12     .    12     .     1    .    .  .  . . .  /   16
//        .    60     .    20     .    1    .  .  . . .  /   32
//      120     .   180     .    30    .    1  .  . . .  /   64
//        .   840     .   420     .   42    .  1  . . .  /  128
//     1680     .  3360     .   840    .   56  .  1 . .  /  256
//        . 15120     . 10080     . 1512    . 72  . 1 .  /  512
//    30240     . 75600     . 25200    . 2520  . 90 . 1  / 1024
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is nonnegative.
//
//    A is lower triangular.
//
//    det ( A ) = 1 / 2^((N*(N-1))/2)
//
//    LAMBDA(I) = 1 / 2^(I-1)
//
//    A is reducible.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HERMITE_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+1*n] = 0.5;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( j == 0 )
      {
        a[i+j*n] = ( ( double ) ( i - 1 ) * a[i-2+j*n]                  ) / 2.0;
      }
      else
      {
        a[i+j*n] = ( ( double ) ( i - 1 ) * a[i-2+j*n] + a[i-1+(j-1)*n] ) / 2.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *hermite_roots ( int order )

//****************************************************************************80
//
//  Purpose:
//
//    HERMITE_ROOTS computes the roots of a Hermite polynomial.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Arthur Stroud, Don Secrest,
//    Gaussian Quadrature Formulas,
//    Prentice Hall, 1966,
//    LC: QA299.4G3S7.
//
//  Parameters:
//
//    Input, int ORDER, the order of the polynomial.
//
//    Output, double HERMITE_ROOTS[ORDER], the roots.
//
{
  double dx;
  double dp0;
  double dp1;
  double dp2;
  double eps;
  int i;
  int j;
  double p0;
  double p1;
  double p2;
  double s;
  int step;
  int step_max = 10;
  double x;
  double *xtab;

  xtab = new double[order];

  eps = r8_epsilon ( );

  s = pow ( 2 * order + 1, 1.0 / 6.0 );

  for ( i = 0; i < ( order + 1 ) / 2; i++ )
  {
    if ( i == 0 )
    {
      x = s * s * s - 1.85575 / s;
    }
    else if ( i == 1 )
    {
      x = x - 1.14 * pow ( order, 0.426 ) / x;
    }
    else if ( i == 2 )
    {
      x = 1.86 * x - 0.86 * xtab[order-1];
    }
    else if ( i == 3 )
    {
      x = 1.91 * x - 0.91 * xtab[order-2];
    }
    else
    {
      x = 2.0 * x - xtab[order+1-i];
    }

    for ( step = 1; step <= step_max; step++ )
    {
      p1 = 1.0;
      dp1 = 0.0;

      p2 = x;
      dp2 = 1.0;

      for ( j = 2; j <= order; j++ )
      {
        p0 = p1;
        dp0 = dp1;

        p1 = p2;
        dp1 = dp2;

        p2  = x * p1 - 0.5 * ( double ) ( j - 1 ) * p0;
        dp2 = x * dp1 + p1 - 0.5 * ( double ) ( j - 1 ) * dp0;
      }
      dx = p2 / dp2;
      x = x - dx;

      if ( fabs ( dx ) <= eps * ( fabs ( x ) + 1.0 ) )
      {
        break;
      }
    }
    xtab[      i  ] = - x;
    xtab[order-i-1] = + x;
  }
  return xtab;
}
//****************************************************************************80

double *herndon ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HERNDON returns the HERNDON matrix.
//
//  Formula:
//
//    c = ( n * ( n + 1 ) * ( 2 * n - 5 ) ) / 6
//    a(n,n) = - 1 / c
//    do i = 1, n - 1
//      a(i,n) = a(n,i) = i / c
//      a(i,i) = ( c - i*i ) / c
//      do j = 1, i - 1
//        a(i,j) = a(j,i) = - i * j / c
//       }
//     }
//
//  Example:
//
//    N = 5
//
//     0.96  -0.08  -0.12  -0.16   0.04
//    -0.08   0.84  -0.24  -0.32   0.08
//    -0.12  -0.24   0.64  -0.48   0.12
//    -0.16  -0.32  -0.48   0.36   0.16
//     0.04   0.08   0.12   0.16  -0.04
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal: A' * A = A * A'.
//
//    The eigenvalues of A are:
//
//      1 (multiplicity N-2),
//      6 / ( P * ( N + 1 ),
//      P / ( N * ( 5 - 2 * N ) ),
//
//    where
//
//      P = 3 + sqrt ( ( 4 * N - 3 ) * ( N - 1 ) * 3 / ( N + 1 ) ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Herndon,
//    Algorithm 52, A Set of Test Matrices,
//    Communications of the ACM,
//    April, 1961.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HERNDON[N*N], the matrix.
//
{
  double *a;
  double c;
  int i;
  int j;

  a = new double[n*n];

  c = ( double ) ( n * ( n + 1 ) * ( 2 * n - 5 ) ) / 6.0;

  a[n-1+(n-1)*n] = - 1.0 / c;

  for ( i = 0; i < n - 1; i++ )
  {
    a[i  +(n-1)*n] = ( double ) ( i + 1 ) / c;
    a[n-1+ i   *n] = ( double ) ( i + 1 ) / c;
    a[i  + i   *n] = ( c - ( double ) ( ( i + 1 ) * ( i + 1 ) ) ) / c;

    for ( j = 0; j < i; j++ )
    {
      a[i+j*n] = - ( double ) ( ( i + 1 ) * ( j + 1 ) ) / c;
      a[j+i*n] = - ( double ) ( ( i + 1 ) * ( j + 1 ) ) / c;
    }
  }

  return a;
}
//****************************************************************************80

double herndon_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HERNDON_DETERMINANT returns the determinant of the HERNDON matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HERNDON_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 6.0 / ( double ) ( ( n + 1 ) * n * ( 5 - 2 * n ) );

  return determ;
}
//****************************************************************************80

double *herndon_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HERNDON_EIGENVALUES returns the eigenvalues of the HERNDON matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HERNDON_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;
  double p;

  lambda = new double[n];

  p = 3.0 + sqrt ( 
      ( double ) ( ( 4 * n - 3 ) * ( n - 1 ) * 3 ) 
    / ( double ) ( n + 1 ) );

  for ( i = 0; i < n - 2; i++ )
  {
    lambda[i] = 1.0;
  }
  lambda[n-2] = 6.0 / ( p * ( double ) ( n + 1 ) );
  lambda[n-1] = p / ( double ) ( n * ( 5 - 2 * n ) );

  return lambda;
}
//****************************************************************************80

double *herndon_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HERNDON_INVERSE returns the inverse of the HERNDON matrix.
//
//  Formula:
//
//    if ( I == N )
//      A(I,J) = J
//    else if ( J == N )
//      A(I,J) = I
//    else if ( I == J )
//      A(I,J) = 1
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//    1  0  0  0  1
//    0  1  0  0  2
//    0  0  1  0  3
//    0  0  0  1  4
//    1  2  3  4  5
//
//  Properties:
//
//    A is symmetric.
//
//    A is border-banded.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Herndon,
//    Algorithm 52, A Set of Test Matrices,
//    Communications of the ACM,
//    April, 1961.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HERNDON_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == n - 1 )
      {
        a[i+j*n] = ( double ) ( i + 1 );
      }
      else if ( i == n - 1 )
      {
        a[i+j*n] = ( double ) ( j + 1 );
      }
      else if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
/******************************************************************************/

complex <double> *hess4 ( )

/******************************************************************************/
/*
  Purpose:

    HESS4 returns the HESS4 matrix.

  Discussion:

    HESS4 is simply an example of a 4x4 complex upper Hessenberg matrix.

  Example:

    4+8i  7+6i  7+10i 7+10i
    9+9i  8+1i  8+10i 2 +5i
    0     8+3i  7+ 2i 7 +8i
    0     0     4+10i 0 +1i

  Properties:

    A is integral.

    A is not symmetric.

    A is complex.

    A is upper Hessenberg.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 March 2018

  Author:

    John Burkardt

  Parameters:

    Output, complex <double> HESS4[4*4], the matrix.
*/
{
  complex <double> *a;
  static complex <double> a_save[4*4] = {
    complex <double> ( 4, 8 ), 
    complex <double> ( 9, 9 ), 
    complex <double> ( 0, 0 ), 
    complex <double> ( 0, 0 ), 
    complex <double> ( 7, 6 ), 
    complex <double> ( 8, 1 ), 
    complex <double> ( 8, 3 ), 
    complex <double> ( 0, 0 ), 
    complex <double> ( 7,10 ), 
    complex <double> ( 8,10 ), 
    complex <double> ( 7, 2 ), 
    complex <double> ( 4,10 ), 
    complex <double> ( 7,10 ), 
    complex <double> ( 2, 5 ), 
    complex <double> ( 7, 8 ), 
    complex <double> ( 0, 1 ) };

  a = c8mat_copy_new ( 4, 4, a_save );

  return a;
}
/******************************************************************************/

complex <double> hess4_determinant ( )

/******************************************************************************/
/*
  Purpose:

    HESS4_DETERMINANT returns the determinant of the HESS4 matrix.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 March 2018

  Author:

    John Burkardt

  Parameters:

    Output, complex <double> HESS4_DETERMINANT-, the determinant.
*/
{
  complex <double> value;

  value = complex <double> ( 6.393999999999999E+03, -4.548000000000000E+03 );

  return value;
}
/******************************************************************************/

complex <double> *hess4_eigen_right ( )

/******************************************************************************/
/*
  Purpose:

    HESS4_EIGEN_RIGHT returns the right eigenvectors of the HESS4 matrix.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 March 2018

  Author:

    John Burkardt

  Parameters:

    Output, complex <double> HESS4_EIGEN_RIGHT[4*4], the right eigenvector matrix.
*/
{
  complex <double> *a;
  static complex <double> a_save[4*4] = {
    complex <double> ( -0.330070042547862, - 0.222298022567869 ), 
    complex <double> (  1.000000000000000, + 0.000000000000000 ), 
    complex <double> (  0.257417722386482, + 0.309094498615456 ), 
    complex <double> ( -0.842630039297297, + 0.197751498603984 ), 
    complex <double> (  1.000000000000000, + 0.000000000000000 ), 
    complex <double> (  0.503205870426247, - 0.824241552742355 ), 
    complex <double> ( -0.215016769732540, + 0.275479867860766 ), 
    complex <double> ( -0.238196952722339, + 0.597205448629795 ), 
    complex <double> (  0.335490948571943, - 0.068002965084462 ), 
    complex <double> ( -0.768179408120474, + 0.010513990305666 ), 
    complex <double> (  1.000000000000000, + 0.000000000000000 ), 
    complex <double> ( -0.972653465585451, - 0.104040336437224 ), 
    complex <double> (  0.952157320531579, + 0.250709960744793 ), 
    complex <double> (  1.000000000000000, + 0.000000000000000 ), 
    complex <double> (  0.501508766439785, - 0.172182272014276 ), 
    complex <double> (  0.218561824850003, + 0.044757232962382 ) };

  a = c8mat_copy_new ( 4, 4, a_save );

  return a;
}
/******************************************************************************/

complex <double> *hess4_eigenvalues ( )

/******************************************************************************/
/*
  Purpose:

    HESS4_EIGENVALUES returns the eigenvalues of the HESS4 matrix.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 March 2018

  Author:

    John Burkardt

  Parameters:

    Output, complex <double> HESS4_EIGENVALUES[4], the eigenvalues.
*/
{
  complex <double> *lambda;
  static complex <double> lambda_save[4] = {
    complex <double> (  3.324431041502838,  - 2.742026572531628 ), 
    complex <double> (  0.568541187348097,  + 6.826204344246118 ), 
    complex <double> ( -5.153228803481162,  - 8.729936381660266 ), 
    complex <double> ( 20.260256574630240, + 16.645758609945791 ) };

  lambda = c8vec_copy_new ( 4, lambda_save );

  return lambda;
}
/******************************************************************************/

complex <double> *hess4_inverse ( )

/******************************************************************************/
/*
  Purpose:

    HESS4_INVERSE returns the inverse of the HESS4 matrix.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    12 March 2018

  Author:

    John Burkardt

  Parameters:

    Output, complex <double> HESS4_INVERSE[4*4], the matrix.
*/
{
  complex <double> *b;
  static complex <double> b_save[4*4] = {
    complex <double> (  0.055479592005787, - 0.046555961144460 ), 
    complex <double> (  0.098221887702513, + 0.072992359285429 ), 
    complex <double> (  0.003980766488315, + 0.005177436032039 ), 
    complex <double> ( -0.048947708484049, + 0.045728154803651 ), 
    complex <double> (  0.008223391741817, - 0.036847046349424 ), 
    complex <double> (  0.151056059735374, + 0.029715821031667 ), 
    complex <double> (  0.146615375569659, - 0.028025222381794 ), 
    complex <double> ( -0.018713432435338, + 0.036423414026287 ), 
    complex <double> ( -0.072930346088215, + 0.062294774161839 ), 
    complex <double> ( -0.013605643493308, - 0.002639735159144 ), 
    complex <double> ( -0.103971410909060, - 0.013897712983173 ), 
    complex <double> (  0.034460691461767, - 0.089345132191411 ), 
    complex <double> ( -0.165446110076836, - 0.054339835569198 ), 
    complex <double> (  0.008483821182396, + 0.004783299771276 ), 
    complex <double> ( -0.060517409011307, - 0.035851294367129 ), 
    complex <double> (  0.012773614147975, + 0.031294087761181 ) };

  b = c8mat_copy_new ( 4, 4, b_save );

  return b;
}
//****************************************************************************80

double *hess5 ( )

//****************************************************************************80
//
//  Purpose:
//
//    HESS5 returns the HESS5 matrix.
//
//  Discussion:
//
//    HESS5 is simply an example of a 4x4 complex upper Hessenberg matrix.
//
//  Example:
//
//     9     4     1     3     2
//     4     3     1     7     1
//     0     3     1     2     4
//     0     0     5     5     1
//     0     0     0     1     2
//
//  Properties:
//
//    A is integral.
//
//    A is not symmetric.
//
//    A is upper Hessenberg.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double HESS5[5*5], the matrix.
//
{
  double *a;
  static double a_save[5*5] = {
     9.0, 4.0, 0.0, 0.0, 0.0, 
     4.0, 3.0, 3.0, 0.0, 0.0, 
     1.0, 1.0, 1.0, 5.0, 0.0, 
     3.0, 7.0, 2.0, 5.0, 1.0, 
     2.0, 1.0, 4.0, 1.0, 2.0 };

  a = r8mat_copy_new ( 5, 5, a_save );

  return a;
}
//****************************************************************************80

double hess5_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    HESS5_DETERMINANT returns the determinant of the HESS5 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double HESS5_DETERMINANT, the determinant.
//
{
  double value;

  value = 1479.0;

  return value;
}
//****************************************************************************80

complex <double> *hess5_eigen_right ( )

//****************************************************************************80
//
//  Purpose:
//
//    HESS5_EIGEN_RIGHT returns the right eigenvectors of the HESS5 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
///    Output, complex <double> HESS5_EIGEN_RIGHT[5*5], the right eigenvector matrix.
//
{
  complex <double> *a;
  static complex <double> a_save[5*5] = {
    complex <double> ( -0.4048,+0.0000 ), 
    complex <double> (  1.0000,+0.0000 ), 
    complex <double> (  0.0565,+0.0000 ), 
    complex <double> (  0.1687,+0.0000 ), 
    complex <double> ( -0.8231,+0.0000 ), 
    complex <double> ( -0.2788,-0.1981 ), 
    complex <double> (  1.0000,+0.0000 ), 
    complex <double> ( -0.0712,-0.9695 ), 
    complex <double> ( -0.3560,+0.6933 ),  
    complex <double> (  0.1938,-0.0411 ), 
    complex <double> ( -0.2788,+0.1981 ),  
    complex <double> (  1.0000,+0.0000 ), 
    complex <double> ( -0.0712,+0.9695 ), 
    complex <double> ( -0.3560,+0.6933 ), 
    complex <double> (  0.1938,+0.0411 ), 
    complex <double> (  1.0000,+0.0000 ), 
    complex <double> (  0.0372,+0.0000 ), 
    complex <double> ( -0.2064,+0.0000 ), 
    complex <double> ( -0.5057,+0.0000 ), 
    complex <double> ( -0.0966,+0.0000 ), 
    complex <double> (  1.0000,+0.0000 ), 
    complex <double> (  0.5780,+0.0000 ), 
    complex <double> (  0.1887,+0.0000 ), 
    complex <double> (  0.1379,+0.0000 ), 
    complex <double> (  0.0139,+0.0000 ) };

  a = c8mat_copy_new ( 5, 5, a_save );

  return a;
}
//****************************************************************************80

complex <double> *hess5_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    HESS5_EIGENVALUES returns the eigenvalues of the HESS5 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, complex <double> HESS5_EIGENVALUES[5], the eigenvalues.
//
{
  complex <double> *lambda;
  static complex <double> lambda_save[5] = {
    complex <double> (  1.795071645585215, + 0.000000000000000 ), 
    complex <double> ( -0.484650565840867, + 3.050399870879445 ), 
    complex <double> ( -0.484650565840867, - 3.050399870879445 ), 
    complex <double> (  7.232089690415871, + 0.000000000000000 ), 
    complex <double> ( 11.942139795680633, + 0.000000000000000 ) };

  lambda = c8vec_copy_new ( 5, lambda_save );

  return lambda;
}
//****************************************************************************80

double *hess5_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    HESS5_INVERSE returns the inverse of the HESS5 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double HESS5_INVERSE[5*5], the matrix.
//
{
  double *b;
  static double b_save[5*5] = {
    0.131845841784990, 
   -0.024340770791075, 
    0.073022312373225, 
   -0.081135902636917, 
    0.040567951318458, 
   -0.046653144016227, 
    0.054766734279919, 
   -0.164300202839757, 
    0.182555780933063, 
   -0.091277890466531, 
   -0.129141311697093, 
    0.311020960108181, 
    0.066937119675456, 
   -0.074374577417174, 
    0.037187288708587, 
    0.008789722785666, 
   -0.068289384719405, 
    0.204868154158215, 
   -0.005409060175794, 
    0.002704530087897, 
    0.145368492224476, 
   -0.590939824205544, 
   -0.227180527383367, 
    0.141311697092630, 
    0.429344151453685 };

  b = r8mat_copy_new ( 5, 5, b_save );

  return b;
}
//****************************************************************************80

double *hilbert ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    HILBERT returns the HILBERT matrix.
//
//  Formula:
//
//    A(I,J) = 1 / ( I + J - 1 )
//
//  Example:
//
//    N = 5
//
//    1/1 1/2 1/3 1/4 1/5
//    1/2 1/3 1/4 1/5 1/6
//    1/3 1/4 1/5 1/6 1/7
//    1/4 1/5 1/6 1/7 1/8
//    1/5 1/6 1/7 1/8 1/9
//
//  Properties:
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//    A is positive definite.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is totally positive.
//
//    A is a Cauchy matrix.
//
//    A is nonsingular.
//
//    A is very ill-conditioned.
//
//    The entries of the inverse of A are all integers.
//
//    The sum of the entries of the inverse of A is N*N.
//
//    The ratio of the absolute values of the maximum and minimum
//    eigenvalues is roughly EXP(3.5*N).
//
//    The determinant of the Hilbert matrix of order 10 is
//    2.16417... * 10^(-53).
//
//    If the (1,1) entry of the 5 by 5 Hilbert matrix is changed
//    from 1 to 24/25, the matrix is exactly singular.  And there
//    is a similar rule for larger Hilbert matrices.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    MD Choi,
//    Tricks or treats with the Hilbert matrix,
//    American Mathematical Monthly,
//    Volume 90, 1983, pages 301-312.
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Nicholas Higham,
//    Accuracy and Stability of Numerical Algorithms,
//    Society for Industrial and Applied Mathematics, Philadelphia, PA,
//    USA, 1996; section 26.1.
//
//    Donald Knuth,
//    The Art of Computer Programming,
//    Volume 1, Fundamental Algorithms, Second Edition
//    Addison-Wesley, Reading, Massachusetts, 1973, page 37.
//
//    Morris Newman, John Todd,
//    Example A13,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, 1958, pages 466-476.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double A[M*N], the matrix.
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
      a[i+j*m] = 1.0 / ( double ) ( i + j + 1 );
    }
  }
  return a;
}
//****************************************************************************80

double hilbert_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HILBERT_DETERMINANT returns the determinant of the HILBERT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HILBERT_DETERMINANT, the determinant.
//
{
  double bottom;
  double determ;
  int i;
  int j;
  double top;

  top = 1.0;
  for ( i = 0; i < n; i++ )
  {
    for ( j = i + 1; j < n; j++ )
    {
      top = top * ( double ) ( ( j - i ) * ( j - i ) );
    }
  }

  bottom = 1.0;
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      bottom = bottom * ( double ) ( i + j + 1 );
    }
  }

  determ = top / bottom;

  return determ;
}
//****************************************************************************80

double *hilbert_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    HILBERT_INVERSE returns the inverse of the HILBERT matrix.
//
//  Formula:
//
//    A(I,J) =  (-1)^(I+J) * (N+I-1)! * (N+J-1)! /
//           [ (I+J-1) * ((I-1)!*(J-1)!)^2 * (N-I)! * (N-J)! ]
//
//  Example:
//
//    N = 5
//
//       25    -300     1050    -1400     630
//     -300    4800   -18900    26880  -12600
//     1050  -18900    79380  -117600   56700
//    -1400   26880  -117600   179200  -88200
//      630  -12600    56700   -88200   44100
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is almost impossible to compute accurately by general routines
//    that compute the inverse.
//
//    A is the exact inverse of the Hilbert matrix; however, if the
//    Hilbert matrix is stored on a finite precision computer, and
//    hence rounded, A is actually a poor approximation
//    to the inverse of that rounded matrix.  Even though Gauss elimination
//    has difficulty with the Hilbert matrix, it can compute an approximate
//    inverse matrix whose residual is lower than that of the
//    "exact" inverse.
//
//    All entries of A are integers.
//
//    The sum of the entries of A is N^2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double HILBERT_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];
//
//  Set the (1,1) entry.
//
  a[0+0*n] = ( double ) ( n * n );
//
//  Define Row 1, Column J by recursion on Row 1 Column J-1
//
  i = 0;
  for ( j = 1; j < n; j++ )
  {
    a[i+j*n] = - a[i+(j-1)*n] 
      * ( double ) ( ( n + j ) * ( i + j ) * ( n - j ) ) 
      / ( double ) ( ( i + j + 1 ) * j * j );
  }
//
//  Define Row I by recursion on row I-1
//
  for ( i = 1; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      a[i+j*n] = - a[i-1+j*n] 
        * ( double ) ( ( n + i ) * ( i + j ) * ( n - i ) ) 
        / ( double ) ( ( i + j + 1 ) * ( i ) * ( i ) );
    }
  }
  return a;
}
//****************************************************************************80

double *hoffman ( double omega )

//****************************************************************************80
//
//  Purpose:
//
//    HOFFMAN computes the HOFFMAN matrix.
//
//  Discussion:
//
//    This matrix comes from a 4x11 linear programming problem.
//
//  Example:
//
//    c  = cos ( THETA )
//    c2 = cos ( 2 THETA )
//    s  = sin ( THETA )
//    s2 = sin ( 2 THETA )
//    t  = tan ( THETA )
//    w  = OMEGA
//
//    1 0 0  0        0  0      0     0      0     0    0
//    0 1 0  c       -wc c2    -2wcc  c2     2wcc  c    wc
//    0 0 1  ts/w     c  tsw/w  c2   -2ss/2  c2   -ts/w c
//    0 0 0  (c-1)/c  w  0      2w    4ss   -2wc2  4ss  w*(1-2c)
//
//  Discussion:
//
//    In 1951, Alan Hoffman presented the first example of a "circle",
//    that is, a linear programming problem which causes the linear
//    programming algorithm to fall into a cycle of operations.
//    Because of the possibility of such occurrences, the linear
//    programming algorithm was refined to avoid such cycles.
//
//    The matrix represents a system of 3 linear equations and 11 variables,
//       A * x = b
//    and one linear constraint
//       c' * x = z
//    with the added condition
//       0 <= x.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    George Dantzig,
//    Linear Programming and Extensions,
//    Princeton University Press, 1963.
//
//    Jon Lee,
//    Hoffman's Circle Untangled,
//    SIAM Review,
//    Volume 39, Number 1, March 1997, pages 98-105.
//
//  Parameters:
//
//    Input, double OMEGA, a value which is required to be
//    greater than ( 1 - cos ( THETA ) ) / ( 1 - 2 cos ( THETA ) )
//    where THETA is 2 * pi / 5.  This limit is roughly 1.809.
//
//    Output, double HOFFMAN[4*11], the matrix.
//
{
  double *a;
  double c;
  double c2;
  int m = 4;
  int n = 11;
  const double r8_pi = 3.141592653589793;
  double s;
  double s2;
  double t;
  double theta;

  theta = 2.0 * r8_pi / 5.0;

  c = cos ( theta );

  if ( omega <= ( 1.0 - c ) / ( 1.0 - 2.0 * c ) )
  {
    cerr << "\n";
    cerr << "HOFFMAN - Fatal error!\n";
    cerr << "  Illegal input value of OMEGA.\n";
    exit ( 1 );
  }

  a = new double[m*n];

  c2 = cos ( 2.0 * theta );
  s = sin ( theta );
  s2 = sin ( 2.0 * theta );
  t = tan ( theta );

  a[0+0*m] = 1.0;
  a[0+1*m] = 0.0;
  a[0+2*m] = 0.0;
  a[0+3*m] = 0.0;
  a[0+4*m] = 0.0;
  a[0+5*m] = 0.0;
  a[0+6*m] = 0.0;
  a[0+7*m] = 0.0;
  a[0+8*m] = 0.0;
  a[0+9*m] = 0.0;
  a[0+10*m] = 0.0;

  a[1+0*m] = 0.0;
  a[1+1*m] = 1.0;
  a[1+2*m] = 0.0;
  a[1+3*m] = c;
  a[1+4*m] = - omega * c;
  a[1+5*m] = c2;
  a[1+6*m] = - 2.0 * omega * c * c;
  a[1+7*m] = c2;
  a[1+8*m] = 2.0 * omega * c * c;
  a[1+9*m] = c;
  a[1+10*m] = omega * c;

  a[2+0*m] = 0.0;
  a[2+1*m] = 0.0;
  a[2+2*m] = 1.0;
  a[2+3*m] = t * s / omega;
  a[2+4*m] = c;
  a[2+5*m] = t * s2 / omega;
  a[2+6*m] = c2;
  a[2+7*m] = - 2.0 * s * s / omega;
  a[2+8*m] = c2;
  a[2+9*m] = - t * s / omega;
  a[2+10*m] = c;

  a[3+0*m] = 0.0;
  a[3+1*m] = 0.0;
  a[3+2*m] = 0.0;
  a[3+3*m] = ( c - 1.0 ) / c;
  a[3+4*m] = omega;
  a[3+5*m] = 0.0;
  a[3+6*m] = 2.0 * omega;
  a[3+7*m] = 4.0 * s * s;
  a[3+8*m] = - 2.0 * omega * c2;
  a[3+9*m] = 4.0 * s * s;
  a[3+10*m] = omega * ( 1.0 - 2.0 * c );

  return a;
}
//****************************************************************************80

double *hoffman_rhs ( )

//****************************************************************************80
//
//  Purpose:
//
//    HOFFMAN_RHS returns the HOFFMAN right hand side.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double HOFFMAN_RHS[3], the right hand side vector.
//
{
  double *b;
  static double b_save[3] = { 1.0, 0.0, 0.0 };

  b = r8vec_copy_new ( 3, b_save );

  return b;
}
//****************************************************************************80

double *hoffman_optimum ( )

//****************************************************************************80
//
//  Purpose:
//
//    HOFFMAN_OPTIMUM returns the HOFFMAN optimum solution.
//
//  Discussion:
//
//    X = (/ 1, 0 /) is both the unique optimum and the only
//    basic feasible solution.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double HOFFMAN_OPTIMUM[2], the optimum solution.
//
{
  double *x;
  static double x_save[2] = { 1.0, 0.0 };

  x = r8vec_copy_new ( 2, x_save );

  return x;
}
//****************************************************************************80

double *householder ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    HOUSEHOLDER constructs a HOUSEHOLDER matrix.
//
//  Discussion:
//
//    A Householder matrix is also called an elementary reflector.
//
//  Formula:
//
//     A = I - ( 2 * X * X' ) / ( X' * X )
//
//  Example:
//
//    N = 5, X = ( 1, 1, 1, 0, -1 )
//
//   1/2 -1/2 -1/2  0  1/2
//  -1/2  1/2 -1/2  0  1/2
//  -1/2 -1/2  1/2  0  1/2
//    0    0    0   1   0
//   1/2  1/2  1/2  0  1/2
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is orthogonal: A' * A = A * A' = I.
//
//    inverse ( A ) = A.
//
//    det ( A ) = -1.
//
//    A is unimodular.
//
//    If Y and Z are nonzero vectors of equal length, and
//      X = ( Y - Z ) / NORM(Y-Z),
//    then
//      A * Y = Z.
//
//    A represents a reflection through the plane which
//    is perpendicular to the vector X.  In particular, A*X = -X.
//
//    LAMBDA(1) = -1;
//    LAMBDA(2:N) = +1.
//
//    If X is the vector used to define H, then X is the eigenvector
//    associated with the eigenvalue -1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gene Golub, Charles Van Loan,
//    Matrix Computations, second edition,
//    Johns Hopkins University Press, Baltimore, Maryland, 1989.
//
//    Pete Stewart,
//    Introduction to Matrix Computations,
//    Academic Press, 1973,
//
//    James Wilkinson,
//    The Algebraic Eigenvalue Problem,
//    Oxford University Press, 1965.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the vector that defines the 
//    Householder matrix.
//
//    Output, double HOUSEHOLDER[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double xdot;

  a = r8mat_identity ( n );

  xdot = r8vec_dot_product ( n, x, x );

  if ( 0.0 < xdot )
  {
    for ( i = 0; i < n; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        a[i+j*n] = a[i+j*n] - 2.0 * x[i] * x[j] / xdot;
      }
    }
  }
  return a;
}
//****************************************************************************80

double householder_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    HOUSEHOLDER_DETERMINANT returns the determinant of a HOUSEHOLDER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the vector that defines the 
//    Householder matrix.
//
//    Output, double HOUSEHOLDER_DETERMINANT, the determinant.
//
{
  double determ;

  determ = -1.0;

  return determ;
}
//****************************************************************************80

double *householder_eigenvalues ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    HOUSEHOLDER_EIGENVALUES returns the eigenvalues of a HOUSEHOLDER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the vector that defines the 
//    Householder matrix.
//
//    Output, double HOUSEHOLDER_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  lambda[0] = -1.0;
  for ( i = 1; i < n; i++ )
  {
    lambda[i] = +1.0;
  }
  return lambda;
}
//****************************************************************************80

double *householder_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    HOUSEHOLDER_INVERSE returns the inverse of a HOUSEHOLDER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N], the vector that defines the 
//    Householder matrix.
//
//    Output, double HOUSEHOLDER_INVERSE[N*N], the eigenvalues.
//
{
  double *a;

  a = householder ( n, x );

  return a;
}
//****************************************************************************80

void i4_factor ( int n, int maxfactor, int &nfactor, int factor[], 
  int exponent[], int &nleft )

//****************************************************************************80
//
//  Purpose:
//
//    I4_FACTOR factors an I4 into prime factors.
//
//  Discussion:
//
//    The factorization may be incomplete.  The remaining unresolved
//    factor is given as NLEFT:
//
//    N = NLEFT * Product ( 1 <= I <= NFACTOR ) FACTOR(I)^EXPONENT(I).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 May 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the integer to be factored.  N may be positive,
//    negative, or 0.
//
//    Input, int MAXFACTOR, the maximum number of prime factors for
//    which storage has been allocated.
//
//    Output, int &NFACTOR, the number of prime factors of N discovered
//    by the routine.
//
//    Output, int FACTOR[MAXFACTOR], the prime factors of N.
//
//    Output, int EXPONENT[MAXFACTOR].  EXPONENT(I) is the power of
//    the FACTOR(I) in the representation of N.
//
//    Output, int &NLEFT, the factor of N that the routine could not
//    divide out.  If NLEFT is 1, then N has been completely factored.
//    Otherwise, NLEFT represents factors of N involving large primes.
//
{
  int i;
  int maxprime;
  int p;

  nfactor = 0;

  for ( i = 0; i < maxfactor; i++ )
  {
    factor[i] = 0;
  }

  for ( i = 0; i < maxfactor; i++ )
  {
    exponent[i] = 0;
  }

  nleft = n;

  if ( n == 0 )
  {
    return;
  }

  if ( abs ( n ) == 1 )
  {
    nfactor = 1;
    factor[0] = 1;
    exponent[0] = 1;
    return;
  }
//
//  Find out how many primes we stored.
//
  maxprime = prime ( -1 );
//
//  Try dividing the remainder by each prime.
//
  for ( i = 1; i <= maxprime; i++ )
  {
    p = prime ( i );

    if ( abs ( nleft ) % p == 0 )
    {
      if ( nfactor < maxfactor )
      {
        nfactor = nfactor + 1;
        factor[nfactor-1] = p;
        exponent[nfactor-1] = 0;

        for ( ; ; )
        {
          exponent[nfactor-1] = exponent[nfactor-1] + 1;
          nleft = nleft / p;

          if ( abs ( nleft ) % p != 0 )
          {
            break;
          }

        }

        if ( abs ( nleft ) == 1 )
        {
          break;
        }
      }
    }
  }
  return;
}
//****************************************************************************80

int i4_huge ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_HUGE returns a "huge" I4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 May 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, int I4_HUGE, a "huge" I4.
//
{
  return 2147483647;
}
//****************************************************************************80

bool i4_is_even ( int i )

//****************************************************************************80
//
//  Purpose:
//
//    I4_IS_EVEN returns TRUE if an I4 is even.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the value to be tested.
//
//    Output, bool I4_IS_EVEN, is TRUE if I is even.
//
{
  bool value;

  value = ( ( i % 2 ) == 0 );

  return value;
}
//****************************************************************************80

bool i4_is_odd ( int i )

//****************************************************************************80
//
//  Purpose:
//
//    I4_IS_ODD returns TRUE if an I4 is odd.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    01 April 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the values to be tested.
//
//    Output, bool I4_IS_ODD, is TRUE if I is odd.
//
{
  bool value;

  value = ( ( i % 2 ) != 0 );

  return value;
}
//****************************************************************************80

bool i4_is_prime ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    I4_IS_PRIME reports whether an I4 is prime.
//
//  Discussion:
//
//    A simple, unoptimized sieve of Erasthosthenes is used to
//    check whether N can be divided by any integer between 2
//    and SQRT(N).
//
//    Note that negative numbers, 0 and 1 are not considered prime.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 March 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the integer to be tested.
//
//    Output, bool I4_IS_PRIME, is TRUE if N is prime, and FALSE
//    otherwise.  
//
{
  int i;
  int nhi;

  if ( n <= 0 )
  {
    return false;
  }

  if ( n == 1 )
  {
    return false;
  }

  if ( n <= 3 )
  {
    return true;
  }

  nhi = ( int ) ( sqrt ( ( double ) ( n ) ) );

  for ( i = 2; i <= nhi; i++ )
  {
    if ( ( n % i ) == 0 )
    {
      return false;
    }
  }

  return true;
}
//****************************************************************************80

int i4_log_10 ( int i )

//****************************************************************************80
//
//  Purpose:
//
//    I4_LOG_10 returns the integer part of the logarithm base 10 of an I4.
//
//  Example:
//
//        I  I4_LOG_10
//    -----  --------
//        0    0
//        1    0
//        2    0
//        9    0
//       10    1
//       11    1
//       99    1
//      100    2
//      101    2
//      999    2
//     1000    3
//     1001    3
//     9999    3
//    10000    4
//
//  Discussion:
//
//    I4_LOG_10 ( I ) + 1 is the number of decimal digits in I.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    04 January 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the number whose logarithm base 10 is desired.
//
//    Output, int I4_LOG_10, the integer part of the logarithm base 10 of
//    the absolute value of X.
//
{
  int i_abs;
  int ten_pow;
  int value;

  if ( i == 0 )
  {
    value = 0;
  }
  else
  {
    value = 0;
    ten_pow = 10;

    i_abs = abs ( i );

    while ( ten_pow <= i_abs )
    {
      value = value + 1;
      ten_pow = ten_pow * 10;
    }

  }

  return value;
}
//****************************************************************************80

int i4_max ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MAX returns the maximum of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 May 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, two integers to be compared.
//
//    Output, int I4_MAX, the larger of I1 and I2.
//
{
  int value;

  if ( i2 < i1 ) 
  {
    value = i1;
  }
  else 
  {
    value = i2;
  }
  return value;
}
//****************************************************************************80

int i4_min ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MIN returns the smaller of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 May 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, two integers to be compared.
//
//    Output, int I4_MIN, the smaller of I1 and I2.
//
{
  int value;

  if ( i1 < i2 ) 
  {
    value = i1;
  }
  else 
  {
    value = i2;
  }
  return value;
}
//****************************************************************************80

int i4_modp ( int i, int j )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MODP returns the nonnegative remainder of I4 division.
//
//  Discussion:
//
//    If 
//      NREM = I4_MODP ( I, J ) 
//      NMULT = ( I - NREM ) / J
//    then
//      I = J * NMULT + NREM
//    where NREM is always nonnegative.
//
//    The MOD function computes a result with the same sign as the
//    quantity being divided.  Thus, suppose you had an angle A,
//    and you wanted to ensure that it was between 0 and 360.
//    Then mod(A,360) would do, if A was positive, but if A
//    was negative, your result would be between -360 and 0.
//
//    On the other hand, I4_MODP(A,360) is between 0 and 360, always.
//
//        I         J     MOD  I4_MODP   I4_MODP Factorization
// 
//      107        50       7       7    107 =  2 *  50 + 7
//      107       -50       7       7    107 = -2 * -50 + 7
//     -107        50      -7      43   -107 = -3 *  50 + 43
//     -107       -50      -7      43   -107 =  3 * -50 + 43
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 May 1999
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the number to be divided.
//
//    Input, int J, the number that divides I.
//
//    Output, int I4_MODP, the nonnegative remainder when I is 
//    divided by J.
//
{
  int value;

  if ( j == 0 )
  {
    cerr << "\n";
    cerr << "I4_MODP - Fatal error!\n";
    cerr << "  I4_MODP ( I, J ) called with J = " << j << "\n";
    exit ( 1 );
  }

  value = i % j;

  if ( value < 0 )
  {
    value = value + abs ( j );
  }

  return value;
}
//****************************************************************************80

int i4_power ( int i, int j )

//****************************************************************************80
//
//  Purpose:
//
//    I4_POWER returns the value of I^J.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    01 April 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, J, the base and the power.  J should be nonnegative.
//
//    Output, int I4_POWER, the value of I^J.
//
{
  int k;
  int value;

  if ( j < 0 )
  {
    if ( i == 1 )
    {
      value = 1;
    }
    else if ( i == 0 )
    {
      cerr << "\n";
      cerr << "I4_POWER - Fatal error!\n";
      cerr << "  I^J requested, with I = 0 and J negative.\n";
      exit ( 1 );
    }
    else
    {
      value = 0;
    }
  }
  else if ( j == 0 )
  {
    if ( i == 0 )
    {
      cerr << "\n";
      cerr << "I4_POWER - Fatal error!\n";
      cerr << "  I^J requested, with I = 0 and J = 0.\n";
      exit ( 1 );
    }
    else
    {
      value = 1;
    }
  }
  else if ( j == 1 )
  {
    value = i;
  }
  else
  {
    value = 1;
    for ( k = 1; k <= j; k++ )
    {
      value = value * i;
    }
  }
  return value;
}
//****************************************************************************80

int i4_rise ( int x, int n )

//****************************************************************************80
//
//  Purpose:
//
//    I4_RISE computes the rising factorial function [X]^N.
//
//  Discussion:
//
//    [X}^N = X * ( X + 1 ) * ( X + 2 ) * ... * ( X + N - 1 ).
//
//    Note that the number of ways of arranging N objects in M ordered
//    boxes is [M}^N.  (Here, the ordering in each box matters).  Thus,
//    2 objects in 2 boxes have the following 6 possible arrangements:
//
//      -/12, 1/2, 12/-, -/21, 2/1, 21/-.
//
//    Moreover, the number of non-decreasing maps from a set of
//    N to a set of M ordered elements is [M]^N / N!.  Thus the set of
//    nondecreasing maps from (1,2,3) to (a,b,c,d) is the 20 elements:
//
//      aaa, abb, acc, add, aab, abc, acd, aac, abd, aad
//      bbb, bcc, bdd, bbc, bcd, bbd, ccc, cdd, ccd, ddd.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 May 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int X, the argument of the rising factorial function.
//
//    Input, int N, the order of the rising factorial function.
//    If N = 0, RISE = 1, if N = 1, RISE = X.  Note that if N is
//    negative, a "falling" factorial will be computed.
//
//    Output, int I4_RISE, the value of the rising factorial function.
//
{
  int i;
  int value;

  value = 1;

  if ( 0 < n )
  {
    for ( i = 1; i <= n; i++ )
    {
      value = value * x;
      x = x + 1;
    }
  }
  else if ( n < 0 )
  {
    for ( i = -1; n <= i; i-- )
    {
      value = value * x;
      x = x - 1;
    }
  }

  return value;
}
//****************************************************************************80

int i4_sign ( int i )

//****************************************************************************80
//
//  Purpose:
//
//    I4_SIGN returns the sign of an I4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 March 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the value whose sign is desired.
//
//    Output, int I4_SIGN, the sign of I.
{
  int value;

  if ( i < 0 ) 
  {
    value = -1;
  }
  else
  {
    value = 1;
  }
  return value;
}
//****************************************************************************80

int i4_uniform_ab ( int a, int b, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    I4_UNIFORM_AB returns a scaled pseudorandom I4 between A and B.
//
//  Discussion:
//
//    The pseudorandom number should be uniformly distributed
//    between A and B.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    02 October 2012
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
//  Input:
//
//    int A, B, the limits of the interval.
//
//    int &SEED, the "seed" value, which should NOT be 0.
//
//  Output:
//
//    int I4_UNIFORM, a number between A and B.
//
//    int &SEED, an updated seed.
//
{
  int c;
  const int i4_huge = 2147483647;
  int k;
  float r;
  int value;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "I4_UNIFORM_AB - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }
//
//  Guarantee A <= B.
//
  if ( b < a )
  {
    c = a;
    a = b;
    b = c;
  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )
  {
    seed = seed + i4_huge;
  }

  r = ( float ) ( seed ) * 4.656612875E-10;
//
//  Scale R to lie between A-0.5 and B+0.5.
//
  r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 
    +         r   * ( ( float ) b + 0.5 );
//
//  Use rounding to convert R to an integer between A and B.
//
  value = round ( r );
//
//  Guarantee A <= VALUE <= B.
//
  if ( value < a )
  {
    value = a;
  }
  if ( b < value )
  {
    value = b;
  }

  return value;
}
//****************************************************************************80

int i4_wrap ( int ival, int ilo, int ihi )

//****************************************************************************80
//
//  Purpose:
//
//    I4_WRAP forces an I4 to lie between given limits by wrapping.
//
//  Example:
//
//    ILO = 4, IHI = 8
//
//    I   Value
//
//    -2     8
//    -1     4
//     0     5
//     1     6
//     2     7
//     3     8
//     4     4
//     5     5
//     6     6
//     7     7
//     8     8
//     9     4
//    10     5
//    11     6
//    12     7
//    13     8
//    14     4
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 August 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int IVAL, an integer value.
//
//    Input, int ILO, IHI, the desired bounds for the integer value.
//
//    Output, int I4_WRAP, a "wrapped" version of IVAL.
//
{
  int jhi;
  int jlo;
  int value;
  int wide;

  jlo = i4_min ( ilo, ihi );
  jhi = i4_max ( ilo, ihi );

  wide = jhi + 1 - jlo;

  if ( wide == 1 )
  {
    value = jlo;
  }
  else
  {
    value = jlo + i4_modp ( ival - jlo, wide );
  }

  return value;
}
//****************************************************************************80

void i4mat_print ( int m, int n, int a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_PRINT prints an I4MAT.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
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
//    Input, int A[M*N], the M by N matrix.
//
//    Input, string TITLE, a title.
//
{
  i4mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
//****************************************************************************80

void i4mat_print_some ( int m, int n, int a[], int ilo, int jlo, int ihi,
  int jhi, string title )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_PRINT_SOME prints some of an I4MAT.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 August 2010
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
//    Input, int A[M*N], the matrix.
//
//    Input, int ILO, JLO, IHI, JHI, designate the first row and
//    column, and the last row and column to be printed.
//
//    Input, string TITLE, a title.
//
{
# define INCX 10

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
//  Print the columns of the matrix, in strips of INCX.
//
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    j2hi = i4_min ( j2hi, n );
    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";
//
//  For each column J in the current range...
//
//  Write the header.
//
    cout << "  Col:";
    for ( j = j2lo; j <= j2hi; j++ )
    {
      cout << "  " << setw(6) << j - 1;
    }
    cout << "\n";
    cout << "  Row\n";
    cout << "\n";
//
//  Determine the range of the rows in this strip.
//
    i2lo = i4_max ( ilo, 1 );
    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )
    {
//
//  Print out (up to INCX) entries in row I, that lie in the current strip.
//
      cout << setw(5) << i - 1 << ":";
      for ( j = j2lo; j <= j2hi; j++ )
      {
        cout << "  " << setw(6) << a[i-1+(j-1)*m];
      }
      cout << "\n";
    }
  }

  return;
# undef INCX
}
//****************************************************************************80

int i4vec_index ( int n, int a[], int aval )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_INDEX returns the location of the first occurrence of a given value.
//
//  Discussion:
//
//    An I4VEC is a vector of integer values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, int A[N], the vector to be searched.
//
//    Input, int AVAL, the value to be indexed.
//
//    Output, int I4VEC_INDEX, the first location in A which has the
//    value AVAL, or -1 if no such index exists.
//
{
  int i;
  int index;

  for ( i = 1; i <= n; i++ )
  {
    if ( a[i-1] == aval )
    {
      index = i;
      return index;
    }
  }

  index = -1;

  return index;
}
//****************************************************************************80

int *i4vec_indicator_new ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_INDICATOR_NEW sets an I4VEC to the indicator vector.
//
//  Discussion:
//
//    An I4VEC is a vector of integer values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 February 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of elements of A.
//
//    Output, int I4VEC_INDICATOR_NEW[N], the initialized array.
//
{
  int *a;
  int i;

  a = new int[n];

  for ( i = 0; i < n; i++ )
  {
    a[i] = i + 1;
  }

  return a;
}
//****************************************************************************80

void i4vec_print ( int n, int a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_PRINT prints an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 November 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, int A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(8) << i
         << ": " << setw(8) << a[i]  << "\n";
  }
  return;
}
//****************************************************************************80

double *idempotent_random ( int n, int rank, int key )

//****************************************************************************80
//
//  Purpose:
//
//    idempotent_random returns the idempotent_random matrix.
//
//  Discussion:
//
//    The idempotent_random matrix is a random idempotent matrix of rank K.
//
//  Properties:
//
//    A is idempotent: A * A = A
//
//    If A is invertible, then A must be the identity matrix.
//    In other words, unless A is the identity matrix, it is singular.
//
//    I - A is also idempotent.
//
//    All eigenvalues of A are either 0 or 1.
//
//    rank(A) = trace(A)
//
//    A is a projector matrix.
//
//    The matrix I - 2A is involutory, that is ( I - 2A ) * ( I - 2A ) = I.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Alston Householder, John Carpenter,
//    The singular values of involutory and of idempotent matrices,
//    Numerische Mathematik,
//    Volume 5, 1963, pages 234-237.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int RANK, the rank of A.
//    0 <= RANK <= N.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double idempotent_random[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  double *q;
  double value;

  a = new double[n*n];

  if ( rank < 0 || n < rank )
  {
    cerr << "\n";
    cerr << "idempotent_random - Fatal error!\n";
    cerr << "  RANK must be between 0 and N.\n";
    cerr << "  Input value = " << rank << "\n";
    exit ( 1 );
  }
//
//  Get a random orthogonal matrix Q.
//
  q = orthogonal_random ( n, key );
//
//  Compute Q' * D * Q, where D is the diagonal eigenvalue matrix
//  of RANK 1's followed by N-RANK 0's.
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      value = 0.0;
      for ( k = 0; k < rank; k++ )
      {
        value = value + q[k+i*n] * q[k+j*n];
      }
      a[i+j*n] = value;
    }
  }
//
//  Free memory.
//
  delete [] q;

  return a;
}
//****************************************************************************80

double idempotent_random_determinant ( int n, int rank, int key )

//****************************************************************************80
//
//  Purpose:
//
//    idempotent_random_DETERMINANT returns the determinant of the idempotent_random matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int RANK, the rank of A.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double idempotent_random_DETERMINANT, the determinant.
//
{
  double determ;

  if ( rank == n )
  {
    determ = 1.0;
  }
  else
  {
    determ = 0.0;
  }
  return determ;
}
//****************************************************************************80

double *idempotent_random_eigenvalues ( int n, int rank, int key )

//****************************************************************************80
//
//  Purpose:
//
//    idempotent_random_EIGENVALUES returns the eigenvalues of the idempotent_random matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int RANK, the rank of A.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double idempotent_random_EIGENVALUES[N] the eigenvalues.
//
{
  int i;
  double *lambda;
  
  lambda = new double[n];

  for ( i = 0; i < rank; i++ )
  {
    lambda[i] = 1.0;
  }
  for ( i = rank; i < n; i++ )
  {
    lambda[i] = 0.0;
  }
  return lambda;
}
//****************************************************************************80

double *idempotent_random_eigen_right ( int n, int rank, int key )

//****************************************************************************80
//
//  Purpose:
//
//    idempotent_random_EIGEN_RIGHT returns the right eigenvectors of the idempotent_random matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Alston Householder, John Carpenter,
//    The singular values of involutory and of idempotent matrices,
//    Numerische Mathematik,
//    Volume 5, 1963, pages 234-237.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int RANK, the rank of A.
//    0 <= RANK <= N.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double idempotent_random_EIGEN_RIGHT[N*N], the matrix.
//
{
  double *x;
  double *y;

  y = orthogonal_random ( n, key );

  x = r8mat_transpose_new ( n, n, y );
//
//  Free memory.
//
  delete [] y;

  return x;
}
//****************************************************************************80

double *identity ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    IDENTITY returns the IDENTITY matrix.
//
//  Formula:
//
//    if ( I = J )
//      A[i+j*n] = 1
//    else
//      A[i+j*n] = 0
//
//  Example:
//
//    M = 4, N = 5
//
//    1 0 0 0 0
//    0 1 0 0 0
//    0 0 1 0 0
//    0 0 0 1 0
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a zero/one matrix.
//
//    A is nonsingular.
//
//    A is involutory: A * A = I.
//
//    A is diagonal.
//
//    Because A is diagonal, it has property A.
//
//    A is symmetric: A' = A.
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    LAMBDA(1:N) = 1
//
//    The matrix of eigenvectors of A is A.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    For any vector v, A*v = v.
//
//    For any matrix B, A*B = B*A=B.
//
//    A is persymmetric: A[i+j*n] = A(N+1-J,N+1-I).
//
//    A is centrosymmetric: A[i+j*n] = A(N+1-I,N+1-J).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double IDENTITY[M*N], the matrix.
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
      if ( i == j )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double identity_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IDENTITY_CONDITION returns the L1 condition of the IDENTITY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IDENTITY_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 1.0;
  b_norm = 1.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double identity_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IDENTITY_DETERMINANT returns the determinant of the IDENTITY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IDENTITY_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *identity_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IDENTITY_EIGENVALUES returns the eigenvalues of the IDENTITY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IDENTITY_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = 1.0;
  }
  return lambda;
}
//****************************************************************************80

double *identity_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IDENTITY_INVERSE returns the inverse of the IDENTITY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IDENTITY_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *identity_eigen_left ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IDENTITY_EIGEN_LEFT returns the left eigenvectors of the IDENTITY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IDENTITY_EIGEN_LEFT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *identity_eigen_right ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IDENTITY_EIGEN_RIGHT returns the right eigenvectors of the IDENTITY matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IDENTITY_EIGEN_RIGHT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *ijfact1 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IJFACT1 returns the IJFACT1 matrix.
//
//  Discussion:
//
//    This matrix is sometimes called the IJ-factorial matrix.
//
//  Formula:
//
//    A(I,J) = (I+J)!
//
//  Example:
//
//    N = 4
//
//     2   6   24   120
//     6  24  120   720
//    24 120  720  5040
//   120 720 5040 40320
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    MJC Gover,
//    The explicit inverse of factorial Hankel matrices,
//    Department of Mathematics, University of Bradford, 1993.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IJFACT1[N*N], the matrix.
//
{
  double *a;
  int fact;
  int i;
  int ihi;
  int ilo;
  int k;

  a = new double[n*n];

  fact = 1;

  for ( k = 2; k <= 2 * n; k++ )
  {
    fact = fact * k;
    ilo = i4_max ( 1, k - n );
    ihi = i4_min ( n, k - 1 );

    for ( i = ilo; i <= ihi; i++ )
    {
      a[i-1+(k-i-1)*n] = ( double ) ( fact );
    }
  }
  return a;
}
//****************************************************************************80

double ijfact1_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IJFACT1_DETERMINANT returns the determinant of the IJFACT1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IJFACT1_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int ip1;
  int nmi;
  int np1;

  determ = 1.0;

  for ( i = 1; i <= n - 1; i++ )
  {
    ip1 = i + 1;
    nmi = n - i;
    determ = determ * r8_factorial ( ip1 ) * r8_factorial ( nmi );
  }

  np1 = n + 1;
  determ = determ * r8_factorial ( np1 );

  return determ;
}
//****************************************************************************80

double *ijfact2 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IJFACT2 returns the IJFACT2 matrix.
//
//  Formula:
//
//    A(I,J) = 1 / ( (I+J)! )
//
//  Example:
//
//    N = 4
//
//   1/2   1/6   1/24   1/120
//   1/6   1/24  1/120  1/720
//   1/24  1/120 1/720  1/5040
//   1/120 1/720 1/5040 1/40320
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    MJC Gover,
//    The explicit inverse of factorial Hankel matrices,
//    Department of Mathematics, University of Bradford, 1993.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IJFACT2[N*N], the matrix.
//
{
  double *a;
  double fact;
  int i;
  int ihi;
  int ilo;
  int ipj;

  a = new double[n*n];

  fact = 1.0;

  for ( ipj = 2; ipj <= 2 * n; ipj++ )
  {
    fact = fact * ( double ) ipj;
    ilo = i4_max ( 1, ipj - n );
    ihi = i4_min ( n, ipj - 1 );
    for ( i = ilo; i <= ihi; i++ )
    {
      a[i-1+(ipj-i-1)*n] = 1.0 / fact;
    }
  }

  return a;
}
//****************************************************************************80

double ijfact2_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    IJFACT2_DETERMINANT returns the determinant of the IJFACT2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 November 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double IJFACT2_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int np1pi;

  determ = 1.0;

  for ( i = 0; i <= n - 1; i++ )
  {
    np1pi = n + 1 + i;
    determ = determ * r8_factorial ( i ) / r8_factorial ( np1pi );
  }

  if ( ( ( ( n * ( n - 1 ) ) / 2 ) % 2 ) != 0 )
  {
    determ = - determ;
  }

  return determ;
}
//****************************************************************************80

double *ill3 ( )

//****************************************************************************80
//
//  Purpose:
//
//    ILL3 returns the ILL3 matrix.
//
//  Discussion:
//
//    This is a 3x3 ill-conditioned matrix.
//
//  Formula:
//
//    -149  -50 -154
//     537  180  546
//     -27   -9  -25
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    The eigenvalues are ( 1, 2, 3 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, double ILL3[3*3], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[3*3] = {
  -149.0,  537.0, -27.0, 
   -50.0,  180.0,  -9.0, 
  -154.0,  546.0, -25.0 };

  a = r8mat_copy_new ( 3, 3, a_save );

  return a;
}
//****************************************************************************80

double ill3_condition ( )

//****************************************************************************80
//
//  Purpose:
//
//    ILL3_CONDITION returns the L1 condition of the ILL3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, double ILL3_CONDITION, the L1 condition.
//
{
  double value;

  value = 725.0 * 299.0;

  return value;
}
//****************************************************************************80

double ill3_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    ILL3_DETERMINANT returns the determinant of the ILL3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, double ILL3_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 6.0;

  return determ;
}
//****************************************************************************80

double *ill3_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    ILL3_EIGENVALUES returns the eigenvalues of the ILL3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, double ILL3_EIGENVALUES[3], the eigenvalues.
//
{
  double *lambda;
  static double lambda_save[3] = {
    3.0, 2.0, 1.0 };

  lambda = r8vec_copy_new ( 3, lambda_save );

  return lambda;
}
//****************************************************************************80

double *ill3_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    ILL3_INVERSE returns the inverse of the ILL3 matrix.
//
//  Formula:
//
//      69      68/3    70
//    -439/2  -433/6  -224
//       9/2     3/2     5
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double ILL3_INVERSE[3*3], the matrix.
//
{
  double *a;
  int n = 3;

  a = new double[n*n];

  a[0+0*n] =   69.0;
  a[1+0*n] = -219.5;
  a[2+0*n] =    4.5;

  a[0+1*n] =   68.0 / 3.0;
  a[1+1*n] = -433.0 / 6.0;
  a[2+1*n] =    1.5;

  a[0+2*n] =   70.0;
  a[1+2*n] = -224.0;
  a[2+2*n] =    5.0;

  return a;
}
//****************************************************************************80

double *ill3_eigen_right ( )

//****************************************************************************80
//
//  Purpose:
//
//    ILL3_EIGEN_RIGHT returns the right eigenvectors of the ILL3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, double ILL3_EIGEN_RIGHT[3*3], the right eigenvector matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[3*3] = {
  -0.139139989879567, 
   0.973979929161820, 
  -0.178894272703878, 
  -0.404061017818396, 
   0.909137290098421, 
   0.101015254452291, 
   0.316227766017190, 
  -0.948683298050396, 
  -0.000000000000407 };

  a = r8mat_copy_new ( 3, 3, a_save );

  return a;
}
//****************************************************************************80

double *indicator ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    INDICATOR returns the INDICATOR matrix.
//
//  Discussion:
//
//    The indicator matrix has entries which reveal their row and column.
//
//    That makes it useful for testing printing algorithms, or schemes
//    which select a submatrix, or extract a particular value from a
//    matrix, or in general, any situation in which it would be useful
//    to know the origin of a value that was extracted from a matrix.
//
//  Example:
//
//    M = 3, N = 4
//
//    A =
//
//    11 12 13 14
//    21 22 23 24
//    31 32 33 34
//
//  Properties:
//
//    For a particular A, no two entries are equal.
//
//    A is generally not symmetric: A' /= A.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix A.
//
//    Output, double INDICATOR[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[m*n];

  k = i4_power ( 10, i4_log_10 ( n ) + 1 );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * k + j + 1 );
    }
  }
  return a;
}
//****************************************************************************80

double *integration ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    INTEGRATION returns the INTEGRATION matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = 1
//    else if ( J = I + 1 )
//      A(I,J) = ALPHA / I
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5,
//    ALPHA = 2,
//
//    1  2   0   0   0
//    0  1  2/2  0   0
//    0  0   1  2/3  0
//    0  0   0   1  2/4
//    0  0   0   0   1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is unit upper triangular.
//
//    A is bidiagonal.
//
//    Because A is bidiagonal, it has property A (bipartite).
//
//    A is nonsingular.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    LAMBDA(1:N) = 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar which defines the first 
//    superdiagonal of the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double INTEGRATION[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == i )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == i + 1 )
      {
        a[i+j*n] = alpha / ( double ) ( i + 1 );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double integration_determinant ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    INTEGRATION_DETERMINANT returns the determinant of the INTEGRATION matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar which defines the first 
//    superdiagonal of the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double INTEGRATION_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *integration_eigenvalues ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    INTEGRATION_EIGENVALUES returns the eigenvalues of the INTEGRATION matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar which defines the first 
//    superdiagonal of the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double INTEGRATION_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = 1.0;
  }
  return lambda;
}
//****************************************************************************80

double *integration_inverse ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    INTEGRATION_INVERSE returns the inverse of the INTEGRATION matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = 1
//    else if ( I < J )
//      A(I,J) = (-ALPHA)^(J-I) / (I*...*J-1)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 2, N = 5
//
//    1 -2   2  -4/3   2/3
//    0  1  -1   2/3  -1/3
//    0  0   1  -2/3   1/3
//    0  0   0    1   -1/2
//    0  0   0    0     1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is unit upper triangular.
//
//    A is nonsingular.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    LAMBDA(1:N) = 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar which defines the first
//    superdiagonal of the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double INTEGRATION_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == i ) 
      {
        a[i+j*n] = 1.0;
      }
      else if ( i < j )
      {
        a[i+j*n] = pow ( - alpha, j - i ) 
          / ( double ) ( i4_rise ( i + 1, j - i ) );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *involutory ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    involutory returns the involutory matrix.
//
//  Discussion:
//
//    This matrix is an example of an involutory matrix.
//
//  Formula:
//
//    a[i+j*n] = 1 / ( I + J - 1 )
//
//    Set D = -N
//
//    Multiply column 1 of A by D.
//
//    For I = 1 to N-1
//      D = -(N+I)*(N-I)*D/(I*I)
//      Multiply row I + 1 by D.
//    End
//
//  Example:
//
//    N = 5
//
//       -5     0.5     0.33     0.25    0.2
//     -300    40.0    30.00    24.00   20.0
//     1050  -157.5  -126.00  -105.00  -90.0
//    -1400   224.0   186.66   160.00  140.0
//      630  -105.0   -90.00   -78.75  -70.0
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is involutory: A * A = I.
//
//    det ( A ) = +1 or -1.
//
//    A is unimodular.
//
//    The matrices:
//      B = 1/2 ( I - A )
//    and
//      C = 1/2 ( I + A )
//    are idempotent, that is, B * B = B, and C * C = C.
//
//    A is ill-conditioned.
//
//    A is a diagonally scaled version of the Hilbert matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Alston Householder, John Carpenter,
//    The singular values of involutory and of idempotent matrices,
//    Numerische Mathematik,
//    Volume 5, 1963, pages 234-237.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double involutory[N*N], the matrix.
//
{
  double *a;
  double d;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 1.0 / ( double ) ( i + j + 1 );
    }
  }

  d = - ( double ) ( n );

  j = 0;
  for ( i = 0; i < n; i++ )
  {
    a[i+j*n] = d * a[i+j*n] ;
  }

  for ( i = 1; i < n; i++ )
  {
    d = - ( double ) ( ( n + i ) * ( n - i ) ) * d  / ( double ) ( i * i );
    for ( j = 0; j < n; j++ )
   {
      a[i+j*n] = d * a[i+j*n];
    }
  }
  return a;
}
//****************************************************************************80

double involutory_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    involutory_DETERMINANT returns the determinant of the involutory matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double involutory_DETERMINANT, the determinant.
//
{
  double determ;

  if ( ( n % 4 ) == 0 || ( n % 4 ) == 3 )
  {
    determ = 1.0;
  }
  else
  {
    determ = -1.0;
  }
  return determ;
}
//****************************************************************************80

double *involutory_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    involutory_EIGENVALUES returns the eigenvalues of the involutory matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double involutory_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n / 2; i++ )
  {
    lambda[i] = +1.0;
  }
  for ( i = n / 2; i < n; i++ )
  {
    lambda[i] = -1.0;
  }
  return lambda;
}
//****************************************************************************80

double *involutory_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    involutory_INVERSE returns the inverse of the involutory matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double involutory_INVERSE[N*N], the matrix.
//
{
  double *a;

  a = involutory ( n );

  return a;
}
//****************************************************************************80

double *involutory_random ( int n, int rank, int key )

//****************************************************************************80
//
//  Purpose:
//
//    involutory_RANDOM returns the involutory_RANDOM matrix.
//
//  Discussion:
//
//    This matrix is a random involutory matrix.
//
//  Properties:
//
//    A is nonsingular.
//
//    A is involutory: A * A = I
//
//    det ( A ) = +1 or -1.
//
//    A is unimodular.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Alston Householder, John Carpenter,
//    The singular values of involutory and of idempotent matrices,
//    Numerische Mathematik,
//    Volume 5, 1963, pages 234-237.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int RANK, the rank of the idempotent matrix
//    used to generate A.  Setting RANK = 0 or N will yield
//    a multiple of the identity.  Intermediate values will give
//    more interesting results.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double involutory_RANDOM[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = idempotent_random ( n, rank, key );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0 - 2.0 * a[i+j*n];
      }
      else
      {
        a[i+j*n] = - 2.0 * a[i+j*n];
      }
    }
  }
  return a;
}
//****************************************************************************80

double *jacobi ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    JACOBI returns the JACOBI matrix.
//
//  Formula:
//
//    if ( J = I - 1 )
//      A(I,J) = 0.5 * sqrt ( ( 4 * J^2 ) / ( 4 * J^2 - 1 ) )
//    else if ( J = I + 1 ) then
//      A(I,J) = 0.5 * sqrt ( ( 4 * (J-1)^2 ) / ( 4 * (J-1)^2 - 1 ) )
//    else
//      A(I,J) = 0
//
//  Example:
//
//    M = 4, N = 4
//
//    0            0.577350269  0            0
//    0.577350269  0            0.516397779  0
//    0            0.516397779  0            0.507092553
//    0            0            0.507092553  0
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A has a zero diagonal.
//
//    The eigenvalues of A are the zeros of the Legendre polynomial
//    of degree N.  They lie symmetrically in [-1,1], and are also
//    the nodes of Gauss-Legendre quadrature.  For the case of N = 4,
//    these eigenvalues are
//
//      [ -0.861136312, -0.339981044, +0.339981044, +0.861136312 ].
//
//    It follows that A is singular when N is odd.
//
//    The J-th Gauss-Legendre weight is twice the square of the first
//    component of the J-th eigenvector of A.  For the case of N = 4,
//    the eigenvector matrix is:
//
//      -0.417046     -0.571028     -0.571028    0.417046
//       0.622037      0.336258     -0.336258    0.622038
//      -0.571028      0.417046      0.417046    0.571028
//       0.336258     -0.622037      0.622038    0.336258
//
//    and the corresponding weights are
//
//      [ 0.347854845, 0.652145155, 0.652145155, 0.347854845 ]
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Lloyd Trefethen, David Bau,
//    Numerical Linear Algebra,
//    SIAM, 1997, pages 287-292.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double JACOBI[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[m*n];

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( j == i - 1 )
      {
        a[i+j*m] = 0.5 * sqrt ( ( double ) ( 4 * ( j + 1 ) * ( j + 1 ) ) 
          / ( double ) ( 4 * ( j + 1 ) * ( j + 1 ) - 1 ) );
      }
      else if ( j == i + 1 )
      {
        a[i+j*m] = 0.5 * sqrt ( ( double ) ( 4 * j * j ) 
          / ( double ) ( 4 * j * j - 1 ) );
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double jacobi_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    JACOBI_DETERMINANT returns the determinant of the JACOBI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double JACOBI_DETERMINANT, the determinant.
//
{
  double determ;
  double *lambda;

  if ( ( n % 2 ) == 1 )
  { 
    determ = 0.0;
  }
  else
  {
    lambda = legendre_zeros ( n );
  
    determ = r8vec_product ( n, lambda );
//
//  Free memory.
//
    delete [] lambda;
  } 
  return determ;
}
//****************************************************************************80

double *jacobi_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    JACOBI_EIGENVALUES returns the eigenvalues of the JACOBI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double JACOBI_EIGENVALUES[N], the eigenvalues.
//
{
  double *lambda;

  lambda = legendre_zeros ( n );

  return lambda;
}
//****************************************************************************80

double *jacobi_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    JACOBI_INVERSE returns the inverse of the JACOBI matrix.
//
//  Discussion:
//
//    This inverse is related to that of the CLEMENT1 matrix.
//
//  Example:
//
//    N = 6
//
//         0    1.7321         0   -1.7638         0    1.7689
//    1.7321         0         0         0         0         0
//         0         0         0    1.9720         0   -1.9777
//   -1.7638         0    1.9720         0         0         0
//         0         0         0         0         0    1.9900
//    1.7689         0   -1.9777         0    1.9900         0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be even.
//
//    Output, double JACOBI_INVERSE[N*N], the matrix.
//
{
  double *a;
  double a1;
  double a2;
  int i;
  int j;
  double p;

  if ( ( n % 2 ) == 1 )
  {
    cerr << "\n";
    cerr << "JACOBI_INVERSE - Fatal error!\n";
    cerr << "  The Jacobi matrix is singular for odd N.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n; i++ )
  {
    if ( ( i % 2 ) == 0 )
    {
      p = 1.0;
      for ( j = i; j < n - 1; j = j + 2 )
      {
 
        a1 = 0.5 * sqrt ( ( double ) ( 4 * ( j + 1 ) * ( j + 1 ) )
                        / ( double ) ( 4 * ( j + 1 ) * ( j + 1 ) - 1 ) );
        a2 = 0.5 * sqrt ( ( double ) ( 4 * j * j )
                        / ( double ) ( 4 * j * j - 1 ) );

        if ( j == i )
        {
          p = p / a1;
        }
        else
        {
          p = - p * a2 / a1;
        }

        a[i+(j+1)*n] = p;
        a[j+1+i*n] = p;
      }
    }
  }

  return a;
}
//****************************************************************************80

void jacobi_iterate ( int n, double a[], double lambda[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    JACOBI_ITERATE applies the Jacobi eigenvalue iteration to a symmetric matrix.
//
//  Discussion:
//
//    I had to modify the code, in order to avoid cases where the
//    off-diagonal element was not exactly zero, but very very close.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double A[N*N], a symmetric matrix.
//    On output, the matrix has been overwritten by an approximately
//    diagonal matrix, with the eigenvalues on the diagonal.
//
//    Output, double LAMBDA[N], the computed eigenvalues.
//
//    Output, double X[N*N], the computed eigenvector matrix.
//
{
  double *b;
  double c;
  double eps = 0.00001;
  double error_frobenius;
  int i;
  int it;
  int it_max = 100;
  int j;
  int k;
  double norm_fro;
  double s;
  double sum2;
  double t;
  double t1;
  double t2;
  double u;

  error_frobenius = r8mat_is_symmetric ( n, n, a );

  if ( eps < error_frobenius )
  {
    cerr << "\n";
    cerr << "JACOBI_ITERATE - Fatal error!\n";
    cerr << "  The input matrix is not symmetric.\n";
    exit ( 1 );
  }

  b = r8mat_copy_new ( n, n, a );

  norm_fro = r8mat_norm_fro ( n, n, b );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        x[i+j*n] = 1.0;
      }
      else
      {
        x[i+j*n] = 0.0;
      }
    }
  }

  for ( it = 1; it <= it_max; it++ )
  {
    for ( i = 0; i < n; i++ )
    {
      for ( j = 0; j < i; j++ )
      {
        if ( eps * norm_fro < fabs ( b[i+j*n] ) + fabs ( b[j+i*n] ) )
        {
          u = ( b[j+j*n] - b[i+i*n] ) / ( b[i+j*n] + b[j+i*n] );

          t = r8_sign ( u ) / ( fabs ( u ) + sqrt ( u * u + 1.0 ) );
          c = 1.0 / sqrt ( t * t + 1.0 );
          s = t * c;
//
//  A -> A * Q.
//
          for ( k = 0; k < n; k++ )
          {
            t1 = b[i+k*n];
            t2 = b[j+k*n];
            b[i+k*n] = t1 * c - t2 * s;
            b[j+k*n] = t1 * s + t2 * c;
          }
//
//  A -> Q' * A
//
          for ( k = 0; k < n; k++ )
          {
            t1 = b[k+i*n];
            t2 = b[k+j*n];
            b[k+i*n] = c * t1 - s * t2;
            b[k+j*n] = s * t1 + c * t2;
          }
//
//  X -> Q' * X
//
          for ( k = 0; k < n; k++ )
          {
            t1 = x[k+i*n];
            t2 = x[k+j*n];
            x[k+i*n] = c * t1 - s * t2;
            x[k+j*n] = s * t1 + c * t2;
          }
        }
      }
    }
//
//  Test the size of the off-diagonal elements.
//
    sum2 = 0.0;
    for ( i = 0; i < n; i++ )
    {
      for ( j = 0; j < i; j++ )
      {
        sum2 = sum2 + fabs ( b[i+j*n] );
      }
    }

    if ( sum2 <= eps * ( norm_fro + 1.0 ) )
    {
      break;
    }
  }

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = b[i+i*n];
  }
//
//  Free memory.
//
  delete [] b;

  return;
}
//****************************************************************************80

int jacobi_symbol ( int q, int p )

//****************************************************************************80
//
//  Purpose:
//
//    JACOBI_SYMBOL evaluates the Jacobi symbol (Q/P).
//
//  Discussion:
//
//    If P is prime, then
//
//      Jacobi Symbol (Q/P) = Legendre Symbol (Q/P)
//
//    Else
//
//      let P have the prime factorization
//
//        P = Product ( 1 <= I <= N ) P(I)**E(I)
//
//      Jacobi Symbol (Q/P) =
//
//        Product ( 1 <= I <= N ) Legendre Symbol (Q/P(I))**E(I)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    30 June 2000
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Daniel Zwillinger,
//    CRC Standard Mathematical Tables and Formulae,
//    30th Edition,
//    CRC Press, 1996, pages 86-87.
//
//  Parameters:
//
//    Input, int Q, an integer whose Jacobi symbol with
//    respect to P is desired.
//
//    Input, int P, the number with respect to which the Jacobi
//    symbol of Q is desired.  P should be 2 or greater.
//
//    Output, int JACOBI_SYMBOL, the Jacobi symbol (Q/P).
//    Ordinarily, L will be -1, 0 or 1.
//    If JACOBI_SYMBOL is -10, an error occurred.
//
{
# define FACTOR_MAX 20

  int factor[FACTOR_MAX];
  int i;
  int l;
  int nfactor;
  int nleft;
  int power[FACTOR_MAX];
  int value;
//
//  P must be greater than 1.
//
  if ( p <= 1 )
  {
    cerr << "\n";
    cerr << "JACOBI_SYMBOL - Fatal error!\n";
    cerr << "  P must be greater than 1.\n";
    exit ( 1 );
  }
//
//  Decompose P into factors of prime powers.
//
  i4_factor ( p, FACTOR_MAX, nfactor, factor, power, nleft );

  if ( nleft != 1 )
  {
    cerr << "\n";
    cerr << "JACOBI_SYMBOL - Fatal error!\n";
    cerr << "  Not enough factorization space.\n";
    exit ( 1 );
  }
//
//  Force Q to be nonnegative.
//
  while ( q < 0 )
  {
    q = q + p;
  }
//
//  For each prime factor, compute the Legendre symbol, and
//  multiply the Jacobi symbol by the appropriate factor.
//
  value = 1;

  for ( i = 0; i < nfactor; i++ )
  {
    l = legendre_symbol ( q, factor[i] );

    if ( l < -1 )
    {
      cerr << "\n";
      cerr << "JACOBI_SYMBOL - Fatal error!\n";
      cerr << "  Error during Legendre symbol calculation.\n";
      exit ( 1 );
    }
    value = value * ( int ) pow ( ( double ) l, power[i] );
  }

  return value;
# undef FACTOR_MAX
}
//****************************************************************************80

double *jordan ( int m, int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    JORDAN returns the JORDAN matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = ALPHA
//    else if ( I = J-1 )
//      A(I,J) = 1
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 2, M = 5, N = 5
//
//    2  1  0  0  0
//    0  2  1  0  0
//    0  0  2  1  0
//    0  0  0  2  1
//    0  0  0  0  2
//
//  Properties:
//
//    A is upper triangular.
//
//    A is lower Hessenberg.
//
//    A is bidiagonal.
//
//    Because A is bidiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 2.
//
//    A is generally not symmetric: A' /= A.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is nonsingular if and only if ALPHA is nonzero.
//
//    det ( A ) = ALPHA^N.
//
//    LAMBDA(I) = ALPHA.
//
//    A is defective, having only one eigenvector, namely (1,0,0,...,0).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double ALPHA, the eigenvalue of the Jordan matrix.
//
//    Output, double JORDAN[M*N], the matrix.
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
      if ( i == j )
      {
        a[i+j*m] = alpha;
      }
      else if ( j == i + 1 )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }

  return a;
}
//****************************************************************************80

double jordan_condition ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    JORDAN_CONDITION returns the L1 condition of the JORDAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, the eigenvalue of the Jordan matrix.
//
//    Output, double JORDAN_CONDITION, the L1 condition.
//
{
  double a_norm;
  double a2;
  double b_norm;
  double value;

  a2 = fabs ( alpha );

  if ( n == 1 )
  {
    a_norm = a2;
  }
  else
  {
    a_norm = a2 + 1.0;
  }

  if ( a2 == 1 )
  {
    b_norm = ( double ) ( n ) * a2;
  }
  else
  {
    b_norm = ( pow ( a2, n ) - 1.0 ) / ( a2 - 1.0 ) / pow ( a2, n );
  }

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double jordan_determinant ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    JORDAN_DETERMINANT returns the determinant of the JORDAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, the eigenvalue of the Jordan matrix.
//
//    Output, double JORDAN_DETERMINANT, the determinant.
//
{
  double determ;

  determ = pow ( alpha, n );

  return determ;
}
//****************************************************************************80

double *jordan_eigenvalues ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    JORDAN_EIGENVALUES returns the eigenvalues of the JORDAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, the eigenvalue of the Jordan matrix.
//
//    Output, double JORDAN_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = alpha;
  }

  return lambda;
}
//****************************************************************************80

double *jordan_inverse ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    JORDAN_INVERSE returns the inverse of the JORDAN matrix.
//
//  Formula:
//
//    if ( I <= J )
//      A(I,J) =  -1 * (-1/ALPHA)^(J+1-I)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 2, N = 4
//
//    1/2 -1/4  1/8 -1/16
//    0    1/2 -1/4  1/8
//    0    0    1/2 -1/4
//    0    0    0    1/2
//
//  Properties:
//
//    A is upper triangular.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is generally not symmetric: A' /= A.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    The inverse of A is the Jordan block matrix, whose diagonal
//    entries are ALPHA, whose first superdiagonal entries are 1,
//    with all other entries zero.
//
//    det ( A ) = (1/ALPHA)^N.
//
//    LAMBDA(1:N) = 1 / ALPHA.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, the eigenvalue of the Jordan matrix.
//
//    Output, double JORDAN_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( alpha == 0.0 ) 
  {
    cerr << "\n";
    cerr << "JORDAN_INVERSE - Fatal error!\n";
    cerr << "  The input parameter ALPHA was 0.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i <= j )
      {
        a[i+j*n] =  - pow ( - 1.0 / alpha, j + 1 - i );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *kahan ( double alpha, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KAHAN returns the KAHAN matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,I) =  sin(ALPHA)^(I)
//    else if ( I < J )
//      A(I,J) = - sin(ALPHA)^(I) * cos(ALPHA)
//    else
//      A(I,J) = 0
//
//  Example:
//
//    ALPHA = 0.25, N = 4
//
//    S  -C*S    -C*S      -C*S
//    0     S^2  -C*S^2    -C*S^2
//    0     0       S^3    -C*S^3
//    0     0       0         S^4
//
//    where
//
//      S = sin(ALPHA), C=COS(ALPHA)
//
//  Properties:
//
//    A is upper triangular.
//
//    A = B * C, where B is a diagonal matrix and C is unit upper triangular.
//    For instance, for the case M = 3, N = 4:
//
//    A = | S 0    0    |  * | 1 -C -C  -C |
//        | 0 S^2  0    |    | 0  1 -C  -C |
//        | 0 0    S^3  |    | 0  0  1  -C |
//
//    A is generally not symmetric: A' /= A.
//
//    A has some interesting properties regarding estimation of
//    condition and rank.
//
//    det ( A ) = sin(ALPHA^(N*(N+1)/2).
//
//    LAMBDA(I) = sin ( ALPHA )^I
//
//    A is nonsingular if and only if sin ( ALPHA ) =/= 0.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Nicholas Higham,
//    A survey of condition number estimation for triangular matrices,
//    SIAM Review,
//    Volume 9, 1987, pages 575-596.
//
//    W Kahan,
//    Numerical Linear Algebra,
//    Canadian Mathematical Bulletin,
//    Volume 9, 1966, pages 757-801.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  A typical
//    value is 1.2.  The "interesting" range of ALPHA is 0 < ALPHA < PI.
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double KAHAN[M*N], the matrix.
//
{
  double *a;
  double csi;
  int i;
  int j;
  double si;

  a = new double[m*n];

  for ( i = 0; i < m; i++ )
  {
    si = pow ( sin ( alpha ), i + 1 );
    csi = - cos ( alpha ) * si;
    for ( j = 0; j < n; j++ )
    {
      if ( j < i )
      {
        a[i+j*m] = 0.0;
      }
      else if ( j == i )
      {
        a[i+j*m] = si;
      }
      else
      {
        a[i+j*m] = csi;
      }
    }
  }
  return a;
}
//****************************************************************************80

double kahan_determinant ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KAHAN_DETERMINANT returns the determinant of the KAHAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  A typical 
//    value is 1.2.  The "interesting" range of ALPHA is 0 < ALPHA < PI.
//
//    Input, int N, the order of the matrix.
//
//    Output, double KAHAN_DETERMINANT, the determinant.
//
{
  double determ;
  int power;

  power = ( n * ( n + 1 ) ) / 2;
  determ = pow ( sin ( alpha ), power );

  return determ;
}
//****************************************************************************80

double *kahan_inverse ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KAHAN_INVERSE returns the inverse of the KAHAN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  A typical 
//    value is 1.2.  The "interesting" range of ALPHA is 0 < ALPHA < PI.
//
//    Input, int N, the order of the matrix.
//
//    Output, double KAHAN_INVERSE[N*N], the matrix.
//
{
  double *a;
  double ci;
  int i;
  int j;
  double si;

  a = new double[n*n];

  ci = cos ( alpha );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0;
      }
      else if ( i == j - 1 )
      {
        a[i+j*n] = ci;
      }
      else if ( i < j )
      {
        a[i+j*n] = ci * pow ( 1.0 + ci, j - i - 1 );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
//
//  Scale the columns.
//
  for ( j = 0; j < n; j++ )
  {
    si = pow ( sin ( alpha ), j + 1 );
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = a[i+j*n] / si;
    }
  }
  return a;
}
//****************************************************************************80

double *kershaw ( )

//****************************************************************************80
//
//
//  Purpose:
//
//    KERSHAW returns the KERSHAW matrix.
//
//  Discussion:
//
//    The Kershaw matrix is a simple example of a symmetric
//    positive definite matrix for which the incomplete Cholesky
//    factorization fails, because of a negative pivot.
//
//  Example:
//
//     3 -2  0  2
//    -2  3 -2  0
//     0 -2  3 -2
//     2  0 -2  3
//
//  Properties:
//
//    A is symmetric.
//
//    A is positive definite.
//
//    det ( A ) = 1.
//
//    LAMBDA(A) = [ 
//      5.828427124746192
//      5.828427124746188
//      0.171572875253810
//      0.171572875253810 ].
//
//    A does not have an incompete Cholesky factorization.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    David Kershaw,
//    The Incomplete Cholesky-Conjugate Gradient Method for the Iterative
//    Solution of Systems of Linear Equations,
//    Journal of Computational Physics,
//    Volume 26, Number 1, January 1978, pages 43-65.
//
//  Parameters:
//
//    Output, double KERSHAW[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
     3.0, -2.0,  0.0,  2.0, 
    -2.0,  3.0, -2.0,  0.0, 
     0.0, -2.0,  3.0, -2.0, 
     2.0,  0.0, -2.0,  3.0 };
  int i;
  int j;

  a = new double[4*4];

  for ( j = 0; j < 4; j++ )
  {
    for ( i = 0; i < 4; i++ )
    {
      a[i+j*4] = a_save[i+j*4];
    }
  }
  return a;
}
//****************************************************************************80

double kershaw_condition ( )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAW_CONDITION returns the L1 condition of the KERSHAW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double KERSHAW_CONDITION, the L1 condition of the matrix.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 7.0;
  b_norm = 7.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double kershaw_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAW_DETERMINANT returns the determinant of the KERSHAW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double KERSHAW_DETERMINANT, the determinant of the matrix.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *kershaw_eigen_right ( )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAW_EIGEN_RIGHT returns right eigenvectors of the KERSHAW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double KERSHAW_EIGEN_RIGHT[4,4], the eigenvectors.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  double a_save[4*4] = {
    0.500000000000000,  -0.707106781186548, 
    0.500000000000000,  -0.000000000000000, 
    0.500000000000000,  -0.000000000000000, 
   -0.500000000000000,   0.707106781186548,
   -0.548490135760211,  -0.703402951241362,
   -0.446271857698584,   0.072279237578588, 
    0.446271857698584,  -0.072279237578588, 
   -0.548490135760211,  -0.703402951241362 };
    
  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double *kershaw_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAW_EIGENVALUES returns the eigenvalues of the KERSHAW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double KERSHAW_EIGENVALUES[4], the eigenvalues of the matrix.
//
{
  int i;
  double *lambda;
  static double lambda_save[4] = {
    5.828427124746192, 
    5.828427124746188, 
    0.171572875253810, 
    0.171572875253810 };

  lambda = new double[4];

  for ( i = 0; i < 4; i++ )
  {
    lambda[i] = lambda_save[i];
  }
  return lambda;
}
//****************************************************************************80

double *kershaw_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAW_INVERSE returns the inverse of the KERSHAW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double KERSHAW_INVERSE[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
     3.0,  2.0,  0.0, -2.0, 
     2.0,  3.0,  2.0,  0.0, 
     0.0,  2.0,  3.0,  2.0, 
    -2.0,  0.0,  2.0,  3.0 };

  int i;
  int j;

  a = new double[4*4];

  for ( j = 0; j < 4; j++ )
  {
    for ( i = 0; i < 4; i++ )
    {
      a[i+j*4] = a_save[i+j*4];
    }
  }
  return a;
}
//****************************************************************************80

double *kershaw_llt ( )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAW_LLT returns the Cholesky factor of the KERSHAW matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double KERSHAW_LLT[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
    1.732050807568877,  -1.154700538379252, 
                  0.0,   1.154700538379252, 
                  0.0,   1.290994448735805, 
   -1.549193338482967,   1.032795558988645, 
                  0.0,                 0.0, 
    0.774596669241483,  -0.516397779494321, 
                  0.0,                 0.0, 
                  0.0,   0.577350269189626 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double *kershawtri ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAWTRI returns the KERSHAWTRI matrix.
//
//  Discussion:
//
//    A(I,I) = X(I)     for I <= (N+1)/2
//    A(I,I) = X(N+1-I) for (N+1)/2 < I
//    A(I,J) = 1        for I = J + 1 or I = J - 1.
//    A(I,J) = 0        otherwise.
//
//  Example:
//
//    N = 5,
//    X = ( 10, 20, 30 )
//    A = 
//      10   1   0   0   0
//       1  20   1   0   0
//       0   1  30   1   0
//       0   0   1  20   1
//       0   0   0   1  10
//
//  Properties:
//
//    A is tridiagonal.
//
//    A is symmetric.
//
//    If the entries in X are integers, then det(A) is an integer.
//
//    If det(A) is an integer, then det(A) * inv(A) is an integer matrix.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is centrosymmetric: A(I,J) = A(N+1-I,N+1-J).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    P Schlegel,
//    The Explicit Inverse of a Tridiagonal Matrix,
//    Mathematics of Computation,
//    Volume 24, Number 111, July 1970, page 665.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[(N+1)/2], defines the diagonal of the matrix.
//
//    Output, double KERSHAWTRI[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int nh;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  nh = ( n / 2 );

  for ( i = 0; i < nh; i++ )
  {
    a[i+i*n]           = x[i];
    a[n-1-i+(n-1-i)*n] = x[i];
  }

  if ( ( n % 2 ) == 1 )
  {
    a[nh+nh*n] = x[nh];
  }
  
  for ( i = 0; i < n - 1; i++ )
  {
    a[i+(i+1)*n] = 1.0;
    a[i+1+i*n] = 1.0;
  }

  return a;
}
//****************************************************************************80

double kershawtri_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAWTRI_DETERMINANT returns the determinant of the KERSHAWTRI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[(N+1)/2], defines the diagonal of the matrix.
//
//    Output, double KERSHAWTRI_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int nh;
  double *r;
  double xim1;
  
  nh = ( n / 2 );

  r = new double[n+1];

  for ( i = 0; i < n + 1; i++ )
  {
    r[i] = 0.0;
  }

  r[0] = 1.0;
  r[1] = - x[0];

  for ( i = 2; i < n; i++ )
  {
    if ( i <= nh )
    {
      xim1 = x[i-1];
    }
    else
    {
      xim1 = x[n-i];
    }
    r[i] = - ( xim1 * r[i-1] + r[i-2] );
  }
  r[n] = x[0] * r[n-1] + r[n-2];

  determ = x[0] * r[n-1] + r[n-2];
//
//  Free memory.
//
  delete [] r;

  return determ;
}
//****************************************************************************80

double *kershawtri_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    KERSHAWTRI_INVERSE returns the inverse of the KERSHAWTRI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[(N+1)/2], defines the diagonal of the matrix.
//
//    Output, double KERSHAWTRI_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int nh;
  double *r;
  double xim1;

  nh = ( n / 2 );

  r = new double[n+1];

  for ( i = 0; i < n + 1; i++ )
  {
    r[i] = 0.0;
  }

  r[0] = 1.0;
  r[1] = - x[0];
  for ( i = 2; i < n; i++ )
  {
    if ( i <= nh )
    {
      xim1 = x[i-1];
    }
    else
    {
      xim1 = x[n-i];
    }
    r[i] = - ( xim1 * r[i-1] + r[i-2] );
  }
  r[n] = x[0] * r[n-1] + r[n-2];

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      a[i+j*n] = r[j] * r[n-1-i] / r[n];
    }
    a[i+i*n] = r[i] * r[n-1-i] / r[n];
    for ( j = i + 1; j < n; j++ )
    {
      a[i+j*n] = r[i] * r[n-1-j] / r[n];
    }
  }
//
//  Free memory.
//
  delete [] r;

  return a;
}
//****************************************************************************80

double *kms ( double alpha, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KMS returns the KMS matrix.
//
//  Discussion:
//
//    The KMS matrix is also called the Kac-Murdock-Szego matrix.
//
//  Formula:
//
//    A(I,J) = ALPHA^abs ( I - J )
//
//  Example:
//
//    ALPHA = 2, N = 5
//
//     1  2  4  8  16
//     2  1  2  4   8
//     4  2  1  2   4
//     8  4  2  1   2
//    16  8  4  2   1
//
//    ALPHA = 1/2, N = 5
//
//     1   1/2  1/4  1/8  1/16
//    1/2   1   1/2  1/4  1/8
//    1/4  1/2   1   1/2  1/4
//    1/8  1/4  1/2   1   1/2
//    1/16 1/8  1/4  1/2   1
//
//  Properties:
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is centrosymmetric: A(I,J) = A(N+1-I,N+1-J).
//
//    A has an L*D*L' factorization, with L being the inverse
//    of the transpose of the matrix with 1's on the diagonal and
//    -ALPHA on the superdiagonal and zero elsewhere, and
//    D(I,I) = (1-ALPHA^2) except that D(1,1)=1.
//
//    det ( A ) = ( 1 - ALPHA^2 )^(N-1).
//
//    The inverse of A is tridiagonal.
//
//    A is positive definite if and only if 0 < abs ( ALPHA ) < 1.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Trench,
//    Numerical solution of the eigenvalue problem for Hermitian
//    Toeplitz matrices,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 10, Number 2, April 1989, pages 135-146.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  
//    A typical value is 0.5.
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double KMS[M*N], the matrix.
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
      if ( alpha == 0.0 && i == j )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = pow ( alpha, abs ( i - j ) );
      }
    }
  }

  return a;
}
//****************************************************************************80

double kms_determinant ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KMS_DETERMINANT returns the determinant of the KMS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.
//
//    Input, int N, the order of the matrix.
//
//    Output, double KMS_DETERMINANT, the determinant.
//
{
  double determ;
 
  if ( n == 1 )
  {
    determ = 1.0;
  }
  else
  {
    determ = pow ( 1.0 - alpha * alpha, n - 1 );
  }
  return determ;
}
//****************************************************************************80

double *kms_eigenvalues ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KMS_EIGENVALUES returns the eigenvalues of the KMS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Trench,
//    Spectral decomposition of Kac-Murdock-Szego matrices,
//    Unpublished technical document.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  
//    Eigenvalue computations require 0 <= ALPHA <= 1.
//
//    Input, int N, the order of the matrix.
//
//    Output, double KMS_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;
  double *theta;

  lambda = new double[n];

  theta = kms_eigenvalues_theta ( alpha, n );
 
  for ( i = 0; i < n; i++ )
  {
    lambda[i] = ( 1.0 + alpha ) * ( 1.0 - alpha ) 
      / ( 1.0 - 2.0 * alpha * cos ( theta[i] ) + alpha * alpha );
  }
//
//  Free memory.
//
  delete [] theta;

  return lambda;
}
//****************************************************************************80

double *kms_eigenvalues_theta ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KMS_EIGENVALUES_THETA returns data needed to compute KMS eigenvalues.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Trench,
//    Spectral decomposition of Kac-Murdock-Szego matrices,
//    Unpublished technical document.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  
//    Eigenvalue computations require 0 <= ALPHA <= 1.
//
//    Input, int N, the order of the matrix.
//
//    Output, double KMS_EIGENVALUES_THETA[N], the angles associated with
//    the eigenvalues.
//
{
  double fxa;
  double fxb;
  double fxc;
  int i;
  const double r8_pi = 3.141592653589793;
  int step;
  int step_max = 100;
  double *t;
  double temp;
  double xa;
  double xb;
  double xc;

  t = new double[n];

  for ( i = 0; i < n; i++ )
  {
//
//  Avoid confusion in first subinterval, where f(0) = 0.
//
    if ( i == 0 )
    {
      xa = 0.0001;
    }
    else
    {
      xa = ( double ) ( i ) * r8_pi / ( double ) ( n + 1 );
    }
    fxa = kms_eigenvalues_theta_f ( alpha, n, xa );
    xb = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 1 );
    fxb = kms_eigenvalues_theta_f ( alpha, n, xb );

    if ( 0.0 < fxa )
    {
      temp = xa;
      xa = xb;
      xb = temp;
      temp = fxa;
      fxa = fxb;
      fxb = temp;
    }

    for ( step = 1; step <= step_max; step++ )
    {
      xc = 0.5 * ( xa + xb );
      fxc = kms_eigenvalues_theta_f ( alpha, n, xc );
//
//  Return if residual is small.
//
      if ( fabs ( fxc ) <= 0.0000001 )
      {
        break;
      }
//
//  Return if interval is small.
//
      if ( fabs ( xb - xa ) <= 0.0000001 )
      {
        break;
      }

      if ( fxc < 0.0 )
      {
        xa = xc;
        fxa = fxc;
      }
      else
      {
        xb = xc;
        fxb = fxc;
      }
    }

    t[i] = xc;
  }

  return t;
}
//****************************************************************************80

double kms_eigenvalues_theta_f ( double alpha, int n, double t )

//****************************************************************************80
//
//  Purpose:
//
//    KMS_EIGENVALUES_THETA_F evaluates a function for KMS eigenvalues.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Trench,
//    Spectral decomposition of Kac-Murdock-Szego matrices,
//    Unpublished technical document.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  
//    Eigenvalue computations require 0 <= ALPHA <= 1.
//
//    Input, int N, the order of the matrix.
//
//    Input, double T, an angle associated with the eigenvalue.
//
//    Output, double KMS_EIGENVALUES_THETA_F, the function value.
//
{
  double n_r8;
  double value;

  n_r8 = ( double ) ( n ); 

  value = sin ( ( n_r8 + 1.0 ) * t ) 
    - 2.0 * alpha * sin ( n_r8 * t ) 
    + alpha * alpha * sin ( ( n_r8 - 1.0 ) * t );

  return value;
}
//****************************************************************************80

double *kms_inverse ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KMS_INVERSE returns the inverse of the KMS matrix.
//
//  Formula:
//
//    if ( I = J )
//      if ( I = 1 )
//        A(I,J) = -1/(ALPHA^2-1)
//      else if ( I < N )
//        A(I,J) = -(ALPHA^2+1)/(ALPHA^2-1)
//      else if ( I = N )
//        A(I,J) = -1/(ALPHA^2-1)
//    else if ( J = I + 1 or I = J + 1 )
//      A(I,J) = ALPHA/(ALPHA^2-1)
//    else
//      A(I,J) = 0 otherwise
//
//  Example:
//
//    ALPHA = 2, N = 5
//
//         -1  2  0  0  0
//          2 -5  2  0  0
//    1/3 * 0  2 -5  2  0
//          0  0  2 -5  2
//          0  0  0  2 -1
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Trench,
//    Numerical solution of the eigenvalue problem for Hermitian
//    Toeplitz matrices,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 10, Number 2, April 1989, pages 135-146.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.
//
//    Input, int N, the order of the matrix.
//
//    Output, double KMS_INVERSE[N*N], the matrix.
//
{
  double *a;
  double bot;
  int i;
  int j;

  bot = alpha * alpha - 1.0;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        if ( j == 0 )
        {
          a[i+j*n] = - 1.0 / bot;
        }
        else if ( j < n - 1 )
        {
          a[i+j*n] = - ( alpha * alpha + 1.0 ) / bot;
        }
        else if ( j == n - 1 )
        {
          a[i+j*n] = - 1.0 / bot;
        }
      }
      else if ( i == j + 1 || j == i + 1 )
      {
        a[i+j*n] = alpha / bot;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

void kms_ldl ( double alpha, int n, double **l, double **d )

//****************************************************************************80
//
//  Purpose:
//
//    KMS_LDL returns the LDL factorization of the KMS matrix.
//
//  Discussion:
//
//    A = L * D * L'
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Trench,
//    Numerical solution of the eigenvalue problem for Hermitian
//    Toeplitz matrices,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 10, Number 2, April 1989, pages 135-146.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  
//    A typical value is 0.5.
//
//    Input, int N, the order of the matrix.
//
//    Output, double L[N*N], the lower triangular factor.
//
//    Output, double D[N*N], the diagonal factor.
//
{
  int i;
  int j;

  *l = new double[n*n];

  *l[0+0*n] = 1.0;
  for ( i = 1; i < n; i++ )
  {
    *l[i+0*n] = alpha * *l[i-1+0*n];
  }
  for ( j = 1; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      *l[i+j*n] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      *l[i+j*n] = *l[i-j+0*n];
    }
  }

  *d = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      *d[i+j*n] = 0.0;
    }
  }
  *d[0+0*n] = 1.0;
  for ( i = 1; i < n; i++ )
  {
    *d[i+i*n] = 1.0 - alpha * alpha;
  }
  return;
}
//****************************************************************************80

void kms_plu ( double alpha, int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    KMS_PLU returns the PLU factorization of the KMS matrix.
//
//  Example:
//
//    ALPHA = 0.5, N = 5
//
//    P = Identity matrix
//
//    L =
//
//       1    0   0   0   0
//      1/2   1   0   0   0
//      1/4  1/2  1   0   0
//      1/8  1/4 1/2  1   0
//      1/16 1/8 1/4 1/2  1
//
//    U =
//
//       1   1/2  1/4  1/8  1/16
//       0   3/4  3/8  3/16 3/32
//       0    0   3/4  3/8  3/16
//       0    0    0   3/4  3/8
//       0    0    0    0   3/4
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Trench,
//    Numerical solution of the eigenvalue problem for Hermitian
//    Toeplitz matrices,
//    SIAM Journal on Matrix Analysis and Applications,
//    Volume 10, Number 2, April 1989, pages 135-146.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.  
//    A typical value is 0.5.
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  l[0+0*n] = 1.0;
  for ( i = 1; i < n; i++ )
  {
    l[i+0*n] = alpha * l[i-1+0*n];
  }
  for ( j = 1; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      l[i+j*n] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      l[i+j*n] = l[i-j+0*n];
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      u[i+j*n] = l[j+i*n];
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 1; i < n; i++ )
    {
      u[i+j*n] = u[i+j*n] * ( 1.0 - alpha * alpha );
    }
  }

  return;
}
//****************************************************************************80

double *kms_eigen_right ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    KMS_EIGEN_RIGHT returns the right eigenvectors of the KMS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    William Trench,
//    Spectral decomposition of Kac-Murdock-Szego matrices,
//    Unpublished technical report.
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//    Eigenvalue computations require 0 <= ALPHA <= 1.
//
//    Input, int N, the order of A.
//
//    Output, double KMS_EIGEN_RIGHT[N*N], the right eigenvector matrix.
//
{
  double *a;
  int i;
  int j;
  double *t;

  a = new double[n*n];

  t = kms_eigenvalues_theta ( alpha, n );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      a[i+j*n] = sin ( ( double ) ( i + 1 ) * t[j] ) 
        - alpha * sin ( ( double ) ( i ) * t[j] );
    }
  }
//
//  Free memory.
//
  delete [] t;

  return a;
}
//****************************************************************************80

double *krylov ( int n, double b[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    KRYLOV returns the KRYLOV matrix.
//
//  Formula:
//
//    Column 1 of A is X.
//    Column 2 of A is B*X.
//    Column 3 of A is B*B*X.
//    ..
//    Column N of A is B^(N-1)*X.
//
//  Example:
//
//    N = 5, X = ( 1, -2, 3, -4, 5 )
//
//    Matrix B:
//
//    1  2 1 0 1
//    1  0 3 1 4
//    2  1 3 2 1
//    1  1 2 1 0
//    1 -4 3 5 0
//
//    Matrix A:
//
//     6  61  71  688
//    26  16 -37 2752
//     6  54 312 1878
//     1  44 229  887
//    -2 -76 379 2300
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gene Golub, Charles Van Loan,
//    Matrix Computations,
//    Johns Hopkins University Press, 1983, page 224.
//
//  Parameters:
//
//    Input, int N, the order of the matrices.
//
//    Input, double B[N*N], the multiplying matrix.
//
//    Input, double X[N], the vector defining A.
//
//    Output, double KRYLOV[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    a[i+0*n] = x[i];
  }

  for ( j = 1; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        a[i+j*n] = a[i+j*n] + b[i+k*n] * a[k+(j-1)*n];
      }
    }
  }
  return a;
}
//****************************************************************************80

double *laguerre ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LAGUERRE returns the LAGUERRE matrix.
//
//  Example:
//
//    N = 8
//
//      1      .     .      .    .    .    .    .
//      1     -1     .      .    .    .    .    .
//      2     -4     1      .    .    .    .    .   /    2
//      6    -18     9     -1    .    .    .    .   /    6
//     24    -96    72    -16    1    .    .    .   /   24
//    120   -600   600   -200   25   -1    .    .   /  120
//    720  -4320  5400  -2400  450  -36    1    .   /  720
//   5040 -35280 52920 -29400 7350 -882   49   -1   / 5040
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is lower triangular.
//
//    The columns of A alternate in sign.
//
//    A(I,1) = 1
//    A(I,I) = (-1)^(I-1) / (I-1)!.
//
//    LAMBDA(I) = (-1)^(I-1) / (I-1)!.
//
//    det ( A ) = product ( 1 <= I <= N ) (-1)^(I-1) / (I-1)!
//
//    The I-th row contains the coefficients of the Laguerre
//    polynomial of degree I-1.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Milton Abramowitz, Irene Stegun,
//    Handbook of Mathematical Functions,
//    US Department of Commerce, 1964.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LAGUERRE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }
  a = r8mat_zero_new ( n, n );

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+0*n] =   1.0;
  a[1+1*n] = - 1.0;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    a[i+0*n] = ( ( double ) ( 2 * i - 1 ) * a[i-1+0*n]
               + ( double ) (   - i + 1 ) * a[i-2+0*n] )
               / ( double ) (     i     );
    for ( j = 1; j < n; j++ )
    {
      a[i+j*n] = ( ( double ) ( 2 * i - 1 ) * a[i-1+j*n] 
                 - ( double ) (         1 ) * a[i-1+(j-1)*n]
                 + ( double ) (   - i + 1 ) * a[i-2+j*n] ) 
                 / ( double ) (     i     );
    }
  }
  return a;
}
//****************************************************************************80

double laguerre_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LAGUERRE_DETERMINANT returns the determinant of the LAGUERRE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LAGUERRE_DETERMINANT, the determinant.
//
{
  double determ;
  int i;

  determ = 1.0;
  for ( i = 0; i < n; i++ )
  {
    determ = determ * r8_mop ( i ) / r8_factorial ( i );
  }
  return determ;
}
//****************************************************************************80

double *laguerre_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LAGUERRE_INVERSE returns the inverse of the LAGUERRE matrix.
//
//  Example:
//
//    N = 9
//
//        1        .       .        .       .        .       .       .     .
//        1       -1       .        .       .        .       .       .     .
//        2       -4       2        .       .        .       .       .     .
//        6      -18      18       -6       .        .       .       .     .
//       24      -96     144      -96      24        .       .       .     .
//      120     -600    1200    -1200     600     -120       .       .     .
//      720    -4320   10800   -14400   10800    -4320     720       .     .
//     5040   -35280  105840  -176400  176400  -105840   35280   -5040     .
//     40320 -322560 1128960 -2257920 2822400 -2257920 1128960 -322560 40320
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is lower triangular.
//
//    The columns of A alternate in sign.
//
//    A(I,1) = (I-1)!
//    A(I,I) = (I-1)! * ( -1 )^(N+1)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LAGUERRE_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = r8mat_zero_new ( n, n );

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+0*n] =   1.0;
  a[1+1*n] = - 1.0;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    j = 0;
    a[i+j*n] = ( double ) ( i ) * a[i-1+j*n];
    for ( j = 1; j < n; j++ )
    {
      a[i+j*n] = ( double ) ( i ) * ( a[i-1+j*n] - a[i-1+(j-1)*n] );
    }
  }
  return a;
}
//****************************************************************************80

double *lauchli ( double alpha, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    LAUCHLI returns the LAUCHLI matrix.
//
//  Discussion:
//
//    The Lauchli matrix is of order M by N, with M = N + 1.
//
//    This matrix is a well-known example in least squares that indicates
//    the danger of forming the matrix of the normal equations,  A' * A.
//
//    A common value for ALPHA is sqrt(EPS) where EPS is the machine epsilon.
//
//  Formula:
//
//    if ( I = 1 )
//      A(I,J) = 1
//    else if ( I-1 = J )
//      A(I,J) = ALPHA
//    else
//      A(I,J) = 0
//
//  Example:
//
//    M = 5, N = 4
//    ALPHA = 2
//
//    1  1  1  1
//    2  0  0  0
//    0  2  0  0
//    0  0  2  0
//    0  0  0  2
//
//  Properties:
//
//    The matrix is singular in a simple way.  The first row is
//    equal to the sum of the other rows, divided by ALPHA.
//
//    if ( ALPHA /= 0 ) then
//      rank ( A ) = N - 1
//    else if ( ALPHA == 0 ) then
//      rank ( A ) = 1
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Peter Lauchli,
//    Jordan-Elimination und Ausgleichung nach kleinsten Quadraten,
//    (Jordan elimination and smoothing by least squares),
//    Numerische Mathematik,
//    Volume 3, Number 1, December 1961, pages 226-240.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining the matrix.
//
//    Input, int M, N, the order of the matrix.
//    It should be the case that M = N + 1.
//
//    Output, double LAUCHLI[M*N], the matrix.
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
      if ( i == 0 )
      {
        a[i+j*m] = 1.0;
      }
      else if ( i == j + 1 )
      {
        a[i+j*m] = alpha;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *lauchli_null_left ( double alpha, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    LAUCHLI_NULL_LEFT returns a left null vector of the LAUCHLI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar defining the matrix.
//
//    Input, int M, N, the order of the matrix.
//    It should be the case that M = N + 1.
//
//    Output, double LAUCHLI_NULL_LEFT[M], the vector.
//
{
  int i;
  double *x;

  x = new double[m];

  x[0] = - alpha;
  for ( i = 1; i < m; i++ )
  {
    x[i] = 1.0;
  }
  return x;
}
//****************************************************************************80

double *legendre ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LEGENDRE returns the LEGENDRE matrix.
//
//  Example:
//
//    N = 11
//
//     1    .     .     .      .     .      .      .       .     .     . / 1
//     .    1     .     .      .     .      .      .       .     .     . / 1
//    -1    .     3     .      .     .      .      .       .     .     . / 2
//     .   -3     .     5      .     .      .      .       .     .     . / 2
//     3    .   -30     .     35     .      .      .       .     .     . / 8
//     .   15     .   -70      .    63      .      .       .     .     . / 8
//    -5    .   105     .   -315     .    231      .       .     .     . / 16
//     .  -35     .   315      .  -693      .    429       .     .     . / 16
//    35    . -1260     .   6930     . -12012      .    6435     .     . / 128
//     .  315     . -4620      . 18018      . -25740       . 12155     . / 128
//   -63    .  3465     . -30030     .  90090      . -109395     . 46189 / 256
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is lower triangular.
//
//    The elements of each row sum to 1.
//
//    Because it has a constant row sum of 1,
//    A has an eigenvalue of 1, and
//    a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A is reducible.
//
//    The diagonals form a pattern of zero, positive, zero, negative.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LEGENDRE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = r8mat_zero_new ( n, n );

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+1*n] = 1.0;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    a[i+0*n] = - ( double ) ( i - 1 ) * a[i-2+0*n] / ( double ) ( i );
    for ( j = 1; j < n; j++ )
    {
      a[i+j*n] = ( ( double ) ( 2 * i - 1 ) * a[i-1+(j-1)*n]
                 + ( double ) (   - i + 1 ) * a[i-2+j*n] )
                 / ( double ) (     i     );
    }
  }
  return a;
}
//****************************************************************************80

double legendre_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LEGENDRE_DETERMINANT returns the determinant of the LEGENDRE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LEGENDRE_DETERMINANT, the determinant.
//
{
  int i;
  double t;
  double value;

  value = 1.0;
  t = 1.0;

  for ( i = 3; i <= n; i++ )
  {
    t = t * ( double ) ( 2 * i - 3 ) / ( double ) (  i - 1 );
    value = value * t;
  }

  return value;
}
//****************************************************************************80

double *legendre_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LEGENDRE_INVERSE returns the inverse of the LEGENDRE matrix.
//
//  Example:
//
//    N = 11
//
//       1    .     .    .     .    .    .   .    .   .   .
//       .    1     .    .     .    .    .   .    .   .   .
//       1    .     2    .     .    .    .   .    .   .   . /     3
//       .    3     .    2     .    .    .   .    .   .   . /     5
//       7    .    20    .     8    .    .   .    .   .   . /    35
//       .   27     .   28     .    8    .   .    .   .   . /    63
//      33    .   110    .    72    .   16   .    .   .   . /   231
//       .  143     .  182     .   88    .  16    .   .   . /   429
//     715    .  2600    .  2160    .  832   .  128   .   . /  6435
//       . 3315     . 4760     . 2992    . 960    . 128   . / 12155
//    4199    . 16150    . 15504    . 7904   . 2176   . 256 / 46189
//
//  Properties:
//
//    A is nonnegative.
//
//    The elements of each row sum to 1.
//
//    Because it has a constant row sum of 1,
//    A has an eigenvalue of 1, and
//    a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A is lower triangular.
//
//    A is reducible.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LEGENDRE_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( n <= 0 )
  {
    return NULL;
  }

  a = r8mat_zero_new ( n, n );

  a[0+0*n] = 1.0;

  if ( n == 1 )
  {
    return a;
  }

  a[1+1*n] = 1.0;

  if ( n == 2 )
  {
    return a;
  }

  for ( i = 2; i < n; i++ )
  {
    j = 0;
    a[i+j*n] = ( double ) ( j + 1 ) * a[i-1+1*n] / ( double ) ( 2 * j + 3 );
    for ( j = 1; j < n - 1; j++ )
    {
      a[i+j*n] = ( double ) (     j     ) * a[i-1+(j-1)*n] 
               / ( double ) ( 2 * j - 1 ) 
               + ( double ) (     j + 1 ) * a[i-1+(j+1)*n] 
               / ( double ) ( 2 * j + 3 );

    }
    j = n - 1;

    a[i+j*n] = ( double ) ( j ) * a[i-1+(j-1)*n]
             / ( double ) ( 2 * j - 1 );
  }
  return a;
}
//****************************************************************************80

int legendre_symbol ( int q, int p )

//****************************************************************************80
//
//  Purpose:
//
//    LEGENDRE_SYMBOL evaluates the Legendre symbol (Q/P).
//
//  Discussion:
//
//    Let P be an odd prime.  Q is a QUADRATIC RESIDUE modulo P
//    if there is an integer R such that R^2 = Q ( mod P ).
//    The Legendre symbol ( Q / P ) is defined to be:
//
//      + 1 if Q ( mod P ) /= 0 and Q is a quadratic residue modulo P,
//      - 1 if Q ( mod P ) /= 0 and Q is not a quadratic residue modulo P,
//        0 if Q ( mod P ) == 0.
//
//    We can also define ( Q / P ) for P = 2 by:
//
//      + 1 if Q ( mod P ) /= 0
//        0 if Q ( mod P ) == 0
//
//  Example:
//
//    (0/7) =   0
//    (1/7) = + 1  ( 1^2 = 1 mod 7 )
//    (2/7) = + 1  ( 3^2 = 2 mod 7 )
//    (3/7) = - 1
//    (4/7) = + 1  ( 2^2 = 4 mod 7 )
//    (5/7) = - 1
//    (6/7) = - 1
//
//  Discussion:
//
//    For any prime P, exactly half of the integers from 1 to P-1
//    are quadratic residues.
//
//    ( 0 / P ) = 0.
//
//    ( Q / P ) = ( mod ( Q, P ) / P ).
//
//    ( Q / P ) = ( Q1 / P ) * ( Q2 / P ) if Q = Q1 * Q2.
//
//    If Q is prime, and P is prime and greater than 2, then:
//
//      if ( Q == 1 ) then
//
//        ( Q / P ) = 1
//
//      else if ( Q == 2 ) then
//
//        ( Q / P ) = + 1 if mod ( P, 8 ) = 1 or mod ( P, 8 ) = 7,
//        ( Q / P ) = - 1 if mod ( P, 8 ) = 3 or mod ( P, 8 ) = 5.
//
//      else
//
//        ( Q / P ) = - ( P / Q ) if Q = 3 ( mod 4 ) and P = 3 ( mod 4 ),
//                  =   ( P / Q ) otherwise.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 March 2001
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Charles Pinter,
//    A Book of Abstract Algebra,
//    McGraw Hill, 1982, pages 236-237.
//
//    Daniel Zwillinger,
//    CRC Standard Mathematical Tables and Formulae,
//    30th Edition,
//    CRC Press, 1996, pages 86-87.
//
//  Parameters:
//
//    Input, int Q, an integer whose Legendre symbol with
//    respect to P is desired.
//
//    Input, int P, a prime number, greater than 1, with respect
//    to which the Legendre symbol of Q is desired.
//
//    Output, int LEGENDRE_SYMBOL, the Legendre symbol (Q/P).
//    Ordinarily, this will be -1, 0 or 1.
//    L = -2, P is less than or equal to 1.
//    L = -3, P is not prime.
//    L = -4, the internal stack of factors overflowed.
//    L = -5, not enough factorization space.
//
{
# define FACTOR_MAX 20
# define STACK_MAX 50

  int factor[FACTOR_MAX];
  int i;
  int l;
  int nfactor;
  int nleft;
  int nmore;
  int nstack;
  int power[FACTOR_MAX];
  int pstack[STACK_MAX];
  int qstack[STACK_MAX];
  int r;
//
//  P must be greater than 1.
//
  if ( p <= 1 )
  {
    cerr << "\n";
    cerr << "LEGENDRE_SYMBOL - Fatal error!\n";
    cerr << "  P must be greater than 1.\n";
    exit ( 1 );
  }
//
//  P must be prime.
//
  if ( !( i4_is_prime ( p ) ) )
  {
    cerr << "\n";
    cerr << "LEGENDRE_SYMBOL - Fatal error!\n";
    cerr << "  P is not prime.\n";
    exit ( 1 );
  }
//
//  ( k*P / P ) = 0.
//
  if ( ( q % p ) == 0 )
  {
    return 0;
  }
//
//  For the special case P = 2, (Q/P) = 1 for all odd numbers.
//
  if ( p == 2 )
  {
    return 1;
  }
//
//  Force Q to be nonnegative.
//
  while ( q < 0 )
  {
    q = q + p;
  }

  nstack = 0;
  l = 1;

  for ( ; ; )
  {
    q = q % p;
//
//  Decompose Q into factors of prime powers.
//
    i4_factor ( q, FACTOR_MAX, nfactor, factor, power, nleft );

    if ( nleft != 1 )
    {
      cerr << "\n";
      cerr << "LEGENDRE_SYMBOL - Fatal error!\n";
      cerr << "  Not enough factorization space.\n";
      exit ( 1 );
    }
//
//  Each factor which is an odd power is added to the stack.
//
    nmore = 0;

    for ( i = 0; i < nfactor; i++ )
    {
      if ( ( power[i] % 2 ) == 1 )
      {
        nmore = nmore + 1;

        if ( STACK_MAX <= nstack )
        {
          cerr << "\n";
          cerr << "LEGENDRE_SYMBOL - Fatal error!\n";
          cerr << "  Stack overflow!\n";
          exit ( 1 );
        }

        pstack[nstack] = p;
        qstack[nstack] = factor[i];
        nstack = nstack + 1;
      }
    }

    if ( nmore != 0 )
    {
      nstack = nstack - 1;
      q = qstack[nstack];
//
//  Check for a Q of 1 or 2.
//
      if ( q == 1 )
      {
        l = + 1 * l;
      }
      else if ( q == 2 && ( ( p % 8 ) == 1 || ( p % 8 ) == 7 ) )
      {
        l = + 1 * l;
      }
      else if ( q == 2 && ( ( p % 8 ) == 3 || ( p % 8 ) == 5 ) )
      {
        l = - 1 * l;
      }
      else
      {
        if ( ( p % 4 ) == 3 && ( q % 4 ) == 3 )
        {
          l = - 1 * l;
        }
        r = p;
        p = q;
        q = r;

        continue;
      }
    }
//
//  If the stack is empty, we're done.
//
    if ( nstack == 0 )
    {
      break;
    }
//
//  Otherwise, get the last P and Q from the stack, and process them.
//
    nstack = nstack - 1;
    p = pstack[nstack];
    q = qstack[nstack];
  }

  return l;

# undef FACTOR_MAX
# undef STACK_MAX
}
//****************************************************************************80

double *legendre_van ( int m, double a, double b, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    LEGENDRE_VAN returns the LEGENDRE_VAN matrix.
//
//  Discussion:
//
//    The LEGENDRE_VAN matrix is the Legendre Vandermonde-like matrix.
//
//    Normally, the Legendre polynomials are defined on -1 <= XI <= +1.
//    Here, we assume the Legendre polynomials have been defined on the
//    interval A <= X <= B, using the mapping
//      XI = ( - ( B - X ) + ( X - A ) ) / ( B - A )
//    so that
//      Lab(A,B;X) = L(XI).
//
//    if ( I = 1 ) then
//      V(1,1:N) = 1
//    else if ( I = 2 ) then
//      V(2,1:N) = XI(1:N)
//    else
//      V(I,1:N) = ( (2*I-1) * XI(1:N) * V(I-1,1:N) - (I-1)*V(I-2,1:N) ) / I
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 April 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//
//    Input, double A, B, the interval.
//
//    Input, int N, the number of columns of the matrix.
//
//    Input, double X[N], the vector that defines the matrix.
//
//    Output, double LEGENDRE_VAN[M*N], the matrix.
//
{
  int i;
  int j;
  double *v;
  double xi;

  v = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    xi = ( - ( b - x[j] ) + ( x[j] - a ) ) / ( b - a );
    for ( i = 0; i < m; i++ )
    {
      if ( i == 0 )
      {
        v[i+j*m] = 1.0;
      }
      else if ( i == 1 )
      {
        v[i+j*m] = xi;
      }
      else
      {
        v[i+j*m] = ( ( double ) ( 2 * i - 1 ) * xi * v[i-1+j*m] +
                     ( double ) (   - i + 1 ) *      v[i-2+j*m] )
                   / ( double ) (     i );
      }
    }
  }

  return v;
}
//****************************************************************************80

double *legendre_zeros ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LEGENDRE_ZEROS computes the zeros of the Legendre polynomial.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 June 2008
//
//  Author:
//
//    Original FORTRAN77 version by Philip Davis, Philip Rabinowitz.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Philip Davis, Philip Rabinowitz,
//    Methods of Numerical Integration,
//    Second Edition,
//    Dover, 2007,
//    ISBN: 0486453391,
//    LC: QA299.3.D28.
//
//  Parameters:
//
//    Input, int N, the degree of the polynomial.
//
//    Output, double LEGENDRE_ZEROS[N], the zeros of the polynomial.
//
{
  double d1;
  double d2pn;
  double d3pn;
  double d4pn;
  double dp;
  double dpn;
  double e1;
  double h;
  int i;
  int iback;
  int k;
  int m;
  int mp1mi;
  int ncopy;
  int nmove;
  double p;
  const double r8_pi = 3.141592653589793;
  double pk;
  double pkm1;
  double pkp1;
  double t;
  double u;
  double v;
  double *x;
  double x0;
  double xtemp;

  x = new double[n];

  e1 = ( double ) ( n * ( n + 1 ) );

  m = ( n + 1 ) / 2;

  for ( i = 1; i <= m; i++ )
  {
    mp1mi = m + 1 - i;

    t = ( double ) ( 4 * i - 1 ) * r8_pi / ( double ) ( 4 * n + 2 );

    x0 = cos ( t ) * ( 1.0 - ( 1.0 - 1.0 / ( double ) ( n ) ) 
      / ( double ) ( 8 * n * n ) );

    pkm1 = 1.0;
    pk = x0;

    for ( k = 2; k <= n; k++ )
    {
      pkp1 = 2.0 * x0 * pk - pkm1 - ( x0 * pk - pkm1 ) / ( double ) ( k );
      pkm1 = pk;
      pk = pkp1;
    }

    d1 = ( double ) ( n ) * ( pkm1 - x0 * pk );

    dpn = d1 / ( 1.0 - x0 * x0 );

    d2pn = ( 2.0 * x0 * dpn - e1 * pk ) / ( 1.0 - x0 * x0 );

    d3pn = ( 4.0 * x0 * d2pn + ( 2.0 - e1 ) * dpn ) / ( 1.0 - x0 * x0 );

    d4pn = ( 6.0 * x0 * d3pn + ( 6.0 - e1 ) * d2pn ) / ( 1.0 - x0 * x0 );

    u = pk / dpn;
    v = d2pn / dpn;
//
//  Initial approximation H:
//
    h = -u * ( 1.0 + 0.5 * u * ( v + u * ( v * v - d3pn / ( 3.0 * dpn ) ) ) );
//
//  Refine H using one step of Newton's method:
//
    p = pk + h * ( dpn + 0.5 * h * ( d2pn + h / 3.0 
      * ( d3pn + 0.25 * h * d4pn ) ) );

    dp = dpn + h * ( d2pn + 0.5 * h * ( d3pn + h * d4pn / 3.0 ) );

    h = h - p / dp;

    xtemp = x0 + h;

    x[mp1mi-1] = xtemp;

//  fx = d1 - h * e1 * ( pk + 0.5 * h * ( dpn + h / 3.0 
//    * ( d2pn + 0.25 * h * ( d3pn + 0.2 * h * d4pn ) ) ) );
  }

  if ( ( n % 2 ) == 1 )
  {
    x[0] = 0.0;
  }
//
//  Shift the data up.
//
  nmove = ( n + 1 ) / 2;
  ncopy = n - nmove;

  for ( i = 1; i <= nmove; i++ )
  {
    iback = n + 1 - i;
    x[iback-1] = x[iback-ncopy-1];
  }
//
//  Reflect values for the negative abscissas.
//
  for ( i = 1; i <= n - nmove; i++ )
  {
    x[i-1] = - x[n-i];
  }

  return x;
}
//****************************************************************************80

double *lehmer ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    LEHMER returns the LEHMER matrix.
//
//  Discussion:
//
//    This matrix is also known as the "Westlake" matrix.
//
//    See page 154 of the Todd reference.
//
//  Formula:
//
//    A(I,J) = min ( I, J ) / max ( I, J )
//
//  Example:
//
//    N = 5
//
//    1/1  1/2  1/3  1/4  1/5
//    1/2  2/2  2/3  2/4  2/5
//    1/3  2/3  3/3  3/4  3/5
//    1/4  2/4  3/4  4/4  4/5
//    1/5  2/5  3/5  4/5  5/5
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is positive definite.
//
//    A is totally nonnegative.
//
//    The inverse of A is tridiagonal.
//
//    The condition number of A lies between N and 4*N*N.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Morris Newman, John Todd,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, 1958, pages 466-476.
//
//    Solutions to problem E710, proposed by DH Lehmer: The inverse of
//    a matrix.
//    American Mathematical Monthly,
//    Volume 53, Number 9, November 1946, pages 534-535.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double LEHMER[M*N], the matrix.
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
      a[i+j*m] = ( double ) ( i4_min ( i + 1, j + 1 ) ) 
               / ( double ) ( i4_max ( i + 1, j + 1 ) );
    }
  }
  return a;
}
//****************************************************************************80

double lehmer_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LEHMER_DETERMINANT returns the determinant of the LEHMER matrix.
//
//  Formula:
//
//    determinant = (2n)! / 2^n / (n!)^3
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Emrah Kilic, Pantelimon Stanica,
//    The Lehmer matrix and its recursive analogue,
//    Journal of Combinatorial Mathematics and Combinatorial Computing,
//    Volume 74, August 2010, pages 193-205.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LEHMER_DETERMINANT, the determinant.
//
{
  int i;
  double value;

  value = 1.0;
  for ( i = 1; i <= n; i++ )
  {
    value = value * ( double ) ( n + i ) / ( double ) ( 2 * i * i );
  }

  return value;
}
//****************************************************************************80

double *lehmer_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LEHMER_INVERSE returns the inverse of the LEHMER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LEHMER_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;

  a = r8mat_zero_new ( n, n );

  for ( i = 0; i < n - 1; i++ )
  {
    a[i+i*n] = ( double ) ( 4 * ( i + 1 ) * ( i + 1 ) * ( i + 1 ) ) 
             / ( double ) ( 4 * ( i + 1 ) * ( i + 1 ) - 1 );
  }
  a[n-1+(n-1)*n] = ( double ) ( n * n ) / ( double ) ( 2 * n - 1 );

  for ( i = 0; i < n - 1; i++ )
  {
    a[i+(i+1)*n] = - ( double ) ( ( i + 1 ) * ( i + 2 ) ) 
                   / ( double ) ( 2 * i + 3 );
    a[i+1+i*n]   = - ( double ) ( ( i + 1 ) * ( i + 2 ) ) 
                   / ( double ) ( 2 * i + 3 );
  }
  return a;
}
//****************************************************************************80

double *lehmer_llt ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LEHMER_LLT returns the Cholesky factor of the LEHMER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Emrah Kilic, Pantelimon Stanica,
//    The Lehmer matrix and its recursive analogue,
//    Journal of Combinatorial Mathematics and Combinatorial Computing,
//    Volume 74, August 2010, pages 193-205.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LEHMER_LLT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  
  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      a[i+j*n] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      a[i+j*n] = sqrt ( ( double ) ( 2 * j + 1 ) ) / ( double ) ( i + 1 );
    }
  }

  return a;
}
//****************************************************************************80

void lehmer_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    LEHMER_PLU returns the PLU factors of the LEHMER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Emrah Kilic, Pantelimon Stanica,
//    The Lehmer matrix and its recursive analogue,
//    Journal of Combinatorial Mathematics and Combinatorial Computing,
//    Volume 74, August 2010, pages 193-205.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      l[i+j*n] = 0.0;
    }
    l[j+j*n] = 1.0;
    for ( i = j + 1; i < n; i++ )
    {
      l[i+j*n] = ( double ) ( j + 1 ) / ( double ) ( i + 1 );
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      u[i+j*n] = ( double ) ( 2 * i + 1 ) / ( double ) ( ( i + 1 ) * ( j + 1 ) );
    }
    for ( i = j + 1; i < n; i++ )
    {
      u[i+j*n] = 0.0;
    }
  }

  return;
}
//****************************************************************************80

double *leslie ( double b, double di, double da )

//****************************************************************************80
//
//  Purpose:
//
//    LESLIE returns the LESLIE matrix.
//
//  Discussion:
//
//    This matrix is used in population dynamics.
//
//  Formula:
//
//    5/6 * ( 1.0 - DI )    0      B         0
//    1/6 * ( 1.0 - DI )  13/14    0         0
//        0                    1/14  39/40       0
//        0                     0     1/40  9/10 * ( 1 - DA )
//
//  Discussion:
//
//    A human population is assumed to be grouped into the categories:
//
//      X(+0*n] = between  0 and  5+
//      X(+1*n] = between  6 and 19+
//      X(+2*n] = between 20 and 59+
//      X(+3*n] = between 60 and 69+
//
//    Humans older than 69 are ignored.  Deaths occur in the 60 to 69
//    year bracket at a relative rate of DA per year, and in the 0 to 5
//    year bracket at a relative rate of DI per year.  Deaths do not occurr
//    in the other two brackets.
//
//    Births occur at a rate of B relative to the population in the
//    20 to 59 year bracket.
//
//    Thus, given the population vector X in a given year, the population
//    in the next year will be A * X.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Ke Chen, Peter Giblin, Alan Irving,
//    Mathematical Explorations with MATLAB,
//    Cambridge University Press, 1999,
//    ISBN: 0-521-63920-4.
//
//  Parameters:
//
//    Input, double B, DI, DA, the birth rate, infant mortality rate,
//    and aged mortality rate.  These should be positive values.
//    The mortality rates must be between 0.0 and 1.0.  Reasonable
//    values might be B = 0.025, DI = 0.010, and DA = 0.100
//
//    Output, double LESLIE[4*4], the matrix.
//
{
  double *a;
  int n = 4;

  a = new double[n*n];

  if ( b < 0.0 )
  {
    cerr << "\n";
    cerr << "LESLIE - Fatal error!\n";
    cerr << "  0 <= B is required.\n";
    exit ( 1 );
  }

  if ( da < 0.0 || 1.0 < da )
  {
    cerr << "\n";
    cerr << "LESLIE - Fatal error!\n";
    cerr << "  0 <= DA <= 1.0 is required.\n";
    exit ( 1 );
  }

  if ( di < 0.0 || 1.0 < di )
  {
    cerr << "\n";
    cerr << "LESLIE - Fatal error!\n";
    cerr << "  DI < 0 or 1.0 < DI.\n";
    exit ( 1 );
  }

  a[0+0*n] = 5.0 * ( 1.0 - di ) / 6.0;
  a[0+1*n] = 0.0;
  a[0+2*n] = b;
  a[0+3*n] = 0.0;

  a[1+0*n] = ( 1.0 - di ) / 6.0;
  a[1+1*n] = 13.0 / 14.0;
  a[1+2*n] = 0.0;
  a[1+3*n] = 0.0;

  a[2+0*n] = 0.0;
  a[2+1*n] = 1.0 / 14.0;
  a[2+2*n] = 39.0 / 40.0;
  a[2+3*n] = 0.0;

  a[3+0*n] = 0.0;
  a[3+1*n] = 0.0;
  a[3+2*n] = 1.0 / 40.0;
  a[3+3*n] = 9.0 * ( 1.0 - da ) / 10.0;

  return a;
}
//****************************************************************************80

double leslie_determinant ( double b, double di, double da )

//****************************************************************************80
//
//  Purpose:
//
//    LESLIE_DETERMINANT returns the determinant of the LESLIE matrix.
//
//  Discussion:
//
//    DETERM = a(4,4) * ( 
//        a(1,1) * a(2,2) * a(3,3)
//      + a(1,3) * a(2,1) * a(3,2) )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double B, DI, DA, the birth rate, infant mortality rate,
//    and aged mortality rate.  These should be positive values.
//    The mortality rates must be between 0.0 and 1.0.  Reasonable
//    values might be B = 0.025, DI = 0.010, and DA = 0.100
//
//    Output, double LESLIE_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 9.0 * ( 1.0 - da ) / 10.0 * 
  ( 
      5.0 * ( 1.0 - di ) / 6.0 
    * 13.0 / 14.0 
    * 39.0 / 40.0 
  +   b 
    * ( 1.0 - di ) / 6.0 
    * 1.0 / 14.0 
   );

  return determ;
}
//****************************************************************************80

double *lesp ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    LESP returns the LESP matrix.
//
//  Formula:
//
//    if ( I - J == 1 ) then
//      A(I,J) = 1 / I
//    else if ( I - J == 0 ) then
//      A(I,J) = - ( 2*I+3 )
//    else if ( I - J == 1 ) then
//      A(I,J) = J
//    else
//      A(I,J) = 0.0
//
//  Example:
//
//    M = 5, N = 5
//
//     -5    2    .    .     .
//     1/2  -7    3    .     .
//      .   1/3  -9    4     .
//      .    .   1/4 -11     5
//      .    .    .   1/5  -13
//
//
//  Properties:
//
//    The matrix is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is generally not symmetric: A' /= A.
//
//    The eigenvalues are real, and smoothly distributed in [-2*N-3.5, -4.5].
//
//    The eigenvalues are sensitive.
//
//    The matrix is similar to the symmetric tridiagonal matrix with
//    the same diagonal entries and with off-diagonal entries 1,
//    via a similarity transformation using the diagonal matrix
//    D = diagonal ( 1!, 2!, ..., N! ).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Wim Lenferink, MN Spijker,
//    On the use of stability regions in the numerical analysis of initial
//    value problems,
//    Mathematics of Computation,
//    Volume 57, 1991, pages 221-237.
//
//    Lloyd Trefethen,
//    Pseudospectra of matrices,
//    in Numerical Analysis 1991,
//    Proceedings of the 14th Dundee Conference,
//    D F Griffiths and G A Watson, editors,
//    Pitman Research Notes in Mathematics, volume 260,
//    Longman Scientific and Technical, Essex, UK, 1992, pages 234-266.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double LESP[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( i - j == 1 )
      {
        a[i+j*m] = 1.0 / ( double ) ( i + 1 );
      }
      else if ( i - j == 0 )
      {
        a[i+j*m] = - ( double ) ( 2 * i + 5 );
      }
      else if ( i - j == -1 )
      {
        a[i+j*m] = ( double ) ( j + 1 );
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double lesp_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LESP_DETERMINANT computes the determinant of the LESP matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LESP_DETERMINANT, the determinant.
//
{
  double determ;
  double determ_nm1;
  double determ_nm2;
  int i;

  determ_nm1 = - ( double ) ( 2 * n + 3 );

  if ( n == 1 )
  {
    determ = determ_nm1;
    return determ;
  }

  determ_nm2 = determ_nm1;
  determ_nm1 = ( double ) ( 2 * n + 1 ) * ( double ) ( 2 * n + 3 ) - 1.0;

  if ( n == 2 )
  {
    determ = determ_nm1;
    return determ;
  }

  for ( i = n - 2; 1 <= i; i-- )
  {
    determ = - ( double ) ( 2 * i + 3 ) * determ_nm1 - determ_nm2;

    determ_nm2 = determ_nm1;
    determ_nm1 = determ;
  }

  return determ;
}
//****************************************************************************80

double *lesp_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LESP_INVERSE returns the inverse of the LESP matrix.
//
//  Discussion:
//
//    This computation is an application of the TRIV_INVERSE function.
//
//  Example:
//
//    N = 5
//   -0.2060   -0.0598   -0.0201   -0.0074   -0.0028
//   -0.0150   -0.1495   -0.0504   -0.0184   -0.0071
//   -0.0006   -0.0056   -0.1141   -0.0418   -0.0161
//   -0.0000   -0.0001   -0.0026   -0.0925   -0.0356
//   -0.0000   -0.0000   -0.0000   -0.0014   -0.0775
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    CM daFonseca, J Petronilho,
//    Explicit Inverses of Some Tridiagonal Matrices,
//    Linear Algebra and Its Applications,
//    Volume 325, 2001, pages 7-21.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LESP_INVERSE[N*N], the inverse of the matrix.
//
{
  double *a;
  int i;
  double *x;
  double *y;
  double *z;

  x = new double[n-1];
  for ( i = 0; i < n - 1; i++ )
  {
    x[i] = 1.0 / ( double ) ( i + 2 );
  }

  y = new double[n];
  for ( i = 0; i < n; i++ )
  {
    y[i] = ( double ) ( - 2 * i - 5 );
  }

  z = new double[n-1];
  for ( i = 0; i < n - 1; i++ )
  {
    z[i] = ( double ) ( i + 2 );
  }

  a = triv_inverse ( n, x, y, z );

  delete [] x;
  delete [] y;
  delete [] z;

  return a;
}
//****************************************************************************80

double *lietzke ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LIETZKE returns the LIETZKE matrix.
//
//  Formula:
//
//    A(I,J) = N - abs ( I - J )
//
//  Example:
//
//    N = 5
//
//     5  4  3  2  1
//     4  5  4  3  2
//     3  4  5  4  3
//     2  3  4  5  4
//     1  2  3  4  5
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    det ( A ) = ( n + 1 ) * 2^( n - 2 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    M Lietzke, R Stoughton, Marjorie Lietzke,
//    A Comparison of Seeral Method for Inverting Large Symmetric
//    Positive Definite Matrics,
//    Mathematics of Computation,
//    Volume 18, Number 87, pages 449-456.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LIETZKE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = ( double ) ( n - abs ( i - j ) );
    }
  }
  return a;
}
//****************************************************************************80

double lietzke_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LIETZKE_CONDITION returns the L1 condition of the LIETZKE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LIETZKE_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  int i;
  int k;
  int s;
  double value;

  s = 0;
  k = n;
  for ( i = 1; i <= n; i++ )
  {
    s = s + k;
    if ( ( i % 2 ) == 1 )
    {
      k = k - 1;
    }
  }
  a_norm = ( double ) ( s );
  if ( n == 1 )
  {
    b_norm = 0.25;
  }
  else if ( n == 2 )
  {
    b_norm = 5.0 / 6.0;
  }
  else
  {
    b_norm = 2.0;
  }
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double lietzke_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LIETZKE_DETERMINANT returns the determinant of the LIETZKE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LIETZKE_DETERMINANT, the determinant..
//
{
  double determ;

  determ = ( double ) ( ( n + 1 ) * i4_power ( 2, n - 2 ) );
    
  return determ;
}
//****************************************************************************80

double *lietzke_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LIETZKE_INVERSE returns the inverse of the LIETZKE matrix.
//
//  Example:
//
//    N = 5
//
//   0.5833   -0.5000         0         0    0.0833
//  -0.5000    1.0000   -0.5000         0         0
//        0   -0.5000    1.0000   -0.5000         0
//        0         0   -0.5000    1.0000   -0.5000
//   0.0833         0         0   -0.5000    0.5833
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LIETZKE_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  a[0+0*n] = ( double ) ( n + 2 ) / ( double ) ( 2 * n + 2 );
  for ( i = 1; i < n - 1; i++ )
  {
    a[i+i*n] = 1.0;
  }
  a[n-1+(n-1)*n] = ( double ) ( n + 2 ) / ( double ) ( 2 * n + 2 );

  if ( n == 2 )
  {
    for ( i = 0; i < n - 1; i++ )
    {
      a[i+(i+1)*n] = - 1.0 / 3.0;
    }
    for ( i = 1; i < n; i++ )
    {
      a[i+(i-1)*n] = - 1.0 / 3.0;
    }
  }
  else
  {
    for ( i = 0; i < n - 1; i++ )
    {
      a[i+(i+1)*n] = - 0.5;
    }
    for ( i = 1; i < n; i++ )
    {
      a[i+(i-1)*n] = - 0.5;
    }
  }

  a[0  +(n-1)*n] = 1.0 / ( double ) ( 2 * n + 2 );
  a[n-1+ 0   *n] = 1.0 / ( double ) ( 2 * n + 2 );

  return a;
}
//****************************************************************************80

double *line_adj ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_ADJ returns the LINE_ADJ matrix.
//
//  Discussion:
//
//    The matrix describes the adjacency of points on a line.
//
//  Example:
//
//    N = 5
//
//    0  1  0  0  0
//    1  0  1  0  0
//    0  1  0  1  0
//    0  0  1  0  1
//    0  0  0  1  0
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is tridiagonal.
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 3.
//
//    A is an adjacency matrix for a set of points arranged in a line.
//
//    A has a zero diagonal.
//
//    A is a zero/one matrix.
//
//    The row and column sums are all 2, except for the first and last
//    rows and columns which have a sum of 1.
//
//    A is singular if N is odd.
//
//    det ( A ) = 0, -1, 0, +1, as mod ( N, 4 ) = 1, 2, 3 or 0.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LINE_ADJ[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == i - 1 )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == i + 1 )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double line_adj_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_ADJ_DETERMINANT returns the determinant of the LINE_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LINE_ADJ_DETERMINANT, the determinant.
//
{
  double determ;

       if ( ( n % 4 ) == 1 )
  {
    determ =   0.0;
  }
  else if ( ( n % 4 ) == 2 )
  {
    determ = - 1.0;
  }
  else if ( ( n % 4 ) == 3 )
  {
    determ =   0.0;
  }
  else if ( ( n % 4 ) == 0 )
  {
    determ = + 1.0;
  }
  return determ;
}
//****************************************************************************80

double *line_adj_eigen_right ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_ADJ_EIGEN_RIGHT returns the right eigenvectors of the LINE_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LINE_ADJ_EIGEN_RIGHT[N*N], the right eigenvector matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( ( i + 1 ) * ( j + 1 ) ) 
        * r8_pi / ( double ) ( n + 1 );
      a[i+j*n] = sqrt ( 2.0 / ( double ) ( n + 1 ) ) * sin ( angle );
    }
  }
  return a;
}
//****************************************************************************80

double *line_adj_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_ADJ_EIGENVALUES returns the eigenvalues of the LINE_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LINE_ADJ_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  int i;
  double *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 1 );
    lambda[i] = 2.0 * cos ( angle );
  }
  return lambda;
}
//****************************************************************************80

double *line_adj_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_ADJ_INVERSE returns the inverse of the LINE_ADJ matrix.
//
//  Example:
//
//    N = 6:
//
//      0     1     0   -1    0    1
//      1     0     0    0    0    0
//      0     0     0    1    0   -1
//     -1     0     1    0    0    0
//      0     0     0    0    0    1
//      1     0    -1    0    1    0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    17 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LINE_ADJ_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double p;

  if ( ( n % 2 ) == 1 )
  {
    cerr << "\n";
    cerr << "LINE_ADJ_INVERSE - Fatal error!\n";
    cerr << "  The matrix is singular for odd N.\n";
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 1; i <= n; i++ )
  {
    if ( ( i % 2 ) == 1 )
    {
      for ( j = i; j <= n - 1; j = j + 2 )
      {
        if ( j == i )
        {
          p = 1.0;
        }
        else
        {
          p = - p;
        }

        a[i-1+(j  )*n] = p;
        a[j  +(i-1)*n] = p;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *line_adj_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_ADJ_NULL_LEFT returns a left null vector of the LINE_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double LINE_ADJ_NULL_LEFT[M], a null vector
//
{
  int i;
  double *x;

  if ( ( m % 2 ) == 0 )
  {
    cerr << "\n";
    cerr << "LINE_ADJ_NULL_LEFT - Fatal error!\n";
    cerr << "  For M even, there is no null vector.\n";
    exit ( 1 );
  }

  x = new double[m];

  for ( i = 0; i < m; i = i + 4 )
  {
    x[i] = 1.0;
  }
  for ( i = 1; i < m; i = i + 4 )
  {
    x[i] = 0.0;
  }
  for ( i = 2; i < m; i = i + 4 )
  {
    x[i] = -1.0;
  }
  for ( i = 3; i < m; i = i + 4 )
  {
    x[i] =  0.0;
  }
  return x;
}
//****************************************************************************80

double *line_adj_null_right ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_ADJ_NULL_RIGHT returns a right null vector of the LINE_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double LINE_ADJ_NULL_RIGHT[N], a null vector
//
{
  int i;
  double *x;

  if ( ( n % 2 ) == 0 )
  {
    cerr << "\n";
    cerr << "LINE_ADJ_NULL_RIGHT - Fatal error!\n";
    cerr << "  For N even, there is no null vector.\n";
    exit ( 1 );
  }

  x = new double[n];

  for ( i = 0; i < n; i = i + 4 )
  {
    x[i] = 1.0;
  }
  for ( i = 1; i < n; i = i + 4 )
  {
    x[i] = 0.0;
  }
  for ( i = 2; i < n; i = i + 4 )
  {
    x[i] = -1.0;
  }
  for ( i = 3; i < n; i = i + 4 )
  {
    x[i] =  0.0;
  }
  return x;
}
//****************************************************************************80

double *line_loop_adj ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_LOOP_ADJ returns the LINE_LOOP_ADJ matrix.
//
//  Discussion:
//
//    The matrix describes the adjacency of points on a loop.
//
//  Example:
//
//    N = 5
//
//    1  1  0  0  0
//    1  1  1  0  0
//    0  1  1  1  0
//    0  0  1  1  1
//    0  0  0  1  1
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is tridiagonal.
//
//    A is a special case of the TRIS or tridiagonal scalar matrix.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 3.
//
//    A is an adjacency matrix for a set of points arranged in a line.
//
//    A is a zero/one matrix.
//
//    The row and column sums are all 3, except for the first and last
//    rows and columns which have a sum of 2.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LINE_LOOP_ADJ[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == i - 1 )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == i )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == i + 1 )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double line_loop_adj_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_LOOP_ADJ_DETERMINANT returns the determinant of the LINE_LOOP_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LINE_LOOP_ADJ_DETERMINANT, the determinant.
//
{
  double angle;
  double determ;
  int i;
  const double r8_pi = 3.141592653589793;

  if ( ( n % 2 ) == 1 )
  {
    determ = 0.0;
  }
  else
  {
    determ = 1.0;
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 1 );
      determ = determ * ( 1.0 + 2.0 * cos ( angle ) );
    }
  }
  return determ;
}
//****************************************************************************80

double *line_loop_adj_eigen_right ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_LOOP_ADJ_EIGEN_RIGHT returns the right eigenvectors of the LINE_LOOP matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LINE_LOOP_ADJ_EIGEN_RIGHT[N*N], the right eigenvector matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( ( i + 1 ) * ( j + 1 ) ) 
        * r8_pi / ( double ) ( n + 1 );
      a[i+j*n] = sqrt ( 2.0 / ( double ) ( n + 1 ) ) * sin ( angle );
    }
  }
  return a;
}
//****************************************************************************80

double *line_loop_adj_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LINE_LOOP_ADJ_EIGENVALUES returns the eigenvalues of the LINE_LOOP_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double *LINE_LOOP_ADJ_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  int i;
  double *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( n + 1 );
    lambda[i] = 1.0 + 2.0 * cos ( angle );
  }

  return lambda;
}
//****************************************************************************80

double *loewner ( double w[], double x[], double y[], double z[], int n )

//****************************************************************************80
//
//  Purpose:
//
//    LOEWNER returns the LOEWNER matrix.
//
//  Formula:
//
//    A(I,J) = ( W(I) - X(J) ) / ( Y(I) - Z(J) )
//
//  Example:
//
//    N = 3
//    W = (/ 8, 4, 9 /)
//    X = (/ 1, 2, 3 /)
//    Y = (/ 9, 6, 4 /)
//    Z = (/ 2, 3, 1 /)
//
//    A =
//
//    8 - 1  8 - 2  8 - 3
//    -----  -----  -----
//    9 - 2  9 - 3  9 - 1
//
//    4 - 1  4 - 2  4 - 3
//    -----  -----  -----
//    6 - 2  6 - 3  6 - 1
//
//    9 - 1  9 - 2  9 - 3
//    -----  -----  -----
//    4 - 2  4 - 3  4 - 1
//
//    =
//
//    7/7  6/6  5/8
//
//    3/4  2/3  1/5
//
//    8/2  7/1  6/3
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double W[N], X[N], Y[N], Z[N], vectors defining 
//    the matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double LOEWNER[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];
 
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( y[i] - z[j] == 0.0 )
      {
        cerr << "\n";
        cerr << "LOEWNER - Fatal error!\n";
        cerr << "  Y(I) = Z(J).\n";
        exit ( 1 );
      }
      a[i+j*n] = ( w[i] - x[j] ) / ( y[i] - z[j] );
    }
  }
  return a;
}
//****************************************************************************80

double *lotkin ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    LOTKIN returns the LOTKIN matrix.
//
//  Formula:
//
//    if ( I = 1 )
//      A(I,J) = 1
//    else
//      A(I,J) = 1 / ( I + J - 1 )
//
//  Example:
//
//    N = 5
//
//     1   1   1   1   1
//    1/2 1/3 1/4 1/5 1/6
//    1/3 1/4 1/5 1/6 1/7
//    1/4 1/5 1/6 1/7 1/8
//    1/5 1/6 1/7 1/8 1/9
//
//  Properties:
//
//    A is the Hilbert matrix with the first row set to all 1's.
//
//    A is generally not symmetric: A' /= A.
//
//    A is ill-conditioned.
//
//    A has many negative eigenvalues of small magnitude.
//
//    The inverse of A has all integer elements, and is known explicitly.
//
//    For N = 6, the eigenvalues are:
//       2.132376,
//      -0.2214068,
//      -0.3184330 D-1,
//      -0.8983233 D-3,
//      -0.1706278 D-4,
//      -0.1394499 D-6.
//
//    det ( A(N) ) = ( -1 )^(N-1) / DELTA(N)
//
//    where
//
//      DELTA(N) = CHOOSE ( 2*N-2, N-2 ) * CHOOSE ( 2*N-2, N-1 )
//        * ( 2*N-1) * DELTA(N-1),
//      DELTA(1) = 1.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Max Lotkin,
//    A set of test matrices,
//    Mathematics Tables and Other Aids to Computation,
//    Volume 9, 1955, pages 153-161.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double LOTKIN[M*N], the matrix.
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
      if ( i == 0 )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = 1.0 / ( double ) ( i + j + 1 );
      }
    }
  }
  return a;
}
//****************************************************************************80

double lotkin_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LOTKIN_DETERMINANT returns the determinant of the LOTKIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LOTKIN_DETERMINANT, the determinant.
//
{
  double delta;
  double determ;
  int i;

  delta = 1.0;

  for ( i = 2; i <= n; i++ )
  {
    delta = - r8_choose ( 2 * i - 2, i - 2 ) * r8_choose ( 2 * i - 2, i - 1 ) 
      * ( 2 * i - 1 ) * delta;
  }

  determ = 1.0 / delta;

  return determ;
}
//****************************************************************************80

double *lotkin_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    LOTKIN_INVERSE returns the inverse of the LOTKIN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double LOTKIN[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == 0 )
      {
        a[i+j*n] = r8_mop ( n - i - 1 ) * r8_choose ( n + i, i ) 
          * r8_choose ( n, i + 1 );
      }
      else
      {
        a[i+j*n] = r8_mop ( i - j + 1 ) * ( double ) ( i + 1 ) 
          * r8_choose ( i + j + 1, j ) * r8_choose ( i + j, j - 1 ) 
          * r8_choose ( n + i, i + j + 1 ) 
          * r8_choose ( n + j, i + j + 1 );
      }
    }
  }
  return a;
}
//****************************************************************************80

double *markov_random ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    MARKOV_RANDOM returns the MARKOV_RANDOM matrix.
//
//  Discussion:
//
//    A Markov matrix, also called a "stochastic" matrix, is distinguished
//    by two properties:
//
//    * All matrix entries are nonnegative;
//    * The sum of the entries in each row is 1.
//
//    A "transition matrix" is the transpose of a Markov matrix, and
//    has column sums equal to 1.
//
//  Example:
//
//    N = 4
//
//    1/10  2/10  3/10  4/10
//    1     0     0     0
//    5/10  2/10  3/10  0
//    2/10  2/10  2/10  4/10
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    0 <= A(I,J) <= 1.0 for every I and J.
//
//    The sum of the entries in each row of A is 1.
//
//    Because it has a constant row sum of 1,
//    A has an eigenvalue of 1, and
//    a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    All the eigenvalues of A have modulus no greater than 1.
//
//    The eigenvalue 1 lies on the boundary of all the Gerschgorin rowsum disks.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double MARKOV_RANDOM[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  double row_sum;
  int seed;

  seed = key;
  a = r8mat_uniform_01_new ( n, n, seed );

  for ( i = 0; i < n; i++ )
  {
    row_sum = 0.0;
    for ( j = 0; j < n; j++ )
    {
      row_sum = row_sum + a[i+j*n];
    }
    for ( j = 0; j < n; j++ )
    {
      a[i+j*n] = a[i+j*n] / row_sum;
    }
  }
  return a;
}
//****************************************************************************80

double *maxij ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    MAXIJ returns the MAXIJ matrix.
//
//  Discussion:
//
//    This matrix is occasionally known as the "Boothroyd MAX" matrix.
//
//  Formula:
//
//    A(I,J) = max(I,J)
//
//  Example:
//
//    N = 5
//
//    1 2 3 4 5
//    2 2 3 4 5
//    3 3 3 4 5
//    4 4 4 4 5
//    5 5 5 5 5
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    The inverse of A is tridiagonal.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double MAXIJ[M*N], the matrix.
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
      a[i+j*m] = ( double ) ( i4_max ( i + 1, j + 1 ) );
    }
  }
  return a;
}
//****************************************************************************80

double maxij_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MAXIJ_CONDITION returns the L1 condition of the MAXIJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MAXIJ_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = ( double ) ( n * n );

  if ( n == 1 )
  {
    b_norm = 1.0;
  }
  else if ( n == 2 )
  {
    b_norm = 2.0;
  }
  else
  {
    b_norm = 4.0;
  }

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double maxij_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MAXIJ_DETERMINANT returns the determinant of the MAXIJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MAXIJ_DETERMINANT, the determinant.
//
{
  double determ;

  determ = ( double ) ( n );

  return determ;
}
//****************************************************************************80

double *maxij_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MAXIJ_INVERSE returns the inverse of the MAXIJ matrix.
//
//  Formula:
//
//    if ( I = 1 and J = 1 )
//      A(I,J) = -1
//    else if ( I = N and J = N )
//      A(I,J) = -(N-1)/N
//    else if ( I = J )
//      A(I,J) = -2
//    else if ( J = I-1 or J = I + 1 )
//      A(I,J) =  1
//    else
//      A(I,J) =  0
//
//  Example:
//
//    N = 5
//
//    -1  1  0  0   0
//     1 -2  1  0   0
//     0  1 -2  1   0
//     0  0  1 -2   1
//     0  0  0  1 -4/5
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is "almost" equal to the second difference matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MAXIJ_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == i )
      {
        if ( i == 0 )
        {
          a[i+j*n] = - 1.0;
        }
        else if ( i < n  - 1 )
        {
          a[i+j*n] = - 2.0;
        }
        else
        {
          a[i+j*n] = - ( double ) ( n - 1 ) / ( double ) ( n );
        }
      }
      else if ( j == i - 1 || j == i + 1 )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

void maxij_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAXIJ_PLU returns the PLU factors of the MAXIJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i4_wrap ( j - i, 1, n ) == 1 )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  i = 0;
  j = 0;
  l[i+j*n] = 1.0;

  j = 0;
  for ( i = 1; i < n; i++ )
  {
    l[i+j*n] = ( double ) ( i ) / ( double ) ( n );
  }

  for ( j = 1; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      l[i+j*n] = 0.0;
    }
    l[j+j*n] = 1.0;
    for ( i = j + 1; i < n; i++ )
    {
      l[i+j*n] = 0.0;
    }
  }

  i = 0;
  for ( j = 0; j < n; j++ )
  {
    u[i+j*n] = ( double ) ( n );
  }

  for ( i = 1; i < n; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      u[i+j*n] = 0.0;
    }
    for ( j = i; j < n; j++ )
    {
      u[i+j*n] = ( double ) ( j + 1 - i );
    }
  }

  return;
}
//****************************************************************************80

int mertens ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MERTENS evaluates the Mertens function.
//
//  Discussion:
//
//    The Mertens function M(N) is the sum from 1 to N of the Moebius
//    function MU.  That is,
//
//    M(N) = sum ( 1 <= I <= N ) MU(I)
//
//        N   M(N)
//        --  ----
//         1     1
//         2     0
//         3    -1
//         4    -1
//         5    -2
//         6    -1
//         7    -2
//         8    -2
//         9    -2
//        10    -1
//        11    -2
//        12    -2
//       100     1
//      1000     2
//     10000   -23
//    100000   -48
//
//    The determinant of the Redheffer matrix of order N is equal
//    to the Mertens function M(N).
// 
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 October 2007
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    M Deleglise, J Rivat,
//    Computing the Summation of the Moebius Function,
//    Experimental Mathematics,
//    Volume 5, 1996, pages 291-295.
//
//    Eric Weisstein,
//    CRC Concise Encyclopedia of Mathematics,
//    CRC Press, 2002,
//    Second edition,
//    ISBN: 1584883472,
//    LC: QA5.W45
//
//  Parameters:
//
//    Input, int N, the argument.
//
//    Output, int MERTENS, the value.
//
{
  int i;
  int value;

  value = 0;

  for ( i = 1; i <= n; i++ )
  {
    value = value + moebius ( i );
  }
  return value;
}
//****************************************************************************80

void mertens_values ( int &n_data, int &n, int &c )

//****************************************************************************80
//
//  Purpose:
//
//    MERTENS_VALUES returns some values of the Mertens function.
//
//  Discussion:
//
//    The Mertens function M(N) is the sum from 1 to N of the Moebius
//    function MU.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 October 2007
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    M Deleglise, J Rivat,
//    Computing the Summation of the Moebius Function,
//    Experimental Mathematics,
//    Volume 5, 1996, pages 291-295.
//
//    Eric Weisstein,
//    CRC Concise Encyclopedia of Mathematics,
//    CRC Press, 2002,
//    Second edition,
//    ISBN: 1584883472,
//    LC: QA5.W45.
//
//  Input:
//
//    int &N_DATA, on first call, N_DATA should be set to 0.
//
//  Output:
//
//    int &N_DATA, the input value of N_DATA is
//    incremented and that test data item is returned, if available.  When
//    there is no more test data, N_DATA is set to 0.
//
//    Output, int &N, the argument of the Mertens function.
//
//    Output, int &C, the value of the Mertens function.
//
{
# define N_MAX 15

  static int c_vec[N_MAX] = {
      1,   0,  -1,   -1,  -2,  -1,  -2,  -2,   -2,  -1,
     -2,  -2,   1,    2, -23 };
  static int n_vec[N_MAX] = {
      1,   2,   3,   4,   5,   6,   7,   8,   9,  10,
     11,  12,  100, 1000, 10000 };

  if ( n_data < 0 )
  {
    n_data = 0;
  }

  if ( N_MAX <= n_data )
  {
    n_data = 0;
    n = 0;
    c = 0;
  }
  else
  {
    n = n_vec[n_data];
    c = c_vec[n_data];
    n_data = n_data + 1;
  }

  return;
# undef N_MAX
}
//****************************************************************************80

double *milnes ( int m, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    MILNES returns the MILNES matrix.
//
//  Formula:
//
//    If ( I <= J )
//      A(I,J) = 1
//    else
//      A(I,J) = X(J)
//
//  Example:
//
//    M = 5, N = 5, X = ( 4, 7, 3, 8 )
//
//    1 1 1 1 1
//    4 1 1 1 1
//    4 7 1 1 1
//    4 7 3 1 1
//    4 7 3 8 1
//
//    M = 3, N = 6, X = ( 5, 7 )
//
//    1 1 1 1 1
//    5 1 1 1 1
//    5 7 1 1 1
//
//    M = 5, N = 3, X = ( 5, 7, 8 )
//
//    1 1 1
//    5 1 1
//    5 7 1
//    5 7 8
//    5 7 8
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    det ( A ) = ( 1 - X(1) ) * ( 1 - X(2) ) * ... * ( 1 - X(N-1) ).
//
//    A is singular if and only if X(I) = 1 for any I.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double X[*], the lower column values.
//    If M <= N, then X should be dimensioned M-1.
//    If N < M, X should be dimensioned N.
//
//    Output, double MILNES[M*N], the matrix.
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
      if ( i <= j )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = x[j];
      }
    }
  }

  return a;
}
//****************************************************************************80

double milnes_determinant ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    MILNES_DETERMINANT returns the determinant of the MILNES matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N-1], the lower column values.
//
//    Output, double MILNES_DETERMINANT, the determinant.
//
{
  double determ;
  int i;

  determ = 1.0;
  for ( i = 0; i < n - 1; i++ )
  {
    determ = determ * ( 1.0 - x[i] );
  }

  return determ;
}
//****************************************************************************80

double *milnes_inverse ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    MILNES_INVERSE returns the inverse of the MILNES matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double X[N-1], the lower column values.
//
//    Output, double MILNES_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j && i != n - 1 )
      {
        a[i+j*n] = 1.0 / ( 1.0 - x[i] );
      }
      else if ( j == i + 1 && i != n - 1 )
      {
        a[i+j*n] = - 1.0 / ( 1.0 - x[i] );
      }
      else if ( i == n - 1 && j != 0 && j != n - 1 )
      {
        a[i+j*n] = ( x[j-1] - x[j] ) / 
          ( ( 1.0 - x[j] ) * ( 1.0 - x[j-1] ) );
      }
      else if ( i == n - 1 && j == 0 )
      {
        a[i+j*n] = - x[0] / ( 1.0 - x[0] );
      }
      else if ( i == n - 1 && j == n - 1 )
      {
        a[i+j*n] = 1.0 / ( 1.0 - x[n-2] );
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }

  return a;
}
//****************************************************************************80

double *minij ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    MINIJ returns the MINIJ matrix.
//
//  Discussion:
//
//    See page 158 of the Todd reference.
//
//  Formula:
//
//    A(I,J) = min ( I, J )
//
//  Example:
//
//    N = 5
//
//    1 1 1 1 1
//    1 2 2 2 2
//    1 2 3 3 3
//    1 2 3 4 4
//    1 2 3 4 5
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is positive definite.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    The inverse of A is tridiagonal.
//
//    The eigenvalues of A are
//
//      LAMBDA(I) = 0.5 / ( 1 - cos ( ( 2 * I - 1 ) * pi / ( 2 * N + 1 ) ) ),
//
//    For N = 12, the characteristic polynomial is
//      P(X) = X^12 - 78 X^11 + 1001 X^10 - 5005 X^9 + 12870 X^8
//        - 19448 X^7 + 18564 X^6 - 11628 X^5 + 4845 X^4 - 1330 X^3
//        + 231 X^2 - 23 X + 1.
//
//    (N+1)*ONES(N) - A also has a tridiagonal inverse.
//
//    Gregory and Karney consider the matrix defined by
//
//      B(I,J) = N + 1 - MAX(I,J)
//
//    which is equal to the MINIJ matrix, but with the rows and
//    columns reversed.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Daniel Rutherford,
//    Some continuant determinants arising in physics and chemistry II,
//    Proceedings of the Royal Society Edinburgh,
//    Volume 63, A, 1952, pages 232-241.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double MINIJ[M*N], the matrix.
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
      a[i+j*m] = ( double ) ( i4_min ( i + 1, j + 1 ) );
    }
  }
  return a;
}
//****************************************************************************80

double minij_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MINIJ_CONDITION returns the L1 condition of the MINIJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MINIJ_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = ( double ) ( n * ( n + 1 ) ) / 2.0;
  if ( n == 1 )
  {
    b_norm = 1.0;
  }
  else if ( n == 2 )
  {
    b_norm = 3.0;
  }
  else
  {
    b_norm = 4.0;
  }

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double minij_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MINIJ_DETERMINANT returns the determinant of the MINIJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MINIJ_DETERMINANT, the determinant.
//
{
  double angle;
  double determ;
  int i;
  const double r8_pi = 3.141592653589793;

  determ = 1.0;

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( 2 * i + 1 ) * r8_pi / ( double ) ( 2 * n + 1 );
    determ = determ * 0.5 / ( 1.0 - cos ( angle ) );
  }
  return determ;
}
//****************************************************************************80

double *minij_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MINIJ_EIGENVALUES returns the eigenvalues of the MINIJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MINIJ_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  int i;
  double *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( 2 * i + 1 ) * r8_pi / ( double ) ( 2 * n + 1 );
    lambda[i] = 0.5 / ( 1.0 - cos ( angle ) );
  }
  return lambda;
}
//****************************************************************************80

double *minij_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MINIJ_INVERSE returns the inverse of the MINIJ matrix.
//
//  Formula:
//
//    A(I,J) =  -1  if J=I-1 or J=I+1
//    A(I,J) =   2  if J=I and J is not N.
//    A(I,J) =   1  if J=I and J=N.
//    A(I,J) =   0  otherwise
//
//  Example:
//
//    N = 5
//
//     2 -1  0  0  0
//    -1  2 -1  0  0
//     0 -1  2 -1  0
//     0  0 -1  2 -1
//     0  0  0 -1  1
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is banded, with bandwidth 3.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is "almost" equal to the second difference matrix,
//    as computed by DIF.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MINIJ_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        if ( i < n - 1 )
        {
          a[i+j*n] = 2.0;
        }
        else
        {
          a[i+j*n] = 1.0;
        }
      }
      else if ( i == j + 1 || i == j - 1 )
      {
        a[i+j*n] = - 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *minij_llt ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MINIJ_LLT returns the Cholesky factor of the MINIJ matrix.
//
//  Example:
//
//    N = 5
//
//    1  0  0  0  0
//    1  1  0  0  0
//    1  1  1  0  0
//    1  1  1  1  0
//    1  1  1  1  1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MINIJ_LLT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j <= i; j++ )
    {
      a[i+j*n] = 1.0;
    }
    for ( j = i + 1; j < n; j++ )
    {
      a[i+j*n] = 0.0;
    }
  }
  return a;
}
//****************************************************************************80

void minij_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    MINIJ_PLU returns the PLU factors of the MINIJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      l[i+j*n] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      l[i+j*n] = 1.0;
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      u[i+j*n] = 1.0;
    }
    for ( i = j + 1; i < n; i++ )
    {
      u[i+j*n] = 0.0;
    }
  }

  return;
}
//****************************************************************************80

int moebius ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MOEBIUS returns the value of MU(N), the Moebius function of N.
//
//  Discussion:
//
//    MU(N) is defined as follows:
//
//      MU(N) = 1 if N = 1;
//              0 if N is divisible by the square of a prime;
//              (-1)**K, if N is the product of K distinct primes.
//
//  First values:
//
//     N  MU(N)
//
//     1    1
//     2   -1
//     3   -1
//     4    0
//     5   -1
//     6    1
//     7   -1
//     8    0
//     9    0
//    10    1
//    11   -1
//    12    0
//    13   -1
//    14    1
//    15    1
//    16    0
//    17   -1
//    18    0
//    19   -1
//    20    0
//
//  Note:
//
//    As special cases, MU(N) is -1 if N is a prime, and MU(N) is 0
//    if N is a square, cube, etc.
//
//  Formula:
//
//    The Moebius function is related to Euler's totient function:
//
//      PHI(N) = Sum ( D divides N ) MU(D) * ( N / D ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    01 March 1999
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the value to be analyzed.
//
//    Output, int MOEBIUS, the value of MU(N).
//    If N is less than or equal to 0, or there was not enough internal 
//    space for factoring, MOEBIUS is returned as -1.
//
{
# define FACTOR_MAX 20

  int factor[FACTOR_MAX];
  int i;
  int nfactor;
  int nleft;
  int power[FACTOR_MAX];
  int value;

  if ( n <= 0 )
  {
    return (-1);
  }

  if ( n == 1 )
  {
    return 1;
  }
//
//  Factor N.
//
  i4_factor ( n, FACTOR_MAX, nfactor, factor, power, nleft );

  if ( nleft != 1 )
  {
    cerr << "\n";
    cerr << "MOEBIUS - Fatal error!\n";
    cerr <<  "  Not enough factorization space.\n";
    return (-1);
  }

  value = 1;

  for ( i = 0; i < nfactor; i++ )
  {
    value = -value;

    if ( 1 < power[i] )
    {
      return 0;
    }
  }

  return value;
# undef FACTOR_MAX
}
//****************************************************************************80

void moebius_values ( int &n_data, int &n, int &c )

//****************************************************************************80
//
//  Purpose:
//
//    MOEBIUS_VALUES returns some values of the Moebius function.
//
//  Discussion:
//
//    MU(N) is defined as follows:
//
//      MU(N) = 1 if N = 1;
//              0 if N is divisible by the square of a prime;
//              (-1)**K, if N is the product of K distinct primes.
//
//    In Mathematica, the function can be evaluated by:
//
//      MoebiusMu[n]
//
//  First values:
//
//     N  MU(N)
//
//     1    1
//     2   -1
//     3   -1
//     4    0
//     5   -1
//     6    1
//     7   -1
//     8    0
//     9    0
//    10    1
//    11   -1
//    12    0
//    13   -1
//    14    1
//    15    1
//    16    0
//    17   -1
//    18    0
//    19   -1
//    20    0
//
//  Note:
//
//    As special cases, MU(N) is -1 if N is a prime, and MU(N) is 0
//    if N is a square, cube, etc.
//
//  Formula:
//
//    The Moebius function is related to Euler's totient function:
//
//      PHI(N) = Sum ( D divides N ) MU(D) * ( N / D ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 February 2003
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Milton Abramowitz, Irene Stegun,
//    Handbook of Mathematical Functions,
//    National Bureau of Standards, 1964,
//    ISBN: 0-486-61272-4,
//    LC: QA47.A34.
//
//    Stephen Wolfram,
//    The Mathematica Book,
//    Fourth Edition,
//    Cambridge University Press, 1999,
//    ISBN: 0-521-64314-7,
//    LC: QA76.95.W65.
//
//  Input:
//
//    int &N_DATA, on first call, N_DATA should be set to 0.
//
//  Output:
//
//    int &N_DATA, the input value of N_DATA is
//    incremented and that test data item is returned, if available.  When
//    there is no more test data, N_DATA is set to 0.
//
//    Output, int &N, the argument of the Moebius function.
//
//    Output, int &C, the value of the Moebius function.
//
{
# define N_MAX 20

  static int c_vec[N_MAX] = {
      1,  -1,  -1,   0,  -1,   1,  -1,   0,   0,   1,
     -1,   0,  -1,   1,   1,   0,  -1,   0,  -1,   0 };

  static int n_vec[N_MAX] = {
      1,   2,   3,   4,   5,   6,   7,   8,   9,  10,
     11,  12,  13,  14,  15,  16,  17,  18,  19,  20 };

  if ( n_data < 0 )
  {
    n_data = 0;
  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )
  {
    n_data = 0;
    n = 0;
    c = 0;
  }
  else
  {
    n = n_vec[n_data-1];
    c = c_vec[n_data-1];
  }

  return;
# undef N_MAX
}
//****************************************************************************80

double *moler1 ( double alpha, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER1 returns the MOLER1 matrix.
//
//  Formula:
//
//    If ( I = J )
//      A(I,J) = min ( I-1, J-1 ) * ALPHA^2 + 1
//    else
//      A(I,J) = min ( I-1, J-1 ) * ALPHA^2 + ALPHA
//
//  Example:
//
//    ALPHA = 2, N = 5
//
//    1 2  2  2  2
//    2 5  6  6  6
//    2 6  9 10 10
//    2 6 10 13 14
//    2 6 10 14 17
//
//  Properties:
//
//    Successive elements of each diagonal increase by an increment of ALPHA^2.
//
//    A is the product of B' * B, where B is the matrix returned by
//
//      CALL TRIW ( ALPHA, N-1, N, B ).
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is positive definite.
//
//    If ALPHA = -1, A(I,J) = min ( I, J ) - 2, A(I,I)=I.
//
//    A has one small eigenvalue.
//
//    If ALPHA is integral, then A is integral.
//    If A is integral, then det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Nash,
//    Compact Numerical Methods for Computers: Linear Algebra and
//    Function Minimisation,
//    Second Edition,
//    Taylor & Francis, 1990,
//    ISBN: 085274319X,
//    LC: QA184.N37.
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double MOLER1[M*N], the matrix.
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
      if ( i == j )
      {
        a[i+j*m] = ( double ) ( i4_min ( i, j ) ) * alpha * alpha + 1.0;
      }
      else
      {
        a[i+j*m] = ( double ) ( i4_min ( i, j ) ) * alpha * alpha + alpha;
      }
    }
  }
  return a;
}
//****************************************************************************80

double moler1_determinant ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER1_DETERMINANT returns the determinant of the MOLER1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int N, the order of the matrix.
//
//    Output, double MOLER1_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *moler1_inverse ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER1_INVERSE returns the inverse of the MOLER1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int N, the order of the matrix.
//
//    Output, double MOLER1_INVERSE[N*N], the matrix.
//
{
  double *a;
  double dot;
  int i;
  int j;
  int k;
  double *v;

  v = new double[n];

  v[0] = 1.0;
  v[1] = - alpha;
  for ( i = 2; i < n; i++ )
  {
    v[i] = - ( alpha - 1.0 ) * v[i-1];
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i <= j )
      {
        dot = 0.0;
        for ( k = 0; k < n - j; k++ )
        {
          dot = dot + v[k+j-i] * v[k];
        }
        a[i+j*n] = dot;
      }
      else
      {
        dot = 0.0;
        for ( k = 0; k < n - i; k++ )
        {
          dot = dot + v[k] * v[k+i-j];
        }
        a[i+j*n] = dot;
      }
    }
  }
//
//  Free memory.
//
  delete [] v;

  return a;
}
//*****************************************************************************/

double *moler1_llt ( double alpha, int n )

//*****************************************************************************/
//
//  Purpose:
//
//    MOLER1_LLT returns the lower triangular Cholesky factor of the MOLER1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int N, the order of the matrix.
//
//    Output, double MOLER_LLT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      a[i+j*n] = 0.0;
    }
    a[j+j*n] = 1.0;
    for ( i = j + 1; i < n; i++ )
    {
      a[i+j*n] = alpha;
    }
  }

  return a;
}
//****************************************************************************80

void moler1_plu ( double alpha, int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER1_PLU returns the PLU factors of the MOLER1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Nash,
//    Compact Numerical Methods for Computers: Linear Algebra and
//    Function Minimisation,
//    Second Edition,
//    Taylor & Francis, 1990,
//    ISBN: 085274319X,
//    LC: QA184.N37.
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        l[i+j*n] = 1.0;
      }
      else if ( j < i )
      {
        l[i+j*n] = alpha;
      }
      else
      {
        l[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        u[i+j*n] = 1.0;
      }
      else if ( i < j )
      {
        u[i+j*n] = alpha;
      }
      else
      {
        u[i+j*n] = 0.0;
      }
    }
  }

  return;
}
//****************************************************************************80

double *moler2 ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER2 returns the MOLER2 matrix.
//
//  Discussion:
//
//    This is a 5 by 5 matrix for which the challenge is to find the EXACT
//    eigenvalues and eigenvectors.
//
//  Formula:
//
//       -9     11    -21     63    -252
//       70    -69    141   -421    1684
//     -575    575  -1149   3451  -13801
//     3891  -3891   7782 -23345   93365
//     1024  -1024   2048  -6144   24572
//
//  Properties:
//
//    A is defective.
//
//    The Jordan normal form of A has just one block, with eigenvalue
//    zero, because A**k is nonzero for K = 0, 1, 2, 3, 4, but A**5=0.
//
//    det ( A ) = 0.
//
//    TRACE(A) = 0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double MOLER2[5*5], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[5*5] = {
     -9.0,     70.0,   -575.0,   3891.0,   1024.0,
     11.0,    -69.0,    575.0,  -3891.0,  -1024.0,
    -21.0,    141.0,  -1149.0,   7782.0,   2048.0,
     63.0,   -421.0,   3451.0, -23345.0,  -6144.0,
   -252.0,   1684.0, -13801.0,  93365.0,  24572.0 };
  int n = 5;

  a = r8mat_copy_new ( n, n, a_save );

  return a;
}
//****************************************************************************80

double moler2_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER2_DETERMINANT returns the determinant of the MOLER2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double MOLER2_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 0.0;

  return determ;
}
//****************************************************************************80

double *moler2_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER2_EIGENVALUES returns the eigenvalues of the MOLER2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double MOLER2_EIGENVALUES[5], the eigenvalues.
//
{
  double *lambda;
  int n = 5;

  lambda = r8vec_zero_new ( n );

  return lambda;
}
//****************************************************************************80

double *moler2_null_left ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER2_NULL_LEFT returns a left null vector for the MOLER2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double MOLER2_NULL_LEFT[5], the vector.
//
{
  int n = 5;
  double *x;
  static double x_save[5] = {
    4.0, -8.0, 20.0, -64.0, 255.0 };

  x = r8vec_copy_new ( n, x_save );

  return x;
}
//****************************************************************************80

double *moler2_null_right ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER2_NULL_RIGHT returns a right null vector for the MOLER2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double MOLER2_NULL_RIGHT[5], the vector.
//
{
  int n = 5;
  double *x;
  static double x_save[5] = {
    0.0, -21.0, 142.0, -973.0, -256.0 };

  x = r8vec_copy_new ( n, x_save );

  return x;
}
//****************************************************************************80

double *moler3 ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER3 returns the MOLER3 matrix.
//
//  Formula:
//
//    if ( I == J ) then
//      A(I,J) = I
//    else
//      A(I,J) = min(I,J) - 2
//
//  Example:
//
//    N = 5
//
//     1 -1 -1 -1 -1
//    -1  2  0  0  0
//    -1  0  3  1  1
//    -1  0  1  4  2
//    -1  0  1  2  5
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is positive definite.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A has a simple Cholesky factorization.
//
//    A has one small eigenvalue.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double MOLER3[M*N], the matrix.
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
      if ( i == j )
      {
        a[i+j*m] = ( double ) ( i + 1 );
      }
      else
      {
        a[i+j*m] = ( double ) ( i4_min ( i, j ) - 1 );
      }
    }
  }
  return a;
}
//****************************************************************************80

double moler3_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER3_DETERMINANT returns the determinant of the MOLER3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MOLER3_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *moler3_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER3_INVERSE returns the inverse of the MOLER3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MOLER3[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  double *l;
  double value;

  l = r8mat_zero_new ( n, n );

  for ( j = 0; j < n; j++ )
  {
    l[j+j*n] = 1.0;
    value = 1.0;
    for ( i = j + 1; i < n; i++ )
    {
      l[i+j*n] = value;
      value = value * 2.0;
    }
  }

  a = r8mat_zero_new ( n, n );
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      for ( k = 0; k < n; k++ )
      {
        a[i+j*n] = a[i+j*n] + l[k+i*n] * l[k+j*n];
      }
    }
  }
//
//  Free memory.
//
  delete [] l;

  return a;
}
//****************************************************************************80

double *moler3_llt ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER3_LLT returns the Cholesky factor of the MOLER3 matrix.
//
//  Example:
//
//    N = 5
//
//    1  0  0  0  0
//   -1  1  0  0  0
//   -1 -1  1  0  0
//   -1 -1 -1  1  0
//   -1 -1 -1 -1  1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double MOLER3_LLT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      a[i+j*n] = -1.0;
    }
    j = i;
    a[i+j*n] = 1.0;
    for ( j = i + 1; j < n; j++ )
    {
      a[i+j*n] = 0.0;
    }
  }
  return a;
}
//****************************************************************************80

void moler3_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER3_PLU returns the PLU factors of the MOLER3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < i; j++ )
    {
      l[i+j*n] = -1.0;
    }
    l[i+i*n] = 1.0;
    for ( j = i + 1; j < n; j++ )
    {
      l[i+j*n] = 0.0;
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      u[i+j*n] = -1.0;
    }
    u[j+j*n] = 1.0;
    for ( i = j + 1; i < n; i++ )
    {
      u[i+j*n] = 0.0;
    }
  }
  return;
}
//****************************************************************************80

double *moler4 ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER4 returns the MOLER4 matrix.
//
//  Example:
//
//    0  2  0 -1
//    1  0  0  0
//    0  1  0  0
//    0  0  1  0
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is the companion matrix of the polynomial X^4-2X^2+1=0.
//
//    A has eigenvalues -1, -1, +1, +1.
//
//    A can cause problems to a standard QR algorithm, which
//    can fail to converge.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double A(4,4), the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  double a_save[4*4] = {
   0.0,  1.0,  0.0,  0.0, 
   2.0,  0.0,  1.0,  0.0, 
   0.0,  0.0,  0.0,  1.0, 
  -1.0,  0.0,  0.0,  0.0 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double moler4_condition ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER4_CONDITION returns the L1 condition of the MOLER4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double VALUE, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double value;

  a_norm = 3.0;
  b_norm = 3.0;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double moler4_determinant ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER4_DETERMINANT returns the determinant of the MOLER4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double VALUE, the determinant.
//
{
  double value;

  value = 1.0;

  return value;
}
//****************************************************************************80

double *moler4_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER4_EIGENVALUES returns the eigenvalues of the MOLER4 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double LAMBDA(4), the eigenvalues.
//
{
  double *lambda;

  lambda = new double[4];

  lambda[0] = -1.0;
  lambda[1] = -1.0;
  lambda[2] = +1.0;
  lambda[3] = +1.0;

  return lambda;
}
//****************************************************************************80

double *moler4_inverse ( )

//****************************************************************************80
//
//  Purpose:
//
//    MOLER4_INVERSE returns the inverse of the MOLER4 matrix.
//
//  Example:
//
//    0  1  0  0
//    0  0  1  0
//    0  0  0  1
//   -1  0  2  0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double A(4,4), the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  double a_save[4*4] = {
   0.0,  0.0,  0.0, -1.0, 
   1.0,  0.0,  0.0,  0.0, 
   0.0,  1.0,  0.0,  2.0, 
   0.0,  0.0,  1.0,  0.0 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double *neumann ( int nrow, int ncol )

//****************************************************************************80
//
//  Purpose:
//
//    NEUMANN returns the NEUMANN matrix.
//
//  Formula:
//
//    I1 = 1 + ( I - 1 ) / NROW
//    I2 = I - ( I1 - 1 ) * NROW
//    J1 = 1 + ( J - 1 ) / NROW
//
//    if ( I = J )
//      A(I,J) = 4
//    else If ( I = J-1 )
//      If ( I2 = 1 )
//        A(I,J) = -2
//      else
//        A(I,J) = -1
//    else if ( I = J+1 )
//      If ( I2 = NROW )
//        A(I,J) = -2
//      else
//        A(I,J) = -1
//    else if ( I = J - NROW )
//      if ( J1 = 2 )
//        A(I,J) = -2
//      else
//        A(I,J) = -1
//    else if ( I = J + NROW )
//      if ( J1 = NCOL-1 )
//        A(I,J) = -2
//      else
//        A(I,J) = -1
//    else
//      A(I,J) = 0.0
//
//  Example:
//
//    NROW = NCOL = 3
//
//     4 -2  0 | -2  0  0 |  0  0  0
//    -1  4 -1 |  0 -2  0 |  0  0  0
//     0 -2  4 |  0  0 -2 |  0  0  0
//     ----------------------------
//    -1  0  0 |  4 -1  0 | -1  0  0
//     0 -1  0 | -1  4 -1 |  0 -1  0
//     0  0 -1 |  0 -1  4 |  0  0 -1
//     ----------------------------
//     0  0  0 | -2  0  0 |  4 -2  0
//     0  0  0 |  0 -2  0 | -1  4 -1
//     0  0  0 |  0  0 -2 |  0 -2  4
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is block tridiagonal.
//
//    A results from discretizing Neumann's equation with the
//    5 point operator on a mesh of NROW by NCOL points.
//
//    A is singular.
//
//    A has the null vector ( 1, 1, ..., 1 ).
//
//    det ( A ) = 0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gene Golub, Charles Van Loan,
//    Matrix Computations, second edition,
//    Johns Hopkins University Press, Baltimore, Maryland, 1989
//    (Section 4.5.4).
//
//  Parameters:
//
//    Input, int NROW, NCOL, the number of rows and columns
//    in the grid.
//
//    Output, double NEUMANN[(NROW*NCOL)*(NROW*NCOL)], the matrix.
//
{
  double *a;
  int i;
  int i1;
  int j;
  int j1;
  int n;

  n = nrow * ncol;

  a = r8mat_zero_new ( n, n );

  i = 0;

  for ( i1 = 0; i1 < nrow; i1++ )
  {
    for ( j1 = 0; j1 < ncol; j1++ )
    {
      if ( 0 < i1 )
      {
        j = i - nrow;
      }
      else
      {
        j = i + nrow;
      }
      a[i+j*n] = a[i+j*n] - 1.0;

      if ( 0 < j1 )
      {
        j = i - 1;
      }
      else
      {
        j = i + 1;
      }
      a[i+j*n] = a[i+j*n] - 1.0;

      j = i;
      a[i+j*n] = 4.0;

      if ( j1 < ncol - 1 )
      {
        j = i + 1;
      }
      else
      {
        j = i - 1;
      }
      a[i+j*n] = a[i+j*n] - 1.0;

      if ( i1 < nrow - 1 )
      {
        j = i + nrow;
      }
      else
      {
        j = i - nrow;
      }
      a[i+j*n] = a[i+j*n] - 1.0;

      i = i + 1;
    }
  }
  return a;
}
//****************************************************************************80

double neumann_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    NEUMANN_DETERMINANT returns the determinant of the NEUMANN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double NEUMANN_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 0.0;

  return determ;
}
//****************************************************************************80

double *neumann_null_right ( int nrow, int ncol )

//****************************************************************************80
//
//  Purpose:
//
//    NEUMANN_NULL_RIGHT returns a right null vector of the NEUMANN matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NROW, NCOL, the number of rows and columns 
//    in the grid.
//
//    Output, double NEUMANN_NULL_RIGHT[NROW*NCOL], the null vector.
//
{
  int i;
  double *x;

  x = new double[nrow*ncol];

  for ( i = 0; i < nrow*ncol; i++ )
  {
    x[i] = 1.0;
  }
  return x;
}
//****************************************************************************80

double *one ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    ONE returns the ONE matrix.
//
//  Discussion:
//
//    The matrix is sometimes symbolized by "J".
//
//  Example:
//
//    N = 5
//
//    1 1 1 1 1
//    1 1 1 1 1
//    1 1 1 1 1
//    1 1 1 1 1
//    1 1 1 1 1
//
//  Properties:
//
//    Every entry of A is 1.
//
//    A is symmetric.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is Hankel: constant along antidiagonals.
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    A has constant row sums.
//
//    A has constant column sums.
//
//    If 1 < N, A is singular.
//
//    If 1 < N, det ( A ) = 0.
//
//    LAMBDA(1:N-1) = 0
//    LAMBDA(N) = N
//
//    The eigenvectors associated with LAMBDA = 0 can be written as
//    ( 1, -1,  0, ..., 0 )
//    ( 1,  0, -1, ..., 0 )
//    ...
//    ( 1,  0,  0, ..., -1 ).
//    The eigenvector associated with LAMBDA = N is ( 1, 1, ..., 1 ).
//
//    A * A = N * A
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double ONE[M*N], the matrix.
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
      a[i+j*m] = 1.0;
    }
  }
  return a;
}
//****************************************************************************80

double one_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    ONE_DETERMINANT returns the determinant of the ONE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double ONE_DETERMINANT, the determinant.
//
{
  double determ;

  if ( n == 1 )
  {
    determ = 1.0;
  }
  else
  {
    determ = 0.0;
  }
  return determ;
}
//****************************************************************************80

double *one_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    ONE_EIGENVALUES returns the eigenvalues of the ONE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double ONE_EIGENVALUES[N], the eigenvalues.
//
{
  double *lambda;

  lambda = r8vec_zero_new ( n );
  
  lambda[n-1] = ( double ) ( n );

  return lambda;
}
//****************************************************************************80

double *one_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    ONE_NULL_LEFT returns a left null vector of the ONE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double ONE_NULL_LEFT[M], the null vector.
//
{
  double *x;

  if ( m == 1 )
  {
    cerr << "\n";
    cerr << "ONE_NULL_LEFT - Fatal error!\n";
    cerr << "  Matrix is nonsingular for M = 1.\n";
    exit ( 1 );
  }

  x = r8vec_zero_new ( m );

  x[0]   = 1.0;
  x[m-1] = - 1.0;

  return x;
}
//****************************************************************************80

double *one_null_right ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    ONE_NULL_RIGHT returns a right null vector of the ONE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double ONE_NULL_RIGHT[N], the null vector.
//
{
  double *x;

  if ( n == 1 )
  {
    cerr << "\n";
    cerr << "ONE_NULL_RIGHT - Fatal error!\n";
    cerr << "  Matrix is nonsingular for N = 1.\n";
    exit ( 1 );
  }

  x = r8vec_zero_new ( n );

  x[0]   = 1.0;
  x[n-1] = - 1.0;

  return x;
}
//****************************************************************************80

double *one_eigen_right ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    ONE_EIGEN_RIGHT returns the right eigenvectors of the ONE matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double ONE_EIGEN_RIGHT[N*N], the right eigenvectors.
//
{
  int i;
  int j;
  double *x;

  x = r8mat_zero_new ( n, n );

  for ( j = 0; j < n - 1; j++ )
  {
    x[  0+j*n] = +1.0;
    x[j+1+j*n] = -1.0;
  }

  j = n - 1;
  for ( i = 0; i < n; i++ )
  {
    x[i+j*n] = 1.0;
  }
  return x;
}
//****************************************************************************80

double *ortega ( int n, double u[], double v[], double d[] )

//****************************************************************************80
//
//  Purpose:
//
//    ORTEGA returns the ORTEGA matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    James Ortega,
//    Generation of Test Matrices by Similarity Transformations,
//    Communications of the ACM,
//    Volume 7, 1964, pages 377-378.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    2 <= N.
//
//    Input, double U[N], V[N], vectors which define the matrix.
//    U'V must not equal -1.0.  If, in fact, U'V = 0, and U, V and D are
//    integers, then the matrix, inverse, eigenvalues, and eigenvectors 
//    will be integers.
//
//    Input, double D[N], the desired eigenvalues.
//
//    Output, double ORTEGA[N*N], the matrix.
//
{ 
  double *a;
  double beta;
  double bik;
  double ckj;
  int i;
  int j;
  int k;
  double vtu;

  a = new double[n*n];

  vtu = r8vec_dot_product ( n, v, u );

  beta = 1.0 / ( 1.0 + vtu );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;

      for ( k = 0; k < n; k++ )
      {
        if ( i == k )
        {
          bik = 1.0 + u[i] * v[k];
        }
        else
        {
          bik =       u[i] * v[k];
        }
        if ( k == j )
        {
          ckj = 1.0 - beta * u[k] * v[j];
        }
        else
        {
          ckj =     - beta * u[k] * v[j];
        }
        a[i+j*n] = a[i+j*n] + bik * d[k] * ckj;
      }
    }
  }
  return a;
}
//****************************************************************************80

double ortega_determinant ( int n, double u[], double v[], double d[] )

//****************************************************************************80
//
//  Purpose:
//
//    ORTEGA_DETERMINANT returns the determinant of the ORTEGA matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    James Ortega,
//    Generation of Test Matrices by Similarity Transformations,
//    Communications of the ACM,
//    Volume 7, 1964, pages 377-378.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    2 <= N.
//
//    Input, double U[N], V[N], vectors which define the matrix.
//    U'V must not equal -1.0.  If, in fact, U'V = 0, and U, V and D are
//    integers, then the matrix, inverse, eigenvalues, and eigenvectors 
//    will be integers.
//
//    Input, double D[N], the desired eigenvalues.
//
//    Output, double ORTEGA_DETERMINANT, the determinant.
//
{
  double determ;

  determ = r8vec_product ( n, d );

  return determ;
}
//****************************************************************************80

double *ortega_eigenvalues ( int n, double u[], double v[], double d[] )

//****************************************************************************80
//
//  Purpose:
//
//    ORTEGA_EIGENVALUES returns the eigenvalues of the ORTEGA matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    James Ortega,
//    Generation of Test Matrices by Similarity Transformations,
//    Communications of the ACM,
//    Volume 7, 1964, pages 377-378.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    2 <= N.
//
//    Input, double U[N], V[N], vectors which define the matrix.
//    U'V must not equal -1.0.  If, in fact, U'V = 0, and U, V and D are
//    integers, then the matrix, inverse, eigenvalues, and eigenvectors 
//    will be integers.
//
//    Input, double D[N], the desired eigenvalues.
//
//    Output, double ORTEGA_EIGENVALUES[N], the determinant.
//
{
  double *lambda;

  lambda = r8vec_copy_new ( n, d );

  return lambda;
}
//****************************************************************************80

double *ortega_inverse ( int n, double u[], double v[], double d[] )

//****************************************************************************80
//
//  Purpose:
//
//    ORTEGA_INVERSE returns the inverse of the ORTEGA matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    James Ortega,
//    Generation of Test Matrices by Similarity Transformations,
//    Communications of the ACM,
//    Volume 7, 1964, pages 377-378.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    2 <= N.
//
//    Input, double U[N], V[N], vectors which define the matrix.
//    U'V must not equal -1.0.  If, in fact, U'V = 0, and U, V and D are
//    integers, then the matrix, inverse, eigenvalues, and eigenvectors 
//    will be integers.
//
//    Input, double D[N], the desired eigenvalues.
//
//    Output, double ORTEGA_INVERSE[N*N], the matrix.
//
{
  double *a;
  double beta;
  double bik;
  double ckj;
  int i;
  int j;
  int k;
  double vtu;

  a = new double[n*n];

  vtu = r8vec_dot_product ( n, v, u );

  for ( i = 0; i < n; i++ )
  {
    if ( d[i] == 0.0 )
    {
      cerr << "\n";
      cerr << "ORTEGA_INVERSE - Fatal error!\n";
      cerr << "  D[" << i << "] = 0.\n";
      exit ( 1 );
    }
  }

  beta = 1.0 / ( 1.0 + vtu );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;

      for ( k = 0; k < n; k++ )
      {
        if ( i == k )
        {
          bik = 1.0 + u[i] * v[k];
        }
        else
        {
          bik =     + u[i] * v[k];
        }
        if ( k == j )
        {
          ckj = 1.0 - beta * u[k] * v[j];
        }
        else
        {
          ckj =     - beta * u[k] * v[j];
        }
        a[i+j*n] = a[i+j*n] + ( bik / d[k] ) * ckj;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *ortega_eigen_right ( int n, double u[], double v[], double d[] )

//****************************************************************************80
//
//  Purpose:
//
//    ORTEGA_EIGEN_RIGHT returns the (right) eigenvectors of the ORTEGA matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    James Ortega,
//    Generation of Test Matrices by Similarity Transformations,
//    Communications of the ACM,
//    Volume 7, 1964, pages 377-378.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    2 <= N.
//
//    Input, double U[N], V[N], vectors which define the matrix.
//    U'V must not equal -1.0.  If, in fact, U'V = 0, and U, V and D are
//    integers, then the matrix, inverse, eigenvalues, and eigenvectors 
//    will be integers.
//
//    Input, double D[N], the desired eigenvalues.
//
//    Output, double ORTEGRA_EIGEN_RIGHT[N*N], the determinant.
//
{
  int i;
  int j;
  double *x;

  x = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        x[i+j*n] = 1.0 + u[i] * v[j];
      }
      else
      {
        x[i+j*n] =       u[i] * v[j];
      }
    }
  }
  return x;
}
//****************************************************************************80

double *orthogonal_random ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    orthogonal_random returns the orthogonal_random matrix.
//
//  Discussion:
//
//    The matrix is a random orthogonal matrix.
//
//  Properties:
//
//    The inverse of A is equal to A'.
//
//    A is orthogonal: A * A' = A' * A = I.
//
//    Because A is orthogonal, it is normal: A' * A = A * A'.
//
//    Columns and rows of A have unit Euclidean norm.
//
//    Distinct pairs of columns of A are orthogonal.
//
//    Distinct pairs of rows of A are orthogonal.
//
//    The L2 vector norm of A*x = the L2 vector norm of x for any vector x.
//
//    The L2 matrix norm of A*B = the L2 matrix norm of B for any matrix B.
//
//    det ( A ) = +1 or -1.
//
//    A is unimodular.
//
//    All the eigenvalues of A have modulus 1.
//
//    All singular values of A are 1.
//
//    All entries of A are between -1 and 1.
//
//  Discussion:
//
//    Thanks to Eugene Petrov, B I Stepanov Institute of Physics,
//    National Academy of Sciences of Belarus, for convincingly
//    pointing out the severe deficiencies of an earlier version of
//    this routine.
//
//    Essentially, the computation involves saving the Q factor of the
//    QR factorization of a matrix whose entries are normally distributed.
//    However, it is only necessary to generate this matrix a column at
//    a time, since it can be shown that when it comes time to annihilate
//    the subdiagonal elements of column K, these (transformed) elements of
//    column K are still normally distributed random values.  Hence, there
//    is no need to generate them at the beginning of the process and
//    transform them K-1 times.
//
//    For computational efficiency, the individual Householder transformations
//    could be saved, as recommended in the reference, instead of being
//    accumulated into an explicit matrix format.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Pete Stewart,
//    Efficient Generation of Random Orthogonal Matrices With an Application
//    to Condition Estimators,
//    SIAM Journal on Numerical Analysis,
//    Volume 17, Number 3, June 1980, pages 403-409.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double orthogonal_random[N*N] the matrix.
//
{
  double *a;
  int i;
  int j;
  int seed;
  double *v;
  double *x;
//
//  Start with A = the identity matrix.
//
  a = r8mat_zero_new ( n, n );

  for ( i = 0; i < n; i++ )
  {
    a[i+i*n] = 1.0;
  }
//
//  Now behave as though we were computing the QR factorization of
//  some other random matrix.  Generate the N elements of the first column,
//  compute the Householder matrix H1 that annihilates the subdiagonal elements,
//  and set A := A * H1' = A * H.
//
//  On the second step, generate the lower N-1 elements of the second column,
//  compute the Householder matrix H2 that annihilates them,
//  and set A := A * H2' = A * H2 = H1 * H2.
//
//  On the N-1 step, generate the lower 2 elements of column N-1,
//  compute the Householder matrix HN-1 that annihilates them, and
//  and set A := A * H(N-1)' = A * H(N-1) = H1 * H2 * ... * H(N-1).
//  This is our random orthogonal matrix.
//
  x = new double[n];
  seed = key;

  for ( j = 0; j < n - 1; j++ )
  {
//
//  Set the vector that represents the J-th column to be annihilated.
//
    for ( i = 0; i < j; i++ )
    {
      x[i] = 0.0;
    }
    for ( i = j; i < n; i++ )
    {
      x[i] = r8_normal_01 ( seed );
    }
//
//  Compute the vector V that defines a Householder transformation matrix
//  H(V) that annihilates the subdiagonal elements of X.
//
//  The COLUMN argument here is 1-based.
//
    v = r8vec_house_column ( n, x, j+1 );
//
//  Postmultiply the matrix A by H'(V) = H(V).
//
    r8mat_house_axh ( n, a, v );

    delete [] v;
  }
//
//  Free memory.
//
  delete [] x;

  return a;
}
//****************************************************************************80

double orthogonal_random_determinant ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    orthogonal_random_DETERMINANT returns the determinant of the orthogonal_random matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double orthogonal_random_DETERMINANT, the determinant.
//
{
  double determinant;

  determinant = 1.0;

  return determinant;
}
//****************************************************************************80

double *orthogonal_random_inverse ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    orthogonal_random_INVERSE returns the inverse of the orthogonal_random matrix.
//
//  Discussion:
//
//    This routine will only work properly if the input value of SEED
//    is exactly the same as the value used to generate the original matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double orthogonal_random_INVERSE[N*N], the matrix.
//
{
  double *a;

  a = orthogonal_random ( n, key );

  return a;
}
//****************************************************************************80

double *orthogonal_symmetric ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    orthogonal_symmetric returns the orthogonal_symmetric matrix.
//
//  Formula:
//
//    A(I,J) = sqrt ( 2 ) * sin ( I * J * pi / ( N + 1 ) ) / sqrt ( N + 1 )
//
//  Example:
//
//    N = 5
//
//    0.326019   0.548529   0.596885   0.455734   0.169891
//    0.548529   0.455734  -0.169891  -0.596885  -0.326019
//    0.596885  -0.169891  -0.548529   0.326019   0.455734
//    0.455734  -0.596885   0.326019   0.169891  -0.548528
//    0.169891  -0.326019   0.455734  -0.548528   0.596885
//
//  Properties:
//
//    A is orthogonal: A' * A = A * A' = I.
//
//    A is symmetric: A' = A.
//
//    A is not positive definite (unless N = 1 ).
//
//    Because A is symmetric, it is normal.
//
//    Because A is symmetric, its eigenvalues are real.
//
//    Because A is orthogonal, its eigenvalues have unit norm.
//
//    Only +1 and -1 can be eigenvalues of A.
//
//    Because A is normal, it is diagonalizable.
//
//    A is involutory: A * A = I.
//
//    If N is even, trace ( A ) = 0; if N is odd, trace ( A ) = 1.
//
//    LAMBDA(1:(N+1)/2) = 1; LAMBDA((N+1)/2+1:N) = -1.
//
//    A is the left and right eigenvector matrix for the
//    second difference matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Morris Newman, John Todd,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double orthogonal_symmetric[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = 2.0 * ( double ) ( ( i + 1 ) * ( j + 1 ) ) * r8_pi 
                  / ( double ) ( 2 * n + 1 );
      a[i+j*n] = 2.0 * sin ( angle ) / sqrt ( ( double ) ( 2 * n + 1 ) );
    }
  }
  return a;
}
//****************************************************************************80

double orthogonal_symmetric_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    orthogonal_symmetric_CONDITION returns the L1 condition of the orthogonal_symmetric matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 February 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double orthogonal_symmetric_CONDITION, the L1 condition.
//
{
  double a_norm;
  double angle;
  double b_norm;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;
  double value;

  a_norm = 0.0;
  j = 1;
  for ( i = 1; i <= n; i++ )
  {
    angle = 2.0 * ( double ) ( i * j ) * r8_pi / ( double ) ( 2 * n + 1 );
    a_norm = a_norm + 2.0 * fabs ( sin ( angle ) ) 
      / sqrt ( ( double ) ( 2 * n + 1 ) );
  }
  b_norm = a_norm;
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double orthogonal_symmetric_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    orthogonal_symmetric_DETERMINANT returns the determinant of the orthogonal_symmetric matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double orthogonal_symmetric_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *orthogonal_symmetric_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    orthogonal_symmetric_EIGENVALUES returns eigenvalues of the orthogonal_symmetric matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double orthogonal_symmetric_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < ( n + 1 ) / 2; i++ )
  {
    lambda[i] = +1.0;
  }
  for ( i = ( n + 1 ) / 2; i < n; i++ )
  {
    lambda[i] = -1.0;
  }
  return lambda;
}
//****************************************************************************80

double *orthogonal_symmetric_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    orthogonal_symmetric_INVERSE returns the inverse of the orthogonal_symmetric matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double orthogonal_symmetric_INVERSE[N*N], the matrix.
//
{
  double *a;

  a = orthogonal_symmetric ( n );

  return a;
}
//****************************************************************************80

double *oto ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    OTO returns the OTO matrix.
//
//  Discussion:
//
//    The name is meant to suggest "One, Two, One".
//
//  Example:
//
//    N = 5
//
//    2  1  .  .  .
//    1  2  1  .  .
//    .  1  2  1  .
//    .  .  1  2  1
//    .  .  .  1  2
//
//  Properties:
//
//    A is banded, with bandwidth 3.
//
//    A is tridiagonal.
//
//    Because A is tridiagonal, it has property A (bipartite).
//
//    A is integral: int ( A ) = A.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is weakly diagonally dominant, but not strictly diagonally dominant.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double OTO[M*N], the matrix.
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
      if ( j == i - 1 )
      {
        a[i+j*m] = 1.0;
      }
      else if ( j == i )
      {
        a[i+j*m] = 2.0;
      }
      else if ( j == i + 1 )
      {
        a[i+j*m] = 1.0;
      }
      else
      {
        a[i+j*m] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double oto_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    OTO_CONDITION returns the L1 condition of the OTO matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double OTO_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  int i1;
  int i2;
  int n1;
  int n2;
  int s;
  double value;

  if ( n == 1 )
  {
    a_norm = 2.0;
  }
  else if ( n == 2 )
  {
    a_norm = 3.0;
  }
  else
  {
    a_norm = 4.0;
  }

  n1 = ( n + 1 ) / 2;
  n2 = ( n + 2 ) / 2;

  s = 0;
  i1 = n1;
  i2 = 0;

  while ( i2 < n2 )
  {
    i2 = i2 + 1;
    s = s + i1 * i2;
  }

  while ( 1 < i1 )
  {
    i1 = i1 - 1;
    s = s + i1 * i2;
  }

  b_norm = ( double ) ( s ) / ( double ) ( n + 1 );

  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double oto_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    OTO_DETERMINANT returns the determinant of the OTO matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double OTO_DETERMINANT, the determinant of the matrix.
//
{
  double determ;

  determ = ( double ) ( n + 1 );

  return determ;
}
//****************************************************************************80

double *oto_eigen_right ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    OTO_EIGEN_RIGHT returns the right eigenvectors of the OTO matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double OTO_EIGEN_RIGHT[N*N], the right eigenvector matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      angle = ( double ) ( ( i + 1 ) * ( j + 1 ) ) * r8_pi 
        / ( double ) ( n + 1 );
      a[i+j*n] = r8_mop ( i + j ) 
        * sqrt ( 2.0 / ( double ) ( n + 1 ) ) * sin ( angle );
    }
  }
  return a;
}
//****************************************************************************80

double *oto_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    OTO_EIGENVALUES returns the eigenvalues of the OTO matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, OTO_EIGENVALUES[N], the eigenvalues.
//
{
  double angle;
  int i;
  double *lambda;
  const double r8_pi = 3.141592653589793;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( 2 * ( n + 1 ) );
    lambda[i] = 4.0 * pow ( sin ( angle ), 2 );
  }

  return lambda;
}
//****************************************************************************80

double *oto_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    OTO_INVERSE returns the inverse of the OTO matrix.
//
//  Formula:
//
//    if ( I <= J )
//      A(I,J) = (-1)^(I+J) * I * (N-J+1) / (N+1)
//    else
//      A(I,J) = (-1)^(I+J) * J * (N-I+1) / (N+1)
//
//  Example:
//
//    N = 4
//
//             4 -3  2 -1
//    (1/5) * -3  6 -4  2
//             2 -4  6 -3
//            -1  2 -3  4
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double OTO_INVERSE[N*N] the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i <= j )
      {
        a[i+j*n] = r8_mop ( i + j )
          * ( double ) ( ( i + 1 ) * ( n - j ) ) / ( double ) ( n + 1 );
      }
      else
      {
        a[i+j*n] = r8_mop ( i + j ) 
          * ( double ) ( ( j + 1 ) * ( n - i ) ) / ( double ) ( n + 1 );
      }
    }
  }
  return a;
}
//****************************************************************************80

double *oto_llt ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    OTO_LLT returns the Cholesky factor of the OTO matrix.
//
//  Example:
//
//    N = 5
//
//   1.4142         0         0         0         0
//   0.7071    1.2247         0         0         0
//        0    0.8165    1.1547         0         0
//        0         0    0.8660    1.1180         0
//        0         0         0    0.8944    1.0954
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double OTO_LLT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  
  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
    }
  }

  for ( i = 0; i < n; i++ )
  {
    a[i+i*n] = sqrt ( ( double ) ( i + 2 ) / ( double ) ( i + 1 ) );
  }

  for ( i = 1; i < n; i++ )
  {
    a[i+(i-1)*n] = sqrt ( ( double ) ( i ) / ( double ) ( i + 1 ) );
  }

  return a;
}
//****************************************************************************80

void oto_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    OTO_PLU returns the PLU factors of the OTO matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        l[i+j*n] = 1.0;
      }
      else if ( i == j + 1 )
      {
        l[i+j*n] = ( double ) ( j + 1 ) / ( double ) ( j + 2 );
      }
      else
      {
        l[i+j*n] = 0.0;
      }
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        u[i+j*n] = ( double ) ( i + 2 ) / ( double ) ( i + 1 );
      }
      else if ( i == j - 1 )
      {
        u[i+j*n] = 1.0;
      }
      else
      {
        u[i+j*n] = 0.0;
      }
    }
  }

  return;
}
//****************************************************************************80

double *parlett ( )

//****************************************************************************80
//
//  Purpose:
//
//    PARLETT returns the PARLETT matrix.
//
//  Formula:
//
//    N = 100
//
//    if ( I < J )
//      if ( I = 1 and J = 2 )
//        A(I,J) = 40 / 102
//      else if ( I = 1 and J = 100 )
//        A(I,J) = 40
//      else
//        A(I,J) = 0
//    else if ( I = J )
//      A(I,J) = 101 - I
//    else if ( J < I )
//      A(I,J) = (-1)^(I+J+1) * 40 / ( I + J - 2 )
//
//  Example:
//
//    100.00    0.39    0       0       0     ...   40.00
//     40.00   99.00    0       0       0     ...    0
//    -20.00   13.33   98.00    0       0     ...    0
//     13.33  -10.00    8.00   97.00    0     ...    0
//    -10.00    8.00   -6.67    5.71   96.00  ...    0
//     ...     ...     ...     ...     ...    ...   ...
//      0.40   -0.40    0.39   -0.39    0.38  ...    1.00
//
//  Properties:
//
//    A is not symmetric: A' /= A.
//
//    The eigenvalues of A are
//
//      LAMBDA(I) = I.
//
//    det ( A ) = 100!
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Output, double PARLETT[100*100], the matrix.
//
{
  double *a;
  int i;
  int j;
  int n = 100;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i < j )
      {
        if ( i == 0 && j == 1 )
        {
          a[i+j*n] = 40.0 / 102.0;
        }
        else if ( i == 0 && j == n - 1 )
        {
          a[i+j*n] = 40.0;
        }
        else
        {
          a[i+j*n] = 0.0;
        }
      }
      else if ( i == j )
      {
        a[i+j*n] = ( double ) ( n - i );
      }
      else if ( j < i )
      {
        a[i+j*n] = r8_mop ( i + j + 1 ) * 40.0 / ( double ) ( i + j );
      }
    }
  }
  return a;
}
//****************************************************************************80

double *parlett_eigenvalues ( )

//****************************************************************************80
//
//  Purpose:
//
//    PARLETT_EIGENVALUES returns the eigenvalues of the PARLETT matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double PARLETT_EIGENVALUES[100], the eigenvalues.
//
{
  int i;
  double *lambda;
  int n = 100;

  lambda = new double[n];
  
  for ( i = 0; i < n; i++ )
  {
    lambda[i] = ( double ) ( i + 1 );
  }
  return lambda;
}
//****************************************************************************80

double *parter ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    PARTER returns the PARTER matrix.
//
//  Formula:
//
//    A(I,J) = 1 / ( i - j + 0.5 )
//
//  Example:
//
//    N = 5
//
//     2   -2  -2/3 -2/5 -2/7
//    2/3   2   -2  -2/3 -2/5
//    2/5  2/3   2   -2  -2/3
//    2/7  2/5  2/3   2   -2
//    2/9  2/7  2/5  2/3   2
//
//  Properties:
//
//    The diagonal entries are all 2, the first superdiagonals all -2.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is generally not symmetric: A' /= A.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is a special case of the Cauchy matrix.
//
//    Most of the singular values are very close to Pi.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Seymour Parter,
//    On the distribution of the singular values of Toeplitz matrices,
//    Linear Algebra and Applications,
//    Volume 80, August 1986, pages 115-130.
//
//    Evgeny Tyrtyshnikov,
//    Cauchy-Toeplitz matrices and some applications,
//    Linear Algebra and Applications,
//    Volume 149, 15 April 1991, pages 1-18.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double PARTER[M*N], the matrix.
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
      a[i+j*m] = 1.0 / ( ( double ) ( i - j ) + 0.5 );
    }
  }
  return a;
}
//****************************************************************************80

double parter_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PARTER_DETERMINANT returns the determinant of the PARTER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PARTER_DETERMINANT, the determinant.
//
{
  double bottom;
  double determ;
  int i;
  int j;
  double top;

  top = 1.0;
  for ( i = 0; i < n; i++ )
  {
    for ( j = i + 1; j < n; j++ )
    {
      top = top * ( double ) ( j - i ) * ( double ) ( i - j );
    }
  }

  bottom = 1.0;
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      bottom = bottom * ( ( double ) ( i - j ) + 0.5 );
    }
  }
  determ = top / bottom;

  return determ;
}
//****************************************************************************80

double *parter_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PARTER_INVERSE returns the inverse of the PARTER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PARTER_INVERSE[N*N], the matrix.
//
{
  double *a;
  double bot1;
  double bot2;
  int i;
  int j;
  int k;
  double top;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      top = 1.0;
      bot1 = 1.0;
      bot2 = 1.0;
      for ( k = 0; k < n; k++ )
      {
        top = top * ( 0.5 + ( double ) ( j - k ) ) 
          * ( 0.5 + ( double ) ( k - i ) );

        if ( k != j )
        {
          bot1 = bot1 * ( double ) ( j - k );
        }
        if ( k != i )
        {
          bot2 = bot2 * ( double ) ( k - i );
        }
      }
      a[i+j*n] = top / ( ( 0.5 + ( double ) ( j - i ) ) * bot1 * bot2 );
    }
  }
  return a;
}
//****************************************************************************80

double *pascal1 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL1 returns the PASCAL1 matrix.
//
//  Formula:
//
//    if ( J = 1 )
//      a[i+j*n] = 1
//    else if ( I = 0 )
//      A(1,J) = 0
//    else
//      a[i+j*n] = A(I-1,J) + A(I-1,J-1)
//
//  Example:
//
//    N = 5
//
//    1  0  0  0  0
//    1  1  0  0  0
//    1  2  1  0  0
//    1  3  3  1  0
//    1  4  6  4  1
//
//  Properties:
//
//    A is a "chunk" of the Pascal binomial combinatorial triangle.
//
//    A is generally not symmetric: A' /= A.
//
//    A is nonsingular.
//
//    A is lower triangular.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    LAMBDA(1:N) = 1.
//
//    (0, 0, ..., 0, 1) is an eigenvector.
//
//    The inverse of A is the same as A, except that entries in "odd"
//    positions have changed sign:
//
//      B(I,J) = (-1)^(I+J) * a[i+j*n]
//
//    The product A*A' is a Pascal matrix
//    of the sort created by PASCAL2.
//
//    Let the matrix C have the same entries as A, except that
//    the even columns are negated.  Then Inverse(C) = C, and
//    C' * C = the Pascal matrix created by PASCAL2.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL1[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( i = 0; i < n; i ++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( j == 0 )
      {
        a[i+j*n] = 1.0;
      }
      else if ( i == 0 )
      {
        a[i+j*n] = 0.0;
      }
      else
      {
        a[i+j*n] = a[i-1+(j-1)*n] + a[i-1+j*n];
      }
    }
  }
  return a;
}
//****************************************************************************80

double pascal1_condition ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL1_CONDITION returns the L1 condition of the PASCAL1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL1_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  int nhalf;
  double value;

  nhalf = ( n + 1 ) / 2;
  a_norm = r8_choose ( n, nhalf );
  b_norm = r8_choose ( n, nhalf );
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double pascal1_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL1_DETERMINANT returns the determinant of the PASCAL1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL1_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *pascal1_eigenvalues ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL1_EIGENVALUES returns eigenvalues of the PASCAL1 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL1_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n; i++ )
  {
    lambda[i] = 1.0;
  }
  return lambda;
}
//****************************************************************************80

double *pascal1_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL1_INVERSE returns the inverse of the PASCAL1 matrix.
//
//  Formula:
//
//    if ( J = 1 )
//      a[i+j*n] = (-1)^(I+J)
//    else if ( I = 1 )
//      a[i+j*n] = 0
//    else
//      a[i+j*n] = A(I-1,J) - A(I,J-1)
//
//  Example:
//
//    N = 5
//
//     1  0  0  0  0
//    -1  1  0  0  0
//     1 -2  1  0  0
//    -1  3 -3  1  0
//     1 -4  6 -4  1
//
//  Properties:
//
//    A is nonsingular.
//
//    A is lower triangular.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    LAMBDA(1:N) = 1.
//
//    (0, 0, ..., 0, 1) is an eigenvector.
//
//    The inverse of A is the same as A, except that entries in "odd"
//    positions have changed sign:
//
//      B(I,J) = (-1)^(I+J) * a[i+j*n]
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL1_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j ++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == 0 )
      {
        a[i+j*n] = r8_mop ( i + j );
      }
      else if ( i == 0 )
      {
        a[i+j*n] = 0.0;
      }
      else
      {
        a[i+j*n] = a[i-1+(j-1)*n] - a[i-1+j*n];
      }
    }
  }
  return a;
}
//****************************************************************************80

double *pascal2 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL2 returns the PASCAL2 matrix.
//
//  Discussion:
//
//    See page 172 of the Todd reference.
//
//  Formula:
//
//    If ( I = 1 or J = 1 )
//      a[i+j*n] = 1
//    else
//      a[i+j*n] = A(I-1,J) + A(I,J-1)
//
//  Example:
//
//    N = 5
//
//    1 1  1  1  1
//    1 2  3  4  5
//    1 3  6 10 15
//    1 4 10 20 35
//    1 5 15 35 70
//
//  Properties:
//
//    A is a "chunk" of the Pascal binomial combinatorial triangle.
//
//    A is positive definite.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is nonsingular.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    Eigenvalues of A occur in reciprocal pairs.
//
//    The condition number of A is approximately 16^N / ( N*PI ).
//
//    The elements of the inverse of A are integers.
//
//    a[i+j*n] = (I+J-2)! / ( (I-1)! * (J-1)! )
//
//    The Cholesky factor of A is a lower triangular matrix R,
//    such that A = R * R'.  The matrix R is a Pascal
//    matrix of the type generated by subroutine PASCAL.  In other
//    words, PASCAL2 = PASCAL * PASCAL'.
//
//    If the (N,N) entry of A is decreased by 1, the matrix is singular.
//
//    Gregory and Karney consider a generalization of this matrix as
//    their test matrix 3.7, in which every element is multiplied by a
//    nonzero constant K.  They point out that if K is the reciprocal of
//    an integer, then the inverse matrix has all integer entries.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Robert Brawer, Magnus Pirovino,
//    The linear algebra of the Pascal matrix,
//    Linear Algebra and Applications,
//    Volume 174, 1992, pages 13-23.
//
//    Robert Gregory, David Karney,
//    A Collection of Matrices for Testing Computational Algorithms,
//    Wiley, 1969,
//    ISBN: 0882756494,
//    LC: QA263.68
//
//    Nicholas Higham,
//    Accuracy and Stability of Numerical Algorithms,
//    Society for Industrial and Applied Mathematics,
//    Philadelphia, PA, USA, 1996; section 26.4.
//
//    Sam Karlin,
//    Total Positivity, Volume 1,
//    Stanford University Press, 1968.
//
//    Morris Newman, John Todd,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    Heinz Rutishauser,
//    On test matrices,
//    Programmation en Mathematiques Numeriques,
//    Centre National de la Recherche Scientifique,
//    1966, pages 349-365.
//
//    John Todd,
//    Basic Numerical Mathematics,
//    Volume 2: Numerical Algebra,
//    Birkhauser, 1980,
//    ISBN: 0817608117,
//    LC: QA297.T58.
//
//    HW Turnbull,
//    The Theory of Determinants, Matrices, and Invariants,
//    Blackie, 1929.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL2[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j ++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 )
      {
        a[i+j*n] = 1.0;
      }
      else if ( j == 0 )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = a[i+(j-1)*n] + a[i-1+j*n];
      }
    }
  }
  return a;
}
//****************************************************************************80

double pascal2_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL2_DETERMINANT returns the determinant of the PASCAL2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL2_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *pascal2_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL2_INVERSE returns the inverse of the PASCAL2 matrix.
//
//  Formula:
//
//    a[i+j*n] = sum ( max(I,J) <= K <= N )
//      (-1)^(J+I) * COMB(K-1,I-1) * COMB(K-1,J-1)
//
//  Example:
//
//    N = 5
//
//      5 -10  10  -5   1
//    -10  30 -35  19  -4
//     10 -35  46 -27   6
//     -5  19 -27  17  -4
//      1  -4   6  -4   1
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    The first row sums to 1, the others to 0.
//
//    The first column sums to 1, the others to 0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL2_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  int klo;

  a = new double[n*n];

  for ( j = 0; j < n; j ++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
      klo = i4_max ( i + 1, j + 1 );
      for ( k = klo; k <= n; k++ )
      {
        a[i+j*n] = a[i+j*n] + r8_mop ( i + j ) * r8_choose ( k - 1, i ) 
          * r8_choose ( k - 1, j );
      }
    }
  }
  return a;
}
//****************************************************************************80

double *pascal2_llt ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL2_LLT returns the Cholesky factor of the PASCAL2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double PASCAL2_LLT[N*N], the matrix.
//
{
  double *a;

  a = pascal1 ( n );

  return a;
}
//****************************************************************************80

void pascal2_plu ( int n, double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL2_PLU returns the PLU factors of the PASCAL2 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double P[N*N], L[N*N], U[N*N], the PLU factors.
//
{
  int i;
  int j;
  double *l_local;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }

  l_local = pascal1 ( n );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      l[i+j*n] = l_local[i+j*n];
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      u[i+j*n] = l[j+i*n];
    }
  }
//
//  Free memory.
//
  delete [] l_local;

  return;
}
//****************************************************************************80

double *pascal3 ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL3 returns the PASCAL3 matrix.
//
//  Formula:
//
//    if ( J = 1 )
//      a[i+j*n] = 1
//    else if ( I = 0 )
//      A(1,J) = 0
//    else
//      a[i+j*n] =  ALPHA * A(I-1,J) + A(I-1,J-1) )
//
//  Example:
//
//    N = 5, ALPHA = 2
//
//     1   0   0   0   0
//     2   1   0   0   0
//     4   4   1   0   0
//     8  12   6   1   0
//    16  32  24   8   1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A[0] is the identity matrix.
//
//    A[1] is the usual (lower triangular) Pascal matrix.
//
//    A is nonsingular.
//
//    A is lower triangular.
//
//    If ALPHA is integral, then A is integral.
//    If A is integral, then det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    det ( A ) = 1.
//
//    A is unimodular.
//
//    LAMBDA(1:N) = 1.
//
//    (0, 0, ..., 0, 1) is an eigenvector.
//
//    The inverse of A[X] is A[-X].
//
//    A[ALPHA] * A[BETA] = A[ALPHA*BETA].
//
//    A[1/2] is the "square root" of A[1], and so on.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gregory Call, Daniel Velleman,
//    Pascal's Matrices,
//    American Mathematical Monthly,
//    Volume 100, Number 4, April 1993, pages 372-376.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, the parameter.
//
//    Output, double PASCAL3[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j ++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 )
      {
        if ( j == 0 )
        {
          a[i+j*n] = 1.0;
        }
        else
        {
          a[i+j*n] = 0.0;
        }
      }
      else if ( j == 0 )
      {
        a[i+j*n] = alpha * a[i-1+j*n];
      }
      else
      {
        a[i+j*n] = a[i-1+(j-1)*n] + alpha * a[i-1+j*n];
      }
    }
  }
  return a;
}
//****************************************************************************80

double pascal3_condition ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL3_CONDITION returns the L1 condition of the PASCAL3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, the parameter.
//
//    Output, double PASCAL3_CONDITION, the L1 condition.
//
{
  double *a;
  double a_norm;
  double b_norm;
  double value;

  a = pascal3 ( n, alpha );
  a_norm = r8mat_norm_l1 ( n, n, a );
  b_norm = a_norm;
  value = a_norm * b_norm;

  delete [] a;

  return value;
}
//****************************************************************************80

double pascal3_determinant ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL3_DETERMINANT returns the determinant of the PASCAL3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, the parameter.
//
//    Output, double PASCAL3_DETERMINANT, the determinant.
//
{
  double determ;

  determ = 1.0;

  return determ;
}
//****************************************************************************80

double *pascal3_inverse ( int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    PASCAL3_INVERSE returns the inverse of the PASCAL3 matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 May 2002
//
//  Author:
//
//    04 July 2008
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double ALPHA, the parameter.
//
//    Output, double PASCAL3_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j ++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 )
      {
        if ( j == 0 )
        {
          a[i+j*n] = 1.0;
        }
        else
        {
          a[i+j*n] = 0.0;
        }
      }
      else if ( j == 0 )
      {
        a[i+j*n] = - alpha * a[i-1+j*n];
      }
      else
      {
        a[i+j*n] = a[i-1+(j-1)*n] - alpha * a[i-1+j*n];
      }
    }
  }
  return a;
}
//****************************************************************************80

double *spd_random ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    SPD_RANDOM returns the SPD_RANDOM matrix.
//
//  Discussion:
//
//    The matrix is a "random" positive definite symmetric matrix.
//
//    The matrix returned will have eigenvalues in the range [0,1].
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    A is positive definite: 0 < x'*A*x for nonzero x.
//
//    The eigenvalues of A will be real.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double SPD_RANDOM[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  double *lambda;
  double *q;
  int seed;

  a = new double[n*n];
//
//  Get a random set of eigenvalues.
//
  seed = key;
  lambda = r8vec_uniform_01_new ( n, seed );
//
//  Get a random orthogonal matrix Q.
//
  q = orthogonal_random ( n, key );
//
//  Set A = Q * Lambda * Q'.
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        a[i+j*n] = a[i+j*n] + q[i+k*n] * lambda[k] * q[j+k*n];
      }
    }
  }
//
//  Free memory.
//
  delete [] lambda;
  delete [] q;

  return a;
}
//****************************************************************************80

double spd_random_determinant ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    SPD_RANDOM_DETERMINANT returns the determinant of the SPD_RANDOM matrix.
//
//  Discussion:
//
//    This routine will only work properly if the SAME value of SEED
//    is input that was input to SPD_RANDOM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double SPD_RANDOM_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  double *lambda;
  int seed;

  seed = key;
  lambda = r8vec_uniform_01_new ( n, seed );

  determ = 1.0;
  for ( i = 0; i < n; i++ )
  {
    determ = determ * lambda[i];
  }
//
//  Free memory.
//
  delete [] lambda;

  return determ;
}
//****************************************************************************80

double *spd_random_eigenvalues ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    SPD_RANDOM_EIGENVALUES returns the eigenvalues of the SPD_RANDOM matrix.
//
//  Discussion:
//
//    This routine will only work properly if the SAME value of SEED
//    is input that was input to SPD_RANDOM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double SPD_RANDOM_EIGENVALUES[N], the eigenvalues.
//
{
  double *lambda;
  int seed;

  seed = key;
  lambda = r8vec_uniform_01_new ( n, seed );

  return lambda;
}
//****************************************************************************80

double *spd_random_inverse ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    SPD_RANDOM_INVERSE returns the inverse of the SPD_RANDOM matrix.
//
//  Discussion:
//
//    The matrix is a "random" positive definite symmetric matrix.
//
//    The matrix returned will have eigenvalues in the range [0,1].
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    A is positive definite: 0 < x'*A*x for nonzero x.
//
//    The eigenvalues of A will be real.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double SPD_RANDOM_INVERSE[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  double *lambda;
  double *q;
  int seed;
//
//  Get a random set of eigenvalues.
//
  seed = key;
  lambda = r8vec_uniform_01_new ( n, seed );
//
//  Get a random orthogonal matrix Q.
//
  q = orthogonal_random ( n, key );
//
//  Set A = Q * Lambda * Q'.
//
  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        a[i+j*n] = a[i+j*n] + q[i+k*n] * ( 1.0 / lambda[k] ) * q[j+k*n];
      }
    }
  }
//
//  Free memory.
//
  delete [] lambda;
  delete [] q;

  return a;
}
//****************************************************************************80

double *spd_random_eigen_right ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    SPD_RANDOM_EIGEN_RIGHT returns the right eigenvectors of the SPD_RANDOM matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double SPD_RANDOM_EIGEN_RIGHT[N*N], the matrix.
//
{
  double *lambda;
  double *q;
  int seed;
//
//  Get a random set of eigenvalues.
//
  seed = key;
  lambda = r8vec_uniform_01_new ( n, seed );
//
//  Get a random orthogonal matrix Q.
//
  q = orthogonal_random ( n, key );
//
//  Free memory.
//
  delete [] lambda;

  return q;
}
//****************************************************************************80

double *pei ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    PEI returns the PEI matrix.
//
//  Formula:
//
//    if ( I = J ) then
//      A(I,J) = 1.0 + ALPHA
//    else
//      A(I,J) = 1.0
//
//  Example:
//
//    ALPHA = 2, N = 5
//
//    3 1 1 1 1
//    1 3 1 1 1
//    1 1 3 1 1
//    1 1 1 3 1
//    1 1 1 1 3
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is positive definite for 0 < ALPHA.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    A is singular if and only if ALPHA = 0 or ALPHA = -N.
//
//    A becomes more ill-conditioned as ALPHA approaches 0.
//
//    The condition number under the spectral norm is 
//      abs ( ( ALPHA + N ) / ALPHA )
//
//    The eigenvalues of A are
//
//      LAMBDA(1:N-1) = ALPHA
//      LAMBDA(N) = ALPHA + N
//
//    A has constant row sum of ALPHA + N.
//
//    Because it has a constant row sum of ALPHA + N,
//    A has an eigenvalue of ALPHA + N, and
//    a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has constant column sum of ALPHA + N.
//
//    Because it has a constant column sum of ALPHA + N,
//    A has an eigenvalue of ALPHA + N, and
//    a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    The eigenvectors are:
//
//      V1 = 1 / sqrt ( N )       * ( 1, 1, 1, ... , 1 )
//      VR = 1 / sqrt ( R * (R-1) ) * ( 1, 1, 1, ... 1, -R+1, 0, 0, 0, ... 0 )
//
//    where the "-R+1" occurs at index R.
//
//    det ( A ) = ALPHA^(N-1) * ( N + ALPHA ).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Morris Newman, John Todd,
//    Example A3,
//    The evaluation of matrix inversion programs,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 6, Number 4, pages 466-476, 1958.
//
//    ML Pei,
//    A test matrix for inversion procedures,
//    Communications of the ACM,
//    Volume 5, 1962, page 508.
//
//    Joan Westlake,
//    A Handbook of Numerical Matrix Inversion and Solution of 
//    Linear Equations,
//    John Wiley, 1968,
//    ISBN13: 978-0471936756,
//    LC: QA263.W47.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines the Pei matrix.  A
//    typical value of ALPHA is 1.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double PEI[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 1.0 + alpha;
      }
      else
      {
        a[i+j*n] = 1.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double pei_condition ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    PEI_CONDITION returns the L1 condition of the PEI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines the Pei matrix.  A
//    typical value of ALPHA is 1.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double PEI_CONDITION, the L1 condition.
//
{
  double a_norm;
  double b_norm;
  double n_r8;
  double value;

  n_r8 = ( double ) ( n );
  a_norm = fabs ( alpha + 1.0 ) + n_r8 - 1.0;
  b_norm = ( fabs ( alpha + n_r8 - 1.0 ) + n_r8 - 1.0 ) 
    / fabs ( alpha * ( alpha + n_r8 ) );
  value = a_norm * b_norm;

  return value;
}
//****************************************************************************80

double pei_determinant ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    PEI_DETERMINANT returns the determinant of the PEI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines the Pei matrix.  A
//    typical value of ALPHA is 1.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double PEI_DETERMINANT, the determinant.
//
{
  double determ;

  determ = pow ( alpha, n - 1 ) * ( alpha + ( double ) ( n ) );

  return determ;
}
//****************************************************************************80

double *pei_eigenvalues ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    PEI_EIGENVALUES returns the eigenvalues of the PEI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines the Pei matrix.  A
//    typical value of ALPHA is 1.0.
//
//    Input, int N, the order of the matrix.
//
//    Output, double PEI_EIGENVALUES[N], the eigenvalues.
//
{
  int i;
  double *lambda;

  lambda = new double[n];

  for ( i = 0; i < n - 1; i++ )
  {
    lambda[i] = alpha;
  }
  lambda[n-1] = alpha + ( double ) ( n );

  return lambda;
}
//****************************************************************************80

double *pei_inverse ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    PEI_INVERSE returns the inverse of the PEI matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = (ALPHA+N-1) / ( (ALPHA+1)*(ALPHA+N-1)-(N-1) )
//    else
//      A(I,J) =          -1 / ( (ALPHA+1)*(ALPHA+N-1)-(N-1) )
//
//  Example:
//
//    ALPHA = 2, N = 5
//
//            6 -1 -1 -1 -1
//           -1  6 -1 -1 -1
//    1/14 * -1 -1  6 -1 -1
//           -1 -1 -1  6 -1
//           -1 -1 -1 -1  6
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is a "combinatorial" matrix.  See routine COMBIN.
//
//    A is Toeplitz: constant along diagonals.
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    A has constant row sum.
//
//    Because it has a constant row sum of 1 / ( ALPHA + N ),
//    A has an eigenvalue of 1 / ( ALPHA + N ), and
//    a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has constant column sum.
//
//    Because it has constant column sum of 1 / ( ALPHA + N ),
//    A has an eigenvalue of 1 / ( ALPHA + N ), and
//    a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    The eigenvalues of A are
//      LAMBDA(1:N-1) = 1 / ALPHA
//      LAMBDA(N) = 1 / ( ALPHA + N )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    ML Pei,
//    A test matrix for inversion procedures,
//    Communications of the ACM,
//    Volume 5, 1962, page 508.
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines the inverse 
//    of the Pei matrix.
//
//    Input, int N, the order of the matrix.
//
//    Output, double PEI_INVERSE[N*N], the matrix.
//
{
  double *a;
  double alpha1;
  double beta1;
  double bottom;
  int i;
  int j;

  bottom = ( alpha + 1.0 ) * 
    ( alpha + ( double ) ( n ) - 1.0 ) - ( double ) ( n ) + 1.0;

  if ( bottom == 0.0 )
  {
    cerr << "\n";
    cerr << "PEI_INVERSE - Fatal error!\n";
    cerr << "  The matrix is not invertible.\n";
    cerr << "  (ALPHA+1)*(ALPHA+N-1)-N+1 is zero.\n";
    exit ( 1 );
  }

  alpha1 = ( alpha + ( double ) ( n ) - 1.0 ) / bottom;
  beta1 = - 1.0 / bottom;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = alpha1;
      }
      else
      {
        a[i+j*n] = beta1;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *pei_eigen_right ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    PEI_EIGEN_RIGHT returns the right eigenvectors of the PEI matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double ALPHA, the scalar that defines A.
//
//    Input, int N, the order of the matrix.
//
//    Output, double PEI_EIGEN_RIGHT[N*N], the right eigenvectors.
//
{
  int i;
  int j;
  double *x;

  x = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == 0 )
      {
        x[i+j*n] = + 1.0;
      }
      else if ( i == j + 1 )
      {
        x[i+j*n] = - 1.0;
      }
      else if ( j == n - 1 )
      {
        x[i+j*n] = 1.0;
      }
      else
      {
        x[i+j*n] = 0.0;
      }
    }
  }
  return x;
}
//****************************************************************************80

bool perm_check ( int n, int p[] )

//****************************************************************************80
//
//  Purpose:
//
//    PERM_CHECK checks that a vector represents a permutation.
//
//  Discussion:
//
//    The routine verifies that each of the integers from 1
//    to N occurs among the N entries of the permutation.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 January 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries.
//
//    Input, int P[N], the array to check.
//
//    Output, bool PERM_CHECK, is TRUE if the permutation is OK.
//
{
  bool found;
  int i;
  int seek;

  for ( seek = 1; seek <= n; seek++ )
  {
    found = false;

    for ( i = 0; i < n; i++ )
    {
      if ( p[i] == seek )
      {
        found = true;
        break;
      }
    }

    if ( !found )
    {
      cout << "\n";
      cout << "PERM_CHECK did not find " << seek << "\n";
      return false;
    }

  }

  return true;
}
//****************************************************************************80

void perm_inverse ( int n, int p[] )

//****************************************************************************80
//
//  Purpose:
//
//    PERM_INVERSE inverts a permutation "in place".
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 January 2004
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of objects being permuted.
//
//    int P[N], the permutation, in standard index form.
//
//  Output:
//
//    int P[N]: describes the inverse permutation.
//
{
  int i;
  int i0;
  int i1;
  int i2;
  int is;

  if ( n <= 0 )
  {
    cerr << "\n";
    cerr << "PERM_INVERSE - Fatal error!\n";
    cerr << "  Input value of N = " << n << "\n";
    exit ( 1 );
  }

  if ( !perm_check ( n, p ) )
  {
    cerr << "\n";
    cerr << "PERM_INVERSE - Fatal error!\n";
    cerr << "  The input array does not represent\n";
    cerr << "  a proper permutation.\n";
    exit ( 1 );
  }

  is = 1;

  for ( i = 1; i <= n; i++ )
  {
    i1 = p[i-1];

    while ( i < i1 )
    {
      i2 = p[i1-1];
      p[i1-1] = -i2;
      i1 = i2;
    }

    is = - i4_sign ( p[i-1] );
    p[i-1] = i4_sign ( is ) * abs ( p[i-1] );
  }

  for ( i = 1; i <= n; i++ )
  {
    i1 = -p[i-1];

    if ( 0 <= i1 )
    {
      i0 = i;

      for ( ; ; )
      {
        i2 = p[i1-1];
        p[i1-1] = i0;

        if ( i2 < 0 )
        {
          break;
        }
        i0 = i1;
        i1 = i2;
      }
    }
  }

  return;
}
//****************************************************************************80

int *perm_mat_to_vec ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    PERM_MAT_TO_VEC returns a permutation from a permutation matrix.
//
//  Example:
//
//    N = 5
//
//    A = 0  1  0  0  0
//        0  0  0  1  0
//        1  0  0  0  0
//        0  0  1  0  0
//        0  0  0  0  1
//
//    p = ( 2, 4, 1, 3, 5 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double A[N*N], the permutation matrix.
//
//    Output, int PERM_MAT_TO_VEC[N], a permutation of the indices 1 through 
//    N, which corresponds to the matrix.
//
{
  int i;
  int ival;
  int j;
  int *p;

  ival = r8mat_is_permutation ( n, n, a );

  if ( ival != 1 )
  {
    cerr << "\n";
    cerr << "PERM_MAT_TO_VEC - Fatal error!\n";
    cerr << "  The input matrix does not define a permutation.\n";
    cerr << "  R8MAT_IS_PERMUTATION returned IVAL = " << ival << "\n";
    exit ( 1 );
  }

  p = new int[n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( a[i+j*n] == 1.0 )
      {
        p[i] = j + 1;
      }
    }
  }
  return p;
}
//****************************************************************************80

int perm_sign ( int n, int p[] )

//****************************************************************************80
//
//  Purpose:
//
//    PERM_SIGN returns the sign of a permutation.
//
//  Discussion:
//
//    A permutation can always be replaced by a sequence of pairwise
//    transpositions.  A given permutation can be represented by
//    many different such transposition sequences, but the number of
//    such transpositions will always be odd or always be even.
//    If the number of transpositions is even or odd, the permutation is
//    said to be even or odd.
//
//  Example:
//
//    Input:
//
//      N = 9
//      P = 2, 3, 9, 6, 7, 8, 5, 4, 1
//
//    Output:
//
//      PERM_SIGN = +1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    07 July 2011
//
//  Author:
//
//    Original FORTRAN77 version by Albert Nijenhuis, Herbert Wilf.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Albert Nijenhuis, Herbert Wilf,
//    Combinatorial Algorithms for Computers and Calculators,
//    Second Edition,
//    Academic Press, 1978,
//    ISBN: 0-12-519260-6,
//    LC: QA164.N54.
//
//  Parameters:
//
//    Input, int N, the number of objects permuted.
//
//    Input, int P[N], a permutation, in standard index form.
//
//    Output, int PERM_SIGN, the "sign" of the permutation.
//    +1, the permutation is even,
//    -1, the permutation is odd.
//
{
  int i;
  int j;
  int p_sign;
  int *q;
  int temp;

  if ( !perm_check ( n, p ) )
  {
    cerr << "\n";
    cerr << "PERM_SIGN - Fatal error!\n";
    cerr << "  The input array does not represent\n";
    cerr << "  a proper permutation.\n";
    exit ( 1 );
  }
//
//  Make a temporary copy of the permutation.
//
  q = new int[n];

  for ( i = 0; i < n; i++ )
  {
    q[i] = p[i];
  }
//
//  Start with P_SIGN indicating an even permutation.
//  Restore each element of the permutation to its correct position,
//  updating P_SIGN as you go.
//
  p_sign = 1;

  for ( i = 1; i <= n - 1; i++ )
  {
    j = i4vec_index ( n, q, i );

    if ( j != i - 1 )
    {
      temp = q[i-1];
      q[i-1] = q[j-1];
      q[j-1] = temp;

      p_sign = - p_sign;
    }
  }
//
//  Free memory.
//
  delete [] q;
  
  return p_sign;
}
//****************************************************************************80

double *perm_vec_to_mat ( int n, int p[] )

//****************************************************************************80
//
//  Purpose:
//
//    PERM_VEC_TO_MAT returns a permutation matrix.
//
//  Formula:
//
//    if ( J = P(I) )
//      A(I,J) = 1
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5, P = ( 2, 4, 1, 3, 5 )
//
//    0  1  0  0  0
//    0  0  0  1  0
//    1  0  0  0  0
//    0  0  1  0  0
//    0  0  0  0  1
//
//  Properties:
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is a zero/one matrix.
//
//    P is a proper definition of a permutation if and only if
//    every value from 1 to N occurs exactly once.  The matrix A
//    will be a permutation matrix if and only if P is a proper
//    definition of a permutation.
//
//    A is nonsingular.
//
//    The inverse of A is the transpose of A, inverse ( A ) = A'.
//
//    The inverse of A is the permutation matrix corresponding to the
//    inverse permutation of the one that formed A.
//
//    det ( A ) = +1 or -1.
//
//    A is unimodular.
//
//    The determinant of A is +1 or -1, depending on the sign of
//    the permutation; Any permutation can be written as the product
//    of pairwise transpositions.  An odd permutation can be written
//    as an odd number of such transpositions, and the corresponding
//    matrix has a determinant of -1.
//
//    The product of two permutation matrices is a permutation matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int P[N], contains the permutation.  The
//    entries of P should be a permutation of the indices 1 through N.
//
//    Output, double PERM_VEC_TO_MAT[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  if ( !perm_check ( n, p ) )
  {
    cerr << "\n";
    cerr << "PERM_VEC_TO_MAT - Fatal error!\n";
    cerr << "  The input does not define a permutation.\n";
    i4vec_print ( n, p, "  The permutation:" );
    exit ( 1 );
  }

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j + 1 == p[i] )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }

  return a;
}
//****************************************************************************80

double permutation_determinant ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    PERMUTATION_DETERMINANT returns the determinant of a PERMUTATION matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double A[N*N], the matrix.
//
//    Output, double PERMUTATION_DETERMINANT, the determinant.
//
{
  double determ;
  int *p;
  int p_sign;

  p = perm_mat_to_vec ( n, a );

  p_sign = perm_sign ( n, p );

  determ = ( double ) ( p_sign );

  return determ;
}
//****************************************************************************80

double *permutation_random ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    PERMUTATION_RANDOM returns the PERMUTATION_RANDOM matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Albert Nijenhuis, Herbert Wilf,
//    Combinatorial Algorithms,
//    Academic Press, 1978, second edition,
//    ISBN 0-12-519260-6.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double PERMUTATION_RANDOM[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  int *p;
  int seed;

  p = i4vec_indicator_new ( n );

  seed = key;

  for ( i = 0; i < n; i++ )
  {
    j = i4_uniform_ab ( i, n - 1, seed );
    k    = p[j];
    p[j] = p[i];
    p[i] = k;
  }

  a = perm_vec_to_mat ( n, p );
//
//  Free memory.
//
  delete [] p;

  return a;
}
//****************************************************************************80

double permutation_random_determinant ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    PERMUTATION_RANDOM_DETERMINANT: determinant of PERMUTATION_RANDOM matrix.
//
//  Discussion:
//
//    This routine will only work properly if it is given as input the
//    same value of SEED that was given to PERMUTATION_RANDOM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double PERMUTATION_RANDOM_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int j;
  int k;
  int *p;
  int p_sign;
  int seed;

  p = i4vec_indicator_new ( n );

  seed = key;

  for ( i = 0; i < n; i++ )
  {
    j = i4_uniform_ab ( i, n - 1, seed );
    k    = p[j];
    p[j] = p[i];
    p[i] = k;
  }

  p_sign = perm_sign ( n, p );

  determ = ( double ) ( p_sign );
//
//  Free memory.
//
  delete [] p;

  return determ;
}
//****************************************************************************80

double *permutation_random_inverse ( int n, int key )

//****************************************************************************80
//
//  Purpose:
//
//    PERMUTATION_RANDOM_INVERSE: inverse of PERMUTATION_RANDOM matrix.
//
//  Discussion:
//
//    This routine will only work properly if it is given as input the
//    same value of SEED that was given to PERMUTATION_RANDOM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double PERMUTATION_RANDOM_INVERSE[N*N], the inverse matrix.
//
{
  double *a;
  int i;
  int j;
  int k;
  int *p;
  int seed;

  p = i4vec_indicator_new ( n );

  seed = key;

  for ( i = 0; i < n; i++ )
  {
    j = i4_uniform_ab ( i, n - 1, seed );
    k    = p[j];
    p[j] = p[i];
    p[i] = k;
  }

  perm_inverse ( n, p );

  a = perm_vec_to_mat ( n, p );
//
//  Free memory.
//
  delete [] p;

  return a;
}
//****************************************************************************80

complex <double> *pick ( int n, complex <double> w[], complex <double> z[] )

//****************************************************************************80
//
//  Purpose:
//
//    PICK returns the PICK matrix.
//
//  Formula:
//
//    A(I,J) = ( 1 - conjg ( W(I) ) * W(J) )
//           / ( 1 - conjg ( Z(I) ) * Z(J) )
//
//  Properties:
//
//    A is Hermitian: A* = A.
//
//  Discussion:
//
//    Pick's matrix is related to an interpolation problem in the 
//    complex unit disk |z| < 1.
//
//    If z(1:n) are distinct points in the complex unit disk, and
//    w(1:n) are complex values, then Pick's matrix is positive
//    semidefinite if and only if there is a holomorphic function
//    phi from the unit disk to itself such that phi(z(i)) = w(i).
//
//    phi is unique if and only if Pick's matrix is singular.
//  
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//  
//  Modified:
//
//    25 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John McCarthy,
//    Pick's Theorem: What's the Big Deal?
//    American Mathematical Monthly,
//    Volume 110, Number 1, January 2003, pages 36-45.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, complex <double> W[N], the parameters associated with the
//    numerator.
//
//    Input, complex <double> Z[N], the parameters associated with the
//    denominator.  Normally, the z's are distinct, and each of norm less 
//    than 1.
//
//    Output, complex <double> PICK[N*N], the matrix.
//
{
  complex <double> *a;
  int i;
  int j;

  a = new complex <double>[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = ( 1.0 - conj ( w[i] ) * w[j] )
               / ( 1.0 - conj ( z[i] ) * z[j] );
    }
  }
  return a;
}
//****************************************************************************80

double *plu ( int n, int pivot[] )

//****************************************************************************80
//
//  Purpose:
//
//    PLU returns a PLU matrix.
//
//  Example:
//
//    Input:
//
//      N = 5
//      PIVOT = ( 1, 3, 3, 5, 5 )
//
//    Output:
//
//      A:
//
//         11            12           13            14           15
//          1.375         9.75        43.25         44.75        46.25
//          2.75         25           26.25         27.5         28.75
//          0.34375       2.4375       7.71875      17.625       73.125
//          0.6875        4.875       15.4375       60           61.5625
//
//      P:
//
//          1             0            0             0            0
//          0             0            1             0            0
//          0             1            0             0            0
//          0             0            0             0            1
//          0             0            0             1            0
//
//      L:
//
//         1              0            0             0            0
//         0.25           1            0             0            0
//         0.125          0.375        1             0            0
//         0.0625         0.1875       0.3125        1            0
//         0.03125        0.09375      0.15625       0.21875      1
//
//      U:
//
//        11             12           13            14           15
//         0             22           23            24           25
//         0              0           33            34           35
//         0              0            0            44           45
//         0              0            0             0           55
//
//  Note:
//
//    The LINPACK routine DGEFA will factor the above A as:
//
//       11             12             13             14             15
//      -0.125          22             23             24             25
//      -0.25           -0.375         33             34             35
//      -0.03125        -0.09375       -0.15625       44             45
//      -0.0625         -0.1875        -0.3125        -0.21875       55
//
//    and the pivot information in the vector IPVT as:
//
//      ( 1, 3, 3, 5, 5 ).
//
//    The LAPACK routine DGETRF will factor the above A as:
//
//      11              12             13             14             15
//      0.25            22             23             24             25
//      0.125            0.375         33             34             35
//      0.0625           0.1875         0.3125        44             45
//      0.03125          0.09375        0.15625        0.21875       55
//
//   and the pivot information in the vector PIVOT as:
//
//     ( 1, 3, 3, 5, 5 ).
//
//  Method:
//
//    The L factor will have unit diagonal, and subdiagonal entries
//    L(I,J) = ( 2 * J - 1 ) / 2^I, which should result in a unique
//    value for every entry.
//
//    The U factor of A will have entries
//    U(I,J) = 10 * I + J, which should result in "nice" entries as long
//    as N < 10.
//
//    The P factor can be deduced by applying the pivoting operations
//    specified by PIVOT in reverse order to the rows of the identity.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int PIVOT[N], the list of pivot rows.  PIVOT[I]
//    must be a value between I and N, reflecting the choice of
//    pivot row on the I-th step.  For no pivoting, set PIVOT[I] = I.
//
//    Output, double PLU[N*N], the matrix.
//
{
  double *a;
  double *l;
  double *p;
  double *pl;
  double *u;

  p = new double[n*n];
  l = new double[n*n];
  u = new double[n*n];

  plu_plu ( n, pivot, p, l, u );

  pl = r8mat_mm_new ( n, n, n, p, l );

  a = r8mat_mm_new ( n, n, n, pl, u );

  delete [] l;
  delete [] p;
  delete [] pl;
  delete [] u;

  return a;
}
//****************************************************************************80

double plu_determinant ( int n, int pivot[] )

//****************************************************************************80
//
//  Purpose:
//
//    PLU_DETERMINANT returns the determinant of the PLU matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int PIVOT[N], the list of pivot rows.  PIVOT[I]
//    must be a value between I and N, reflecting the choice of
//    pivot row on the I-th step.  For no pivoting, set PIVOT[I] = I.
//
//    Output, double PLU_DETERMINANT, the determinant.
//
{
  int found;
  int i;
  int i2;
  int j;
  double *l;
  double *p;
  double t;
  double *u;
  double value;

  p = new double[n*n];
  l = new double[n*n];
  u = new double[n*n];

  plu_plu ( n, pivot, p, l, u );

  value = 1.0;

  for ( i = 0; i < n; i++ )
  {
    value = value * u[i+i*n];
  }

  for ( i = 0; i < n; i++ )
  {
    found = 0;
    for ( i2 = i; i2 < n; i2++ )
    {
      if ( p[i2+i*n] == 1.0 )
      {
        found = 1;
        if ( i2 != i )
        {
          for ( j = 0; j < n; j++ )
          {
            t         = p[i2+j*n];
            p[i2+j*n] = p[i+j*n];
            p[i+j*n]  = t;
          }
          value = - value;
        }
      }
    }

    if ( ! found )
    {
      cerr << "\n";
      cerr << "PLU_DETERMINANT - Fatal error!\n";
      cerr << "  Permutation matrix is illegal.\n";
      exit ( 1 );
    }

  }

  return value;
}
//****************************************************************************80

double *plu_inverse ( int n, int pivot[] )

//****************************************************************************80
//
//  Purpose:
//
//    PLU_INVERSE returns the inverse of a PLU matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int PIVOT[N], the list of pivot rows.  PIVOT[I]
//    must be a value between I and N, reflecting the choice of
//    pivot row on the I-th step.  For no pivoting, set PIVOT[I] = I.
//
//    Output, double PLU_INVERSE[N*N], the inverse matrix.
//
{
  double *a;
  double *l;
  double *l_inverse;
  double *lp_inverse;
  double *p;
  double *p_inverse;
  double *u;
  double *u_inverse;

  p = new double[n*n];
  l = new double[n*n];
  u = new double[n*n];

  plu_plu ( n, pivot, p, l, u );

  p_inverse = r8mat_transpose_new ( n, n, p );

  l_inverse = tri_l1_inverse ( n, l );

  lp_inverse = r8mat_mm_new ( n, n, n, l_inverse, p_inverse );

  u_inverse = tri_u_inverse ( n, u );

  a = r8mat_mm_new ( n, n, n, u_inverse, lp_inverse );
//
//  Free memory.
//
  delete [] l;
  delete [] l_inverse;
  delete [] lp_inverse;
  delete [] p;
  delete [] p_inverse;
  delete [] u;
  delete [] u_inverse;

  return a;
}
//****************************************************************************80

void plu_plu ( int n, int pivot[], double p[], double l[], double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    PLU_PLU returns the PLU factors of the PLU matrix.
//
//  Example:
//
//    Input:
//
//      N = 5
//      PIVOT = ( 1, 3, 3, 5, 5 )
//
//    Output:
//
//      A:
//
//         11            12           13            14           15
//          1.375         9.75        43.25         44.75        46.25
//          2.75         25           26.25         27.5         28.75
//          0.34375       2.4375       7.71875      17.625       73.125
//          0.6875        4.875       15.4375       60           61.5625
//
//      P:
//
//          1             0            0             0            0
//          0             0            1             0            0
//          0             1            0             0            0
//          0             0            0             0            1
//          0             0            0             1            0
//
//      L:
//
//         1              0            0             0            0
//         0.25           1            0             0            0
//         0.125          0.375        1             0            0
//         0.0625         0.1875       0.3125        1            0
//         0.03125        0.09375      0.15625       0.21875      1
//
//      U:
//
//        11             12           13            14           15
//         0             22           23            24           25
//         0              0           33            34           35
//         0              0            0            44           45
//         0              0            0             0           55
//
//  Note:
//
//    The LINPACK routine DGEFA will factor the above A as:
//
//       11             12             13             14             15
//      -0.125          22             23             24             25
//      -0.25           -0.375         33             34             35
//      -0.03125        -0.09375       -0.15625       44             45
//      -0.0625         -0.1875        -0.3125        -0.21875       55
//
//    and the pivot information in the vector IPVT as:
//
//      ( 1, 3, 3, 5, 5 ).
//
//    The LAPACK routine DGETRF will factor the above A as:
//
//      11              12             13             14             15
//      0.25            22             23             24             25
//      0.125            0.375         33             34             35
//      0.0625           0.1875         0.3125        44             45
//      0.03125          0.09375        0.15625        0.21875       55
//
//   and the pivot information in the vector PIVOT as:
//
//     ( 1, 3, 3, 5, 5 ).
//
//  Method:
//
//    The L factor will have unit diagonal, and subdiagonal entries
//    L(I,J) = ( 2 * J - 1 ) / 2^I, which should result in a unique
//    value for every entry.
//
//    The U factor of A will have entries
//    U(I,J) = 10 * I + J, which should result in "nice" entries as long
//    as N < 10.
//
//    The P factor can be deduced by applying the pivoting operations
//    specified by PIVOT in reverse order to the rows of the identity.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int PIVOT[N], the list of pivot rows.  PIVOT[I]
//    must be a value between I and N, reflecting the choice of
//    pivot row on the I-th step.  For no pivoting, set PIVOT[I] = I.
//
//    Output, double P[N*N], L[N*N], U[N*N], the P, L and U factors
//    of A, as defined by Gaussian elimination with partial pivoting.
//    P is a permutation matrix, L is unit lower triangular, and U
//    is upper triangular.
//
{
  int i;
  int j;
  int k;
  double t;
//
//  Check that the pivot vector is legal.
//
  for ( i = 0; i < n; i++ )
  {
    if ( pivot[i] < i )
    {
      cerr << "\n";
      cerr << "PLU_PLU - Fatal error!\n";
      cerr << "  PIVOT[" << i << "] = " << pivot[i] << "\n";
      cerr << "  but PIVOT[I] must be no less than I + 1.\n";
      exit ( 1 );
    }
    else if ( n - 1 < pivot[i] )
    {
      cerr << "\n";
      cerr << "PLU_PLU - Fatal error!\n";
      cerr << "  PIVOT[" << i << "] = " << pivot[i] << "\n";
      cerr << "  but PIVOT[I] must be no greater than N = " << n << "\n";
      exit ( 1 );
    }
  }
//
//  Compute U.
//
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i <= j )
      {
        u[i+j*n] = ( double ) ( 10 * ( i + 1 ) + j + 1 );
      }
      else
      {
        u[i+j*n] = 0.0;
      }
    }
  }
//
//  Compute L.
//
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i < j )
      {
        l[i+j*n] = 0.0;
      }
      else if ( j == i )
      {
        l[i+j*n] = 1.0;
      }
      else
      {
        l[i+j*n] = ( double ) ( 2 * j - 1 ) / ( double ) i4_power ( 2, i );
      }
    }
  }
//
//  Compute P.
//
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i == j )
      {
        p[i+j*n] = 1.0;
      }
      else
      {
        p[i+j*n] = 0.0;
      }
    }
  }
//
//  Apply the pivot permutations, in reverse order.
//
  for ( i = n - 1; 0 <= i; i-- )
  {
    if ( pivot[i] != i + 1 )
    {
      for ( j = 0; j < n; j++ )
      {
        k        = pivot[i] - 1;
        t        = p[i+j*n];
        p[i+j*n] = p[k+j*n];
        p[k+j*n] = t;
      }
    }
  }

  return;
}
//****************************************************************************80

double *poisson ( int nrow, int ncol )

//****************************************************************************80
//
//  Purpose:
//
//    POISSON returns the POISSON matrix.
//
//  Formula:
//
//    if ( I = J )
//      A(I,J) = 4.0
//    else if ( I = J+1 or I = J-1 or I = J+NROW or I = J-NROW )
//      A(I,J) = -1.0
//    else
//      A(I,J) = 0.0
//
//  Example:
//
//    NROW = NCOL = 3
//
//     4 -1  0 | -1  0  0 |  0  0  0
//    -1  4 -1 |  0 -1  0 |  0  0  0
//     0 -1  4 |  0  0 -1 |  0  0  0
//     ----------------------------
//    -1  0  0 |  4 -1  0 | -1  0  0
//     0 -1  0 | -1  4 -1 |  0 -1  0
//     0  0 -1 |  0 -1  4 |  0  0 -1
//     ----------------------------
//     0  0  0 | -1  0  0 |  4 -1  0
//     0  0  0 |  0 -1  0 | -1  4 -1
//     0  0  0 |  0  0 -1 |  0 -1  4
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A results from discretizing Poisson's equation with the
//    5 point operator on a square mesh of N points.
//
//    A has eigenvalues
//
//      LAMBDA(I,J) = 4 - 2 * COS(I*PI/(N+1))
//                      - 2 * COS(J*PI/(M+1)), I = 1 to N, J = 1 to M.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gene Golub, Charles Van Loan,
//    Matrix Computations, second edition,
//    Johns Hopkins University Press, Baltimore, Maryland, 1989
//    (Section 4.5.4).
//
//  Parameters:
//
//    Input, int NROW, NCOL, the number of rows and columns 
//    in the grid.
//
//    Output, double POISSON[(NROW*NCOL)*(NROW*NCOL)], the matrix.
//
{
  double *a;
  int i;
  int i1;
  int j;
  int j1;
  int n;

  n = nrow * ncol;

  a = r8mat_zero_new ( n, n );

  i = 0;

  for ( i1 = 1; i1 <= nrow; i1++ )
  {
    for ( j1 = 1; j1 <= ncol; j1++ )
    {

      if ( 1 < i1 )
      {
        j = i - ncol;
        a[i+j*n] = -1.0;
      }

      if ( 1 < j1 )
      {
        j = i - 1;
        a[i+j*n] = -1.0;
      }

      j = i;
      a[i+j*n] = 4.0;

      if ( j1 < ncol )
      {
        j = i + 1;
        a[i+j*n] = -1.0;
      }

      if ( i1 < nrow )
      {
        j = i + ncol;
        a[i+j*n] = -1.0;
      }
      i = i + 1;
    }
  }
  return a;
}
//****************************************************************************80

double poisson_determinant ( int nrow, int ncol )

//****************************************************************************80
//
//  Purpose:
//
//    POISSON_DETERMINANT returns the determinant of the POISSON matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NROW, NCOL, the number of rows and columns 
//    in the grid.
//
//    Output, double POISSON_DETERMINANT, the determinant.
//
{
  double angle;
  double *cc;
  double *cr;
  double determ;
  int i;
  int j;
  const double r8_pi = 3.141592653589793;

  cr = new double[nrow];

  for ( i = 0; i < nrow; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( nrow + 1 );
    cr[i] = cos ( angle );
  }

  cc = new double[ncol];

  for ( j = 0; j < ncol; j++ )
  {
    angle = ( double ) ( j + 1 ) * r8_pi / ( double ) ( ncol + 1 );
    cc[j] = cos ( angle );
  }

  determ = 1.0;

  for ( i = 0; i < nrow; i++ )
  {
    for ( j = 0; j < ncol; j++ )
    {
      determ = determ * ( 4.0 - 2.0 * cr[i] - 2.0 * cc[j] );
    }
  }
//
//  Free memory.
//
  delete [] cc;
  delete [] cr;

  return determ;
}
//****************************************************************************80

double *poisson_eigenvalues ( int nrow, int ncol )

//****************************************************************************80
//
//  Purpose:
//
//    POISSON_EIGENVALUES returns the eigenvalues of the POISSON matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NROW, NCOL, the number of rows and columns 
//    in the grid.
//
//    Output, double POISSON_EIGENVALUES[NROW*NCOL], the eigenvalues.
//
{
  double angle;
  double *cc;
  double *cr;
  double *lambda;
  int i;
  int j;
  int k;
  const double r8_pi = 3.141592653589793;

  cr = new double[nrow];

  for ( i = 0; i < nrow; i++ )
  {
    angle = ( double ) ( i + 1 ) * r8_pi / ( double ) ( nrow + 1 );
    cr[i] = cos ( angle );
  }

  cc = new double[ncol];

  for ( j = 0; j < ncol; j++ )
  {
    angle = ( double ) ( j + 1 ) * r8_pi / ( double ) ( ncol + 1 );
    cc[j] = cos ( angle );
  }

  lambda = new double[nrow*ncol];

  k = 0;
  for ( i = 0; i < nrow; i++ )
  {
    for ( j = 0; j < ncol; j++ )
    {
      lambda[k] = 4.0 - 2.0 * cr[i] - 2.0 * cc[j];
      k = k + 1;
    }
  }
//
//  Free memory.
//
  delete [] cc;
  delete [] cr;

  return lambda;
}
//****************************************************************************80

double *poisson_rhs ( int nrow, int ncol )

//****************************************************************************80
//
//  Purpose:
//
//    POISSON_RHS returns the right hand side of a Poisson linear system.
//
//  Discussion:
//
//    The Poisson matrix is associated with an NROW by NCOL rectangular 
//    grid of points.
//
//    Assume that the points are numbered from left to right, bottom to top.
//
//    If the K-th point is in row I and column J, set X = I + J.
//
//    This will be the solution to the linear system.
//
//    The right hand side is easily determined from X.  It is 0 for every
//    interior point.
//
//  Example:
//
//    NROW = 3, NCOL = 3
//
//    ^
//    |  7  8  9
//    J  4  5  6
//    |  1  2  3
//    |
//    +-----I---->
//
//    Solution vector X = ( 2, 3, 4, 3, 4, 5, 4, 5, 6 )
//
//    Right hand side B = ( 2, 2, 8, 2, 0, 6, 8, 6, 14 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gene Golub, Charles Van Loan,
//    Matrix Computations, second edition,
//    Johns Hopkins University Press, Baltimore, Maryland, 1989
//    (Section 4.5.4).
//
//  Parameters:
//
//    Input, int NROW, NCOL, the number of rows and columns 
//    in the grid.
//
//    Output, double B[NROW*NCOL], the right hand side.
//
{
  double *b;
  int i;
  int j;
  int k;

  b = new double[nrow*ncol];

  k = 0;
  for ( j = 1; j <= nrow; j++ )
  {
    for ( i = 1; i <= ncol; i++ )
    {
      b[k] = 0.0;
      if ( i == 1 )
      {
        b[k] = b[k] + ( double ) ( i + j - 1 );
      }
      if ( j == 1 )
      {
        b[k] = b[k] + ( double ) ( i + j - 1 );
      }
      if ( i == ncol )
      {
        b[k] = b[k] + ( double ) ( i + j + 1 );
      }
      if ( j == nrow )
      {
        b[k] = b[k] + ( double ) ( i + j + 1 );
      }
      k = k + 1;
    }
  }
  return b;
}
//****************************************************************************80

double *poisson_solution ( int nrow, int ncol )

//****************************************************************************80
//
//  Purpose:
//
//    POISSON_SOLUTION returns the solution of a Poisson linear system.
//
//  Discussion:
//
//    The Poisson matrix is associated with an NROW by NCOL rectangular 
//    grid of points.
//
//    Assume that the points are numbered from left to right, bottom to top.
//
//    If the K-th point is in row I and column J, set X = I + J.
//
//    This will be the solution to the linear system.
//
//  Example:
//
//    NROW = 3, NCOL = 3
//
//    ^
//    |  7  8  9
//    J  4  5  6
//    |  1  2  3
//    |
//    +-----I---->
//
//    Solution vector X = ( 2, 3, 4, 3, 4, 5, 4, 5, 6 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Gene Golub, Charles Van Loan,
//    Matrix Computations, second edition,
//    Johns Hopkins University Press, Baltimore, Maryland, 1989
//    (Section 4.5.4).
//
//  Parameters:
//
//    Input, int NROW, NCOL, the number of rows and columns 
//    in the grid.
//
//    Output, double X[NROW*NCOL], the solution.
//
{
  int i;
  int j;
  int k;
  double *x;

  x = new double[nrow*ncol];

  k = 0;
  for ( j = 1; j <= nrow; j++ )
  {
    for ( i = 1; i <= ncol; i++ )
    {
      x[k] = ( double ) ( i + j );
      k = k + 1;
    }
  }
  return x;
}
//****************************************************************************80

int prime ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    PRIME returns any of the first PRIME_MAX prime numbers.
//
//  Discussion:
//
//    PRIME_MAX is 1600, and the largest prime stored is 13499.
//
//    Thanks to Bart Vandewoestyne for pointing out a typo, 18 February 2005.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 February 2005
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Milton Abramowitz, Irene Stegun,
//    Handbook of Mathematical Functions,
//    US Department of Commerce, 1964,
//    ISBN: 0-486-61272-4,
//    LC: QA47.A34.
//
//    Daniel Zwillinger,
//    CRC Standard Mathematical Tables and Formulae,
//    30th Edition,
//    CRC Press, 1996, pages 95-98.
//
//  Parameters:
//
//    Input, int N, the index of the desired prime number.
//    In general, is should be true that 0 <= N <= PRIME_MAX.
//    N = -1 returns PRIME_MAX, the index of the largest prime available.
//    N = 0 is legal, returning PRIME = 1.
//
//    Output, int PRIME, the N-th prime.  If N is out of range, PRIME
//    is returned as -1.
//
{
# define PRIME_MAX 1600

  int npvec[PRIME_MAX] = {
        2,    3,    5,    7,   11,   13,   17,   19,   23,   29,
       31,   37,   41,   43,   47,   53,   59,   61,   67,   71,
       73,   79,   83,   89,   97,  101,  103,  107,  109,  113,
      127,  131,  137,  139,  149,  151,  157,  163,  167,  173,
      179,  181,  191,  193,  197,  199,  211,  223,  227,  229,
      233,  239,  241,  251,  257,  263,  269,  271,  277,  281,
      283,  293,  307,  311,  313,  317,  331,  337,  347,  349,
      353,  359,  367,  373,  379,  383,  389,  397,  401,  409,
      419,  421,  431,  433,  439,  443,  449,  457,  461,  463,
      467,  479,  487,  491,  499,  503,  509,  521,  523,  541,
      547,  557,  563,  569,  571,  577,  587,  593,  599,  601,
      607,  613,  617,  619,  631,  641,  643,  647,  653,  659,
      661,  673,  677,  683,  691,  701,  709,  719,  727,  733,
      739,  743,  751,  757,  761,  769,  773,  787,  797,  809,
      811,  821,  823,  827,  829,  839,  853,  857,  859,  863,
      877,  881,  883,  887,  907,  911,  919,  929,  937,  941,
      947,  953,  967,  971,  977,  983,  991,  997, 1009, 1013,
     1019, 1021, 1031, 1033, 1039, 1049, 1051, 1061, 1063, 1069,
     1087, 1091, 1093, 1097, 1103, 1109, 1117, 1123, 1129, 1151,
     1153, 1163, 1171, 1181, 1187, 1193, 1201, 1213, 1217, 1223,
     1229, 1231, 1237, 1249, 1259, 1277, 1279, 1283, 1289, 1291, 
     1297, 1301, 1303, 1307, 1319, 1321, 1327, 1361, 1367, 1373, 
     1381, 1399, 1409, 1423, 1427, 1429, 1433, 1439, 1447, 1451, 
     1453, 1459, 1471, 1481, 1483, 1487, 1489, 1493, 1499, 1511, 
     1523, 1531, 1543, 1549, 1553, 1559, 1567, 1571, 1579, 1583, 
     1597, 1601, 1607, 1609, 1613, 1619, 1621, 1627, 1637, 1657, 
     1663, 1667, 1669, 1693, 1697, 1699, 1709, 1721, 1723, 1733, 
     1741, 1747, 1753, 1759, 1777, 1783, 1787, 1789, 1801, 1811, 
     1823, 1831, 1847, 1861, 1867, 1871, 1873, 1877, 1879, 1889,
     1901, 1907, 1913, 1931, 1933, 1949, 1951, 1973, 1979, 1987,
     1993, 1997, 1999, 2003, 2011, 2017, 2027, 2029, 2039, 2053,
     2063, 2069, 2081, 2083, 2087, 2089, 2099, 2111, 2113, 2129,
     2131, 2137, 2141, 2143, 2153, 2161, 2179, 2203, 2207, 2213,
     2221, 2237, 2239, 2243, 2251, 2267, 2269, 2273, 2281, 2287,
     2293, 2297, 2309, 2311, 2333, 2339, 2341, 2347, 2351, 2357, 
     2371, 2377, 2381, 2383, 2389, 2393, 2399, 2411, 2417, 2423, 
     2437, 2441, 2447, 2459, 2467, 2473, 2477, 2503, 2521, 2531, 
     2539, 2543, 2549, 2551, 2557, 2579, 2591, 2593, 2609, 2617, 
     2621, 2633, 2647, 2657, 2659, 2663, 2671, 2677, 2683, 2687, 
     2689, 2693, 2699, 2707, 2711, 2713, 2719, 2729, 2731, 2741,
     2749, 2753, 2767, 2777, 2789, 2791, 2797, 2801, 2803, 2819, 
     2833, 2837, 2843, 2851, 2857, 2861, 2879, 2887, 2897, 2903, 
     2909, 2917, 2927, 2939, 2953, 2957, 2963, 2969, 2971, 2999, 
     3001, 3011, 3019, 3023, 3037, 3041, 3049, 3061, 3067, 3079, 
     3083, 3089, 3109, 3119, 3121, 3137, 3163, 3167, 3169, 3181, 
     3187, 3191, 3203, 3209, 3217, 3221, 3229, 3251, 3253, 3257, 
     3259, 3271, 3299, 3301, 3307, 3313, 3319, 3323, 3329, 3331, 
     3343, 3347, 3359, 3361, 3371, 3373, 3389, 3391, 3407, 3413, 
     3433, 3449, 3457, 3461, 3463, 3467, 3469, 3491, 3499, 3511, 
     3517, 3527, 3529, 3533, 3539, 3541, 3547, 3557, 3559, 3571,
     3581, 3583, 3593, 3607, 3613, 3617, 3623, 3631, 3637, 3643,
     3659, 3671, 3673, 3677, 3691, 3697, 3701, 3709, 3719, 3727,
     3733, 3739, 3761, 3767, 3769, 3779, 3793, 3797, 3803, 3821,
     3823, 3833, 3847, 3851, 3853, 3863, 3877, 3881, 3889, 3907,
     3911, 3917, 3919, 3923, 3929, 3931, 3943, 3947, 3967, 3989,
     4001, 4003, 4007, 4013, 4019, 4021, 4027, 4049, 4051, 4057,
     4073, 4079, 4091, 4093, 4099, 4111, 4127, 4129, 4133, 4139,
     4153, 4157, 4159, 4177, 4201, 4211, 4217, 4219, 4229, 4231,
     4241, 4243, 4253, 4259, 4261, 4271, 4273, 4283, 4289, 4297,
     4327, 4337, 4339, 4349, 4357, 4363, 4373, 4391, 4397, 4409,
     4421, 4423, 4441, 4447, 4451, 4457, 4463, 4481, 4483, 4493, 
     4507, 4513, 4517, 4519, 4523, 4547, 4549, 4561, 4567, 4583, 
     4591, 4597, 4603, 4621, 4637, 4639, 4643, 4649, 4651, 4657, 
     4663, 4673, 4679, 4691, 4703, 4721, 4723, 4729, 4733, 4751, 
     4759, 4783, 4787, 4789, 4793, 4799, 4801, 4813, 4817, 4831, 
     4861, 4871, 4877, 4889, 4903, 4909, 4919, 4931, 4933, 4937, 
     4943, 4951, 4957, 4967, 4969, 4973, 4987, 4993, 4999, 5003, 
     5009, 5011, 5021, 5023, 5039, 5051, 5059, 5077, 5081, 5087, 
     5099, 5101, 5107, 5113, 5119, 5147, 5153, 5167, 5171, 5179, 
     5189, 5197, 5209, 5227, 5231, 5233, 5237, 5261, 5273, 5279,
     5281, 5297, 5303, 5309, 5323, 5333, 5347, 5351, 5381, 5387,
     5393, 5399, 5407, 5413, 5417, 5419, 5431, 5437, 5441, 5443,
     5449, 5471, 5477, 5479, 5483, 5501, 5503, 5507, 5519, 5521,
     5527, 5531, 5557, 5563, 5569, 5573, 5581, 5591, 5623, 5639,
     5641, 5647, 5651, 5653, 5657, 5659, 5669, 5683, 5689, 5693,
     5701, 5711, 5717, 5737, 5741, 5743, 5749, 5779, 5783, 5791,
     5801, 5807, 5813, 5821, 5827, 5839, 5843, 5849, 5851, 5857,
     5861, 5867, 5869, 5879, 5881, 5897, 5903, 5923, 5927, 5939,
     5953, 5981, 5987, 6007, 6011, 6029, 6037, 6043, 6047, 6053,
     6067, 6073, 6079, 6089, 6091, 6101, 6113, 6121, 6131, 6133,
     6143, 6151, 6163, 6173, 6197, 6199, 6203, 6211, 6217, 6221,
     6229, 6247, 6257, 6263, 6269, 6271, 6277, 6287, 6299, 6301,
     6311, 6317, 6323, 6329, 6337, 6343, 6353, 6359, 6361, 6367, 
     6373, 6379, 6389, 6397, 6421, 6427, 6449, 6451, 6469, 6473, 
     6481, 6491, 6521, 6529, 6547, 6551, 6553, 6563, 6569, 6571, 
     6577, 6581, 6599, 6607, 6619, 6637, 6653, 6659, 6661, 6673, 
     6679, 6689, 6691, 6701, 6703, 6709, 6719, 6733, 6737, 6761, 
     6763, 6779, 6781, 6791, 6793, 6803, 6823, 6827, 6829, 6833, 
     6841, 6857, 6863, 6869, 6871, 6883, 6899, 6907, 6911, 6917, 
     6947, 6949, 6959, 6961, 6967, 6971, 6977, 6983, 6991, 6997,
     7001, 7013, 7019, 7027, 7039, 7043, 7057, 7069, 7079, 7103, 
     7109, 7121, 7127, 7129, 7151, 7159, 7177, 7187, 7193, 7207, 
     7211, 7213, 7219, 7229, 7237, 7243, 7247, 7253, 7283, 7297, 
     7307, 7309, 7321, 7331, 7333, 7349, 7351, 7369, 7393, 7411, 
     7417, 7433, 7451, 7457, 7459, 7477, 7481, 7487, 7489, 7499, 
     7507, 7517, 7523, 7529, 7537, 7541, 7547, 7549, 7559, 7561, 
     7573, 7577, 7583, 7589, 7591, 7603, 7607, 7621, 7639, 7643, 
     7649, 7669, 7673, 7681, 7687, 7691, 7699, 7703, 7717, 7723, 
     7727, 7741, 7753, 7757, 7759, 7789, 7793, 7817, 7823, 7829, 
     7841, 7853, 7867, 7873, 7877, 7879, 7883, 7901, 7907, 7919,
     7927, 7933, 7937, 7949, 7951, 7963, 7993, 8009, 8011, 8017,
     8039, 8053, 8059, 8069, 8081, 8087, 8089, 8093, 8101, 8111,
     8117, 8123, 8147, 8161, 8167, 8171, 8179, 8191, 8209, 8219,
     8221, 8231, 8233, 8237, 8243, 8263, 8269, 8273, 8287, 8291,
     8293, 8297, 8311, 8317, 8329, 8353, 8363, 8369, 8377, 8387,
     8389, 8419, 8423, 8429, 8431, 8443, 8447, 8461, 8467, 8501,
     8513, 8521, 8527, 8537, 8539, 8543, 8563, 8573, 8581, 8597,
     8599, 8609, 8623, 8627, 8629, 8641, 8647, 8663, 8669, 8677,
     8681, 8689, 8693, 8699, 8707, 8713, 8719, 8731, 8737, 8741, 
     8747, 8753, 8761, 8779, 8783, 8803, 8807, 8819, 8821, 8831,
     8837, 8839, 8849, 8861, 8863, 8867, 8887, 8893, 8923, 8929,
     8933, 8941, 8951, 8963, 8969, 8971, 8999, 9001, 9007, 9011,
     9013, 9029, 9041, 9043, 9049, 9059, 9067, 9091, 9103, 9109,
     9127, 9133, 9137, 9151, 9157, 9161, 9173, 9181, 9187, 9199,
     9203, 9209, 9221, 9227, 9239, 9241, 9257, 9277, 9281, 9283,
     9293, 9311, 9319, 9323, 9337, 9341, 9343, 9349, 9371, 9377,
     9391, 9397, 9403, 9413, 9419, 9421, 9431, 9433, 9437, 9439,
     9461, 9463, 9467, 9473, 9479, 9491, 9497, 9511, 9521, 9533,
     9539, 9547, 9551, 9587, 9601, 9613, 9619, 9623, 9629, 9631,
     9643, 9649, 9661, 9677, 9679, 9689, 9697, 9719, 9721, 9733,
     9739, 9743, 9749, 9767, 9769, 9781, 9787, 9791, 9803, 9811,
     9817, 9829, 9833, 9839, 9851, 9857, 9859, 9871, 9883, 9887,
     9901, 9907, 9923, 9929, 9931, 9941, 9949, 9967, 9973,10007,
    10009,10037,10039,10061,10067,10069,10079,10091,10093,10099,
    10103,10111,10133,10139,10141,10151,10159,10163,10169,10177,
    10181,10193,10211,10223,10243,10247,10253,10259,10267,10271,
    10273,10289,10301,10303,10313,10321,10331,10333,10337,10343,
    10357,10369,10391,10399,10427,10429,10433,10453,10457,10459,
    10463,10477,10487,10499,10501,10513,10529,10531,10559,10567,
    10589,10597,10601,10607,10613,10627,10631,10639,10651,10657,
    10663,10667,10687,10691,10709,10711,10723,10729,10733,10739,
    10753,10771,10781,10789,10799,10831,10837,10847,10853,10859,
    10861,10867,10883,10889,10891,10903,10909,10937,10939,10949,
    10957,10973,10979,10987,10993,11003,11027,11047,11057,11059,
    11069,11071,11083,11087,11093,11113,11117,11119,11131,11149,
    11159,11161,11171,11173,11177,11197,11213,11239,11243,11251,
    11257,11261,11273,11279,11287,11299,11311,11317,11321,11329,
    11351,11353,11369,11383,11393,11399,11411,11423,11437,11443,
    11447,11467,11471,11483,11489,11491,11497,11503,11519,11527,
    11549,11551,11579,11587,11593,11597,11617,11621,11633,11657,
    11677,11681,11689,11699,11701,11717,11719,11731,11743,11777,
    11779,11783,11789,11801,11807,11813,11821,11827,11831,11833,
    11839,11863,11867,11887,11897,11903,11909,11923,11927,11933,
    11939,11941,11953,11959,11969,11971,11981,11987,12007,12011,
    12037,12041,12043,12049,12071,12073,12097,12101,12107,12109,
    12113,12119,12143,12149,12157,12161,12163,12197,12203,12211,
    12227,12239,12241,12251,12253,12263,12269,12277,12281,12289,
    12301,12323,12329,12343,12347,12373,12377,12379,12391,12401,
    12409,12413,12421,12433,12437,12451,12457,12473,12479,12487,
    12491,12497,12503,12511,12517,12527,12539,12541,12547,12553,
    12569,12577,12583,12589,12601,12611,12613,12619,12637,12641, 
    12647,12653,12659,12671,12689,12697,12703,12713,12721,12739, 
    12743,12757,12763,12781,12791,12799,12809,12821,12823,12829, 
    12841,12853,12889,12893,12899,12907,12911,12917,12919,12923, 
    12941,12953,12959,12967,12973,12979,12983,13001,13003,13007, 
    13009,13033,13037,13043,13049,13063,13093,13099,13103,13109, 
    13121,13127,13147,13151,13159,13163,13171,13177,13183,13187, 
    13217,13219,13229,13241,13249,13259,13267,13291,13297,13309, 
    13313,13327,13331,13337,13339,13367,13381,13397,13399,13411, 
    13417,13421,13441,13451,13457,13463,13469,13477,13487,13499 };

  if ( n == -1 )
  {
    return PRIME_MAX;
  }
  else if ( n == 0 )
  {
    return 1;
  }
  else if ( n <= PRIME_MAX )
  {
    return npvec[n-1];
  }
  else
  {
    cerr << "\n";
    cerr << "PRIME - Fatal error!\n";
    cerr << "  Unexpected input value of n = " << n << "\n";
    exit ( 1 );
  }

  return 0;
# undef PRIME_MAX
}
//****************************************************************************80

double *prolate ( double alpha, int n )

//****************************************************************************80
//
//  Purpose:
//
//    PROLATE returns the PROLATE matrix.
//
//  Formula:
//
//    If ( I == J ) then
//      A(I,J) = 2 * ALPHA
//    else
//      K = abs ( I - J ) + 1
//      A(I,J) = sin ( 2 * pi * ALPHA * K ) / ( pi * K )
//
//  Example:
//
//    N = 5, ALPHA = 0.25
//
//     0.5        0.0       -0.106103   0.0        0.0636620
//     0.0        0.5        0.0       -0.106103   0.0
//    -0.106103   0.0        0.5        0.0       -0.106103
//     0.0       -0.106103   0.0        0.5        0.0
//     0.0636620  0.0       -0.106103   0.0        0.5
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is centrosymmetric: A(I,J) = A(N+1-I,N+1-J).
//
//    A is Toeplitz: constant along diagonals.
//
//    If 0 < ALPHA < 0.5, then
//      A is positive definite,
//      the eigenvalues of A are distinct,
//      the eigenvalues lie in (0,1) and cluster around 0 and 1.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    James Varah,
//    The Prolate Matrix,
//    Linear Algebra and Applications,
//    Volume 187, pages 269-278, 1993.
//
//  Parameters:
//
//    Input, double ALPHA, the parameter.
//
//    Input, int N, the order of the matrix.
//
//    Output, double PROLATE[N*N], the matrix.
//
{
  double *a;
  double angle;
  int i;
  int j;
  int k;
  const double r8_pi = 3.141592653589793;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[i+j*n] = 2.0 * alpha;
      }
      else
      {
        k = abs ( i - j ) + 1;
        angle = 2.0 * r8_pi * alpha * ( double ) ( k );
        a[i+j*n] = sin (  angle ) / ( r8_pi * ( double ) ( k ) );
      }
    }
  }
  return a;
}
//****************************************************************************80

double *quaternion_i ( )

//****************************************************************************80
//
//  Purpose:
//
//    QUATERNION_I returns a 4 by 4 matrix that behaves like the quaternion unit I.
//
//  Formula:
//
//    0  1  0  0
//   -1  0  0  0
//    0  0  0 -1
//    0  0  1  0
//
//  Properties:
//
//    I * 1 =   I
//    I * I = - 1
//    I * J =   K
//    I * K = - J
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double QUATERNION_I[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
    0.0, -1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,  0.0,
    0.0,  0.0,  0.0,  1.0,
    0.0,  0.0, -1.0,  0.0 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double *quaternion_j ( )

//****************************************************************************80
//
//  Purpose:
//
//    QUATERNION_J returns a 4 by 4 matrix that behaves like the quaternion unit J.
//
//  Formula:
//
//    0  0  1  0
//    0  0  0  1
//   -1  0  0  0
//    0 -1  0  0
//
//  Properties:
//
//    J * 1 =   J
//    J * I = - K
//    J * J = - 1
//    J * K =   I
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 March 2001
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double QUATERNION_J[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
    0.0,  0.0, -1.0,  0.0,
    0.0,  0.0,  0.0, -1.0,
    1.0,  0.0,  0.0,  0.0,
    0.0,  1.0,  0.0,  0.0 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double *quaternion_k ( )

//****************************************************************************80
//
//  Purpose:
//
//    QUATERNION_K returns a 4 by 4 matrix that behaves like the quaternion unit K.
//
//  Formula:
//
//    0  0  0  1
//    0  0 -1  0
//    0  1  0  0
//   -1  0  0  0
//
//  Properties:
//
//    K * 1 =   K
//    K * I =   J
//    K * J = - I
//    K * K = - 1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 March 2001
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double QUATERNION_K[4*4], the matrix.
//
{
  double *a;
//
//  Note that the matrix entries are listed by column.
//
  static double a_save[4*4] = {
    0.0,  0.0,  0.0, -1.0,
    0.0,  0.0,  1.0,  0.0,
    0.0, -1.0,  0.0,  0.0,
    1.0,  0.0,  0.0,  0.0 };

  a = r8mat_copy_new ( 4, 4, a_save );

  return a;
}
//****************************************************************************80

double r8_choose ( int n, int k )

//****************************************************************************80
//
//  Purpose:
//
//    R8_CHOOSE computes the binomial coefficient C(N,K) as an R8.
//
//  Discussion:
//
//    The value is calculated in such a way as to avoid overflow and
//    roundoff.  The calculation is done in R8 arithmetic.
//
//    The formula used is:
//
//      C(N,K) = N! / ( K! * (N-K)! )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    24 March 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    ML Wolfson, HV Wright,
//    Algorithm 160:
//    Combinatorial of M Things Taken N at a Time,
//    Communications of the ACM,
//    Volume 6, Number 4, April 1963, page 161.
//
//  Parameters:
//
//    Input, int N, K, the values of N and K.
//
//    Output, double R8_CHOOSE, the number of combinations of N
//    things taken K at a time.
//
{
  int i;
  int mn;
  int mx;
  int value;

  mn = i4_min ( k, n - k );

  if ( mn < 0 )
  {
    value = 0.0;
  }
  else if ( mn == 0 )
  {
    value = 1.0;
  }
  else
  {
    mx = i4_max ( k, n - k );
    value = ( double ) ( mx + 1 );

    for ( i = 2; i <= mn; i++ )
    {
      value = ( value * ( double ) ( mx + i ) ) / ( double ) i;
    }
  }
  return value;
}
//****************************************************************************80

double r8_cube_root ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    r8_cube_root() returns the cube root of an R8.
//
//  Discussion:
//
//    This routine is designed to avoid the possible problems that can occur
//    when formulas like 0.0^(1/3) or (-1.0)^(1/3) are to be evaluated.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 April 2004
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the number whose cube root is desired.
//
//  Output:
//
//    double R8_CUBE_ROOT, the cube root of X.
//
{
  double value;

  if ( 0.0 < x )
  {
    value = pow ( ( double ) x, ( 1.0 / 3.0 ) );
  }
  else if ( x == 0.0 )
  {
    value = 0.0;
  }
  else
  {
    value = - pow ( ( double ) ( fabs ( x ) ), ( 1.0 / 3.0 ) );
  }

  return value;
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

double r8_factorial ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8_FACTORIAL computes the factorial of N.
//
//  Discussion:
//
//    factorial ( N ) = product ( 1 <= I <= N ) I
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 January 1999
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the argument of the factorial function.
//    If N is less than 1, the function value is returned as 1.
//
//    Output, double R8_FACTORIAL, the factorial of N.
//
{
  int i;
  double value;

  value = 1.0;

  for ( i = 1; i <= n; i++ )
  {
    value = value * ( double ) ( i );
  }

  return value;
}
//****************************************************************************80

double r8_huge ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_HUGE returns a "huge" R8.
//
//  Discussion:
//
//    The value returned by this function is NOT required to be the
//    maximum representable R8.  This value varies from machine to machine,
//    from compiler to compiler, and may cause problems when being printed.
//    We simply want a "very large" but non-infinite number.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 October 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double R8_HUGE, a "huge" R8 value.
//
{
  double value;

  value = 1.0E+30;

  return value;
}
//****************************************************************************80

double r8_max ( double x, double y )

//****************************************************************************80
//
//  Purpose:
//
//    R8_MAX returns the maximum of two R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, Y, the quantities to compare.
//
//    Output, double R8_MAX, the maximum of X and Y.
//
{
  double value;

  if ( y < x )
  {
    value = x;
  }
  else
  {
    value = y;
  }
  return value;
}
//****************************************************************************80

double r8_mop ( int i )

//****************************************************************************80
//
//  Purpose:
//
//    R8_MOP returns the I-th power of -1 as an R8 value.
//
//  Discussion:
//
//    An R8 is an double value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 November 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the power of -1.
//
//    Output, double R8_MOP, the I-th power of -1.
//
{
  double value;

  if ( ( i % 2 ) == 0 )
  {
    value = 1.0;
  }
  else
  {
    value = -1.0;
  }

  return value;
}
//****************************************************************************80

int r8_nint ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_NINT returns the nearest integer to an R8.
//
//  Example:
//
//        X         Value
//
//      1.3         1
//      1.4         1
//      1.5         1 or 2
//      1.6         2
//      0.0         0
//     -0.7        -1
//     -1.1        -1
//     -1.6        -2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the value.
//
//    Output, int R8_NINT, the nearest integer to X.
//
{
  int value;

  if ( x < 0.0 )
  {
    value = - ( int ) ( fabs ( x ) + 0.5 );
  }
  else
  {
    value =   ( int ) ( fabs ( x ) + 0.5 );
  }

  return value;
}
//****************************************************************************80

double r8_normal_01 ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8_NORMAL_01 samples the standard normal probability distribution.
//
//  Discussion:
//
//    The standard normal probability distribution function (PDF) has 
//    mean 0 and standard deviation 1.
//
//    The Box-Muller method is used, which is efficient, but 
//    generates two values at a time.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 September 2004
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int &SEED, a seed for the random number generator.
//
//  Output:
//
//    double R8_NORMAL_01, a normally distributed random value.
//
//    int &SEED, an updated seed.
//
{
  const double r8_pi = 3.141592653589793;
  double r1;
  double r2;
  static int used = -1;
  double x;
  static double y = 0.0;

  if ( used == -1 )
  {
    used = 0;
  }
//
//  If we've used an even number of values so far, generate two more, return one,
//  and save one.
//
  if ( ( used % 2 )== 0 )
  {
    for ( ; ; )
    {
      r1 = r8_uniform_01 ( seed );
      if ( r1 != 0.0 )
      {
        break;
      }
    }

    r2 = r8_uniform_01 ( seed );

    x = sqrt ( -2.0 * log ( r1 ) ) * cos ( 2.0 * r8_pi * r2 );
    y = sqrt ( -2.0 * log ( r1 ) ) * sin ( 2.0 * r8_pi * r2 );
  }
  else
  {
    x = y;
  }

  used = used + 1;

  return x;
}
//****************************************************************************80

double r8_sign ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_SIGN returns the sign of an R8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 October 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the number whose sign is desired.
//
//    Output, double R8_SIGN, the sign of X.
//
{
  double value;

  if ( x < 0.0 )
  {
    value = -1.0;
  } 
  else
  {
    value = 1.0;
  }
  return value;
}
//****************************************************************************80

double r8_uniform_ab ( double b, double c, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8_UNIFORM_AB returns a scaled pseudorandom R8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    17 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double B, C, the minimum and maximum values.
//
//    int &SEED, a seed for the random number generator.
//
//  Output:
//
//    double R8_UNIFORM_AB, the randomly chosen value.
//
//    int &SEED, an updated seed.
//
{
  double t;

  t = r8_uniform_01 ( seed );

  t = ( 1.0 - t ) * b + t * c;

  return t;
}
//****************************************************************************80

double r8_uniform_01 ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8_UNIFORM_01 returns a unit pseudorandom R8.
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
//    If the initial seed is 12345, then the first three computations are
//
//      Input     Output      R8_UNIFORM_01
//      SEED      SEED
//
//         12345   207482415  0.096616
//     207482415  1790989824  0.833995
//    1790989824  2035175616  0.947702
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 August 2004
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
//  Input:
//
//    int &SEED, the "seed" value.
//
//  Output:
//
//    double R8_UNIFORM_01, a new pseudorandom variate, 
//    strictly between 0 and 1.
//
//    int &SEED, an updated seed.
{
  int i4_huge = 2147483647;
  int k;
  double r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8_UNIFORM_01 - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )
  {
    seed = seed + i4_huge;
  }

  r = ( double ) ( seed ) * 4.656612875E-10;

  return r;
}
//****************************************************************************80

void r8col_swap ( int m, int n, double a[], int j1, int j2 )

//****************************************************************************80
//
//  Purpose:
//
//    R8COL_SWAP swaps columns J1 and J2 of an R8COL.
//
//  Discussion:
//
//    An R8COL is an M by N array of R8's, regarded
//    as an array of N columns of length M.
//
//  Example:
//
//    Input:
//
//      M = 3, N = 4, J1 = 2, J2 = 4
//
//      A = (
//        1.  2.  3.  4.
//        5.  6.  7.  8.
//        9. 10. 11. 12. )
//
//    Output:
//
//      A = (
//        1.  4.  3.  2.
//        5.  8.  7.  6.
//        9. 12. 11. 10. )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 October 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int M, N, the number of rows and columns.
//
//    double A[M*N], the M by N array.
//
//    int J1, J2, the columns to be swapped.
//    These columns are 1-based.
//
//  Output:
//
//    double A[M*N}: the array after column swapping.
//
{
  int i;
  double temp;

  if ( j1 < 1 || n < j1 || j2 < 1 || n < j2 )
  {
    cerr << "\n";
    cerr << "R8COL_SWAP - Fatal error!\n";
    cerr << "  J1 or J2 is out of bounds.\n";
    cerr << "  J1 =   " << j1 << "\n";
    cerr << "  J2 =   " << j2 << "\n";
    cerr << "  NCOL = " << n << "\n";
    exit ( 1 );
  }

  if ( j1 == j2 )
  {
    return;
  }

  for ( i = 0; i < m; i++ )
  {
    temp          = a[i+(j1-1)*m];
    a[i+(j1-1)*m] = a[i+(j2-1)*m];
    a[i+(j2-1)*m] = temp;
  }

  return;
}
//****************************************************************************80

double *r8col_to_r8vec ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8COL_TO_R8VEC converts an R8COL to an R8VEC.
//
//  Discussion:
//
//    An R8COL is an M by N array of double precision values, regarded
//    as an array of N columns of length M.
//
//    This routine is not really useful in our C++ implementation, since
//    we actually store an M by N matrix exactly as a vector already.
//
//  Example:
//
//    M = 3, N = 4
//
//    A =
//      11 12 13 14
//      21 22 23 24
//      31 32 33 34
//
//    R8COL_TO_R8VEC = ( 11, 21, 31, 12, 22, 32, 13, 23, 33, 14, 24, 34 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 December 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, double A[M*N], the M by N array.
//
//    Output, double X[M*N], a vector containing the N columns of A.
//
{
  int i;
  int j;
  int k;
  double *x;

  x = new double[m*n];

  k = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      x[k] = a[i+j*m];
      k = k + 1;
    }
  }

  return x;
}
//****************************************************************************80

void r8mat_copy ( int m, int n, double a1[], double a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_COPY copies one R8MAT to another.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 October 2005
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
//    Output, double A2[M*N], the copy of A1.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }

  return;
}
//****************************************************************************80

double *r8mat_copy_new ( int m, int n, double a1[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_COPY_NEW copies one R8MAT to another.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
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

double r8mat_determinant ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_DETETMINANT computes the determinant of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double A[N*N], the matrix whose determinant is desired.
//
//    Output, double R8MAT_DETERMINANT, the determinant of the matrix.
//
{
  double *b;
  double determ;
  int *pivot;

  b = r8mat_copy_new ( n, n, a );

  pivot = new int[n];

  r8mat_gefa ( b, n, pivot );

  determ = r8mat_gedet ( b, n, pivot );
//
//  Free memory.
//
  delete [] b;
  delete [] pivot;

  return determ;
}
//****************************************************************************80

double *r8mat_diag_get_vector ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_DIAG_GET_VECTOR gets the value of the diagonal of an R8MAT.
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
//    07 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of rows and columns of the matrix.
//
//    Input, double A[N*N], the N by N matrix.
//
//    Output, double R8MAT_DIAG_GET_VECTOR[N], the diagonal entries
//    of the matrix.
//
{
  int i;
  double *v;

  v = new double[n];

  for ( i = 0; i < n; i++ )
  {
    v[i] = a[i+i*n];
  }

  return v;
}
//****************************************************************************80

double r8mat_gedet ( double a[], int n, int pivot[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_GEDET computes the determinant of an R8MAT factored by R8MAT_GEFA.
//
//  Discussion:
//
//    An R8MAT is a matrix of R8 values.
//
//    This is a modified version of the LINPACK routine DGEDI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Jack Dongarra, Jim Bunch, Cleve Moler, Pete Stewart,
//    LINPACK User's Guide,
//    SIAM, 1979
//
//  Parameters:
//
//    Input, double A[N*N], the LU factors from R8MAT_GEFA.
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, int PIVOT[N], as computed by R8MAT_GEFA.
//
//    Output, double R8MAT_GEDET, the determinant of the matrix.
//
{
  double determ;
  int i;

  determ = 1.0;

  for ( i = 0; i < n; i++ )
  {
    determ = determ * a[i+i*n];
    if ( pivot[i] != i + 1 )
    {
      determ = - determ;
    }
  }
  return determ;
}
//****************************************************************************80

int r8mat_gefa ( double a[], int n, int pivot[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_GEFA factors an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//    This is a simplified version of the LINPACK routine DGEFA.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
//    LINPACK User's Guide,
//    SIAM, (Society for Industrial and Applied Mathematics),
//    3600 University City Science Center,
//    Philadelphia, PA, 19104-2688.
//    ISBN 0-89871-172-X
//
//  Input:
//
//    double A[N*N], the matrix to be factored.
//
//    int N, the order of the matrix.
//    N must be positive.
//
//  Output:
//
//    double A[N*N]: an upper triangular matrix and the multipliers
//    which were used to obtain it.  The factorization can be written
//    A = L * U, where L is a product of permutation and unit lower
//    triangular matrices and U is upper triangular.
//
//    int PIVOT[N], a vector of pivot indices.
//
//    int R8MAT_GEFA, singularity flag.
//    0, no singularity detected.
//    nonzero, the factorization failed on the INFO-th step.
//
{
  bool debug = false;
  int i;
  int info;
  int j;
  int k;
  int l;
  double temp;

  info = 0;

  for ( i = 0; i < n; i++ )
  {
    pivot[i] = i + 1;
  }

  for ( k = 1; k <= n - 1; k++ )
  {
//
//  Find L, the index of the pivot row.
//
    l = k;
    for ( i = k + 1; i <= n; i++ )
    {
      if ( fabs ( a[l-1+(k-1)*n] ) < fabs ( a[i-1+(k-1)*n] ) )
      {
        l = i;
      }
    }
    pivot[k-1] = l;
//
//  If the pivot index is zero, the algorithm has failed.
//
    if ( a[l-1+(k-1)*n] == 0.0 )
    {
      info = k;
      if ( debug )
      {
        cout << "\n";
        cout << "R8MAT_GEFA - Warning!\n";
        cout << "  Zero pivot on step " << info << "\n";
      }
      return info;
    }
//
//  Interchange rows L and K if necessary.
//
    if ( l != k )
    {
      temp           = a[l-1+(k-1)*n];
      a[l-1+(k-1)*n] = a[k-1+(k-1)*n];
      a[k-1+(k-1)*n] = temp;
    }
//
//  Normalize the values that lie below the pivot entry A(K,K).
//
    for ( i = k + 1; i <= n; i++ )
    {
      a[i-1+(k-1)*n] = - a[i-1+(k-1)*n] / a[k-1+(k-1)*n];
    }
//
//  Row elimination with column indexing.
//
    for ( j = k + 1; j <= n; j++ )
    {
      if ( l != k )
      {
        temp           = a[l-1+(j-1)*n];
        a[l-1+(j-1)*n] = a[k-1+(j-1)*n];
        a[k-1+(j-1)*n] = temp;
      }
      for ( i = k + 1; i <= n; i++ )
      {
        a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + a[i-1+(k-1)*n] * a[k-1+(j-1)*n];
      }
    }
  }

  pivot[n-1] = n;

  if ( a[n-1+(n-1)*n] == 0.0 )
  {
    info = n;
    if ( debug )
    {
      cout << "\n";
      cout << "R8MAT_GEFA - Warning!\n";
      cout << "  Zero pivot on step " << info << "\n";
    }
  }
  return info;
}
//****************************************************************************80

void r8mat_geinverse ( double a[], int n, int pivot[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_GEINVERSE computes the inverse of an R8MAT factored by R8MAT_GEFA.
//
//  Discussion:
//
//    An R8MAT is a matrix of doubles.
//
//    R8MAT_GEINVERSE is a modified version of the LINPACK routine DGEDI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Jack Dongarra, Cleve Moler, Jim Bunch, Pete Stewart,
//    LINPACK User's Guide,
//    SIAM, (Society for Industrial and Applied Mathematics),
//    3600 University City Science Center,
//    Philadelphia, PA, 19104-2688.
//    ISBN 0-89871-172-X
//
//  Input:
//
//    double A[N*N], factor information computed by R8MAT_GEFA.
//
//    int N, the order of the matrix A.
//
//    int PIVOT[N], the pivot vector from R8MAT_GEFA.
//
//  Output:
//
//    double A[N*N]: the inverse matrix.
//
{
  int i;
  int j;
  int k;
  double temp;
  double *work;
//
//  Compute Inverse(U).
//
  work = new double[n];

  for ( k = 1; k <= n; k++ )
  {
    a[k-1+(k-1)*n] = 1.0 / a[k-1+(k-1)*n];

    for ( i = 1; i <= k - 1; i++ )
    {
      a[i-1+(k-1)*n] = - a[i-1+(k-1)*n] * a[k-1+(k-1)*n];
    }
    for ( j = k + 1; j <= n; j++ )
    {
      temp = a[k-1+(j-1)*n];
      a[k-1+(j-1)*n] = 0.0;
      for ( i = 1; i <= k; i++ )
      {
        a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + temp * a[i-1+(k-1)*n];
      }
    }
  }
//
//  Form Inverse(U) * Inverse(L).
//
  for ( k = n - 1; 1 <= k; k-- )
  {
    for ( i = k + 1; i <= n; i++ )
    {
      work[i-1] = a[i-1+(k-1)*n];
      a[i-1+(k-1)*n] = 0.0;
    }
    for ( j = k + 1; j <= n; j++ )
    {
      for ( i = 1; i <= n; i++ )
      {
        a[i-1+(k-1)*n] = a[i-1+(k-1)*n] + work[j-1] * a[i-1+(j-1)*n];
      }
    }

    if ( pivot[k-1] != k )
    {
      for ( i = 1; i <= n; i++ )
      {
        temp                    = a[i-1+(k-1)*n];
        a[i-1+(k-1)*n]          = a[i-1+(pivot[k-1]-1)*n];
        a[i-1+(pivot[k-1]-1)*n] = temp;
      }
    }
  }
//
//  Free memory.
//
  delete [] work;

  return;
}
//****************************************************************************80

void r8mat_house_axh ( int n, double a[], double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_HOUSE_AXH computes A*H where H is a compact Householder matrix.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    The Householder matrix H(V) is defined by
//
//      H(V) = I - 2 * v * v' / ( v' * v )
//
//    This routine is not particularly efficient.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of A.
//
//    double A[N*N]: the matrix to be postmultiplied.
//
//    double V[N], a vector defining a Householder matrix.
//
//  Output:
//
//    double A[N*N]: A has been replaced by A*H.
//
{
  double *ah;
  int i;
  int j;
  int k;
  double v_normsq;

  v_normsq = 0.0;
  for ( i = 0; i < n; i++ )
  {
    v_normsq = v_normsq + v[i] * v[i];
  }
//
//  Compute A*H' = A*H
//
  ah = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      ah[i+j*n] = a[i+j*n];
      for ( k = 0; k < n; k++ )
      {
        ah[i+j*n] = ah[i+j*n] - 2.0 * a[i+k*n] * v[k] * v[j] / v_normsq;
      }
    }
  }
//
//  Copy A = AH;
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = ah[i+j*n];
    }
  }
//
//  Free memory.
//
  delete [] ah;

  return;
}
//****************************************************************************80

double *r8mat_house_axh_new ( int n, double a[], double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_HOUSE_AXH_NEW computes A*H where H is a compact Householder matrix.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    The Householder matrix H(V) is defined by
//
//      H(V) = I - 2 * v * v' / ( v' * v )
//
//    This routine is not particularly efficient.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of A.
//
//    Input, double A[N*N], the matrix to be postmultiplied.
//
//    Input, double V[N], a vector defining a Householder matrix.
//
//    Output, double R8MAT_HOUSE_AXH[N*N], the product A*H.
//
{
  double *ah;
  int i;
  int j;
  int k;
  double v_normsq;

  v_normsq = 0.0;
  for ( i = 0; i < n; i++ )
  {
    v_normsq = v_normsq + v[i] * v[i];
  }
//
//  Compute A*H' = A*H
//
  ah = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      ah[i+j*n] = a[i+j*n];
      for ( k = 0; k < n; k++ )
      {
        ah[i+j*n] = ah[i+j*n] - 2.0 * a[i+k*n] * v[k] * v[j] / v_normsq;
      }
    }
  }
  return ah;
}
//****************************************************************************80

double *r8mat_house_form ( int n, double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_HOUSE_FORM constructs a Householder matrix from its compact form.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    H(v) = I - 2 * v * v' / ( v' * v )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    07 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double V[N], the vector defining the Householder matrix.
//
//    Output, double R8MAT_HOUSE_FORM[N*N], the Householder matrix.
//
{
  double beta;
  double *h;
  int i;
  int j;
//
//  Compute the L2 norm of V.
//
  beta = 0.0;
  for ( i = 0; i < n; i++ )
  {
    beta = beta + v[i] * v[i];
  }
//
//  Form the matrix H.
//
  h = r8mat_identity ( n );

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      h[i+j*n] = h[i+j*n] - 2.0 * v[i] * v[j] / beta;
    }
  }
  return h;
}
//****************************************************************************80

double *r8mat_identity ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IDENTITY sets the square matrix A to the identity.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of A.
//
//    Output, double A[N*N], the N by N identity matrix.
//
{
  double *a;
  int i;
  int j;
  int k;

  a = new double[n*n];

  k = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j )
      {
        a[k] = 1.0;
      }
      else
      {
        a[k] = 0.0;
      }
      k = k + 1;
    }
  }
  return a;
}
//****************************************************************************80

double *r8mat_inverse ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_INVERSE computes the inverse of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix A.
//
//    Input, double A[N*N], the matrix.
//
//    Output, double R8MAT_INVERSE[N*N], the inverse matrix.
//
{
  double *b;
  int info;
  int *pivot;

  b = r8mat_copy_new ( n, n, a );

  pivot = new int[n];

  info = r8mat_gefa ( b, n, pivot );

  if ( info == 0 )
  {
    r8mat_geinverse ( b, n, pivot );
  }
//
//  Free memory.
//
  delete [] pivot;

  return b;
}
//****************************************************************************80

int r8mat_is_adjacency ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_ADJACENCY checks whether an R8MAT is an adjacency matrix.
//
//  Discussion:
//
//    An R8MAT is a matrix of double precision real values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, int R8MAT_IS_ADJACENCY:
//    -1, the matrix is not an adjacency matrix.
//    1, the matrix is an adjacency matrix.
//
{
  double error_frobenius;
  int ival;
  int jval;
  double tol = 0.00001;

  ival = 1;

  if ( ! r8mat_is_square ( m, n, a ) )
  {
    ival = -1;
    return ival;
  }

  error_frobenius = r8mat_is_symmetric ( m, n, a );

  if ( tol < error_frobenius )
  {
    ival = -1;
    return ival;
  }

  jval = r8mat_is_zero_one ( m, n, a );

  if ( jval != 1 )
  {
    ival = -1;
    return ival;
  }

  return ival;
}
//****************************************************************************80

int r8mat_is_anticirculant ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_ANTICIRCULANT checks whether an R8MAT is an anticirculant matrix.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, int R8MAT_IS_ANTICIRCULANT:
//    -1, the matrix is not anticirculant.
//    1, the matrix is anticirculant.
//
{
  int i;
  int ival;
  int j;
  int k;

  ival = 1;

  for ( i = 1; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      k = ( j + i ) % n;

      if ( a[i+j*m] != a[0+k*m] )
      {
        ival = -1;
        return ival;
      }
    }
  }

  return ival;
}
//****************************************************************************80

double r8mat_is_antipersymmetric ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_ANTIPERSYMMETRIC checks an R8MAT for antipersymmetry.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//    A is antipersymmetric if A(I,J) = -A(N+1-J,N+1-I).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, double R8MAT_IS_ANTIPERSYMMETRIC, is 0.0 if the matrix
//    is exactly antipersymmetric.
//
{
  int i;
  int j;
  double error_frobenius;
  const double r8_huge = 1.79769313486231571E+308;

  if ( ! r8mat_is_square ( m, n, a ) )
  {
    error_frobenius = r8_huge;
    return error_frobenius;
  }

  error_frobenius = 0.0;

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      error_frobenius = error_frobenius 
        + pow ( a[i+j*m] + a[n-1-j+(m-1-i)*m], 2 );
    }
  }

  error_frobenius = sqrt ( error_frobenius );

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_antisymmetric ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_ANTISYMMETRIC checks an R8MAT for antisymmetry.
//
//  Discussion:
//
//    An R8MAT is a matrix of double precision real values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double A[M*N], the matrix.
//
//    Output, double RMAT_IS_ANTISYMMETRIC, measures the 
//    Frobenius norm of ( A + A' ), which would be zero if the matrix
//    were exactly symmetric.
//
{
  int i;
  int j;
  const double r8_huge = 1.79769313486231571E+308;
  double value;

  if ( ! r8mat_is_square ( m, n, a ) )
  {
    value = r8_huge;
    return value;
  }

  value = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      value = value + pow ( a[i+j*m] + a[j+i*m], 2 );
    }
  }
  value = sqrt ( value );

  return value;
}
//****************************************************************************80

int r8mat_is_diagonally_dominant ( int n, double a[] )

//*****************************************************************************/
//
//  Purpose:
//
//    R8MAT_IS_DIAGONALLY_DOMINANT checks whether an R8MAT is diagonally dominant.
//
//  Discussion:
//
//    The matrix is required to be square.
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the row and column dimensions of 
//    the matrix.  N must be positive.
//
//    Input, double A[N*N], the matrix.
//
//    Output, int R8MAT_IS_DIAGONALLY_DOMINANT:
//    -1, the matrix is not diagonally dominant.
//    1, the matrix is diagonally dominant.
//    2, the matrix is strictly diagonally dominant.
//
{
  int i;
  int j;
  int k;
  double s;
  double sumi;
  double sumj;
  int value;

  value = 2;

  for ( k = 0; k < n; k++ )
  {
    s = fabs ( a[k+k*n] );
    sumj = 0.0;
    for ( j = 0; j < n; j++ )
    {
      if ( j != k )
      {
        sumj = sumj + fabs ( a[k+j*n] );
      }
    }

    sumi = 0.0;
    for ( i = 0; i < n; i++ )
    {
      if ( i != k )
      {
        sumi = sumi + fabs ( a[i+k*n] );
      }
    }

    if ( s < sumi || s < sumj )
    {
      value = -1;
      return value;
    }
    else if ( s == sumi || s == sumj )
    {
      value = 1;
    }

  }

  return value;
}
//****************************************************************************80

int r8mat_is_diagonally_dominant_column ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_DIAGONALLY_DOMINANT_COLUMN: is an R8MAT column diagonally dominant.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, int R8MAT_IS_DIAGONALLY_DOMINANT_COLUMN:
//    -1, the matrix is not column diagonally dominant.
//    1, the matrix is column diagonally dominant.
//    2, the matrix is strictly column diagonally dominant.
//
{
  int i;
  int j;
  double s;
  double sumi;
  int value;

  value = 2;

  for ( j = 0; j < i4_min ( m, n ); j++ )
  {
    s = fabs ( a[j+j*m] );

    sumi = 0.0;
    for ( i = 0; i < m; i++ )
    {
      if ( i != j )
      {
        sumi = sumi + fabs ( a[i+j*m] );
      }
    }

    if ( s < sumi )
    {
      value = -1;
      return value;
    }
    else if ( s == sumi )
    {
      value = 1;
    }

  }

  return value;
}
//****************************************************************************80

int r8mat_is_diagonally_dominant_row ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_DIAGONALLY_DOMINANT_ROW: is an R8MAT row diagonally dominant.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, int R8MAT_IS_DIAGONALLY_DOMINANT_ROW:
//    -1, the matrix is not row diagonally dominant.
//    1, the matrix is row diagonally dominant.
//    2, the matrix is strictly row diagonally dominant.
//
{
  int i;
  int j;
  double s;
  double sumj;
  int value;

  value = 2;

  for ( i = 0; i < i4_min ( m, n ); i++ )
  {
    s = fabs ( a[j+i*m] );

    sumj = 0.0;
    for ( j = 0; j < m; j++ )
    {
      if ( i != j )
      {
        sumj = sumj + fabs ( a[i+j*m] );
      }
    }

    if ( s < sumj )
    {
      value = -1;
      return value;
    }
    else if ( s == sumj )
    {
      value = 1;
    }

  }

  return value;
}
//****************************************************************************80

double r8mat_is_eigen_left ( int n, int k, double a[], double x[],
  double lambda[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_EIGEN_LEFT determines the error in a left eigensystem.
//
//  Discussion:
//
//    An R8MAT is a matrix of doubles.
//
//    This routine computes the Frobenius norm of
//
//      X * A - LAMBDA * X
//
//    where
//
//      A is an N by N matrix,
//      X is an K by N matrix (each of K columns is an eigenvector)
//      LAMBDA is a K by K diagonal matrix of eigenvalues.
//
//    This routine assumes that A, X and LAMBDA are all real.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, int K, the number of eigenvectors.
//    K is usually 1 or N.
//
//    Input, double A[N*N], the matrix.
//
//    Input, double X[K*N], the K eigenvectors.
//
//    Input, double LAMBDA[K], the K eigenvalues.
//
//    Output, double R8MAT_IS_EIGEN_LEFT, the Frobenius norm
//    of X * A - LAMBDA * X.
//
{
  double *c;
  double error_frobenius;
  int i;
  int j;
//
//  C = X * A
//
  c = r8mat_mm_new ( k, n, n, x, a );
//
//  C = C - LAMBDA * X
//
  for ( i = 0; i < k; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      c[i+j*n] = c[i+j*n] - lambda[i] * x[i+j*n];
    }
  }

  error_frobenius = r8mat_norm_fro ( k, n, c );
//
//  Free memory.
//
  delete [] c;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_eigen_right ( int n, int k, double a[], double x[],
  double lambda[] )

//****************************************************************************80
//
//  Purpose:
//
//    r8mat_is_eigen_right() determines the error in a right eigensystem.
//
//  Discussion:
//
//    An R8MAT is a matrix of doubles.
//
//    This routine computes the Frobenius norm of
//
//      A * X - X * LAMBDA
//
//    where
//
//      A is an N by N matrix,
//      X is an N by K matrix (each of K columns is an eigenvector)
//      LAMBDA is a K by K diagonal matrix of eigenvalues.
//
//    This routine assumes that A, X and LAMBDA are all real.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of the matrix.
//
//    int K, the number of eigenvectors.
//    K is usually 1 or N.
//
//    double A[N*N], the matrix.
//
//    double X[N*K], the K eigenvectors.
//
//    double LAMBDA[K], the K eigenvalues.
//
//  Output:
//
//    double R8MAT_IS_EIGEN_RIGHT, the Frobenius norm
//    of the difference matrix A * X - X * LAMBDA, which would be exactly zero
//    if X and LAMBDA were exact eigenvectors and eigenvalues of A.
//
{
  double *c;
  double error_frobenius;
  int i;
  int j;
//
//  C = A * X
//
  c = r8mat_mm_new ( n, n, k, a, x );
//
//  C = C - LAMBDA * X
//
  for ( j = 0; j < k; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      c[i+j*n] = c[i+j*n] - lambda[j] * x[i+j*n];
    }
  }

  error_frobenius = r8mat_norm_fro ( n, k, c );
//
//  Free memory.
//
  delete [] c;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_identity ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_IDENTITY determines if an R8MAT is the identity.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//    The routine returns the Frobenius norm of A - I.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double A[N*N], the matrix.
//
//    Output, double R8MAT_IS_IDENTITY, the Frobenius norm
//    of the difference matrix A - I, which would be exactly zero
//    if A were the identity matrix.
//
{
  double error_frobenius;
  int i;
  int j;
  double t;

  error_frobenius = 0.0;

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i == j )
      {
        t = a[i+j*n] - 1.0;
      }
      else
      {
        t = a[i+j*n];
      }
      error_frobenius = error_frobenius + t * t;
    }
  }
  error_frobenius = sqrt ( error_frobenius );

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_integer ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_INTEGER checks whether an R8MAT has only integer entries.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, double R8MAT_IS_INTEGER, the Frobenius norm of
//    the difference between A and the nearest integer matrix.
//
{
  double error_frobenius;
  int i;
  int j;
  double t;

  error_frobenius = 0.0;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      t = a[i+j*m] - round ( a[i+j*m] );
      error_frobenius = error_frobenius + t * t;
    }
  }
  error_frobenius = sqrt ( error_frobenius );

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_inverse ( int n, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_INVERSE determines if one R8MAT is the inverse of another.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//    This routine returns the sum of the Frobenius norms of
//    A * B - I and B * A - I.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double A[N*N], B[N*N], the matrices.
//
//    Output, double R8MAT_IS_INVERSE, the sum of the Frobenius norms
//    of the difference matrices A * B - I and B * A - I, which would be exactly zero
//    if B was the exact inverse of A and computer arithmetic were exact.
//
{
  double error_frobenius;
  double error_left;
  double error_right;

  error_left = r8mat_is_inverse_left ( n, n, a, b );
  error_right = r8mat_is_inverse_right ( n, n, a, b );

  error_frobenius = error_left + error_right;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_inverse_left ( int m, int n, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_INVERSE_LEFT determines if one R8MAT is the left inverse of another.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//    This routine returns the Frobenius norm of B * A - I.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double A[M*N], the matrix.
//
//    Input, double B[N*M], the matrix which is to be tested as a left inverse
//    of A.
//
//    Output, double R8MAT_IS_INVERSE_LEFT, the Frobenius norm
//    of the difference matrix B * A - I, which would be exactly zero
//    if B was the exact left inverse of A and computer arithmetic were exact.
//
{
  double *c;
  double error_frobenius;
  int i;
  int j;
  int k;
  
  c = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      c[i+j*n] = 0.0;
      for ( k = 0; k < m; k++ )
      {
        c[i+j*n] = c[i+j*n] + b[i+k*n] * a[k+j*m];
      }
    }
  }

  for ( i = 0; i < n; i++ )
  {
    c[i+i*n] = c[i+i*n] - 1.0;
  }

  error_frobenius = r8mat_norm_fro ( n, n, c );
//
//  Free memory.
//
  delete [] c;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_inverse_right ( int m, int n, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_INVERSE_RIGHT determines if one R8MAT is the right inverse of another.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//    This routine returns the Frobenius norm of A * B - I.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double A[M*N], the matrix.
//
//    Input, double B[N*M], the matrix which is to be tested as a right inverse
//    of A.
//
//    Output, double R8MAT_IS_INVERSE_RIGHT, the Frobenius norm
//    of the difference matrix A * B - I, which would be exactly zero
//    if B was the exact right inverse of A and computer arithmetic were exact.
//
{
  double *c;
  double error_frobenius;
  int i;
  int j;
  int k;
  
  c = new double[m*m];

  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      c[i+j*m] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        c[i+j*m] = c[i+j*m] + b[i+k*n] * a[k+j*m];
      }
    }
  }

  for ( i = 0; i < m; i++ )
  {
    c[i+i*m] = c[i+i*m] - 1.0;
  }

  error_frobenius = r8mat_norm_fro ( m, m, c );
//
//  Free memory.
//
  delete [] c;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_llt ( int m, int n, double a[], double l[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_LLT measures the error in a lower triangular Cholesky factorization.
//
//  Discussion:
//
//    An R8MAT is a matrix of R8 values.
//
//    This routine simply returns the Frobenius norm of the M x M matrix:
//    A - L * L'.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double A[M*M], the matrix.
//
//    Input, double L[M*N], the Cholesky factor.
//
//    Output, double R8MAT_IS_LLT, the Frobenius norm of A - L * L'.
//
{
  double *d;
  int i;
  int j;
  double error_frobenius;

  d = r8mat_mmt_new ( m, n, m, l, l );

  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      d[i+j*m] = a[i+j*m] - d[i+j*m];
    }
  }

  error_frobenius = r8mat_norm_fro ( m, n, d );

  delete [] d;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_null_left ( int m, int n, double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_NULL_LEFT determines if x is a left null vector of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a matrix of doubles.
//
//    The nonzero M vector x is a left null vector of the MxN matrix A if
//
//      x' * A = A' * x = 0
//
//    If A is a square matrix, then this implies that A is singular.
//
//    If A is a square matrix, this implies that 0 is an eigenvalue of A,
//    and that x is an associated eigenvector.
//
//    This routine returns 0 if x is exactly a null vector of A.
//
//    It returns a "huge" value if x is the zero vector.
//
//    Otherwise, it returns the L2 norm of A' * x divided by the L2 norm of x:
//
//      ERROR_L2 = NORM_L2 ( A' * x ) / NORM_L2 ( x )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 May 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Input, double X[M], the vector.
//
//    Output, double R8MAT_IS_NULL_LEFT, the result.
//    0.0 indicates that X is exactly a left null vector.
//    A "huge" value indicates that ||x|| = 0;
//    Otherwise, the value returned is a relative error ||A'*x||/||x||.
//
{
  double atx;
  double atx_norm;
  double error_l2;
  int i;
  int j;
  double x_norm;

  x_norm = 0.0;
  for ( i = 0; i < m; i++ )
  {
    x_norm = x_norm + x[i] * x[i];
  }
  x_norm = sqrt ( x_norm );

  if ( x_norm == 0.0 )
  {
    error_l2 = r8_huge ( );
    return error_l2;
  }

  atx_norm = 0.0;
  for ( j = 0; j < n; j++ )
  {
    atx = 0.0;
    for ( i = 0; i < m; i++ )
    {
      atx = atx + x[i] * a[i+j*m];
    }
    atx_norm = atx_norm + atx * atx;
  }
  atx_norm = sqrt ( atx_norm );

  error_l2 = atx_norm / x_norm;

  return error_l2;
}
//****************************************************************************80

double r8mat_is_null_right ( int m, int n, double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_NULL_RIGHT determines if x is a right null vector of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a matrix of doubles.
//
//    The nonzero N vector x is a right null vector of the MxN matrix A if
//
//      A * x = 0
//
//    If A is a square matrix, then this implies that A is singular.
//
//    If A is a square matrix, this implies that 0 is an eigenvalue of A,
//    and that x is an associated eigenvector.
//
//    This routine returns 0 if x is exactly a null vector of A.
//
//    It returns a "huge" value if x is the zero vector.
//
//    Otherwise, it returns the L2 norm of A * x divided by the L2 norm of x:
//
//      ERROR_L2 = NORM_L2 ( A * x ) / NORM_L2 ( x )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Input, double X[N], the vector.
//
//    Output, double R8MAT_IS_NULL_RIGHT, the result.
//    0.0 indicates that X is exactly a null vector.
//    A "huge" value indicates that ||x|| = 0;
//    Otherwise, the value returned is a relative error ||A*x||/||x||.
//
{
  double ax;
  double ax_norm;
  double error_l2;
  int i;
  int j;
  double x_norm;

  x_norm = 0.0;
  for ( i = 0; i < n; i++ )
  {
    x_norm = x_norm + x[i] * x[i];
  }
  x_norm = sqrt ( x_norm );

  if ( x_norm == 0.0 )
  {
    error_l2 = r8_huge ( );
    return error_l2;
  }

  ax_norm = 0.0;
  for ( i = 0; i < m; i++ )
  {
    ax = 0.0;
    for ( j = 0; j < n; j++ )
    {
      ax = ax + a[i+j*m] * x[j];
    }
    ax_norm = ax_norm + ax * ax;
  }
  ax_norm = sqrt ( ax_norm );

  error_l2 = ax_norm / x_norm;

  return error_l2;
}
//****************************************************************************80

double r8mat_is_orthogonal ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_ORTHOGONAL checks whether an R8MAT is orthogonal.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, double R8MAT_IS_ORTHOGONAL, the Frobenius orthogonality
//    error, which is zero if the matrix is exactly orthogonal.
//
{
  double *b;
  double error_frobenius;

  if ( ! r8mat_is_square ( m, n, a ) )
  {
    error_frobenius = r8_huge ( );
    return error_frobenius;
  }

  b = r8mat_mtm_new ( n, n, n, a, a );

  error_frobenius = r8mat_is_identity ( n, b );

  delete [] b;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_orthogonal_column ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_ORTHOGONAL_COLUMN checks whether an R8MAT has orthogonal columns.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, double R8MAT_IS_ORTHOGONAL_COLUMN, the sum of the errors.
//
{
  double *b;
  double error_frobenius;

  b = r8mat_mtm_new ( n, m, n, a, a );

  error_frobenius = r8mat_is_identity ( n, b );

  delete [] b;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_orthogonal_row ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_ORTHOGONAL_ROW checks whether an R8MAT has orthogonal rows.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, double R8MAT_IS_ORTHOGONAL_ROW, the sum of the errors.
//
{
  double *b;
  double error_frobenius;

  b = r8mat_mmt_new ( m, n, m, a, a );

  error_frobenius = r8mat_is_identity ( m, b );

  delete [] b;

  return error_frobenius;
}
//****************************************************************************80

int r8mat_is_permutation ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_PERMUTATION checks whether an R8MAT is a permutation matrix.
//
//  Discussion:
//
//    An R8MAT is a matrix of doubles.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double A[M*N], the matrix.
//
//    Output, int R8MAT_IS_PERMUTATION:
//    -1, the matrix is not square;
//    -2, the matrix is not a zero-one matrix.
//    -3, there is a row that does not sum to 1.
//    -4, there is a column that does not sum to 1.
//    1, the matrix is a permutation matrix,
//
{
  int i;
  int ival;
  int j;
  int jval;
  double sum;

  if ( ! r8mat_is_square ( m, n, a ) )
  {
    ival = -1;
    return ival;
  }

  jval = r8mat_is_zero_one ( n, n, a );

  if ( jval != 1 )
  {
    ival = -2;
    return ival;
  }

  for ( i = 0; i < m; i++ )
  {
    sum = 0.0;
    for ( j = 0; j < n; j++ )
    {
      sum = sum + a[i+j*m];
    }
    if ( sum != 1.0 )
    {
      ival = -3;
      return ival;
    }
  }

  for ( j = 0; j < n; j++ )
  {
    sum = 0.0;
    for ( i = 0; i < m; i++ )
    {
      sum = sum + a[i+j*m];
    }
    if ( sum != 1.0 )
    {
      ival = -4;
      return ival;
    }
  }

  ival = 1;
  return ival;
}
//****************************************************************************80

double r8mat_is_plu ( int m, int n, double a[], double p[], double l[], 
  double u[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_PLU measures the error in a PLU factorization.
//
//  Discussion:
//
//    An R8MAT is a matrix of real ( kind = 8 ) values.
//
//    This routine simply returns the Frobenius norm of the M x N matrix:
//    A - P * L * U.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double A[M*N], the matrix.
//
//    Input, double P[M*M], L[M*M], U[M*N], the PLU factors.
//
//    Output, double R8MAT_IS_PLU, the Frobenius norm
//    of the difference matrix A  - P * L * U.
//
{
  double *d;
  int i;
  int j;
  double *lu;
  double *plu;
  double error_frobenius;

  lu = r8mat_mm_new ( m, m, n, l, u );

  plu = r8mat_mm_new ( m, m, n, p, lu );

  d = new double[m*n];
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      d[i+j*m] = a[i+j*m] - plu[i+j*m];
    }
  }

  error_frobenius = r8mat_norm_fro ( m, n, d );
//
//  Free memory.
//
  delete [] d;
  delete [] lu;
  delete [] plu;

  return error_frobenius;
}
//****************************************************************************80

double r8mat_is_solution ( int m, int n, int k, double a[], double x[], 
  double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_SOLUTION measures the error in a linear system solution.
//
//  Discussion:
//
//    An R8MAT is a matrix of doubles.
//
//    The system matrix A is an M x N matrix.
//    It is not required that A be invertible.
//
//    The solution vector X is actually allowed to be an N x K matrix.
//
//    The right hand side "vector" B is actually allowed to be an M x K matrix.
//
//    This routine simply returns the Frobenius norm of the M x K matrix:
//    A * X - B.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    01 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, K, the order of the matrices.
//
//    Input, double A[M*N], X[N*K], B[M*K], the matrices.
//
//    Output, double R8MAT_IS_SOOLUTION, the Frobenius norm
//    of the difference matrix A * X - B, which would be exactly zero
//    if X was the "solution" of the linear system.
//
{
  double *c;
  double error_frobenius;
  int i;
  int j;
  int l;

  c = new double[m*k];

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < k; j++ )
    {
      c[i+j*m] = - b[i+j*m];
      for ( l = 0; l < n; l++ )
      {
        c[i+j*m] = c[i+j*m] + a[i+l*m] * x[l+j*n];
      }
    }
  }

  error_frobenius = r8mat_norm_fro ( m, k, c );
//
//  Free memory.
//
  delete [] c;

  return error_frobenius;
}
//****************************************************************************80

bool r8mat_is_square ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_SQUARE checks whether an R8MAT is square.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 April 2017
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, bool R8MAT_IS_SQUARE, is TRUE if the matrix is square.
//
{
  bool lvalue;

  lvalue = ( m == n );

  return lvalue;
}
//****************************************************************************80

double r8mat_is_symmetric ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_SYMMETRIC checks an R8MAT for symmetry.
//
//  Discussion:
//
//    An R8MAT is a matrix of double precision real values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double A[M*N], the matrix.
//
//    Output, double RMAT_IS_SYMMETRIC, measures the 
//    Frobenius norm of ( A - A' ), which would be zero if the matrix
//    were exactly symmetric.
//
{
  int i;
  int j;
  double value;

  if ( ! r8mat_is_square ( m, n, a ) )
  {
    value = r8_huge ( );
    return value;
  }

  value = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      value = value + pow ( a[i+j*m] - a[j+i*m], 2 );
    }
  }
  value = sqrt ( value );

  return value;
}
//****************************************************************************80

double r8mat_is_transition ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_TRANSITION checks whether an R8MAT is a transition matrix.
//
//  Discussion:
//
//    A transition matrix:
//    * is a square matrix;
//    * with real, nonnegative entries;
//    * whose columns each sum to 1.
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of A.
//
//    Input, double A[M*N], the matrix.
//
//    Output, double R8MAT_IS_TRANSITION.
//    This value is R8_HUGE(), if M /= N.
//    This value is R8_HUGE(), if any entry is negative.
//    Otherwise, it is the square root of the sum of the squares of the
//    deviations of the column sums from 1.
//
{
  double error_frobenius;
  int i;
  int j;
  double t;

  if ( ! r8mat_is_square ( m, n, a ) )
  {
    error_frobenius = r8_huge ( );
    return error_frobenius;
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( a[i+j*m] < 0.0 )
      {
        error_frobenius = r8_huge ( );
        return error_frobenius;
      }
    }
  }
//
//  Take column sums.
//
  error_frobenius = 0.0;
  for ( j = 0; j < n; j++ )
  {
    t = 0.0;
    for ( i = 0; i < m; i++ )
    {
      t = t + a[i+j*m];
    }
    t = t - 1.0;
    error_frobenius = error_frobenius + t * t;
  }
  error_frobenius = sqrt ( error_frobenius );
 
  return error_frobenius;
}
//****************************************************************************80

void r8mat_is_triangular ( int m, int n, double a[], int &ival, int &jval )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_TRIANGULAR determines whether an R8MAT is triangular.
//
//  Discussion:
//
//    An R8MAT is a matrix of double values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 July 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, int &IVAL:
//    -1, the matrix is not upper triangular
//    1, the matrix is upper triangular.
//    2, the matrix is unit upper triangular.
//
//    Output, int &JVAL:
//    -1, the matrix is not lower triangular.
//    1, the matrix is lower triangular.
//    2, the matrix is unit lower triangular.
//
{
  int i;
  int j;

  ival = 2;
  jval = 2;

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( i == j )
      {
        if ( a[i+j*m] != 1.0 )
        {
          if ( ival == 2 )
          {
            ival = 1;
          }
          if ( jval == 2 )
          {
            jval = 1;
          }
        }
      }
      else if ( i < j )
      {
        if ( a[i+j*m] != 0.0 )
        {
          jval = -1;
        }
      }
      else if ( j < i )
      {
        if ( a[i+j*m] != 0.0 )
        {
          ival = -1;
        }
      }

      if ( ival == -1 && jval == -1 )
      {
        return;
      }
    }
  }

  return;
}
//****************************************************************************80

int r8mat_is_zero_one ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_IS_ZERO_ONE checks whether an R8MAT is a zero/one matrix.
//
//  Discussion:
//
//    An R8MAT is a matrix of doubles.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the row and column dimensions of 
//    the matrix.  M and N must be positive.
//
//    Input, double A[M*N], the matrix.
//
//    Output, int R8MAT_IS_ZERO_ONE:
//    -1, the matrix is not a zero/one matrix.
//    1, the matrix is a zero/one matrix.
//
{
  int i;
  int ival;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( a[i+j*m] != 0.0 && a[i+j*m] != 1.0 )
      {
        ival = -1;
        return ival;
      }
    }
  }
  ival = 1;

  return ival;
}
//****************************************************************************80

double *r8mat_mm_new ( int n1, int n2, int n3, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_MM_NEW multiplies two matrices.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    For this routine, the result is returned as the function value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N1, N2, N3, the order of the matrices.
//
//    Input, double A[N1*N2], double B[N2*N3], the matrices to multiply.
//
//    Output, double R8MAT_MM[N1*N3], the product matrix C = A * B.
//
{
  double *c;
  int i;
  int j;
  int k;

  c = new double[n1*n3];

  for ( i = 0; i < n1; i ++ )
  {
    for ( j = 0; j < n3; j++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[i+k*n1] * b[k+j*n2];
      }
    }
  }

  return c;
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

double *r8mat_mtm_new ( int n1, int n2, int n3, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_MTM_NEW computes C = A' * B.
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
//    07 September 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N1, N2, N3, the order of the matrices.
//
//    Input, double A[N2*N1], double B[N2*N3], the matrices to multiply.
//
//    Output, double R8MAT_MTM_NEW[N1*N3], the product matrix C = A' * B.
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
        c[i+j*n1] = c[i+j*n1] + a[k+i*n2] * b[k+j*n2];
      }
    }
  }

  return c;
}
//****************************************************************************80

double r8mat_norm_eis ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_NORM_EIS returns the EISPACK norm of an R8MAT.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    The EISPACK norm is defined as:
//
//      R8MAT_NORM_EIS =
//        sum ( 1 <= I <= M ) sum ( 1 <= J <= N ) abs ( A(I,J) )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 September 2005
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
//    Input, double A[M*N], the matrix whose EISPACK norm is desired.
//
//    Output, double R8MAT_NORM_EIS, the EISPACK norm of A.
//
{
  int i;
  int j;
  double value;

  value = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      value = value + fabs ( a[i+j*m] );
    }
  }
  return value;
}
//****************************************************************************80

double r8mat_norm_fro ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_NORM_FRO returns the Frobenius norm of an R8MAT.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    The Frobenius norm is defined as
//
//      R8MAT_NORM_FRO = sqrt (
//        sum ( 1 <= I <= M ) sum ( 1 <= j <= N ) A(I,J)^2 )
//    The matrix Frobenius norm is not derived from a vector norm, but
//    is compatible with the vector L2 norm, so that:
//
//      r8vec_norm_l2 ( A * x ) <= r8mat_norm_fro ( A ) * r8vec_norm_l2 ( x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 October 2005
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
//    Input, double A[M*N], the matrix whose Frobenius
//    norm is desired.
//
//    Output, double R8MAT_NORM_FRO, the Frobenius norm of A.
//
{
  int i;
  int j;
  double value;

  value = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      value = value + pow ( a[i+j*m], 2 );
    }
  }
  value = sqrt ( value );

  return value;
}
//****************************************************************************80

double r8mat_norm_l1 ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_NORM_L1 returns the matrix L1 norm of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is an array of R8 values.
//
//    The matrix L1 norm is defined as:
//
//      R8MAT_NORM_L1 = max ( 1 <= J <= N )
//        sum ( 1 <= I <= M ) abs ( A(I,J) ).
//
//    The matrix L1 norm is derived from the vector L1 norm, and
//    satisifies:
//
//      r8vec_norm_l1 ( A * x ) <= r8mat_norm_l1 ( A ) * r8vec_norm_l1 ( x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 December 2011
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
//    Input, double A(M,N), the matrix whose L1 norm is desired.
//
//    Output, double R8MAT_NORM_L1, the L1 norm of A.
//
{
  double col_sum;
  int i;
  int j;
  double value;

  value = 0.0;

  for ( j = 0; j < n; j++ )
  {
    col_sum = 0.0;
    for ( i = 0; i < m; i++ )
    {
      col_sum = col_sum + fabs ( a[i+j*m] );
    }
    value = r8_max ( value, col_sum );
  }
  return value;
}
//****************************************************************************80

double r8mat_norm_l2 ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_NORM_L2 returns the matrix L2 norm of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is an array of R8 values.
//
//    The matrix L2 norm is defined as:
//
//      R8MAT_NORM_L2 = sqrt ( max ( 1 <= I <= M ) LAMBDA(I) )
//
//    where LAMBDA contains the eigenvalues of A * A'.
//
//    The matrix L2 norm is derived from the vector L2 norm, and
//    satisifies:
//
//      r8vec_norm_l2 ( A * x ) <= r8mat_norm_l2 ( A ) * r8vec_norm_l2 ( x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 December 2011
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
//    Input, double A(M,N), the matrix whose L2 norm is desired.
//
//    Output, double R8MAT_NORM_L2, the L2 norm of A.
//
{
  double *at;
  double *b;
  double *diag;
  double value;

  at = r8mat_transpose_new ( m, n, a );
//
//  Compute B = A * A'.
//
  b = r8mat_mm_new ( m, n, m, a, at );
//
//  Diagonalize B.
//
  r8mat_symm_jacobi ( m, b );
//
//  Find the maximum eigenvalue, and take its square root.
//
  diag = r8mat_diag_get_vector ( m, b );

  value = sqrt ( r8vec_max ( m, diag ) );
//
//  Free memory.
//
  delete [] at;
  delete [] b;
  delete [] diag;

  return value;
}
//****************************************************************************80

double r8mat_norm_li ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_NORM_LI returns the matrix L-oo norm of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is an array of R8 values.
//
//    The matrix L-oo norm is defined as:
//
//      R8MAT_NORM_LI =  max ( 1 <= I <= M ) sum ( 1 <= J <= N ) abs ( A(I,J) ).
//
//    The matrix L-oo norm is derived from the vector L-oo norm,
//    and satisifies:
//
//      r8vec_norm_li ( A * x ) <= r8mat_norm_li ( A ) * r8vec_norm_li ( x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 December 2011
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
//    Input, double A[M*N], the matrix whose L-oo
//    norm is desired.
//
//    Output, double R8MAT_NORM_LI, the L-oo norm of A.
//
{
  int i;
  int j;
  double row_sum;
  double value;

  value = 0.0;

  for ( i = 0; i < m; i++ )
  {
    row_sum = 0.0;
    for ( j = 0; j < n; j++ )
    {
      row_sum = row_sum + fabs ( a[i+j*m] );
    }
    value = r8_max ( value, row_sum );
  }
  return value;
}
//****************************************************************************80

void r8mat_plot ( int m, int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PLOT "plots" an R8MAT.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 June 2011
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
//    Input, double A[M*N}, the matrix.
//
//    Input, string TITLE.
//
{
  int i;
  int j;
  int jhi;
  int jlo;

  cout << "\n";
  cout << title << "\n";

  for ( jlo = 1; jlo <= n; jlo = jlo + 70 )
  {
    jhi = i4_min ( jlo + 70-1, n );
    cout << "\n";
    cout << "          ";
    for ( j = jlo; j <= jhi; j++ )
    {
      cout <<  ( j % 10 );
    }
    cout << "\n";
    cout << "\n";

    for ( i = 1; i <= m; i++ )
    {
      cout << setw(6) << i << "    ";
      for ( j = jlo; j <= jhi; j++ )
      {
        cout << r8mat_plot_symbol ( a[i-1+(j-1)*m] );
      }
      cout << "\n";
    }
  }

  return;
}
//****************************************************************************80

char r8mat_plot_symbol ( double r )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PLOT_SYMBOL returns a symbol for a double precision number.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double R, a value whose symbol is desired.
//
//    Output, char R8MAT_PLOT_SYMBOL, is
//    '-' if R is negative,
//    '0' if R is zero,
//    '+' if R is positive.
//
{
  char c;

  if ( r < 0.0 )
  {
    c = '-';
  }
  else if ( r == 0.0 )
  {
    c = '0';
  }
  else if ( 0.0 < r )
  {
    c = '+';
  }

  return c;
}
//****************************************************************************80

double *r8mat_poly_char ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_POLY_CHAR computes the characteristic polynomial of an R8MAT.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix A.
//
//    Input, double A[N*N], the N by N matrix.
//
//    Output, double R8MAT_POLY_CHAR[N+1], the coefficients of the characteristic
//    polynomial of A.  P(N) contains the coefficient of X^N
//    (which will be 1), P(I) contains the coefficient of X^I,
//    and P(0) contains the constant term.
//
{
  int i;
  int order;
  double *p;
  double trace;
  double *work1;
  double *work2;

  p = new double[n+1];
//
//  Initialize WORK1 to the identity matrix.
//
  work1 = r8mat_identity ( n );

  p[n] = 1.0;

  for ( order = n-1; 0 <= order; order-- )
  {
//
//  Work2 = A * WORK1.
//
    work2 = r8mat_mm_new ( n, n, n, a, work1 );
//
//  Take the trace.
//
    trace = r8mat_trace ( n, work2 );
//
//  P(ORDER) = -Trace ( WORK2 ) / ( N - ORDER )
//
    p[order] = -trace / ( double ) ( n - order );
//
//  WORK1 := WORK2 + P(IORDER) * Identity.
//
    delete [] work1;

    r8mat_copy ( n, n, work2, work1 );

    delete [] work2;

    for ( i = 0; i < n; i++ )
    {
      work1[i+i*n] = work1[i+i*n] + p[order];
    }
  }
//
//  Free memory.
//
  delete [] work1;

  return p;
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
//    20 August 2010
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
    j2hi = i4_min ( j2hi, n );
    j2hi = i4_min ( j2hi, jhi );

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
    i2lo = i4_max ( ilo, 1 );
    i2hi = i4_min ( ihi, m );

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

void r8mat_symm_jacobi ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_SYMM_JACOBI applies Jacobi eigenvalue iteration to a symmetric matrix.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    This code was modified so that it treats as zero the off-diagonal
//    elements that are sufficiently close to, but not exactly, zero.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the order of A.
//
//    double A[N*N], a symmetric N by N matrix.
//
//  Output:
//
//    double A[N*N], the matrix has been overwritten by an approximately
//    diagonal matrix, with the eigenvalues on the diagonal.
//
{
  double c;
  double eps = 0.00001;
  int i;
  int it;
  int it_max = 100;
  int j;
  int k;
  double norm_fro;
  double s;
  double sum2;
  double t;
  double t1;
  double t2;
  double u;

  norm_fro = r8mat_norm_fro ( n, n, a );

  it = 0;

  for ( ; ; )
  {
    it = it + 1;

    for ( i = 0; i < n; i++ )
    {
      for ( j = 0; j < i; j++ )
      {
        if ( eps * norm_fro < fabs ( a[i+j*n] ) + fabs ( a[j+i*n] ) )
        {
          u = ( a[j+j*n] - a[i+i*n] ) / ( a[i+j*n] + a[j+i*n] );

          t = r8_sign ( u ) / ( fabs ( u ) + sqrt ( u * u + 1.0 ) );
          c = 1.0 / sqrt ( t * t + 1.0 );
          s = t * c;
//
//  A -> A * Q.
//
          for ( k = 0; k < n; k++ )
          {
            t1 = a[i+k*n];
            t2 = a[j+k*n];
            a[i+k*n] = t1 * c - t2 * s;
            a[j+k*n] = t1 * s + t2 * c;
          }
//
//  A -> QT * A
//
          for ( k = 0; k < n; k++ )
          {
            t1 = a[k+i*n];
            t2 = a[k+j*n];
            a[k+i*n] = c * t1 - s * t2;
            a[k+j*n] = s * t1 + c * t2;
          }
        }
      }
    }
//
//  Test the size of the off-diagonal elements.
//
    sum2 = 0.0;
    for ( i = 0; i < n; i++ )
    {
      for ( j = 0; j < i; j++ )
      {
        sum2 = sum2 + fabs ( a[i+j*n] );
      }
    }

    if ( sum2 <= eps * ( norm_fro + 1.0 ) )
    {
      break;
    }

    if ( it_max <= it )
    {
      break;
    }

  }

  return;
}
//****************************************************************************80

complex <double> *r8mat_to_c8mat ( int m, int n, double r8mat[] )

//****************************************************************************80
//
//  Purpose:
//
//    r8mat_to_c8mat() copies an R8MAT to a C8MAT.
//
//  Discussion:
//
//    An R8MAT is a matrix of real numbers.
//
//    A C8MAT is a matrix of complex numbers.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 May 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int M, N, the number of rows and columns.
//
//    double R8MAT[M*N], the matrix to be copied.
//
//  Output:
//
//    complex <double> C8MAT[M*N], the complex copy of R8MAT.
//
{
  complex <double> *c8mat;
  int i;
  int j;

  c8mat = new complex <double>[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      c8mat[i+j*m] = r8mat[i+j*m];
    }
  }

  return c8mat;
}
//****************************************************************************80

double r8mat_trace ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    r8mat_trace() computes the trace of an R8MAT.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    The trace of a square matrix is the sum of the diagonal elements.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix A.
//
//    Input, double A[N*N], the matrix whose trace is desired.
//
//    Output, double R8MAT_TRACE, the trace of the matrix.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a[i+i*n];
  }

  return value;
}
//****************************************************************************80

double *r8mat_transpose_new ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_TRANSPOSE_NEW returns the transpose of an R8MAT.
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
//    12 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns of the matrix A.
//
//    Input, double A[M*N], the matrix whose transpose is desired.
//
//    Output, double R8MAT_TRANSPOSE_NEW[N*M], the transposed matrix.
//
{
  double *b;
  int i;
  int j;

  b = new double[n*m];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      b[j+i*n] = a[i+j*m];
    }
  }
  return b;
}
//****************************************************************************80

void r8mat_transpose_in_place ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_TRANSPOSE_IN_PLACE transposes a square matrix in place.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 June 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of rows and columns of the matrix A.
//
//    double A[N*N], the matrix to be transposed.  
//
//  Output:
//
//    double A[N*N]: the transposed matrix.
//
{
  int i;
  int j;
  double t;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < j; i++ )
    {
      t        = a[i+j*n];
      a[i+j*n] = a[j+i*n];
      a[j+i*n] = t;
    }
  }
  return;
}
//****************************************************************************80

double *r8mat_uniform_01_new ( int m, int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_UNIFORM_01_NEW returns a unit pseudorandom R8MAT.
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
//    03 October 2005
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
//  Input:
//
//    int M, N, the number of rows and columns.
//
//    int &SEED, the "seed" value.
//
//  Output:
//
//    double R8MAT_UNIFORM_01_NEW[M*N], a matrix of pseudorandom values.
//
//    int &SEED, an updated seed.
//
{
  int i;
  int j;
  int k;
  double *r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8MAT_UNIFORM_01_NEW - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  r = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )
      {
        seed = seed + i4_huge ( );
      }

      r[i+j*m] = ( double ) ( seed ) * 4.656612875E-10;
    }
  }

  return r;
}
//****************************************************************************80

double *r8mat_uniform_ab_new ( int m, int n, double b, double c, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_UNIFORM_AB_NEW returns a scaled pseudorandom R8MAT.
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
//    03 October 2005
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
//  Input:
//
//    int M, N, the number of rows and columns.
//
//    double B, C, the limits of the pseudorandom values.
//
//    int &SEED, the "seed" value.
//
//  Output:
//
//    double R8MAT_UNIFORM_AB_NEW[M*N], a matrix of pseudorandom values.
//
//    int &SEED, an updated seed.
//
{
  int i;
  int j;
  int k;
  double *r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8MAT_UNIFORM_AB_NEW - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  r = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = seed / 127773;

      seed = 16807 * ( seed - k * 127773 ) - k * 2836;

      if ( seed < 0 )
      {
        seed = seed + i4_huge ( );
      }

      r[i+j*m] = b + ( c - b ) * ( double ) ( seed ) * 4.656612875E-10;
    }
  }

  return r;
}
//****************************************************************************80

double *r8mat_zero_new ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_ZERO_NEW returns a new zeroed R8MAT.
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
//    Output, double R8MAT_ZERO[M*N], the new zeroed matrix.
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

int r8poly_degree ( int na, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_DEGREE returns the degree of an R8POLY.
//
//  Discussion:
//
//    The degree of a polynomial is the index of the highest power
//    of X with a nonzero coefficient.
//
//    The degree of a constant polynomial is 0.  The degree of the
//    zero polynomial is debatable, but this routine returns the
//    degree as 0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 May 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NA, the dimension of A.
//
//    Input, double A[NA+1], the coefficients of the polynomials.
//
//    Output, int R8POLY_DEGREE, the degree of the polynomial.
//
{
  int degree;

  degree = na;

  while ( 0 < degree )
  {
    if ( a[degree] != 0.0 )
    {
      return degree;
    }
    degree = degree - 1;
  }
  return degree;
}
//****************************************************************************80

void r8poly_print ( int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_PRINT prints out a polynomial.
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
//    Input, int N, the dimension of A.
//
//    Input, double A[N+1], the polynomial coefficients.
//    A(0) is the constant term and
//    A(N) is the coefficient of X^N.
//
//    Input, string TITLE, a title.
//
{
  int i;
  double mag;
  int n2;
  char plus_minus;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";

  n2 = r8poly_degree ( n, a );

  if ( n2 <= 0 )
  {
    cout << "  p(x) = 0\n";
    return;
  }

  if ( a[n2] < 0.0 )
  {
    plus_minus = '-';
  }
  else
  {
    plus_minus = ' ';
  }

  mag = fabs ( a[n2] );

  if ( 2 <= n2 )
  {
    cout << "  p(x) = " << plus_minus
         << setw(14) << mag << " * x ^ " << n2 << "\n";
  }
  else if ( n2 == 1 )
  {
    cout << "  p(x) = " << plus_minus
         << setw(14) << mag << " * x\n";
  }
  else if ( n2 == 0 )
  {
    cout << "  p(x) = " << plus_minus
         << setw(14) << mag << "\n";
  }

  for ( i = n2-1; 0 <= i; i-- )
  {
    if ( a[i] < 0.0 )
    {
      plus_minus = '-';
    }
    else
    {
      plus_minus = '+';
    }

    mag = fabs ( a[i] );

    if ( mag != 0.0 )
    {
      if ( 2 <= i )
      {
        cout << "         " << plus_minus
             << setw(14) << mag << " * x ^ " << i << "\n";
      }
      else if ( i == 1 )
      {
        cout << "         " << plus_minus
             << setw(14) << mag << " * x\n";
      }
      else if ( i == 0 )
      {
        cout << "         " << plus_minus
             << setw(14) << mag << "\n";
      }
    }
  }

  return;
}
//****************************************************************************80

void r8row_swap ( int m, int n, double a[], int irow1, int irow2 )

//****************************************************************************80
//
//  Purpose:
//
//    R8ROW_SWAP swaps two rows of an R8ROW.
//
//  Discussion:
//
//    The two dimensional information is stored as a one dimensional
//    array, by columns.
//
//    The row indices are 1 based, NOT 0 based//  However, a preprocessor
//    variable, called OFFSET, can be reset from 1 to 0 if you wish to
//    use 0-based indices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    17 September 2003
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int M, N, the number of rows and columns.
//
//    double A[M*N], an array of data.
//
//    int IROW1, IROW2, the two rows to swap.
//    These indices should be between 1 and M.
//
//  Output:
//
//    double A[M*N]: the array after row swapping.
//
{
  int j;
  double t;
//
//  Check.
//
  if ( irow1 < 1 || m < irow1 )
  {
    cerr << "\n";
    cerr << "R8ROW_SWAP - Fatal error!\n";
    cerr << "  IROW1 is out of range.\n";
    exit ( 1 );
  }

  if ( irow2 < 1 || m < irow2 )
  {
    cerr << "\n";
    cerr << "R8ROW_SWAP - Fatal error!\n";
    cerr << "  IROW2 is out of range.\n";
    exit ( 1 );
  }

  if ( irow1 == irow2 )
  {
    return;
  }

  for ( j = 0; j < n; j++ )
  {
    t              = a[irow1-1+j*m];
    a[irow1-1+j*m] = a[irow2-1+j*m];
    a[irow2-1+j*m] = t;
  }

  return;
# undef OFFSET
}
//****************************************************************************80

double *r8row_to_r8vec ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8ROW_TO_R8VEC converts an R8ROW into an R8VEC.
//
//  Example:
//
//    M = 3, N = 4
//
//    A =
//      11 12 13 14
//      21 22 23 24
//      31 32 33 34
//
//    R8ROW_TO_R8VEC = ( 11, 12, 13, 14, 21, 22, 23, 24, 31, 32, 33, 34 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, double A[M*N], the M by N array.
//
//    Output, double R8ROW_TO_R8VEC[M*N], a vector containing the M rows of A.
//
{
  int i;
  int j;
  int k;
  double *x;

  x = new double[m*n];

  k = 0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      x[k] = a[i+j*m];
      k = k + 1;
    }
  }

  return x;
}
//****************************************************************************80

double r8vec_amax ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_AMAX returns the maximum absolute value in an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the array.
//
//    Input, double A[N], the array.
//
//    Output, double AMAX, the value of the entry
//    of largest magnitude.
//
{
  double amax;
  int i;

  amax = 0.0;
  for ( i = 0; i < n; i++ )
  {
    if ( amax < fabs ( a[i] ) )
    {
      amax = fabs ( a[i] );
    }
  }

  return amax;
}
//****************************************************************************80

double r8vec_amin ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_AMIN returns the minimum absolute value in an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the array.
//
//    Input, double A[N], the array.
//
//    Output, double R8VEC_AMIN, the value of the entry
//    of smallest magnitude.
//
{
  int i;
  const double r8_huge = 1.79769313486231571E+308;
  double value;

  value = r8_huge;
  for ( i = 0; i < n; i++ )
  {
    if ( fabs ( a[i] ) < value )
    {
      value = fabs ( a[i] );
    }
  }

  return value;
}
//****************************************************************************80

double r8vec_asum ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_ASUM sums the absolute values of the entries of an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, double A[N], the vector.
//
//    Output, double R8VEC_ASUM, the sum of absolute values of the entries.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + fabs ( a[i] );
  }
  return value;
}
//****************************************************************************80

void r8vec_copy ( int n, double a1[], double a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_COPY copies an R8VEC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 July 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input, double A1[N], the vector to be copied.
//
//    Output, double A2[N], the copy of A1.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return;
}
//****************************************************************************80

double *r8vec_copy_new ( int n, double a1[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_COPY_NE Wcopies an R8VEC.
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
//    Input, int N, the number of entries in the vectors.
//
//    Input, double A1[N], the vector to be copied.
//
//    Output, double R8VEC_COPY_NEW[N], the copy of A1.
//
{
  double *a2;
  int i;

  a2 = new double[n];

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return a2;
}
//****************************************************************************80

double r8vec_dot_product ( int n, double a1[], double a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_DOT_PRODUCT computes the dot product of a pair of R8VEC's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 July 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input, double A1[N], A2[N], the two vectors to be considered.
//
//    Output, double R8VEC_DOT, the dot product of the vectors.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a1[i] * a2[i];
  }
  return value;
}
//****************************************************************************80

double *r8vec_house_column ( int n, double a[], int k )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_HOUSE_COLUMN defines a Householder premultiplier that "packs" a column.
//
//  Discussion:
//
//    The routine returns a vector V that defines a Householder
//    premultiplier matrix H(V) that zeros out the subdiagonal entries of
//    column K of the matrix A.
//
//       H(V) = I - 2 * v * v'
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix A.
//
//    Input, double A[N], column K of the matrix A.
//
//    Input, int K, the column of the matrix to be modified.
//
//    Output, double R8VEC_HOUSE_COLUMN[N], a vector of unit L2 norm which
//    defines an orthogonal Householder premultiplier matrix H with the property
//    that the K-th column of H*A is zero below the diagonal.
//
{
  int i;
  double s;
  double *v;

  v = r8vec_zero_new ( n );

  if ( k < 1 || n <= k )
  {
    return v;
  }

  s = r8vec_norm_l2 ( n+1-k, a+k-1 );

  if ( s == 0.0 )
  {
    return v;
  }

  v[k-1] = a[k-1] + fabs ( s ) * r8_sign ( a[k-1] );

  r8vec_copy ( n-k, a+k, v+k );

  s = r8vec_norm_l2 ( n-k+1, v+k-1 );

  for ( i = k-1; i < n; i++ )
  {
    v[i] = v[i] / s;
  }

  return v;
}
//****************************************************************************80

double *r8vec_indicator_new ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_INDICATOR_NEW sets an R8VEC to the indicator vector {1,2,3...}.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of elements of A.
//
//    Output, double R8VEC_INDICATOR_NEW[N], the array to be initialized.
//
{
  double *a;
  int i;

  a = new double[n];

  for ( i = 0; i <= n-1; i++ ) 
  {
    a[i] = ( double ) ( i + 1 );
  }

  return a;
}
//****************************************************************************80

double *r8vec_linspace_new ( int n, double a_first, double a_last )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_LINSPACE_NEW creates a vector of linearly spaced values.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//    4 points evenly spaced between 0 and 12 will yield 0, 4, 8, 12.
//
//    In other words, the interval is divided into N-1 even subintervals,
//    and the endpoints of intervals are used as the points.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, double A_FIRST, A_LAST, the first and last entries.
//
//    Output, double R8VEC_LINSPACE_NEW[N], a vector of linearly spaced data.
//
{
  double *a;
  int i;

  a = new double[n];

  if ( n == 1 )
  {
    a[0] = ( a_first + a_last ) / 2.0;
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      a[i] = ( ( double ) ( n - 1 - i ) * a_first 
             + ( double ) (         i ) * a_last ) 
             / ( double ) ( n - 1     );
    }
  }
  return a;
}
//****************************************************************************80

double r8vec_max ( int n, double r8vec[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_MAX returns the value of the maximum element in an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 August 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the array.
//
//    Input, double R8VEC[N], a pointer to the first entry of the array.
//
//    Output, double R8VEC_MAX, the value of the maximum element.  This
//    is set to 0.0 if N <= 0.
//
{
  int i;
  double value;

  value = r8vec[0];

  for ( i = 1; i < n; i++ )
  {
    if ( value < r8vec[i] )
    {
      value = r8vec[i];
    }
  }
  return value;
}
//****************************************************************************80

double r8vec_norm_l2 ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_NORM_L2 returns the L2 norm of an R8VEC.
//
//  Discussion:
//
//    The vector L2 norm is defined as:
//
//      R8VEC_NORM_L2 = sqrt ( sum ( 1 <= I <= N ) A(I)^2 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    01 March 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in A.
//
//    Input, double A[N], the vector whose L2 norm is desired.
//
//    Output, double R8VEC_NORM_L2, the L2 norm of A.
//
{
  int i;
  double v;

  v = 0.0;

  for ( i = 0; i < n; i++ )
  {
    v = v + a[i] * a[i];
  }
  v = sqrt ( v );

  return v;
}
//****************************************************************************80

void r8vec_print ( int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT prints an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(8)  << i
         << ": " << setw(14) << a[i]  << "\n";
  }

  return;
}
//****************************************************************************80

double r8vec_product ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRODUCT returns the product of the entries of an R8VEC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    17 September 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, double A[N], the vector.
//
//    Output, double R8VEC_PRODUCT, the product of the vector.
//
{
  int i;
  double product;

  product = 1.0;
  for ( i = 0; i < n; i++ )
  {
    product = product * a[i];
  }

  return product;
}
//****************************************************************************80

void r8vec_sort_bubble_a ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_SORT_BUBBLE_A ascending sorts an R8VEC using bubble sort.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 April 1999
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, length of input array.
//
//    double A[N], an array to be sorted.
//
//  Output:
//
//    double A[N]: the sorted array.
//
{
  int i;
  int j;
  double temp;

  for ( i = 0; i < n-1; i++ ) 
  {
    for ( j = i+1; j < n; j++ ) 
    {
      if ( a[j] < a[i] ) 
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}
//****************************************************************************80

double r8vec_sum ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_SUM returns the sum of an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 October 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, double A[N], the vector.
//
//    Output, double R8VEC_SUM, the sum of the vector.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a[i];
  }
  return value;
}
//****************************************************************************80

double *r8vec_uniform_ab_new ( int n, double b, double c, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_AB_NEW returns a scaled pseudorandom R8VEC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 October 2004
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in the vector.
//
//    double B, C, the range allowed for the entries.
//
//    int &SEED, a seed for the random number generator.
//
//  Output:
//
//    double R8VEC_UNIFORM_AB_NEW[N], the vector of pseudorandom values.
//
//    int &SEED, an updated seed.
//
{
  double *a;
  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )
  {
    a[i] = r8_uniform_ab ( b, c, seed );
  }

  return a; 
}
//****************************************************************************80

double *r8vec_uniform_01_new ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01_NEW returns a unit pseudorandom R8VEC.
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
//  Input:
//
//    int N, the number of entries in the vector.
//
//    int &SEED, a seed for the random number generator.
//
//  Output:
//
//    double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
//
//    int &SEED, an updated seed.
{
  int i;
  int i4_huge = 2147483647;
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

void r8vec_zero ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_ZERO zeroes an R8VEC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 July 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Output, double A[N], a vector of zeroes.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a[i] = 0.0;
  }
  return;
}
//****************************************************************************80

double *r8vec_zero_new ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_ZERO_NEW creates and zeroes an R8VEC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Output, double R8VEC_ZERO_NEW[N], a vector of zeroes.
//
{
  double *a;
  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )
  {
    a[i] = 0.0;
  }
  return a;
}
//****************************************************************************80

void r8vec2_print ( int n, double a1[], double a2[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC2_PRINT prints an R8VEC2.
//
//  Discussion:
//
//    An R8VEC2 is a dataset consisting of N pairs of real values, stored
//    as two separate vectors A1 and A2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 November 2002
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A1[N], double A2[N], the vectors to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i <= n - 1; i++ )
  {
    cout << setw(6)  << i
         << ": " << setw(14) << a1[i]
         << "  " << setw(14) << a2[i] << "\n";
  }

  return;
}
//****************************************************************************80

double rayleigh ( int n, double a[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    RAYLEIGH returns the Rayleigh quotient of the matrix A and the vector X.
//
//  Formula:
//
//    RAYLEIGH = X' * A * X / ( X' * X )
//
//  Properties:
//
//    If X is an eigenvector of A, then RAYLEIGH will equal the
//    corresponding eigenvalue.
//
//    The set of all Rayleigh quotients for a matrix is known
//    as its "field of values".
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double A[N*N], the matrix.
//
//    Input, double X[N], the vector used in the Rayleigh quotient.
//
//    Output, double RAYLEIGH, the Rayleigh quotient of A and X.
//
{
  double *ax;
  int i;
  int j;
  double value;
  double xax;
  double xx;

  ax = r8vec_zero_new ( n );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      ax[i] = ax[i] + a[i+j*n] * x[j];
    }
  }

  xax = r8vec_dot_product ( n, x, ax );
  xx = r8vec_dot_product ( n, x, x );
  value = xax / xx;
//
//  Free memory.
//
  delete [] ax;

  return value;
}
//****************************************************************************80

double rayleigh2 ( int n, double a[], double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    RAYLEIGH2 returns the generalized Rayleigh quotient.
//
//  Formula:
//
//    RAYLEIGH2 = X' * A * Y / ( X' * Y )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 May 2002
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double A[N*N], the matrix.
//
//    Input, double X[N], Y[N], the vectors used in the 
//    Rayleigh quotient.
//
//    Output, double RAYLEIGH2, the Rayleigh quotient of A and X.
//
{
  double *ay;
  int i;
  int j;
  double value;
  double xay;
  double xy;

  ay = r8vec_zero_new ( n );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      ay[i] = ay[i] + a[i+j*n] * y[j];
    }
  }
  xay = r8vec_dot_product ( n, x, ay );
  xy = r8vec_dot_product ( n, x, y );
  value = xay / xy;
//
//  Free memory.
//
  delete [] ay;

  return value;
}
//****************************************************************************80

double rectangle_adj_determinant ( int row_num, int col_num )

//****************************************************************************80
//
//  Purpose:
//
//    RECTANGLE_ADJ_DETERMINANT: the determinant of the RECTANGLE_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int ROW_NUM, COL_NUM, the number of rows and 
//    columns in the rectangle.
//
//    Output, double RECTANGLE_ADJ_DETERMINANT, the determinant.
//
{
  double determ;
//
//  If ROW_NUM == 1 or COL_NUM == 1 we have a case of the LINE_ADJ matrix.
//
  if ( row_num == 1 )
  {
    if ( ( row_num % 4 ) == 1 )
    {
      determ =   0.0;
    }
    else if ( ( row_num % 4 ) == 2 )
    {
      determ = - 1.0;
    }
    else if ( ( row_num % 4 ) == 3 )
    {
      determ =   0.0;
    }
    else if ( ( row_num % 4 ) == 0 )
    {
      determ = + 1.0;
    }
  }
  else if ( col_num == 1 )
  {
    if ( ( col_num % 4 ) == 1 )
    {
      determ =   0.0;
    }
    else if ( ( col_num % 4 ) == 2 )
    {
      determ = - 1.0;
    }
    else if ( ( col_num % 4 ) == 3 )
    {
      determ =   0.0;
    }
    else if ( ( col_num % 4 ) == 0 )
    {
      determ = + 1.0;
    }
  }
//
//  Otherwise, we can form at least one square, hence a null vector,
//  hence the matrix is singular.
//
  else
  {
    determ = 0.0;
  }
  return determ;
}
//****************************************************************************80

double *redheffer ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    REDHEFFER returns the REDHEFFER matrix.
//
//  Formula:
//
//    if ( J = 1 or mod ( J, I ) == 0 )
//      A(I,J) = 1
//    else
//      A(I,J) = 0
//
//  Example:
//
//    N = 5
//
//     1  1  1  1  1
//     1  1  0  1  0
//     1  0  1  0  0
//     1  0  0  1  0
//     1  0  0  0  1
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    The diagonal entries of A are all 1.
//
//    A is a zero/one matrix.
//
//    N - int ( log2 ( N ) ) - 1 eigenvalues are equal to 1.
//
//    There is a real eigenvalue of magnitude approximately sqrt ( N ),
//    which is the spectral radius of the matrix.
//
//    There is a negative eigenvalue of value approximately -sqrt ( N ).
//
//    The remaining eigenvalues are "small", and there is a conjecture
//    that they lie inside the unit circle in the complex plane.
//
//    The determinant is equal to the Mertens function M(N).
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Wayne Barrett, Tyler Jarvis,
//    Spectral Properties of a Matrix of Redheffer,
//    Linear Algebra and Applications,
//    Volume 162, 1992, pages 673-683.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double REDHEFFER[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == 0 || ( ( j + 1 ) % ( i + 1 ) == 0 ) )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double redheffer_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    REDHEFFER_DETERMINANT returns the determinant of the REDHEFFER matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, REDHEFFER_DETERMINANT, the determinant.
//
{
  double determ;

  determ = ( double ) ( mertens ( n ) );

  return determ;
}
//****************************************************************************80

double *ref_random ( int m, int n, double prob, int key )

//****************************************************************************80
//
//  Purpose:
//
//    REF_RANDOM returns a REF_RANDOM matrix.
//
//  Discussion:
//
//    The matrix returned is a random matrix in row echelon form.
//
//    The definition of row echelon form requires:
//
//    1) the first nonzero entry in any row is 1.
//
//    2) the first nonzero entry in row I occurs in a later column
//       than the first nonzero entry of every previous row.
//
//    3) rows that are entirely zero occur after all rows with
//       nonzero entries.
//
//  Example:
//
//    M = 6, N = 5, PROB = 0.8
//
//     1.0  0.3  0.2  0.0  0.5
//     0.0  0.0  1.0  0.7  0.9
//     0.0  0.0  0.0  1.0  0.3
//     0.0  0.0  0.0  0.0  1.0
//     0.0  0.0  0.0  0.0  0.0
//     0.0  0.0  0.0  0.0  0.0
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Input, double PROB, the probability that the 1 in the next 
//    row will be placed as early as possibly.
//    Setting PROB = 1 forces the 1 to occur immediately, setting
//    PROB = 0 forces the entire matrix to be zero.  A more reasonable
//    value might be PROB = 0.8 or 0.9.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double REF_RANDOM[M*N], the matrix.
//
{
  double *a;
  int i;
  int j;
  int jnew;
  int jprev;
  int seed;
  double temp;

  a = new double[m*n];

  seed = key;

  jprev = - 1;

  for ( i = 0; i < m; i++ )
  {
    jnew = - 1;

    for ( j = 0; j < n; j++ )
    {
      if ( j <= jprev )
      {
        a[i+j*m] = 0.0;
      }
      else if ( jnew == -1 )
      {
        temp = r8_uniform_01 ( seed );
        if ( temp <= prob )
        {
          jnew = j;
          a[i+j*m] = 1.0;
        }
        else
        {
          a[i+j*m] = 0.0;
        }
      }
      else
      {
        a[i+j*m] = r8_uniform_01 ( seed );
      }
    }
    if ( jnew == - 1 )
    {
      jnew = n;
    }
    jprev = jnew;
  }
  return a;
}
//****************************************************************************80

double ref_random_determinant ( int n, double prob, int key )

//****************************************************************************80
//
//  Purpose:
//
//    REF_RANDOM_DETERMINANT: determinant of a REF_RANDOM matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input, double PROB, the probability that the 1 in the next 
//    row will be placed as early as possibly.
//    Setting PROB = 1 forces the 1 to occur immediately, setting
//    PROB = 0 forces the entire matrix to be zero.  A more reasonable
//    value might be PROB = 0.8 or 0.9.
//
//    Input, int KEY, a positive value that selects the data.
//
//    Output, double REF_RANDOM_DETERMINANT, the determinant.
//
{
  double determ;
  int i;
  int j;
  int jnew;
  int jprev;
  int seed;
  double temp;

  determ = 1.0;

  seed = key;

  jprev = - 1;

  for ( i = 0; i < n; i++ )
  {
    jnew = - 1;

    for ( j = 0; j < n; j++ )
    {
      if ( j <= jprev )
      {
      }
      else if ( jnew == - 1 )
      {
        temp = r8_uniform_01 ( seed );
        if ( temp <= prob )
        {
          jnew = j;
        }
        else
        {
        }
      }
      else
      {
        temp = r8_uniform_01 ( seed );
      }
    }
    if ( jnew != i )
    {
      determ = 0.0;
    }
    if ( jnew == - 1 )
    {
      jnew = n;
    }
    jprev = jnew;
  }
  return determ;
}
//****************************************************************************80

double *riemann ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    RIEMANN returns the RIEMANN matrix.
//
//  Formula:
//
//    if ( I + 1 divides J + 1 evenly )
//      A(I,J) = I
//    else
//      A(I,J) = -1
//
//  Example:
//
//    M = 5, N = 5
//
//     1 -1  1 -1  1
//    -1  2 -1 -1  2
//    -1 -1  3 -1 -1
//    -1 -1 -1  4 -1
//    -1 -1 -1 -1  5
//
//  Discussion:
//
//    The Riemann hypothesis is true if and only if the determinant of A
//    is of order (N! * N^(-.5 + epsilon)) for every positive epsilon.
//
//  Properties:
//
//    A is generally not symmetric: A' /= A.
//
//    A is integral, therefore det ( A ) is integral, and 
//    det ( A ) * inverse ( A ) is integral.
//
//    The strict lower triangular entries are all -1.
//
//    If A is square, then each eigenvalue LAMBDA(I) satisfies
//      abs ( LAMBDA(I) ) <= (N+1) - 1 / (N+1),
//    and eigenvalue LAMBDA(I) satisfies
//      1 <= LAMBDA(I) <= I + 1
//    except for at most (N+1) - sqrt ( N + 1 ) values, and
//    all integers in the interval ( (N+1)/3, (N+1)/2 ] are eigenvalues.
//
//    The family of matrices is nested as a function of N.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Friedrich Roesler,
//    Riemann's hypothesis as an eigenvalue problem,
//    Linear Algebra and Applications,
//    Volume 81, 1986, pages 153-198.
//
//  Parameters:
//
//    Input, int M, N, the order of the matrix.
//
//    Output, double RIEMANN[M*N], the matrix.
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
      if ( ( j + 2 ) % ( i + 2 ) == 0 )
      {
        a[i+j*m] = ( double ) ( i );
      }
      else
      {
        a[i+j*m] = - 1.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double *ring_adj ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    RING_ADJ returns the RING_ADJ matrix.
//
//  Discussion:
//
//    This is the adjacency matrix for a ring, or set of points on a circle.
//
//  Example:
//
//    N = 5
//
//    0  1  0  0  1
//    1  0  1  0  0
//    0  1  0  1  0
//    0  0  1  0  1
//    1  0  0  1  0
//
//  Properties:
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    The determinant for N = 1 is 1, for N = 2 is -1, and for 2 < N,
//      mod ( N, 4 ) = 1 ==> det ( A ) =  2
//      mod ( N, 4 ) = 2 ==> det ( A ) = -4
//      mod ( N, 4 ) = 3 ==> det ( A ) =  2
//      mod ( N, 4 ) = 0 ==> det ( A ) =  0
//
//    A is a zero/one matrix.
//
//    A is an adjacency matrix.
//
//    A has a zero diagonal.
//
//    A is cyclic tridiagonal.
//
//    A is a circulant matrix: each row is shifted once to get the next row.
//
//    A has a constant row sum of 2.
//
//    Because it has a constant row sum of 2,
//    A has an eigenvalue of 2, and
//    a (right) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A has a constant column sum of 2.
//
//    Because it has a constant column sum of 2,
//    A has an eigenvalue of 2, and
//    a (left) eigenvector of ( 1, 1, 1, ..., 1 ).
//
//    A is persymmetric: A(I,J) = A(N+1-J,N+1-I).
//
//    A is centrosymmetric: A(I,J) = A(N+1-I,N+1-J).
//
//    When N is a multiple of 4, A has the null vector
//    (1,1,-1,-1, 1,1,-1,-1, ..., 1,1,-1,-1)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double RING_ADJ[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( j == i + 1 || j == i - 1 || j == i + 1 - n || j == i - 1 + n )
      {
        a[i+j*n] = 1.0;
      }
      else
      {
        a[i+j*n] = 0.0;
      }
    }
  }
  return a;
}
//****************************************************************************80

double ring_adj_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    RING_ADJ_DETERMINANT returns the determinant of the RING_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double RING_ADJ_DETERMINANT, the determinant.
//
{
  double determ;

  if ( n == 1 )
  {
    determ = 1.0;
  }
  else if ( n == 2 )
  {
    determ = -1.0;
  }
  else if ( ( n % 4 ) == 0 )
  {
    determ = 0.0;
  }
  else if ( ( n % 4 ) == 1 )
  {
    determ = 2.0;
  }
  else if ( ( n % 4 ) == 2 )
  {
    determ = -4.0;
  }
  else if ( ( n % 4 ) == 3 )
  {
    determ = 2.0;
  }
  return determ;
}
//****************************************************************************80

double *ring_adj_null_left ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    RING_ADJ_NULL_LEFT returns a left null vector of the RING_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, integer M, N, the order of the matrix.
//
//    Output, double RING_ADJ_NULL_LEFT[M], the null vector.
//
{
  int i;
  double *x;

  x = new double[m];

  if ( ( m % 4 ) != 0 )
  {
    cerr << "\n";
    cerr << "RING_ADJ_NULL_LEFT - Fatal error!\n";
    cerr << "  M must be a multiple of 4.\n";
    exit ( 1 );
  }

  for ( i = 0; i < m; i = i + 4 )
  {
    x[i]   = + 1.0;
    x[i+1] = + 1.0;
    x[i+2] = - 1.0;
    x[i+3] = - 1.0;
  }
  return x;
}
//****************************************************************************80

double *ring_adj_null_right ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    RING_ADJ_NULL_RIGHT returns a right null vector of the RING_ADJ matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, integer M, N, the order of the matrix.
//
//    Output, double RING_ADJ_NULL_RIGHT[N], the null vector.
//
{
  int i;
  double *x;

  x = new double[n];

  if ( ( n % 4 ) != 0 )
  {
    cerr << "\n";
    cerr << "RING_ADJ_NULL_RIGHT - Fatal error!\n";
    cerr << "  N must be a multiple of 4.\n";
    exit ( 1 );
  }

  for ( i = 0; i < n; i = i + 4 )
  {
    x[i]   = + 1.0;
    x[i+1] = + 1.0;
    x[i+2] = - 1.0;
    x[i+3] = - 1.0;
  }
  return x;
}
//****************************************************************************80

double *ris ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    RIS returns the RIS matrix.
//
//  Discussion:
//
//    This matrix is also called the dingdong matrix.  It was invented
//    by FN Ris.
//
//  Formula:
//
//    A(I,J) = 1 / ( 3 + 2 * N - 2 * I - 2 * J )
//
//  Example:
//
//    N = 5
//
//    1/9  1/7  1/5  1/3   1
//    1/7  1/5  1/3   1   -1
//    1/5  1/3   1   -1  -1/3
//    1/3   1   -1  -1/3 -1/5
//     1   -1  -1/3 -1/5 -1/7
//
//  Properties:
//
//    A is a Cauchy matrix.
//
//    A is a Hankel matrix: constant along anti-diagonals.
//
//    A is symmetric: A' = A.
//
//    Because A is symmetric, it is normal.
//
//    Because A is normal, it is diagonalizable.
//
//    The eigenvalues of A cluster around PI/2 and -PI/2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    John Nash,
//    Compact Numerical Methods for Computers: Linear Algebra and
//    Function Minimisation,
//    Second Edition,
//    Taylor & Francis, 1990,
//    ISBN: 085274319X,
//    LC: QA184.N37.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double RIS[N*N], the matrix.
//
{
  double *a;
  int i;
  int j;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      a[i+j*n] = 1.0 / ( double ) ( 2 * n - 2 * i - 2 * j - 1 );
    }
  }
  return a;
}
//****************************************************************************80

double ris_determinant ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    RIS_DETERMINANT returns the determinant of the RIS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double RIS_DETERMINANT, the determinant.
//
{
  double bottom;
  double determ;
  int i;
  int j;
  double top;

  top = 1.0;
  for ( i = 0; i < n; i++ )
  {
    for ( j = i + 1; j < n; j++ )
    {
      top = top * ( double ) ( 4 * ( i - j ) * ( i - j ) );
    }
  }

  bottom = 1.0;
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      bottom = bottom * ( double ) ( 2 * n - 2 * i - 2 * j - 1 );
    }
  }
  determ = top / bottom;

  return determ;
}
//****************************************************************************80

double *ris_inverse ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    RIS_INVERSE returns the inverse of the RIS matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Output, double RIS_INVERSE[N*N], the matrix.
//
{
  double *a;
  double bot1;
  double bot2;
  int i;
  int j;
  int k;
  double top;

  a = new double[n*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      top = 1.0;
      bot1 = 1.0;
      bot2 = 1.0;

      for ( k = 0; k < n; k++ )
      {
        top = top * ( 2 * n - 2 * j - 2 * k - 1 ) 
                  * ( 2 * n - 2 * k - 2 * i - 1 );

        if ( k != j )
        {
          bot1 = bot1 * ( double ) ( 2 * ( k - j ) );
        }
        if ( k != i )
        {
          bot2 = bot2 * ( double ) ( 2 * ( k - i ) );
        }
      }
      a[i+j*n] = top / 
        ( ( double ) ( 2 * n - 2 * j - 2 * i - 1 ) * bot1 * bot2 );
    }
  }
  return a;
}
//****************************************************************************80

double *rodman ( int m, int n, double alpha )

//****************************************************************************80
//
//  Purpose:
//
//    RODMAN returns the RODMAN matrix.
//
//  Formula:
//
//    If ( I = J ) then
//      A(I,J) = 1
//    else
//      A(I,J) = ALPHA
//
//  Example:
//
//    M = 5, N = 5, 
//
{