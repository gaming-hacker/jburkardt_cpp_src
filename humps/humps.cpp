# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "humps.hpp"

//****************************************************************************80

double humps_antideriv ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    humps_antideriv evaluates the antiderivative of the humps function.
//
//  Discussion:
//
//    y = 1.0 / ( r8_square ( x - 0.3 ) + 0.01 ) 
//      + 1.0 / ( r8_square ( x - 0.9 ) + 0.04 ) 
//      - 6.0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double x: the argument.
//
//  Output:
//
//    double humps_antideriv: the value of the antiderivative at x.
//
{
  double ya;

  ya = ( 1.0 / 0.1 ) * atan ( ( x - 0.3 ) / 0.1 )
     + ( 1.0 / 0.2 ) * atan ( ( x - 0.9 ) / 0.2 )
     - 6.0 * x;

  return ya;
}
//****************************************************************************80

double humps_deriv ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    humps_deriv evaluates the derivative of the humps function.
//
//  Discussion:
//
//    y = 1.0 / ( ( x - 0.3 )^2 + 0.01 )
//      + 1.0 / ( ( x - 0.9 )^2 + 0.04 )
//      - 6.0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double x: the argument.
//
//  Output:
//
//    double humps_deriv: the value of the derivative at x.
//
{
  double yp;

  yp = - 2.0 * ( x - 0.3 ) / r8_square ( r8_square ( x - 0.3 ) + 0.01 )
       - 2.0 * ( x - 0.9 ) / r8_square ( r8_square ( x - 0.9 ) + 0.04 );

  return yp;
}
//****************************************************************************80

double humps_deriv2 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    humps_deriv2 evaluates the second derivative of the humps function.
//
//  Discussion:
//
//    y = 1.0 / ( ( x - 0.3 )^2 + 0.01 )
//      + 1.0 / ( ( x - 0.9 )^2 + 0.04 )
//      - 6.0;
//
//    yp = - 2.0 * ( x - 0.3 ) / ( ( x - 0.3 )^2 + 0.01 )^2
//         - 2.0 * ( x - 0.9 ) / ( ( x - 0.9 )^2 + 0.04 )^2;
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double x: the argument.
//
//  Output:
//
//    double humps_deriv2: the value of the second derivative at x.
//
{
  double u1;
  double u1p;
  double u2;
  double u2p;
  double v1;
  double v1p;
  double v2;
  double v2p;
  double ypp;

  u1 = - 2.0 * ( x - 0.3 );
  v1 = r8_square ( r8_square ( x - 0.3 ) + 0.01 );
  u2 = - 2.0 * ( x - 0.9 );
  v2 = r8_square ( r8_square ( x - 0.9 ) + 0.04 );

  u1p = - 2.0;
  v1p = 2.0 * ( r8_square ( x - 0.3 ) + 0.01 ) * 2.0 * ( x - 0.3 ); 
  u2p = - 2.0;
  v2p = 2.0 * ( r8_square ( x - 0.9 ) + 0.04 ) * 2.0 * ( x - 0.9 );

  ypp = ( u1p * v1 - u1 * v1p ) / v1 / v1
      + ( u2p * v2 - u2 * v2p ) / v2 / v2;

  return ypp;
}
//****************************************************************************80

double humps_fun ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    humps_fun evaluates the humps function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double x: the evaluation point.
//
//  Output:
//
//    double y: the function value.
//
{
  double y;

  y = 1.0 / ( r8_square ( x - 0.3 ) + 0.01 )
    + 1.0 / ( r8_square ( x - 0.9 ) + 0.04 )
    - 6.0;

  return y;
}
//****************************************************************************80

double humps_ode ( double x, double y )

//****************************************************************************80
//
//  Purpose:
//
//    humps_ode evaluates the derivative of the humps function for an ODE solver.
//
//  Discussion:
//
//    This verion of "humps_deriv" appends the input argument "y", as expected 
//    by most ODE solving software.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
//
//  Input:
//
//    double x: the argument.
//
//    double y: the value of the dependent variable.
//
//  Output:
//
//    double humps_ode: the value of the derivative of the humps function.
//
{
  double yp;

  yp = - 1.0 / r8_square ( r8_square ( x - 0.3 ) + 0.01 )
       * 2.0 * ( x - 0.3 )
       - 1.0 / r8_square ( r8_square ( x - 0.9 ) + 0.04 )
       * 2.0 * ( x - 0.9 );

  return yp;
}
//****************************************************************************80

