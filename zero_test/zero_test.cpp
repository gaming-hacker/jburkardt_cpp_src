# include <cfloat>
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <string>

using namespace std;

# include "zero.hpp"

int main ( );
void zero_example ( double a, double b, double f ( double x ), string title );

double f_01 ( double x );
double f_02 ( double x );
double f_03 ( double x );
double f_04 ( double x );
double f_05 ( double x );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    zero_test() tests zero().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2021
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
  cout << "zero_test():\n";
  cout << "  C++ version\n";
  cout << "  zero() seeks a root of a function F(X)\n";
  cout << "  in an interval [A,B].\n";

  a = 1.0;
  b = 2.0;
  zero_example ( a, b, f_01, "f_01(x) = sin ( x ) - x / 2" );

  a = 0.0;
  b = 1.0;
  zero_example ( a, b, f_02, "f_02(x) = 2 * x - exp ( - x )" );

  a = -1.0;
  b =  0.5;
  zero_example ( a, b, f_03, "f_03(x) = x * exp ( - x )" );

  a =  0.0001;
  b =  20.0;
  zero_example ( a, b, f_04, "f_04(x) = exp ( x ) - 1 / ( 100 * x * x )" );

  a = -5.0;
  b =  2.0;
  zero_example ( a, b, f_05, "f_05(x) = (x+3) * (x-1) * (x-1)" );
//
//  Terminate.
//
  cout << "\n";
  cout << "zero_test():\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void zero_example ( double a, double b, double f ( double x ), string title )

//****************************************************************************80
//
//  Purpose:
//
//    zero_example() tests zero() on one test function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double A, B, the endpoints of the change of sign interval.
//
//    double F ( double x ), the name of a user-supplied
//    function which evaluates the function whose zero is being sought.
//
//    string TITLE, a title for the problem.
//
{
  int calls;
  double fa;
  double fb;
  double fz;
  double t;
  double z;

  t = DBL_EPSILON;

  z = zero ( a, b, t, f, calls );
  fz = f ( z );
  fa = f ( a );
  fb = f ( b );

  cout << "\n";
  cout << "  " << title << "\n";
  cout << "\n";
  cout << "           A                 Z             B\n";
  cout << "         F(A)              F(Z)          F(B)\n";
  cout << "  " << setw(14) << a
       << "  " << setw(14) << z
       << "  " << setw(14) << b << "\n";
  cout << "  " << setw(14) << fa
       << "  " << setw(14) << fz
       << "  " << setw(14) << fb << "\n";
  cout << "  Number of calls to F = " << calls << "\n";

  return;
}
//****************************************************************************80

double f_01 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F_01 evaluates sin ( x ) - x / 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the point at which F is to be evaluated.
//
//  Output:
//
//    double F_01, the value of the function at X.
//
{
  double value;

  value = sin ( x ) - 0.5 * x;

  return value;
}
//****************************************************************************80

double f_02 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F_02 evaluates 2*x-exp(-x).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the point at which F is to be evaluated.
//
//  Output:
//
//    double F_02, the value of the function at X.
//
{
  double value;

  value = 2.0 * x - exp ( - x );

  return value;
}
//****************************************************************************80

double f_03 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F_03 evaluates x*exp(-x).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the point at which F is to be evaluated.
//
//  Output:
//
//    double F_03, the value of the function at X.
//
{
  double value;

  value = x * exp ( - x );

  return value;
}
//****************************************************************************80

double f_04 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F_04 evaluates exp(x) - 1 / (100*x*x).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the point at which F is to be evaluated.
//
//  Output:
//
//    double F_04, the value of the function at X.
//
{
  double value;

  value = exp ( x ) - 1.0 / 100.0 / x / x;

  return value;
}
//****************************************************************************80

double f_05 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F_05 evaluates (x+3)*(x-1)*(x-1).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double X, the point at which F is to be evaluated.
//
//  Output:
//
//    double F_05, the value of the function at X.
//
{
  double value;

  value = ( x + 3.0 ) * ( x - 1.0 ) * ( x - 1.0 );

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

