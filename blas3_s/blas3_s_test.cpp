# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "blas0.hpp"
# include "blas3_s.hpp"

int main ( );
void sgemm_test ( );
void strmm_test ( );
void strsm_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for BLAS3_S_TEST.
//
//  Discussion:
//
//    BLAS3_S_TEST tests the BLAS3_S library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 March 2017
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "BLAS3_S_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the BLAS3_S library.\n";

  sgemm_test ( );
  strmm_test ( );
  strsm_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "BLAS3_S_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void sgemm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SGEMM_TEST tests SGEMM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 February 2014
//
//  Author:
//
//    John Burkardt
//
{
  float *a;
  float alpha;
  float *b;
  float beta;
  float *c;
  int k;
  int lda;
  int ldb;
  int ldc;
  int m;
  int n;
  char transa;
  char transb;
  char transc;

  cout << "\n";
  cout << "SGEMM_TEST\n";
  cout << "  SGEMM carries out matrix multiplications\n";
  cout << "  for single precision real matrices.\n";
  cout << "\n";
  cout << "  1: C = alpha * A  * B  + beta * C;\n";
  cout << "  2: C = alpha * A' * B  + beta * C;\n";
  cout << "  3: C = alpha * A  * B' + beta * C;\n";
  cout << "  4: C = alpha * A' * B' + beta * C;\n";
  cout << "\n";
  cout << "  We carry out all four calculations, but in each case,\n";
  cout << "  we choose our input matrices so that we get the same result.\n";
//
//  C = alpha * A * B + beta * C.
//
  transa = 'N';
  transb = 'N';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = m;
  a = r4mat_test ( transa, lda, m, k );
  ldb = k;
  b = r4mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r4mat_test ( transc, ldc, m, n );

  sgemm ( transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r4mat_print ( m, n, c, "  C = alpha * A * B + beta * C:" );

  delete [] a;
  delete [] b;
  delete [] c;
//
//  C = alpha * A' * B + beta * C.
//
  transa = 'T';
  transb = 'N';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = k;
  a = r4mat_test ( transa, lda, m, k );
  ldb = k;
  b = r4mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r4mat_test ( transc, ldc, m, n );

  sgemm ( transa, transb,  m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r4mat_print ( m, n, c, "  C = alpha * A' * B + beta * C:" );

  delete [] a;
  delete [] b;
  delete [] c;
//
//  C = alpha * A * B' + beta * C.
//
  transa = 'N';
  transb = 'T';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = m;
  a = r4mat_test ( transa, lda, m, k );
  ldb = n;
  b = r4mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r4mat_test ( transc, ldc, m, n );

  sgemm ( transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r4mat_print ( m, n, c, "  C = alpha * A * B' + beta * C:" );

  delete [] a;
  delete [] b;
  delete [] c;
//
//  C = alpha * A' * B' + beta * C.
//
  transa = 'T';
  transb = 'T';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = k;
  a = r4mat_test ( transa, lda, m, k );
  ldb = n;
  b = r4mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r4mat_test ( transc, ldc, m, n );

  sgemm ( transa, transb,  m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r4mat_print ( m, n, c, "  C = alpha * A' * B' + beta * C:" );

  delete [] a;
  delete [] b;
  delete [] c;

  return;
}
//****************************************************************************80

void strmm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    STRMM_TEST tests STRMM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2014
//
//  Author:
//
//    John Burkardt
//
{
  float *a;
  float alpha;
  float *b;
  char diag;
  int i;
  int j;
  int lda;
  int ldb;
  int m;
  int n;
  char side;
  char transa;
  char transb;
  char uplo;

  cout << "\n";
  cout << "STRMM_TEST\n";
  cout << "  STRMM multiplies a triangular matrix A and a\n";
  cout << "  rectangular matrix B\n";
  cout << "\n";
  cout << "  1: B = alpha * A  * B;\n";
  cout << "  2: B = alpha * A' * B;\n";
//
//  B = alpha * A * B.
//
  side = 'L';
  uplo = 'U';
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = new float[lda*m];
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strmm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  B = alpha * A * B:" );

  delete [] a;
  delete [] b;
//
//  B = alpha * A' * B.
//
  side = 'L';
  uplo = 'U';
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = new float[lda*m];
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strmm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  B = alpha * A' * B:" );

  delete [] a;
  delete [] b;

  return;
}
//****************************************************************************80

void strsm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    STRSM_TEST tests STRSM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 April 2014
//
//  Author:
//
//    John Burkardt
//
{
  float *a;
  float alpha;
  float *b;
  char diag;
  int i;
  int j;
  int lda;
  int ldb;
  int m;
  int n;
  char side;
  char transa;
  char transb;
  char uplo;

  cout << "\n";
  cout << "STRSM_TEST\n";
  cout << "  STRSM solves a linear system involving a triangular\n";
  cout << "  matrix A and a rectangular matrix B.\n";
  cout << "\n";
  cout << "  1: Solve A  * X  = alpha * B;\n";
  cout << "  2: Solve A' * X  = alpha * B;\n";
  cout << "  3: Solve X  * A  = alpha * B;\n";
  cout << "  4: Solve X  * A' = alpha * B;\n";
//
//  Solve A * X = alpha * B.
//
  side = 'L';
  uplo = 'U';
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = new float[lda*m];

  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strsm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  X = inv ( A ) * alpha * B:" );

  delete [] a;
  delete [] b;
//
//  Solve A' * X = alpha * B.
//
  side = 'L';
  uplo = 'U';
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = new float[lda*m];
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strsm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  X = inv ( A' ) * alpha * B:" );

  delete [] a;
  delete [] b;
//
//  Solve X * A = alpha * B.
//
  side = 'R';
  uplo = 'U';
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = n;
  ldb = m;

  a = new float[lda*n];
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < n; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strsm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  X = alpha * B * inv ( A ):" );

  delete [] a;
  delete [] b;
//
//  Solve X * A'' = alpha * B.
//
  side = 'R';
  uplo = 'U';
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = n;
  ldb = m;

  a = new float[lda*n];
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( float ) ( i + j + 2 );
    }
    for ( i = j + 1; i < n; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r4mat_test ( transb, ldb, m, n );

  strsm ( side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb );

  r4mat_print ( m, n, b, "  X = alpha * B * inv ( A' ):" );

  delete [] a;
  delete [] b;

  return;
}

