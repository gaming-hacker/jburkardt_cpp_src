# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iostream>
# include <iomanip>

using namespace std;

# include "dislin.h"
# include "discpp.h"

int main ( int argc, char *argv[] );
float r4_uniform_01 ( int *seed );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    RANDOM_SCATTER uses DISLIN to draw a scatterplot of 2D data.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 April 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Helmut Michels,
//    The Data Plotting Software DISLIN - version 10.4,
//    Shaker Media GmbH, January 2010,
//    ISBN13: 978-3-86858-517-9.
//
{
# define N 500

  int i;
  int j;
  int pat;
  float s;
  int seed;
  float xvec[N];
  float yvec[N];

  timestamp ( );
  cout << "\n";
  cout << "RANDOM_SCATTER:\n";
  cout << "  C++ version:\n";
  cout << "  Use DISLIN to make a scatter plot of random data.\n";
//
//  Generate the data.  
//  We average 4 random values to get data that tends to cluster
//  near (0.5,0.5).
//
  seed = 123456789;

  for ( i = 0; i < N; i++ )
  {
    s = 0.0;
    for ( j = 0; j < 4; j++ )
    {
      s = s + r4_uniform_01 ( &seed );
    }
    xvec[i] = s / 4.0;
  }
  for ( i = 0; i < N; i++ )
  {
    s = 0.0;
    for ( j = 0; j < 4; j++ )
    {
      s = s + r4_uniform_01 ( &seed );
    }
    yvec[i] = s / 4.0;
  }
//
//  Specify the format of the output file.
//
  metafl ( "png" );
//
//  Indicate that new data overwrites old data.
//
  filmod ( "delete" );
//
//  Specify the name of the output graphics file.
//
  setfil ( "random_scatter.png" );
//
//  Choose the page size and orientation.
//  'USA' is 2160 plot units wide and 2790 plot units high.
//  'P' requests PROFILE rather than LANDSCAPE orientation.
//
  setpag ( "usap" );
//
//  For PNG output, reverse the default black background to white.
//
  scrmod ( "reverse" );
//
//  Open DISLIN.
//
  disini ( );
//
//  Plot a border around the page.
//
  pagera ( );
//
//  Use the COMPLEX font.
//
  complx ( );
//
//  Define the X and Y sizes of the axis system in plot units.
//
  axslen ( 1800, 1800 );
//
//  Specify how the lower X, left Y, upper X and right Y axes are labeled.
//
  setgrf ( "line", "line", "line", "line" );
//
//  Set the axis origin 180 plot units to the right, and 2610 plot units DOWN.
//
  axspos ( 180, 2610 );
//
//  Relate the physical coordinates to the axes, and specify tick marks.
//
  graf ( 0.0, 1.0, 0.0, 0.1, 0.0, 1.0, 0.0, 0.1 );
//
//  Add a grid, with one grid line for every tick mark in the X and Y axes.
//
  grid ( 1, 1 );
//
//  Select the shading pattern.
//
  pat = 16;
  shdpat ( pat );
//
//  Set the color to blue.
//
  color ( "blue" );
//
//  At every data point, draw a circle of radius 0.01.
//
  for ( i = 0; i < N; i++ )
  {
    rlcirc ( xvec[i], yvec[i], 0.01 );
  }
//
//  Select character height in plot units.
//
  height ( 50 );
//
//  Set the title color to black.
//  We say "white" because these colors were reversed.
//
  color ( "white" );
//
//  Define the axis titles.
//
  titlin ( "Scatter plot of random data", 1 );
//
//  Draw the title.
//
  title ( );
//
//  End this plot.
//
  endgrf ( );
//
//  Close DISLIN.
//
  disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "RANDOM_SCATTER:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

float r4_uniform_01 ( int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    R4_UNIFORM_01 returns a unit pseudorandom R4.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = 16807 * seed mod ( 2**31 - 1 )
//      r4_uniform_01 = seed / ( 2**31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//    If the initial seed is 12345, then the first three computations are
//
//      Input     Output      R4_UNIFORM_01
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
//    16 November 2004
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Springer Verlag, pages 201-202, 1983.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation
//    edited by Jerry Banks,
//    Wiley Interscience, page 95, 1998.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, pages 362-376, 1986.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, pages 136-143, 1969.
//
//  Parameters:
//
//    Input/output, int *SEED, the "seed" value.  Normally, this
//    value should not be 0.  On output, SEED has been updated.
//
//    Output, float R4_UNIFORM_01, a new pseudorandom variate, strictly between
//    0 and 1.
//
{
  int k;
  float value;

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
    *seed = *seed + 2147483647;
  }
//
//  Although SEED can be represented exactly as a 32 bit integer,
//  it generally cannot be represented exactly as a 32 bit real number.
//
  value = ( float ) ( *seed ) * 4.656612875E-10;

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
//    19 March 2018
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

