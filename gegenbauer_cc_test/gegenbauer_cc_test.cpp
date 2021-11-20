# include <cmath>
# include <iomanip>
# include <iostream>

using namespace std;

# include "gegenbauer_cc.hpp"

int main ( );
double f ( double x );
void chebyshev_even1_test ( );
void chebyshev_even2_test ( );
void gegenbauer_cc1_test ( );
void gegenbauer_cc2_test ( );
void i4_uniform_ab_test ( );
void r8_mop_test ( );
void r8vec_print_test ( );
void r8vec2_print_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for GEGENBAUER_CC_TEST.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "GEGENBAUER_CC_TEST:\n";
  cout << "  C++ version.\n";
  cout << "  Test the GEGENBAUER_CC library.\n";

  chebyshev_even1_test ( );
  chebyshev_even2_test ( );
  gegenbauer_cc1_test ( );
  gegenbauer_cc2_test ( );
  i4_uniform_ab_test ( );
  r8_mop_test ( );
  r8vec_print_test ( );
  r8vec2_print_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "GEGENBAUER_CC_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

double f ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F is the function to be integrated.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 January 2016
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the argument.
//
//    Output, double F, the value.
//
{
  double a;
  double value;

  a = 2.0;
  value = cos ( a * x );

  return value;
}
//****************************************************************************80

void chebyshev_even1_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBYSHEV_EVEN1_TEST tests CHEBYSHEV_EVEN1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  double *a2;
  double a2_exact[4] = {
    0.4477815660, 
   -0.7056685603, 
    0.0680357987, 
   -0.0048097159 };
  int s;
  int n;

  cout << "\n";
  cout << "CHEBYSHEV_EVEN1_TEST:\n";
  cout << "  CHEBYSHEV_EVEN1 computes the even Chebyshev coefficients\n";
  cout << "  of a function F, using the extreme points of Tn(x).\n";

  n = 6;

  a2 = chebyshev_even1 ( n, f );

  s = ( n / 2 );
  r8vec2_print ( s + 1, a2, a2_exact, "  Computed and Exact Coefficients:" );

  delete [] a2;

  return;
}
//****************************************************************************80

void chebyshev_even2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBYSHEV_EVEN2_TEST tests CHEBYSHEV_EVEN2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  double *b2;
  int n;
  int s;

  cout << "\n";
  cout << "CHEBYSHEV_EVEN2_TEST:\n";
  cout << "  CHEBYSHEV_EVEN2 computes the even Chebyshev coefficients\n";
  cout << "  of a function F, using the zeros of Tn(x).\n";

  n = 6;

  b2 = chebyshev_even2 ( n, f );

  s = ( n / 2 );
  r8vec_print ( s + 1, b2,"  Computed Coefficients:" );

  delete [] b2;

  return;
}
//****************************************************************************80

void gegenbauer_cc1_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    GEGENBAUER_CC1_TEST tests GEGENBAUER_CC1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double exact;
  double lambda;
  int n;
  const double r8_pi = 3.141592653589793;
  double value;

  cout << "\n";
  cout << "GEGENBAUER_CC1_TEST:\n";
  cout << "  GEGENBAUER_CC1 estimates the Gegenbauer integral of\n";
  cout << "  a function f(x) using a Clenshaw-Curtis type approach\n";
  cout << "  based on the extreme points of Tn(x).\n";

  lambda = 0.75;
  a = 2.0;
  n = 6;

  value = gegenbauer_cc1 ( n, lambda, f );

  cout << "\n";
  cout << "  Value = " << value << "\n";
  exact = tgamma ( lambda + 0.5 ) * sqrt ( r8_pi ) * besselj ( lambda, a ) 
    / pow ( 0.5 * a, lambda );
  cout << "  Exact = " << exact << "\n";

  return;
}
//****************************************************************************80

void gegenbauer_cc2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    GEGENBAUER_CC2_TEST tests GEGENBAUER_CC2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double exact;
  double lambda;
  int n;
  const double r8_pi = 3.141592653589793;
  double value;

  cout << "\n";
  cout << "GEGENBAUER_CC2_TEST:\n";
  cout << "  GEGENBAUER_CC2 estimates the Gegenbauer integral of\n";
  cout << "  a function f(x) using a Clenshaw-Curtis type approach\n";
  cout << "  based on the zeros of Tn(x).\n";

  lambda = 0.75;
  a = 2.0;
  n = 6;

  value = gegenbauer_cc2 ( n, lambda, f );

  cout << "\n";
  cout << "  Value = " << value << "\n";
  exact = tgamma ( lambda + 0.5 ) * sqrt ( r8_pi ) * besselj ( lambda, a ) 
    / pow ( 0.5 * a, lambda );
  cout << "  Exact = " << exact << "\n";

  return;
}
//****************************************************************************80

void i4_uniform_ab_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_UNIFORM_AB_TEST tests I4_UNIFORM_AB.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 October 2014
//
//  Author:
//
//    John Burkardt
//
{
  int a = -100;
  int b = 200;
  int i;
  int j;
  int seed = 123456789;

  cout << "\n";
  cout << "I4_UNIFORM_AB_TEST\n";
  cout << "  I4_UNIFORM_AB computes pseudorandom values\n";
  cout << "  in an interval [A,B].\n";

  cout << "\n";
  cout << "  The lower endpoint A = " << a << "\n";
  cout << "  The upper endpoint B = " << b << "\n";
  cout << "  The initial seed is " << seed << "\n";
  cout << "\n";

  for ( i = 1; i <= 20; i++ )
  {
    j = i4_uniform_ab ( a, b, seed );

    cout << "  " << setw(8) << i
         << "  " << setw(8) << j << "\n";
  }

  return;
}
//****************************************************************************80

void r8_mop_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_MOP_TEST tests R8_MOP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 December 2014
//
//  Author:
//
//    John Burkardt
//
{
  int i4;
  int i4_max;
  int i4_min;
  double r8;
  int seed = 123456789;
  int test;

  cout << "\n";
  cout << "R8_MOP_TEST\n";
  cout << "  R8_MOP evaluates (-1.0)^I4 as an R8.\n";
  cout << "\n";
  cout << "    I4  R8_MOP(I4)\n";
  cout << "\n";

  i4_min = -100;
  i4_max = +100;

  for ( test = 1; test <= 10; test++ )
  {
    i4 = i4_uniform_ab ( i4_min, i4_max, seed );
    r8 = r8_mop ( i4 );
    cout << "  "
         << setw(4) << i4 << "  "
         << setw(4) <<r8 << "\n";
  }

  return;
}
//****************************************************************************80

void r8vec_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT_TEST tests R8VEC_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
  double a[4] = { 123.456, 0.000005, -1.0E+06, 3.14159265 };
  int n = 4;

  cout << "\n";
  cout << "R8VEC_PRINT_TEST\n";
  cout << "  R8VEC_PRINT prints an R8VEC.\n";

  r8vec_print ( n, a, "  The R8VEC:" );

  return;
}
//****************************************************************************80

void r8vec2_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC2_PRINT_TEST tests R8VEC2_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  double a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
  double b[5];
  double c[5];
  int i;
  int n = 5;

  cout << "\n";
  cout << "R8VEC2_PRINT_TEST\n";
  cout << "  R8VEC2_PRINT prints a pair of R8VEC's.\n";

  for ( i = 0; i < n; i++ )
  {
    b[i] = a[i] * a[i];
    c[i] = sqrt ( a[i] );
  }

  r8vec2_print ( n, b, c, "  Squares and square roots:" );

  return;
}