void plot_xy ( int n, double x[], double y[], string prefix )

//****************************************************************************80
//
//  Purpose:
//
//    plot_xy plots xy data.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int n, the number of data points.
//
//    double x[n], y[n], the data points.
//
//    string prefix, the prefix for the plot names.
//
{
  string command_filename;
  ofstream command_unit;
  string data_filename;
  ofstream data_unit;
  int i;
  string output_filename;
  string prefix2;
//
//  Create the data file.
//
  data_filename = prefix + "_data.txt";
  data_unit.open ( data_filename.c_str ( ) );
  for ( i = 0; i < n; i++ )
  {
    data_unit << x[i] << "  " << y[i] << "\n";
  }
  data_unit.close ( );
  cout << "\n";
  cout << "  Created graphics data file '" << data_filename << "'.\n";
//
//  Plot the selected data.
//
  command_filename = prefix + "_commands.txt";
  command_unit.open ( command_filename.c_str ( ) );

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set nokey\n";
  output_filename = prefix + ".png";
  command_unit << "set output '" << output_filename << "'\n";
  command_unit << "set xlabel '<---X--->'\n";
  command_unit << "set ylabel '<---Y(X)--->'\n";
  prefix2 = s_escape_tex ( prefix );
  command_unit << "set title '" << prefix2 << "'\n";
  command_unit << "set grid\n";
  command_unit << "set style data lines\n";
  command_unit << "plot '" << data_filename << "' using 1:2 lw 3 linecolor rgb 'blue'\n";

  command_unit.close ( );
  cout << "  Created graphics command file '" << command_filename<< "'.\n";

  return;
}
//****************************************************************************80

double r8_square ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    r8_square returns the square of an R8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double x: the argument.
//
//  Output:
//
//    double r8_square: the square of x.
//
{
  double value;

  value = x * x;

  return value;
}
//****************************************************************************80

string s_escape_tex ( string s1 )

//****************************************************************************80
//
//  Purpose:
//
//    S_ESCAPE_TEX de-escapes TeX escape sequences.
//
//  Discussion:
//
//    In particular, every occurrence of the characters '\', '_',
//    '^', '{' and '}' will be replaced by '\\', '\_', '\^',
//    '\{' and '\}'.  A TeX interpreter, on seeing these character
//    strings, is then likely to return the original characters.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string S1, the string to be de-escaped.
//
//    Output, string S_ESCAPE_TEX, a copy of the string,
//    modified to avoid TeX escapes.
//
{
  char ch;
  int s1_length;
  int s1_pos;
  char *s2;
  int s2_pos;
  string s3;
  int slash_count;

  s1_length = s1.length ( );

  slash_count = 0;
  for ( s1_pos = 0; s1_pos < s1_length; s1_pos++ )
  {
    ch = s1[s1_pos];

    if ( ch == '\\' ||
         ch == '_' ||
         ch == '^' ||
         ch == '{' ||
         ch == '}' )
    {
      slash_count = slash_count + 1;
    }
  }
  s2 = new char[s1_length + slash_count + 1];
//
//  Now copy S1 into S2.
//
  s1_pos = 0;
  s2_pos = 0;

  for ( s1_pos = 0; s1_pos < s1_length; s1_pos++ )
  {
    ch = s1[s1_pos];

    if ( ch == '\\' ||
         ch == '_' ||
         ch == '^' ||
         ch == '{' ||
         ch == '}' )
    {
      s2[s2_pos] = '\\';
      s2_pos = s2_pos + 1;
    }

    s2[s2_pos] = ch;
    s2_pos = s2_pos + 1;
  }

  s2[s2_pos] = '\0';
  s2_pos = s2_pos + 1;

  s3 = string ( s2 );

  return s3;
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
//    31 May 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 March 2018
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
  const struct std::tm *tm_ptr;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}

