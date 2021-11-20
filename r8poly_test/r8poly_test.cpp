# include <cmath>
# include <complex>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "r8poly.hpp"

int main ( );

void r8_sign_test ( );

void r82poly2_type_test ( );
void r82poly2_print_test ( );

void r8mat_inverse_3d_test ( );
void r8mat_print_test ( );
void r8mat_print_some_test ( );

void r8poly_add_test ( );
void r8poly_ant_coef_test ( );
void r8poly_ant_value_test ( );
void r8poly_degree_test ( );
void r8poly_deriv_test ( );
void r8poly_division_test ( );
void r8poly_lagrange_coef_test ( );
void r8poly_lagrange_0_test ( );
void r8poly_lagrange_1_test ( );
void r8poly_lagrange_2_test ( );
void r8poly_lagrange_factor_test ( );
void r8poly_lagrange_value_test ( );
void r8poly_multiply_test ( );
void r8poly_power_test ( );
void r8poly_print_test ( );
void r8poly_value_test ( );
void r8poly_value_horner_test ( );
void r8poly_values_horner_test ( );

void r8poly2_ex_test ( );
void r8poly2_ex2_test ( );
void r8poly2_f ( double x, double &y, double &yp, double &ypp );
void r8poly2_root_test ( );
void r8poly2_rroot_test ( );
void r8poly2_val_f ( double x, double &y, double &yp, double &ypp );
void r8poly2_val_test ( );
void r8poly2_val2_test ( );

void r8poly3_root_test ( );

void r8poly4_root_test ( );

void r8vec_even_new_test ( );
void r8vec_even_select_test ( );
void r8vec_indicator1_new_test ( );
void r8vec_is_distinct_test ( );
void r8vec_linspace_new_test ( );
void r8vec_print_test ( );
void r8vec_transpose_print_test ( );
void r8vec_uniform_01_new_test ( );

void r8vec2_print_test ( );

void roots_to_r8poly_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for R8POLY_TEST.
//
//  Discussion:
//
//    R8POLY_TEST tests R8POLY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 November 2019
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "R8POLY_TEST\n";
  cout << "  C version\n";
  cout << "  Test r8poly.\n";

  r8_sign_test ( );

  r82poly2_print_test ( );
  r82poly2_type_test ( );

  r8mat_inverse_3d_test ( );
  r8mat_print_test ( );
  r8mat_print_some_test ( );

  r8poly_add_test ( );
  r8poly_ant_coef_test ( );
  r8poly_ant_value_test ( );
  r8poly_degree_test ( );
  r8poly_deriv_test ( );
  r8poly_division_test ( );
  r8poly_lagrange_coef_test ( );
  r8poly_lagrange_0_test ( );
  r8poly_lagrange_1_test ( );
  r8poly_lagrange_2_test ( );
  r8poly_lagrange_factor_test ( );
  r8poly_lagrange_value_test ( );
  r8poly_multiply_test ( );
  r8poly_power_test ( );
  r8poly_print_test ( );
  r8poly_value_test ( );
  r8poly_value_horner_test ( );
  r8poly_values_horner_test ( );

  r8poly2_ex_test ( );
  r8poly2_ex2_test ( );
  r8poly2_root_test ( );
  r8poly2_rroot_test ( );
  r8poly2_val_test ( );
  r8poly2_val2_test ( );

  r8poly3_root_test ( );

  r8poly4_root_test ( );

  r8vec_even_new_test ( );
  r8vec_even_select_test ( );
  r8vec_indicator1_new_test ( );
  r8vec_is_distinct_test ( );
  r8vec_linspace_new_test ( );
  r8vec_print_test ( );
  r8vec_transpose_print_test ( );
  r8vec_uniform_01_new_test ( );

  r8vec2_print_test ( );

  roots_to_r8poly_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "R8POLY_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void r8_sign_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_SIGN_TEST tests R8_SIGN.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 September 2014
//
//  Author:
//
//    John Burkardt
//
{
  double r8;
  double r8_test[5] = { -1.25, -0.25, 0.0, +0.5, +9.0 };
  double s;
  int test;
  const int test_num = 5;

  cout << "\n";
  cout << "R8_SIGN_TEST\n";
  cout << "  R8_SIGN returns the sign of an R8.\n";
  cout << "\n";
  cout << "      R8      R8_SIGN(R8)\n";
  cout << "\n";

  for ( test = 0; test < test_num; test++ )
  {
    r8 = r8_test[test];
    s = r8_sign ( r8 );
    cout << setw(10) << r8 << "  "
         << setw(10) << s << "\n";
  }

  return;
}
//****************************************************************************80

void r82poly2_type_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R82POLY2_TYPE_TEST tests R82POLY2_TYPE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 12

  double a;
  double a_test[TEST_NUM] = {
    9.0, 4.0, 9.0,  1.0, 0.0,
    1.0, 0.0, 0.0,  0.0, 0.0,
    0.0, 0.0 };
  double b;
  double b_test[TEST_NUM] = {
    -4.0, 1.0,  16.0,  1.0,  0.0,
     2.0, 1.0,   1.0,  1.0,  0.0,
     0.0, 0.0 };
  double c;
  double c_test[TEST_NUM] = {
     0.0, -4.0,   0.0,   0.0, 1.0,
     0.0,  0.0,   0.0,  0.0,  0.0,
     0.0,  0.0 };
  double d;
  double r8_test[TEST_NUM] = {
    -36.0,  3.0,  36.0,  -6.0, 3.0,
    -2.0,   0.0,   0.0,  0.0,  2.0,
     0.0, 0.0 };
  double e;
  double e_test[TEST_NUM] = {
    -24.0, -4.0, -32.0, -10.0, -1.0,
     16.0, -6.0, -6.0, -2.0, -1.0,
     0.0, 0.0 };
  double f;
  double f_test[TEST_NUM] = {
    -36.0,  1.0, -92.0, 115.0, -3.0,
     33.0, +8.0, 10.0,  +1.0,  1.0,
      0.0, 1.0 };
  int test;
  int type;

  cout << "\n";
  cout << "R82POLY2_TYPE_TEST\n";
  cout << "  R82POLY2_TYPE determines the type of a second order\n";
  cout << "  equation in two variables.\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];
    d = r8_test[test];
    e = e_test[test];
    f = f_test[test];

    cout << "\n";

    r82poly2_print ( a, b, c, d, e, f );

    type = r82poly2_type ( a, b, c, d, e, f );

    cout << "  Type = " << type << "\n";

    r82poly2_type_print ( type );
  }

  return;
# undef TEST_NUM
}
//****************************************************************************//

void r82poly2_print_test ( )

