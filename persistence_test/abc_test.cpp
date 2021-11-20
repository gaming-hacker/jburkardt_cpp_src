# include <cstdlib>
# include <ctime>
# include <iostream>

using namespace std;

# include "abc.hpp"

int main ( );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    abc_test() tests abc().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 May 2021
//
//  Author:
//
//    John Burkardt
//
{
  double a_in;
  double a_out;
  double b_in;
  double b_out;
  double c_in;
  double c_out;
  double *p = NULL;

  timestamp ( );
  cout << "\n";
  cout << "abc_test():\n";
  cout << "  C++ version\n";
  cout << "  Test abc(), with the interface:\n";
  cout << "  abc(a_in,b_in,c_in,a_out,b_out,c_out)\n";

  abc ( p, p, p, &a_out, &b_out, &c_out );
  cout << "\n";
  cout << "    abc ( NULL, NULL, NULL"
       << ", a_out = " << a_out 
       << ", b_out = " << b_out 
       << ", c_out = " << c_out << " )\n";

  a_in = a_out;
  b_in = 19;
  c_in = c_out;
  abc ( &a_in, &b_in, &c_in, p, p, p );
  cout << "\n";
  cout << "    abc "
       << "( a_in = " << a_in 
       << ", b_in = " << b_in 
       << ", c_in = " << c_in
       << ", NULL, NULL, NULL )\n";

  abc ( p, p, p, &a_out, &b_out, &c_out );
  cout << "\n";
  cout << "    abc ( NULL, NULL, NULL"
       << "( a_out = " << a_out 
       << ", b_out = " << b_out 
       << ", c_out = " << c_out << " )\n";

  a_in = 50;
  b_in = 60;
  c_in = 70;
  abc ( &a_in, &b_in, &c_in, &a_out, &b_out, &c_out );
  cout << "\n";
  cout << "    abc"
       << "( a_in = " << a_in 
       << ", b_in = " << b_in 
       << ", c_in = " << c_in
       << ", a_out = " << a_out 
       << ", b_out = " << b_out 
       << ", c_out = " << c_out << " )\n";

  abc ( p, p, p, &a_out, &b_out, &c_out );
  cout << "    abc ( NULL, NULL, NULL" 
       << ", a_out = " << a_out 
       << ", b_out = " << b_out 
       << ", c_out = " << c_out << " )\n";
//
//  Terminate.
//
  cout << "\n";
  cout << "abc_test():\n";
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

