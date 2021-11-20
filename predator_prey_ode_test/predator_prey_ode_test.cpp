# include <cmath>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "predator_prey_ode.hpp"

int main ( );
void euler ( double *dydt ( double x, double y[] ), double tspan[2], 
  double y0[], int n, int m, double t[], double y[] );
void midpoint_fixed ( double *dydt ( double x, double y[] ), 
  double tspan[2], double y0[], int n, int m, double t[], double y[] );
void predator_prey_euler ( double tspan[2], double p0[2], int n );
void predator_prey_midpoint ( double tspan[2], double p0[2], int n );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    predator_prey_ode_test tests predator_prey_ode.
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
{
  double alpha;
  double beta;
  double delta;
  double gamma;
  int n;
  double p0[2];
  double tspan[2];

  timestamp ( );
  cout << "\n";
  cout << "predator_prey_ode_test:\n";
  cout << "  C++ version\n";
  cout << "  Test predator_prey_ode using euler, midpoint.\n";

  predator_prey_parameters ( alpha, beta, gamma, delta );

  cout << "\n";
  cout << "  Parameters:\n";
  cout << "    alpha = " << alpha << "\n";
  cout << "    beta  = " << beta << "\n";
  cout << "    gamma = " << gamma << "\n";
  cout << "    delta = " << delta << "\n";

  tspan[0] = 0.0;
  tspan[1] = 5.0;
  p0[0] = 5000.0;
  p0[1] = 100.0;
  n = 200;

  predator_prey_euler ( tspan, p0, n );
  predator_prey_midpoint ( tspan, p0, n );
//
//  Terminate.
//
  cout << "\n";
  cout << "predator_prey_ode_test:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return ( 0 );
}
//****************************************************************************80

void euler ( double *dydt ( double x, double y[] ), double tspan[2], 
  double y0[], int n, int m, double t[], double y[] )

//****************************************************************************80
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
    dy = dydt ( t[j], y+j*m );
    t[j+1] = t[j] + dt;
    for ( i = 0; i < m; i++ )
    {
      y[i+(j+1)*m] = y[i+j*m] + dt * dy[i];
    }
    free ( dy );
  }

  return;
}
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
//    28 April 2020
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
    tm = t[i] + theta * dt;
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
      free ( f );
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

void predator_prey_euler ( double tspan[2], double p0[2], int n )

//****************************************************************************80
//
//  Purpose:
//
//    predator_prey_euler solves the predator-prey system using euler().
//
//  Discussion:
//
//    The physical system under consideration is a pair of animal populations.
//
//    The PREY reproduce rapidly for each animal alive at the beginning of the
//    year, two more will be born by the end of the year.  The prey do not have
//    a natural death rate instead, they only die by being eaten by the predator.
//    Every prey animal has 1 chance in 1000 of being eaten in a given year by
//    a given predator.
//
//    The PREDATORS only die of starvation, but this happens very quickly.
//    If unfed, a predator will tend to starve in about 1/10 of a year.
//    On the other hand, the predator reproduction rate is dependent on
//    eating prey, and the chances of this depend on the number of available prey.
//
//    The resulting differential equations can be written:
//
//      PREY(0) = 5000         
//      PRED(0) =  100
//
//      d PREY / dT =    2 * PREY(T) - 0.001 * PREY(T) * PRED(T)
//      d PRED / dT = - 10 * PRED(T) + 0.002 * PREY(T) * PRED(T)
//
//    Here, the initial values (5000,100) are a somewhat arbitrary starting point.
//
//    The pair of ordinary differential equations that result have an interesting
//    behavior.  For certain choices of the interaction coefficients (such as
//    those given here), the populations of predator and prey will tend to 
//    a periodic oscillation.  The two populations will be out of phase the number
//    of prey will rise, then after a delay, the predators will rise as the prey
//    begins to fall, causing the predator population to crash again.
//
//    There is a conserved quantity, which here would be:
//      E(r,f) = 0.002 r + 0.001 f - 10 ln(r) - 2 ln(f)
// 
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 April 2020
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
//    double TSPAN[2]: the initial and final times.
//
//    double P0[2]: the initial number of prey and predators.
//
//    int N: the number of time steps.
//
{
  string command_filename;
  ofstream command;
  string data_filename;
  ofstream data;
  string header = "predator_prey_euler";
  int i;
  const int m = 2;
  double *pout;
  double *t;

  cout << "\n";
  cout << "predator_prey_euler\n";
  cout << "  A pair of ordinary differential equations for a population\n";
  cout << "  of predators and prey are solved using euler().\n";

  t = new double[n+1];
  pout = new double[(n+1)*m];

  euler ( predator_prey_deriv, tspan, p0, n, m, t, pout );
//
//  Create the data file.
//
  data_filename = header + "_data.txt";
  data.open ( data_filename.c_str ( ) );
  for ( i = 0; i < n; i++ )
  {
    data << "  " << t[i]
         << "  " << pout[0+i*m]
         << "  " << pout[1+i*m] << "\n";
  }
  data.close ( );

  cout << "\n";
  cout << "  predator_prey_euler: data stored in '" << data_filename << "'.\n";
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
  command << "set output '" << header << ".png'\n";
  command << "set xlabel '<-- PREDATOR -->'\n";
  command << "set ylabel '<-- PREY -->'\n";
  command << "set title 'Predator prey: euler'\n";
  command << "set grid\n";
  command << "set style data lines\n";
  command << "plot '" << data_filename << "' using 2:3 with lines lw 3\n";
  command << "quit\n";

  command.close ( );

  cout << "  predator_prey_euler: plot commands stored in '" << command_filename << "'.\n";

  delete [] pout;
  delete [] t;

  return;
}
//****************************************************************************80

