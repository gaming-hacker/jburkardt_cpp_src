# include <cmath>
# include <complex>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "toms243.hpp"

//****************************************************************************80

complex <double> toms243 ( complex <double> z )

//****************************************************************************80
//
//  Purpose:
//
//    TOMS243 computes the natural logarithm for complex values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 January 2019
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    David Collens,
//    Algorithm 243: Logarithm of a Complex Number,
//    Communications of the Association for Computing Machinery,
//    Volume 7, Number 11, November 1964, page 660.
//
//  Parameters:
//
//    Input, complex <double> Z, the argument of the function.
//
//    Output, complex <double> TOMS243, the value of the function.
//
{
  double a;
  double b;
  double c;
  double d;
  double e;
  double f;
  static double r8_pi = 3.141592653589793;
  complex <double> value;

  a = real ( z );
  b = imag ( z );
//
//  Ugly hack to get NaN values.
//
  if ( a == 0.0 && b == 0.0 )
  {
    c = 1.0 / a;
    d = 1.0 / b;
  }
  else
  {
    e = a / 2.0;
    f = b / 2.0;
    if ( abs ( e ) < 0.5 && fabs ( f ) < 0.5 )
    {
      c = fabs ( 2.0 * a ) + fabs ( 2.0 * b );
      d = 8.0 * ( a / c ) * a + 8.0 * ( b / c ) * b;
      c = 0.5 * ( log ( c ) + log ( d ) ) - log ( sqrt ( 8.0 ) );
    }
    else
    {
      c = fabs ( e / 2.0 ) + fabs ( f / 2.0 );
      d = 0.5 * ( e / c ) * e + 0.5 * ( f / c ) * f;
      c = 0.5 * ( log ( c ) + log ( d ) ) + log ( sqrt ( 8.0 ) );
    }

    if ( ( a != 0.0 ) && fabs ( f ) <= fabs ( e ) )
    {
      if ( copysign ( 1.0, a ) != -1.0 )
      {
        d = atan ( b / a );
      }
      else if ( copysign ( 1.0, b ) != -1.0 )
      {
        d = atan ( b / a ) + r8_pi;
      }
      else
      {
        d = atan ( b / a ) - r8_pi;
      }
    }
    else
    {
      d = - atan ( a / b ) + r8_pi / 2.0 * copysign ( 1.0, b );
    }

  }

  value = complex <double> ( c, d );

  return value;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    May 31 2001 09:45:54 AM
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
//  Parameters:
//
//    None
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}

