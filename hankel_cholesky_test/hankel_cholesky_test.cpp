# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "hankel_cholesky.hpp"

int main ( );
void hankel_cholesky_upper_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL_CHOLESKY_TEST tests HANKEL_CHOLESKY.
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
{
  timestamp ( );
  cout << "\n";
  cout << "HANKEL_CHOLESKY_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the HANKEL_CHOLESKY library.\n";

  hankel_cholesky_upper_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "HANKEL_CHOLESKY_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void hankel_cholesky_upper_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    HANKEL_CHOLESKY_UPPER_TEST tests HANKEL_CHOLESKY_UPPER.
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
{
  int flag;
  double *h;
  double *hanti;
  int i;
  int j;
  double *l;
  double *lii;
  double *liim1;
  int n;
  double *r1;
  double *r2;
  int seed;

  n = 5;

  cout << "\n";
  cout << "HANKEL_CHOLESKY_UPPER_TEST\n";
  cout << "  HANKEL_CHOLESKY_UPPER is given a Hankel matrix H and\n";
  cout << "  computes an upper triangular matrix R such that\n";
  cout << "  H = R' * R\n";
//
//  Get a Hankel matrix that is symmetric positive definite.
//
  seed = 123456789;
  lii = r8vec_uniform_01_new ( n, seed );
  liim1 = r8vec_uniform_01_new ( n - 1, seed );
  l = hankel_spd_cholesky_lower ( n, lii, liim1 );
  h = r8mat_mmt_new ( n, n, n, l, l );
  r8mat_print ( n, n, h, "  The Hankel matrix H:" );
//
//  Compute R using R8MAT_CHOLESKY_FACTOR_UPPER.
//
  r1 = r8mat_cholesky_factor_upper ( n, h, flag );
  if ( flag != 0 )
  {
    cout << "\n";
    cout << " R8MAT_CHOLESKY_FACTOR_UPPER says H is not positive definite.\n";
  }
  else
  {
    r8mat_print ( n, n, r1, "  R computed by R8MAT_CHOLESKY_FACTOR_UPPER:" );
  }
//
//  Compute R using HANKEL_CHOLESKY.
//
  hanti = new double[2*n-1];
  for ( i = 0; i < n; i++ )
  {
    hanti[i] = h[i+0*n];
  }
  for ( j = 1; j < n; j++ )
  {
    hanti[n-1+j] = h[n-1+j*n];
  }
  r2 = hankel_cholesky_upper ( n, hanti );
  r8mat_print ( n, n, r2, "  R computed by HANKEL_CHOLESKY:" );

  delete [] hanti;
  delete [] l;
  delete [] lii;
  delete [] liim1;
  delete [] r1;
  delete [] r2;

  return;
}
