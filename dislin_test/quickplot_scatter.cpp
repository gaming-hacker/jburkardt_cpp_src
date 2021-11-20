# include <cstdlib>
# include <iostream>
# include <cmath>
# include <ctime>

# include "dislin.hpp"

using namespace std;

int main ( int argc, char *argv[] );
double r8_uniform_01 ( int *seed );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    QUICKPLOT_SCATTER demonstrates the DISLIN quickplot command QPLSCA.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    01 March 2014
//
//  Author:
//
//    This C++ version by John Burkardt.
//
//  Reference:
//
//    Helmut Michels,
//    The Data Plotting Software DISLIN - version 10.4,
//    Shaker Media GmbH, January 2010,
//    ISBN13: 978-3-86858-517-9.
//
{
  Dislin g;
  int i;
  int j;
  int n = 100;
  double s;
  int seed;
  double *xvec;
  double *yvec;

  timestamp ( );
  cout << "\n";
  cout << "QUICKPLOT_SCATTER:\n";
  cout << "  C++ version\n";
  cout << "  Demonstrate the DISLIN \"quickplot\" command QPLSCA\n";
  cout << "  to make a scatter plot.\n";
//
//  Generate the data.  
//  We average 4 random values to get data that tends to cluster
//  near (0.5,0.5).
//
  seed = 123456789;

  xvec = new double[n];
  yvec = new double[n];

  for ( i = 0; i < n; i++ )
  {
    s = 0.0;
    for ( j = 1; j <= 4 ; j++ )
    {
      s = s + r8_uniform_01 ( &seed );
    }
    xvec[i] = s / 4.0;
  }

  for ( i = 0; i < n; i++ )
  {
    s = 0.0;
    for ( j = 1; j <= 4 ; j++ )
    {
      s = s + r8_uniform_01 ( &seed );
    }
    yvec[i] = s / 4.0;
  }
//
//  Specify the format of the output file.
//
  g.metafl ( "png" );
//
//  Indicate that new data overwrites old data.
//
  g.filmod ( "delete" );
//
//  Specify the name of the output graphics file.
//
  g.setfil ( "quickplot_scatter.png" );
//
//  Choose the page size and orientation.
//
  g.setpag ( "usal" );
//
//  For PNG output, reverse the default black background to white.
//
  g.scrmod ( "reverse" );
//
//  Open DISLIN.
//
  g.disini ( );
//
//  Label the axes and the plot.
//
  g.name ( "<-- X -->", "X" );
  g.name ( "<-- Y -->", "Y" );
  g.titlin ( "Quick plot by QPLSCA", 2 );
//
//  Draw the curve.
//
  g.qplsca ( xvec, yvec, n );
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Free memory.
//
  delete [] xvec;
  delete [] yvec;
//
//  Terminate.
//
  cout << "\n";
  cout << "QUICKPLOT_SCATTER:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

double r8_uniform_01 ( int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8_UNIFORM_01 returns a unit pseudorandom R4.
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
//    11 August 2004
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
//    Input/output, int *SEED, the "seed" value.  Normally, this
//    value should not be 0.  On output, SEED has been updated.
//
//    Output, double R8_UNIFORM_01, a new pseudorandom variate,
//    strictly between 0 and 1.
//
{
  int i4_huge = 2147483647;
  int k;
  double r;

  if ( *seed == 0 )
  {
    cerr << "\n";
    cerr << "R4_UNIFORM_01 - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  k = *seed / 127773;

  *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

  if ( *seed < 0 )
  {
    *seed = *seed + i4_huge;
  }
//
//  Although SEED can be represented exactly as a 32 bit integer,
//  it generally cannot be represented exactly as a 32 bit real number.
//
  r = ( double ) ( *seed ) * 4.656612875E-10;

  return r;
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
  size_t len;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  len = std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
