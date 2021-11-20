# include <cmath>
# include <complex>
# include <ctime>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "linpack_s.hpp"
# include "blas0.hpp"
# include "blas1_s.hpp"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void test08 ( );
void test09 ( );
void test10 ( );
void test11 ( );
void test12 ( );
void test13 ( );
void test14 ( );
void test15 ( );
void test16 ( );
void test17 ( );
void test18 ( );
void test19 ( );
void test20 ( );
void test21 ( );
void test22 ( );
void sqrdc_test ( );
void sqrsl_test ( );
void test24 ( );
void test25 ( );
void test26 ( );
void test27 ( );
void ssvdc_test ( );
void test29 ( );
void test30 ( );
void test31 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for LINPACK_S_TEST.
//
//  Discussion:
//
//    LINPACK_S_TEST tests the LINPACK_S library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 August 2016
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "LINPACK_S_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the LINPACK_S library.\n";

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
  test09 ( );

  test10 ( );
  test11 ( );
  test12 ( );
  test13 ( );
  test14 ( );
  test15 ( );
  test16 ( );
  test17 ( );
  test18 ( );
  test19 ( );

  test20 ( );
  test21 ( );
  test22 ( );
  sqrdc_test ( );
  sqrsl_test ( );
  test24 ( );
  test25 ( );
  test26 ( );
  test27 ( );
  ssvdc_test ( );
  test29 ( );

  test30 ( );
  test31 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "LINPACK_S_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test01 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tests SCHDC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 4
# define LDA N

  float a[LDA*N];
  float b[LDA*N];
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;
  int k;
  float work[N];

  cout << "\n";
  cout << "TEST01\n";
  cout << "  For a general matrix,\n";
  cout << "  SCHDC computes the Cholesky decomposition.\n";
  cout << "\n";
  cout << "  The number of equations is N = " << N << "\n";
//
//  Set the values of the matrix A.
//
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= N; i++ )
    {
      if ( i == j-1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else if ( i == j )
      {
        a[i-1+(j-1)*LDA] = 2.0;
      }
      else if ( i == j+1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }
  }

  cout << "\n";
  cout << "  The matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }
//
//  Decompose the matrix.
//
  cout << "\n";
  cout << "  Decompose the matrix.\n";

  job = 0;

  for ( i = 0; i < N; i++ )
  {
    ipvt[i] = 0;
  }

  info = schdc ( a, LDA, N, work, ipvt, job );

  if ( info != N )
  {
    cout << "\n";
    cout << "  SCHDC returned INFO = " << info << "\n";
    cout << "  This means the matrix is not positive definite.\n";
    return;
  }
//
//  Zero out the lower diagonal.
//
  for ( i = 2; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }
//
//  Print the factorization.
//
  cout << "\n";
  cout << "  The Cholesky factor U:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }
//
//  Compute the Cholesky product.
//
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      b[i-1+(j-1)*LDA] = 0.0;
      for ( k = 1; k <= N; k++ )
      {
        b[i-1+(j-1)*LDA] = b[i-1+(j-1)*LDA]
          + a[k-1+(i-1)*LDA] * a[k-1+(j-1)*LDA];
      }
    }
  }
  cout << "\n";
  cout << "  The product U' * U:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << b[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 tests SCHEX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define LDA N
# define NZ 1

  float a[LDA*N];
  float b[LDA*N];
  float c[N];
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;
  int k;
  int l;
  float s[N];
  float work[N];
  float z[N];

  cout << "\n";
  cout << "TEST02\n";
  cout << "  For a general matrix,\n";
  cout << "  SCHEX can shift columns in a Cholesky factorization.\n";
  cout << "\n";
  cout << "  The number of equations is N = " << N << "\n";
//
//  Set the values of the matrix A.
//
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= N; i++ )
    {
      if ( i == j-1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else if ( i == j )
      {
        a[i-1+(j-1)*LDA] = 2.0;
      }
      else if ( i == j+1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }
  }
  for ( i = 1; i <= N; i++ )
  {
    z[i-1] = ( float ) i;
  }

  cout << "\n";
  cout << "  The matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "  The vector Z:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout << "  " << setw(12) << z[i-1];
  }
//
//  Decompose the matrix.
//
  cout << "\n";
  cout << "  Decompose the matrix.\n";

  job = 0;

  for ( i = 0; i < N; i++ )
  {
    ipvt[i] = 0;
  }

  info = schdc ( a, LDA, N, work, ipvt, job );

  if ( info != N )
  {
    cout << "\n";
    cout << "  SCHDC returned INFO = " << info << "\n";
    cout << "  This means the matrix is not positive definite.\n";
    return;
  }
//
//  Zero out the lower diagonal.
//
  for ( i = 2; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }
//
//  Print the factorization.
//
  cout << "\n";
  cout << "  The Cholesky factor U:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }
//
//  Right circular shift columns L through K.
//
  k = 1;
  l = 3;

  cout << "\n";
  cout << "  Right circular shift columns K  = " << k <<
    " through L = " << l << "\n";

  job = 1;
  schex ( a, LDA, N, k, l, z, N, NZ, c, s, job );
//
//  Left circular shift columns K+1 through L.
//
  cout << "\n";
  cout << "  Left circular shift columns K+1 = " << k+1 <<
    " through L = " << l << "\n";

  job = 2;
  schex ( a, LDA, N, k+1, l, z, N, NZ, c, s, job );
//
//  Print the factorization.
//
  cout << "\n";
  cout << "  The shifted Cholesky factor U:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "  The shifted vector Z:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout << "  " << setw(12) << z[i-1];
  }
//
// Compute the Cholesky product.
//
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      b[i-1+(j-1)*LDA] = 0.0;
      for ( k = 1; k <= N; k++ )
      {
        b[i-1+(j-1)*LDA] = b[i-1+(j-1)*LDA]
          + a[k-1+(i-1)*LDA] * a[k-1+(j-1)*LDA];
      }
    }
  }

  cout << "\n";
  cout << "  The shifted product U' * U:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << b[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  return;
# undef LDA
# undef N
# undef NZ
}
//****************************************************************************80

void test03 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST03 tests SCHUD.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define P 20
# define LDR P
# define NZ 1

  float b[P];
  float c[P];
  int i;
  int j;
  int job;
  float r[LDR*P];
  float rho[NZ];
  float row[P];
  float s[P];
  int seed;
  float x[P];
  float y[NZ];
  float z[P*NZ];

  cout << "\n";
  cout << "TEST03\n";
  cout << "  For a general matrix,\n";
  cout << "  SCHUD updates a Cholesky decomposition.\n";
  cout << "\n";
  cout << "  In this example, we use SCHUD to solve a\n";
  cout << "  least squares problem R * b = z.\n";
  cout << "\n";
  cout << "  The number of equations is P = " << P << "\n";
//
//  Initialize.
//
  for ( j = 1; j <= P; j++ )
  {
    for ( i = 1; i <= P; i++ )
    {
      r[i-1+(j-1)*LDR] = 0.0;
    }
  }
  for ( j = 1; j <= NZ; j++ )
  {
    for ( i = 1; i <= P; i++ )
    {
      z[i-1+(j-1)*P] = 0.0;
    }
  }

  for ( i = 1; i <= P; i++ )
  {
    x[i-1] = ( float ) i;
  }
//
//  Use SCHUD to form R, Z and RHO by adding X and Y a row at a time.
//  X is a row of the least squares matrix and Y the right hand side.
//
  seed = 123456789;

  for ( i = 1; i <= P; i++ )
  {
    r4mat_uniform_01 ( 1, P, seed, row );
    y[0] = 0.0;
    for ( j = 1; j <= P; j++ )
    {
      y[0] = y[0] + row[j-1] * x[j-1];
    }
    rho[0] = 0.0;
    schud ( r, LDR, P, row, z, P, NZ, y, rho, c, s );
  }