//****************************************************************************//
//
//  Purpose:
//
//    R82POLY2_PRINT_TEST tests R82POLY2_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double c;
  double d;
  double e;
  double f;

  cout << "\n";
  cout << "R82POLY2_PRINT_TEST\n";
  cout << "  R82POLY2_PRINT prints an R82POLY2,\n";
  cout << "  a quadratic polynomial in x and y.\n";

  a = 1.0;
  b = 2.0;
  c = 3.0;
  d = 4.0;
  e = 5.0;
  f = 6.0;

  cout << "\n";
  cout << "  Coefficients a, b, c, d, e, f\n";
  cout << "  " << a
       << "  " << b
       << "  " << c
       << "  " << d
       << "  " << e
       << "  " << f << "\n";
  cout << "\n";

  r82poly2_print ( a, b, c, d, e, f );

  return;
}
//****************************************************************************80

void r8mat_inverse_3d_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_INVERSE_3D_TEST tests R8MAT_INVERSE_3D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 October 2005
//
//  Author:
//
//    John Burkardt
//
{
# define N 3

  double a[N*N];
  double *b;
  double c[N*N];
  int i;
  int j;
  int k;

  cout << "\n";
  cout << "R8MAT_INVERSE_3D_TEST\n";
  cout << "  R8MAT_INVERSE_3D inverts a 3 by 3 matrix.\n";

  a[0+0*N] = 3.0;
  a[0+1*N] = 2.0;
  a[0+2*N] = 1.0;

  a[1+0*N] = 2.0;
  a[1+1*N] = 2.0;
  a[1+2*N] = 1.0;

  a[2+0*N] = 0.0;
  a[2+1*N] = 1.0;
  a[2+2*N] = 1.0;

  r8mat_print ( 3, 3, a, "  Matrix A:" );

  b = r8mat_inverse_3d ( a );

  r8mat_print ( 3, 3, b, "  Inverse matrix B:" );

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      c[i+j*N] = 0.0;
      for ( k = 0; k < N; k++ )
      {
        c[i+j*N] = c[i+j*N] + a[i+k*N] * b[k+j*N];
      }
    }
  }

  r8mat_print ( 3, 3, c, "  C = A * B:" );

  delete [] b;

  return;

# undef N
}
//****************************************************************************80

void r8mat_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT_TEST tests R8MAT_PRINT.
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
# define M 6
# define N 4

  double a[M*N];
  int i;
  int j;
  int m = M;
  int n = N;

  cout << "\n";
  cout << "R8MAT_PRINT_TEST\n";
  cout << "  R8MAT_PRINT prints an R8MAT.\n";

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
  r8mat_print ( m, n, a, "  The R8MAT:" );

  return;
# undef M
# undef N
}
//****************************************************************************80

void r8mat_print_some_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT_SOME_TEST tests R8MAT_PRINT_SOME.
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
# define M 6
# define N 4

  double a[M*N];
  int i;
  int j;
  int m = M;
  int n = N;

  cout << "\n";
  cout << "R8MAT_PRINT_SOME_TEST\n";
  cout << "  R8MAT_PRINT_SOME prints some of an R8MAT.\n";

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
  r8mat_print_some ( m, n, a, 2, 1, 4, 2, "  The R8MAT, rows 2:4, cols 1:2:" );

  return;
# undef M
# undef N
}
//****************************************************************************80

void r8poly_add_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_ADD_TEST tests R8POLY_ADD.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 May 2015
//
//  Author:
//
//    John Burkardt
//
{
  double a[6] = { 0.0,  1.1, 2.2, 3.3, 4.4,  5.5 };
  double b[6] = { 1.0, -2.1, 7.2, 8.3, 0.0, -5.5 };
  double *c;
  int na = 5;
  int nb = 5;
  int nc;
  int nc2;

  cout << "\n";
  cout << "R8POLY_ADD_TEST\n";
  cout << "  R8POLY_ADD adds two polynomials.\n";

  r8poly_print ( na, a, "  Polynomial A:" );

  r8poly_print ( nb, b, "  Polynomial B:" );

  c = r8poly_add ( na, a, nb, b );

  nc = i4_max ( na, nb );

  nc2 = r8poly_degree ( nc, c );

  r8poly_print ( nc2, c, "  Polynomial C = A+B:" );

  delete [] c;

  return;
}
//****************************************************************************80

void r8poly_ant_coef_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    r8poly_ant_coef_test tests r8poly_ant_coef().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 October 2019
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int n;
  double *poly_cof;
  double *poly_cof2;

  n = 5;

  cout << "\n";
  cout << "r8poly_ant_coef_test\n";
  cout << "  r8poly_ant_coef() computes the coefficients of the\n";
  cout << "  antiderivative of a polynomial;\n";

  poly_cof = new double[n+1];
  for ( i = 0; i < n + 1; i++ )
  {
    poly_cof[i] = n + 1 - i;
  }

  r8poly_print ( n, poly_cof, "  Polynomial p(x):" );

  poly_cof2 = r8poly_ant_coef ( n, poly_cof );

  r8poly_print ( n+1, poly_cof2, "  Antideriv(p(x)):" );

  delete [] poly_cof;
  delete [] poly_cof2;

  return;
}
//****************************************************************************80

void r8poly_ant_value_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    r8poly_ant_value_test tests r8poly_ant_value().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 October 2019
//
//  Author:
//
//    John Burkardt
//
{
  double c[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int i;
  int m = 4;
  int n = 16;
  double p;
  double *x;
  double x_hi;
  double x_lo;

  cout << "\n";
  cout << "r8poly_ant_value_test\n";
  cout << "  r8poly_ant_value() evaluates the antiderivative of a polynomial at\n";
  cout << "  one point, using a naive method.\n";

  r8poly_print ( m, c, "  The polynomial coefficients:" );

  x_lo = 0.0;
  x_hi = 5.0;
  x = r8vec_linspace_new ( n, x_lo, x_hi );

  cout << "\n";
  cout << "   I    X    antiP(X)\n";
  cout << "\n";

  for ( i = 0; i < n; i++ )
  {
    p = r8poly_ant_value ( m, c, x[i] );
    cout << "  " << setw(2) << i
         << "  " << setw(8) << x[i]
         << "  " << setw(14) << p << "\n";
  }

  delete [] x;

  return;
}
//****************************************************************************80

void r8poly_degree_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_DEGREE_TEST tests R8POLY_DEGREE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  double c1[4] = { 1.0, 2.0, 3.0, 4.0 }; 
  double c2[4] = { 1.0, 2.0, 3.0, 0.0 };
  double c3[4] = { 1.0, 2.0, 0.0, 4.0 };
  double c4[4] = { 1.0, 0.0, 0.0, 0.0 };
  double c5[4] = { 0.0, 0.0, 0.0, 0.0 };
  int d;
  int m;
 
  cout << "\n";
  cout << "R8POLY_DEGREE_TEST\n";
  cout << "  R8POLY_DEGREE determines the degree of an R8POLY.\n";

  m = 3;

  r8poly_print ( m, c1, "  The R8POLY:" );
  d = r8poly_degree ( m, c1 );
  cout << "  Dimensioned degree = " << m << ",  Actual degree = " << d << "\n";

  r8poly_print ( m, c2, "  The R8POLY:" );
  d = r8poly_degree ( m, c2 );
  cout << "  Dimensioned degree = " << m << ",  Actual degree = " << d << "\n";

  r8poly_print ( m, c3, "  The R8POLY:" );
  d = r8poly_degree ( m, c3 );
  cout << "  Dimensioned degree = " << m << ",  Actual degree = " << d << "\n";

  r8poly_print ( m, c4, "  The R8POLY:" );
  d = r8poly_degree ( m, c4 );
  cout << "  Dimensioned degree = " << m << ",  Actual degree = " << d << "\n";

  r8poly_print ( m, c5, "  The R8POLY:" );
  d = r8poly_degree ( m, c5 );
  cout << "  Dimensioned degree = " << m << ",  Actual degree = " << d << "\n";

  return;
}
//****************************************************************************80

