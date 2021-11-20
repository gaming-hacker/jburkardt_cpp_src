# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <cstring>

using namespace std;

# include "vandermonde_interp_2d.hpp"
# include "qr_solve.hpp"
# include "test_interp_2d.hpp"
# include "r8lib.hpp"

int main ( );
void test01 ( int prob, int m );
double *r8poly_values_2d ( int m, double c[], int n, double x[], double y[] );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for VANDERMONDE_INTERP_1D_TEST.
//
//  Discussion:
//
//    VANDERMONDE_INTERP_2D_TEST tests the VANDERMONDE_INTERP_2D library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 October 2012
//
//  Author:
//
//    John Burkardt
//
{
  int j;
  int m;
  int m_test[5] = { 1, 2, 3, 4, 8 };
  int m_test_num = 5;
  int prob;
  int prob_num;

  timestamp ( );
  cout << "\n";
  cout << "VANDERMONDE_INTERP_2D_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the VANDERMONDE_INTERP_2D library.\n";
  cout << "  The QR_SOLVE library is needed.\n";
  cout << "  The R8LIB library is needed.\n";
  cout << "  This test needs the TEST_INTERP_2D library.\n";

  prob_num = f00_num ( );
  for ( prob = 1; prob <= prob_num; prob++ )
  {
    for ( j = 0; j < m_test_num; j++ )
    {
      m = m_test[j];
      test01 ( prob, m );
    }
  }
//
//  Terminate.
//
  cout << "\n";
  cout << "VANDERMONDE_INTERP_2D_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test01 ( int prob, int m )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tests VANDERMONDE_INTERP_2D_MATRIX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 October 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int PROB, the problem number.
//
//    Input, int M, the degree of interpolation.
//
{
  double *a;
  double app_error;
  double *c;
  bool debug = false;
  int nd;
  int ni;
  int seed;
  int tmp1;
  double *xd;
  double *xi;
  double *yd;
  double *yi;
  double *zd;
  double *zi;

  cout << "\n";
  cout << "TEST01:\n";
  cout << "  Interpolate data from TEST_INTERP_2D problem #" << prob << "\n";
  cout << "  Create an interpolant of total degree " << m << "\n";
  tmp1 = triangle_num ( m + 1 );
  cout << "  Number of data values needed is " << tmp1 << "\n";

  nd = tmp1;

  seed = 123456789;

  xd = r8vec_uniform_01_new ( nd, seed );
  yd = r8vec_uniform_01_new ( nd, seed );
  zd = new double[nd];
  f00_f0 ( prob, nd, xd, yd, zd );

  if ( debug )
  {
    r8vec3_print ( nd, xd, yd, zd, "  X, Y, Z data:" );
  }
//
//  Compute the Vandermonde matrix.
//
  a = vandermonde_interp_2d_matrix ( nd, m, xd, yd );
//
//  Solve linear system.
//
  c = qr_solve ( nd, nd, a, zd );
//
//  #1:  Does interpolant match function at data points?
//
  ni = nd;
  xi = r8vec_copy_new ( ni, xd );
  yi = r8vec_copy_new ( ni, yd );
  zi = r8poly_values_2d ( m, c, ni, xi, yi );

  app_error = r8vec_norm_affine ( ni, zi, zd ) / ( double ) ( ni );

  cout << "\n";
  cout << "  L2 data interpolation error = " << app_error << "\n";

  delete [] a;
  delete [] c;
  delete [] xd;
  delete [] xi;
  delete [] yd;
  delete [] yi;
  delete [] zd;
  delete [] zi;

  return;
}
//****************************************************************************80

double *r8poly_values_2d ( int m, double c[], int n, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    r8poly_values_2d evaluates a polynomial in 2 variables, X and Y.
//
//  Discussion:
//
//    We assume the polynomial is of total degree M, and has the form:
//
//      p(x,y) = c00 
//             + c10 * x                + c01 * y
//             + c20 * x^2   + c11 * xy + c02 * y^2
//             + ...
//             + cm0 * x^(m) + ...      + c0m * y^m.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 September 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the degree of the polynomial.
//
//    Input, double C[T(M+1)], the polynomial coefficients.  
//    C[0] is the constant term.  T(M+1) is the M+1-th triangular number.
//    The coefficients are stored consistent with the following ordering
//    of monomials: 1, X, Y, X^2, XY, Y^2, X^3, X^2Y, XY^2, Y^3, X^4, ...
//
//    Input, int N, the number of evaluation points.
//
//    Input, double X[N], Y[N], the evaluation points.
//
//    Output, double R8POLY_VALUE_2D[N], the value of the polynomial at the 
//    evaluation points.
//
{
  int ex;
  int ey;
  int i;
  int j;
  double *p;
  int s;

  p = new double[n];

  for ( i = 0; i < n; i++ )
  {
    p[i] = 0.0;
  }

  j = 0;
  for ( s = 0; s <= m; s++ )
  {
    for ( ex = s; 0 <= ex; ex-- )
    {
      ey = s - ex;
      for ( i = 0; i < n; i++ )
      {
        p[i] = p[i] + c[j] * pow ( x[i], ex ) * pow ( y[i], ey );
      }
      j = j + 1;
    }
  }
  return p;
}