//
//  Generate the least squares solution, b = inverse ( R ) * Z.
//
  for ( j = 1; j <= NZ; j++ )
  {
    for ( i = 1; i <= P; i++ )
    {
      b[i-1] = z[i-1+(j-1)*P];
    }
    job = 01;

    strsl ( r, LDR, P, b, job );

    cout << "\n";
    cout << "  Solution vector # " << j << "\n";
    cout << "  (Should be (1,2,3...,n))\n";
    cout << "\n";

    for ( i = 1; i <= P; i++ )
    {
      if ( i <= 5 || P-5 < i )
      {
        cout << "  " << setw(6) << i
             << "  " << setw(14) << b[i-1] << "\n";
      }
      if ( i == 5 )
      {
        cout << "  ......  ..............\n";
      }
    }
  }

  return;
# undef LDR
# undef NZ
# undef P
}
//****************************************************************************80

void test04 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST04 tests SGBCO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define ML 1
# define MU 1
# define LDA ( 2 * ML + MU + 1 )

  float a[LDA*N];
  int ipivot[N];
  int j;
  int m;
  float rcond;
  float z[N];

  cout << "\n";
  cout << "TEST04\n";
  cout << "  For a general banded matrix,\n";
  cout << "  SGBCO estimates the reciprocal condition number.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the matrix A.
//
  m = ML + MU + 1;
  cout << "  The bandwidth of the matrix is " << m << "\n";

  for ( j = 1; j <= N; j++ )
  {
    a[m-2+(j-1)*LDA] = -1.0;
    a[m-1+(j-1)*LDA] =  2.0;
    a[m  +(j-1)*LDA] = -1.0;
  }
//
//  Estimate the condition.
//
  cout << "\n";
  cout << "  Estimate the condition.\n";

  rcond = sgbco ( a, LDA, N, ML, MU, ipivot, z );

  cout << "\n";
  cout << "  Estimated reciprocal condition = " << rcond << "\n";

  return;
# undef LDA
# undef ML
# undef MU
# undef N
}
//****************************************************************************80

void test05 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST05 tests SGBFA and SGBSL.
//
//  Discussion:
//
//    The problem solved here is a larger version of this one:
//
//    Matrix A is ( 2 -1  0  0  0)    right hand side B is  (1)
//                (-1  2 -1  0  0)                          (0)
//                ( 0 -1  2 -1  0)                          (0)
//                ( 0  0 -1  2 -1)                          (0)
//                ( 0  0  0 -1  2)                          (1)
//
//
//    Solution is   (1)
//                  (1)
//                  (1)
//                  (1)
//                  (1)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
//  Local Parameters:
//
//    N is the number of equations.
//
//    ML is the number of subdiagonals,
//    MU the number of superdiagonals.
//
//    LDA is the leading dimension of the array used to store the
//    matrix, which must be at least 2*ML+MU+1.
//
{
# define N 10
# define ML 1
# define MU 1
# define LDA ( 2 * ML + MU + 1 )

  float a[LDA*N];
  float b[N];
  int i;
  int info;
  int ipivot[N];
  int j;
  int job;
  int m;

  cout << "\n";
  cout << "TEST05\n";
  cout << "  For a general banded matrix,\n";
  cout << "  SGBFA computes the LU factors,\n";
  cout << "  SGBSL solves a factored linear system.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the right hand side B.
//
  b[0] = 1.0;
  for ( i = 2; i <= N-1; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = 1.0;
//
//  Set the matrix A.
//
  m = ML + MU + 1;
  cout << "  The bandwidth of the matrix is " << m << "\n";

  for ( j = 1; j <= N; j++ )
  {
    a[m-2+(j-1)*LDA] = -1.0;
    a[m-1+(j-1)*LDA] =  2.0;
    a[m  +(j-1)*LDA] = -1.0;
  }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = sgbfa ( a, LDA, N, ML, MU, ipivot );

  if ( info != 0 )
  {
    cout << "  Error!  SGBFA returns INFO = " << info << "\n";
    return;
  }
//
//  Call SGBSL to solve the linear system.  The solution
//  is returned in B, that is, it overwrites the right hand side.
//
  cout << "\n";
  cout << "  Solve the linear system.\n";

  job = 0;
  sgbsl ( a, LDA, N, ML, MU, ipivot, b, job );
//
//  Print the results.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,1,1,1,1,...,1,1))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }

  return;
# undef LDA
# undef ML
# undef MU
# undef N
}
//****************************************************************************80

void test06 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST06 tests SGBFA and SGBDI.
//
//  Discussion:
//
//    Matrix A is ( 2 -1  0  0  0)
//                (-1  2 -1  0  0)
//                ( 0 -1  2 -1  0)
//                ( 0  0 -1  2 -1)
//                ( 0  0  0 -1  2)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
//  Local Parameters:
//
//    N is the number of equations.
//
//    ML is the number of subdiagonals,
//    MU the number of superdiagonals.
//
//    LDA is the leading dimension of the array used to store the
//    matrix, which must be at least 2*ML+MU+1.
//
{
# define N_MAX 128
# define ML 1
# define MU 1
# define LDA ( 2 * ML + MU + 1 )

  float a[LDA*N_MAX];
  float det[2];
  int i;
  int info;
  int ipivot[N_MAX];
  int j;
  int m;
  int n;
  int n_log;

  cout << "\n";
  cout << "TEST06\n";
  cout << "  For a general banded matrix,\n";
  cout << "  SGBFA factors the matrix,\n";
  cout << "  SGBDI computes the determinant as\n";
  cout << "    det = MANTISSA * 10^EXPONENT\n";
  cout << "\n";
  cout << "  Find the determinant of the -1,2,-1 matrix\n";
  cout << "  for N = 2, 4, 8, 16, 32, 64, 128.\n";
  cout << "\n";
  cout << "  (For this matrix, det ( A ) = N + 1.)\n";
//
//  Set the matrix A.
//
  m = ML + MU + 1;
  cout << "  The bandwidth of the matrix is " << m << "\n";
  cout << "\n";
  cout << "       N    Mantissa       Exponent\n";
  cout << "\n";

  n = 1;

  for ( n_log = 1; n_log <= 7; n_log++ )
  {
    n = 2 * n;

    for ( j = 1; j <= n; j++ )
    {
      for ( i = 1; i <= LDA; i++ )
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }

    for ( j = 1; j <= n; j++ )
    {
      i = j;
      a[i-j+ML+MU+(j-1)*LDA] = 2.0;
    }

    for ( j = 2; j <= n; j++ )
    {
      i = j - 1;
      a[i-j+ML+MU+(j-1)*LDA] = -1.0;
    }

    for ( j = 1; j <= n-1; j++ )
    {
      i = j + 1;
      a[i-j+ML+MU+(j-1)*LDA] = -1.0;
    }

    info = sgbfa ( a, LDA, n, ML, MU, ipivot );

    if ( info != 0 )
    {
      cout << "  Error!  SGBFA returns INFO = " << info << "\n";
      return;
    }

    sgbdi ( a, LDA, n, ML, MU, ipivot, det );

    cout << "  " << setw(6)  << n
         << "  " << setw(14) << det[0]
         << "  " << setw(14) << det[1] << "\n";
  }

  return;
# undef LDA
# undef ML
# undef MU
# undef N_MAX
}
//****************************************************************************80

void test07 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST07 tests SGBFA and SGBSL.
//
//  Discussion:
//
//    SGBFA and SGBSL are for general banded matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 100
# define ML 25
# define MU 25
# define LDA ( 2 * ML + MU + 1 )

  float a[LDA*N];
  float b[N];
  int i;
  int ihi;
  int ilo;
  int info;
  int ipivot[N];
  int j;
  int job;
  int m;
  float temp;

  cout << "\n";
  cout << "TEST07\n";
  cout << "  For a general banded matrix,\n";
  cout << "  SGBFA computes the LU factors,\n";
  cout << "  SGBSL solves a factored linear system.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Assign values to matrix A and right hand side B.
//
//  We want to try a problem with a significant bandwidth.
//
  m = ML + MU + 1;
  cout << "  The bandwidth of the matrix is " << m << "\n";

  for ( j = 1; j <= N; j++ )
  {
    ilo = i4_max ( 1, j - MU );
    ihi = i4_min ( N, j + ML );

    temp = 0.0;
    for ( i = ilo; i <= ihi; i++ )
    {
      a[i-j+m-1+(j-1)*LDA] = -1.0;
      temp = temp - 1.0;
    }
    temp = temp + 1.0;
    a[m-1+(j-1)*LDA] = 4.0 - temp;
    b[j-1] = 4.0;
  }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = sgbfa ( a, LDA, N, ML, MU, ipivot );

  if ( info != 0 )
  {
    cout << "  Error!  SGBFA returns INFO = " << info << "\n";
    return;
  }
//
//  Call SGBSL to solve the linear system.  The solution
//  is returned in B, that is, it overwrites the right hand side.
//
  cout << "\n";
  cout << "  Solve the linear system.\n";

  job = 0;
  sgbsl ( a, LDA, N, ML, MU, ipivot, b, job );
//
//  Print the results.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,1,1,1,1,...,1,1))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }

  return;
# undef LDA
# undef ML
# undef MU
# undef N
}
//****************************************************************************80

