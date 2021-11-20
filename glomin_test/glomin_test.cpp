# include <cfloat>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <string>

using namespace std;

# include "glomin.hpp"

int main ( );
void glomin_example ( double a, double b, double c, double m, double e,
  double t, double f ( double x ), string title );
double h_01 ( double x );
double h_02 ( double x );
double h_03 ( double x );
double h_04 ( double x );
double h_05 ( double x );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    glomin_test() tests glomin().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 June 2021
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double c;
  double e;
  double m;
  double t;

  timestamp ( );
  cout << "\n";
  cout << "glomin_test():\n";
  cout << "  C++ version\n";
  cout << "  glomin() seeks a global minimizer of a function F(X)\n";
  cout << "  in an interval [A,B], given some upper bound M \n";
  cout << "  for the second derivative of F.\n";

  e = sqrt ( DBL_EPSILON );
  t = sqrt ( DBL_EPSILON );

  cout << "\n";
  cout << "  Tolerances:\n";
  cout << "  e = " << e << "\n";
  cout << "  t = " << t << "\n";

  a = 7.0;
  b = 9.0;
  c = ( a + b ) / 2.0;
  m = 0.0;
  glomin_example ( a, b, c, m, e, t, h_01,
    "h_01(x) = 2 - x" );

  a = 7.0;
  b = 9.0;
  c = ( a + b ) / 2.0;
  m = 100.0;
  glomin_example ( a, b, c, m, e, t, h_01,
    "h_01(x) = 2 - x" );

  a = -1.0;
  b = +2.0;
  c = ( a + b ) / 2.0;
  m = 2.0;
  glomin_example ( a, b, c, m, e, t, h_02,
    "h_02(x) = x * x" );

  a = -1.0;
  b = +2.0;
  c = ( a + b ) / 2.0;
  m = 2.1;
  glomin_example ( a, b, c, m, e, t, h_02,
    "h_02(x) = x * x" );

  a = -0.5;
  b =  +2.0;
  c = ( a + b ) / 2.0;
  m = 14.0;
  glomin_example ( a, b, c, m, e, t, h_03,
    "h_03(x) = x^3 + x^2" );

  a = -0.5;
  b =  +2.0;
  c = ( a + b ) / 2.0;
  m = 28.0;
 glomin_example ( a, b, c, m, e, t, h_03,
    "h_03(x) = x^3 + x^2" );

  a = -10.0;
  b = +10.0;
  c = ( a + b ) / 2.0;
  m = 72.0;
  glomin_example ( a, b, c, m, e, t, h_04,
    "h_04(x) = ( x + sin(x) ) * exp(-x*x)" );

  a = -10.0;
  b = +10.0;
  c = ( a + b ) / 2.0;
  m = 72.0;
  glomin_example ( a, b, c, m, e, t, h_05,
    "h_05(x) = ( x - sin(x) ) * exp(-x*x)" );
//
//  Terminate.
//
  cout << "\n";
  cout << "glomin_test():\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void glomin_example ( double a, double b, double c, double m,
  double e, double t, double f ( double x ), string title )

//****************************************************************************80
//
//  Purpose:
//
//    glomin_example() tests glomin() on one test function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 May 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double A, B, the endpoints of the interval.
//
//    double C, an initial guess for the global
//    minimizer.  If no good guess is known, C = A or B is acceptable.
//
//    double M, the bound on the second derivative.
//
//    double E, a positive tolerance, a bound for the
//    absolute error in the evaluation of F(X) for any X in [A,B].
//
//    double T, a positive absolute error tolerance.
//
//    double F ( double x ), the name of a user-supplied
//    function whose global minimum is being sought.
//
//    string TITLE, a title for the problem.
//
{
  int calls;
  double fa;
  double fb;
  double fx;
  double x;

  fx = glomin ( a, b, c, m, e, t, f, x, calls );
  fa = f ( a );
  fb = f ( b );

  cout << "\n";
  cout << "  " << title << "\n";
  cout << "  M = " << m << "\n";
  cout << "\n";
  cout << "           A                 X             B\n";
  cout << "         F(A)              F(X)          F(B)\n";
  cout << "  " << setprecision(6) << setw(14) << a
       << "  " << setw(14) << x
       << "  " << setw(14) << b << "\n";
  cout << "  " << setw(14) << fa
       << "  " << setw(14) << fx
       << "  " << setw(14) << fb << "\n";
  cout << "  Number of calls to F = " << calls << "\n";

  return;
}
//****************************************************************************80

double h_01 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    h_01() evaluates 2 - x.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the evaluation point.
//
//  Output:
//
//    double double H_01, the value of the function at X.
//
{
  double value;

  value = 2.0 - x;

  return value;
}
//****************************************************************************80

double h_02 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    h_02() evaluates x^2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the evaluation point.
//
//  Output:
//
//    double H_02, the value of the function at X.
//
{
  double value;

  value = x * x;

  return value;
}
//****************************************************************************80

double h_03 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    h_03() evaluates x^3+x^2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the evaluation point.
//
//  Output:
//
//    double H_03, the value of the function at X.
//
{
  double value;

  value = x * x * ( x + 1.0 );

  return value;
}
//****************************************************************************80

double h_04 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    h_04() evaluates ( x + sin ( x ) ) * exp ( - x * x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the evaluation point.
//
//  Output:
//
//    double H_04, the value of the function at X.
//
{
  double value;

  value = ( x + sin ( x ) ) * exp ( - x * x );

  return value;
}
//****************************************************************************80

double h_05 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    h_05() evaluates ( x - sin ( x ) ) * exp ( - x * x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the evaluation point.
//
//  Output:
//
//    double H_05, the value of the function at X.
//
{
  double value;

  value = ( x - sin ( x ) ) * exp ( - x * x );

  return value;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    timestamp() prints the current YMDHMS date as a time stamp.
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
//    24 September 2003
//
//  Author:
//
//    John Burkardt
//
{
  const int TIME_SIZE(40);

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  cout << time_buffer << "\n";

  return;
}

