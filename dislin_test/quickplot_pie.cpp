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
//    QUICKPLOT_PIE demonstrates the DISLIN quickplot command QPLPIE.
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
  int n = 5;
  double xray[5] = { 10.0, 20.0, 15.0, 5.0, 50.0 };

  timestamp ( );
  cout << "\n";
  cout << "QUICKPLOT_PIE:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the DISLIN 'quickplot' command QPLOT\n";
  cout << "  to plot a curve.\n";
  cout << "\n";
  cout << "  Here, we plot 10 percent luck, 20 percent skill,\n";
  cout << "  15 percent concentrated power of will, 5 percent pleasure,\n";
  cout << "  50 percent pain.\n";
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
  g.setfil ( "quickplot_pie.png" );
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
  g.titlin ( "Quick plot by QPLPIE", 2 );
//
//  Draw the curve.
//
  g.qplpie ( xray, n );
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "QUICKPLOT_PIE:\n";
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
