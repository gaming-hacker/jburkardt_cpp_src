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
//    MAIN demonstrates the use of the POLAR routine.
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
# define M 10
# define N 300

  double a;
  double f;
  Dislin g;
  int i;
  const double pi = 3.141592653589793;
  double step;
  double x2[M];
  double xray[N];
  double y2[M];
  double yray[N];
  
  f = pi / 180.0;

  timestamp ( );
  cout << "\n";
  cout << "EX02:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the use of the POLAR routine, for\n";
  cout << "  plotting (R,Theta) data.\n";

  step = 360.0 / ( double ) ( N - 1 );

  for ( i = 0; i < N; i++ )
  { 
    a = ( double ) i * step * f;
    yray[i] = a;
    xray[i] = sin ( 5.0 * a );
  }

  for ( i = 0; i < M; i++ )
  {
    x2[i] = ( double ) ( i + 1 );
    y2[i] = ( double ) ( i + 1 );
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
  g.setfil ( "ex02.png" );
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
  g.axspos ( 450, 1800 );

  g.titlin ( "Polar Plots", 2 );
  g.ticks  ( 3, "Y" );
  g.axends ( "NOENDS", "X" );
  g.labdig ( -1, "Y" );
  g.axslen ( 1000, 1000 );
  g.axsorg ( 1050, 900 );

  g.polar  ( 1.0, 0.0, 0.2, 0.0, 30.0 );
  g.curve  ( xray, yray, N );
  g.htitle ( 50 );
  g.title  ( );
  g.endgrf ( );

  g.labdig ( -1, "X" );
  g.axsorg ( 1050, 2250 );
  g.labtyp ( "VERT", "Y" );
  g.polar  ( 10.0, 0.0, 2.0, 0.0, 30.0 );
  g.barwth ( -5.0 );
  g.polcrv ( "FBARS" );
  g.curve  ( x2, y2, M );
//
//  Close DISLIN.
//       
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX02:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
# undef M
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
