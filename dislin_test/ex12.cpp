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
//    MAIN demonstrates the creation of a shaded contour plot.
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

  Dislin g;
  int i;
  int j;
  double step;
  double x;
  double xray[N];
  double y;
  double yray[N];
  double zlev[12];
  double zmat[N][N];

  timestamp ( );
  cout << "\n";
  cout << "EX12:\n";
  cout << "  C++ version:\n";
  cout << "  Demonstrate a shaded contour plot.\n";

  step = 1.6 / ( double ) ( N - 1 );
  for (i = 0; i < N; i++)
  {
    x = 0.0 + ( double ) i * step;
    xray[i] = x;
    for ( j = 0; j < N; j++)
    {
      y = 0.0 + ( double ) j * step;
      yray[j] = y;
      zmat[i][j] = ( x * x - 1.0 ) * ( x * x - 1.0) 
                 + ( y * y - 1.0 ) * ( y * y - 1.0 );
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
  g.setfil ( "ex12.png" );
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

  g.mixalf ( );
  g.titlin ( "Shaded Contour Plot", 1 );
  g.titlin ( "F(X,Y) = (X[2$ - 1)[2$ + (Y[2$ - 1)[2$", 3 );
  g.name ( "X-axis", "x" );
  g.name ( "Y-axis", "y" );

  g.shdmod ( "poly", "contur" );
  g.axspos ( 450, 2670 );
  g.graf ( 0.0, 1.6, 0.0, 0.2, 0.0, 1.6, 0.0, 0.2 );

  for ( i = 1; i <= 12; i++ )
  {
    zlev[12-i] = 0.1 + ( double ) ( i - 1 ) * 0.1;
  }

  g.conshd ( xray, N, yray, N, (double *) zmat, zlev, 12 );

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
  cout << "EX12:\n";
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