void r8poly_deriv_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_DERIV_TEST tests R8POLY_DERIV.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define N 4

  double *c;
  double *cp;
  int d;
  double *x;

  cout << "\n";
  cout << "R8POLY_DERIV_TEST\n";
  cout << "  R8POLY_DERIV computes the coefficients of\n";
  cout << "  the derivative of a polynomial.\n";

  x = r8vec_indicator1_new ( N );

  c = roots_to_r8poly ( N, x );

  r8poly_print ( N, c, "  The initial polynomial" );

  for ( d = 0; d <= N; d++ )
  {
    cp = r8poly_deriv ( N, c, d );
    cout << "\n";
    cout << "  The derivative of order " << d << "\n";
    cout << "\n";
    r8poly_print ( N-d, cp, " " );
    delete [] cp;
  }

  delete [] c;
  delete [] x;

  return;
# undef N
}
//****************************************************************************80

void r8poly_division_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    r8poly_division_test tests r8poly_division.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 October 2019
//
//  Author:
//
//    John Burkardt
//
{
  double a[11];
  double b[11];
  int i;
  int na;
  int nb;
  int nq;
  int nr;
  int ntest = 3;
  double q[11];
  double r[11];
  int test;

  cout << "\n";
  cout << "r8poly_division_test\n";
  cout << "  r8poly_division computes the quotient and\n";
  cout << "  remainder for polynomial division.\n";
  cout << "\n";
//
//  1: Divide X**3 + 2*X**2 - 5*X - 6  by X-2.  
//     Quotient is 3+4*X+X**2, remainder is 0.
//
//  2: Divide X**4 + 3*X**3 + 2*X**2 - 2  by  X**2 + X - 3.
//     Quotient is X**2 + 2*X + 3, remainder 8*X + 7.
//
  for ( test = 1; test <= ntest; test++ )
  {
    if ( test == 1 )
    {
      na = 3;
      a[0] = -6.0;
      a[1] = -5.0;
      a[2] =  2.0;
      a[3] =  1.0;
      nb = 1;
      b[0] = -2.0;
      b[1] =  1.0;
    }
    else if ( test == 2 )
    {
      na = 4;
      a[0] = -2.0;
      a[1] =  5.0;
      a[2] =  2.0;
      a[3] =  3.0;
      a[4] =  1.0;
      nb = 2;
      b[0] = -3.0;
      b[1] =  1.0;
      b[2] =  1.0;
    }
    else if ( test == 3 )
    {
      na = 3;
      a[0] = -4.0;
      a[1] =  0.0;
      a[2] = -2.0;
      a[3] =  1.0;
      nb = 1;
      b[0] = -3.0;
      b[1] =  1.0;
    }

    r8poly_print ( na, a, "  The polynomial to be divided, A:" );

    r8poly_print ( nb, b, "  The divisor polynomial, B:" );

    r8poly_division ( na, a, nb, b, nq, q, nr, r );

    r8poly_print ( nq, q, "  The quotient polynomial, Q:" );

    r8poly_print ( nr, r, "  The remainder polynomial, R:" );

  }
  return;
}
//****************************************************************************80

void r8poly_lagrange_coef_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_LAGRANGE_COEF_TEST tests R8POLY_LAGRANGE_COEF.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define NPOL 3

  int i;
  int ipol;
  double *pcof;
  double *xpol;

  cout << "\n";
  cout << "R8POLY_LAGRANGE_COEF_TEST\n";
  cout << "  R8POLY_LAGRANGE_COEF returns the coefficients for\n";
  cout << "  a Lagrange basis polynomial.\n";

  xpol = r8vec_indicator1_new ( NPOL );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );

  for ( ipol = 1; ipol <= NPOL; ipol++ )
  {
    pcof = r8poly_lagrange_coef ( NPOL, ipol, xpol );

    cout << "\n";
    cout << "  Lagrange basis polynomial " << setw(4) << ipol << ":\n";
    cout << "\n";

    for ( i = 0; i < NPOL; i++ )
    {
      cout << setw(10) << pcof[i] << "  "
           << setw(4)  << i << "\n";
    }
    delete [] pcof;

  }

  delete [] xpol;

  return;
# undef NPOL
}
//****************************************************************************80

void r8poly_lagrange_0_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_LAGRANGE_0_TEST tests R8POLY_LAGRANGE_0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define NPOL 5

  int ival;
  int nx;
  double wval;
  double xhi;
  double xlo;
  double *xpol;
  double xval;

  cout << "\n";
  cout << "R8POLY_LAGRANGE_0_TEST\n";
  cout << "  R8POLY_LAGRANGE_0 evaluates the Lagrange\n";
  cout << "  factor W(X) at a point.\n";
  cout << "\n";
  cout << "  The number of data points is " << NPOL << "\n";
//
//  Set the abscissas of the polynomials.
//
  xlo = 0.0E+00;
  xhi = ( double ) ( NPOL - 1 );

  xpol = r8vec_even_new ( NPOL, xlo, xhi );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
//
//  Evaluate W(X), W'(X).
//
  cout << "\n";
  cout << "      X          W(X)\n";
  cout << "\n";

  nx = 4 * NPOL - 1;

  for ( ival = 1; ival <= nx; ival++ )
  {
    xval = r8vec_even_select ( nx, xlo, xhi, ival );

    wval = r8poly_lagrange_0 ( NPOL, xpol, xval );

    cout << setw(12) << xval   << "  "
         << setw(12) << wval   << "\n";
  }

  delete [] xpol;

  return;
# undef NPOL
}
//****************************************************************************80

void r8poly_lagrange_1_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_LAGRANGE_1_TEST tests R8POLY_LAGRANGE_1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define NPOL 5

  double dwdx;
  int ival;
  int nx;
  double xhi;
  double xlo;
  double *xpol;
  double xval;

  cout << "\n";
  cout << "R8POLY_LAGRANGE_1_TEST\n";
  cout << "  R8POLY_LAGRANGE_1 evaluates the Lagrange\n";
  cout << "  factor W'(X) at a point.\n";
  cout << "\n";
  cout << "  The number of data points is " << NPOL << "\n";
//
//  Set the abscissas of the polynomials.
//
  xlo = 0.0E+00;
  xhi = ( double ) ( NPOL - 1 );

  xpol = r8vec_even_new ( NPOL, xlo, xhi );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
