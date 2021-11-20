# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cstring>

using namespace std;

# include "weekday.hpp"

int main ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for WEEKDAY_TEST.
//
//  Discussion:
//
//    WEEKDAY_TEST tests the WEEKDAY library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2017
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "WEEKDAY_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the WEEKDAY library.\n";

  jed_to_weekday_test ( );
  ymd_to_weekday_common_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "WEEKDAY_TEST:\n";
  cout << "  Noraml end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