void test08 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST08 calls SGECO and SGESL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
//  Local Parameters:
//
//    LDA defines the maximum matrix size we will use.
//
{
# define LDA 10

  float a[LDA*LDA];
  float b[LDA];
  int i;
  int ipvt[LDA];
  int job;
  int n;
  float rcond;
  float z[LDA];

  n = 3;

  cout << "\n";
  cout << "TEST08\n";
  cout << "  For a general matrix,\n";
  cout << "  SGECO computes the LU factors and computes\n";
  cout << "  its reciprocal condition number;\n";
  cout << "  SGESL solves a factored linear system.\n";
  cout << "  The matrix size is N = " << n << "\n";
//
//  Set the values of the matrix A.
//
  a[0+0*LDA] = 1.0;
  a[0+1*LDA] = 2.0;
  a[0+2*LDA] = 3.0;

  a[1+0*LDA] = 4.0;
  a[1+1*LDA] = 5.0;
  a[1+2*LDA] = 6.0;

  a[2+0*LDA] = 7.0;
  a[2+1*LDA] = 8.0;
  a[2+2*LDA] = 0.0;
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  rcond = sgeco ( a, LDA, n, ipvt, z );

  cout << "  The reciprocal matrix condition number = " << rcond << "\n";

  if ( rcond + 1.0 == 1.0 )
  {
    cout << "  Error!  The matrix is nearly singular!\n";
    return;
  }
//
//  Set a right hand side.
//
  b[0] = 6.0;
  b[1] = 15.0;
  b[2] = 15.0;
//
//  Solve the linear system.
//
  cout << "\n";
  cout << "  Solve the linear system.\n";

  job = 0;
  sgesl ( a, LDA, n, ipvt, b, job );
//
//  Print the results.
//
  cout << "\n";
  cout << "  Solution returned by SGESL\n";
  cout << "  (Should be (1,1,1))\n";
  cout << "\n";
  for ( i = 1; i <= n; i++ )
  {
    cout << "  " << setw(14) << b[i-1] << "\n";
  }
//
//  A second right hand side can be solved without refactoring a.
//
  cout << "\n";
  cout << "  Call SGESL for a new right hand\n";
  cout << "  side for the same, factored matrix.\n";
//
//  Set the right hand side.
//
  b[0] = 1.0;
  b[1] = 4.0;
  b[2] = 7.0;
//
//  Solve the system.
//
  cout << "\n";
  cout << "  Solve a linear system.\n";

  job = 0;
  sgesl ( a, LDA, n, ipvt, b, job );
//
//  Print the results.
//
  cout << "\n";
  cout << "  Solution returned by SGESL\n";
  cout << "  (should be (1,0,0))\n";
  cout << "\n";
  for ( i = 1; i <= n; i++ )
  {
    cout << "  " << setw(14) << b[i-1] << "\n";
  }
//
//  The transposed problem A'*X = B can be solved by SGESL
//  as well, without any refactoring.
//
  cout << "\n";
  cout << "  Call SGESL for transposed problem.\n";
//
//  Set the right hand side.
//
  b[0] = 6.0;
  b[1] = 6.0;
  b[2] = -3.0;
//
//  Solve the transposed system.
//
  cout << "\n";
  cout << "  Call SGESL to solve a transposed linear system.\n";

  job = 1;
  sgesl ( a, LDA, n, ipvt, b, job );
//
//  Print the results.
//
  cout << "\n";
  cout << "  Solution returned by SGESL\n";
  cout << "  (should be (-1,0,1))\n";
  cout << "\n";
  for ( i = 1; i <= n; i++ )
  {
    cout << "  " << setw(14) << b[i-1] << "\n";
  }

  return;
# undef LDA
}
//****************************************************************************80

void test09 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST09 tests SGEFA and SGEDI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 3
# define LDA 3
//
//  Matrix listed by columns.
//
  float a[LDA*N] = {
    1.0, 4.0, 7.0,
    2.0, 5.0, 8.0,
    3.0, 6.0, 0.0 };
  float det[2];
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;
  float work[N];

  cout << "\n";
  cout << "TEST09\n";
  cout << "  For a general banded matrix,\n";
  cout << "  SGEFA computes the LU factors;\n";
  cout << "  SGEDI computes the inverse and determinant.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = sgefa ( a, LDA, N, ipvt );

  if ( info != 0 )
  {
    cout << "  Error!  The matrix is nearly singular!\n";
    return;
  }
//
//  Get the inverse and determinant.
//
  cout << "\n";
  cout << "  Get the inverse and determinant.\n";

  job = 11;
  sgedi ( a, LDA, N, ipvt, det, work, job );

  cout << "\n";
  cout << "  The determinant = " << det[0] << " * 10^"<< det[1] << "\n";

  cout << "\n";
  cout << "  The inverse matrix:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test10 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST10 tests SGEFA and SGESL.
//
//  Discussion:
//
//    Solve A*x = b where A is a given matrix, and B a right hand side.
//
//    We will also assume that A is stored in the simplest
//    possible way.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 3
# define LDA N
//
//  The entries of the matrix A are listed by columns.
//
  float a[LDA*N] = {
    1.0, 4.0, 7.0,
    2.0, 5.0, 8.0,
    3.0, 6.0, 0.0 };
  float b[N] = { 6.0, 15.0, 15.0 };
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;

  cout << "\n";
  cout << "TEST10\n";
  cout << "  For a general banded matrix,\n";
  cout << "  SGEFA computes the LU factors;\n";
  cout << "  SGESL solves a factored linear system;\n";
  cout << "\n";
  cout << "  The number of equations is N = " << N << "\n";

  cout << "\n";
  cout << "  The matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(14) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "  The right hand side B:\n";
  cout << "\n";
  for ( i = 1; i <= N; i++ )
  {
    cout << "  " << setw(14) << b[i-1];
  }
  cout << "\n";
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = sgefa ( a, LDA, N, ipvt );

  if ( info != 0 )
  {
    cout << "  SGEFA returned an error flag INFO = " << info << "\n";
    return;
  }
