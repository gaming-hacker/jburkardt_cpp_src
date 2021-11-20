# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <fstream>
# include <iostream>

using namespace std;

int main ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MANDELBROT_PPM creates an ASCII PPM image of the Mandelbrot set.
//
//  Notice:
//
//    mandelbrot_ppm.C   by Eric R. Weeks   written 9-28-96
//    weeks@physics.emory.edu
//    http://www.physics.emory.edu/~weeks/
//
//    This program is public domain, but this header must be left intact
//    and unchanged.
//
//  Author:
//
//    Eric Weeks
//
//  Local Parameters:
//
//    Local, int HXRES, the horizontal resolution (number of pixels);
//
//    Local, int HYRES, the vertical resolution (number of pixels);
//
//    Local, int ITERMAX, the number of iterations to carry out.
//
//    Local, double MAGNIFY, the magnification factor.
//
{
  unsigned char b;
  double cx;
  double cy;
  unsigned char g;
  int hx;
  int hxres = 500;
  int hy;
  int hyres = 500;
  int it2;
  int iteration;
  int itermax = 100;
  double magnify = 1.0;
  ofstream output;
  string output_filename = "mandelbrot.ppm";
  unsigned char r;
  double x;
  double x_new;
  double y;
  double y_new;

  cout << "\n";
  cout << "mandelbrot_ppm\n";
  cout << "  C++ version\n";
  cout << "  Image of Mandelbrot set as a binary PPM file.\n";

  output.open ( output_filename.c_str ( ) );
//
//  Write the PPM header.
//
  output << "P6\n";
  output << "# CREATOR: Eric R Weeks / mandel program\n";
  output << hxres << "  " << hyres << " " << 255 << "\n";

  for ( hy = 1; hy <= hyres; hy++ )
  {
    cy = ( ( ( double ) hy ) / ( ( double ) hyres ) - 0.5 ) / magnify * 3.0;

    for ( hx = 1; hx <= hxres; hx++ )
    {
      cx = ( ( ( double ) hx ) / ( ( double ) hxres ) - 0.5 ) / magnify * 3.0 - 0.7;

      x = 0.0;
      y = 0.0;

      it2 = itermax + 1;

      for ( iteration = 1; iteration <= itermax; iteration++ )
      {
        x_new = cx + x * x - y * y;
        y_new = cy + 2.0 * x * y;

        x = x_new;
        y = y_new;

        if ( 100.0 < x * x + y * y ) 
        { 
          it2 = iteration; 
          break; 
        }

      }

      if ( it2 < itermax ) 
      {
        r =  200+(55*it2)/100;
        g = (230*(100-it2))/100;
        b = (230*(100-it2))/100;
      }
      else
      {
        r = 0;
        g = 255;
        b = 255;
      }
      output << r << g << b;
    }
  }
  output.close ( );

  cout << "\n";
  cout << "  Graphics saved as '" << output_filename << "'\n";

  cout << "\n";
  cout << "mandelbrot_ppm\n";
  cout << "  Normal end of execution.\n";

  return 0;
}

