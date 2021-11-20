# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "toeplitz_cholesky.hpp"

int main ( );
void t_cholesky_lower_test ( );
void toep_cholesky_lower_test ( );
void toeplitz_cholesky_lower_test ( );
void t_cholesky_upper_test ( );
void toep_cholesky_upper_test ( );
void toeplitz_cholesky_upper_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN tests TOEPLITZ_CHOLESKY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 January 2017
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "TOEPLITZ_CHOLESKY_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the TOEPLITZ_CHOLESKY library.\n";

  t_cholesky_lower_test ( );
  toep_cholesky_lower_test ( );
  toeplitz_cholesky_lower_test ( );
  t_cholesky_upper_test ( );
  toep_cholesky_upper_test ( );
  toeplitz_cholesky_upper_test ( );
/*
  Terminate.
*/
  cout << "\n";
  cout << "TOEPLITZ_CHOLESKY_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void t_cholesky_lower_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    T_CHOLESKY_LOWER_TEST tests T_CHOLESKY_LOWER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 January 2017
//
//  Author:
//
//    John Burkardt
//
{

  double *b;
  double *l;
  int n = 3;
  double t[3*3] = {  
    1.0,    0.5, -0.375 };

  cout << "\n";
  cout << "T_CHOLESKY_LOWER_TEST\n";
  cout << "  T_CHOLESKY_LOWER computes the lower Cholesky factor L\n";
  cout << "  of a positive definites symmetric Toeplitz matrix\n";
  cout << "  defined by the first row.\n";

  r8vec_print ( n, t, "  First row of Toeplitz matrix T:" );

  l = t_cholesky_lower ( n, t );
  r8mat_print ( n, n, l, "  Computed lower Cholesky factor L:" );

  b = r8mat_mmt_new ( n, n, n, l, l );
  r8mat_print ( n, n, b, "  Product LL':" );

  delete [] b;
  delete [] l;

  return;
}
//****************************************************************************80

void toep_cholesky_lower_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    TOEP_CHOLESKY_LOWER_TEST tests TOEP_CHOLESKY_LOWER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 January 2017
//
//  Author:
//
//    John Burkardt
//
{
  double *b;
  double g[2*3] = {
    1.0,    0.0,
    0.5,    0.5,
   -0.375, -0.375 };
  double *l;
  int n = 3;

  cout << "\n";
  cout << "TOEP_CHOLESKY_LOWER_TEST\n";
  cout << "  TOEP_CHOLESKY_LOWER computes the lower Cholesky factor L\n";
  cout << "  of a positive definites symmetric Toeplitz matrix\n";
  cout << "  defined by a (2,N) array.\n";

  r8mat_print ( 2, n, g, "  Compressed Toeplitz matrix G:" );

  l = toep_cholesky_lower ( n, g );
  r8mat_print ( n, n, l, "  Computed lower Cholesky factor L:" );

  b = r8mat_mmt_new ( n, n, n, l, l );
  r8mat_print ( n, n, b, "  Product LL':" );

  delete [] b;
  delete [] l;

  return;
}
//****************************************************************************80

void toeplitz_cholesky_lower_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    TOEPLITZ_CHOLESKY_LOWER_TEST tests TOEPLITZ_CHOLESKY_LOWER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 January 2017
//
//  Author:
//
//    John Burkardt
//
{
  double a[3*3] = {  
    1.0,    0.5, -0.375,
    0.5,    1.0,  0.5,
   -0.375,  0.5,  1.0 };
  double *b;
  double *l;
  int n = 3;

  cout << "\n";
  cout << "TOEPLITZ_CHOLESKY_LOWER_TEST\n";
  cout << "  TOEPLITZ_CHOLESKY_LOWER computes the lower Cholesky factor L\n";
  cout << "  of a positive definites symmetric Toeplitz matrix\n";
  cout << "  defined as an NxN array.\n";

  r8mat_print ( n, n, a, "  Toeplitz matrix A:" );

  l = toeplitz_cholesky_lower ( n, a );
  r8mat_print ( n, n, l, "  Computed lower Cholesky factor L:" );

  b = r8mat_mmt_new ( n, n, n, l, l );
  r8mat_print ( n, n, b, "  Product LL':" );

  delete [] b;
  delete [] l;

  return;
}
//****************************************************************************80

void t_cholesky_upper_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    T_CHOLESKY_UPPER_TEST tests T_CHOLESKY_UPPER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 January 2017
//
//  Author:
//
//    John Burkardt
//
{
  double *b;
  int n = 3;
  double *r;
  double t[3] = {  
    1.0,    0.5, -0.375 };

  cout << "\n";
  cout << "T_CHOLESKY_UPPER_TEST\n";
  cout << "  T_CHOLESKY_UPPER computes the upper Cholesky factor R\n";
  cout << "  of a positive definites symmetric Toeplitz matrix\n";
  cout << "  defined by the first row.\n";
  
  r8vec_print ( n, t, "  First row of Toeplitz matrix T:" );

  r = t_cholesky_upper ( n, t );
  r8mat_print ( n, n, r, "  Computed upper Cholesky factor R:" );

  b = r8mat_mtm_new ( n, n, n, r, r );
  r8mat_print ( n, n, b, "  Product R'R:" );

  delete [] b;
  delete [] r;

  return;
}
//****************************************************************************80

void toep_cholesky_upper_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    TOEP_CHOLESKY_UPPER_TEST tests TOEP_CHOLESKY_UPPER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 January 2017
//
//  Author:
//
//    John Burkardt
//
{
  double *b;
  double g[2*3] = {
    1.0,    0.0,
    0.5,    0.5,
   -0.375, -0.375 };
  int n = 3;
  double *r;

  cout << "\n";
  cout << "TOEP_CHOLESKY_UPPER_TEST\n";
  cout << "  TOEP_CHOLESKY_UPPER computes the upper Cholesky factor L\n";
  cout << "  of a positive definites symmetric Toeplitz matrix\n";
  cout << "  defined by a (2,N) array.\n";

  r8mat_print ( 2, n, g, "  Compressed Toeplitz matrix G:" );

  r = toep_cholesky_upper ( n, g );
  r8mat_print ( n, n, r, "  Computed upper Cholesky factor R:" );

  b = r8mat_mtm_new ( n, n, n, r, r );
  r8mat_print ( n, n, b, "  Product R'R:" );

  delete [] b;
  delete [] r;

  return;
}
//****************************************************************************80

void toeplitz_cholesky_upper_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    TOEPLITZ_CHOLESKY_UPPER_TEST tests TOEPLITZ_CHOLESKY_UPPER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 January 2017
//
//  Author:
//
//    John Burkardt
//
{
  double a[3*3] = {  
    1.0,    0.5, -0.375,
    0.5,    1.0,  0.5,
   -0.375,  0.5,  1.0 };
  double *b;
  int n = 3;
  double *r;

  cout << "\n";
  cout << "TOEPLITZ_CHOLESKY_UPPER_TEST\n";
  cout << "  TOEPLITZ_CHOLESKY_UPPER computes the upper Cholesky factor L\n";
  cout << "  of a positive definites symmetric Toeplitz matrix\n";
  cout << "  defined as an NxN array.\n";

  r8mat_print ( n, n, a, "  Toeplitz matrix A:" );

  r = toeplitz_cholesky_upper ( n, a );
  r8mat_print ( n, n, r, "  Computed upper Cholesky factor R:" );

  b = r8mat_mtm_new ( n, n, n, r, r );
  r8mat_print ( n, n, b, "  Product R'R:" );

  delete [] b;
  delete [] r;

  return;
}

