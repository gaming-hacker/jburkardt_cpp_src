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
//    MAIN demonstrates the use of TeX for mathematical formulas.
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
  char cstr[80];
  Dislin g;
  int nl;

  timestamp ( );
  cout << "\n";
  cout << "EX14:\n";
  cout << "  C++ version:\n";
  cout << "  Using TeX for mathematical formulas.\n";
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
  g.setfil ( "ex14.png" );
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
  g.height ( 40 );

  strcpy ( cstr, "TeX Instructions for Mathematical Formulas" );
  nl = g.nlmess ( cstr );
  g.messag ( cstr, ( 2100 - nl ) / 2, 100 );
  
  g.texmod ( "on" );
  g.messag ( "$\\frac{1}{x+y}$", 150, 400 );
  g.messag ( "$\\frac{a^2 - b^2}{a+b} = a - b$", 1200, 400 );
  
  g.messag ( "$r = \\red{\\sqrt{x^2 + y^2}}", 150, 700);
  g.messag ( "$\\cos \\phi = \\frac{x}{\\sqrt{x^2 + y^2}}$", 1200, 700 );

  g.messag ( "$\\Gamma(x) = \\int_0^\\infty e^{-t}t^{x-1}dt$", 150, 1000 );
  g.messag ( "$\\lim_{x \\to \\infty} (1 + \\frac{1}{x})^x = e$", 1200, 1000 );

  g.messag ( "$\\mu = \\sum_{i=1}^n x_i p_i$", 150, 1300 );
  g.messag ( "$\\mu = \\int_{-\\infty}^ \\infty x f(x) dx$", 1200, 1300 );

  g.messag ( "$\\overline{x} = \\frac{1}{n} \\sum_{i=1}^n x_i$", 150, 1600 );
  g.messag ( "$s^2 = \\frac{1}{n-1} \\sum_{i=1}^n (x_i - \\overline{x})^2$",
          1200, 1600 );

  g.messag ( "$\\sqrt[n]{\\frac{x^n - y^n}{1 + u^{2n}}}$", 150, 1900 );  
  g.messag ( "$\\sqrt[3]{-q + \\sqrt{q^2 + p^3}}$", 1200, 1900 );

  g.messag ( "$\\int \\frac{dx}{1+x^2} = \\arctan x + C$", 150, 2200 );
  g.messag ( "$\\int \\frac{dx}{\\sqrt{1+x^2}} = {\\rm arcsinh} x + C$",
          1200, 2200 );

  g.messag ( "$\\overline{P_1P_2} = \\sqrt{(x_2-x_1)^2 + (y_2-y_1)^2}$",
           150, 2500 );
  g.messag ( "$x = \\frac{x_1 + \\lambda x_2}{1 + \\lambda}$", 1200, 2500 );
//
//  Close DISLIN.
//
  g.disfin ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "EX14:\n";
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
