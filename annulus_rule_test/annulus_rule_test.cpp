# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "annulus_rule.hpp"

int main ( );
void annulus_area_test ( );
void annulus_rule_compute_test ( );
void annulus_rule_monomial_test ( double center[2], double r1, double r2 );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for ANNULUS_RULE_TEST.
//
//  Discussion:
//
//    ANNULUS_RULE_TEST tests ANNULUS_RULE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2018
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
  cout << "ANNULUS_RULE_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test ANNULUS_RULE.\n";

  annulus_area_test ( );
  annulus_rule_compute_test ( );

  center[0] = 0.0;
  center[1] = 0.0;
  r1 = 0.0;
  r2 = 1.0;
  annulus_rule_monomial_test ( center, r1, r2 );

  center[0] = 1.0;
  center[1] = 0.0;
  r1 = 0.5;
  r2 = 1.0;
  annulus_rule_monomial_test ( center, r1, r2 );

  center[0] = 1.0;
  center[1] = 0.0;
  r1 = 0.0;
  r2 = 1.0;
  annulus_rule_monomial_test ( center, r1, r2 );
//
//  Terminate.
//
  cout << "\n";
  cout << "ANNULUS_RULE_TEST\n";
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
//    08 July 2018
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
         << "  " << setw(9) << r1
         << "  " << setw(9) << r2;
    area = annulus_area ( center, r1, r2 );
    cout << "  " << setw(9) << area << "\n";
    delete [] data;
  }

  return;
}
//****************************************************************************80

void annulus_rule_compute_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ANNULUS_RULE_COMPUTE_TEST tests ANNULUS_RULE_COMPUTE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2018
//
//  Author:
//
//    John Burkardt
//
{
  double center[2];
  int n;
  int nr;
  int nt;
  double r1;
  double r2;
  double *w;
  double *x;
  double *y;

  cout << "\n";
  cout << "ANNULUS_RULE_COMPUTE_TEST:\n";
  cout << "  Test ANNULUS_RULE_COMPUTE.\n";

  center[0] = 0.0;
  center[1] = 0.0;
  r1 = 0.5;
  r2 = 1.0;
  nr = 3;
  nt = 12;
  n = nt * nr;

  w = new double[n];
  x = new double[n];
  y = new double[n];

  annulus_rule_compute ( center, r1, r2, nr, nt, w, x, y );

  r8vec3_print ( n, w, x, y, "  W, X, Y for annulus quadrature:" );

  delete [] w;
  delete [] x;
  delete [] y;
//
//  Terminate.
//
  cout << "\n";
  cout << "ANNULUS_RULE_COMPUTE_TEST:\n";
  cout << "  Normal end of execution.\n";

  return;
}
//****************************************************************************80

void annulus_rule_monomial_test ( double center[2], double r1, double r2 )

//****************************************************************************80
//
//  Purpose:
//
//    ANNULUS_RULE_MONOMIAL_TEST estimates monomial integrals using quadrature.
//
//  Discussion:
//
//    If CENTER=(0,0) and R1 = 0 and R2 = 1, then we can compare exact values.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double CENTER[2], the coordinates of the center.
//
//    Input, double R1, R2, the inner and outer radii of the annulus.
//    0.0 <= R1 <= R2.
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
  int nr;
  int nt;
  double result;
  double *value;
  double *w;
  double *x;
  double *xy;
  double *y;

  cout << "\n";
  cout << "ANNULUS_RULE_MONOMIAL_TEST\n";
  cout << "  ANNULUS_RULE_COMPUTE supplies a quadrature rule for the annulus\n";
  cout << "  with center (" << center[0]
       << "," << center[1]
       << "), inner radius " << r1
       << ", outer radius " << r2 << "\n";

  cout << "\n";
  cout << "    NR    NT           1               X^2            Y^2";
  cout << "             X^4             X^2Y^2          Y^4             X^6\n";
  cout << "\n";

  nr = 4;

  while ( nr <= 64 )
  {
    nt = 4 * nr;
    n = nr * nt;

    w = new double[n];
    x = new double[n];
    xy = new double[2*n];
    y = new double[n];

    annulus_rule_compute ( center, r1, r2, nr, nt, w, x, y );

    for ( j = 0; j < n; j++ )
    {
      xy[0+2*j] = x[j];
      xy[1+2*j] = y[j];
    }

    cout << "  " << setw(4) << nr
         << "  " << setw(4) << nt;
    for ( j = 0; j < 7; j++ )
    {
      for ( i = 0; i < 2; i++ )
      {
        e[i] = e_test[i+j*2];
      }
      value = monomial_value ( 2, n, e, xy );

      result = r8vec_dot_product ( n, w, value );
      cout << "  " << setw(14) << result;

      delete  value;
    }
    cout << "\n";

    delete [] w;
    delete [] x;
    delete [] xy;
    delete [] y;

    nr = 2 * nr;
  }

  if (
    center[0] == 0.0 &&
    center[1] == 0.0 &&
    r1 == 0.0 &&
    r2 == 1.0 )
  {
    cout << "\n";
    cout << "     Exact  ";
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
