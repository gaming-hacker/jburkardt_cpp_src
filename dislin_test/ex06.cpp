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
  static char cbuf[41];
  string ctit = "Pie Charts (PIEGRF)";
  Dislin g;
  int i;
  int nya = 2800;
  static double xray[5] = { 1.0, 2.5, 2.0, 2.7, 1.8 };

  timestamp ( );
  cout << "\n";
  cout << "EX06:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the use of the PIEGRF routine, for\n";
  cout << "  plotting piechart data.\n";
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
  g.setfil ( "ex06.png" );
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
  g.axslen ( 1600, 1000 );
  g.titlin ( ctit.c_str ( ), 2 );
  g.chnpie ( "both" );

  g.legini ( cbuf, 5, 8 );
  g.leglin ( cbuf, "FIRST", 1 );
  g.leglin ( cbuf, "SECOND", 2 );
  g.leglin ( cbuf, "THIRD", 3 );
  g.leglin ( cbuf, "FOURTH", 4 );
  g.leglin ( cbuf, "FIFTH", 5 );

  g.patcyc ( 1, 7L );
  g.patcyc ( 2, 4L );
  g.patcyc ( 3, 13L );
  g.patcyc ( 4, 3L );
  g.patcyc ( 5, 5L );

  for ( i = 0; i < 2; i++ )
  {
    g.axspos ( 250, nya-i*1200 );
    if ( i == 1 )
    {
      g.labels ( "data", "pie" );
      g.labpos ( "external", "pie" );
    }

    g.piegrf ( cbuf, 1, xray, 5 );

    if ( i == 1 )
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
  cout << "EX06:\n";
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
