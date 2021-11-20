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
//    MAIN demonstrates the use of bar graphs.
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
  static char cbuf[25];
  string ctit = "Bar Graphs (BARS)";
  Dislin g;
  int i;
  int nya = 2700;
  static double x[9]  = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
  static double y[9]  = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  static double y1[9] = { 1.0, 1.5, 2.5, 1.3, 2.0, 1.2, 0.7, 1.4, 1.1 };
  static double y2[9] = { 2.0, 2.7, 3.5, 2.1, 3.2, 1.9, 2.0, 2.3, 1.8 };
  static double y3[9] = { 4.0, 3.5, 4.5, 3.7, 4.0, 2.9, 3.0, 3.2, 2.6 };

  timestamp ( );
  cout << "\n";
  cout << "EX05:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the display of data in bar graphs.\n";
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
  g.setfil ( "ex05.png" );
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
  g.ticks ( 1, "x" );
  g.intax ( );
  g.axslen ( 1600, 700 );
  g.titlin ( ctit.c_str(), 3 );

  g.legini ( cbuf, 3, 8 );
  g.leglin ( cbuf, "FIRST", 1 );
  g.leglin ( cbuf, "SECOND", 2 );
  g.leglin ( cbuf, "THIRD", 3 );
  g.legtit ( " " );
  g.shdpat ( 5L );

  for ( i = 1; i <= 3; i++ )
  {
     if ( 1 < i )
     {
       g.labels ( "none", "x" );
     }
    g.axspos ( 300, nya-(i-1)*800 );

    g.graf ( 0.0, 10.0, 0.0, 1.0, 0.0, 5.0, 0.0, 1.0 );

    if ( i == 1 )
    {
      g.bargrp ( 3, 0.15 );
      g.color ( "red" );
      g.bars ( x, y, y1, 9 );
      g.color ( "green" );
      g.bars ( x, y, y2, 9 );
      g.color ( "blue" );
      g.bars ( x, y, y3, 9 );
      g.color ( "fore" );
      g.reset ( "bargrp" );
    }
    else if ( i == 2 )
    {
      g.height ( 30 );
      g.labels ( "delta", "bars" );
      g.labpos ( "center", "bars" );
      g.color ( "red" );
      g.bars ( x, y, y1, 9 );
      g.color ( "green" );
      g.bars ( x, y1, y2, 9 );
      g.color ( "blue" );
      g.bars ( x, y2, y3, 9 );
      g.color ( "fore" );
      g.reset ( "height" ); 
    }
    else if ( i == 3 )
    {
      g.labels ( "second", "bars" );
      g.labpos ( "outside", "bars" );
      g.color ( "red" );
      g.bars ( x, y, y1, 9 );
      g.color ( "fore" );
    }

    if ( i < 3 )
    {
      g.legend ( cbuf, 7 );
    }
    else
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
  cout << "EX05:\n";
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
