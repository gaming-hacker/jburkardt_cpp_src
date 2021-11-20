# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "square_minimal_rule.hpp"

int main ( );
void square_minimal_rule_print_test ( int degree );
void square_minimal_rule_order_test ( );
void square_minimal_rule_error_max_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for SQUARE_MINIMAL_RULE_TEST.
//
//  Discussion:
//
//    SQUARE_MINIMAL_RULE_TEST tests the SQUARE_MINIMAL_RULE library.
//    
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 February 2018
//
//  Author:
//
//    John Burkardt
//
{
  int degree;

  timestamp ( );
  cout << "\n";
  cout << "SQUARE_MINIMAL_RULE_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the SQUARE_MINIMAL_RULE library.\n";

  degree = 8;
  square_minimal_rule_print_test ( degree );

  square_minimal_rule_order_test ( );

  square_minimal_rule_error_max_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "SQUARE_MINIMAL_RULE_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void square_minimal_rule_print_test ( int degree )

//****************************************************************************80
//
//  Purpose:
//
//    SQUARE_MINIMAL_RULE_PRINT_TEST tests SQUARE_MINIMAL_RULE_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 February 2018
//
//  Author:
//
//    John Burkardt
//
{
  double area;
  double d;
  int j;
  int order;
  double *xyw;

  cout << "\n";
  cout << "SQUARE_MINIMAL_RULE_PRINT_TEST\n";
  cout << "  SQUARE_MINIMAL_RULE_PRINT prints a quadrature rule\n";
  cout << "  for the symmetric unit square.\n";
  cout << "  Minimal quadrature rule for a square.\n";
  cout << "  Polynomial exactness degree DEGREE = " << degree << "\n";
//
//  Retrieve and print a symmetric quadrature rule.
//
  xyw = square_minimal_rule ( degree );

  order = square_minimal_rule_order ( degree );

  cout << "\n";
  cout << "  Number of nodes N = " << order << "\n";

  cout << "\n";
  cout << "     J          X               Y               W\n";
  cout << "\n";
  for ( j = 0; j < order; j++ )
  {
    cout << "  " << setw(4) << j
         << "  " << setw(14) << xyw[0+j*3]
         << "  " << setw(14) << xyw[1+j*3]
         << "  " << setw(14) << xyw[2+j*3] << "\n";
  }

  d = 0.0;
  for ( j = 0; j < order; j++ )
  {
    d = d + xyw[2+j*3];
  }

  cout << "\n";
  cout << "   Sum  " << setw(14) << d << "\n";
  area = squaresym_area ( );
  cout << "  Area  " << setw(14 ) << area << "\n";

  free ( xyw );

  return;
}
//****************************************************************************80

void square_minimal_rule_order_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SQUARE_MINIMAL_RULE_ORDER_TEST tests SQUARE_MINIMAL_RULE_ORDER.
//
//  Licensing:
//
//    This code is distributed under the GNU GPL license.
//
//  Modified:
//
//    22 February 2018
//
//  Author:
//
//    John Burkardt.
//
//  Reference:
//
//    Mattia Festa, Alvise Sommariva,
//    Computing almost minimal formulas on the square,
//    Journal of Computational and Applied Mathematics,
//    Volume 17, Number 236, November 2012, pages 4296-4302.
//
{
  int degree;
  int degree_max;
  int order;

  cout << "\n";
  cout << "SQUARE_MINIMAL_RULE_ORDER_TEST\n";
  cout << "  Print the order (number of points) for each\n";
  cout << "  minimal square rule.\n";

  degree_max = square_minimal_rule_degree_max ( );

  cout << "\n";
  cout << " Degree  Order\n";
  cout << "\n";
  for ( degree = 0; degree <= degree_max; degree++ )
  {
    order = square_minimal_rule_order ( degree );
    cout << "  " << degree
         << "  " << order << "\n";
  }

  return;
}
//****************************************************************************80

void square_minimal_rule_error_max_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SQUARE_MINIMAL_RULE_ERROR_MAX_TEST tests SQUARE_MINIMAL_RULE_ERROR_MAX.
//
//  Licensing:
//
//    This code is distributed under the GNU GPL license.
//
//  Modified:
//
//    22 February 2018
//
//  Author:
//
//    John Burkardt.
//
//  Reference:
//
//    Mattia Festa, Alvise Sommariva,
//    Computing almost minimal formulas on the square,
//    Journal of Computational and Applied Mathematics,
//    Volume 17, Number 236, November 2012, pages 4296-4302.
//
{
  int degree;
  int degree_max;
  double error_max;
  int m_num;

  cout << "\n";
  cout << "SQUARE_MINIMAL_RULE_ERROR_MAX_TEST\n";
  cout << "  SQUARE_MINIMAL_RULE_ERROR_MAX computes the maximum\n";
  cout << "  error for a rule that should be exact for all monomials\n";
  cout << "  up to a given value of DEGREE.\n";

  degree_max = square_minimal_rule_degree_max ( );

  cout << "\n";
  cout << " Degree  Monomials  Error Max\n";
  cout << "\n";

  for ( degree = 0; degree <= degree_max; degree++ )
  {
    error_max = square_minimal_rule_error_max ( degree );
    m_num = ( ( degree + 1 ) * ( degree + 2 ) ) / 2;
    cout << "   " << setw(4) << degree
         << "       " << setw(4) << m_num
         << "  " << error_max << "\n";
  }

  return;
}
