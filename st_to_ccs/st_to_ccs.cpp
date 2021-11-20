# include <cmath>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <iomanip>
# include <ctime>
# include <cstring>

using namespace std;

# include "st_to_ccs.hpp"

//****************************************************************************80

double *ccs_mv ( int m, int n, int ncc, int icc[], int ccc[], double acc[], 
  double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    ccs_MV multiplies a CCS matrix by a vector
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Iain Duff, Roger Grimes, John Lewis,
//    User's Guide for the Harwell-Boeing Sparse Matrix Collection,
//    October 1992
//
//  Parameters:
//
//    Input, int M, the number of rows.
//
//    Input, int N, the number of columns.
//
//    Input, int NCC, the number of CCS values.
//
//    Input, int ICC[NCC], the CCS rows.
//
//    Input, int CCC[N+1], the compressed CCS columns
//
//    Input, double ACC[NCC], the CCS values.
//
//    Input, double X[N], the vector to be multiplied.
//
//    Output, double ccs_MV[M], the product A*X.
//
{
  double *b;
  int i;
  int j;
  int k;

  b = new double[m];

  for ( i = 0; i < m; i++ )
  {
    b[i] = 0.0;
  }

  for ( j = 0; j < n; j++ )
  {
    for ( k = ccc[j]; k < ccc[j+1]; k++ )
    {
      i = icc[k];
      b[i] = b[i] + acc[k] * x[j];
    }
  }

  return b;
}
//****************************************************************************80

void ccs_print ( int m, int n, int ncc, int icc[], int ccc[], double acc[], 
  string title )

//****************************************************************************80
//
//  Purpose:
//
//    ccs_PRINT prints a sparse matrix in CCS format.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows in the matrix.
//
//    Input, int N, the number of columns in the matrix.
//
//    Input, int NCC, the number of CCS elements.
//
//    Input, int ICC[NCC], the CCS rows.
//
//    Input, int CCC[N+1], the compressed CCS columns.
//
//    Input, double ACC[NCC], the CCS values.
//
//    Input, string TITLE, a title.
//
{
  int i;
  int j;
  int k;

  cout << "\n";
  cout << title << "\n";
  cout << "     #     I     J         A\n";
  cout << "  ----  ----  ----  ----------------\n";
  cout << "\n";

  if ( ccc[0] == 0 )
  {
    j = 0;
    for ( k = 0; k < ncc; k++ )
    {
      i = icc[k];
      while ( ccc[j+1] <= k )
      {
        j = j + 1;
      }
      cout << setw(4) << k << "  "
           << setw(4) << i << "  "
           << setw(4) << j << "  "
           << setw(16) << acc[k] << "\n";
    }
  }
  else
  {
    j = 1;
    for ( k = 0; k < ncc; k++ )
    {
      i = icc[k];
      while ( ccc[j] <= k + 1 )
      {
        j = j + 1;
      }
      cout << setw(4) << k + 1 << "  "
           << setw(4) << i << "  "
           << setw(4) << j << "  "
          << setw(16) << acc[k] << "\n";
    }
  }

  return;
}
//****************************************************************************80

int i4_max ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MAX returns the maximum of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, are two integers to be compared.
//
//    Output, int I4_MAX, the larger of I1 and I2.
//
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
//****************************************************************************80

int i4_min ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MIN returns the minimum of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, two integers to be compared.
//
//    Output, int I4_MIN, the smaller of I1 and I2.
//
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
//****************************************************************************80

int *i4vec_copy_new ( int n, int a1[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_COPY_NEW copies an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input, int A1[N], the vector to be copied.
//
//    Output, int I4VEC_COPY_NEW[N], the copy of A1.
//
{
  int *a2;
  int i;

  a2 = new int[n];

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return a2;
}
//****************************************************************************80

void i4vec_dec ( int n, int a[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_DEC decrements an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input/output, int A[N], the vector to be decremented.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a[i] = a[i] - 1;
  }
  return;
}
//****************************************************************************80

void i4vec_inc ( int n, int a[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_INC increments an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input/output, int A[N], the vector to be incremented.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a[i] = a[i] + 1;
  }
  return;
}
//****************************************************************************80

int i4vec_max ( int n, int a[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_MAX returns the value of the maximum element in an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 May 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the array.
//
//    Input, int A[N], the array to be checked.
//
//    Output, int I4VEC_MAX, the value of the maximum element.  This
//    is set to 0 if N <= 0.
//
{
  int i;
  int value;

  if ( n <= 0 )
  {
    return 0;
  }

  value = a[0];

  for ( i = 1; i < n; i++ )
  {
    if ( value < a[i] )
    {
      value = a[i];
    }
  }

  return value;
}
//****************************************************************************80

int i4vec_min ( int n, int a[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_MIN returns the value of the minimum element in an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 May 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the array.
//
//    Input, int A[N], the array to be checked.
//
//    Output, int I4VEC_MIN, the value of the minimum element.  This
//    is set to 0 if N <= 0.
//
{
  int i;
  int value;

  if ( n <= 0 )
  {
    return 0;
  }

  value = a[0];

  for ( i = 1; i < n; i++ )
  {
    if ( a[i] < value )
    {
      value = a[i];
    }
  }
  return value;
}
//****************************************************************************80

void i4vec_write ( string output_filename, int n, int table[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_WRITE writes an I4VEC to a file.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string OUTPUT_FILENAME, the output filename.
//
//    Input, int N, the number of points.
//
//    Input, int TABLE[N], the data.
//
{
  int j;
  ofstream output;
//
//  Open the file.
//
  output.open ( output_filename.c_str ( ) );

  if ( !output )
  {
    cerr << "\n";
    cerr << "I4VEC_WRITE - Fatal error!\n";
    cerr << "  Could not open the output file.\n";
    exit ( 1 );
  }
//
//  Write the data.
//
  for ( j = 0; j < n; j++ )
  {
    output << table[j] << "\n";
  }
//
//  Close the file.
//
  output.close ( );

  return;
}
//****************************************************************************80

int i4vec2_compare ( int n, int a1[], int a2[], int i, int j )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC2_COMPARE compares pairs of integers stored in two vectors.
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
//  Parameters:
//
//    Input, int N, the number of data items.
//
//    Input, int A1[N], A2[N], contain the two components of each item.
//
//    Input, int I, J, the items to be compared.  These values will be
//    1-based indices for the arrays A1 and A2.
//
//    Output, int I4VEC2_COMPARE, the results of the comparison:
//    -1, item I < item J,
//     0, item I = item J,
//    +1, item J < item I.
//
{
  int isgn;

  isgn = 0;

  if ( a1[i-1] < a1[j-1] )
  {
    isgn = -1;
  }
  else if ( a1[i-1] == a1[j-1] )
  {
    if ( a2[i-1] < a2[j-1] )
    {
      isgn = -1;
    }
    else if ( a2[i-1] < a2[j-1] )
    {
      isgn = 0;
    }
    else if ( a2[j-1] < a2[i-1] )
    {
      isgn = +1;
    }
  }
  else if ( a1[j-1] < a1[i-1] )
  {
    isgn = +1;
  }

  return isgn;
}
//****************************************************************************80

void i4vec2_sort_a ( int n, int a1[], int a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC2_SORT_A ascending sorts an I4VEC2.
//
//  Discussion:
//
//    Each item to be sorted is a pair of integers (I,J), with the I
//    and J values stored in separate vectors A1 and A2.
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
//  Parameters:
//
//    Input, int N, the number of items of data.
//
//    Input/output, int A1[N], A2[N], the data to be sorted..
//
{
  int i;
  int indx;
  int isgn;
  int j;
  int temp;
//
//  Initialize.
//
  i = 0;
  indx = 0;
  isgn = 0;
  j = 0;
//
//  Call the external heap sorter.
//
  for ( ; ; )
  {
    sort_heap_external ( n, indx, i, j, isgn );
//
//  Interchange the I and J objects.
//
    if ( 0 < indx )
    {
      temp    = a1[i-1];
      a1[i-1] = a1[j-1];
      a1[j-1] = temp;

      temp    = a2[i-1];
      a2[i-1] = a2[j-1];
      a2[j-1] = temp;
    }
//
//  Compare the I and J objects.
//
    else if ( indx < 0 )
    {
      isgn = i4vec2_compare ( n, a1, a2, i, j );
    }
    else if ( indx == 0 )
    {
      break;
    }
  }
  return;
}
//****************************************************************************80

int i4vec2_sorted_unique_count ( int n, int a1[], int a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC2_SORTED_UNIQUE_COUNT counts unique elements in an I4VEC2.
//
//  Discussion:
//
//    Item I is stored as the pair A1(I), A2(I).
//
//    The items must have been sorted, or at least it must be the
//    case that equal items are stored in adjacent vector locations.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of items.
//
//    Input, int A1[N], A2[N], the array of N items.
//
//    Output, int I4VEC2_SORTED_UNIQUE_COUNT, the number of unique items.
//
{
  int i;
  int iu;
  int unique_num;

  unique_num = 0;

  if ( n <= 0 )
  {
    return unique_num;
  }

  iu = 0;
  unique_num = 1;

  for ( i = 1; i < n; i++ )
  {
    if ( a1[i] != a1[iu] ||
         a2[i] != a2[iu] )
    {
      iu = i;
      unique_num = unique_num + 1;
    }
  }

  return unique_num;
}
//****************************************************************************80

void i4vec2_sorted_uniquely ( int n1, int a1[], int b1[], int n2, int a2[], 
  int b2[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC2_SORTED_UNIQUELY keeps the unique elements in an I4VEC2.
//
//  Discussion:
//
//    Item I is stored as the pair A1(I), A2(I).
//
//    The items must have been sorted, or at least it must be the
//    case that equal items are stored in adjacent vector locations.
//
//    If the items were not sorted, then this routine will only
//    replace a string of equal values by a single representative.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N1, the number of items.
//
//    Input, int A1[N1], B1[N1], the input array.
//
//    Input, int N2, the number of unique items.
//
//    Input, int A2[N2], B2[N2], the output array of unique items.
//
{
  int i1;
  int i2;

  i1 = 0;
  i2 = 0;

  if ( n1 <= 0 )
  {
    return;
  }

  a2[i2] = a1[i1];
  b2[i2] = b1[i1];

  for ( i1 = 1; i1 < n1; i1++ )
  {
    if ( a1[i1] != a2[i2] || b1[i1] != b2[i2] )
    {
      i2 = i2 + 1;
      a2[i2] = a1[i1];
      b2[i2] = b1[i1];
    }
  }

  return;
}
//****************************************************************************80

double r8_uniform_01 ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8_UNIFORM_01 returns a unit pseudorandom R8.
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
//    If the initial seed is 12345, then the first three computations are
//
//      Input     Output      R8_UNIFORM_01
//      SEED      SEED
//
//         12345   207482415  0.096616
//     207482415  1790989824  0.833995
//    1790989824  2035175616  0.947702
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 April 2012
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
//    Input/output, int &SEED, the "seed" value.  Normally, this
//    value should not be 0.  On output, SEED has been updated.
//
//    Output, double R8_UNIFORM_01, a new pseudorandom variate, 
//    strictly between 0 and 1.
//
{
  const int i4_huge = 2147483647;
  int k;
  double r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8_UNIFORM_01 - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )
  {
    seed = seed + i4_huge;
  }
  r = ( double ) ( seed ) * 4.656612875E-10;

  return r;
}
//****************************************************************************80

double r8vec_diff_norm ( int n, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_DIFF_NORM returns the L2 norm of the difference of R8VEC's.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//    The vector L2 norm is defined as:
//
//      R8VEC_NORM_L2 = sqrt ( sum ( 1 <= I <= N ) A(I)^2 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 June 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in A.
//
//    Input, double A[N], B[N], the vectors.
//
//    Output, double R8VEC_DIFF_NORM, the L2 norm of A - B.
//
{
  int i;
  double value;

  value = 0.0;

  for ( i = 0; i < n; i++ )
  {
    value = value + ( a[i] - b[i] ) * ( a[i] - b[i] );
  }
  value = sqrt ( value );

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
  const int i4_huge = 2147483647;
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

void r8vec_write ( string output_filename, int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_WRITE writes an R8VEC file.
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
//    10 July 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string OUTPUT_FILENAME, the output filename.
//
//    Input, int N, the number of points.
//
//    Input, double X[N], the data.
//
{
  int j;
  ofstream output;
//
//  Open the file.
//
  output.open ( output_filename.c_str ( ) );

  if ( !output )
  {
    cerr << "\n";
    cerr << "R8VEC_WRITE - Fatal error!\n";
    cerr << "  Could not open the output file.\n";
    exit ( 1 );
  }
//
//  Write the data.
//
  for ( j = 0; j < n; j++ )
  {
    output << "  " << setw(24) << setprecision(16) << x[j] << "\n";
  }
//
//  Close the file.
//
  output.close ( );

  return;
}
//****************************************************************************80

double *r8vec_zero_new ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_ZERO_NEW creates and zeroes an R8VEC.
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
//    10 July 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Output, double R8VEC_ZERO_NEW[N], a vector of zeroes.
//
{
  double *a;
  int i;

  a = new double[n];

  for ( i = 0; i < n; i++ )
  {
    a[i] = 0.0;
  }
  return a;
}
//****************************************************************************80

void sort_heap_external ( int n, int &indx, int &i, int &j, int isgn )

//****************************************************************************80
//
//  Purpose:
//
//    SORT_HEAP_EXTERNAL externally sorts a list of items into ascending order.
//
//  Discussion:
//
//    The actual list is not passed to the routine.  Hence it may
//    consist of integers, reals, numbers, names, etc.  The user,
//    after each return from the routine, will be asked to compare or
//    interchange two items.
//
//    The current version of this code mimics the FORTRAN version,
//    so the values of I and J, in particular, are FORTRAN indices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 January 2013
//
//  Author:
//
//    Original FORTRAN77 version by Albert Nijenhuis, Herbert Wilf.
//    C++ version by John Burkardt
//
//  Reference:
//
//    Albert Nijenhuis, Herbert Wilf,
//    Combinatorial Algorithms,
//    Academic Press, 1978, second edition,
//    ISBN 0-12-519260-6.
//
//  Parameters:
//
//    Input, int N, the length of the input list.
//
//    Input/output, int &INDX.
//    The user must set INDX to 0 before the first call.
//    On return,
//      if INDX is greater than 0, the user must interchange
//      items I and J and recall the routine.
//      If INDX is less than 0, the user is to compare items I
//      and J and return in ISGN a negative value if I is to
//      precede J, and a positive value otherwise.
//      If INDX is 0, the sorting is done.
//
//    Output, int &I, &J.  On return with INDX positive,
//    elements I and J of the user's list should be
//    interchanged.  On return with INDX negative, elements I
//    and J are to be compared by the user.
//
//    Input, int ISGN. On return with INDX negative, the
//    user should compare elements I and J of the list.  If
//    item I is to precede item J, set ISGN negative,
//    otherwise set ISGN positive.
//
{
  static int i_save = 0;
  static int j_save = 0;
  static int k = 0;
  static int k1 = 0;
  static int n1 = 0;
//
//  INDX = 0: This is the first call.
//
  if ( indx == 0 )
  {

    i_save = 0;
    j_save = 0;
    k = n / 2;
    k1 = k;
    n1 = n;
  }
//
//  INDX < 0: The user is returning the results of a comparison.
//
  else if ( indx < 0 )
  {
    if ( indx == -2 )
    {
      if ( isgn < 0 )
      {
        i_save = i_save + 1;
      }
      j_save = k1;
      k1 = i_save;
      indx = -1;
      i = i_save;
      j = j_save;
      return;
    }

    if ( 0 < isgn )
    {
      indx = 2;
      i = i_save;
      j = j_save;
      return;
    }

    if ( k <= 1 )
    {
      if ( n1 == 1 )
      {
        i_save = 0;
        j_save = 0;
        indx = 0;
      }
      else
      {
        i_save = n1;
        j_save = 1;
        n1 = n1 - 1;
        indx = 1;
      }
      i = i_save;
      j = j_save;
      return;
    }
    k = k - 1;
    k1 = k;
  }
//
//  0 < INDX: the user was asked to make an interchange.
//
  else if ( indx == 1 )
  {
    k1 = k;
  }

  for ( ; ; )
  {

    i_save = 2 * k1;

    if ( i_save == n1 )
    {
      j_save = k1;
      k1 = i_save;
      indx = -1;
      i = i_save;
      j = j_save;
      return;
    }
    else if ( i_save <= n1 )
    {
      j_save = i_save + 1;
      indx = -2;
      i = i_save;
      j = j_save;
      return;
    }

    if ( k <= 1 )
    {
      break;
    }

    k = k - 1;
    k1 = k;
  }

  if ( n1 == 1 )
  {
    i_save = 0;
    j_save = 0;
    indx = 0;
    i = i_save;
    j = j_save;
  }
  else
  {
    i_save = n1;
    j_save = 1;
    n1 = n1 - 1;
    indx = 1;
    i = i_save;
    j = j_save;
  }

  return;
}
//****************************************************************************80

void st_data_read ( string input_filename, int m, int n, int nst, int ist[], 
  int jst[], double ast[] )

//****************************************************************************80
//
//  Purpose:
//
//    ST_DATA_READ reads the data of an ST file.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string INPUT_FILENAME, the name of the ST file.
//
//    Input, int M, the number of rows.
//
//    Input, int N, the number of columns.
//
//    Input, int NST, the number of nonzeros.
//
//    Output, int IST[NNZERO], JST[NNZERO], the row and column indices.
//
//    Output, double AST[NST], the nonzero values.
//
{
  double aij;
  int i;
  ifstream input;
  int j;
  int k;

  input.open ( input_filename.c_str ( ) );

  for ( k = 0; k < nst; k++ )
  {
    input >> i >> j >> aij;

    if ( !input )
    {
      cerr << "\n";
      cerr <<"ST_DATA_READ - Fatal error!\n";
      cerr << "  I/O error reading data index " << k << "\n";
      exit ( 1 );
    }

    ist[k] = i;
    jst[k] = j;
    ast[k] = aij;
  }

  input.close ( );

  return;
}
//****************************************************************************80

void st_header_print ( int i_min, int i_max, int j_min, int j_max, int m, 
  int n, int nst )

//****************************************************************************80
//
//  Purpose:
//
//    ST_HEADER_PRINT prints the header of an ST file.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I_MIN, I_MAX, the minimum and maximum row indices.
//
//    Input, int J_MIN, J_MAX, the minimum and maximum column indices.
//
//    Input, int M, the number of rows.
//
//    Input, int N, the number of columns.
//
//    Input, int NST, the number of nonzeros.
//
{
  cout << "\n";
  cout << "  ST header information:\n";
  cout << "\n";
  cout << "  Minimum row index I_MIN = " << i_min << "\n";
  cout << "  Maximum row index I_MAX = " << i_max << "\n";
  cout << "  Minimum col index J_MIN = " << j_min << "\n";
  cout << "  Maximum col index J_MAX = " << j_max << "\n";
  cout << "  Number of rows        M = " << m << "\n";
  cout << "  Number of columns     N = " << n << "\n";
  cout << "  Number of nonzeros  NST = " << nst << "\n";

  return;
}
//****************************************************************************80

void st_header_read ( string input_filename, int &i_min, int &i_max, int &j_min, 
  int &j_max, int &m, int &n, int &nst )

//****************************************************************************80
//
//  Purpose:
//
//    ST_HEADER_READ reads the header of an ST file.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string INPUT_FILENAME, the name of the ST file.
//
//    Output, int &I_MIN, &I_MAX, the minimum and maximum row indices.
//
//    Output, int &J_MIN, &J_MAX, the minimum and maximum column indices.
//
//    Output, int &M, the number of rows.
//
//    Output, int &N, the number of columns .
//
//    Output, int &NST, the number of nonzeros.
//
{
  double aij;
  int i;
  const int i4_huge = 2147483647;
  ifstream input;
  int j;

  input.open ( input_filename.c_str ( ) );

  nst = 0;
  i_min = + i4_huge;
  i_max = - i4_huge;
  j_min = + i4_huge;
  j_max = - i4_huge;

  for ( ; ; )
  {
    input >> i >> j >> aij;

    if ( ! input )
    {
      break;
    }

    nst = nst + 1;
    i_min = i4_min ( i_min, i );
    i_max = i4_max ( i_max, i );
    j_min = i4_min ( j_min, j );
    j_max = i4_max ( j_max, j );
  }

  input.close ( );

  m = i_max - i_min + 1;
  n = j_max - j_min + 1;

  return;
}
//****************************************************************************80

double *st_mv ( int m, int n, int nst, int ist[], int jst[], double ast[], 
  double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    ST_MV multiplies an ST matrix by an R8VEC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int NST, the number of nonzeros.
//
//    Input, int IST[NST], JST[NST], the row and column indices.
//
//    Input, double AST[NST], the nonzero values.
//
//    Input, double X[N], the vector to be multiplied by A.
//
//    Output, double B[M], the product vector A*X.
//
{
  double *b;
  int i;
  int j;
  int k;

  b = r8vec_zero_new ( m );

  for ( k = 0; k < nst; k++ )
  {
    i = ist[k];
    j = jst[k];
    b[i] = b[i] + ast[k] * x[j];
  }

  return b;
}
//****************************************************************************80

void st_print ( int m, int n, int nst, int ist[], int jst[], double ast[], 
  string title )

//****************************************************************************80
//
//  Purpose:
//
//    ST_PRINT prints a sparse matrix in ST format.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows.
//
//    Input, int N, the number of columns.
//
//    Input, int NST, the number of ST elements.
//
//    Input, int IST[NST], JST[NST], the ST rows and columns.
//
//    Input, double AST[NST], the ST values.
//
//    Input, string TITLE, a title.
//
{
  int k;

  cout << "\n";
  cout << title << "\n";
  cout << "     #     I     J       A\n";
  cout << "  ----  ----  ----  --------------\n";
  cout << "\n";
  for ( k = 0; k < nst; k++ )
  {
    cout << setw(4) << k << "  "
         << setw(4) << ist[k] << "  "
         << setw(4) << jst[k] << "  "
         << setw(16) << ast[k] << "\n";
  }

  return;
}
//****************************************************************************80

int st_to_ccs_size ( int nst, int ist[], int jst[] )

//****************************************************************************80
//
//  Purpose:
//
//    ST_TO_ccs_SIZE sizes CCS indexes based on ST data.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NST, the number of ST elements.
//
//    Input, int IST[NST], JST[NST], the ST rows and columns.
//
//    Output, int ST_TO_ccs_SIZE, the number of CCS elements.
//
{
  int *ist2;
  int *jst2;
  int ncc;
//
//  Make copies so the sorting doesn't confuse the user.
//
  ist2 = i4vec_copy_new ( nst, ist );
  jst2 = i4vec_copy_new ( nst, jst );
//
//  Sort by column first, then row.
//
  i4vec2_sort_a ( nst, jst2, ist2 );
//
//  Count the unique pairs.
//
  ncc = i4vec2_sorted_unique_count ( nst, jst2, ist2 );

  delete [] ist2;
  delete [] jst2;

  return ncc;
}
//****************************************************************************80

void st_to_ccs_index ( int nst, int ist[], int jst[], int ncc, int n, 
  int icc[], int ccc[] )

//****************************************************************************80
//
//  Purpose:
//
//    ST_TO_ccs_INDEX creates CCS indices from ST data.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NST, the number of ST elements.
//
//    Input, int IST[NST], JST[NST], the ST rows and columns.
//
//    Input, int NCC, the number of CCS elements.
//
//    Input, int N, the number of columns in the matrix.
//
//    Output, int ICC[NCC], the CCS rows.
//
//    Output, int CCC[N+1], the compressed CCS columns.
//
{
  int *ist2;
  int j;
  int *jcc;
  int jhi;
  int jlo;
  int *jst2;
  int k;
//
//  Make copies so the sorting doesn't confuse the user.
//
  ist2 = i4vec_copy_new ( nst, ist );
  jst2 = i4vec_copy_new ( nst, jst );
//
//  Sort the elements.
//
  i4vec2_sort_a ( nst, jst2, ist2 );
//
//  Get the unique elements.
//
  jcc = new int[ncc];
  i4vec2_sorted_uniquely ( nst, jst2, ist2, ncc, jcc, icc );
//
//  Compress the column index.
//
  ccc[0] = 0;
  jlo = 0;
  for ( k = 0; k < ncc; k++ )
  {
    jhi = jcc[k];
    if ( jhi != jlo )
    {
      for ( j = jlo + 1; j <= jhi; j++ )
      {
        ccc[j] = k;
      }
      jlo = jhi;
    }
  }
  jhi = n;
  for ( j = jlo + 1; j <= jhi; j++ )
  {
    ccc[j] = ncc;
  }

  delete [] ist2;
  delete [] jcc;
  delete [] jst2;

  return;
}
//****************************************************************************80

double *st_to_ccs_values ( int nst, int ist[], int jst[], double ast[], int ncc, 
  int n, int icc[], int ccc[] )

//****************************************************************************80
//
//  Purpose:
//
//    ST_TO_ccs_VALUES creates CCS values from ST data.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 July 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NST, the number of ST elements.
//
//    Input, int IST[NST], JST[NST], the ST rows and columns.
//
//    Input, double AST[NST], the ST values.
//
//    Input, int NCC, the number of CCS elements.
//
//    Input, int N, the number of columns.
//
//    Input, int ICC[NCC], the CCS rows.
//
//    Input, int CCC[N+1], the CCS compressed columns.
//
//    Output, double ST_TO_ccs_VALUES[NCC], the CCS values.
//
{
  double *acc;
  int chi;
  int clo;
  bool fail;
  int i;
  int j;
  int kcc;
  int kst;

  acc = new double[ncc];

  for ( i = 0; i < ncc; i++ )
  {
    acc[i] = 0.0;
  }

  for ( kst = 0; kst < nst; kst++ )
  {
    i = ist[kst];
    j = jst[kst];

    clo = ccc[j];
    chi = ccc[j+1];

    fail = true;

    for ( kcc = clo; kcc < chi; kcc++ )
    {
      if ( icc[kcc] == i )
      {
        acc[kcc] = acc[kcc] + ast[kst];
        fail = false;
        break;
      }
    }

    if ( fail )
    {
      cerr << "\n";
      cerr << "ST_TO_ccs_VALUES - Fatal error!\n";
      cerr << "  ST entry cannot be located in CCS array.\n";
      cerr << "  ST index KST    = " << kst << "\n";
      cerr << "  ST row IST(KST) = " << ist[kst] << "\n";
      cerr << "  ST col JST(KST) = " << jst[kst] << "\n";
      cerr << "  ST val AST(KST) = " << ast[kst] << "\n";
      exit ( 1 );
    }

  }

  return acc;
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
//****************************************************************************80

double *wathen_st ( int nx, int ny, int nz_num, int &seed, int row[], 
  int col[] )

//****************************************************************************80
//
//  Purpose:
//
//    WATHEN_ST: Wathen matrix stored in sparse triplet (ST) format.
//
//  Discussion:
//
//    When dealing with sparse matrices in MATLAB, it can be much more efficient
//    to work first with a triple of I, J, and X vectors, and only once
//    they are complete, convert to MATLAB's sparse format.
//
//    The Wathen matrix is a finite element matrix which is sparse.
//
//    The entries of the matrix depend in part on a physical quantity
//    related to density.  That density is here assigned random values between
//    0 and 100.
//
//    The matrix order N is determined by the input quantities NX and NY,
//    which would usually be the number of elements in the X and Y directions.
//
//    The value of N is
//
//      N = 3*NX*NY + 2*NX + 2*NY + 1,
//
//    The matrix is the consistent mass matrix for a regular NX by NY grid
//    of 8 node serendipity elements.
//
//    The local element numbering is
//
//      3--2--1
//      |     |
//      4     8
//      |     |
//      5--6--7
//
//    Here is an illustration for NX = 3, NY = 2:
//
//     23-24-25-26-27-28-29
//      |     |     |     |
//     19    20    21    22
//      |     |     |     |
//     12-13-14-15-16-17-18
//      |     |     |     |
//      8     9    10    11
//      |     |     |     |
//      1--2--3--4--5--6--7
//
//    For this example, the total number of nodes is, as expected,
//
//      N = 3 * 3 * 2 + 2 * 2 + 2 * 3 + 1 = 29
//
//    The matrix is symmetric positive definite for any positive values of the
//    density RHO(X,Y).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2014
//
//  Author:
//
//    John Burkardt.
//
//  Reference:
//
//    Nicholas Higham,
//    Algorithm 694: A Collection of Test Matrices in MATLAB,
//    ACM Transactions on Mathematical Software,
//    Volume 17, Number 3, September 1991, pages 289-305.
//
//    Andrew Wathen,
//    Realistic eigenvalue bounds for the Galerkin mass matrix,
//    IMA Journal of Numerical Analysis,
//    Volume 7, Number 4, October 1987, pages 449-457.
//
//  Parameters:
//
//    Input, int NX, NY, values which determine the size of 
//    the matrix.
//
//    Input, int NZ_NUM, the number of values used to 
//    describe the matrix.
//
//    Input/output, int &SEED, the random number seed.
//
//    Output, int ROW[NZ_NUM], COL[NZ_NUM], the row and 
//    column indices of the nonzero entries.
//
//    Output, double WATHEN_ST[NZ_NUM], the nonzero entries of the matrix.
//
{
  double *a;
  const double em[8*8] = {
     6.0, -6.0,  2.0, -8.0,  3.0, -8.0,  2.0, -6.0, 
    -6.0, 32.0, -6.0, 20.0, -8.0, 16.0, -8.0, 20.0, 
     2.0, -6.0,  6.0, -6.0,  2.0, -8.0,  3.0, -8.0, 
    -8.0, 20.0, -6.0, 32.0, -6.0, 20.0, -8.0, 16.0, 
     3.0, -8.0,  2.0, -6.0,  6.0, -6.0,  2.0, -8.0, 
    -8.0, 16.0, -8.0, 20.0, -6.0, 32.0, -6.0, 20.0, 
     2.0, -8.0,  3.0, -8.0,  2.0, -6.0,  6.0, -6.0, 
    -6.0, 20.0, -8.0, 16.0, -8.0, 20.0, -6.0, 32.0 };
  int i;
  int j;
  int k;
  int kcol;
  int krow;
  int node[8];
  double rho;

  a = new double[nz_num];
 
  for ( k = 0; k < nz_num; k++ )
  {
    row[k] = 0;
    col[k] = 0;
    a[k] = 0.0;
  }

  k = 0;

  for ( j = 0; j < nx; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      node[0] = 3 * ( j + 1 ) * nx + 2 * ( j + 1 ) + 2 * ( i + 1 );
      node[1] = node[0] - 1;
      node[2] = node[0] - 2;
      node[3] = ( 3 * ( j + 1 ) - 1 ) * nx + 2 * ( j + 1 ) + ( i + 1 ) - 2;
      node[4] = ( 3 * ( j + 1 ) - 3 ) * nx + 2 * ( j + 1 ) + 2 * ( i + 1 ) - 4;
      node[5] = node[4] + 1;
      node[6] = node[4] + 2;
      node[7] = node[3] + 1;

      rho = 100.0 * r8_uniform_01 ( seed );

      for ( krow = 0; krow < 8; krow++ )
      {
        for ( kcol = 0; kcol < 8; kcol++ )
        {
          row[k] = node[krow];
          col[k] = node[kcol];
          a[k] = rho * em[krow+kcol*8];
          k = k + 1;
        }
      }
    }
  }

  return a;
}
//****************************************************************************80

int wathen_st_size ( int nx, int ny )

//****************************************************************************80
//
//  Purpose:
//
//    WATHEN_ST_SIZE: Size of Wathen matrix stored in sparse triplet format.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 June 2014
//
//  Author:
//
//    John Burkardt.
//
//  Reference:
//
//    Nicholas Higham,
//    Algorithm 694: A Collection of Test Matrices in MATLAB,
//    ACM Transactions on Mathematical Software,
//    Volume 17, Number 3, September 1991, pages 289-305.
//
//    Andrew Wathen,
//    Realistic eigenvalue bounds for the Galerkin mass matrix,
//    IMA Journal of Numerical Analysis,
//    Volume 7, Number 4, October 1987, pages 449-457.
//
//  Parameters:
//
//    Input, integer NX, NY, values which determine the size of the matrix.
//
//    Output, integer NZ_NUM, the number of items of data used to describe
//    the matrix.
//
{
  int nz_num;

  nz_num = nx * ny * 64;

  return nz_num;
}