//
//  Solve the system.
//
  job = 0;
  sgesl ( a, LDA, N, ipvt, b, job );

  cout << "\n";
  cout << "  SGESL returns the solution:\n";
  cout << "  (Should be (1,1,1))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout << "  " << setw(14) << b[i-1];
  }
  cout << "\n";

  return;
# undef N
# undef LDA
}
//****************************************************************************80

void test11 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST11 tests SGEFA and SGESL.
//
//  Discussion:
//
//    In this example, we solve a relatively large linear system.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 100
# define LDA N

  float a[LDA*N];
  float b[N];
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;

  cout << "\n";
  cout << "TEST11\n";
  cout << "  For a general banded matrix,\n";
  cout << "  SGEFA computes the LU factors;\n";
  cout << "  SGESL solves a factored linear system;\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Assign values to the matrix A and the right hand side B.
//
//  The problem is just an enlarged version of the
//  problem for N = 5, which is:
//
//  Matrix A is ( n -1 -1 -1 -1)    Right hand side B is  (1)
//              (-1  n -1 -1 -1)                          (1)
//              (-1 -1  n -1 -1)                          (1)
//              (-1 -1 -1  n -1)                          (1)
//              (-1 -1 -1 -1  n)                          (1)
//
//  Solution is   (1)
//                (1)
//                (1)
//                (1)
//                (1)
//
  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 1.0;
  }

  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= N; i++ )
    {
      if ( i == j )
      {
        a[i-1+(j-1)*LDA] = ( float ) N;
      }
      else
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
    }
   }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = sgefa ( a, LDA, N, ipvt );

  if ( info != 0 )
  {
    cout << "  SGEFA returned an error flag INFO = " << info << "\n";
    return;
  }
//
//  Solve the system.
//
  cout << "\n";
  cout << "  Solve the factored system.\n";

  job = 0;
  sgesl ( a, LDA, N, ipvt, b, job );
//
//  Print the results.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,1,1,1,1,...,1,1))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test12 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST12 tests SGTSL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 100

  float b[N];
  float c[N];
  float d[N];
  float e[N];
  int i;
  int info;

  cout << "\n";
  cout << "TEST12\n";
  cout << "  For a general tridiagonal matrix,\n";
  cout << "  SGTSL factors and solves a linear system.\n";
  cout << "  The matrix size is N = " << N << "\n";
  cout << "\n";
//
//  Set up the linear system, by storing the values of the
//  subdiagonal, diagonal, and superdiagonal in C, D, and E,
//  and the right hand side in B.
//
  c[0] = 0.0;
  for ( i = 2; i <= N; i++ )
  {
    c[i-1] = -1.0;
  }

  for ( i = 1; i <= N; i++ )
  {
    d[i-1] = 2.0;
  }

  for ( i = 1; i <= N-1; i++ )
  {
    e[i-1] = -1.0;
  }
  e[N-1] = 0.0;

  for ( i = 1; i <= N-1; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = ( float ) ( N + 1 );
//
// Factor the matrix and solve the system.
//
  cout << "\n";
  cout << "  Factor the matrix and solve the system.\n";

  info = sgtsl ( N, c, d, e, b );

  if ( info != 0 )
  {
    cout << "\n";
    cout << "  SGTSL returns nonzero INFO = " << info << "\n";
    return;
  }
//
//  Print the results.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,2,3,4,5,...,n-1,n))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }

  return;
# undef N
}
//****************************************************************************80

void test13 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST13 tests SPBCO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define LDA 2

  float a[LDA*N];
  int j;
  int m;
  float rcond;
  float z[N];

  cout << "\n";
  cout << "TEST13\n";
  cout << "  For a positive definite symmetric banded matrix,\n";
  cout << "  SPBCO estimates the reciprocal condition number.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the number of nonzero diagonals.
//
  m = 1;
//
//  Set the value of the subdiagonal and diagonal.
//
  for ( j = 1; j <= N; j++ )
  {
    a[0+(j-1)*LDA] = -1.0;
    a[1+(j-1)*LDA] = 2.0;
  }

  cout << "\n";
  cout << "  Estimate the condition.\n";

  rcond = spbco ( a, LDA, N, m, z );

  cout << "\n";
  cout << "  Reciprocal condition  = " << rcond << "\n";

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test14 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST14 tests SPBDI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N_MAX 128
# define LDA 2

  float a[LDA*N_MAX];
  float det[2];
  int info;
  int j;
  int m;
  int n;
  int n_log;

  cout << "\n";
  cout << "TEST14\n";
  cout << "  For a positive definite symmetric banded matrix,\n";
  cout << "  SPBDI computes the determinant as\n";
  cout << "    det = MANTISSA * 10^EXPONENT\n";
  cout << "\n";
  cout << "  Find the determinant of the -1,2,-1 matrix\n";
  cout << "  for N = 2, 4, 8, 16, 32, 64, 128.\n";
  cout << "\n";
  cout << "  (For this matrix, det ( A ) = N + 1.)\n";
//
//  Set the number of  nonzero diagonals.
//
  m = 1;

  cout << "\n";
  cout << "       N    Mantissa       Exponent\n";
  cout << "\n";

  n = 1;

  for ( n_log = 1; n_log <= 7; n_log++ )
  {
    n = 2 * n;

    a[0+0*LDA] =  0.0;
    for ( j = 2; j <= n; j++ )
    {
      a[0+(j-1)*LDA] = -1.0;
    }
    for ( j = 1; j <= n; j++ )
    {
      a[1+(j-1)*LDA] = 2.0;
    }

    info = spbfa ( a, LDA, n, m );

    if ( info != 0 )
    {
      cout << "  Error!  SPBFA returns INFO = " << info << "\n";
      return;
    }

    spbdi ( a, LDA, n, m, det );

    cout << "  " << setw(6)  << n
         << "  " << setw(14) << det[0]
         << "  " << setw(14) << det[1] << "\n";
  }

  return;
# undef LDA
# undef N_MAX
}
//****************************************************************************80

void test15 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST15 tests SPBFA and SPBSL.
//
//  Discussion:
//
//    SPBFA and SPBSL are for a positive definite symmetric band matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 10
# define LDA 2

  float a[LDA*N];
  float b[N];
  int i;
  int info;
  int j;
  int m;

  cout << "\n";
  cout << "TEST15\n";
  cout << "  For a positive definite symmetric banded matrix,\n";
  cout << "  SPBFA computes the LU factors.\n";
  cout << "  SPBSL solves a factored linear system.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Assign values to matrix A and right hand side B.
