# include <cstdlib>
# include <iostream>
# include <fstream>
# include <sstream>
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
//    MAIN demonstrates the use of the SYMBOL routine.
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
  string cstr;
  string ctit = "Symbols";
  ostringstream fred;
  Dislin g;
  int i;
  int nl;
  int nxp;
  int ny;

  timestamp ( );
  cout << "\n";
  cout << "EX03:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the use of the SYMBOL routine, for\n";
  cout << "  the generation of special symbols and fonts.\n";
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
  g.setfil ( "ex03.png" );
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

  g.height ( 60 );
  nl = g.nlmess ( ctit.c_str ( ) );
  g.messag ( ctit.c_str ( ), ( 2100 - nl ) / 2, 200 );

  g.height ( 50 );
  g.hsymbl ( 120 );

  ny = 150;

  for ( i = 0; i < 24; i++ )
  {
    if ( ( i % 4 ) == 0 ) 
    {
      ny  = ny + 400;
      nxp = 550;
    }
    else
    {
      nxp = nxp + 350;
    }

    fred << i;
    cstr = fred.str ( );
    fred.str ( "" );

    nl = g.nlmess ( cstr.c_str ( ) ) / 2;
    g.messag ( cstr.c_str ( ), nxp-nl ,ny+150 );
    g.symbol ( i, nxp, ny );
  }
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX03:\n";
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
