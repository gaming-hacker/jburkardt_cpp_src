# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "walker_sample.hpp"

int main ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for WALKER_SAMPLE_TEST.
//
//  Discussion:
//
//    WALKER_SAMPLE_TEST tests WALKER_SAMPLE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 February 2016
//
//  Author:
//
//    John Burkardt
//
{ 
  timestamp ( );
  cout << "\n";
  cout << "WALKER_SAMPLE_TEST:\n";
  cout << "  C++ version.\n";
  cout << "  Test the WALKER_SAMPLE library.\n";
  
  walker_sampler_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "WALKER_SAMPLE_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