//
//  Evaluate W(X), W'(X).
//
  cout << "\n";
  cout << "      X          W'(X)\n";
  cout << "\n";

  nx = 4 * NPOL - 1;

  for ( ival = 1; ival <= nx; ival++ )
  {
    xval = r8vec_even_select ( nx, xlo, xhi, ival );

    dwdx = r8poly_lagrange_1 ( NPOL, xpol, xval );

    cout << setw(12) << xval   << "  "
         << setw(12) << dwdx   << "\n";
  }

  delete [] xpol;

  return;
# undef NPOL
}
//****************************************************************************80

void r8poly_lagrange_2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_LAGRANGE_2_TEST tests R8POLY_LAGRANGE_2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define NPOL 5

  double dw2dx2;
  int ival;
  int nx;
  double xhi;
  double xlo;
  double *xpol;
  double xval;

  cout << "\n";
  cout << "R8POLY_LAGRANGE_2_TEST\n";
  cout << "  R8POLY_LAGRANGE_2 evaluates the Lagrange\n";
  cout << "  factor W''(X) at a point.\n";
  cout << "\n";
  cout << "  The number of data points is " << NPOL << "\n";
//
//  Set the abscissas of the polynomials.
//
  xlo = 0.0E+00;
  xhi = ( double ) ( NPOL - 1 );

  xpol = r8vec_even_new ( NPOL, xlo, xhi );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
//
//  Evaluate W''.
//
  cout << "\n";
  cout << "      X          W''(X)\n";
  cout << "\n";

  nx = 4 * NPOL - 1;

  for ( ival = 1; ival <= nx; ival++ )
  {
    xval = r8vec_even_select ( nx, xlo, xhi, ival );

    dw2dx2 = r8poly_lagrange_2 ( NPOL, xpol, xval );

    cout << setw(12) << xval   << "  "
         << setw(12) << dw2dx2 << "\n";
  }

  delete [] xpol;

  return;
# undef NPOL
}
//****************************************************************************80

void r8poly_lagrange_factor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_LAGRANGE_FACTOR_TEST tests R8POLY_LAGRANGE_FACTOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define NPOL 5

  double dwdx;
  int i;
  double wval;
  double xhi;
  double xlo;
  double xpol[NPOL];
  double xval;

  cout << "\n";
  cout << "R8POLY_LAGRANGE_FACTOR_TEST\n";
  cout << "  R8POLY_LAGRANGE_FACTOR evaluates the Lagrange\n";
  cout << "  factor W(X) at a point.\n";
  cout << "\n";
  cout << "  For this test, we use " << NPOL << " functions.\n";
//
//  Set the abscissas of the polynomials.
//
  xlo = 0.0;
  xhi = ( double ) ( NPOL - 1 );
  for ( i = 0; i < NPOL; i++ )
  {
    xpol[i] = ( ( double ) ( NPOL - i ) * xlo + ( double ) i * xhi )
      / ( double ) ( NPOL );
  }

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
//
//  Evaluate W(X) and W'(X).
//
  cout << "\n";
  cout << "      X          W(X)          W'(X)\n";
  cout << "\n";

  for ( i = 0; i < 2 * NPOL - 2; i++ )
  {
    xval = r8vec_even_select ( 2 * NPOL - 1, xhi, xlo, i );

    r8poly_lagrange_factor ( NPOL, xpol, xval, wval, dwdx );

    cout << setw ( 10 ) << xval << " "
         << setw ( 10 ) << wval << " "
         << setw ( 10 ) << dwdx << "\n";
  }

  return;
# undef NPOL
}
//****************************************************************************80

void r8poly_lagrange_value_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    r8poly_lagrange_value_test tests r8poly_lagrange_value().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define NPOL 5

  int ipol;
  int ival;
  double p1;
  double p2;
  double xhi;
  double xlo;
  double *xpol;
  double xval;

  cout << "\n";
  cout << "r8poly_lagrange_value_test\n";
  cout << "  r8poly_lagrange_value() evaluates a Lagrange\n";
  cout << "  interpolating polynomial at a point.\n";
  cout << "\n";
  cout << "  For this test, we use " << NPOL << " functions.\n";
//
//  Set the abscissas of the polynomials.
//
  xlo = 0.0E+00;
  xhi = ( double ) ( NPOL - 1 );
  xpol = r8vec_even_new ( NPOL, xlo, xhi );

  r8vec_print ( NPOL, xpol, "  Abscissas:" );
//
//  Evaluate the polynomials.
//
  cout << "\n";
  cout << "  Here are the values of the functions at\n";
  cout << "  several points:\n";
  cout << "\n";
  cout << "      X          L1          L2          L3      L4          L5\n";
  cout << "\n";

  for ( ival = 0; ival < 2 * NPOL - 1; ival++ )
  {
    xval = r8vec_even_select ( 2 * NPOL - 1, xhi, xlo, ival );
    cout << setw(10) << xval << "  ";

    for ( ipol = 0; ipol < NPOL; ipol++ )
    {
      r8poly_lagrange_value ( NPOL, ipol, xpol, xval, p1, p2 );
      cout << setw(10) << p1 << "  ";
    }
    cout << "\n";
  }
  cout << "\n";
  cout << "  And the derivatives:\n";
  cout << "\n";
  cout << "      X          L'1         L'2         L'3     L'4         L'5\n";
  cout << "\n";

  for ( ival = 0; ival < 2 * NPOL - 1; ival++ )
  {
    xval = r8vec_even_select ( 2 * NPOL - 1, xhi, xlo, ival );
    cout << setw(10) << xval << " ";

    for ( ipol = 0; ipol < NPOL; ipol++ )
    {
      r8poly_lagrange_value ( NPOL, ipol, xpol, xval, p1, p2 );
      cout << setw(10) << p2 << " ";
    }
    cout << "\n";
  }

  delete [] xpol;

  return;
# undef NPOL
}
//****************************************************************************80

void r8poly_multiply_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    r8poly_multiply_test tests r8poly_multiply.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 July 2007
//
//  Author:
//
//    John Burkardt
//
{
# define MAXN 5

  double a[MAXN+1];
  double b[MAXN+1];
  double c[MAXN+1];
  int na;
  int nb;
  int ntest = 2;
  int test;

  cout << "\n";
  cout << "r8poly_multiply_test\n";
  cout << "  r8poly_multiply multiplies two polynomials.\n";
  cout << "\n";
//
//  1: Multiply (1+X) times (1-X).  Answer is 1-X**2.
//  2: Multiply (1+2*X+3*X**2) by (1-2*X). Answer is 1 + 0*X - X**2 - 6*X**3
//
  for ( test = 1; test <= ntest; test++ )
  {
    if ( test == 1 )
    {
      na = 1;
      a[0] = 1.0;
      a[1] = 1.0;
      nb = 1;
      b[0] =  1.0;
      b[1] = -1.0;
    }
    else if ( test == 2 )
    {
      na = 2;
      a[0] = 1.0;
      a[1] = 2.0;
      a[2] = 3.0;
      nb = 1;
      b[0] =  1.0;
      b[1] = -2.0;
    }

    r8poly_multiply ( na, a, nb, b, c );

    r8poly_print ( na, a, "  The factor A:" );

    r8poly_print ( nb, b, "  The factor B:" );

    r8poly_print ( na+nb, c, "  The product C = A*B:" );

  }

  return;
# undef MAXN
}
//****************************************************************************80

