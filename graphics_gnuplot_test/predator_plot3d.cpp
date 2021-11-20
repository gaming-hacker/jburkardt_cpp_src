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
//    MAIN is the main program for PREDATOR_PLOT3D.
//
//  Discussion:
//
//    PREDATOR_PLOT3D computes and plots some predator/prey data.
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
  string command_filename = "predator_commands.txt";
  ofstream command;
  string data_filename = "predator_data.txt";
  ofstream data;
  double dt;
  string plot_filename = "predator_plot3d.png";
  int i;
  int n;
  double *pred;
  double *prey;
  double *t;

  timestamp ( );
  cout << "\n";
  cout << "PREDATOR_PLOT3D:\n";
  cout << "  C++ version\n";
  cout << "  Define (X,Y,Z) data on a 3D curve.\n";
  cout << "  Create corresponding GNUPLOT input files.\n";
//
//  Set number of points in plot.
//
  n = 1001;
//
//  Allocate arrays.
//
  t = new double[n];
  pred = new double[n];
  prey = new double[n];
//
//  Define the data.
//
  dt = ( 5.0 - 0.0 ) / ( double ) ( n - 1 );

  t[0] = 0.0;
  prey[0] = 5000.0;
  pred[0] = 100.0;

  for ( i = 1; i < n; i++ )
  {
    t[i] = t[i-1] + dt;
    prey[i] = prey[i-1] + dt * (    2.0 * prey[i-1] - 0.001 * pred[i-1] * prey[i-1] );
    pred[i] = pred[i-1] + dt * ( - 10.0 * pred[i-1] + 0.002 * pred[i-1] * prey[i-1] );
  }
//
//  Create the data file.
//
  data.open ( data_filename.c_str ( ) );

  for ( i = 0; i < n; i++ )
  {
    data << "  " << t[i]
         << "  " << prey[i]
         << "  " << pred[i] << "\n";
  }

  data.close ( );

  cout << "\n";
  cout << "  PREDATOR_PLOT3D: data stored in '" << data_filename << "'.\n";
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
  command << "set zlabel '<-- TIME -->'\n";
  command << "set title 'Predator/prey evolution'\n";
  command << "set grid\n";
  command << "set style data lines\n";
  command << "splot '" << data_filename << "' using 2:3:1 with lines\n";
  command << "quit\n";

  command.close ( );

  cout << "  PREDATOR_PLOT3D: plot commands stored in '" << command_filename << "'.\n";
//
//  Free memory.
//
  delete [] pred;
  delete [] prey;
  delete [] t;
//
//  Terminate.
//
  cout << "\n";
  cout << "PREDATOR_PLOT3D:\n";
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
