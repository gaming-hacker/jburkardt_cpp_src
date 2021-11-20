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
# define N 18

  char cbuf[80];
  Dislin g;
  int i;
  int icray[N] = { 30, 30, 30, 30, 30, 30, 100, 100, 100, 100,
                 100, 100, 170, 170, 170, 170, 170, 170 };
  double xray[N]  = { 1.0, 3.0, 8.0, 1.5, 9.0, 6.3, 5.8, 2.3, 8.1, 3.5,
                     2.2, 8.7, 9.2, 4.8, 3.4, 6.9, 7.5, 3.8 };
  double xwray[N];
  double yray[N]  = {5.0, 8.0, 3.5, 2.0, 7.0, 1.0, 4.3, 7.2, 6.0, 8.5,
                    4.1, 5.0, 7.3, 2.8, 1.6, 8.9, 9.5, 3.2 };
  double ywray[N];
  double z1ray[N] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  double z2ray[N] = { 4.0, 5.0, 3.0, 2.0, 3.5, 4.5, 2.0, 1.6, 3.8, 4.7,
                    2.1, 3.5, 1.9, 4.2, 4.9, 2.8, 3.6, 4.3 };

  timestamp ( );
  cout << "\n";
  cout << "EX07B:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate of 3D bar graphs.\n";

  for ( i = 0; i < N; i++ )
  {
    xwray[i] = 0.5;
    ywray[i] = 0.5;
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
  g.setfil ( "ex07b.png" );
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
  g.axspos ( 200, 2600 );
  g.axslen ( 1800, 1800 );

  g.name ( "X-axis", "x" );
  g.name ( "Y-axis", "y" );
  g.name ( "Z-axis", "z" );

  g.titlin ( "3D Bars / BARS3D", 3 );
  g.labl3d ( "hori" );

  g.graf3d ( 0.0, 10.0, 0.0, 2.0, 0.0, 10.0, 0.0, 2.0, 0.0, 5.0, 0.0, 1.0 );
  g.grid3d ( 1, 1, "bottom" );
  g.bars3d ( xray, yray, z1ray, z2ray, xwray, ywray, icray, N );

  g.legini ( cbuf, 3, 20 );
  g.legtit ( " ");
  g.legpos ( 1350, 1150 );
  g.leglin ( cbuf, "First", 1 );
  g.leglin ( cbuf, "Second", 2 );
  g.leglin ( cbuf, "Third", 3 );
  g.legend ( cbuf, 3);

  g.height ( 50 );
  g.title ( );
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX07B:\n";
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
