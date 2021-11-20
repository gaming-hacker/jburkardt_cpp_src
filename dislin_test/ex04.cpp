# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <cstring>

using namespace std;

# include "dislin.hpp"

int main ( int argc, char *argv[] );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN demonstrates the use of the interpolation options when using CURVE.
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
  string cpol[6] = { "SPLINE", "STEM", "BARS", "STAIRS", "STEP", "LINEAR" };
  string ctit    = "Interpolation Methods";
  Dislin g;
  int i;
  int nx;
  int ny;
  int nya = 2700;
  static double x[] = {
     0.0,  1.0,  3.0,  4.5,  6.0,  8.0,  9.0, 11.0, 12.0, 12.5,
    13.0, 15.0, 16.0, 17.0, 19.0, 20.0 };
  static double y[] = {
     2.0,  4.0,  4.5,  3.0,  1.0,  7.0,  2.0,  3.0,  5.0,  2.0, 
     2.5,  2.0,  4.0,  6.0,  5.5,  4.0 };

  timestamp ( );
  cout << "\n";
  cout << "EX04:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the use of the various interpolation options\n";
  cout << "  when using CURVE to plot (X,Y) data.\n";
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
  g.setfil ( "ex04.png" );
//
//  Choose the page size and orientation.
//
  g.setpag ( "usap" );
//
//  For PNG output, reverse the default black background to white.
//
  g.scrmod ( "reverse" );
//
//  Open DISLIN.
//
  g.disini ( );
//
//  Plot a border around the page.
//
  g.pagera ( );
//
//  Use the COMPLEX font.
//
  g.complx ( );
  g.incmrk ( 1 );
  g.hsymbl ( 25 );
  g.titlin ( ctit.c_str ( ), 1 );
  g.axslen ( 1500, 350 );

  g.setgrf ( "line", "line", "line", "line" );

  for ( i = 0; i < 6; i++ )
  {
    g.axspos ( 350, nya-i*350 );
    g.polcrv ( cpol[i].c_str ( ) );
    g.marker ( 0 );

    g.graf ( 0.0, 20.0, 0.0, 5.0, 0.0, 10.0, 0.0, 5.0 );
    nx = g.nxposn ( 1.0 );
    ny = g.nyposn ( 8.0 );
    g.messag ( cpol[i].c_str ( ), nx, ny );
    g.curve ( x, y, 16 );

    if ( i == 5 )
    {
      g.height ( 50 );
      g.title ( );
    }
    g.endgrf ( );
  }
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX04:\n";
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
