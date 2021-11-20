# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "disk_monte_carlo.hpp"

int main ( );
void disk_area_test ( );
void disk_sample_test ( double center[2], double r );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for DISK_MONTE_CARLO_TEST.
//
//  Discussion:
//
//    DISK_MONTE_CARLO_TEST tests the DISK_MONTE_CARLO library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2018
//
//  Author:
//
//    John Burkardt
//
{
  double center[2];
  double r;

  timestamp ( );
  cout << "\n";
  cout << "DISK_MONTE_CARLO_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the DISK_MONTE_CARLO library.\n";

  disk_area_test ( );

  center[0] = 0.0;
  center[1] = 0.0;
  r = 1.0;
  disk_sample_test ( center, r );

  center[0] = 1.0;
  center[1] = 0.0;
  r = 1.0;
  disk_sample_test ( center, r );

  center[0] = 1.0;
  center[1] = 2.0;
  r = 3.0;
  disk_sample_test ( center, r );
//
//  Terminate.
//
  cout << "\n";
  cout << "DISK_MONTE_CARLO_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void disk_area_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DISK_AREA_TEST test DISK_AREA.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2018
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
  double r;
  int seed;

  cout << "\n";
  cout << "DISK_AREA_TEST\n";
  cout << "  DISK_AREA computes the area of a disk with\n";
  cout << "  center = (CX,CY) and radius R.\n";
  
  seed = 123456789;

  cout << "\n";
  cout << "  (   CX        CY     )    R          Area\n";
  cout << "\n";

  for ( i = 1; i <= 10; i++ )
  {
    data = r8vec_uniform_01_new ( 3, seed );
    center[0] = 10.0 * data[0] - 5.0;
    center[1] = 10.0 * data[1] - 5.0;
    r = data[2];
    area = disk_area ( center, r );
    cout << "  (" << setw(9) << center[0]
         << ", " << setw(9) << center[1]
         << ")  " << setw(9) << r
         << "  " << area << "\n";
    delete [] data;
  }

  return;
}
//****************************************************************************80

void disk_sample_test ( double center[2], double r )

//****************************************************************************80
//
//  Purpose:
//
//    DISK_SAMPLE_TEST uses DISK_SAMPLE to estimate integrals.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 July 2018
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
  cout << "DISK_SAMPLE_TEST\n";
  cout << "  Use DISK_SAMPLE to estimate integrals in the unit disk\n";
  cout << "  with center (" << center[0]
       << "," << center[1]
       << ") and radius " << r << "\n";

  seed = 123456789;

  cout << "\n";
  cout << "         N        1              X^2             Y^2";
  cout << "             X^4             X^2Y^2           Y^4             X^6\n";
  cout << "\n";

  n = 1;

  while ( n <= 65536 )
  {
    x = disk_sample ( center, r, n, seed );

    cout << "  " << setw(8) << n;
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        e[i] = e_test[i+j*2];
      }
      value = monomial_value ( 2, n, e, x );

      result = disk_area ( center, r ) * r8vec_sum ( n, value ) / ( double ) ( n );
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
    r == 1.0 )
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
