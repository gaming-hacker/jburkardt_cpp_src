# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "quadrature_least_squares.hpp"
# include "qr_solve.hpp"
# include "r8lib.hpp"

int main ( );
void test01 ( );
void test02 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for QLS_TEST.
//
//  Discussion:
//
//    QLS_TEST tests the QUADRATURE_LEAST_SQUARES library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 March 2014
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "QLS_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the QUADRATURE_LEAST_SQUARES library.\n";

  test01 ( );
  test02 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "QLS_TEST\n";
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
//    QLS_TEST01 shows that we can compute the Newton-Cotes rules.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 April 2014
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  int d;
  int i;
  int n;
  double *w1;
  double *w2;
  double *x;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  WEIGHTS_LS computes the weights for a\n";
  cout << "  least squares quadrature rule.\n";
//
//  Demonstrate the 5 point Newton-Cotes closed rule.
//
  cout << "\n";
  cout << "  W1 = classical Newton Cotes weights, N = 5\n";
  cout << "  W2 = least squares weights, D = 4, N = 5\n";

  n = 5;
  x = new double[n];
  w1 = new double[n];

  ncc_set ( n, x, w1 );
//
//  Using the same points, compute the least squares weights
//  for polynomial approximation up to degree 4.
//
  d = n - 1;
  a = -1.0;
  b = +1.0;

  w2 = weights_ls ( d, a, b, n, x );

  cout << "\n";
  cout << "   I        X(i)          W1(i)           W2(i)\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(2) << i
         << "  " << setw(14) << x[i]
         << "  " << setw(14) << w1[i]
         << "  " << setw(14) << w2[i] << "\n";
  }

  delete [] w1;
  delete [] w2;
  delete [] x;
//
//  Look at a 9 point rule.
//  Note that Newton Cotes rules soon have many negative weights.
//
  cout << "\n";
  cout << "  W1 = classical Newton Cotes weights, N = 9\n";
  cout << "  W2 = least squares weights, D = 4, N = 9\n";

  n = 9;
  x = new double[n];
  w1 = new double[n];
 
  ncc_set ( n, x, w1 );
//
//  Using the same points, compute the least squares weights
//  for polynomial approximation up to degree 4.
//
  d = 4;
  a = -1.0;
  b = +1.0;
  w2 = weights_ls ( d, a, b, n, x );

  cout << "\n";
  cout << "   I        X(i)          W1(i)           W2(i)\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(2) << i
         << "  " << setw(10) << x[i]
         << "  " << setw(14) << w1[i]
         << "  " << setw(14) << w2[i] << "\n";
  }

  delete [] w1;
  delete [] w2;
  delete [] x;

  return;
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 uses random points as abscissas.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 April 2014
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  int d;
  double e;
  double exact;
  double *f;
  int i;
  int n = 50;
  double q;
  int seed;
  double *w;
  double *x;

  cout << "\n";
  cout << "TEST02\n";
  cout << "  WEIGHTS_LS computes the weights for a\n";
  cout << "  least squares quadrature rule.\n";
  cout << "\n";
  cout << "  Pick 50 random values in [-1,+1].\n";
  cout << "  Compare Monte Carlo (equal weight) integral estimate\n";
  cout << "  to least squares estimates of degree D = 0, 1, 2, 3, 4.\n";
  cout << "  For low values of D, the least squares estimate improves.\n";
  cout << "\n";
  cout << "  As D increases, the estimate can deteriorate.\n";
//
//  Define the integration interval.
//
  a = -5.0;
  b = +5.0;
//
//  Get random values.
//
  seed = 123456789;
  x = r8vec_uniform_ab_new ( n, a, b, seed );
//
//  Evaluate the function.
//
  f = new double[n];
  for ( i = 0; i < n; i++ )
  {
    f[i] = 1.0 / ( 1.0 + x[i] * x[i] );
  }
  exact = atan ( b ) - atan ( a );

  cout << "\n";
  cout << "  Rule         Estimate          Error\n";
//
//  Get the MC estimate.
//
  q = ( b - a ) * r8vec_sum ( n, f ) / ( double ) ( n );
  e = fabs ( q - exact );

  cout << "\n";
  cout << "  MC     "<< setw(14)<< q
       << "  " << setw(14) << e << "\n";
  cout << "\n";
//
//  Using the same points, compute the least squares weights
//  for polynomial approximation of degree D.
//
  for ( d = 0; d <= 15; d++ )
  {
    w = weights_ls ( d, a, b, n, x );
    q = r8vec_dot_product ( n, w, f );
    e = fabs ( q - exact );
    cout << "  LS" << setw(2) << d
         << "  " << setw(14) << q
         << "  " << setw(14) << e << "\n";
    delete [] w;
  }

  q = exact;
  e = fabs ( q - exact );
  cout << "\n";
  cout << "  EXACT " << setw(14)<< q
       << "  " << setw(14) << e << "\n";

  delete [] f;
  delete [] x;

  return;
}