void r8poly_power_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_POWER_TEST tests R8POLY_POWER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 July 2007
//
//  Author:
//
//    John Burkardt
//
{
# define LMAX 10

  double a[LMAX+1];
  double b[LMAX+1];
  int na;
  int p;

  cout << "\n";
  cout << "R8POLY_POWER_TEST\n";
  cout << "  R8POLY_POWER takes a polynomial to a power.\n";
//
//  Cube (2-X).  Answer is 8-12*X+6*X**2-X**3.
//
  na = 1;
  a[0] =  2.0;
  a[1] = -1.0;
  p = 3;

  r8poly_print ( na, a, "  The polynomial A:" );
 
  r8poly_power ( na, a, p, b );
 
  r8poly_print ( p*na, b, "  Raised to the power 3:" );
//
//  Square X+X**2
//
  na = 2;
  a[0] =  0.0;
  a[1] =  1.0;
  a[2] =  1.0;
  p = 2;

  r8poly_print ( na, a, "  The polynomial A:" );
 
  r8poly_power ( na, a, p, b );
 
  r8poly_print ( p*na, b, "  Raised to the power 2:" );
 
  return;
# undef LMAX
}
//****************************************************************************80

void r8poly_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_PRINT_TEST tests R8POLY_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  double c[6] = { 2.0, -3.4, 56.0, 0.0, 0.78, 9.0 };
  int m = 5;

  cout << "\n";
  cout << "R8POLY_PRINT_TEST\n";
  cout << "  R8POLY_PRINT prints an R8POLY.\n";

  r8poly_print ( m, c, "  The R8POLY:" );

  return;
}
//****************************************************************************80

void r8poly_value_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_VALUE_TEST tests R8POLY_VALUE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 August 2017
//
//  Author:
//
//    John Burkardt
//
{
  double c[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int i;
  int m = 4;
  int n = 16;
  double p;
  double *x;
  double x_hi;
  double x_lo;

  cout << "\n";
  cout << "R8POLY_VALUE_TEST\n";
  cout << "  R8POLY_VALUE evaluates a polynomial at\n";
  cout << "  one point, using a naive method.\n";

  r8poly_print ( m, c, "  The polynomial coefficients:" );

  x_lo = 0.0;
  x_hi = 5.0;
  x = r8vec_linspace_new ( n, x_lo, x_hi );

  cout << "\n";
  cout << "   I    X    P(X)\n";
  cout << "\n";

  for ( i = 0; i < n; i++ )
  {
    p = r8poly_value ( m, c, x[i] );
    cout << "  " << setw(2) << i
         << "  " << setw(8) << x[i]
         << "  " << setw(14) << p << "\n";
  }

  delete [] x;

  return;
}
//****************************************************************************80

void r8poly_value_horner_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_VALUE_HORNER_TEST tests R8POLY_VALUE_HORNER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  double c[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int i;
  int m = 4;
  int n = 16;
  double p;
  double *x;
  double x_hi;
  double x_lo;

  cout << "\n";
  cout << "R8POLY_VALUE_HORNER_TEST\n";
  cout << "  R8POLY_VALUE_HORNER evaluates a polynomial at\n";
  cout << "  one point, using Horner's method.\n";

  r8poly_print ( m, c, "  The polynomial coefficients:" );

  x_lo = 0.0;
  x_hi = 5.0;
  x = r8vec_linspace_new ( n, x_lo, x_hi );

  cout << "\n";
  cout << "   I    X    P(X)\n";
  cout << "\n";

  for ( i = 0; i < n; i++ )
  {
    p = r8poly_value_horner ( m, c, x[i] );
    cout << "  " << setw(2) << i
         << "  " << setw(8) << x[i]
         << "  " << setw(14) << p << "\n";
  }

  delete [] x;

  return;
}
//****************************************************************************80

void r8poly_values_horner_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY_VALUES_HORNER_TEST tests R8POLY_VALUES_HORNER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 December 2013
//
//  Author:
//
//    John Burkardt
//
{
  double c[5] = { 24.0, -50.0, +35.0, -10.0, 1.0 };
  int m = 4;
  int n = 16;
  double *p;
  double *x;
  double x_hi;
  double x_lo;

  cout << "\n";
  cout << "R8POLY_VALUES_HORNER_TEST\n";
  cout << "  R8POLY_VALUES_HORNER evaluates a polynomial at a\n";
  cout << "  point, using Horner's method.\n";

  r8poly_print ( m, c, "  The polynomial:" );

  x_lo = 0.0;
  x_hi = 5.0;
  x = r8vec_linspace_new ( n, x_lo, x_hi );

  p = r8poly_values_horner ( m, c, n, x );

  r8vec2_print ( n, x, p, "  X, P(X):" );

  delete [] p;
  delete [] x;

  return;
}
//****************************************************************************80

void r8poly2_ex_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY2_EX_TEST tests R8POLY2_EX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double c;
  int ierror;
  double x1;
  double x2;
  double x3;
  double xmin;
  double y1;
  double y2;
  double y3;
  double ymin;

  cout << "\n";
  cout << "R8POLY2_EX_TEST\n";
  cout << "  R8POLY2_EX finds the extreme value\n";
  cout << "  of a parabola determined by three points.\n";

  a =  2.0;
  b = -4.0;
  c = 10.0;

  x1 = 1.0;
  y1 = a * x1 * x1 + b * x1 + c;
  x2 = 2.0;
  y2 = a * x2 * x2 + b * x2 + c;
  x3 = 3.0;
  y3 = a * x3 * x3 + b * x3 + c;

  cout << "\n";
  cout << "  Parabolic coefficients A = "
    << a << ", B = " << b << ", c = " << c << "\n";
  cout << "\n";
  cout << "  X, Y data:\n";
  cout << "\n";
  cout << "  " << x1 << "  " << y1;
  cout << "  " << x2 << "  " << y2;
  cout << "  " << x3 << "  " << y3;

  a = 0.0;
  b = 0.0;
  c = 0.0;

  ierror = r8poly2_ex ( x1, y1, x2, y2, x3, y3, xmin, ymin );

  if ( ierror == 0 )
  {
    cout << "\n";
    cout << "  R8POLY2_EX returns XMIN = "
      << xmin << ", YMIN = " << ymin << "\n";
  }
  else
  {
    cout << "\n";
    cout << "  R8POLY2_EX returns error code " << ierror << ".\n";
  }

  return;
}
//****************************************************************************80

