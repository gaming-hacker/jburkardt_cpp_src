# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "collatz_recursive.hpp"

void test01 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for COLLATZ_RECURSIVE_TEST.
//
//  Discussion:
//
//    COLLATZ_RECURSIVE_TEST tests the COLLATZ_RECURSIVE library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2012
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "COLLATZ_RECURSIVE_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the COLLATZ_RECURSIVE library.\n";

  test01 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "COLLATZ_RECURSIVE_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//*****************************************************************************/

void test01 ( )

//*****************************************************************************/
//
//  Purpose:
//
//    TEST01 tests COLLATZ_PATH;
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2012
//
//  Author:
//
//    John Burkardt
//
{
  int n;
  int n_test[5] = { 7, 8, 9, 10, 600 };
  int test;
  int test_num = 5;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  COLLATZ_PATH prints the members of a Collatz path.\n";

  for ( test = 0; test < test_num; test++ )
  {
    n = n_test[test];
    cout << "\n";
    cout << "  " << n << " is the starting point.\n";
    collatz_path ( n );
  }

  return;
}
