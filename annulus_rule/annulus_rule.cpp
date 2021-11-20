# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "annulus_rule.hpp"

//****************************************************************************80

double annulus_area ( double center[2], double r1, double r2 )

//****************************************************************************80
//
//  Purpose:
//
//    ANNULUS_AREA returns the area of an annulus in 2D.
//
//  Discussion:
//
//    A circular annulus with center (XC,YC), inner radius R1 and
//    outer radius R2, is the set of points (X,Y) so that
//
//      R1^2 <= (X-XC)^2 + (Y-YC)^2 <= R2^2
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
//    Input, double CENTER[2], coordinates of the center.
//    This information is not actually needed to compute the area.
//
//    Input, double R1, R2, the inner and outer radius of the disk.
//    0.0 <= R1 <= R2.
//
//    Output, double ANNULUS_AREA, the area of the annulus.
//
{
  double area;
  const double r8_pi = 3.141592653589793;

  if ( r1 < 0.0 )
  {
    cout << "\n";
    cout << "ANNULUS_AREA - Fatal error!\n";
    cout << "  Inner radius R1 < 0.0.\n";
    exit ( 1 );
  }

  if ( r2 < r1 )
  {
    cout << "\n";
    cout << "ANNULUS_AREA - Fatal error!\n";
    cout << "  Outer radius R2 < R1 = inner radius.\n";
    exit ( 1 );
  }

  area = r8_pi * ( r2 + r1 ) * ( r2 - r1 );

  return area;
}
//****************************************************************************80

