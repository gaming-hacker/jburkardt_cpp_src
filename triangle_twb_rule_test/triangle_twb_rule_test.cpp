# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "triangle_twb_rule.hpp"

int main ( );
void triangle_unit_quad_test ( int degree_max );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    triangle_twb_rule_test tests triangle_twb_rule.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 April 2019
//
//  Author:
//
//    John Burkardt
//
{
  int degree_max;

  timestamp ( );
  cout << "\n";
  cout << "triangle_twb_rule_test\n";
  cout << "  C+= version\n";
  cout << "  Test triangle_twb_rule.\n";

  degree_max = 5;
  triangle_unit_quad_test ( degree_max );
//
//  Terminate.
//
  cout << "\n";
  cout << "triangle_twb_rule_test\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void triangle_unit_quad_test ( int degree_max )

//****************************************************************************80
//
//  Purpose:
//
//    triangle_unit_quad_test tests rules for the unit triangle.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 April 2019
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DEGREE_MAX, the maximum total degree of the monomials to check.
//
{
  int degree;
  int ex;
  int ey;
  int n;
  double q;
  int strength;
  double *v;
  double *w;
  double *x;
  double *y;

  cout << "\n";
  cout << "triangle_unit_quad_test\n";
  cout << "  Approximate monomial integrals in triangle with TWB rules.\n";

  degree = 0;
  ex = 0;
  ey = degree;

  while ( true )
  {
    cout << "\n";
    cout << "  Monomial: x^" << ex << " y^" << ey << "\n";

    for ( strength = 1; strength <= 25; strength++ )
    {
      n = twb_rule_n ( strength );
      if ( n < 1 )
      {
        continue;
      }
      w = twb_rule_w ( strength );
      x = twb_rule_x ( strength );
      y = twb_rule_y ( strength );
      v = monomial_value_2d ( n, ex, ey, x, y );
      q = r8vec_dot_product ( n, w, v );
      cout << "  " << setw(6) << strength
           << "  " << setw(6) << n
           << "  " << setw(14) << q << "\n";

      delete [] v;
      delete [] w;
      delete [] x;
      delete [] y;
    }

    q = triangle_unit_monomial ( ex, ey );
    cout << "   Exact          " << setw(14) << q << "\n";

    if ( ex < degree )
    {
      ex = ex + 1;
      ey = ey - 1;
    }
    else if ( degree < degree_max )
    {
      degree = degree + 1;
      ex = 0;
      ey = degree;
    }
    else
    {
      break;
    }
  }

  return;
}
