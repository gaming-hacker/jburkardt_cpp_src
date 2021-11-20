# include <cmath>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "stiff_ode.hpp"

//****************************************************************************80

double *r8vec_linspace_new ( int n, double a_first, double a_last )

//****************************************************************************80
//
//  Purpose:
//
//    r8vec_linspace_new() creates a vector of linearly spaced values.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//    4 points evenly spaced between 0 and 12 will yield 0, 4, 8, 12.
//
//    In other words, the interval is divided into N-1 even subintervals,
//    and the endpoints of intervals are used as the points.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 March 2011
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in the vector.
//
//    double A_FIRST, A_LAST, the first and last entries.
//
//  Output:
//
//    double R8VEC_LINSPACE_NEW[N], a vector of linearly spaced data.
//
{
  double *a;
  int i;

  a = new double[n];

  if ( n == 1 )
  {
    a[0] = ( a_first + a_last ) / 2.0;
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      a[i] = ( ( double ) ( n - 1 - i ) * a_first 
             + ( double ) (         i ) * a_last ) 
             / ( double ) ( n - 1     );
    }
  }
  return a;
}
//****************************************************************************80

void stiff_deriv ( double t, double y[], double dydt[] )

//****************************************************************************80
//
//  stiff_deriv evaluates the right hand side of the stiff ODE.
//
//  Discussion:
//
//    y' = lambda * ( cos(t) - y )
//    y(t0) = y0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double T, Y[1]: the time and solution value.
//
//  Output:
//
//    double DYDT[1]: the derivative value.
//
{
  double lambda;
  double t0;
  double y0;

  stiff_parameters ( lambda, t0, y0 );

  dydt[0] = lambda * ( cos ( t ) - y[0] );

  return;
}
//****************************************************************************80

void stiff_euler ( int n, double t[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_euler() uses the Euler method on the stiff ODE.
//
//  Discussion:
//
//    y' = lambda * ( cos(t) - y )
//    y(t0) = y0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N: the number of steps to take.
//
//  Output:
//
//    double T[N+1], Y[N+1]: the times and estimated solutions.
//
{
  double dt;
  int i;
  double lambda;
  double t0;
  double tstop;
  double y0;

  stiff_parameters ( lambda, t0, y0 );

  tstop = 1.0;
  dt = ( tstop - 0 ) / ( double ) ( n );

  t[0] = t0;
  y[0] = y0;

  for ( i = 0; i < n; i++ )
  {
    t[i+1] = t[i] + dt;
    y[i+1] = y[i] + dt * lambda * ( cos ( t[i] ) - y[i] );
  }

  return;
}
//****************************************************************************80

void stiff_euler_backward ( int n, double t[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_euler_backward() uses the backward Euler method on the stiff ODE.
//
//  Discussion:
//
//    y' = lambda * ( cos(t) - y )
//    y(t0) = y0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N: the number of steps to take.
//
//  Output:
//
//    double T[N+1], Y[N+1]: the times and estimated solutions.
//
{
  double dt;
  int i;
  double lambda;
  double t0;
  double tstop;
  double y0;

  stiff_parameters ( lambda, t0, y0 );

  tstop = 1.0;
  dt = ( tstop - 0 ) / ( double ) ( n );

  t[0] = t0;
  y[0] = y0;

  for ( i = 0; i < n; i++ )
  {
    t[i+1] = t[i] + dt;
    y[i+1] = ( y[i] + dt * lambda * cos ( t[i+1] ) ) 
      / ( 1.0 + lambda * dt );
  }

  return;
}
//****************************************************************************80

double *stiff_exact ( int n, double t[] )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_exact() evaluates the exact solution of the stiff ODE.
//
//  Discussion:
//
//    y' = lambda * ( cos(t) - y )
//    y(t0) = y0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N: the number of values.
//
//    double T[N]: the evaluation times.
//
//  Output:
//
//    double STIFF_EXACT[N]: the exact solution values.
//
{
  int i;
  double lambda;
  double t0;
  double *y;
  double y0;

  y = new double[n];

  stiff_parameters ( lambda, t0, y0 );

  for ( i = 0; i < n; i++ )
  {
    y[i] = lambda * ( sin ( t[i] ) + lambda * cos ( t[i] )
      - lambda * exp ( - lambda * t[i] ) ) / ( lambda * lambda + 1.0 );
  }

  return y;
}
//****************************************************************************80

void stiff_midpoint ( int n, double t[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_midpoint() uses the midpoint method on the stiff ODE.
//
//  Discussion:
//
//    y' = lambda * ( cos(t) - y )
//    y(t0) = y0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N: the number of steps to take.
//
//  Output:
//
//    double T[N+1], Y[N+1]: the times and estimated solutions.
//
{
  double dt;
  int i;
  double lambda;
  double t0;
  double tstop;
  double y0;

  stiff_parameters ( lambda, t0, y0 );

  tstop = 1.0;
  dt = ( tstop - 0 ) / ( double ) ( n );

  t[0] = t0;
  y[0] = y0;

  for ( i = 0; i < n; i++ )
  {
    t[i+1] = t[i] + dt;
    y[i+1] = 
      ( 
        y[i] + lambda * 0.5 * dt * ( 
                                     cos ( t[i] ) - y[i] + cos ( t[i+1] ) 
                                   ) 
      ) 
      / ( 1.0 + lambda * 0.5 * dt );
  }

  return;
}
//****************************************************************************80

void stiff_parameters ( double &lambda, double &t0, double &y0 )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_parameters() returns parameters of the stiff ODE.
//
//  Discussion:
//
//    y' = lambda * ( cos(t) - y )
//    y(t0) = y0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 April 2021
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    double &LAMBDA, a parameter.
//
//    double &T0, double &Y0: the initial time and value.
//
{
  lambda = 50.0;
  t0 = 0.0;
  y0 = 0.0;

  return;
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
//    08 July 2009
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
