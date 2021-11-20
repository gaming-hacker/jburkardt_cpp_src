# include <cmath>
# include <iomanip>
# include <iostream>

using namespace std;

# include "midpoint.hpp"

//****************************************************************************80

void midpoint_fixed ( double *dydt ( double x, double y[] ), 
  double tspan[2], double y0[], int n, int m, double t[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    midpoint_fixed uses a fixed-point midpoint method to solve an ODE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 April 2021
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
  double *f;
  int i;
  int it_max;
  int j;
  int k;
  double theta;
  double tm;
  double *ym;

  ym = new double[m];

  dt = ( tspan[1] - tspan[0] ) / ( double ) ( n );

  it_max = 10;
  theta = 0.5;

  t[0] = tspan[0];
  j = 0;
  for ( i = 0; i < m; i++ )
  {
    y[i+j*m] = y0[i];
  }

  for ( j = 0; j < n; j++ )
  {
    tm = t[j] + theta * dt;
    for ( i = 0; i < m; i++ )
    {
      ym[i] = y[i+j*m];
    }
    for ( k = 0; k < it_max; k++ )
    {
      f = dydt ( tm, ym );
      for ( i = 0; i < m; i++ )
      {
        ym[i] = y[i+j*m] + theta * dt * f[i];
      }
      delete [] f;
    }
    t[j+1] = t[j] + dt;
    for ( i = 0; i < m; i++ )
    {
      y[i+(j+1)*m] = (       1.0 / theta ) * ym[i]
                   + ( 1.0 - 1.0 / theta ) * y[i+j*m];
    }
  }

  delete [] ym;

  return;
}
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
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, double A_FIRST, A_LAST, the first and last entries.
//
//    Output, double R8VEC_LINSPACE_NEW[N], a vector of linearly spaced data.
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

