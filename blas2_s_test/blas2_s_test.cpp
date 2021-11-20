# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "blas0.hpp"
# include "blas2_s.hpp"

int main ( );
void sgemv_test ( );
void sger_test ( );
void strmv_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for BLAS2_S_TEST.
//
//  Discussion:
//
//    BLAS2_S_TEST tests the BLAS2_S library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 March 2017
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "BLAS2_S_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the BLAS2_S library.\n";

  sgemv_test ( );
  sger_test ( );
  strmv_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "BLAS2_S_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void sgemv_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SGEMV_TEST tests SGEMV.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 March 2017
//
//  Author:
//
//    John Burkardt
//
{
  float *a;
  float alpha;
  float beta;
  int i;
  int incx;
  int incy;
  int lda;
  int m;
  int n;
  char trans;
  float *x;
  float *y;

  cout << "\n";
  cout << "SGEMV_TEST\n";
  cout << "  SGEMV computes y := alpha * A * x + beta * y\n";
  cout << "  or             y := alpha * A'' * x + beta * y,\n";
  cout << "  for a general matrix A,\n";
//
//  y = alpha * A * x + beta * y
//
  trans = 'N';
  m = 5;
  n = 4;
  alpha = 2.0;
  lda = m;
  a = r4mat_test ( trans, lda, m, n );
  x = new float[n];
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( float ) ( i + 1 );
  }
  incx = 1;
  beta = 3.0;
  y = new float[m];
  for ( i = 0; i < m; i++ )
  {
    y[i] = ( float ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r4mat_print ( m, n, a, "  Matrix A:" );
  r4vec_print ( n, x, "  Vector X:" );
  r4vec_print ( m, y, "  Vector Y:" );

  sgemv ( trans, m, n, alpha, a, lda, x, incx, beta, y, incy );

  r4vec_print ( m, y, "  Result Y = alpha * A  * x + beta * y" );
//
//  Free memory.
//
  delete [] a;
  delete [] x;
  delete [] y;
//
//  y = alpha * A' * x + beta * y
//
  trans = 'T';
  m = 5;
  n = 4;
  alpha = 2.0;
  lda = m;
  a = r4mat_test ( trans, lda, n, m );
  x = new float[m];
  for ( i = 0; i < m; i++ )
  {
    x[i] = ( float ) ( i + 1 );
  }
  incx = 1;
  beta = 3.0;
  y = new float[n];
  for ( i = 0; i < n; i++ )
  {
    y[i] = ( float ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r4mat_print ( m, n, a, "  Matrix A:" );
  r4vec_print ( m, x, "  Vector X:" );
  r4vec_print ( n, y, "  Vector Y:" );

  sgemv ( trans, m, n, alpha, a, lda, x, incx, beta, y, incy );

  r4vec_print ( n, y, "  Result Y = alpha * A  * x + beta * y" );
//
//  Free memory.
//
  delete [] a;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void sger_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SGER_TEST tests SGER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 March 2017
//
//  Author:
//
//    John Burkardt
//
{
  float *a;
  float alpha;
  int i;
  int incx;
  int incy;
  int lda;
  int m;
  int n;
  char trans;
  float *x;
  float *y;

  cout << "\n";
  cout << "SGER_TEST\n";
  cout << "  SGER computes A := A + alpha * x * y'\n";
  cout << "  for a general matrix A.\n";

  m = 5;
  n = 4;
  alpha = 2.0;
  trans = 'N';
  lda = m;
  a = r4mat_test ( trans, lda, m, n );

  x = new float[m];
  for ( i = 0; i < m; i++ )
  {
    x[i] = ( float ) ( i + 1 );
  }
  incx = 1;

  y = new float[n];
  for ( i = 0; i < n; i++ )
  {
    y[i] = ( float ) ( 10 * ( i + 1 ) );
  }
  incy = 1;

  r4mat_print ( m, n, a, "  Matrix A:" );
  r4vec_print ( m, x, "  Vector X:" );
  r4vec_print ( n, y, "  Vector Y:" );

  sger ( m, n, alpha, x, incx, y, incy, a, lda );

  r4mat_print ( m, n, a, "  Result A = A + alpha * x * y" );
//
//  Free memory.
//
  delete [] a;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void strmv_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    STRMV_TEST tests STRMV.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 March 2017
//
//  Author:
//
//    John Burkardt
//
{
  float *a;
  char diag;
  int i;
  int incx;
  int j;
  int lda = 5;
  int m = 5;
  int n = 5;
  int test;
  char trans;
  char uplo;
  float *x;

  a = new float[lda*n];
  x = new float[n];

  cout << "\n";
  cout << "STRMV_TEST\n";
  cout << "  STRMV computes y := A * x or y := A' * x\n";
  cout << "  For a triangular matrix A.\n";

  for ( test = 1; test <= 2; test++ )
  {
    uplo = 'U';

    if ( test == 1 )
    {
      trans = 'N';
    }
    else
    {
      trans = 'T';
    }

    diag = 'N';

    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i <= j; i++ )
      {
        a[i+j*m] = ( float ) ( i + j + 2 );
      }
      for ( i = j + 1; i < m; i++ )
      {
        a[i+j*m] = 0.0;
      }
    }

    incx = 1;
    for ( i = 0; i < n; i++ )
    {
      x[i] = ( float ) ( i + 1 );
    }

    strmv ( uplo, trans, diag, n, a, lda, x, incx );

    if ( trans == 'N' )
    {
      r4vec_print ( n, x, "  Result y = A * x" );
    }
    else
    {
      r4vec_print ( n, x, "  Result y = A' * x" );
    }
  }
//
//  Free memory.
//
  delete [] a;
  delete [] x;

  return;
}
