# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

int main ( );
double *r8vec_linspace_new ( int n, double a, double b );
void timestamp ( );

/******************************************************************************/

int main ( )

/******************************************************************************/
//
//  Purpose:
//
//    MAIN is the main program for CORKSCREW_PLOT3D.
//
//  Discussion:
//
//    CORKSCREW_PLOT3D creates a plot of a 3D curve resembling a corkscrew.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 April 2018
//
//  Author:
//
//    John Burkardt
//
{
  string command_filename = "corkscrew_commands.txt";
  ofstream command;
  string data_filename = "corkscrew_data.txt";
  ofstream data;
  string plot_filename = "corkscrew_plot3d.png";
  int i;
  int n;
  double *r;
  const double r8_pi = 3.141592653589793;
  double *theta;
  double theta_max;
  double theta_min;
  double *x;
  double *y;
  double *z;

  timestamp ( );
  cout << "\n";
  cout << "CORKSCREW_PLOT3D:\n";
  cout << "  C++ version\n";
  cout << "  Define (X,Y,Z) data on a 3D curve.\n";
  cout << "  Create corresponding GNUPLOT input files.\n";
//
//  Set number of points in plot.
//
  n = 101;
//
//  Allocate arrays.
//
  r = new double[n];
  x = new double[n];
  y = new double[n];
//
//  Define the data.
//
  z = r8vec_linspace_new ( n, -2.0, 2.0 );
  theta_min = - 6.0 * r8_pi;
  theta_max = + 6.0 * r8_pi;
  theta = r8vec_linspace_new ( n, theta_min, theta_max );
  for ( i = 0; i < n; i++ )
  {
    r[i] = 1.0 + z[i] * z[i];
    x[i] = r[i] * sin ( theta[i] );
    y[i] = r[i] * cos ( theta[i] );
  }
//
//  Create the data file.
//
  data.open ( data_filename.c_str ( ) );

  for ( i = 0; i < n; i++ )
  {
    data << "  " << x[i]
         << "  " << y[i]
         << "  " << z[i] << "\n";
  }

  data.close ( );

  cout << "\n";
  cout << "  CORKSCREW_PLOT3D: data stored in '" << data_filename << "'.\n";
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
  command << "set xlabel 'X'\n";
  command << "set ylabel 'Y'\n";
  command << "set zlabel 'Z'\n";
  command << "set title 'Corkscrew curve'\n";
  command << "set grid\n";
  command << "set style data lines\n";
  command << "splot '" << data_filename << "' using 1:2:3 with lines\n";
  command << "quit\n";

  command.close ( );

  cout << "  CORKSCREW_PLOT3D: plot commands stored in '" << command_filename << "'.\n";
//
//  Free memory.
//
  delete [] r;
  delete [] theta;
  delete [] x;
  delete [] y;
  delete [] z;
//
//  Terminate.
//
  cout << "\n";
  cout << "CORKSCREW_PLOT3D:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

double *r8vec_linspace_new ( int n, double a_first, double a_last )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_LINSPACE_NEW creates a vector of linearly spaced values.
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
