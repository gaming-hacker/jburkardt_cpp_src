# include <cstdlib>
# include <ctime>
# include <iostream>
# include <string>

using namespace std;

# include "byname.hpp"

int main ( );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    byname_test() tests byname().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 May 2021
//
//  Author:
//
//    John Burkardt
//
{
  double alpha;
  double beta;
  double gamma;
  double value_in;
  double *pd = NULL;

  timestamp ( );
  cout << "\n";
  cout << "byname_test():\n";
  cout << "  Test byname(), with the interface:\n";
  cout << "    value_out = byname(action,name,value_in)\n";
/*
  May need a null pointer!
*/
  cout << "\n";
  cout << "    byname ( 'print', '*', NULL );\n";
  byname ( "print", "*", pd );

  value_in = 1.0;
  cout << "    alpha = byname ( 'set', 'alpha', 1.0 );\n";
  alpha = byname ( "set", "alpha", &value_in );

  value_in = 99.0;
  cout << "    beta = byname ( 'set', 'beta', 99 );\n";
  beta = byname ( "set", "beta", &value_in );

  value_in = alpha + beta;
  cout << "    byname ( 'set', 'gamma', alpha + beta );\n";
  byname ( "set", "gamma", &value_in );

  cout << "    byname ( 'print', '*' );\n";
  byname ( "print", "*", pd );

  cout << "    gamma = byname ( 'get', 'gamma' );\n";
  gamma = byname ( "get", "gamma", pd );

  value_in = 2.0 * gamma;
  cout << "    byname ( 'set', 'gamma', 2.0*gamma );\n";
  byname ( "set", "gamma", &value_in );

  cout << "    byname ( 'print', 'gamma' );\n";
  byname ( "print", "gamma", pd );

  cout << "    byname ( 'print', '*' );\n";
  byname ( "print", "*", pd );

  cout << "    byname ( 'reset', NULL, NULL );\n";
  byname ( "reset", "", pd );

  cout << "    byname ( 'print', '*', NULL );\n";
  byname ( "print", "*", pd );
//
//  Terminate.
//
  cout << "\n";
  cout << "byname_test():\n";
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