void r8poly2_ex2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY2_EX2_TEST tests R8POLY2_EX and R8POLY2_EX2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double c;
  int ierror;
  double x1;
  double x2;
  double x3;
  double xmin;
  double y1;
  double y2;
  double y3;
  double ymin;

  cout << "\n";
  cout << "R8POLY2_EX2_TEST\n";
  cout << "  R8POLY2_EX2 finds the extreme value\n";
  cout << "  of a parabola determined by three points.\n";

  a =  2.0;
  b = -4.0;
  c = 10.0;

  x1 = 1.0;
  y1 = a * x1 * x1 + b * x1 + c;
  x2 = 2.0;
  y2 = a * x2 * x2 + b * x2 + c;
  x3 = 3.0;
  y3 = a * x3 * x3 + b * x3 + c;

  cout << "\n";
  cout << "  Parabolic coefficients A = "
    << a << ", B = " << b << ", c = " << c << "\n";
  cout << "\n";
  cout << "  X, Y data:\n";
  cout << "\n";
  cout << "  " << x1 << "  " << y1;
  cout << "  " << x2 << "  " << y2;
  cout << "  " << x3 << "  " << y3;

  a = 0.0;
  b = 0.0;
  c = 0.0;

  ierror = r8poly2_ex2 ( x1, y1, x2, y2, x3, y3, xmin, ymin, a, b, c );

  if ( ierror == 0 )
  {
    cout << "\n";
    cout << "  R8POLY2_EX2 returns XMIN = "
      << xmin << ", YMIN = " << ymin << "\n";
    cout << "  and A = " << a << ", B = " << b << ", c = " << c << "\n";
  }
  else
  {
    cout << "\n";
    cout << "  R8POLY2_EX2 returns error code " << ierror << ".\n";
  }

  return;
}
//****************************************************************************80

void r8poly2_root_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY2_ROOT_TEST tests R8POLY2_ROOT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double a_test[3] = { 2.0, 1.0, 1.0 };
  double b;
  double b_test[3] = { -2.0, -20.0, -2.0 };
  double c;
  double c_test[3] = { -24.0, 100.0, 10.0 };
  complex <double> r1;
  complex <double> r2;
  int test;
  const int test_num = 3;

  cout << "\n";
  cout << "R8POLY2_ROOT_TEST\n";
  cout << "  R8POLY2_ROOT finds quadratic equation roots.\n";
  cout << "\n";
  cout << "         A         B         C     R1         R2\n";
  cout << "\n";

  for ( test = 0; test < test_num; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];

    r8poly2_root ( a, b, c, r1, r2 );

    cout << "  " << a
         << "  " << b
         << "  " << c
         << "  " << r1
         << "  " << r2 << "\n";
  }

  return;
}
//****************************************************************************80

void r8poly2_rroot_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY2_RROOT_TEST tests R8POLY2_RROOT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double a_test[5] = { 2.0,    1.0,  1.0, 1.0,  1.0 };
  double b;
  double b_test[5] = { -2.0,  -20.0, -2.0, 0.0, -6.0 };
  double c;
  double c_test[5] = { -24.0, 100.0, 10.0, 1.0, 10.0 };
  double r1;
  double r2;
  int test;
  const int test_num = 5;

  cout << "\n";
  cout << "R8POLY2_RROOT_TEST\n";
  cout << "  R8POLY2_RROOT finds the real parts of quadratic equation roots.\n";
  cout << "\n";
  cout << "         A         B         C     R1         R2\n";
  cout << "\n";

  for ( test = 0; test < test_num; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];

    r8poly2_rroot ( a, b, c, r1, r2 );
 
    cout << "  " << a
         << "  " << b
         << "  " << c
         << "  " << r1
         << "  " << r2 << "\n";
  }
 
  return;
}
//****************************************************************************80

void r8poly2_val_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY2_VAL_TEST tests R8POLY2_VAL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 January 2007
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double x;
  double x1;
  double x2;
  double x3;
  double y;
  double y1;
  double y2;
  double y3;
  double yp;
  double ypp;

  cout << "\n";
  cout << "R8POLY2_VAL_TEST\n";
  cout << "  R8POLY2_VAL evaluates a parabola given\n";
  cout << "  3 data points.\n";
  cout << "\n";
  cout << "  Our parabola will be 2*x^2 + 3 * x + 1.\n";
  cout << "\n";
  cout << "  Case 1: 3 distinct data points:\n";
  cout << "\n";

  x1 = -1.0;
  x2 = 1.0;
  x3 = 3.0;

  r8poly2_val_f ( x1, y1, yp, ypp );
  r8poly2_val_f ( x2, y2, yp, ypp );
  r8poly2_val_f ( x3, y3, yp, ypp );

  cout << "  " << x1 << " " << y1 << "\n";
  cout << "  " << x2 << " " << y2 << "\n";
  cout << "  " << x3 << " " << y3 << "\n";

  cout << "\n";
  cout << "  Sampled data:\n";
  cout << "\n";
  cout << "  X, Y, Y', Y''\n";
  cout << "\n";
  for ( i = 0; i < 4; i++ )
  {
    x = ( double ) i;
    r8poly2_val ( x1, y1, x2, y2, x3, y3, x, y, yp, ypp );
    cout << "  " << x << "  " << y << "  " << yp << "  " << ypp << "\n";
  }

  cout << "\n";
  cout << "  Case 2: X1=X2, X3 distinct:\n";
  cout << "\n";

  x1 = -1.0;
  x2 = -1.0;
  x3 = 3.0;

  r8poly2_val_f ( x1, y1, y2, ypp );
  r8poly2_val_f ( x3, y3, yp, ypp );

  cout << "  " << x1 << "  " << y1 << "\n";
  cout << "  " << x2 << "  " << y2 << "\n";
  cout << "  " << x3 << "  " << y3 << "\n";

  cout << "\n";
  cout << "  Sampled data:\n";
  cout << "\n";
  cout << "   X, Y, Y', Y''\n";
  cout << "\n";
  for ( i = 0; i < 4; i++ )
  {
    x = ( double ) i;
    r8poly2_val ( x1, y1, x2, y2, x3, y3, x, y, yp, ypp );
    cout << "  " << x << "  " << y << "  " << yp << "  " << ypp << "\n";
  }

  cout << "\n";
  cout << "  Case 3: X1=X2=X3:\n";
  cout << "\n";

  x1 = -1.0;
  x2 = -1.0;
  x3 = -1.0;

  r8poly2_val_f ( x1, y1, y2, y3 );

  cout << "  " << x1 << "  " << y1 << "\n";
  cout << "  " << x2 << "  " << y2 << "\n";
  cout << "  " << x3 << "  " << y3 << "\n";

  cout << "\n";
  cout << "  Sampled data:\n";
  cout << "\n";
  cout << "  X, Y, Y', Y''\n";
  cout << "\n";
  for ( i = 0; i < 4; i++ )
  {
    x = ( double ) i;
    r8poly2_val ( x1, y1, x2, y2, x3, y3, x, y, yp, ypp );
    cout << "  " << x << "  " << y << "  " << yp << "  " << ypp << "\n";
  }

  return;
}
//****************************************************************************80

