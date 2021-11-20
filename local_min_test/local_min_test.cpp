# include <cfloat>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <string>

using namespace std;

# include "local_min.hpp"

int main ( );
void local_min_example ( double a, double b, double f ( double x ),
  string title );
double g_01 ( double x );
double g_02 ( double x );
double g_03 ( double x );
double g_04 ( double x );
double g_05 ( double x );
double g_06 ( double x );
double g_07 ( double x );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    local_min_test() tests local_min().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 June 2021
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;

  timestamp ( );
  cout << "\n";
  cout << "local_min_test():\n";
  cout << "  C++ version\n";
  cout << "  local_min() seeks a local minimizer of a function F(X)\n";
  cout << "  in an interval [A,B].\n";

  a = 0.0;
  b = 3.141592653589793;
  local_min_example ( a, b, g_01,
    "g_01(x) = ( x - 2 ) * ( x - 2 ) + 1" );

  a = 0.0;
  b = 1.0;
  local_min_example ( a, b, g_02,
    "g_02(x) = x * x + exp ( - x )" );

  a = -2.0;
  b =  2.0;
  local_min_example ( a, b, g_03,
    "g_03(x) = x^4 + 2x^2 + x + 3" );

  a =  0.0001;
  b =  1.0;
  local_min_example ( a, b, g_04,
    "g_04(x) = exp ( x ) + 1 / ( 100 x )" );

  a =  0.0002;
  b = 2.0;
  local_min_example ( a, b, g_05,
    "g_05(x) = exp ( x ) - 2x + 1/(100x) - 1/(1000000x^2)" );

  a = 1.8;
  b = 1.9;
  local_min_example ( a, b, g_06, 
    "g_06(x) = -x*sin(10*pi*x)-1.0" );

  a = -1.2;
  b = 2.7;
  local_min_example ( a, b, g_07, 
    "g_07(x) = max(-2(x-1),8(x-1)) + 25*(x-1)^2" );
//
//  Terminate.
//
  cout << "\n";
  cout << "local_min_test():\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void local_min_example ( double a, double b, double f ( double x ),
  string title )

//****************************************************************************80
//
//  Purpose:
//
//    local_min_example() tests local_min() on one test function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 May 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double A, B, the endpoints of the interval.
//
//    double F ( double x ), the name of a user-supplied
//    function, whose local minimum is being sought.
//
//    string TITLE, a title for the problem.
//
{
  int calls;
  double fa;
  double fb;
  double fx;
  double t;
  double x;

  t = sqrt ( DBL_EPSILON );

  fx = local_min ( a, b, t, f, x, calls );
  fa = f ( a );
  fb = f ( b );

  cout << "\n";
  cout << "  " << title << "\n";
  cout << "\n";
  cout << "           A                 X             B\n";
  cout << "         F(A)              F(X)          F(B)\n";
  cout << "  " << setw(14) << a
       << "  " << setw(14) << x
       << "  " << setw(14) << b << "\n";
  cout << "  " << setw(14) << fa
       << "  " << setw(14) << fx
       << "  " << setw(14) << fb << "\n";
  cout << "  Number of calls to F = " << calls << "\n";

  return;
}
//****************************************************************************80

double g_01 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    g_01() evaluates (x-2)^2 + 1.
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
//    double G_01, the value of the function at X.
//
{
  double value;

  value = ( x - 2.0 ) * ( x - 2.0 ) + 1.0;

  return value;
}
//****************************************************************************80

double g_02 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    g_02() evaluates x^2 + exp ( - x ).
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
//    double G_02, the value of the function at X.
//
{
  double value;

  value = x * x + exp ( - x );

  return value;
}
//****************************************************************************80

double g_03 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    g_03() evaluates x^4+2x^2+x+3.
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
//    double G_03, the value of the function at X.
//
{
  double value;

  value = ( ( x * x + 2.0 ) * x + 1.0 ) * x + 3.0;

  return value;
}
//****************************************************************************80

double g_04 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    g_04() evaluates exp(x)+1/(100X)
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
//    double G_04, the value of the function at X.
//
{
  double value;

  value = exp ( x ) + 0.01 / x;

  return value;
}
//****************************************************************************80

double g_05 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    g_05() evaluates exp(x) - 2x + 1/(100x) - 1/(1000000x^2)
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
//    double G_05, the value of the function at X.
//
{
  double value;

  value = exp ( x ) - 2.0 * x + 0.01 / x - 0.000001 / x / x;

  return value;
}
//****************************************************************************80

double g_06 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    g_06() evaluates - x * sin(10 pi x ) - 1.0;
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 May 2021
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
//    double G_06, the value of the function at X.
//
{
  double r8_pi = 3.141592653589793;
  double value;

  value = - x * sin ( 10.0 * r8_pi * x ) - 1.0;

  return value;
}
//****************************************************************************80

double g_07 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    g_07() evaluates max(-2(x-1), 8(x-1)) + 25 (x-1)^2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 May 2021
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
//    double G_07, the value of the function at X.
//
{
  double value;

  value = fmax ( -2.0 * ( x - 1 ), 8.0 * ( x - 1 ) ) 
          + 25.0 * pow ( x - 1.0, 2 );

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

