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
//    MAIN demonstrates the use of shade patterns.
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
  string ctit = "Shading Patterns (AREAF)";
  ostringstream fred;
  Dislin g;
  int i;
  int iclr;
  int ii;
  static int ix[4] = { 0, 300, 300, 0 };
  int ixp[4];
  static int iy[4] = {0, 0, 400, 400 };
  int iyp[4];
  int j;
  int k;
  int nl;
  int nx;
  int nx0 = 335;
  int ny;
  int ny0 = 350;

  timestamp ( );
  cout << "\n";
  cout << "EX08:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the use of shade patterns.\n";
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
  g.setfil ( "ex08.png" );
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
  g.setvlt ( "small" );

  g.height ( 50 );
  nl = g.nlmess ( ctit.c_str ( ) );
  nx = ( 2970 - nl ) / 2 ;
  g.messag ( ctit.c_str ( ), nx, 200 );

  iclr = 0;
  for ( i = 0; i < 3; i++ )
  {
    ny = ny0 + i * 600;
    for ( j = 0; j < 6; j++ )
    {
      nx = nx0 + j * 400;
      ii = i * 6 + j;
      g.shdpat ( (long) ii );

      fred << ii;
      cstr = fred.str ( );
      fred.str ( "" );

      iclr = iclr % 16;
      iclr = iclr + 1;
      g.setclr ( iclr );

      for ( k = 0; k < 4; k++ )
      {
        ixp[k] = ix[k] + nx;
        iyp[k] = iy[k] + ny;
      }
      g.areaf ( ixp, iyp, 4 );

      nl = g.nlmess ( cstr.c_str ( ) );
      nx = nx + ( 300 - nl ) / 2;
      g.messag ( cstr.c_str ( ), nx, ny+460 );
    }
  }
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX08:\n";
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
