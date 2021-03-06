# include <cmath>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

int main ( );
void sor_test01 ( double w );

# include "sor.hpp"

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for SOR_TEST.
//
//  Discussion:
//
//    SOR_TEST tests the SOR library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2011
//
//  Author:
//
//    John Burkardt
//
{
  double w;

  timestamp ( );
  cout << "\n";
  cout << "SOR_TEST\n";
  cout << "  C++ version.\n";
  cout << "  Test the SOR library.\n";

  w = 1.5;
  sor_test01 ( w );
//
//  Terminate.
//
  cout << "\n";
  cout << "SOR_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void sor_test01 ( double w )

//****************************************************************************80
//
//  Purpose:
//
//    SOR_TEST01 tests SOR1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double W, the relaxation factor.
//    0 < W < 2 is required.
//
{
  double *a;
  double *b;
  string command_filename;
  ofstream command;
  string data_filename;
  ofstream data;
  int i;
  int it;
  int it_num;
  int j;
  double *m_plot;
  double *ml_plot;
  int n;
  double *r_plot;
  double *rl_plot;
  double *s_plot;
  double t;
  double *x;
  double *x_exact;
  double *x_new;
  double *x_plot;

  cout << "\n";
  cout << "SOR1_TEST01:\n";
  cout << "  Relaxation parameter W = " << w << "\n";

  it_num = 2000;
  n = 33;
//
//  Set the matrix A.
//
  a = dif2 ( n, n );
//
//  Determine the right hand side vector B.
//
  x_exact = new double[n];
  for ( i = 0; i < n; i++ )
  {
    t = ( double ) i / ( double ) ( n - 1 );
    x_exact[i] = exp ( t ) * ( t - 1 ) * t;
//   x_exact[i] = ( double ) ( i + 1 );
  }
  b = r8mat_mv ( n, n, a, x_exact );
//
//  Set the initial estimate for the solution.
//
  x = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x[i] = 0.0;
  }
//
//  Allocate plot arrays.
//
  m_plot = new double[it_num+1];
  r_plot = new double[it_num+1];
  s_plot = new double[it_num+1];
  x_plot = new double[n*(it_num+1)];
//
//  Initialize plot arrays.
//
  r_plot[0] = r8mat_residual_norm ( n, n, a, x, b );
  m_plot[0] = 1.0;
  for ( i = 0; i < n; i++ )
  {
    x_plot[i+0*n] = x[i];
  }
  for ( j = 0; j <= it_num; j++ )
  {
    s_plot[j] = ( double ) j;
  }
//
//  Carry out the iteration.
//
  for ( it = 1; it <= it_num; it++ )
  {
    x_new = sor1 ( n, a, b, x, w );

    r_plot[it] = r8mat_residual_norm ( n, n, a, x_new, b );
//
//  Compute the average point motion.
//
    m_plot[it] = r8vec_diff_norm_squared ( n, x, x_new ) / ( double ) n;
//
//  Update the solution
//
    r8vec_copy ( n, x_new, x );

    for ( i = 0; i < n; i++ )
    {
      x_plot[i+0*n] = x[i];
    }

    delete [] x_new;
  }
    r8vec_print ( n, x, "Solution" );
//
//  Plot the residual.
//
  rl_plot = new double[it_num+1];
  for ( j = 0; j <= it_num; j++ )
  {
    rl_plot[j] = log ( r_plot[j] );
  }
//
//  Create the data file.
//
  data_filename = "residual_data.txt";

  data.open ( data_filename.c_str ( ) );

  for ( j = 0; j <= it_num; j++ )
  {
    data << j << "  " 
         << rl_plot[j] << "\n";
  }
  data.close ( );

  cout << " \n";
  cout << "  Data stored in \"" << data_filename << "\".\n";
//
//  Create the command file.
//
  command_filename = "residual_commands.txt";

  command.open ( command_filename.c_str ( ) );

  command << "# residual_commands.txt\n";
  command << "#\n";
  command << "# Usage:\n";
  command << "#  gnuplot < residual_commands.txt\n";
  command << "#\n";
  command << "set term png\n";
  command << "set output 'residual.png'\n";
  command << "set style data lines\n";
  command << "set xlabel 'Iteration'\n";
  command << "set ylabel 'Residual'\n";
  command << "set title 'Log(Residual) over Iterations'\n";
  command << "set grid\n";
  command << "plot 'residual_data.txt' using 1:2 lw 2\n";
  command << "quit\n";

  command.close ( );

  cout << "  Plot commands stored in \"" << command_filename << "\".\n";
//
//  Plot the average point motion.
//
  ml_plot = new double[it_num+1];
  for ( j = 0; j <= it_num; j++ )
  {
    ml_plot[j] = log ( m_plot[j] );
  }
//
//  Create the data file.
//
  data_filename = "motion_data.txt";

  data.open ( data_filename.c_str ( ) );

  for ( j = 0; j <= it_num; j++ )
  {
    data << j << "  " 
         << ml_plot[j] << "\n";
  }
  data.close ( );

  cout << " \n";
  cout << "  Data stored in \"" << data_filename << "\".\n";
//
//  Create the command file.
//
  command_filename = "motion_commands.txt";

  command.open ( command_filename.c_str ( ) );

  command << "# motion_commands.txt\n";
  command << "#\n";
  command << "# Usage:\n";
  command << "#  gnuplot < motion_commands.txt\n";
  command << "#\n";
  command << "set term png\n";
  command << "set output 'motion.png'\n";
  command << "set style data lines\n";
  command << "set xlabel 'Iteration'\n";
  command << "set ylabel 'Motion'\n";
  command << "set title 'Log(Motion) over Iterations'\n";
  command << "set grid\n";
  command << "plot 'motion_data.txt' using 1:2 lw 2\n";
  command << "quit\n";

  command.close ( );

  cout << "  Plot commands stored in \"" << command_filename << "\".\n";

  delete [] a;
  delete [] b;
  delete [] m_plot;
  delete [] ml_plot;
  delete [] r_plot;
  delete [] rl_plot;
  delete [] s_plot;
  delete [] x;
  delete [] x_exact;
  delete [] x_plot;

  return;
}
