# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

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
//    MAIN demonstrates the use of the CURVE routine.
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
  int nthk;
  const double pi = 3.141592653589793;
  double step;
  double x;
  double xray[N];
  double y1ray[N];
  double y2ray[N];

  fpi = pi / 180.0;

  timestamp ( );
  cout << "\n";
  cout << "EX01:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the use of the CURVE routine, for\n";
  cout << "  plotting (X,Y) data.\n";

  step = 360.0 / ( double ) ( N - 1 );

  for ( i = 0; i < N; i++ )
  {
    xray[i] = i * step;
    x = xray[i] * fpi;
    y1ray[i] = sin ( x );
    y2ray[i] = cos ( x );
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
  g.setfil ( "ex01.png" );
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
//  Plot a border around the page.
//
  g.pagera ( );
//
//  Use the COMPLEX font.
//
  g.complx ( );
  g.axspos ( 450, 1800 );
  g.axslen ( 2200, 1200 );

  g.name ( "X-axis", "x" );
  g.name ( "Y-axis", "y" );

  g.labdig ( -1, "x" );
  g.ticks ( 10, "xy" );

  g.titlin ( "Demonstration of CURVE", 1 );
  g.titlin ( "SIN(X), COS(X)", 3 );

  g.graf ( 0.0, 360.0, 0.0, 90.0, -1.0, 1.0, -1.0, 0.5 );
  g.title ( );

  g.color ( "red" );

  g.curve ( xray, y1ray, N );
//
//  Make the second curve thicker.
//
  nthk = 10;
  g.thkcrv ( nthk );

  g.color ( "green" );
  g.curve ( xray, y2ray, N );

  g.color ( "fore" );
  g.dash ( );
  g.xaxgit ( );
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX01:\n";
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
