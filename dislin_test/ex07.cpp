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
//    MAIN demonstrates the creation of 3D bar and pie graphs.
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
  char cbuf[80];
  Dislin g;
  int ic1ray[5]  = { 50, 150, 100, 200, 175 };
  int ic2ray[5]  = { 50, 150, 100, 200, 175 };
  double xray[5]  = { 2.0, 4.0, 6.0, 8.0, 10.0 };
  double y1ray[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
  double y2ray[5] = { 3.2, 1.5, 2.0, 1.0, 3.0 };

  timestamp ( );
  cout << "\n";
  cout << "EX07:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the creation of 3D bar and pie graphs.\n";
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
  g.setfil ( "ex07.png" );
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
//  Use the HARDWARE font.
//
  g.hwfont ( );

  g.titlin ( "3D Bar Graph / 3D Pie Chart", 2 );
  g.htitle ( 40 );

  g.shdpat ( 16 );
  g.axslen ( 1500, 1000 );
  g.axspos ( 300, 1400 );

  g.barwth ( 0.5);
  g.bartyp ( "3dvert" );
  g.labels ( "second", "bars" );
  g.labpos ( "outside", "bars" );
  g.labclr ( 255, "bars" );
  g.graf ( 0.0, 12.0, 0.0, 2.0, 0.0, 5.0, 0.0, 1.0 );
  g.title ( );
  g.color ( "red" );
  g.bars ( xray, y1ray, y2ray, 5 );
  g.endgrf ( );

  g.shdpat ( 16 );
  g.labels ( "data", "pie" );
  g.labclr ( 255, "pie" );
  g.chnpie ( "none" );
  g.pieclr ( ic1ray, ic2ray, 5 );
  g.pietyp ( "3d" );
  g.axspos ( 300, 2700 );
  g.piegrf ( cbuf, 0, y2ray , 5 );
//
//  Close DISLIN.
//      
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX07:\n";
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
