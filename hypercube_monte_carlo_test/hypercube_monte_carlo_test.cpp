# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "hypercube_monte_carlo.hpp"

int main ( );
void test01 ( );
void test02 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for HYPERCUBE_MONTE_CARLO_TEST.
//
//  Discussion:
//
//    HYPERCUBE_MONTE_CARLO_TEST tests the HYPERCUBE_MONTE_CARLO library.
//    
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 January 2014
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "HYPERCUBE_MONTE_CARLO_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the HYPERCUBE_MONTE_CARLO library.\n";

  test01 ( );
  test02 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "HYPERCUBE_MONTE_CARLO_TEST\n";
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
//    TEST01 estimates integrals over the unit hypercube in 3D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 January 2014
//
//  Author:
//
//    John Burkardt
//
{
  int e[3];
  int e_test[3*10] = {
    0, 0, 0, 
    1, 0, 0, 
    0, 1, 0, 
    0, 0, 1, 
    2, 0, 0, 
    1, 1, 0, 
    1, 0, 1, 
    0, 2, 0, 
    0, 1, 1, 
    0, 0, 2 };
  double exact;
  int i;
  int j;
  int m = 3;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Use HYPERCUBE01_SAMPLE to estimate integrals\n";
  cout << "  over the interior of the unit hypercube in 3D.\n";

  seed = 123456789;

  cout << "\n";
  cout << "         N";
  cout << "        1";
  cout << "               X";
  cout << "               Y ";
  cout << "              Z";
  cout << "               X^2";
  cout << "              XY";
  cout << "             XZ";
  cout << "              Y^2";
  cout << "             YZ";
  cout << "               Z^2\n";
  cout << "\n";

  n = 1;

  while ( n <= 65536 )
  {
    x = hypercube01_sample ( m, n, seed );
    cout << "  " << setw(8) << n;
    for ( j = 0; j < 10; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+j*m];
      }

      value = monomial_value ( m, n, e, x );

      result = hypercube01_volume ( m ) * r8vec_sum ( n, value ) / ( double ) ( n );
      cout << "  " << setw(14) << result;
      delete [] value;
    }
    cout << "\n";

    delete [] x;

    n = 2 * n;
  }

  cout << "\n";
  cout << "     Exact";
  for ( j = 0; j < 10; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      e[i] = e_test[i+j*m];
    }
    exact = hypercube01_monomial_integral ( m, e );
    cout << "  " << setw(14) << exact;
  }
  cout << "\n";

  return;
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 estimates integrals over the unit hypercube in 6D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 January 2014
//
//  Author:
//
//    John Burkardt
//
{
  int e[6];
  int e_test[6*7] = {
    0, 0, 0, 0, 0, 0, 
    1, 0, 0, 0, 0, 0, 
    0, 2, 0, 0, 0, 0, 
    0, 2, 2, 0, 0, 0, 
    0, 0, 0, 4, 0, 0, 
    2, 0, 0, 0, 2, 2, 
    0, 0, 0, 0, 0, 6 };
  double exact;
  int i;
  int j;
  int m = 6;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Use HYPERCUBE01_SAMPLE to estimate integrals\n";
  cout << "  over the interior of the unit hypercube in 6D.\n";

  seed = 123456789;

  cout << "\n";
  cout << "         N";
  cout << "        1      ";
  cout << "        U      ";
  cout << "         V^2   ";
  cout << "         V^2W^2";
  cout << "         X^4   ";
  cout << "         Y^2Z^2";
  cout << "         Z^6\n";
  cout << "\n";

  n = 1;

  while ( n <= 65536 )
  {
    x = hypercube01_sample ( m, n, seed );
    cout << "  " << setw(8) << n;
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+j*m];
      }

      value = monomial_value ( m, n, e, x );

      result = hypercube01_volume ( m ) * r8vec_sum ( n, value ) / ( double ) ( n );
      cout << "  " << setw(14) << result;
      delete [] value;
    }
    cout << "\n";

    delete [] x;

    n = 2 * n;
  }

  cout << "\n";
  cout << "     Exact";
  for ( j = 0; j < 7; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      e[i] = e_test[i+j*m];
    }
    exact = hypercube01_monomial_integral ( m, e );
    cout << "  " << setw(14) << exact;
  }
  cout << "\n";

  return;
}
