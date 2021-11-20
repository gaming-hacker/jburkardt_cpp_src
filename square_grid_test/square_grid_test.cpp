# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

using namespace std;

# include "square_grid.hpp"

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
//    MAIN is the main program for SQUARE_GRID_TEST.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "SQUARE_GRID_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the SQUARE_GRID library.\n";

  test01 ( );
  test02 ( );
  test03 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "SQUARE_GRID_TEST:\n";
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
//    TEST01 tests SQUARE_GRID using the same parameters for all dimensions.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
  double a[2] = { -1.0, -1.0 };
  double b[2] = { +1.0, +1.0 };
  int c[2] = { 1, 1 };
  int i;
  int n;
  int ns[2] = { 3, 3 };
  double *x;

  n = ns[0] * ns[1];

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Create a grid using SQUARE_GRID.\n";
  cout << "  Use the same parameters in every dimension.\n";
  cout << "  Number of grid points N = " << n << "\n";
  cout << "\n";
  cout << "     I    NS     C      A         B\n";
  cout << "\n";
  for ( i = 0; i < 2; i++ )
  {
    cout 
      << setw(6) << i << "  "
      << setw(4) << ns[i] << "  "
      << setw(4) << c[i] << "  "
      << setw(8) << a[i] << "  "
      << setw(8) << b[i] << "\n";
  }

  x = square_grid ( n, ns, a, b, c );
  r8mat_transpose_print ( 2, n, x, "  Grid points:" );
  delete [] x;

  return;
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 uses a different number of points in each coordinate.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
  double a[2] = { 0.0, 0.0 };
  double b[2] = { 1.0, 1.0  };
  int c[2] = { 2, 2 };
  int i;
  int n;
  int ns[2] = { 4, 2 };
  double *x;

  n = ns[0] * ns[1];

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Create a grid using SQUARE_GRID.\n";
  cout << "  se a different number of points in each dimension..\n";
  cout << "  Number of grid points N = " << n << "\n";
  cout << "\n";
  cout << "     I    NS     C      A         B\n";
  cout << "\n";
  for ( i = 0; i < 2; i++ )
  {
    cout 
      << setw(6) << i << "  "
      << setw(4) << ns[i] << "  "
      << setw(4) << c[i] << "  "
      << setw(8) << a[i] << "  "
      << setw(8) << b[i] << "\n";
  }

  x = square_grid ( n, ns, a, b, c );
  r8mat_transpose_print ( 2, n, x, "  Grid points:" );
  delete [] x;

  return;
}
//****************************************************************************80

void test03 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST03 uses a square with different sizes in each dimension.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
  double a[2] = {   0.0, -2.0 };
  double b[2] = { +10.0, +2.0 };
  int c[2] = { 3, 4 };
  int i;
  int n;
  int ns[2] = { 3, 3 };
  double *x;

  n = ns[0] * ns[1];

  cout << "\n";
  cout << "TEST03\n";
  cout << "  Create a grid using SQUARE_GRID.\n";
  cout << "  Use a different physical size in each dimension.\n";
  cout << "  Number of grid points N = " << n << "\n";
  cout << "\n";
  cout << "     I    NS     C      A         B\n";
  cout << "\n";
  for ( i = 0; i < 2; i++ )
  {
    cout 
      << setw(6) << i << "  "
      << setw(4) << ns[i] << "  "
      << setw(4) << c[i] << "  "
      << setw(8) << a[i] << "  "
      << setw(8) << b[i] << "\n";
  }

  x = square_grid ( n, ns, a, b, c );
  r8mat_transpose_print ( 2, n, x, "  Grid points:" );
  delete [] x;

  return;
}
