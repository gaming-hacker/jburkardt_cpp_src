# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

# include "simplex_coordinates.hpp"

int main ( );
void simplex_coordinates1_test ( int n );
void simplex_coordinates2_test ( int n );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for SIMPLEX_COORDINATED_TEST.
//
//  Discussion:
//
//    SIMPLEX_COORDINATES_TEST tests the SIMPLEX_COORDINATES library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 September 2010
//
//  Author:
//
//    John Burkardt
//
{
  int n;

  timestamp ( );
  cout << "\n";
  cout << "SIMPLEX_COORDINATES_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the SIMPLEX_COORDINATES library.\n";

  n = 3;
  simplex_coordinates1_test ( n );
  simplex_coordinates2_test ( n );

  n = 4;
  simplex_coordinates1_test ( n );
  simplex_coordinates2_test ( n );
//
//  Terminate.
//
  cout << "\n";
  cout << "SIMPLEX_COORDINATES_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void simplex_coordinates1_test ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    SIMPLEX_COORDINATES1_TEST tests SIMPLEX_COORDINATES1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 September 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the spatial dimension.
//
{
  int i;
  int j;
  int k;
  double side;
  double volume;
  double volume2;
  double *x;
  double *xtx;

  cout << "\n";
  cout << "SIMPLEX_COORDINATES1_TEST\n";
  cout << "  Call SIMPLEX_COORDINATES1\n";

  x = simplex_coordinates1 ( n );

  r8mat_transpose_print ( n, n + 1, x, "  Simplex vertex coordinates:" );

  side = 0.0;
  for ( i = 0; i < n; i++ )
  {
    side = side + pow ( x[i+0*n] - x[i+1*n], 2 );
  }
  side = sqrt ( side );

  volume = simplex_volume ( n, x );

  volume2 = sqrt ( ( double ) ( n + 1 ) ) / r8_factorial ( n ) 
    / sqrt ( pow ( 2.0, n ) ) * pow ( side, n );

  cout << "\n";
  cout << "  Side length =     " << side << "\n";
  cout << "  Volume =          " << volume << "\n";
  cout << "  Expected volume = " << volume2 << "\n";

  xtx = new double[(n+1)*(n+1)];

  for ( j = 0; j < n + 1; j++ )
  {
    for ( i = 0; i < n + 1; i++ )
    {
      xtx[i+j*(n+1)] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        xtx[i+j*(n+1)] = xtx[i+j*(n+1)] + x[k+i*n] * x[k+j*n];
      }
    }
  }

  r8mat_transpose_print ( n + 1, n + 1, xtx, "  Dot product matrix:" );

  delete [] x;
  delete [] xtx;

  return;
}
//****************************************************************************80

void simplex_coordinates2_test ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    SIMPLEX_COORDINATES2_TEST tests SIMPLEX_COORDINATES2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 September 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the spatial dimension.
//
{
  int i;
  int j;
  int k;
  double side;
  double volume;
  double volume2;
  double *x;
  double *xtx;

  cout << "\n";
  cout << "SIMPLEX_COORDINATES2_TEST\n";
  cout << "  Call SIMPLEX_COORDINATES2\n";

  x = simplex_coordinates2 ( n );

  r8mat_transpose_print ( n, n + 1, x, "  Simplex vertex coordinates:" );

  side = 0.0;
  for ( i = 0; i < n; i++ )
  {
    side = side + pow ( x[i+0*n] - x[i+1*n], 2 );
  }
  side = sqrt ( side );

  volume = simplex_volume ( n, x );

  volume2 = sqrt ( ( double ) ( n + 1 ) ) / r8_factorial ( n ) 
    / sqrt ( pow ( 2.0, n ) ) * pow ( side, n );

  cout << "\n";
  cout << "  Side length =     " << side << "\n";
  cout << "  Volume =          " << volume << "\n";
  cout << "  Expected volume = " << volume2 << "\n";

  xtx = new double[(n+1)*(n+1)];

  for ( j = 0; j < n + 1; j++ )
  {
    for ( i = 0; i < n + 1; i++ )
    {
      xtx[i+j*(n+1)] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        xtx[i+j*(n+1)] = xtx[i+j*(n+1)] + x[k+i*n] * x[k+j*n];
      }
    }
  }

  r8mat_transpose_print ( n + 1, n + 1, xtx, "  Dot product matrix:" );

  delete [] x;
  delete [] xtx;

  return;
}
