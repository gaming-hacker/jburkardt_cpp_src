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
//    MAIN demonstrates the creation of a contour plot.
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
# define N 50

  double fpi;
  Dislin g;
  int i;
  int j;
  const double pi = 3.141592653589793;
  double step;
  double x;
  double xray[N];
  double y;
  double yray[N];
  double zlev;
  double zmat[N][N];

  fpi = pi / 180.0;

  timestamp ( );
  cout << "\n";
  cout << "EX11:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate the creation of a contour plot.\n";

  step = 360.0 / ( double ) ( N - 1 );

  for ( i = 0; i < N; i++ )
  {
    xray[i] = ( double ) i * step;
    yray[i] = ( double ) i * step;
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      x = xray[i] * fpi;
      y = yray[j] * fpi;    
      zmat[i][j] = 2.0 * sin(x) * sin(y);
    }
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
  g.setfil ( "ex11.png" );
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

  g.titlin ( "Contour Plot", 1 );
  g.titlin ( "F(X,Y) = 2 * SIN(X) * SIN(Y)", 3 );

  g.name ( "X-axis", "x" );
  g.name ( "Y-axis", "y" );

  g.intax ( );
  g.axspos ( 450, 2670 );
  g.graf ( 0.0, 360.0, 0.0, 90.0, 0.0, 360.0, 0.0, 90.0 );

  g.height ( 30 );

  for ( i = 0; i < 9; i++ )
  {
    zlev = -2.0 + i * 0.5;
    g.setclr ( ( i + 1 ) * 25 );
    if ( i == 4 )
    {
      g.labels ( "none", "contur" ); 
    }
    else
    {
      g.labels ( "double", "contur" );
    }

    g.contur ( xray, N, yray, N, (double *) zmat, zlev );
  }

  g.height ( 50 );
  g.color ( "fore" );
  g.title ( );
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX11:\n";
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
