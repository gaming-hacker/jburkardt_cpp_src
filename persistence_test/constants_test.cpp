# include <cstdlib>
# include <ctime>
# include <iostream>

using namespace std;

# include "constants.hpp"

int main ( );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    constants_test() tests constants().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 May 2021
//
//  Author:
//
//    John Burkardt
//
{
  double c;
  double g;
  double h;

  timestamp ( );
  cout << "\n";
  cout << "constants_test():\n";
  cout << "  C++ version\n";
  cout << "  Test constants(), with the interface:\n";
  cout << "    [g,c,h] = constants()\n";

  constants ( g, c, h );
  cout << "\n";
  cout << "    constants ( " 
                 << g << ", "
                 << c << ", "
                 << h << " )" << "\n";
//
//  Terminate.
//
  cout << "\n";
  cout << "constants_test():\n";
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
 
