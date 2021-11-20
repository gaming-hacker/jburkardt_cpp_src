# include <cstdlib>
# include <iostream>
# include <cmath>
# include <ctime>

# include "dislin.hpp"

using namespace std;

int main ( int argc, char *argv[] );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    QUICKPLOT_COLOR demonstrates the DISLIN quickplot command QPLCLR.
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
# define N 100

  double fpi;
  Dislin g;
  int i;
  int j;
  int n = N;
  const double pi = 3.141592653589793;
  double step;
  double x;
  double y;
  double zmat[N][N];

  fpi = pi / 180.0;

  timestamp ( );
  cout << "\n";
  cout << "QUICKPLOT_COLOR:\n";
  cout << "  C++ version\n";
  cout << "  Demonstrate the DISLIN \"quickplot\" command QPLCLR\n";
  cout << "  to make a color plot of a matrix of data.\n";
//
//  Set up the data.
//
  step = 360.0 / ( double ) ( N - 1 );
  for ( i = 0; i < N; i++ )
  {
    x = ( double ) i * step;
    for ( j = 0; j < N; j++ )
    {
      y = ( double ) j * step;
      zmat[i][j] = 2.0 * sin ( x * fpi ) * sin ( y * fpi );
    }
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
  g.setfil ( "quickplot_color.png" );
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
  g.name ( "X-axis", "x" );
  g.name ( "Y-axis", "y" );
  g.titlin ( "Quick plot by QPLCLR", 2 );
//
//  Draw the curve.
//
  g.qplclr ( ( double * ) zmat, n, n );
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "QUICKPLOT_CLR:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
# undef N
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
