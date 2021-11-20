# include <cmath>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "predator_prey_ode.hpp"

//****************************************************************************80

double *predator_prey_conserved ( int n, double rf[] )

//****************************************************************************80
//
//  Purpose:
//
//    predator_prey_conserved evaluates a conserved quantity.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 October 2020
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    George Lindfield, John Penny,
//    Numerical Methods Using MATLAB,
//    Second Edition,
//    Prentice Hall, 1999,
//    ISBN: 0-13-012641-1,
//    LC: QA297.P45.
//
//  Input:
//
//    int N: the number of sets of variables.
//
//    double RF[N*2]: the current solution variables, rabbits and foxes.
//
//  Output:
//
//    double PREDATOR_PREY_CONSERVED[N]: the value of the conserved quantity.
//
{
  double alpha;
  double beta;
  double delta;
  double gamma;
  double *h;
  int i;

  predator_prey_parameters ( alpha, beta, gamma, delta );

  h = new double[n];

  for ( i = 0; i < n; i++ )
  {
    h[i] = delta * rf[0+i*2] - gamma * log ( rf[0+i*2] ) 
         + beta  * rf[1+i*2] - alpha * log ( rf[1+i*2] );
  }

  return h;
}
//****************************************************************************80

double *predator_prey_deriv ( double t, double rf[] )

//****************************************************************************80
//
//  Purpose:
//
//    predator_prey_deriv evaluates the right hand side of the system.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 October 2020
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    George Lindfield, John Penny,
//    Numerical Methods Using MATLAB,
//    Second Edition,
//    Prentice Hall, 1999,
//    ISBN: 0-13-012641-1,
//    LC: QA297.P45.
//
//  Input:
//
//    double T: the current time.
//
//    double RF[2]: the current solution variables, rabbits and foxes.
//
//  Output:
//
//    double PREDATOR_PREY_DERIV[2]: the right hand side of the 2 ODE's.
//
{
  double alpha;
  double beta;
  double delta;
  double *drfdt;
  double gamma;

  drfdt = new double[2];

  predator_prey_parameters ( alpha, beta, gamma, delta );

  drfdt[0] =   alpha * rf[0] - beta  * rf[0] * rf[1];
  drfdt[1] = - gamma * rf[1] + delta * rf[0] * rf[1];

  return drfdt;
}
//****************************************************************************80

void predator_prey_parameters ( double &alpha, double &beta, double &gamma,
  double &delta )

//****************************************************************************80
//
//  Purpose:
//
//    predator_prey_parameters returns the problem parameters.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 October 2020
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    double &ALPHA, &BETA, &GAMMA, &DELTA, the coefficient values.
//
{
  alpha = 2.0;
  beta = 0.001;
  gamma = 10.0;
  delta = 0.002;

  return;
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