void annulus_rule_compute ( double center[2], double r1, double r2, int nr, 
  int nt, double w[], double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    ANNULUS_RULE_COMPUTE computes a quadrature rule for an annulus.
//
//  Discussion:
//
//    The integration region is points (X,Y) such that
//
//      R1^2 <= ( X - CENTER(1) )^2 + ( Y - CENTER(2) )^2 <= R2^2
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
//  Reference:
//
//    William Peirce,
//    Numerical Integration Over the Planar Annulus,
//    Journal of the Society for Industrial and Applied Mathematics,
//    Volume 5, Issue 2, June 1957, pages 66-73.
//
//  Parameters:
//
//    Input, double CENTER(2), the coordinates of the center.
//
//    Input, double R1, R2, the inner and outer radii of the annulus.
//    0.0 <= R1 <= R2.
//
//    Input, int NR, the number of points in the radial rule.
//
//    Input, int NT, the number of angles to use.
//    The value NT=4*NR is recommended.
//
//    Output, double W[NR*NT], the weights for the rule.
//
//    Output, double X[NR*NT], Y[NR*NT], the points for the rule.
//
{
  double a;
  double area;
  double b;
  double c;
  double d;
  int i;
  int j;
  int k;
  const double r8_pi = 3.141592653589793;
  double *ra;
  double *rw;
  double t;
  double tw;
//
//  Request a Legendre rule for [-1,+1].
//
  ra = new double[nr];
  rw = new double[nr];

  legendre_ek_compute ( nr, ra, rw );
//
//  Adjust the rule from [-1,+1] to [r1^2,r2^2].
//
  a = -1.0;
  b = +1.0;
  c = r1 * r1;
  d = r2 * r2;
  rule_adjust ( a, b, c, d, nr, ra, rw );
//
//  Convert from R^2 to R.
//
  for ( i = 0; i < nr; i++ )
  {
    ra[i] = sqrt ( ra[i] );
  }
  for ( i = 0; i < nr; i++ )
  {
    rw[i] = rw[i] / ( r2 + r1 ) / ( r2 - r1 );
  }
//
//  Set the angular weight.
//
  tw = 1.0 / ( double ) ( nt );
//
//  Get area of annulus.
//
  area = annulus_area ( center, r1, r2 );
//
//  Form the abscissa and weight vectors.
//
  k = 0;
  for ( i = 0; i < nt; i++ )
  {
    t = 2.0 * r8_pi * ( double ) ( i ) / ( double ) ( nt );
    for ( j = 0; j < nr; j++ )
    {
      x[k] = center[0] + ra[j] * cos ( t );
      y[k] = center[1] + ra[j] * sin ( t );
      w[k] = area * tw * rw[j];
      k = k + 1;
    }
  }

  delete [] ra;
  delete [] rw;

  return;
}
//****************************************************************************80

double disk01_monomial_integral ( int e[2] )

//****************************************************************************80
//
//  Purpose:
//
//    DISK01_MONOMIAL_INTEGRAL returns monomial integrals in the unit disk in 2D.
//
//  Discussion:
//
//    The integration region is 
//
//      X^2 + Y^2 <= 1.
//
//    The monomial is F(X,Y) = X^E(1) * Y^E(2).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 January 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Philip Davis, Philip Rabinowitz,
//    Methods of Numerical Integration,
//    Second Edition,
//    Academic Press, 1984, page 263.
//
//  Parameters:
//
//    Input, int E[2], the exponents of X and Y in the 
//    monomial.  Each exponent must be nonnegative.
//
//    Output, double DISK01_MONOMIAL_INTEGRAL, the integral.
//
{
  double arg;
  int i;
  double integral;
  const double r = 1.0;
  double s;

  if ( e[0] < 0 || e[1] < 0 )
  {
    cerr << "\n";
    cerr << "DISK01_MONOMIAL_INTEGRAL - Fatal error!\n";
    cerr << "  All exponents must be nonnegative.\n";
    cerr << "  E[0] = " << e[0] << "\n";
    cerr << "  E[1] = " << e[1] << "\n";
    exit ( 1 );
  }

  if ( ( e[0] % 2 ) == 1 || ( e[1] % 2 ) == 1 )
  {
    integral = 0.0;
  }
  else
  {
    integral = 2.0;

    for ( i = 0; i < 2; i++ )
    {
      arg = 0.5 * ( double ) ( e[i] + 1 );
      integral = integral * r8_gamma ( arg );
    }
    arg = 0.5 * ( double ) ( e[0] + e[1] + 2 );
    integral = integral / r8_gamma ( arg );
  }
//
//  Adjust the surface integral to get the volume integral.
//
  s = e[0] + e[1] + 2;
  integral = integral * pow ( r, s ) / ( double ) ( s );

  return integral;
}
//****************************************************************************80

void imtqlx ( int n, double d[], double e[], double z[] )

//****************************************************************************80
//
//  Purpose:
//
//    IMTQLX diagonalizes a symmetric tridiagonal matrix.
//
//  Discussion:
//
//    This routine is a slightly modified version of the EISPACK routine to 
//    perform the implicit QL algorithm on a symmetric tridiagonal matrix. 
//
//    The authors thank the authors of EISPACK for permission to use this
//    routine. 
//
//    It has been modified to produce the product Q' * Z, where Z is an input 
//    vector and Q is the orthogonal matrix diagonalizing the input matrix.  
//    The changes consist (essentially) of applying the orthogonal transformations
//    directly to Z as they are generated.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 January 2010
//
//  Author:
//
//    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Sylvan Elhay, Jaroslav Kautsky,
//    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of 
//    Interpolatory Quadrature,
//    ACM Transactions on Mathematical Software,
//    Volume 13, Number 4, December 1987, pages 399-415.
//
//    Roger Martin, James Wilkinson,
//    The Implicit QL Algorithm,
//    Numerische Mathematik,
//    Volume 12, Number 5, December 1968, pages 377-383.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//
//    Input/output, double D(N), the diagonal entries of the matrix.
//    On output, the information in D has been overwritten.
//
//    Input/output, double E(N), the subdiagonal entries of the 
//    matrix, in entries E(1) through E(N-1).  On output, the information in
//    E has been overwritten.
//
//    Input/output, double Z(N).  On input, a vector.  On output,
//    the value of Q' * Z, where Q is the matrix that diagonalizes the
//    input symmetric tridiagonal matrix.
//
{
  double b;
  double c;
  double f;
  double g;
  int i;
  int ii;
  int itn = 30;
  int j;
  int k;
  int l;
  int m;
  int mml;
  double p;
  double prec;
  double r;
  double s;

  prec = r8_epsilon ( );

  if ( n == 1 )
  {
    return;
  }

  e[n-1] = 0.0;

  for ( l = 1; l <= n; l++ )
  {
    j = 0;
    for ( ; ; )
    {
      for ( m = l; m <= n; m++ )
      {
        if ( m == n )
        {
          break;
        }

        if ( fabs ( e[m-1] ) <= prec * ( fabs ( d[m-1] ) + fabs ( d[m] ) ) )
        {
          break;
        }
      }
      p = d[l-1];
      if ( m == l )
      {
        break;
      }
      if ( itn <= j )
      {
        cerr << "\n";
        cerr << "IMTQLX - Fatal error!\n";
        cerr << "  Iteration limit exceeded\n";
        exit ( 1 );
      }
      j = j + 1;
      g = ( d[l] - p ) / ( 2.0 * e[l-1] );
      r = sqrt ( g * g + 1.0 );
      g = d[m-1] - p + e[l-1] / ( g + fabs ( r ) * r8_sign ( g ) );
      s = 1.0;
      c = 1.0;
      p = 0.0;
      mml = m - l;

      for ( ii = 1; ii <= mml; ii++ )
      {
        i = m - ii;
        f = s * e[i-1];
        b = c * e[i-1];

        if ( fabs ( g ) <= fabs ( f ) )
        {
          c = g / f;
          r = sqrt ( c * c + 1.0 );
          e[i] = f * r;
          s = 1.0 / r;
          c = c * s;
        }
        else
        {
          s = f / g;
          r = sqrt ( s * s + 1.0 );
          e[i] = g * r;
          c = 1.0 / r;
          s = s * c;
        }
        g = d[i] - p;
        r = ( d[i-1] - g ) * s + 2.0 * c * b;
        p = s * r;
        d[i] = g + p;
        g = c * r - b;
        f = z[i];
        z[i] = s * z[i-1] + c * f;
        z[i-1] = c * z[i-1] - s * f;
      }
      d[l-1] = d[l-1] - p;
      e[l-1] = g;
      e[m-1] = 0.0;
    }
  }
//
//  Sorting.
//
  for ( ii = 2; ii <= m; ii++ )
  {
    i = ii - 1;
    k = i;
    p = d[i-1];

    for ( j = ii; j <= n; j++ )
    {
      if ( d[j-1] < p )
      {
         k = j;
         p = d[j-1];
      }
    }

    if ( k != i )
    {
      d[k-1] = d[i-1];
      d[i-1] = p;
      p = z[i-1];
      z[i-1] = z[k-1];
      z[k-1] = p;
    }
  }
  return;
}
//****************************************************************************80

void legendre_ek_compute ( int n, double x[], double w[] )

//****************************************************************************80
//
//  Purpose:
//
//    LEGENDRE_EK_COMPUTE: Legendre quadrature rule by the Elhay-Kautsky method.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 April 2011
//
//  Author:
//
//    Original FORTRAN77 version by Sylvan Elhay, Jaroslav Kautsky.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Sylvan Elhay, Jaroslav Kautsky,
//    Algorithm 655: IQPACK, FORTRAN Subroutines for the Weights of
//    Interpolatory Quadrature,
//    ACM Transactions on Mathematical Software,
//    Volume 13, Number 4, December 1987, pages 399-415.
//
//  Parameters:
//
//    Input, int N, the order.
//
//    Output, double X[N], the abscissas.
//
//    Output, double W[N], the weights.
//
{
  double *bj;
  int i;
  double zemu;
//
//  Define the zero-th moment.
//
  zemu = 2.0;
//
//  Define the Jacobi matrix.
//
  bj = new double[n];

  for ( i = 0; i < n; i++ )
  {
    bj[i] = ( double ) ( ( i + 1 ) * ( i + 1 ) ) 
          / ( double ) ( 4 * ( i + 1 ) * ( i + 1 ) - 1 );
    bj[i] = sqrt ( bj[i] );
  }

  for ( i = 0; i < n; i++ )
  {
    x[i] = 0.0;
  }

  w[0] = sqrt ( zemu );

  for ( i = 1; i < n; i++ )
  {
    w[i] = 0.0;
  }
//
//  Diagonalize the Jacobi matrix.
//
  imtqlx ( n, x, bj, w );

  for ( i = 0; i < n; i++ )
  {
    w[i] = w[i] * w[i];
  }

  delete [] bj;

  return;
}
//****************************************************************************80

double *monomial_value ( int m, int n, int e[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    MONOMIAL_VALUE evaluates a monomial.
//
//  Discussion:
//
//    This routine evaluates a monomial of the form
//
//      product ( 1 <= i <= m ) x(i)^e(i)
//
//    where the exponents are nonnegative integers.  Note that
//    if the combination 0^0 is encountered, it should be treated
//    as 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 May 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the spatial dimension.
//
//    Input, int N, the number of points at which the
//    monomial is to be evaluated.
//
//    Input, int E[M], the exponents.
//
//    Input, double X[M*N], the point coordinates.
//
//    Output, double MONOMIAL_VALUE[N], the value of the monomial.
//
{
  int i;
  int j;
  double *v;

  v = new double[n];

  for ( j = 0; j < n; j++ )
  {
    v[j] = 1.0;
  }

  for ( i = 0; i < m; i++ )
  {
    if ( 0 != e[i] )
    {
      for ( j = 0; j < n; j++ )
      {
        v[j] = v[j] * pow ( x[i+j*m], e[i] );
      }
    }
  }

  return v;
}
//****************************************************************************80

double r8_epsilon ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_EPSILON returns the R8 roundoff unit.
//
//  Discussion:
//
//    The roundoff unit is a number R which is a power of 2 with the
//    property that, to the precision of the computer's arithmetic,
//      1 < 1 + R
//    but
//      1 = ( 1 + R / 2 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 September 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double R8_EPSILON, the R8 round-off unit.
//
{
  const double value = 2.220446049250313E-016;

  return value;
}
//****************************************************************************80

double r8_gamma ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_GAMMA evaluates Gamma(X) for an R8.
//
//  Discussion:
//
//    The C MATH library includes a function GAMMA ( X ) which should be
//    invoked instead of this function.
//
//    This routine calculates the gamma function for a real argument X.
//
//    Computation is based on an algorithm outlined in reference 1.
//    The program uses rational functions that approximate the gamma
//    function to at least 20 significant decimal digits.  Coefficients
//    for the approximation over the interval (1,2) are unpublished.
//    Those for the approximation for 12 <= X are from reference 2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 January 2008
//
//  Author:
//
//    Original FORTRAN77 version by William Cody, Laura Stoltz.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    William Cody,
//    An Overview of Software Development for Special Functions,
//    in Numerical Analysis Dundee, 1975,
//    edited by GA Watson,
//    Lecture Notes in Mathematics 506,
//    Springer, 1976.
//
//    John Hart, Ward Cheney, Charles Lawson, Hans Maehly,
//    Charles Mesztenyi, John Rice, Henry Thatcher,
//    Christoph Witzgall,
//    Computer Approximations,
//    Wiley, 1968,
//    LC: QA297.C64.
//
//  Parameters:
//
//    Input, double X, the argument of the function.
//
//    Output, double R8_GAMMA, the value of the function.
//
{
  double c[7] = {
   -1.910444077728E-03, 
    8.4171387781295E-04, 
   -5.952379913043012E-04, 
    7.93650793500350248E-04, 
   -2.777777777777681622553E-03, 
    8.333333333333333331554247E-02, 
    5.7083835261E-03 };
  double eps = 2.22E-16;
  double fact;
  int i;
  int n;
  double p[8] = {
  -1.71618513886549492533811E+00,
   2.47656508055759199108314E+01, 
  -3.79804256470945635097577E+02,
   6.29331155312818442661052E+02, 
   8.66966202790413211295064E+02,
  -3.14512729688483675254357E+04, 
  -3.61444134186911729807069E+04,
   6.64561438202405440627855E+04 };
  bool parity;
  const double pi = 3.1415926535897932384626434;
  double q[8] = {
  -3.08402300119738975254353E+01,
   3.15350626979604161529144E+02, 
  -1.01515636749021914166146E+03,
  -3.10777167157231109440444E+03, 
   2.25381184209801510330112E+04,
   4.75584627752788110767815E+03, 
  -1.34659959864969306392456E+05,
  -1.15132259675553483497211E+05 };
  double res;
  const double sqrtpi = 0.9189385332046727417803297;
  double sum;
  double value;
  double xbig = 171.624;
  double xden;
  double xinf = 1.79E+308;
  double xminin = 2.23E-308;
  double xnum;
  double y;
  double y1;
  double ysq;
  double z;

  parity = false;
  fact = 1.0;
  n = 0;
  y = x;
//
//  Argument is negative.
//
  if ( y <= 0.0 )
  {
    y = - x;
    y1 = ( double ) ( int ) ( y );
    res = y - y1;

    if ( res != 0.0 )
    {
      if ( y1 != ( double ) ( int ) ( y1 * 0.5 ) * 2.0 )
      {
        parity = true;
      }

      fact = - pi / sin ( pi * res );
      y = y + 1.0;
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
//
//  Argument is positive.
//
  if ( y < eps )
  {
//
//  Argument < EPS.
//
    if ( xminin <= y )
    {
      res = 1.0 / y;
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
  else if ( y < 12.0 )
  {
    y1 = y;
//
//  0.0 < argument < 1.0.
//
    if ( y < 1.0 )
    {
      z = y;
      y = y + 1.0;
    }
//
//  1.0 < argument < 12.0.
//  Reduce argument if necessary.
//
    else
    {
      n = ( int ) ( y ) - 1;
      y = y - ( double ) ( n );
      z = y - 1.0;
    }
//
//  Evaluate approximation for 1.0 < argument < 2.0.
//
    xnum = 0.0;
    xden = 1.0;
    for ( i = 0; i < 8; i++ )
    {
      xnum = ( xnum + p[i] ) * z;
      xden = xden * z + q[i];
    }
    res = xnum / xden + 1.0;
//
//  Adjust result for case  0.0 < argument < 1.0.
//
    if ( y1 < y )
    {
      res = res / y1;
    }
//
//  Adjust result for case 2.0 < argument < 12.0.
//
    else if ( y < y1 )
    {
      for ( i = 1; i <= n; i++ )
      {
        res = res * y;
        y = y + 1.0;
      }
    }
  }
  else
  {
//
//  Evaluate for 12.0 <= argument.
//
    if ( y <= xbig )
    {
      ysq = y * y;
      sum = c[6];
      for ( i = 0; i < 6; i++ )
      {
        sum = sum / ysq + c[i];
      }
      sum = sum / y - y + sqrtpi;
      sum = sum + ( y - 0.5 ) * log ( y );
      res = exp ( sum );
    }
    else
    {
      res = xinf;
      value = res;
      return value;
    }
  }
//
//  Final adjustments and return.
//
  if ( parity )
  {
    res = - res;
  }

  if ( fact != 1.0 )
  {
    res = fact / res;
  }

  value = res;

  return value;
}
//****************************************************************************80

double r8_sign ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_SIGN returns the sign of an R8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 October 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the number whose sign is desired.
//
//    Output, double R8_SIGN, the sign of X.
//
{
  double value;

  if ( x < 0.0 )
  {
    value = -1.0;
  }
  else
  {
    value = 1.0;
  }
  return value;
}
//****************************************************************************80

double r8vec_dot_product ( int n, double a1[], double a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_DOT_PRODUCT computes the dot product of a pair of R8VEC's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 July 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input, double A1[N], A2[N], the two vectors to be considered.
//
//    Output, double R8VEC_DOT_PRODUCT, the dot product of the vectors.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a1[i] * a2[i];
  }
  return value;
}
//****************************************************************************80

void r8vec_print ( int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT prints an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(8)  << i
         << ": " << setw(14) << a[i]  << "\n";
  }

  return;
}
//****************************************************************************80

double *r8vec_uniform_01_new ( int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01_NEW returns a new unit pseudorandom R8VEC.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
//      u = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Second Edition,
//    Springer, 1987,
//    ISBN: 0387964673,
//    LC: QA76.9.C65.B73.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, December 1986, pages 362-376.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998,
//    ISBN: 0471134031,
//    LC: T57.62.H37.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, Number 2, 1969, pages 136-143.
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input/output, int &SEED, a seed for the random number generator.
//
//    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
//
{
  int i;
  int i4_huge = 2147483647;
  int k;
  double *r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8VEC_UNIFORM_01_NEW - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  r = new double[n];

  for ( i = 0; i < n; i++ )
  {
    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )
    {
      seed = seed + i4_huge;
    }

    r[i] = ( double ) ( seed ) * 4.656612875E-10;
  }

  return r;
}
//****************************************************************************80

void r8vec3_print ( int n, double a1[], double a2[], double a3[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC3_PRINT prints a triple of real vectors.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A1[N], double A2[N], double A3[N], the vectors
//    to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i <= n - 1; i++ )
  {
    cout << setw(4)  << i     << ": "
         << setw(10) << a1[i] << "  "
         << setw(10) << a2[i] << "  "
         << setw(10) << a3[i] << "\n";
  }

  return;
}
//****************************************************************************80

void rule_adjust ( double a, double b, double c, double d, int order,
  double x[], double w[] )

//****************************************************************************80
//
//  Purpose:
//
//    RULE_ADJUST maps a quadrature rule from [A,B] to [C,D].
//
//  Discussion:
//
//    Most quadrature rules are defined on a special interval, like
//    [-1,1] or [0,1].  To integrate over an interval, the abscissas
//    and weights must be adjusted.  This can be done on the fly,
//    or by calling this routine.
//
//    If the weight function W(X) is not 1, then the W vector will
//    require further adjustment by the user.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 March 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double A, B, the endpoints of the definition interval.
//
//    Input, double C, D, the endpoints of the integration interval.
//
//    Input, int ORDER, the number of abscissas and weights.
//
//    Input/output, double X[ORDER], W[ORDER], the abscissas
//    and weights.
//
{
  int i;

  for ( i = 0; i < order; i++ )
  {
    x[i] = ( ( b - x[i]     ) * c
           + (     x[i] - a ) * d )
           / ( b              - a );
  }

  for ( i = 0; i < order; i++ )
  {
    w[i] = ( ( d - c ) / ( b - a ) ) * w[i];
  }

  return;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    31 May 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    None
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
