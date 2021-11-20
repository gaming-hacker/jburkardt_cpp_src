# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "sphere_monte_carlo.hpp"

int main ( );
void test01 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for SPHERE_MONTE_CARLO_TEST.
//
//  Discussion:
//
//    SPHERE_MONTE_CARLO_TEST tests the SPHERE_MONTE_CARLO library.
//    
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 September 2010
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "SPHERE_MONTE_CARLO_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the SPHERE_MONTE_CARLO library.\n";

  test01 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "SPHERE_MONTE_CARLO_TEST\n";
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
//    TEST01 uses SPHERE01_SAMPLE with an increasing number of points.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 January 2014
//
//  Author:
//
//    John Burkardt
//
{
  int e[3];
  int e_test[3*7] = {
    0, 0, 0, 
    2, 0, 0, 
    0, 2, 0, 
    0, 0, 2, 
    4, 0, 0, 
    2, 2, 0, 
    0, 0, 4 };
  double exact;
  int i;
  int j;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Use SPHERE01_SAMPLE to estimate integrals on the unit sphere surface.\n";

  seed = 123456789;

  cout << "\n";
  cout << "         N        1              X^2             Y^2";
  cout << "             Z^2             X^4            X^2Y^2          Z^4\n";
  cout << "\n";

  n = 1;

  while ( n <= 65536 )
  {
    x = sphere01_sample ( n, seed );
    cout << "  " << setw(8) << n;
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 3; i++ )
      {
        e[i] = e_test[i+j*3];
      }

      value = monomial_value ( 3, n, e, x );

      result = sphere01_area ( ) * r8vec_sum ( n, value ) / ( double ) ( n );
      cout << "  " << setprecision(10) << setw(14) << result;

      delete [] value;
    }
    cout << "\n";

    delete [] x;

    n = 2 * n;
  }

  cout << "\n";
  cout << "  " << "   Exact";
  for ( j = 0; j < 7; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      e[i] = e_test[i+j*3];
    }
    exact = sphere01_monomial_integral ( e );
    cout << "  " << setprecision(10) << setw(14) << exact;
  }
  cout << "\n";

  return;
}
