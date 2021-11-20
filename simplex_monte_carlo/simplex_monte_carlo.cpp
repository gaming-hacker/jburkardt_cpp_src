# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <cstring>

using namespace std;

# include "simplex_monte_carlo.hpp"

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
//    05 May 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the spatial dimension.
//
//    Input, int POINT_NUM, the number of points at which the
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

double r8ge_det ( int n, double a_lu[], int pivot[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8GE_DET computes the determinant of a matrix factored by R8GE_FA or R8GE_TRF.
//
//  Discussion:
//
//    The R8GE storage format is used for a "general" M by N matrix.  
//    A physical storage space is made for each logical entry.  The two 
//    dimensional logical array is mapped to a vector, in which storage is 
//    by columns.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2004
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Jack Dongarra, Jim Bunch, Cleve Moler, Pete Stewart,
//    LINPACK User's Guide,
//    SIAM, 1979,
//    ISBN13: 978-0-898711-72-1,
//    LC: QA214.L56.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input, double A_LU[N*N], the LU factors from R8GE_FA or R8GE_TRF.
//
//    Input, int PIVOT[N], as computed by R8GE_FA or R8GE_TRF.
//
//    Output, double R8GE_DET, the determinant of the matrix.
//
{
  double det;
  int i;

  det = 1.0;

  for ( i = 1; i <= n; i++ )
  {
    det = det * a_lu[i-1+(i-1)*n];
    if ( pivot[i-1] != i )
    {
      det = -det;
    }
  }

  return det;
}
//****************************************************************************80

int r8ge_fa ( int n, double a[], int pivot[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8GE_FA performs a LINPACK-style PLU factorization of an R8GE matrix.
//
//  Discussion:
//
//    The R8GE storage format is used for a "general" M by N matrix.  
//    A physical storage space is made for each logical entry.  The two 
//    dimensional logical array is mapped to a vector, in which storage is 
//    by columns.
//
//    R8GE_FA is a simplified version of the LINPACK routine SGEFA.
//
//    The two dimensional array is stored by columns in a one dimensional
//    array.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 September 2003
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Jack Dongarra, Jim Bunch, Cleve Moler, Pete Stewart,
//    LINPACK User's Guide,
//    SIAM, 1979,
//    ISBN13: 978-0-898711-72-1,
//    LC: QA214.L56.
//
//  Parameters:
//
//    Input, int N, the order of the matrix.
//    N must be positive.
//
//    Input/output, double A[N*N], the matrix to be factored.
//    On output, A contains an upper triangular matrix and the multipliers
//    which were used to obtain it.  The factorization can be written
//    A = L * U, where L is a product of permutation and unit lower
//    triangular matrices and U is upper triangular.
//
//    Output, int PIVOT[N], a vector of pivot indices.
//
//    Output, int R8GE_FA, singularity flag.
//    0, no singularity detected.
//    nonzero, the factorization failed on the INFO-th step.
//
{
  int i;
  int j;
  int k;
  int l;
  double t;
//
  for ( k = 1; k <= n-1; k++ )
  {
//
//  Find L, the index of the pivot row.
//
    l = k;

    for ( i = k + 1; i <= n; i++ )
    {
      if ( fabs ( a[l-1+(k-1)*n] ) < fabs ( a[i-1+(k-1)*n] ) )
      {
        l = i;
      }
    }

    pivot[k-1] = l;
//
//  If the pivot index is zero, the algorithm has failed.
//
    if ( a[l-1+(k-1)*n] == 0.0 )
    {
      cerr << "\n";
      cerr << "R8GE_FA - Fatal error!\n";
      cerr << "  Zero pivot on step " << k << "\n";
      exit ( 1 );
    }
//
//  Interchange rows L and K if necessary.
//
    if ( l != k )
    {
      t              = a[l-1+(k-1)*n];
      a[l-1+(k-1)*n] = a[k-1+(k-1)*n];
      a[k-1+(k-1)*n] = t;
    }
//
//  Normalize the values that lie below the pivot entry A(K,K).
//
    for ( i = k+1; i <= n; i++ )
    {
      a[i-1+(k-1)*n] = -a[i-1+(k-1)*n] / a[k-1+(k-1)*n];
    }
//
//  Row elimination with column indexing.
//
    for ( j = k+1; j <= n; j++ )
    {
      if ( l != k )
      {
        t              = a[l-1+(j-1)*n];
        a[l-1+(j-1)*n] = a[k-1+(j-1)*n];
        a[k-1+(j-1)*n] = t;
      }

      for ( i = k+1; i <= n; i++ )
      {
        a[i-1+(j-1)*n] = a[i-1+(j-1)*n] + a[i-1+(k-1)*n] * a[k-1+(j-1)*n];
      }

    }

  }

  pivot[n-1] = n;

  if ( a[n-1+(n-1)*n] == 0.0 )
  {
    cerr << "\n";
    cerr << "R8GE_FA - Fatal error!\n";
    cerr << "  Zero pivot on step " << n << "\n";
    exit ( 1 );
  }

  return 0;
}
//****************************************************************************80

double r8vec_sum ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_SUM returns the sum of an R8VEC.
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
//    15 October 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input, double A[N], the vector.
//
//    Output, double R8VEC_SUM, the sum of the vector.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + a[i];
  }

  return value;
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

double *simplex_general_sample ( int m, int n, double t[], int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    SIMPLEX_GENERAL_SAMPLE samples a general simplex in M dimensions.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 March 2017
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Reuven Rubinstein,
//    Monte Carlo Optimization, Simulation, and Sensitivity 
//    of Queueing Networks,
//    Krieger, 1992,
//    ISBN: 0894647644,
//    LC: QA298.R79.
//
//  Parameters:
//
//    Input, int M, the spatial dimension.
//
//    Input, int N, the number of points.
//
//    Input, double T[M*(M+1)], the simplex vertices.
//
//    Input/output, int &SEED, a seed for the random number generator.
//
//    Output, double SIMPLEX_GENERAL_SAMPLE[M*N], the points.
//
{
  double *x;
  double *x1;

  x1 = simplex_unit_sample ( m, n, seed );

  x = new double[m*n];

  simplex_unit_to_general ( m, n, t, x1, x );

  delete [] x1;

  return x;
}
//****************************************************************************80

double simplex_general_volume ( int m, double t[] )

//****************************************************************************80
//
//  Purpose:
//
//    SIMPLEX_GENERAL_VOLUME computes the volume of a simplex in N dimensions.
//
//  Discussion:
//
//    The formula is: 
//
//      volume = 1/M! * det ( B )
//
//    where B is the M by M matrix obtained by subtracting one
//    vector from all the others.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 March 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the dimension of the space.
//
//    Input, double T[M*(M+1)], the vertices.
//
//    Output, double SIMPLEX_GENERAL_VOLUME, the volume of the simplex.
//
{
  double *b;
  double det;
  int i;
  int j;
  int *pivot;
  double volume;

  pivot = new int[m];
  b = new double[m*m];

  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      b[i+j*m] = t[i+j*m] - t[i+m*m];
    }
  }

  r8ge_fa ( m, b, pivot );

  det = r8ge_det ( m, b, pivot );

  volume = fabs ( det );
  for ( i = 1; i <= m; i++ )
  {
    volume = volume / ( double ) ( i );
  }

  delete [] b;
  delete [] pivot;

  return volume;
}
//****************************************************************************80

double simplex_unit_monomial_integral ( int m, int e[] )

//****************************************************************************80
//
//  Purpose:
//
//    SIMPLEX_UNIT_MONOMIAL_INTEGRAL: integrals in the unit simplex in M dimensions.
//
//  Discussion:
//
//    The monomial is F(X) = product ( 1 <= I <= M ) X(I)^E(I).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 January 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the spatial dimension.
//
//    Input, int E[M], the exponents.  
//    Each exponent must be nonnegative.
//
//    Output, double SIMPLEX_UNIT_MONOMIAL_INTEGRAL, the integral.
//
{
  int i;
  double integral;
  int j;
  int k;

  for ( i = 0; i < m; i++ )
  {
    if ( e[i] < 0 )
    {
      cerr << "\n";
      cerr << "SIMPLEX_UNIT_MONOMIAL_INTEGRAL - Fatal error!\n";
      cerr << "  All exponents must be nonnegative.\n";
      exit ( 1 );
    }
  }

  k = 0;
  integral = 1.0;

  for ( i = 0; i < m; i++ )
  {
    for ( j = 1; j <= e[i]; j++ )
    {
      k = k + 1;
      integral = integral * ( double ) ( j ) / ( double ) ( k );
    }
  }

  for ( i = 0; i < m; i++ )
  {
    k = k + 1;
    integral = integral / ( double ) ( k );
  }

  return integral;
}
//****************************************************************************80

double *simplex_unit_sample ( int m, int n, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    SIMPLEX_UNIT_SAMPLE samples the unit simplex in M dimensions.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Reuven Rubinstein,
//    Monte Carlo Optimization, Simulation, and Sensitivity 
//    of Queueing Networks,
//    Krieger, 1992,
//    ISBN: 0894647644,
//    LC: QA298.R79.
//
//  Parameters:
//
//    Input, int M, the spatial dimension.
//
//    Input, int N, the number of points.
//
//    Input/output, int &SEED, a seed for the random 
//    number generator.
//
//    Output, double SIMPLEX_UNIT_SAMPLE_01[M*N], the points.
//
{
  double *e;
  double e_sum;
  int i;
  int j;
  double *x;

  x = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    e = r8vec_uniform_01_new ( m + 1, seed );

    for ( i = 0; i < m + 1; i++ )
    {
      e[i] = - log ( e[i] );
    }
    e_sum = r8vec_sum ( m + 1, e );

    for ( i = 0; i < m; i++ )
    {
      x[i+j*m] = e[i] / e_sum;
    }
    delete [] e;
  }

  return x;
}
//****************************************************************************80

void simplex_unit_to_general ( int m, int n, double t[], double ref[],
  double phy[] )

//****************************************************************************80
//
//  Purpose:
//
//    SIMPLEX_UNIT_TO_GENERAL maps the unit simplex to a general simplex.
//
//  Discussion:
//
//    Given that the unit simplex has been mapped to a general simplex
//    with vertices T, compute the images in T, under the same linear
//    mapping, of points whose coordinates in the unit simplex are REF.
//
//    The vertices of the unit simplex are listed as suggested in the
//    following:
//
//      (0,0,0,...,0)
//      (1,0,0,...,0)
//      (0,1,0,...,0)
//      (0,0,1,...,0)
//      (...........)
//      (0,0,0,...,1)
//
//    Thanks to Andrei ("spiritualworlds") for pointing out a mistake in the
//    previous implementation of this routine, 02 March 2008.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 March 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the spatial dimension.
//
//    Input, int N, the number of points to transform.
//
//    Input, double T[M*(M+1)], the vertices of the
//    general simplex.
//
//    Input, double REF[M*N], points in the
//    reference triangle.
//
//    Output, double PHY[M*N], corresponding points in the physical triangle.
//
{
  int dim;
  int point;
  int vertex;
//
//  The image of each point is initially the image of the origin.
//
//  Insofar as the pre-image differs from the origin in a given vertex
//  direction, add that proportion of the difference between the images
//  of the origin and the vertex.
//
  for ( point = 0; point < n; point++ )
  {
    for ( dim = 0; dim < m; dim++ )
    {
      phy[dim+point*m] = t[dim+0*m];

      for ( vertex = 1; vertex < m + 1; vertex++ )
      {
        phy[dim+point*m] = phy[dim+point*m]
        + ( t[dim+vertex*m] - t[dim+0*m] ) * ref[vertex-1+point*m];
      }
    }
  }

  return;
}
//****************************************************************************80

double simplex_unit_volume ( int m )

//****************************************************************************80
//
//  Purpose:
//
//    SIMPLEX_UNIT_VOLUME returns the volume of the unit simplex in M dimensions.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 January 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the spatial dimension.
//
//    Output, double SIMPLEX_UNIT_VOLUME, the volume.
//
{
  int i;
  double volume;

  volume = 1.0;
  for ( i = 1; i <= m; i++ )
  {
    volume = volume / ( double ) ( i );
  }

  return volume;
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
