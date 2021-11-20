# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "annulus_monte_carlo.hpp"

int main ( );
void annulus_area_test ( );
void annulus_sample_test ( double center[2], double r1, double r2 );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for ANNULUS_MONTE_CARLO_TEST.
//
//  Discussion:
//
//    ANNULUS_MONTE_CARLO_TEST tests ANNULUS_MONTE_CARLO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2018
//
//  Author:
//
//    John Burkardt
//
{
  double center[2];
  double r1;
  double r2;

  timestamp ( );
  cout << "\n";
  cout << "ANNULUS_MONTE_CARLO_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test ANNULUS_MONTE_CARLO.\n";

  annulus_area_test ( );

  center[0] = 0.0;
  center[1] = 0.0;
  r1 = 0.0;
  r2 = 1.0;
  annulus_sample_test ( center, r1, r2 );

  center[0] = 1.0;
  center[1] = 0.0;
  r1 = 0.5;
  r2 = 1.0;
  annulus_sample_test ( center, r1, r2 );

  center[0] = 1.0;
  center[1] = 0.0;
  r1 = 0.0;
  r2 = 1.0;
  annulus_sample_test ( center, r1, r2 );
//
//  Terminate.
//
  cout << "\n";
  cout << "ANNULUS_MONTE_CARLO_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void annulus_area_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ANNULUS_AREA_TEST test ANNULUS_AREA.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2018
//
//  Author:
//
//    John Burkardt
//
{
  double area;
  double center[2];
  double *data;
  int i;
  double r1;
  double r2;
  int seed;

  cout << "\n";
  cout << "ANNULUS_AREA_TEST\n";
  cout << "  ANNULUS_AREA computes the area of an annulus with\n";
  cout << "  center = (CX,CY) and inner radius R1, outer radius R2.\n";
  
  seed = 123456789;

  cout << "\n";
  cout << "  (   CX        CY     )    R1        R2          Area\n";
  cout << "\n";

  for ( i = 1; i <= 10; i++ )
  {
    data = r8vec_uniform_01_new ( 4, seed );
    center[0] = 10.0 * data[0] - 5.0;
    center[1] = 10.0 * data[1] - 5.0;
    r1 = data[2];
    r2 = r1 + data[3];
    cout << "  (" << setw(9) << center[0]
         << "," << setw(9) << center[1]
         << ")  " << setw(9) << r1
         << "  " << setw(9) << r2;
    area = annulus_area ( center, r1, r2 );
    cout << "  " << setw(9) << area << "\n";
    delete [] data;
  }

  return;
}
//****************************************************************************80

void annulus_sample_test ( double center[2], double r1, double r2 )

//****************************************************************************80
//
//  Purpose:
//
//    ANNULUS_SAMPLE_TEST uses ANNULUS_SAMPLE to estimate integrals.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 July 2018
//
//  Author:
//
//    John Burkardt
//
{
  int e[2];
  int e_test[2*7] = {
    0, 0, 
    2, 0, 
    0, 2, 
    4, 0, 
    2, 2, 
    0, 4, 
    6, 0 };
  int i;
  int j;
  int n;
  double result;
  int seed;
  double *value;
  double *x;

  cout << "\n";
  cout << "ANNULUS_SAMPLE_TEST\n";
  cout << "  Use ANNULUS_SAMPLE to estimate integrals in the annulus\n";
  cout << "  with center (" << center[0] 
      << "," << center[1] 
      << "), inner radius " << r1 
      << ", outer radius " << r2 << ".\n", 

  seed = 123456789;

  cout << "\n";
  cout << "         N        1              X^2             Y^2";
  cout << "             X^4             X^2Y^2           Y^4             X^6\n";
  cout << "\n";

  n = 1;

  while ( n <= 65536 )
  {
    x = annulus_sample ( center, r1, r2, n, seed );

    cout << "  " << setw(8) << n;
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        e[i] = e_test[i+j*2];
      }
      value = monomial_value ( 2, n, e, x );

      result = annulus_area ( center, r1, r2 ) 
        * r8vec_sum ( n, value ) / ( double ) ( n );
      cout << "  " << setw(14) << result;

      delete [] value;
    }
    cout << "\n";

    delete [] x;

    n = 2 * n;
  }

  if (
    center[0] == 0.0 &&
    center[1] == 0.0 &&
    r1 == 0.0 &&
    r2 == 1.0 )
  {
    cout << "\n";
    cout << "     Exact";
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
       e[i] = e_test[i+j*2];
     }
     result = disk01_monomial_integral ( e );
      cout << "  " << setw(14) << result;
    }
    cout << "\n";
  }

  return;
}