//
//  The problem is just an enlarged version of the
//  problem for N = 5, which is:
//
//  Matrix A is ( 2 -1  0  0  0)    right hand side B is  (1)
//              (-1  2 -1  0  0)                          (0)
//              ( 0 -1  2 -1  0)                          (0)
//              ( 0  0 -1  2 -1)                          (0)
//              ( 0  0  0 -1  2)                          (1)
//
//
//  solution is   (1)
//                (1)
//                (1)
//                (1)
//                (1)
//
//  Set the right hand side.
//
  b[0] = 1.0;
  for ( i = 2; i <= N-1; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = 1.0;
//
//  Set the number of nonzero diagonals.
//
  m = 1;
//
//  Set the value of the subdiagonal and diagonal.
//
  for ( j = 1; j <= N; j++ )
  {
    a[0+(j-1)*LDA] = -1.0;
    a[1+(j-1)*LDA] = 2.0;
  }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = spbfa ( a, LDA, N, m );

  if ( info != 0 )
  {
    cout << "  Error!  SPBFA returns INFO = " << info << "\n";
    return;
  }
//
//  Solve the linear system.
//
  cout << "\n";
  cout << "  Solve the linear system.\n";

  spbsl ( a, LDA, N, m, b );
//
//  Print the results.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,1,1,1,1,...,1,1))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }
  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test16 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST16 tests SPOCO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define LDA N

  float a[LDA*N];
  int i;
  int j;
  float rcond;
  float z[N];

  cout << "\n";
  cout << "TEST16\n";
  cout << "  For a positive definite symmetric banded matrix,\n";
  cout << "  SPOCO estimates the reciprocal condition number.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the matrix A.
//
  for ( j = 0; j < N; j++ )
  {
    for ( i = 0; i < N; i++ )
    {
      a[i+j*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++ )
  {
    a[i-1+(i-1)*LDA] = 2.0;
    if ( 1 < i )
    {
      a[i-1+(i-2)*LDA] = -1.0;
    }
    if ( i < N )
    {
      a[i-1+(i)*LDA] = -1.0;
    }
  }

  cout << "\n";
  cout << "  Estimate the condition.\n";

  rcond = spoco ( a, LDA, N, z );

  cout << "\n";
  cout << "  Reciprocal condition  = " << rcond << "\n";

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test17 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST17 tests SPOFA and SPODI.
//
//  Discussion:
//
//    SPOFA factors a positive definite symmetric matrix,
//    and SPODI can compute the determinant or the inverse.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define LDA N

  float a[LDA*N];
  float det[2];
  int i;
  int info;
  int j;
  int job;

  cout << "\n";
  cout << "TEST17\n";
  cout << "  For a positive definite symmetric matrix,\n";
  cout << "  SPOFA computes the LU factors.\n";
  cout << "  SPODI computes the inverse or determinant.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the matrix A.
//
  for ( j = 0; j < N; j++ )
  {
    for ( i = 0; i < N; i++ )
    {
      a[i+j*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++ )
  {
    a[i-1+(i-1)*LDA] = 2.0;
    if ( 1 < i )
    {
      a[i-1+(i-2)*LDA] = -1.0;
    }
    if ( i < N )
    {
      a[i-1+(i)*LDA] = -1.0;
    }
  }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = spofa ( a, LDA, N );

  if ( info != 0 )
  {
    cout << "  Error, SPOFA returns INFO = " << info << "\n";
    return;
  }
//
//  Invert the matrix.
//
  cout << "\n";
  cout << "  Get the determinant and inverse.\n";

  job = 11;
  spodi ( a, LDA, N, det, job );
//
//  Print the results.
//
  cout << "\n";
  cout << "  Determinant = " << det[0] << " * 10^" << det[1] << "\n";
//
//  SPODI produces only the 'upper half triangle' of the inverse,
//  which is actually symmetric.  Thus, the lower half could be
//  produced by copying from the upper half.  However, the first row
//  of A, as returned, is exactly the first row of the inverse.
//
  cout << "\n";
  cout << "  First row of inverse:\n";
  cout << "\n";
  for ( j = 1; j <= N; j++ )
  {
    cout << "  " << setw(12) << a[0+(j-1)*LDA];
  }
  cout << "\n";

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test18 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST18 tests SPOFA and SPOSL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 20
# define LDA N

  float a[LDA*N];
  float b[N];
  int i;
  int info;
  int j;
  float x[N];

  cout << "\n";
  cout << "TEST18\n";
  cout << "  For a positive definite symmetric matrix,\n";
  cout << "  SPOFA computes the LU factors.\n";
  cout << "  SPOSL solves a factored linear system.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the matrix A.
//
  for ( j = 0; j < N; j++ )
  {
    for ( i = 0; i < N; i++ )
    {
      a[i+j*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++ )
  {
    a[i-1+(i-1)*LDA] = 2.0;
    if ( 1 < i )
    {
      a[i-1+(i-2)*LDA] = -1.0;
    }
    if ( i < N )
    {
      a[i-1+(i)*LDA] = -1.0;
    }
  }
//
//  Set the right hand side.
//
  for ( i = 1; i <= N; i++ )
  {
    x[i-1] = ( float ) i;
  }
  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[i-1+(j-1)*LDA] * x[j-1];
    }
  }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = spofa ( a, LDA, N );

  if ( info != 0 )
  {
    cout << "  Error, SPOFA returns INFO = " << info << "\n";
    return;
  }
//
//  Solve the linear system.
//
  sposl ( a, LDA, N, b );
//
//  Print the result.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,2,3,4,5,...,n-1,n))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test19 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST19 tests SPPCO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 5

  float a[(N*(N+1))/2];
  int i;
  int j;
  int k;
  float rcond;
  float z[N];

  cout << "\n";
  cout << "TEST19\n";
  cout << "  For a positive definite symmetric packed matrix,\n";
  cout << "  SPPCO estimates the reciprocal condition number.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the matrix A.
//
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j - 1 )
      {
        a[k-1] = -1.0;
      }
      else if ( i == j )
      {
        a[k-1] = 2.0;
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
//
//  Estimate the condition.
//
  cout << "\n";
  cout << "  Estimate the condition number.\n";

  rcond = sppco ( a, N, z );

  cout << "\n";
  cout << "  Reciprocal condition number = " << rcond << "\n";

  return;
# undef N
}
//****************************************************************************80

void test20 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST20 tests SPPFA and SPPDI.
//
//  Discussion:
//
//    SPPFA factors a packed positive definite symmetric matrix,
//    and SPPDI can compute the determinant or the inverse.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 5

  float a[(N*(N+1))/2];
  float b[N*N];
  float det[2];
  int i;
  int info;
  int j;
  int job;
  int k;

  cout << "\n";
  cout << "TEST20\n";
  cout << "  For a positive definite symmetric packed matrix,\n";
  cout << "  SPPFA computes the LU factors.\n";
  cout << "  SPPDI computes the inverse or determinant.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the matrix A.
//
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j - 1 )
      {
        a[k-1] = -1.0;
      }
      else if ( i == j )
      {
        a[k-1] = 2.0;
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = sppfa ( a, N );

  if ( info != 0 )
  {
    cout << "\n";
    cout << "  Error, SPPFA returns INFO = " << info << "\n";
    return;
  }
//
//  Invert the matrix.
//
  cout << "\n";
  cout << "  Get the determinant and inverse.\n";

  job = 11;
  sppdi ( a, N, det, job );
//
//  Print the results.
//
  cout << "\n";
  cout << "  Determinant = " << det[0] << " * 10^" << det[1] << "\n";
//
//  SPPDI produces only the 'upper half triangle' of the inverse,
//  which is actually symmetric.  Thus, the lower half could be
//  produced by copying from the upper half.  However, the first row
//  of A, as returned, is exactly the first row of the inverse.
//
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      b[i-1+(j-1)*N] = a[k-1];
      b[j-1+(i-1)*N] = a[k-1];
    }
  }

  cout << "\n";
  cout << "  The inverse matrix:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << b[i-1+(j-1)*N];
    }
    cout << "\n";
  }

  return;
# undef N
}
//****************************************************************************80

void test21 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST21 tests SPPFA and SPPSL.
//
//  Discussion:
//
//    SPOFA factors a positive definite symmetric matrix,
//    and SPOSL can solve a factored linear system.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 20

  float a[(N*(N+1))/2];
  float b[N];
  int i;
  int info;
  int j;
  int k;
  float x[N];

  cout << "\n";
  cout << "TEST21\n";
  cout << "  For a positive definite symmetric packed matrix,\n";
  cout << "  SPPFA computes the LU factors.\n";
  cout << "  SPPSL solves a factored linear system.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the matrix A.
