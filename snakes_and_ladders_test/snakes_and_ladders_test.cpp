# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "snakes_and_ladders.hpp"

int main ( );
void test01 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for snakes_and_ladders_test.
//
//  Discussion:
//
//    snakes_and_ladders_test tests snakes_and_ladders.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 September 2014
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "snakes_and_ladders_test\n";
  cout << "  C++ version\n";
  cout << "  Test snakes_and_ladders.\n";

  test01 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "snakes_and_ladders_test\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test01 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tests SPY_GE for the SNAKES matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 September 2014
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  string header;
  int m;
  int n;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  SNAKES sets up the snakes and ladders matrix.\n";
  cout << "  SPY_GE generates a sparsity plot for a matrix stored\n";
  cout << "  in general (GE) format.\n";

  m = 101;
  n = 101;
  header = "snakes_and_ladders";
  a = snakes ( );

  spy_ge ( m, n, a, header );

  delete [] a;

  return;
}

