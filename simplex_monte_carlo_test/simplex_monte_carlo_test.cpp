# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "simplex_monte_carlo.hpp"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for SIMPLEX_MONTE_CARLO_TEST.
//
//  Discussion:
//
//    SIMPLEX_MONTE_CARLO_TEST tests the SIMPLEX_MONTE_CARLO library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2014
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "SIMPLEX_MONTE_CARLO_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the SIMPLEX_MONTE_CARLO library.\n";

  test01 ( );
  test02 ( );
  test03 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "SIMPLEX_MONTE_CARLO_TEST\n";
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
//    TEST01 uses SIMPLEX_UNIT_SAMPLE to estimate integrals in 3D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2014
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
  int i;
  int j;
  const int m = 3;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Use SIMPLEX_UNIT_SAMPLE for a Monte Carlo estimate of an\n";
  cout << "  integral over the interior of the unit simplex in 3D.\n";

  seed = 123456789;

  cout << "\n";
  cout << "         N        1               X               Y ";
  cout << "              Z               X^2              XY             XZ";
  cout << "              Y^2             YZ               Z^2\n";
  cout << "\n";

  n = 1;

  while ( n <= 65536 )
  {
    x = simplex_unit_sample ( m, n, seed );

    cout << "  " << setw(8) << n;
    for ( j = 0; j < 10; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+j*m];
      }
      value = monomial_value ( m, n, e, x );

      result = simplex_unit_volume ( m ) * r8vec_sum ( n, value ) 
        / ( double ) ( n );

      cout << "  " << setw(14) << result;

      delete [] value;
    }

    cout << "\n";

    n = 2 * n;

    delete [] x;
  }

  cout << "\n";
  cout << "     Exact";

  for ( j = 0; j < 10; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      e[i] = e_test[i+j*m];
    }

    result = simplex_unit_monomial_integral ( m, e );
    cout << "  " << setw(14) << result;
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
//    TEST02 uses SIMPLEX_UNIT_SAMPLE to estimate integrals in 6D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
// 
//    16 January 2014
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
  int i;
  int j;
  const int m = 6;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Use SIMPLEX_UNIT_SAMPLE for a Monte Carlo estimate of an\n";
  cout << "  integral over the interior of the unit simplex in 6D.\n";

  seed = 123456789;

  cout << "\n";
  cout << "         N";
  cout << "        1      ";
  cout << "        U      ";
  cout << "         V^2    ";
  cout << "         V^2W^2 ";
  cout << "         X^4    ";
  cout << "         Y^2Z^2 ";
  cout << "         Z^6\n";
  cout << "\n";

  n = 1;

  while ( n <= 65536 )
  {
    x = simplex_unit_sample ( m, n, seed );

    cout << "  " << setw(8) << n;
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+j*m];
      }
      value = monomial_value ( m, n, e, x );

      result = simplex_unit_volume ( m ) * r8vec_sum ( n, value ) 
        / ( double ) ( n );

      cout << "  " << setw(14) << result;

      delete [] value;
    }

    cout << "\n";

    n = 2 * n;

    delete [] x;
  }

  cout << "\n";
  cout << "     Exact";

  for ( j = 0; j < 7; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      e[i] = e_test[i+j*m];
    }

    result = simplex_unit_monomial_integral ( m, e );
    cout << "  " << setw(14) << result;
  }

  cout << "\n";

  return;
}
//****************************************************************************80

void test03 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST03 uses SIMPLEX_GENERAL_SAMPLE to estimate integrals in 3D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 March 2017
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
  int i;
  int j;
  const int m = 3;
  int n;
  double result;
  int seed;
  double t[3*4] = {
    1.0, 0.0, 0.0, 
    2.0, 0.0, 0.0, 
    1.0, 2.0, 0.0, 
    1.0, 0.0, 3.0 };
  double *value;
  double *x;

  cout << "\n";
  cout << "TEST03\n";
  cout << "  SIMPLEX_GENERAL_SAMPLE computes a Monte Carlo estimate of an\n";
  cout << "  integral over the interior of a general simplex in 3D.\n";

  cout << "\n";
  cout << "  Simplex vertices:\n";
  cout << "\n";
  for ( j = 0; j < 4; j++ )
  {
    for ( i = 0; i < 3; i++ )
    {
      cout << "  " << setw(14) << t[i+j*3];
    }
    cout << "\n";
  }

  seed = 123456789;

  cout << "\n";
  cout << "         N        1               X               Y ";
  cout << "              Z               X^2              XY             XZ";
  cout << "              Y^2             YZ               Z^2\n";
  cout << "\n";

  n = 1;

  while ( n <= 65536 )
  {
    x = simplex_general_sample ( m, n, t, seed );

    cout << "  " << setw(8) << n;
    for ( j = 0; j < 10; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        e[i] = e_test[i+j*m];
      }
      value = monomial_value ( m, n, e, x );

      result = simplex_general_volume ( m, t ) * r8vec_sum ( n, value ) 
        / ( double ) ( n );

      cout << "  " << setw(14) << result;

      delete [] value;
    }

    cout << "\n";

    n = 2 * n;

    delete [] x;
  }

  return;
}