//
  for ( i = 1; i <= N; i++ )
  {
    x[i-1] = ( float ) i;
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
  }
//
//  Set the matrix A.
//
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j - 1 )
      {
        a[k-1] = -1.0;
        b[i-1] = b[i-1] + a[k-1] * x[j-1];
        b[j-1] = b[j-1] + a[k-1] * x[i-1];
      }
      else if ( i == j )
      {
        a[k-1] = 2.0;
        b[i-1] = b[i-1] + a[k-1] * x[i-1];
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = sppfa ( a, N );

  if ( info != 0 )
  {
    cout << "\n";
    cout << "  Error, SPPFA returns INFO = " << info << "\n";
    return;
  }
//
//  Solve the linear system.
//
  sppsl ( a, N, b );
//
//  Print the result.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,2,3,4,5,...,n-1,n))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }
  return;
# undef N
}
//****************************************************************************80

void test22 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST22 tests SPTSL.
//
//  Discussion:
//
//    SPTSL factors and solves a positive definite symmetric tridiagonal system.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 20

  float b[N];
  float d[N];
  float e[N];
  int i;
  float x[N];

  cout << "\n";
  cout << "TEST22\n";
  cout << "  For a positive definite symmetric tridiagonal matrix,\n";
  cout << "  SPTSL factors and solves a linear system.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Set the matrix A.
//
  for ( i = 1; i <= N; i++ )
  {
    x[i-1] = ( float ) i;
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
  }
  for ( i = 1; i <= N; i++ )
  {
    d[i-1] = 2.0;
  }
  for ( i = 1; i <= N-1; i++ )
  {
    e[i-1] = -1.0;
  }
  e[N-1] = 0.0;

  for ( i = 1; i <= N; i++ )
  {
    if ( 1 < i )
    {
      b[i-1] = b[i-1] + e[i-2] * x[i-2];
    }
    b[i-1] = b[i-1] + d[i-1] * x[i-1];
    if ( i < N )
    {
      b[i-1] = b[i-1] + e[i-1] * x[i];
    }
  }
//
//  Factor and solve the system.
//
  cout << "\n";
  cout << "  Factor the matrix and solve the system.\n";

  sptsl ( N, d, e, b );
//
//  Print the result.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,2,3,4,5,...,n-1,n))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }

  return;
# undef N
}
//****************************************************************************80

void sqrdc_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SQRDC_TEST tests SQRDC.
//
//  Discussion:
//
//    SQRDC computes the QR factorization.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 3
# define P 3
# define LDA N

  float a[LDA*P] = {
    1.0, 1.0, 0.0,
    1.0, 0.0, 1.0,
    0.0, 1.0, 1.0 };
  float b[LDA*P];
  int i;
  int info;
  int ipvt[P];
  int j;
  int job;
  int k;
  float q[N*N];
  float qraux[P];
  float qty[N];
  float qy[N];
  float r[N*P];
  float rsd[N];
  float work[P];
  float xb[N];
  float y[N];

  cout << "\n";
  cout << "SQRDC_TEST\n";
  cout << "  SQRDC computes the QR decomposition of a rectangular\n";
  cout << "  matrix, but does not return Q and R explicitly.\n";
  cout << "\n";
  cout << "  Show how Q and R can be recovered using SQRSL.\n";
//
//  Print the matrix A.
//
  cout << "\n";
  cout << "  The matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }
//
//  Decompose the matrix.
//
  cout << "\n";
  cout << "  Decompose the matrix.\n";

  job = 0;
  for ( j = 1; j <= P; j++ )
  {
    ipvt[j] = 0;
  }

  sqrdc ( a, LDA, N, P, qraux, ipvt, work, job );
//
//  Print out what SQRDC has stored in A...
//
  cout << "\n";
  cout << "  The packed matrix A which describes Q and R:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }
//
//  ...and in QRAUX.
//
  cout << "\n";
  cout << "  The QRAUX vector, containing some additional\n";
  cout << "  information defining Q:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout << "  " << setw(12) << qraux[i-1];
  }
  cout << "\n";
//
//  Print out the resulting R factor.
//
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      if ( j < i )
      {
        r[i-1+(j-1)*N] = 0.0;
      }
      else
      {
        r[i-1+(j-1)*N] = a[i-1+(j-1)*LDA];
      }
    }
  }

  cout << "\n";
  cout << "  The R factor:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      cout << "  " << setw(12) << r[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }
//
//  Call SQRSL to extract the information about the Q matrix.
//  We do this, essentially, by asking SQRSL to tell us the
//  value of Q*Y, where Y is a column of the identity matrix.
//
  job = 10000;

  for ( i = 1; i <= N; i++ )
  {
//
//  Set the vector Y.
//
    for ( j = 1; j <= N; j++ )
    {
      y[j-1] = 0.0;
    }
    y[i-1] = 1.0;
//
//  Ask SQRSL to tell us what Q*Y is.
//
    info = sqrsl ( a, LDA, N, P, qraux, y, qy, qty, b, rsd, xb, job );

    if ( info != 0 )
    {
      cout << "  Error!  SQRSL returns INFO = " << info << "\n";
      return;
    }
//
//  Copy QY into the appropriate column of Q.
//
    for ( j = 1; j <= N; j++ )
    {
      q[j-1+(i-1)*N] = qy[j-1];
    }
  }
//
//  Now print out the Q matrix we have extracted.
//
  cout << "\n";
  cout << "  The Q factor:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << q[i-1+(j-1)*N];
    }
    cout << "\n";
  }
//
//  Compute Q*R to verify that it equals A.
//
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      b[i-1+(j-1)*LDA] = 0.0;
      for ( k = 1; k <= N; k++ )
      {
        b[i-1+(j-1)*LDA] = b[i-1+(j-1)*LDA]
          + q[i-1+(k-1)*N] * r[k-1+(j-1)*N];
      }
    }
  }
//
//  Print the result.
//
  cout << "\n";
  cout << "  The product Q * R:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= P; j++ )
    {
      cout << "  " << setw(12) << b[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  return;
# undef LDA
# undef N
# undef P
}
//****************************************************************************80

void sqrsl_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SQRSL_TEST tests SQRSL.
//
//  Discussion:
//
//    SQRSL can solve a linear system that was factored by SQRDC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 August 2016
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define P 3
# define LDA N

  float a[LDA*P] = {
    1.0,  1.0,  1.0,  1.0,  1.0,
    1.0,  2.0,  3.0,  4.0,  5.0,
    1.0,  4.0,  9.0, 16.0, 25.0 };
  float b[P];
  float b2[P] = {
    -3.02, 4.4914286, -0.72857143 };
  int i;
  int info;
  int ipvt[N];
  int j;
  int job;
  float qraux[P];
  float qty[N];
  float qy[N];
  float r[N];
  float work[P];
  float xb[N];
  float y[N] = {
    1.0,
    2.3,
    4.6,
    3.1,
    1.2 };

  cout << "\n";
  cout << "SQRSL_TEST\n";
  cout << "  SQRSL solves a rectangular linear system A*x=b in the\n";
  cout << "  least squares sense after A has been factored by SQRDC.\n";

  cout << "\n";
  cout << "  The matrix A:\n";
  cout << "\n";

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < P; j++ )
    {
      cout << "  " << setw(12) << a[i+j*LDA];
    }
    cout << "\n";
  }
//
//  Decompose the matrix.
//
  cout << "\n";
  cout << " Decompose the matrix.\n";

  job = 0;

  for ( j = 0; j < P; j++ )
  {
    ipvt[j] = 0;
  }

  sqrdc ( a, LDA, N, P, qraux, ipvt, work, job );
