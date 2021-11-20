# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "midpoint_explicit.hpp"

int main ( );
double *predator_prey_deriv ( double t, double rf[] );
void predator_prey_midpoint_explicit_test ( double tspan[2], double p0[2], int n );
double *stiff_deriv ( double t, double y[] );
double *stiff_exact ( int n, double t[] );
void stiff_midpoint_explicit_test ( double tspan[2], double y0[1], int n );
void plot2 ( int n1, double t1[], double y1[], int n2, double t2[], 
  double y2[], string header, string title );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    midpoint_explicit_test() tests midpoint_explicit.
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
{
  int n;
  double tspan[2];
  double y0[2];

  timestamp ( );
  cout << "\n";
  cout << "midpoint_explicit_test:\n";
  cout << "  C++ version\n";
  cout << "  Test midpoint_explicit() on several ODE's.\n";

  tspan[0] = 0.0;
  tspan[1] = 5.0;
  y0[0] = 5000.0;
  y0[1] = 100.0;
  n = 200;
  predator_prey_midpoint_explicit_test ( tspan, y0, n );

  tspan[0] = 0.0;
  tspan[1] = 1.0;
  y0[0] = 0.0;
  n = 27;
  stiff_midpoint_explicit_test ( tspan, y0, n );
//
//  Terminate.
//
  cout << "\n";
  cout << "midpoint_explicit_test:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return ( 0 );
}
//****************************************************************************80

double *predator_prey_deriv ( double t, double rf[] )

//****************************************************************************80
//
//  Purpose:
//
//    predator_prey_deriv() evaluates the right hand side of the system.
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
//    double T: the current time.
//
//    double RF[2]: the current solution variables, rabbits and foxes.
//
//  Output:
//
//    double PREDATOR_PREY_DERIV[2]: the right hand side of the 2 ODE's.
//
{
  double *drfdt;

  drfdt = new double[2];

  drfdt[0] =    2.0 * rf[0] - 0.001 * rf[0] * rf[1];
  drfdt[1] = - 10.0 * rf[1] + 0.002 * rf[0] * rf[1];

  return drfdt;
}
//****************************************************************************80

void predator_prey_midpoint_explicit_test ( double tspan[2], double p0[2], int n )

//****************************************************************************80
//
//  Purpose:
//
//    predator_prey_midpoint_explicit_test() tests predator_prey_midpoint_explicit().
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
//    06 April 2021
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
  string header = "predator_prey_midpoint_explicit";
  int i;
  const int m = 2;
  double *pout;
  double *t;

  cout << "\n";
  cout << "predator_prey_midpoint_test\n";
  cout << "  A pair of ordinary differential equations for a population\n";
  cout << "  of predators and prey are solved using midpoint_explicit().\n";

  t = new double[n+1];
  pout = new double[(n+1)*m];

  midpoint_explicit ( predator_prey_deriv, tspan, p0, n, m, t, pout );
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
  cout << "  predator_prey_midpoint_explicit_test: data stored in '" << data_filename << "'.\n";
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
  command << "set title 'Predator prey: midpoint explicit'\n";
  command << "set grid\n";
  command << "set style data lines\n";
  command << "plot '" << data_filename << "' using 2:3 with lines lw 3\n";
  command << "quit\n";

  command.close ( );

  cout << "  predator_prey_midpoint_explicit_test: plot commands stored in '" << command_filename << "'.\n";

  delete [] pout;
  delete [] t;

  return;
}
//****************************************************************************80

double *stiff_deriv ( double t, double y[] )

//****************************************************************************80
//
//  stiff_deriv() evaluates the right hand side of the stiff ODE.
//
//  Discussion:
//
//    y' = 50 * ( cos(t) - y )
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
  double *dydt;

  dydt = new double[1];

  dydt[0] = 50.0 * ( cos ( t ) - y[0] );

  return dydt;
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
//    y' = 50 * ( cos(t) - y )
//    y(0) = 0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 April 2020
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
  double *y;

  y = new double[n];

  for ( i = 0; i < n; i++ )
  {
    y[i] = 50.0 * ( sin ( t[i] ) + 50.0 * cos ( t[i] )
      - 50.0 * exp ( - 50.0 * t[i] ) ) / 2501.0;
  }

  return y;
}
//****************************************************************************80

void stiff_midpoint_explicit_test ( double tspan[2], double y0[1], int n )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_midpoint_explicit_test() tests stiff_midpoint_explicit().
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
//    double TSPAN(2): the first and last times.
//
//    double Y0: the initial condition.
//
//    int N: the number of steps to take.
//
{
  int m = 1;
  const int n2 = 101;
  double *t1;
  double *t2;
  double *y1;
  double *y2;

  cout << "\n";
  cout << "stiff_midpoint_explicit_test\n";
  cout << "  Solve stiff ODE using the midpoint_explicit method.\n";

  t1 = new double[n+1];
  y1 = new double[n+1];
  midpoint_explicit ( stiff_deriv, tspan, y0, n, m, t1, y1 );

  t2 = r8vec_linspace_new ( n2, tspan[0], tspan[1] );
  y2 = stiff_exact ( n2, t2 );

  plot2 ( n+1, t1, y1, n2, t2, y2, "stiff_midpoint_explicit", 
    "Stiff ODE: midpoint explicit method" );

  delete [] t1;
  delete [] t2;
  delete [] y1;
  delete [] y2;

  return;
}
//****************************************************************************80

void plot2 ( int n1, double t1[], double y1[], int n2, double t2[], 
  double y2[], string header, string title )

//****************************************************************************80
//
//  Purpose:
//
//    plot2() plots two curves together.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 April 2020
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N1: the size of the first data set.
//
//    double T1(N1), Y1(N1), the first dataset.
//
//    int N2: the size of the second data set.
//
//    double T2(N2), Y2(N2), the secod dataset.
//
//    string HEADER: an identifier for the data.
//
//    string TITLE: a title to appear in the plot.
//
{
  string command_filename;
  ofstream command;
  string data1_filename;
  string data2_filename;
  ofstream data;
  int i;
//
//  Create the data files.
//
  data1_filename = header + "_data1.txt";
  data.open ( data1_filename.c_str ( ) );
  for ( i = 0; i < n1; i++ )
  {
    data << "  " << t1[i] << "  " << y1[i] << "\n";
  }
  data.close ( );

  data2_filename = header + "_data2.txt";
  data.open ( data2_filename.c_str ( ) );
  for ( i = 0; i < n2; i++ )
  {
    data << "  " << t2[i] << "  " << y2[i] << "\n";
  }
  data.close ( );

  cout << "\n";
  cout << "  plot2: data stored in '" << data1_filename
       << "' and '" << data2_filename << "'\n";
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
  command << "set xlabel '<-- T -->'\n";
  command << "set ylabel '<-- Y(T) -->'\n";
  command << "set title '" << title << "'\n";
  command << "set grid\n";
  command << "set style data lines\n";
  command << "plot '" << data1_filename << "' using 1:2 with lines lw 3 lt rgb 'red',\\\n";
  command << "     '" << data2_filename << "' using 1:2 with lines lw 3 lt rgb 'blue'\n";
  command << "quit\n";

  command.close ( );

  cout << "  plot2: plot commands stored in '" << command_filename << "'.\n";

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

