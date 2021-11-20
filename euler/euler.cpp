# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "euler.hpp"

//****************************************************************************80

void euler ( void dydt ( double x, double y[], double yp[] ), double tspan[2], 
  double y0[], int n, int m, double t[], double y[] )

/******************************************************************************/
//
//  Purpose:
//
//    euler approximates the solution to an ODE using Euler's method.
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
//  Input:
//
//    dydt: a function that evaluates the right hand side of the ODE.
//
//    double tspan[2]: contains the initial and final times.
//
//    double y0[m]: a column vector containing the initial condition.
//
//    int n: the number of steps to take.
//
//    int m: the number of variables.
//
//  Output:
//
//    double t[n+1], y[m*(n+1)]: the times and solution values.
//
{
  double dt;
  double *dy;
  int i;
  int j;
  double tfirst;
  double tlast;

  dy = new double[m];

  tfirst = tspan[0];
  tlast = tspan[1];
  dt = ( tlast - tfirst ) / ( double ) ( n );
  j = 0;
  t[j] = tspan[0];
  for ( i = 0; i < m; i++ )
  {
    y[i+j*m] = y0[i];
  }

  for ( j = 0; j < n; j++ )
  {
    dydt ( t[j], y+j*m, dy );
    t[j+1] = t[j] + dt;
    for ( i = 0; i < m; i++ )
    {
      y[i+(j+1)*m] = y[i+j*m] + dt * dy[i];
    }
  }

  delete [] dy;

  return;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    timestamp prints the current YMDHMS date as a time stamp.
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