void predator_prey_midpoint ( double tspan[2], double p0[2], int n )

//****************************************************************************80
//
//  Purpose:
//
//    predator_prey_midpoint solves the predator-prey system using midpoint_fixed().
//
//  Discussion:
//
//    The physical system under consideration is a pair of animal populations.
//
//    The PREY reproduce rapidly for each animal alive at the beginning of the
//    year, two more will be born by the end of the year.  The prey do not have
//    a natural death rate instead, they only die by being eaten by the predator.
//    Every prey animal has 1 chance in 1000 of being eaten in a given year by
//    a given predator.
//
//    The PREDATORS only die of starvation, but this happens very quickly.
//    If unfed, a predator will tend to starve in about 1/10 of a year.
//    On the other hand, the predator reproduction rate is dependent on
//    eating prey, and the chances of this depend on the number of available prey.
//
//    The resulting differential equations can be written:
//
//      PREY(0) = 5000         
//      PRED(0) =  100
//
//      d PREY / dT =    2 * PREY(T) - 0.001 * PREY(T) * PRED(T)
//      d PRED / dT = - 10 * PRED(T) + 0.002 * PREY(T) * PRED(T)
//
//    Here, the initial values (5000,100) are a somewhat arbitrary starting point.
//
//    The pair of ordinary differential equations that result have an interesting
//    behavior.  For certain choices of the interaction coefficients (such as
//    those given here), the populations of predator and prey will tend to 
//    a periodic oscillation.  The two populations will be out of phase the number
//    of prey will rise, then after a delay, the predators will rise as the prey
//    begins to fall, causing the predator population to crash again.
//
//    There is a conserved quantity, which here would be:
//      E(r,f) = 0.002 r + 0.001 f - 10 ln(r) - 2 ln(f)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 April 2020
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
//    double TSPAN = [ T0, TMAX ], the initial and final times.
//    A reasonable value might be [ 0, 5 ].
//
//    double P0 = [ PREY, PRED ], the initial number of prey and predators.
//    A reasonable value might be [ 5000, 100 ].
//
//    int N: the number of time steps.
//
{
  string command_filename;
  ofstream command;
  string data_filename;
  ofstream data;
  string header = "predator_prey_midpoint";
  int i;
  const int m = 2;
  double *pout;
  double *t;

  cout << "\n";
  cout << "predator_prey_midpoint\n";
  cout << "  A pair of ordinary differential equations for a population\n";
  cout << "  of predators and prey are solved using midpoint_fixed().\n";

  t = new double[n+1];
  pout = new double[(n+1)*m];

  midpoint_fixed ( predator_prey_deriv, tspan, p0, n, m, t, pout );
//
//  Create the data file.
//
  data_filename = header + "_data.txt";
  data.open ( data_filename.c_str ( ) );

  for ( i = 0; i < n; i++ )
  {
    data << "  " << t[i]
         << "  " << pout[0+i*m]
         << "  " << pout[1+i*m] << "\n";
  }

  data.close ( );

  cout << "\n";
  cout << "  predator_prey_midpoint: data stored in '" << data_filename << "'.\n";
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
  command << "set output '" << header << ".png'\n";
  command << "set xlabel '<-- PREDATOR -->'\n";
  command << "set ylabel '<-- PREY -->'\n";
  command << "set title 'midpoint: predator prey'\n";
  command << "set grid\n";
  command << "set style data lines\n";
  command << "plot '" << data_filename << "' using 2:3 with lines lw 3\n";
  command << "quit\n";

  command.close ( );

  cout << "  predator_prey_midpoint: plot commands stored in '" << command_filename << "'.\n";

  delete [] pout;
  delete [] t;

  return;
}
