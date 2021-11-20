# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

# include "latin_center.hpp"

int main ( );
void test00 ( int *seed );
void test01 ( int *seed );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for LATIN_CENTER_TEST.
//
//  Discussion:
//
//    LATIN_CENTER_TEST tests the LATIN_CENTER library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int seed;
  int seed_save;

  timestamp ( );
  cout << "\n";
  cout << "LATIN_CENTER_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the LATIN_CENTER library.\n";

  test00 ( &seed );

  seed_save = seed;
  test01 ( &seed );

  cout << "\n";
  cout << "LATIN_CENTER_TEST:\n";
  cout << "  Repeat TEST01, but with different seed from first run.\n";

  test01 ( &seed );

  cout << "\n";
  cout << "LATIN_CENTER_TEST:\n";
  cout << "  Repeat TEST01 with same seed as first run.\n";

  seed = seed_save;
  test01 ( &seed );
//
//  Terminate.
//
  cout << "\n";
  cout << "LATIN_CENTER_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test00 ( int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    TEST00 tests GET_SEED, RANDOM_INITIALIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  cout << "\n";
  cout << "TEST00\n";
  cout << "  GET_SEED returns a seed for the random number\n";
  cout << "  generator, based on the current time.\n";

  *seed = get_seed ( );

  cout << "\n";
  cout << "  GET_SEED returns SEED = " << *seed << "\n";

  return;
}
//****************************************************************************80

void test01 ( int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tests LATIN_CENTER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 March 2007
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 2
# define POINT_NUM 10

  int i;
  int j;
  int k;
  int kk;
  double x[DIM_NUM*POINT_NUM];

  cout << "\n";
  cout << "TEST01\n";
  cout << "  LATIN_CENTER chooses a Latin cell arrangement,\n";
  cout << "  and returns the centers of those cells.\n";
  cout << "\n";
  cout << "  Spatial dimension = " << DIM_NUM << "\n";
  cout << "  Number of points =  " << POINT_NUM << "\n";
  cout << "  Initial seed for UNIFORM = " << *seed << "\n";

  latin_center ( DIM_NUM, POINT_NUM, seed, x );

  cout << "\n";
  cout << "  The Latin centers:\n";
  cout << "\n";

  k = 0;
  for ( j = 0; j < POINT_NUM; j++ )
  {
    kk = k;
    for ( i = 0; i < DIM_NUM; i++ )
    {
      cout << setw(10) << x[kk] << "  ";
      kk = kk + POINT_NUM;
    }
    cout << "\n";
    k = k + 1;
  }

  return;
# undef POINT_NUM
# undef DIM_NUM
}