void r8poly2_val_f ( double x, double &y, double &yp, double &ypp )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY2_VAL_F evaluates a parabola for us.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 December 2006
//
//  Author:
//
//    John Burkardt
//
{
  y = 2.0 * x * x + 3.0 * x + 1.0;
  yp = 4.0 * x + 3.0;
  ypp = 4.0;

  return;
}
//****************************************************************************80

void r8poly2_val2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY2_VAL2_TEST tests R8POLY2_VAL2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 December 2006
//
//  Author:
//
//    John Burkardt
//
{
# define NDATA 5

  int i;
  int left;
  double xdata[NDATA];
  double xval;
  double ydata[NDATA];
  double yval;
  double zdata[NDATA];
  double zval;

  cout << "\n";
  cout << "R8POLY2_VAL2_TEST\n";
  cout << "  R8POLY2_VAL2 evaluates parabolas through\n";
  cout << "  3 points in a table\n";
  cout << "\n";
  cout << "  Our data tables will actually be parabolas:\n";
  cout << "    A: 2*x^2 + 3 * x + 1.\n";
  cout << "    B: 4*x^2 - 2 * x + 5.\n";
  cout << "\n";

  for ( i = 0; i < NDATA; i++ )
  {
    xval = 2.0 * ( double ) ( i + 1 );
    xdata[i] = xval;
    ydata[i] = 2.0 * xval * xval + 3.0 * xval + 1.0;
    zdata[i] = 4.0 * xval * xval - 2.0 * xval + 5.0;
    cout << setw(6)  << i << " "
         << setw(10) << xdata[i] << "  "
         << setw(10) << ydata[i] << "  "
         << setw(10) << zdata[i] << "\n";
  }

  cout << "\n";
  cout << "  Interpolated data:\n";
  cout << "\n";
  cout << "  LEFT, X, Y1, Y2\n";
  cout << "\n";

  for ( i = 0; i <= 4; i++ )
  {
    xval = ( double ) ( 2 * i + 1 );
    left = i;
    if ( NDATA - 3 < left )
    {
      left = NDATA - 3;
    }
    if ( left < 0 )
    {
      left = 0;
    }
    r8poly2_val2 ( NDATA, xdata, ydata, left, xval, yval );
    r8poly2_val2 ( NDATA, xdata, zdata, left, xval, zval );

    cout << setw(6)  << left << "  "
         << setw(10) << xval << "  "
         << setw(10) << yval << "  "
         << setw(10) << zval << "\n";
  }

  return;
# undef NDATA
}
//****************************************************************************80

void r8poly3_root_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY3_ROOT_TEST tests R8POLY3_ROOT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double a_test[4] = { 1.0, 9.0, 1.0, 1.0 };
  double b;
  double b_test[4] = { -6.0, -36.0, -5.0, -8.0 };
  double c;
  double c_test[4] = { 11.0, 54.0, 8.0, 25.0 };
  double d;
  double d_test[4] = { -6.0, -27.0, -4.0, -26.0 };
  complex <double> r1;
  complex <double> r2;
  complex <double> r3;
  int test;
  const int test_num = 4;
//
//  1: Three distinct real roots, 1, 2, 3.
//  2: One repeated real root, 1.5, 1.5, 1.5.
//  3: Two real roots, one repeated, 1, 2, 2.
//  4: One real root, a complex conjugate pair, 2, 3+2I, 3-2I.
//
  cout << "\n";
  cout << "R8POLY3_ROOT_TEST\n";
  cout << "  R8POLY3_ROOT finds roots of cubic equations.\n";
  cout << "\n";

  for ( test = 0; test < test_num; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];
    d = d_test[test];

    cout << "\n";
    cout << "  Polynomial coefficients A, B, C, D:\n";
    cout << "\n";
    cout << "  " << a
         << "  " << b
         << "  " << c
         << "  " << d << "\n";

    r8poly3_root ( a, b, c, d, r1, r2, r3 );

    cout << "\n";
    cout << "  Roots:\n";
    cout << "\n";
    cout << "  " << r1 << "\n";
    cout << "  " << r2 << "\n";
    cout << "  " << r3 << "\n";
  }

  return;
}
//****************************************************************************80

void r8poly4_root_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8POLY4_ROOT_TEST tests R8POLY4_ROOT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double a_test[7] = {
    1.0, 1.0, 1.0, 1.0, 1.0, 
    1.0, 1.0 };
  double b;
  double b_test[7] = {
    -10.0, -5.0, -22.0, -16.0, -20.0, 
    2.0, 0.0 };
  double c;
  double c_test[7] = {
    35.0, 1.0, 141.0, 72.0, 150.0, 
    1.0, 13.0 };
  double d;
  double d_test[7] = {
    -50.0, 21.0, -220.0, -128.0, -500.0, 
    8.0, 0.0 };
  double e;
  double e_test[7] = {
    24.0, -18.0, +100.0, 80.0, 625.0, 
    -12.0, 36.0 };
  complex <double> r1;
  complex <double> r2;
  complex <double> r3;
  complex <double> r4;
  int test;
  const double test_num = 7;
//
//  1: Four distinct real roots, 1, 2, 3, 4.
//  2: Three distinct real roots, 1, -2, 3, 3
//  3: Two distinct real roots, 1, 1, 10, 10.
//  4: Two distinct real roots, 2, 2, 2, 10
//  5: One real root, 5, 5, 5, 5
//  6: Two distinct real roots, one complex conjugate pair.
//  7: Two distinct complex conjugate pairs.
//
  cout << "\n";
  cout << "R8POLY4_ROOT_TEST\n";
  cout << "  R8POLY4_ROOT finds roots of quartic equations.\n";
  cout << "\n";

  for ( test = 0; test < test_num; test++ )
  {
    a = a_test[test];
    b = b_test[test];
    c = c_test[test];
    d = d_test[test];
    e = e_test[test];

    cout << "\n";
    cout << "  Polynomial coefficients A, B, C, D, E:\n";
    cout << "\n";
    cout << "  " << a
         << "  " << b
         << "  " << c
         << "  " << d 
         << "  " << e << "\n";

    r8poly4_root ( a, b, c, d, e, r1, r2, r3, r4 );

    cout << "\n";
    cout << "  Roots:\n";
    cout << "\n";
    cout << "  " << r1 << "\n";
    cout << "  " << r2 << "\n";
    cout << "  " << r3 << "\n";
    cout << "  " << r4 << "\n";
  }

  return;
}
//****************************************************************************80

void r8vec_even_new_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_EVEN_NEW_TEST tests R8VEC_EVEN_NEW.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define N 10

  double *x;
  double xhi = 99.0;
  double xlo = 0.0;

  cout << "\n";
  cout << "R8VEC_EVEN_NEW_TEST\n";
  cout << "  R8VEC_EVEN_NEW computes N evenly spaced values\n";
  cout << "  between XLO and XHI.\n";
  cout << "\n";
  cout << "  XLO = " << xlo << "\n";
  cout << "  XHI = " << xhi << "\n";
  cout << "  while N = " << N << "\n";

  x = r8vec_even_new ( N, xlo, xhi );

  r8vec_print ( N, x, "  Resulting array:" );

  delete [] x;

  return;