//
//  Call SQRSL to compute the least squares solution A*x=b.
//
  job = 110;

  info = sqrsl ( a, LDA, N, P, qraux, y, qy, qty, b, r, xb, job );

  if ( info != 0 )
  {
    cerr << "\n";
    cerr << "SQRSL_TEST - Warning!\n";
    cerr << "  SQRSL returns INFO = " << info << "\n";
    return;
  }

  cout << "\n";
  cout << "      X          X(expected):\n";
  cout << "\n";

  for ( i = 0; i < P; i++ )
  {
    cout << "  " << setw(14) << b[i]
         << "  " << setw(14) << b2[i] << "\n";
  }

  return;
# undef LDA
# undef N
# undef P
}
//****************************************************************************80

void test24 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST24 tests SSICO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 100
# define LDA N

  float a[LDA*N];
  int i;
  int ipvt[N];
  int j;
  float rcond;
  float z[N];

  cout << "\n";
  cout << "TEST24\n";
  cout << "  SSICO estimates the reciprocal condition number.\n";
  cout << "  for a symmetric indefinite matrix.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Assign values to the matrix A and the right hand side B.
//
  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      if ( i == j )
      {
        a[i-1+(j-1)*LDA] = 2.0;
      }
      else if ( j == i+1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }
  }
//
//  Estimate the condition.
//
  cout << "\n";
  cout << "  Estimate the condition.\n";

  rcond = ssico ( a, LDA, N, ipvt, z );

  cout << "\n";
  cout << "  Estimated reciprocal condition = " << rcond << "\n";

  return;
}
//****************************************************************************80

void test25 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST25 tests SSIFA and SSISL.
//
//  Discussion:
//
//    SSIFA and SSISL are for symmetric indefinite matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 100
# define LDA N

  float a[LDA*N];
  float b[N];
  int i;
  int info;
  int ipvt[N];
  int j;

  cout << "\n";
  cout << "TEST25\n";
  cout << "  For a symmetric indefinite matrix,\n";
  cout << "  SSIFA factor a symmetric indefinite matrix;\n";
  cout << "  SSISL solves a factored linear system,\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Assign values to the matrix A and the right hand side B.
//
  for ( i = 1; i < N; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = ( float ) ( N + 1 );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      if ( i == j )
      {
        a[i-1+(j-1)*LDA] = 2.0;
      }
      else if ( j == i+1 )
      {
        a[i-1+(j-1)*LDA] = -1.0;
      }
      else
      {
        a[i-1+(j-1)*LDA] = 0.0;
      }
    }
  }
//
//  Factor the matrix A.
//
  cout << "\n";
  cout << "  Factor the matrix.\n";

  info = ssifa ( a, LDA, N, ipvt );

  if ( info != 0 )
  {
    cout << "  Error!  SSIFA returns INFO = " << info << "\n";
    return;
  }
//
//  Solve the linear system.
//
  cout << "\n";
  cout << "  Solve the linear system.\n";

  ssisl ( a, LDA, N, ipvt, b );
//
//  Print the result.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,2,3,4,5,...,n-1,n))\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test26 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST26 tests SSPCO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 100

  float a[(N*(N+1))/2];
  int i;
  int ipvt[N];
  int j;
  int k;
  float rcond;
  float z[N];

  cout << "\n";
  cout << "TEST26\n";
  cout << "  For a symmetric indefinite packed matrix,\n";
  cout << "  SSPCO estimates the reciprocal condition number.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Assign values to the matrix A.
//
  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j )
      {
        a[k-1] = 2.0;
      }
      else if ( j == i+1 )
      {
        a[k-1] = -1.0;
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
//
//  Estimate the condition.
//
  cout << "\n";
  cout << "  Estimate the condition.\n";

  rcond = sspco ( a, N, ipvt, z );

  cout << "\n";
  cout << "  Estimated reciprocal condition = " << rcond << "\n";

  return;
# undef N
}
//****************************************************************************80

void test27 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST27 tests SSPFA and SSPSL.
//
//  Discussion:
//
//    SSPFA and SSPSL are for packed symmetric indefinite matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 100

  float a[(N*(N+1))/2];
  float b[N];
  int i;
  int info;
  int ipvt[N];
  int j;
  int k;

  cout << "\n";
  cout << "TEST27\n";
  cout << "  For a symmetric indefinite packed matrix,\n";
  cout << "  SSPFA computes the LU factors,\n";
  cout << "  SSPSL solves a factored linear system,\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Assign values to the matrix A and the right hand side B.
//
  for ( i = 1; i <= N-1; i++ )
  {
    b[i-1] = 0.0;
  }
  b[N-1] = ( float ) ( N + 1 );

  k = 0;
  for ( j = 1; j <= N; j++ )
  {
    for ( i = 1; i <= j; i++ )
    {
      k = k + 1;
      if ( i == j )
      {
        a[k-1] = 2.0;
      }
      else if ( j == i+1 )
      {
        a[k-1] = -1.0;
      }
      else
      {
        a[k-1] = 0.0;
      }
    }
  }
//
//  Factor the matrix.
//
  cout << "\n";
  cout << "  Factor the matrix.\n" << flush;

  info = sspfa ( a, N, ipvt );

  if ( info != 0 )
  {
    cout << "  Error!  SSPFA returns INFO = " << info << "\n";
    return;
  }
//
//  Solve the linear system.
//
  cout << "\n";
  cout << "  Solve the linear system.\n" << flush;

  sspsl ( a, N, ipvt, b );
//
//  Print the result.
//
  cout << "\n";
  cout << "  The first and last 5 entries of solution:\n";
  cout << "  (Should be (1,2,3,4,5,...,n-1,n))\n" << flush;
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    if ( i <= 5 || N-5 < i )
    {
      cout << "  " << setw(6) << i
           << "  " << setw(14) << b[i-1] << "\n";
    }
    if ( i == 5 )
    {
      cout << "  ......  ..............\n";
    }
  }


  return;
# undef N
}
//****************************************************************************80

void ssvdc_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SSVDC_TEST tests SSVDC.
//
//  Discussion:
//
//    SSVDC computes the singular value decomposition:
//
//      A = U * S * V'
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define M 6
# define N 4

  float a[M*N];
  float b[M*N];
//
//  S should be dimensioned at least max ( M+1, N ).
//
  float e[M+N];
  int i;
  int info;
  int j;
  int job;
  int k;
  int lda;
  int ldu;
  int ldv;
//
//  S should be dimensioned at least max ( M+1, N ).
//
  float s[M+N];
  int seed;
  float sigma[M*N];
  float u[M*M];
  float v[N*N];
  float work[M];

  cout << "\n";
  cout << "SSVDC_TEST\n";
  cout << "  For an MxN matrix A in general storage,\n";
  cout << "  SSVDC computes the singular value decomposition:\n";
  cout << "    A = U * S * V'\n";
  cout << "\n";
  cout << "  Matrix rows M =    " << M << "\n";
  cout << "  Matrix columns N = " << N << "\n";
//
//  Set A.
//
  seed = 123456789;

  r4mat_uniform_01 ( M, N, seed, a );

  cout << "\n";
  cout << "  The matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(10) << a[(i-1)+(j-1)*M];
    }
    cout << "\n";
  }
