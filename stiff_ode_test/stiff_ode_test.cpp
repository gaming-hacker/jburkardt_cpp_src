# include <cmath>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "stiff_ode.hpp"

int main ( );
void stiff_euler_test ( int n );
void stiff_euler_backward_test ( int n );
void stiff_midpoint_test ( int n );
void plot2 ( int n1, double t1[], double y1[], int n2, double t2[], 
  double y2[], string header, string title );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_ode_test tests stiff_ode.
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
  double lambda;
  int n;
  double t0;
  double y0;

  timestamp ( );
  cout << "\n";
  cout << "stiff_ode_test\n";
  cout << "  C++ version\n";
  cout << "  Test stiff_ode using euler, euler_backward, midpoint.\n";

  stiff_parameters ( lambda, t0, y0 );

  cout << "\n";
  cout << "  Parameter values:\n";
  cout << "    lambda = " << lambda << "\n";
  cout << "    t0     = " << t0 << "\n";
  cout << "    y0     = " << y0 << "\n";

  n = 27;

  stiff_euler_test ( n );
  stiff_euler_backward_test ( n );
  stiff_midpoint_test ( n );
//
//  Terminate.
//
  cout << "\n";
  cout << "stiff_ode_test\n";
  cout << "  Normal end of execution.\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void stiff_euler_test ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_euler_test() tests stiff_euler().
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
{
  const int n2 = 101;
  double t0 = 0.0;
  double *t1;
  double *t2;
  double tstop = 1.0;
  double *y1;
  double *y2;

  cout << "\n";
  cout << "stiff_euler_test\n";
  cout << "  Solve stiff ODE using the Euler method.\n";

  t1 = new double[n+1];
  y1 = new double[n+1];
  stiff_euler ( n, t1, y1 );

  t2 = r8vec_linspace_new ( n2, t0, tstop );
  y2 = stiff_exact ( n2, t2 );

  plot2 ( n+1, t1, y1, n2, t2, y2, "stiff_euler", 
    "Stiff ODE: euler method" );

  delete [] t1;
  delete [] t2;
  delete [] y1;
  delete [] y2;

  return;
}
//****************************************************************************80

void stiff_euler_backward_test ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_euler_backward_test tests stiff_euler_backward().
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
{
  const int n2 = 101;
  double t0 = 0.0;
  double *t1;
  double *t2;
  double tstop = 1.0;
  double *y1;
  double *y2;

  cout << "\n";
  cout << "stiff_backward_euler_test\n";
  cout << "  Solve stiff ODE using the backward Euler method.\n";

  t1 = new double[n+1];
  y1 = new double[n+1];
  stiff_euler_backward ( n, t1, y1 );

  t2 = r8vec_linspace_new ( n2, t0, tstop );
  y2 = stiff_exact ( n2, t2 );

  plot2 ( n+1, t1, y1, n2, t2, y2, "stiff_euler_backward",
    "Stiff ODE: backward euler method" );

  delete [] t1;
  delete [] t2;
  delete [] y1;
  delete [] y2;

  return;
}
//****************************************************************************80

void stiff_midpoint_test ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    stiff_midpoint_test() tests stiff_midpoint().
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
{
  const int n2 = 101;
  double t0 = 0.0;
  double *t1;
  double *t2;
  double tstop = 1.0;
  double *y1;
  double *y2;

  cout << "\n";
  cout << "stiff_midpoint_test\n";
  cout << "  Solve stiff ODE using the midpoint method.\n";

  t1 = new double[n+1];
  y1 = new double[n+1];
  stiff_midpoint ( n, t1, y1 );

  t2 = r8vec_linspace_new ( n2, t0, tstop );
  y2 = stiff_exact ( n2, t2 );

  plot2 ( n+1, t1, y1, n2, t2, y2, "stiff_midpoint", 
    "Stiff ODE: midpoint method" );

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
//    plot2 plots two curves together.
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
