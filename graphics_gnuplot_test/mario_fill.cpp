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
//    MAIN is the main program for MARIO_FILL.
//
//  Discussion:
//
//    MARIO_FILL creates an image of Mario using colored squares.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 April 2018
//
//  Author:
//
//    John Burkardt
//
{
  string color;
  int color_index[16*13] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 5, 5, 5, 0, 0, 6, 
     0, 0, 0, 6, 6, 6, 0, 0, 2, 2, 5, 5, 5, 0, 6, 6, 
     0, 2, 6, 5, 5, 6, 0, 2, 2, 2, 2, 5, 3, 3, 6, 6, 
     2, 2, 6, 6, 6, 5, 5, 2, 2, 2, 3, 3, 3, 3, 6, 6, 
     2, 2, 6, 5, 6, 5, 5, 3, 3, 3, 4, 3, 3, 3, 0, 0, 
     2, 2, 5, 5, 5, 5, 5, 2, 2, 3, 3, 3, 3, 0, 0, 0, 
     2, 2, 5, 5, 5, 5, 5, 2, 2, 3, 3, 3, 3, 0, 0, 0, 
     2, 2, 5, 5, 5, 5, 5, 2, 3, 3, 4, 3, 3, 3, 0, 0, 
     2, 2, 1, 1, 5, 1, 5, 2, 2, 2, 3, 3, 3, 3, 6, 6, 
     0, 2, 5, 5, 1, 1, 5, 0, 2, 2, 2, 5, 3, 3, 6, 6, 
     0, 2, 0, 5, 5, 1, 5, 0, 2, 2, 5, 5, 5, 0, 6, 6, 
     0, 2, 0, 5, 5, 1, 0, 0, 0, 2, 5, 5, 5, 0, 0, 6, 
     0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  string command_filename = "mario_commands.txt";
  ofstream command_unit;
  int i;
  int i_reverse;
  int j;
  int k;
  int m = 16;
  int n = 13;
  string plot_filename = "mario_fill.png";

  timestamp ( );
  cout << "\n";
  cout << "MARIO_FILL\n";
  cout << "  C++ version\n";
  cout << "  Create a GNUPLOT input file that will draw a\n";
  cout << "  picture of Mario, using colored squares.\n";
//
//  Create the command file.
//
  command_unit.open ( command_filename.c_str ( ) );

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output '" << plot_filename << "'\n";
  command_unit << "set title 'MARIO'\n";
//
//  Trying to get a plot TRUE SQUARES was exasperatingly awkward.
//
  command_unit << "set xrange [ -1.5 : 14.5 ]\n";
  command_unit << "set yrange [ 0 : 16 ]\n";
  command_unit << "set size square\n";
  command_unit << "unset border\n";
  command_unit << "unset tics\n";
  command_unit << "set nokey\n";

  k = 0;
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      k = k + 1;

      if ( color_index[i+j*m] == 0 )
      {
        color = "white";
      }
      else if ( color_index[i+j*m] == 1 )
      {
        color = "black";
      }
      else if ( color_index[i+j*m] == 2 )
      {
        color = "red";
      }
      else if ( color_index[i+j*m] == 3 )
      {
        color = "blue";
      }
      else if ( color_index[i+j*m] == 4 )
      {
        color = "yellow";
      }
//
//  The next color should be 'blanchedalmond' but stoopid GNUPLOT won't take
//  it as a string.'
//
      else if ( color_index[i+j*m] == 5 )
      {
        color = "#FFEBCD";
      }
      else if ( color_index[i+j*m] == 6 )
      {
        color = "brown";
      }

      i_reverse = m - 1 - i;
      command_unit << "set object " << k 
        << " rect from " << j 
        << ", " << i_reverse
        << " to " << j + 1
        << ", " << i_reverse + 1 << " back\n";
      command_unit << "set object " << k 
        << " rect fc rgb '" << color 
        << "' fillstyle solid 1.0\n";
    }
  }
//
//  If you don't have some bogus PLOT command here, all the previous work
//  results in no plot all.  Way to go, gnuplot!
//  Here, we plot the function y = -1, which is out of range and won't show up.
//
  command_unit << "plot -1 with lines\n";

  command_unit.close ( );

  cout << "  Created command file '" << command_filename << "'\n";
//
//  Terminate.
//
  cout << "\n";
  cout << "MARIO_FILL:\n";
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