# undef N
}
//****************************************************************************80

void r8vec_even_select_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_EVEN_SELECT_TEST tests R8VEC_EVEN_SELECT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int n = 10;
  int i;
  double xhi = 99.0;
  double xi;
  double xlo = 0.0;

  cout << "\n";
  cout << "R8VEC_EVEN_SELECT_TEST\n";
  cout << "  R8VEC_EVEN_SELECT computes one of N evenly spaced values\n";
  cout << "  between XLO and XHI.\n";
  cout << "\n";
  cout << "  XLO = " << xlo << "\n";
  cout << "  XHI = " << xhi << "\n";
  cout <<"  while N = " << n << "\n";

  for ( i = 2; i <= n; i = i + 3 )
  {
    xi = r8vec_even_select ( n, xlo, xhi, i );
    cout << "  " << setw(2) << i
         << "  " << setw(14) << xi << "\n";
  }

  return;
}
//****************************************************************************80

void r8vec_indicator1_new_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_INDICATOR1_NEW_TEST tests R8VEC_INDICATOR1_NEW.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 September 2014
//
//  Author:
//
//    John Burkardt
//
{
  int n;
  double *v;

  cout << "\n";
  cout << "R8VEC_INDICATOR1_NEW_TEST\n";
  cout << "  R8VEC_INDICATOR1_NEW returns an indicator1 vector.\n";

  n = 10;
  v = r8vec_indicator1_new ( n );
  r8vec_print ( n, v, "  Indicator1 vector:" );
  delete [] v;

  return;
}
//****************************************************************************80

void r8vec_is_distinct_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_IS_DISTINCT_TEST tests R8VEC_IS_DISTINCT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int n = 3;
  double x1[3] = { 0.0, 0.0, 0.0 };
  double x2[3] = { 1.0, 0.0, 1.0 };
  double x3[3] = { 0.0, 2.0, 1.0 };

  cout << "\n";
  cout << "R8VEC_IS_DISTINCT_TEST\n";
  cout << "  R8VEC_IS_DISTINCT is TRUE if an R8VEC only contains\n";
  cout << "  distinct entries.\n";

  cout << "\n";
  r8vec_transpose_print ( n, x1, "  X:" );
  if ( r8vec_is_distinct ( n, x1 ) )
  {
    cout << "  X is distinct.\n";
  }
  else
  {
    cout << "  X is NOT distinct.\n";
  }

  cout << "\n";
  r8vec_transpose_print ( n, x2, "  X:" );
  if ( r8vec_is_distinct ( n, x2 ) )
  {
    cout << "  X is distinct.\n";
  }
  else
  {
    cout << "  X is NOT distinct.\n";
  }

  cout << "\n";
  r8vec_transpose_print ( n, x3, "  X:" );
  if ( r8vec_is_distinct ( n, x3 ) )
  {
    cout << "  X is distinct.\n";
  }
  else
  {
    cout << "  X is NOT distinct.\n";
  }

  return;
}
//****************************************************************************80

void r8vec_linspace_new_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_LINSPACE_NEW_TEST tests R8VEC_LINSPACE_NEW.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 February 2015
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  int n = 5;
  double *x;

  cout << "\n";
  cout << "R8VEC_LINSPACE_NEW_TEST\n";
  cout << "  For a R8VEC:\n";
  cout << "  R8VEC_LINSPACE_NEW: evenly spaced points between A and B;\n";

  a = 10.0;
  b = 20.0;

  x = r8vec_linspace_new ( n, a, b );
  r8vec_print ( n, x, "  r8vec_linspace ( 5, 10, 20 )" );
  delete [] x;

  return;
}
//****************************************************************************80

void r8vec_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT_TEST tests R8VEC_PRINT.
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
  double a[4] = { 123.456, 0.000005, -1.0E+06, 3.14159265 };
  int n = 4;

  cout << "\n";
  cout << "R8VEC_PRINT_TEST\n";
  cout << "  R8VEC_PRINT prints an R8VEC.\n";

  r8vec_print ( n, a, "  The R8VEC:" );

  return;
}
//****************************************************************************80

void r8vec_transpose_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_TRANSPOSE_PRINT_TEST tests R8VEC_TRANSPOSE_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 November 2010
//
//  Author:
//
//    John Burkardt
//
{
  int n = 12;
  int seed;
  double *x;

  seed = 123456789;

  cout << "\n";
  cout << "R8VEC_TRANSPOSE_PRINT_TEST\n";
  cout << "  R8VEC_TRANSPOSE_PRINT prints an R8VEC \"transposed\",\n";
  cout << "  that is, placing multiple entries on a line.\n";

  x = r8vec_uniform_01_new ( n, seed );

  r8vec_transpose_print ( n, x, "  The vector X:" );

  delete [] x;

  return;
}
//****************************************************************************80

void r8vec_uniform_01_new_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01_NEW_TEST tests R8VEC_UNIFORM_01_NEW.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 October 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 10

  int j;
  double *r;
  int seed;

  cout << "\n";
  cout << "R8VEC_UNIFORM_01_NEW_TEST\n";
  cout << "  R8VEC_UNIFORM_01_NEW returns a random R8VEC\n";
  cout << "  with entries in [ 0.0, 1.0 ]\n";

  seed = 123456789;

  for ( j = 1; j <= 3; j++ )
  {
    cout << "\n";
    cout << "  Input SEED = " << seed << "\n";
    cout << "\n";

    r = r8vec_uniform_01_new ( N, seed );

    r8vec_print ( N, r, "  Random R8VEC:" );

    delete [] r;
  }

  return;
# undef N
}
//****************************************************************************80

void r8vec2_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC2_PRINT_TEST tests R8VEC2_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  double a[5] = { 1.0, 2.0, 3.0, 4.0, 5.0 };
  double b[5];
  double c[5];
  int i;
  int n = 5;

  cout << "\n";
  cout << "R8VEC2_PRINT_TEST\n";
  cout << "  R8VEC2_PRINT prints a pair of R8VEC's.\n";

  for ( i = 0; i < n; i++ )
  {
    b[i] = a[i] * a[i];
    c[i] = sqrt ( a[i] );
  }

  r8vec2_print ( n, b, c, "  Squares and square roots:" );

  return;
}
//****************************************************************************80

void roots_to_r8poly_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROOTS_TO_R8POLY_TEST tests ROOTS_TO_R8POLY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 March 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *c;
  int n = 5;
  double x[5] = { 1.0, -4.0, 3.0, 0.0, 3.0 };

  cout << "\n";
  cout << "ROOTS_TO_R8POLY_TEST:\n";
  cout << "  ROOTS_TO_R8POLY is given N real roots,\n";
  cout << "  and constructs the coefficient vector\n";
  cout << "  of the corresponding polynomial.\n";

  r8vec_print ( n, x, "  N real roots:" );

  c = roots_to_r8poly ( n, x );

  r8poly_print ( n, c, "  Corresponding polynomial:" );

  delete [] c;

  return;
}
