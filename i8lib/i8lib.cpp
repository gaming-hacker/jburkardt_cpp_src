# include <cmath>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <iomanip>
# include <ctime>
# include <string>

using namespace std;

# include "i8lib.hpp"

//****************************************************************************80

int i8_bit_hi1 ( long long int n )

//****************************************************************************80
//
//  Purpose:
//
//    I8_BIT_HI1 returns the position of the high 1 bit base 2 in an integer.
//
//  Example:
//
//       N    Binary    Hi 1
//    ----    --------  ----
//       0           0     0
//       1           1     1
//       2          10     2
//       3          11     2 
//       4         100     3
//       5         101     3
//       6         110     3
//       7         111     3
//       8        1000     4
//       9        1001     4
//      10        1010     4
//      11        1011     4
//      12        1100     4
//      13        1101     4
//      14        1110     4
//      15        1111     4
//      16       10000     5
//      17       10001     5
//    1023  1111111111    10
//    1024 10000000000    11
//    1025 10000000001    11
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 May 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, long long int N, the integer to be measured.
//    N should be nonnegative.  If N is nonpositive, I8_BIT_HI1
//    will always be 0.
//
//    Output, int I8_BIT_HI1, the number of bits base 2.
//
{
  int bit;

  bit = 0;

  while ( 0 < n )
  {
    bit = bit + 1;
    n = n / 2;
  }

  return bit;
}
//****************************************************************************80

int i8_bit_lo0 ( long long int n )

//****************************************************************************80
//
//  Purpose:
//
//    I8_BIT_LO0 returns the position of the low 0 bit base 2 in an integer.
//
//  Example:
//
//       N    Binary    Lo 0
//    ----    --------  ----
//       0           0     1
//       1           1     2
//       2          10     1
//       3          11     3 
//       4         100     1
//       5         101     2
//       6         110     1
//       7         111     4
//       8        1000     1
//       9        1001     2
//      10        1010     1
//      11        1011     3
//      12        1100     1
//      13        1101     2
//      14        1110     1
//      15        1111     5
//      16       10000     1
//      17       10001     2
//    1023  1111111111    11
//    1024 10000000000     1
//    1025 10000000001     2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 May 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, long long int N, the integer to be measured.
//    N should be nonnegative.
//
//    Output, int I8_BIT_LO0, the position of the low 1 bit.
//
{
  int bit;
  long long int n2;

  bit = 0;

  while ( true )
  {
    bit = bit + 1;
    n2 = n / 2;

    if ( n == 2 * n2 )
    {
      break;
    }

    n = n2;

  }

  return bit;
}
//****************************************************************************80

long long int i8_choose ( long long int n, long long int k )

//****************************************************************************80
//
//  Purpose:
//
//    I8_CHOOSE computes the binomial coefficient C(N,K) as an I8.
//
//  Discussion:
//
//    The value is calculated in such a way as to avoid overflow and
//    roundoff.
//
//    The formula used is:
//
//      C(N,K) = N! / ( K! * (N-K)! )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 June 2010
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    ML Wolfson, HV Wright,
//    Algorithm 160:
//    Combinatorial of M Things Taken N at a Time,
//    Communications of the ACM,
//    Volume 6, Number 4, April 1963, page 161.
//
//  Parameters:
//
//    Input, long long int N, K, the values of N and K.
//
//    Output, long long int I8_CHOOSE, the number of combinations of N
//    things taken K at a time.
//
{
  long long int i;
  long long mn;
  long long mx;
  long long value;

  mn = i8_min ( k, n - k );

  if ( mn < 0 )
  {
    value = 0;
  }
  else if ( mn == 0 )
  {
    value = 1;
  }
  else
  {
    mx = i8_max ( k, n - k );
    value = mx + 1;

    for ( i = 2; i <= mn; i++ )
    {
      value = ( value * ( mx + i ) ) / i;
    }
  }
  return value;
}
//****************************************************************************80

long long int i8_huge ( )

//****************************************************************************80
//
//  Purpose:
//
//    I8_HUGE returns a "huge" I8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 May 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, long long int I8_HUGE, a "huge" I8.
//
{
  long long int value;

  value = 9223372036854775807LL;

  return value;
}
//****************************************************************************80

