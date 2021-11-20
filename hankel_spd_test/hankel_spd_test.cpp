# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "hankel_spd.hpp"

int main ( );
void hankel_spd_cholesky_lower_test01 ( );
void hankel_spd_cholesky_lower_test02 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    hankel_spd_test tests hankel_spd.
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
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "hankel_spd_test\n";
  cout << "  C++ version\n";
  cout << "  Test the hankel_spd library.\n";

  hankel_spd_cholesky_lower_test01 ( );
  hankel_spd_cholesky_lower_test02 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "hankel_spd_test\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void hankel_spd_cholesky_lower_test01 ( )

//****************************************************************************80
//
//  Purpose:
//
//    hankel_spd_cholesky_lower_test01 tests hankel_spd_cholesky_lower.
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
//    John Burkardt
//
{
  double *h;
  int i;
  double *l;
  double *lii;
  double *liim1;
  int n;
  int seed;

  cout << "\n";
  cout << "hankel_spd_cholesky_lower_test01\n";
  cout << "  hankel_spd_cholesky_lower computes a lower Cholesky\n";
  cout << "  matrix L such that the matrix H = L * L' is a\n";
  cout << "  symmetric positive definite (SPD) Hankel matrix.\n";

  n = 5;
//
//  Example 1:
//
  lii = new double[n];
  for ( i = 0; i < n; i++ )
  {
    lii[i] = 1.0;
  }

  liim1 = new double[n-1];
  for ( i = 0; i < n - 1; i++ )
  {
    liim1[i] = 1.0;
  }

  l = hankel_spd_cholesky_lower ( n, lii, liim1 );

  r8mat_print ( n, n, l, "  The Cholesky factor L:" );

  h = r8mat_mmt_new ( n, n, n, l, l );

  r8mat_print ( n, n, h, "  The Hankel matrix H = L * L':" );

  delete [] h;
  delete [] l;
  delete [] lii;
  delete [] liim1;
//
//  Example 2:
//
  lii = new double[n];
  for ( i = 0; i < n; i++ )
  {
    lii[i] = ( double ) ( i + 1 );
  }

  liim1 = new double[n-1];
  for ( i = 0; i < n - 1; i++ )
  {
    liim1[i] = ( double ) ( n - 1 - i );
  }

  l = hankel_spd_cholesky_lower ( n, lii, liim1 );

  r8mat_print ( n, n, l, "  The Cholesky factor L:" );

  h = r8mat_mmt_new ( n, n, n, l, l );

  r8mat_print ( n, n, h, "  The Hankel matrix H = L * L':" );

  delete [] h;
  delete [] l;
  delete [] lii;
  delete [] liim1;
//
//  Example 3:
//
  seed = 123456789;
  lii = r8vec_uniform_01_new ( n, seed );
  liim1 = r8vec_uniform_01_new ( n - 1, seed );

  l = hankel_spd_cholesky_lower ( n, lii, liim1 );

  r8mat_print ( n, n, l, "  The Cholesky factor L:" );

  h = r8mat_mmt_new ( n, n, n, l, l );

  r8mat_print ( n, n, h, "  The Hankel matrix H = L * L':" );

  delete [] h;
  delete [] l;
  delete [] lii;
  delete [] liim1;

  return;
}
//****************************************************************************80

void hankel_spd_cholesky_lower_test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    hankel_spd_cholesky_lower_test02 tests hankel_spd_cholesky_lower.
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
//    John Burkardt
//
{
  int flag;
  double *h;
  double *h2;
  int i;
  double *l;
  double *l2;
  double *lii;
  double *liim1;
  int n;

  cout << "\n";
  cout << "hankel_spd_cholesky_lower_test02\n";
  cout << "  hankel_spd_cholesky_lower computes a lower Cholesky\n";
  cout << "  matrix L such that the matrix H = L * L' is a\n";
  cout << "  symmetric positive definite (SPD) Hankel matrix.\n";

  n = 5;

  lii = new double[n];
  for ( i = 0; i < n; i++ )
  {
    lii[i] = 1.0;
  }

  liim1 = new double[n-1];
  for ( i = 0; i < n - 1; i++ )
  {
    liim1[i] = 1.0;
  }

  l = hankel_spd_cholesky_lower ( n, lii, liim1 );

  r8mat_print ( n, n, l, "  The Cholesky factor L:" );

  h = r8mat_mmt_new ( n, n, n, l, l );

  r8mat_print ( n, n, h, "  The Hankel matrix H = L * L':" );

  l2 = r8mat_cholesky_factor ( n, h, flag );

  r8mat_print ( n, n, l2, "  The Cholesky factor L2 of H:" );

  h2 = r8mat_mmt_new ( n, n, n, l2, l2 );

  r8mat_print ( n, n, h2, "  The Hankel matrix H2 = L2 * L2':" );

  delete [] h;
  delete [] h2;
  delete [] l;
  delete [] l2;
  delete [] lii;
  delete [] liim1;

  return;
}
