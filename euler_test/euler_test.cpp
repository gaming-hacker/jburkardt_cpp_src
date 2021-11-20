# include <cmath>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "euler.hpp"

int main ( );
void euler_humps_test ( int n );
void humps_deriv ( double x, double y[], double yp[] );
void humps_exact ( int n, double x[], double y[] );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    main is the main program for euler_test.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 April 2020
//
//  Author:
//
//    John Burkardt
//
{
  int n;

  timestamp ( );
  cout << "\n";
  cout << "euler_test\n";
  cout << "  C++ version\n";
  cout << "  Test euler().\n";

  n = 50;
  euler_humps_test ( n );
//
//  Terminate.
//
  cout << "\n";
  cout << "euler_test:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
/******************************************************************************/

void euler_humps_test ( int n )

/******************************************************************************/
/*
  Purpose:

    euler_humps_test calls the Euler code.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    25 April 2020

  Author:

    John Burkardt

  Input:

    int N: the number of steps to take.
*/
{
  string command_filename;
  ofstream command;
  string data_filename;
  ofstream data;
  string header = "euler_humps";
  int i;
  int m = 1;
  string plot_filename;
  double *t;
  double tspan[2];
  double *y;
  double y0[1];
  double *y2;

  t = new double[n+1];
  y = new double[(n+1)*m];
  y2 = new double[(n+1)*m];

  cout << "\n";
  cout << "euler_humps_test:\n";

  tspan[0] = 0.0;
  tspan[1] = 2.0;
  humps_exact ( 1, tspan, y0 );

  euler ( humps_deriv, tspan, y0, n, m, t, y );

  humps_exact ( n+1, t, y2 );
//
//  Create the data file.
//
  data_filename = header + "_data.txt";
  data.open ( data_filename.c_str ( ) );

  for ( i = 0; i <= n; i++ )
  {
    data << "  " << t[i]
         << "  " << y[i]
         << "  " << y2[i] << "\n";
  }

  data.close ( );

  cout << "\n";
  cout << "  euler_humps_test: data stored in '" << data_filename << "'.\n";
//
//  Create the command file.
//
  command_filename = header + "_commands.txt";
  command.open ( command_filename.c_str ( ) );

  command << "# " << command_filename << "\n";
  command << "#\n";
  command << "# Usage:\n";
  command << "#  gnuplot < " << command_filename << "\n";
  command << "#\n";
  command << "set term png\n";
  plot_filename = header + "_test.png";
  command << "set output '" << plot_filename << "'\n";
  command << "set xlabel '<-- T -->'\n";
  command << "set ylabel '<-- Y(T) -->'\n";
  command << "set title 'euler: Humps ODE'\n";
  command << "set grid\n";
  command << "set style data lines\n";
  command << "plot '" << data_filename << "' using 1:2 with lines lw 3 lt rgb 'red',\\\n";
  command << "     '" << data_filename << "' using 1:3 with lines lw 3 lt rgb 'blue'\n";
  command << "quit\n";

  command.close ( );

  cout << "  euler_humps_test: plot commands stored in '" << command_filename << "'.\n";
//
//  Free memory.
//
  delete [] t;
  delete [] y;
  delete [] y2;

  return;
}
//*****************************************************************************/

void humps_deriv ( double x, double y[], double yp[] )

//*****************************************************************************/
//
//  Purpose:
//
//    humps_deriv evaluates the right hand side of the humps ODE.
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
//    04 August 2019
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double x, y[1]: the arguments.
//
//  Output:
//
//    double yp[1]: the value of the derivative at x.
//
{
  yp[0] = - 2.0 * ( x - 0.3 ) / pow ( pow ( x - 0.3, 2 ) + 0.01, 2 )
          - 2.0 * ( x - 0.9 ) / pow ( pow ( x - 0.9, 2 ) + 0.04, 2 );

  return;
}
//****************************************************************************80

void humps_exact ( int n, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    humps_exact evaluates the humps function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 August 2019
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int n: the number of evaluation points.
//
//    double x[n]: the evaluation point.
//
//  Output:
//
//    double y[n]: the function values.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    y[i] = 1.0 / ( pow ( x[i] - 0.3, 2 ) + 0.01 )
         + 1.0 / ( pow ( x[i] - 0.9, 2 ) + 0.04 )
         - 6.0;
  }

  return;
}
