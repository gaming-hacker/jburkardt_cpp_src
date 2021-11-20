# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>
# include <cstring>

using namespace std;

# include "shepard_interp_2d.hpp"
# include "r8lib.hpp"

//****************************************************************************80

double *shepard_interp_2d ( int nd, double xd[], double yd[], double zd[],
  double p, int ni, double xi[], double yi[] )

//****************************************************************************80
//
//  Purpose:
//
//    SHEPARD_INTERP_2D evaluates a 2D Shepard interpolant.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 October 2012
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Donald Shepard,
//    A two-dimensional interpolation function for irregularly spaced data,
//    ACM '68: Proceedings of the 1968 23rd ACM National Conference,
//    ACM, pages 517-524, 1969.
//
//  Parameters:
//
//    Input, int ND, the number of data points.
//
//    Input, double XD[ND], YD[ND], the data points.
//
//    Input, double ZD[ND], the data values.
//
//    Input, double P, the power.
//
//    Input, int NI, the number of interpolation points.
//
//    Input, double XI[NI], YI[NI], the interpolation points.
//
//    Output, double SHEPARD_INTERP_2D[NI], the interpolated values.
//
{ 
  int i;
  int j;
  double s;
  double *w;
  int z;
  double *zi;

  w = new double[nd];
  zi = new double[ni];

  for ( i = 0; i < ni; i++ )
  {
    if ( p == 0.0 )
    {
      for ( j = 0; j < nd; j++ )
      {
        w[j] = 1.0 / ( double ) ( nd );
      }
    }
    else
    {
      z = -1;
      for ( j = 0; j < nd; j++ )
      {
        w[j] = sqrt ( pow ( xi[i] - xd[j], 2 )
                    + pow ( yi[i] - yd[j], 2 ) );
        if ( w[j] == 0.0 )
        {
          z = j;
          break;
        }
      }

      if ( z != -1 )
      {
        for ( j = 0; j < nd; j++ )
        {
          w[j] = 0.0;
        }
        w[z] = 1.0;
      }
      else
      {
        for ( j = 0; j < nd; j++ )
        {
          w[j] = 1.0 / pow ( w[j], p );
        }
        s = 0.0;
        for ( j = 0; j < nd; j++ )
        {
          s = s + w[j];
        }
        for ( j = 0; j < nd; j++ )
        {
          w[j] = w[j] / s;
        }
      }
    }
    zi[i] = r8vec_dot_product ( nd, w, zd );
  }
  delete [] w;

  return zi;
}
