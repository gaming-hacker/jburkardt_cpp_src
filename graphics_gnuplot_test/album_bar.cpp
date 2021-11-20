# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

int main ( );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for ALBUM_BAR.
//
//  Discussion:
//
//    ALBUM_BAR creates a bar plot of data for music album sales over time.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  string command_filename = "album_commands.txt";
  ofstream command;
  string data_filename = "album_data.txt";
  string plot_filename = "album_bar.png";

  timestamp ( );
  cout << "\n";
  cout << "ALBUM_BAR:\n";
  cout << "  C++ version\n";
  cout << "  Create a bar plot of music album sales over time.\n";
  cout << "  Create corresponding GNUPLOT input files.\n";
//
//  Create the command file.
//
  command.open ( command_filename.c_str ( ) );

  command << "# "<< command_filename << "\n";
  command << "#\n";
  command << "# Usage:\n";
  command << "#  gnuplot < " << command_filename << "\n";
  command << "#\n";
  command << "set term png\n";
  command << "set output '" << plot_filename << "'\n";
  command << "set xlabel '<--- Year --->'\n";
  command << "set ylabel '<--- Millions --->'\n";
  command << "set title 'Music album sales, all formats'\n";
  command << "set grid\n";
  command << "set yrange [0:550]\n";
  command << "set boxwidth 0.8\n";
  command << "set style fill solid\n";
  command << "plot '" << data_filename << "' using 1:2 with boxes lc rgb 'red'\n";
  command << "quit\n";

  command.close ( );

  cout << "\n";
  cout << "ALBUM_BAR:\n";
  cout << "  Plot commands stored in \"" << command_filename << "\".\n";
//
//  Terminate.
//
  cout << "\n";
  cout << "ALBUM_BAR:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
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
