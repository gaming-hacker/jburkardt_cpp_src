# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "square_integrals.hpp"

int main ( );
void square01_monomial_integral_test ( );
void squaresym_monomial_integral_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for SQUARE_INTEGRALS_TEST.
//
//  Discussion:
//
//    SQUARE_INTEGRALS_TEST tests the SQUARE_INTEGRALS library.
//    
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 February 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "SQUARE_INTEGRALS_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the SQUARE_INTEGRALS library.\n";

  square01_monomial_integral_test ( );
  squaresym_monomial_integral_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "SQUARE_INTEGRALS_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void square01_monomial_integral_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SQUARE01_MONOMIAL_INTEGRAL_TEST tests SQUARE01_MONOMIAL_INTEGRAL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 February 2018
//
//  Author:
//
//    John Burkardt
//
{
  int *e;
  double error;
  double exact;
  int m = 2;
  int n = 4192;
  double result;
  int seed;
  int test;
  int test_num = 20;
  double *value;
  double *x;

  cout << "\n";
  cout << "SQUARE01_MONOMIAL_INTEGRAL_TEST\n";
  cout << "  SQUARE01_MONOMIAL_INTEGRAL returns the exact integral\n";
  cout << "  of a monomial over the interior of the unit square in 2D.\n";
  cout << "  Compare exact and estimated values.\n";
//
//  Get sample points.
//
  seed = 123456789;
  x = square01_sample ( n, seed );
  cout << "\n";
  cout << "  Number of sample points is " << n << "\n";
//
//  Randomly choose exponents.
//
  cout << "\n";
  cout << "  Ex  Ey     MC-Estimate           Exact      Error\n";
  cout << "\n";

  for ( test = 1; test <= test_num; test++ )
  {
    e = i4vec_uniform_ab_new ( m, 0, 7, seed );

    value = monomial_value ( m, n, e, x );

    result = square01_area ( ) * r8vec_sum ( n, value ) / ( double ) ( n );
    exact = square01_monomial_integral ( e );
    error = fabs ( result - exact );

    cout << "  " << setw(2) << e[0]
         << "  " << setw(2) << e[1]
         << "  " << setw(14) << result
         << "  " << setw(14) << exact
         << "  " << setw(14) << error << "\n";

    delete [] value;
  }

  delete [] x;

  return;
}
//****************************************************************************80

void squaresym_monomial_integral_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SQUARESYM_MONOMIAL_INTEGRAL_TEST tests SQUARESYM_MONOMIAL_INTEGRAL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 February 2018
//
//  Author:
//
//    John Burkardt
//
{
  int *e;
  double error;
  double exact;
  int m = 2;
  int n = 4192;
  double result;
  int seed;
  int test;
  int test_num = 20;
  double *value;
  double *x;

  cout << "\n";
  cout << "SQUARESYM_MONOMIAL_INTEGRAL_TEST\n";
  cout << "  SQUARESYM_MONOMIAL_INTEGRAL returns the exact integral\n";
  cout << "  of a monomial over the interior of the symmetric unit square in 2D.\n";
  cout << "  Compare exact and estimated values.\n";
//
//  Get sample points.
//
  seed = 123456789;
  x = squaresym_sample ( n, seed );
  cout << "\n";
  cout << "  Number of sample points is " << n << "\n";
//
//  Randomly choose exponents.
//
  cout << "\n";
  cout << "  Ex  Ey     MC-Estimate           Exact      Error\n";
  cout << "\n";

  for ( test = 1; test <= test_num; test++ )
  {
    e = i4vec_uniform_ab_new ( m, 0, 7, seed );

    value = monomial_value ( m, n, e, x );

    result = squaresym_area ( ) * r8vec_sum ( n, value ) / ( double ) ( n );
    exact = squaresym_monomial_integral ( e );
    error = fabs ( result - exact );

    cout << "  " << setw(2) << e[0]
         << "  " << setw(2) << e[1]
         << "  " << setw(14) << result
         << "  " << setw(14) << exact
         << "  " << setw(14) << error << "\n";

    delete [] value;
  }

  delete [] x;

  return;
}
