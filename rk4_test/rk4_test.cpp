# include <cmath>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "rk4.hpp"

int main ( );
void rk4_predator_test ( );
void predator_deriv ( double t, double u[], double f[] );
void predator_phase_plot ( int n, int m, double t[], double y[] );

//****************************************************************************80

int main ( ) 

//****************************************************************************80
//
//  Purpose:
// 
//    MAIN is the main program for RK4_TEST.
//
//  Discussion:
//
//    RK4_TEST tests the RK4 library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 April 2020
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "RK4_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test rk4().\n";

  rk4_predator_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "RK4_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void rk4_predator_test ( ) 

//****************************************************************************80
//
//  Purpose:
 //
//    rk4_predator_test tests RK4 on the predator prey ODE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 April 2020
//
//  Author:
//
//    John Burkardt
//
{
  int m;
  int n = 1000;
  double *t;
  double tspan[2];
  double *y;
  double *y0;

  m = 2;
  n = 1000;

  t = new double[n+1];
  y = new double[(n+1)*m];
  y0 = new double[m];

  cout << "\n";
  cout << "rk4_predator_test\n";
  cout << "  Use rk4() to solve the predator prey ODE.\n";

  tspan[0] = 0.0;
  tspan[1] = 5.0;
  y0[0] = 5000.0;
  y0[1] = 100.0;
  
  rk4 ( predator_deriv, tspan, y0, n, m, t, y );

  predator_phase_plot ( n, m, t, y );
//
//  Free memory.
//
  delete [] t;
  delete [] y;
  delete [] y0;

  return;
}
//****************************************************************************80

void predator_deriv ( double t, double y[], double f[] )

//****************************************************************************80
//
//  Purpose:
//
//    predator_deriv returns the right hand side of the predator ODE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 April 2020
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double T, the current time.
//
//    double Y[M], the current solution value.
//
//  Output:
//
//    double F[M], the value of the derivative, dU/dT.
//
{
  double dfdt;
  double drdt;
  double fox;
  double rab;
  
  rab = y[0];
  fox = y[1];

  drdt =   2.0 * rab - 0.001 * rab * fox;
  dfdt = -10.0 * fox + 0.002 * rab * fox;

  f[0] = drdt;
  f[1] = dfdt;
  
  return;
}
//****************************************************************************80

void predator_phase_plot ( int n, int m, double t[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    predator_phase_plot makes a phase plot of the results.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 April 2020
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int n: the number of steps to take.
//
//    int m: the number of variables.
//
//    double t[n+1], y[(n+1)*m]: the times and solution values.
//
{
  string command_filename = "predator_commands.txt";
  ofstream command;
  string data_filename = "predator_data.txt";
  ofstream data;
  int j;
  string plot_filename = "predator_plot3d.png";

  cout << "\n";
  cout << "predator_phase_plot:\n";
  cout << "  Write command and data files that can be used\n";
  cout << "  by gnuplot for a predator-prey phase plot.\n";
//
//  Create the data file.
//
  data.open ( data_filename.c_str ( ) );

  for ( j = 0; j <= n; j++ )
  {
    data << "  " << t[j]
         << "  " << y[0+j*m]
         << "  " << y[1+j*m] << "\n";
  }

  data.close ( );

  cout << "\n";
  cout << "  predator_phase_plot: data stored in '"
       << data_filename << "'\n";
//
//  Create the command file.
//
  command.open ( command_filename.c_str ( ) );

  command << "# " << command_filename << "\n";
  command << "#\n";
  command << "# Usage:\n";
  command << "#  gnuplot < " << command_filename << "\n";
  command << "#\n";
  command << "set term png\n";
  command << "set output '" << plot_filename << "'\n";
  command << "set xlabel '<-- PREDATOR -->'\n";
  command << "set ylabel '<-- PREY -->'\n";
  command << "set title 'Predator_prey solved by rk4()'\n";
  command << "set grid\n";
  command << "set style data lines\n";
  command << "plot '" << data_filename << "' using 2:3 with lines\n";
  command << "quit\n";

  command.close ( );

  cout << "  predator_phase_plot: plot commands stored in '"
       << command_filename << "'\n";
 
  return;
}
