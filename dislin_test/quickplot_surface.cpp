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
//    QUICKPLOT_SURFACE demonstrates the DISLIN quickplot command QPLSUR.
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
  int m = 100;
  int n = 100;
  const double pi = 3.141592653589793;
  double x;
  double y;
  double *zmat;

  timestamp ( );
  cout << "\n";
  cout << "QUICKPLOT_CURVE:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the DISLIN 'quickplot' command QPLSUR\n";
  cout << "  to plot a surface Z(X,Y) stored as a matrix.\n";
//
//  Set up the X and Y data for the plot.
//
  zmat = new double[m*n];

  for ( i = 0; i < m; i++ )
  {
    x = 2.0 * pi * ( double ) ( i ) / ( double ) ( m - 1 );
    for ( j = 0; j < n; j++ )
    {
      y = 2.0 * pi * ( double ) ( j ) / ( double ) ( n - 1 );
      zmat[i+j*m] = 2.0 * sin ( x ) * sin ( y );
    }
  }
//
//  Specify the format of the output file.
//
  g.metafl ( "png" );
//
//  Specify that if a file already exists of the given name,
//  the new data should overwrite the old.
//
  g.filmod ( "delete" );
//
//  Specify the name of the output graphics file.
//
  g.setfil ( "quickplot_surface.png" );
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
  g.titlin ( "Quick plot by QPLOT", 2 );
//
//  Draw the curve.
//
  g.qplsur ( zmat, m, n );
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Free memory.
//
  delete [] zmat;
//
//  Terminate.
//
  cout << "\n";
  cout << "QUICKPLOT_SURFACE:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
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