double i8_huge_normalizer ( )

//****************************************************************************80
//
//  Purpose:
//
//    I8_HUGE_NORMALIZER returns the "normalizer" for I8_HUGE.
//
//  Discussion:
//
//    The value returned is 1 / ( I8_HUGE + 1 ).
//
//    For any I8, it should be the case that
//
//     -1 < I8 * I8_HUGE_NORMALIZER < 1.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 June 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double I8_HUGE_NORMALIZER, the "normalizer"
//    for I8_HUGE.
//
{
  double value = 1.084202172485504434007E-19;

  return value;
}
//****************************************************************************80

long long int i8_max ( long long int i1, long long int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I8_MAX returns the maximum of two I8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 May 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, long long int I1, I2, two integers to be compared.
//
//    Output, long long int I8_MAX, the larger of I1 and I2.
//
{
  long long int value;

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

long long int i8_min ( long long int i1, long long int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I8_MIN returns the smaller of two I8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 May 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, long long int I1, I2, two integers to be compared.
//
//    Output, long long int I8_MIN, the smaller of I1 and I2.
//
{
  long long int value;

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

long long int i8_power ( long long int i, long long int j )

//****************************************************************************80
//
//  Purpose:
//
//    I8_POWER returns the value of I^J.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 June 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, long long int I, J, the base and the power.  
//    J should be nonnegative.
//
//    Output, long long int I8_POWER, the value of I^J.
//
{
  long long int k;
  long long int value;

  if ( j < 0 )
  {
    if ( i == 1 )
    {
      value = 1;
    }
    else if ( i == 0 )
    {
      cerr << "\n";
      cerr << "I8_POWER - Fatal error!\n";
      cerr << "  I^J requested, with I = 0 and J negative.\n";
      exit ( 1 );
    }
    else
    {
      value = 0;
    }
  }
  else if ( j == 0 )
  {
    if ( i == 0 )
    {
      cerr << "\n";
      cerr << "I8_POWER - Fatal error!\n";
      cerr << "  I^J requested, with I = 0 and J = 0.\n";
      exit ( 1 );
    }
    else
    {
      value = 1;
    }
  }
  else if ( j == 1 )
  {
    value = i;
  }
  else
  {
    value = 1;
    for ( k = 1; k <= j; k++ )
    {
      value = value * i;
    }
  }
  return value;
}
//****************************************************************************80

long long int i8_reverse_bytes ( long long int x )

//****************************************************************************80
//
//  Purpose:
//
//    I8_REVERSE_BYTES reverses the bytes in an I8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 May 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, long long int X, a value whose bytes are to be reversed.
//
//    Output, long long int I8_REVERSE_BYTES, a value whose bytes are
//    in reverse order from those in X.
//
{
  char c;
  union
  {
    long long int ylongint;
    char ychar[8];
  } y;

  y.ylongint = x;
  
  c = y.ychar[0];
  y.ychar[0] = y.ychar[7];
  y.ychar[7] = c;

  c = y.ychar[1];
  y.ychar[1] = y.ychar[6];
  y.ychar[6] = c;

  c = y.ychar[2];
  y.ychar[2] = y.ychar[5];
  y.ychar[5] = c;

  c = y.ychar[3];
  y.ychar[3] = y.ychar[4];
  y.ychar[4] = c;

  return ( y.ylongint );
}
//****************************************************************************80

double i8_uniform_ab ( long long int a, long long int b, long long int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    I8_UNIFORM_AB returns a scaled pseudorandom I8 between A and B.
//
//  Discussion:
//
//    The pseudorandom number should be uniformly distributed
//    between A and B.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 March 2020
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
//  Input:
//
//    long long int A, B, the limits of the interval.
//
//    long long int &SEED, the "seed" value, which should NOT be 0.
//
//  Output:
//
//    long long int I8_UNIFORM_AB, a number between A and B.
//
//    long long int &SEED, the "seed" value has been updated.
//
{
  long long int k;
  double r;
  long long int value;

  if ( *seed == 0 )
  {
    cerr << "\n";
    cerr << "I8_UNIFORM_AB - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  k = *seed / 127773LL;

  *seed = 16807LL * ( *seed - k * 127773LL ) - k * 2836LL;

  if ( *seed < 0 )
  {
    *seed = *seed + i8_huge ( );
  }

  r = ( double ) ( *seed ) * 4.656612875E-10;
//
//  Scale R to lie between A-0.5 and B+0.5.
//
  r = ( 1.0 - r ) * ( ( float ) a - 0.5 ) 
    +         r   * ( ( float ) b + 0.5 );
//
//  Use rounding to convert R to an integer between A and B.
//
  value = round ( r );
//
//  Guarantee A <= VALUE <= B.
//
  if ( value < a )
  {
    value = a;
  }
  if ( b < value )
  {
    value = b;
  }
  return value;
}
//****************************************************************************80

unsigned long long int i8_xor ( unsigned long long int i, 
  unsigned long long int j )

//****************************************************************************80
//
//  Purpose:
//
//    I8_XOR calculates the exclusive OR of two I8's.
//
//  Discussion:
//
//    C++ provides the operator "^" which produces the same result, faster.
//    This code is simply provided for illustration.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//   John Burkardt
//
//  Parameters:
//
//    Input, unsigned long long int I, J, two values whose exclusive OR 
//    is needed.
//
//    Output, unsigned long long int I8_XOR, the exclusive OR of I and J.
//
{
  unsigned long long int i2;
  unsigned long long int j2;
  unsigned long long int k;
  unsigned long long int l;

  k = 0;
  l = 1;

  while ( i != 0 || j != 0 )
  {
    i2 = i / 2;
    j2 = j / 2;

    if ( 
      ( ( i == 2 * i2 ) && ( j != 2 * j2 ) ) ||
      ( ( i != 2 * i2 ) && ( j == 2 * j2 ) ) )
    {
      k = k + l;
    }

    i = i2;
    j = j2;
    l = 2 * l;
  }

  return k;
}
//****************************************************************************80

double r8i8_uniform ( double a, double b, long long int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8I8_UNIFORM returns a scaled pseudorandom R8 using an I8 seed.
//
//  Discussion:
//
//    An R8 is a double precision real value.
//
//    An I8 is a double precision integer value.
//
//    The pseudorandom number should be uniformly distributed
//    between A and B.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 April 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double A, B, the limits of the interval.
//
//    Input/output, long long int *SEED, the "seed" value, which should
//    NOT be 0.  On output, SEED has been updated.
//
//    Output, double R8I8_UNIFORM, a number strictly between A and B.
//
{
  long long int k;
  double value;

  if ( *seed == 0 )
  {
    cerr << "\n";
    cerr << "R8I8_UNIFORM - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  k = *seed / 127773LL;

  *seed = 16807LL * ( *seed - k * 127773LL ) - k * 2836LL;

  if ( *seed < 0 )
  {
    *seed = *seed + i8_huge ( );
  }

  value = a + ( b - a ) * ( double ) ( *seed ) * 4.656612875E-10;

  return value;
}
//****************************************************************************80

double r8i8_uniform_01 ( long long int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8I8_UNIFORM_01 returns a unit pseudorandom R8 using an I8 seed.
//
//  Discussion:
//
//    An R8 is a double precision real value.
//
//    An I8 is a double precision integer value.
//
//    This routine implements the recursion
//
//      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
//      r8_uniform_01 = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//    If the initial seed is 12345, then the first three computations are
//
//      Input     Output      R8I8_UNIFORM_01
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
//    23 April 2008
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
//    Input/output, long long int *SEED, the "seed" value, which should
//    NOT be 0. On output, SEED has been updated.
//
//    Output, double R8I8_UNIFORM_01, a new pseudorandom variate,
//    strictly between 0 and 1.
//
{
  long long int k;
  double value;

  if ( *seed == 0 )
  {
    cerr << "\n";
    cerr << "R8I8_UNIFORM_01 - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  k = *seed / 127773LL;

  *seed = 16807LL * ( *seed - k * 127773LL ) - k * 2836LL;

  if ( *seed < 0 )
  {
    *seed = *seed + i8_huge ( );
  }

  value = ( double ) ( *seed ) * 4.656612875E-10;

  return value;
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