//
//  Decompose the matrix.
//
  cout << "\n";
  cout << "  Decompose the matrix.\n";

  job = 11;
  lda = M;
  ldu = M;
  ldv = N;

  info = ssvdc ( a, lda, M, N, s, e, u, ldu, v, ldv, work, job );

  if ( info != 0 )
  {
    cout << "\n";
    cout << "SSVDC_TEST - Warning:\n";
    cout << "  SSVDC returned nonzero INFO = " << info << "\n";
    return;
  }

  cout << "\n";
  cout << "  Singular values:\n";
  cout << "\n";

  for ( i = 1; i <= i4_min ( M, N ); i++ )
  {
    cout << "  "
         << setw(4)  << i+1  << "  "
         << setw(14) << s[i-1] << "\n";
  }

  cout << "\n";
  cout << "  Left Singular Vector Matrix U:\n";
  cout << "\n";

  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= M; j++ )
    {
      cout << "  " << setw(10) << u[(i-1)+(j-1)*M];
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "  Right Singular Vector Matrix V:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(10) << v[(i-1)+(j-1)*N];
    }
    cout << "\n";
  }

  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      if ( i == j )
      {
        sigma[(i-1)+(j-1)*M] = s[i-1];
      }
      else
      {
        sigma[(i-1)+(j-1)*M] = 0.0;
      }
    }
  }
//
//  Verify that A = U * S * V'.
//
  for ( i = 1; i <= M; i++ )
  {
    for ( k = 1; k <= N; k++ )
    {
      b[(i-1)+(k-1)*M] = 0.0;
      for ( j = 1; j <= N; j++ )
      {
      b[(i-1)+(k-1)*M] = b[(i-1)+(k-1)*M] + sigma[i-1+(j-1)*M] * v[k-1+(j-1)*N];
      }
    }
  }

  for ( i = 1; i <= M; i++ )
  {
    for ( k = 1; k <= N; k++ )
    {
      a[(i-1)+(k-1)*M] = 0.0;
      for ( j = 1; j <= M; j++ )
      {
      a[(i-1)+(k-1)*M] = a[(i-1)+(k-1)*M] + u[i-1+(j-1)*M] * b[j-1+(k-1)*M];
      }
    }
  }

  cout << "\n";
  cout << "  The product U * S * V' (should equal A):\n";
  cout << "\n";

  for ( i = 1; i <= M; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(10) << a[(i-1)+(j-1)*M];
    }
    cout << "\n";
  }

  return;
# undef M
# undef N
}
//****************************************************************************80

void test29 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST29 tests STRCO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define LDA N

  float a[LDA*N];
  int i;
  int j;
  int job;
  float rcond;
  int  seed = 123456789;
  float z[N];

  cout << "\n";
  cout << "TEST29\n";
  cout << "  For a triangular matrix,\n";
  cout << "  STRCO computes the LU factors and\n";
  cout << "  computes its reciprocal condition number.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Lower triangular matrix A.
//
  r4mat_uniform_01 ( LDA, N, seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = i+1; j <= N; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  cout << "\n";
  cout << "  Lower triangular matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  job = 0;
  rcond = strco ( a, LDA, N, z, job );

  cout << "\n";
  cout << "  The reciprocal condition number = " << rcond << "\n";
//
//  Upper triangular matrix A.
//
  r4mat_uniform_01 ( LDA, N, seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  cout << "\n";
  cout << "  Upper triangular matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  job = 1;

  rcond = strco ( a, LDA, N, z, job );

  cout << "\n";
  cout << "  The reciprocal condition number = " << rcond << "\n";

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test30 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST30 tests STRDI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define LDA N

  float a[LDA*N];
  float det[2];
  int i;
  int j;
  int job;
  int seed = 123456789;

  cout << "\n";
  cout << "TEST30\n";
  cout << "  For a triangular matrix,\n";
  cout << "  STRDI computes the determinant or inverse.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Lower triangular matrix A.
//
  r4mat_uniform_01 ( N, N, seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = i+1; j <= N; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  cout << "\n";
  cout << "  Lower triangular matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  job = 110;

  strdi ( a, LDA, N, det, job );

  cout << "\n";
  cout << "  The determinant = " << det[0] << " * 10^(" << det[1] << ").\n";

  cout << "\n";
  cout << "  The inverse matrix:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }
//
//  Upper triangular matrix A.
//
  r4mat_uniform_01 ( N, N, seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  cout << "\n";
  cout << "  Upper triangular matrix A:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  job = 111;

  strdi ( a, LDA, N, det, job );

  cout << "\n";
  cout << "  The determinant = " << det[0] << " * 10^(" << det[1] << ").\n";

  cout << "\n";
  cout << "  The inverse matrix:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= N; j++ )
    {
      cout << "  " << setw(12) << a[i-1+(j-1)*LDA];
    }
    cout << "\n";
  }

  return;
# undef LDA
# undef N
}
//****************************************************************************80

void test31 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST31 tests STRSL.
//
//  Discussion:
//
//    STRSL solves triangular linear systems.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define LDA 5

  float a[LDA*N];
  float b[N];
  int i;
  int j;
  int job;
  int seed = 123456789;
  float x[N];

  cout << "\n";
  cout << "TEST31\n";
  cout << "  For a triangular matrix,\n";
  cout << "  STRSL solves a linear system.\n";
  cout << "  The matrix size is N = " << N << "\n";
//
//  Lower triangular matrix A.
//
  r4mat_uniform_01 ( N, N, seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = i+1; j <= N; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++)
  {
    x[i-1] = ( float ) ( i );
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[i-1+(j-1)*LDA] * x[j-1];
    }
  }

  cout << "\n";
  cout << "  For a lower triangular matrix A,\n";
  cout << "  solve A * x = b\n";

  job = 00;

  strsl ( a, LDA, N, b, job );

  cout << "\n";
  cout << "  The solution (should be 1,2,3,4,5):\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout                       << "  "
         << setw(6)  << i      << "  "
         << setw(14) << b[i-1] << "\n";
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[j-1+(i-1)*LDA] * x[j-1];
    }
  }

  cout << "\n";
  cout << "  For a lower triangular matrix A,\n";
  cout << "  solve A' * x = b\n";

  job = 10;

  strsl ( a, LDA, N, b, job );

  cout << "\n";
  cout << "  The solution (should be 1,2,3,4,5):\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout                       << "  "
         << setw(6)  << i      << "  "
         << setw(14) << b[i-1] << "\n";
  }
//
//  Upper triangular matrix A.
//
  r4mat_uniform_01 ( N, N, seed, a );

  for ( i = 1; i <= N; i++ )
  {
    for ( j = 1; j <= i-1; j++ )
    {
      a[i-1+(j-1)*LDA] = 0.0;
    }
  }

  for ( i = 1; i <= N; i++)
  {
    x[i-1] = ( float ) ( i );
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[i-1+(j-1)*LDA] * x[j-1];
    }
  }

  cout << "\n";
  cout << "  For an upper triangular matrix A,\n";
  cout << "  solve A * x = b\n";

  job = 01;

  strsl ( a, LDA, N, b, job );

  cout << "\n";
  cout << "  The solution (should be 1,2,3,4,5):\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout                       << "  "
         << setw(6)  << i      << "  "
         << setw(14) << b[i-1] << "\n";
  }

  for ( i = 1; i <= N; i++ )
  {
    b[i-1] = 0.0;
    for ( j = 1; j <= N; j++ )
    {
      b[i-1] = b[i-1] + a[j-1+(i-1)*LDA] * x[j-1];
    }
  }
  cout << "\n";
  cout << "  For an upper triangular matrix A,\n";
  cout << "  solve A' * x = b\n";

  job = 11;

  strsl ( a, LDA, N, b, job );

  cout << "\n";
  cout << "  The solution (should be 1,2,3,4,5):\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout                       << "  "
         << setw(6)  << i      << "  "
         << setw(14) << b[i-1] << "\n";
  }

  return;
# undef LDA
# undef N
}

