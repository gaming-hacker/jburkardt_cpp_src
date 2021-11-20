# include <cmath>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "navier_stokes_2d_exact.hpp"

//****************************************************************************80

void all_gms ( double nu, double rho, int n, double x[], double y[], double t,
  double u[], double dudt[], double dudx[], double dudxx[], double dudy[], 
  double dudyy[], double us[], 
  double v[], double dvdt[], double dvdx[], double dvdxx[], double dvdy[], 
  double dvdyy[], double vs[],
  double p[], double dpdt[], double dpdx[], double dpdxx[], double dpdy[], 
  double dpdyy[], double ps[] )

//****************************************************************************80
//
//  Purpose:
//
//    all_gms evaluates the variables of the GMS flow.
//
//  Discussion:
//
//    The flow has been modified by a sign change that makes it slightly
//    more plausible physically.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 August 2020
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double U[N], DUDT[N], DUDX[N], DUDXX[N], DUDY[N], DUDYY[N], US[N],
//    the horizontal velocity values.
//
//    double V[N], DVDT[N], DVDX[N], DVDXX[N], DVDY[N], DVDYY[N], VS[N],
//    the vertical velocity values.
//
//    double P[N], DPDT[N], DPDX[N], DPDXX[N], DPDY[N], DPDYY[N], PS[N],
//    the pressure values.
//
{
  int i;
  static double pi = 3.141592653589793;
  static double pi2 = 3.141592653589793 * 3.141592653589793;
  static double pi3 = 3.141592653589793 * 3.141592653589793 * 3.141592653589793;
  double s;

  for ( i = 0; i < n; i++ )
  {
    s = pow ( -1.0, ceil ( x[i] ) + ceil ( y[i] ) );

    u[i] =             pi  * s * sin ( t ) * pow ( sin (       pi * x[i] ), 2 )  * sin ( 2.0 * pi * y[i] );
    dudt[i] =          pi  * s * cos ( t ) * pow ( sin (       pi * x[i] ), 2 )  * sin ( 2.0 * pi * y[i] );
    dudx[i] =          pi2 * s * sin ( t ) *       sin ( 2.0 * pi * x[i] )       * sin ( 2.0 * pi * y[i] );
    dudxx[i] =   2.0 * pi3 * s * sin ( t ) *       cos ( 2.0 * pi * x[i] )       * sin ( 2.0 * pi * y[i] );
    dudy[i] =    2.0 * pi2 * s * sin ( t ) * pow ( sin (       pi * x[i] ), 2 )  * cos ( 2.0 * pi * y[i] );
    dudyy[i] = - 4.0 * pi3 * s * sin ( t ) * pow ( sin (       pi * x[i] ), 2 )  * sin ( 2.0 * pi * y[i] );

    v[i] =           - pi  * s * sin ( t ) * sin ( 2.0 * pi * x[i] ) * pow ( sin (       pi * y[i] ), 2 );
    dvdt[i] =        - pi  * s * cos ( t ) * sin ( 2.0 * pi * x[i] ) * pow ( sin (       pi * y[i] ), 2 );
    dvdx[i] =  - 2.0 * pi2 * s * sin ( t ) * cos ( 2.0 * pi * x[i] ) * pow ( sin (       pi * y[i] ), 2 );
    dvdxx[i] =   4.0 * pi3 * s * sin ( t ) * sin ( 2.0 * pi * x[i] ) * pow ( sin (       pi * y[i] ), 2 );
    dvdy[i] =        - pi2 * s * sin ( t ) * sin ( 2.0 * pi * x[i] ) *       sin ( 2.0 * pi * y[i] );
    dvdyy[i] = - 2.0 * pi3 * s * sin ( t ) * sin ( 2.0 * pi * x[i] ) *       cos ( 2.0 * pi * y[i] );

    p[i] =              rho * s * sin ( t ) * cos ( pi * x[i] ) * sin ( pi * y[i] );
    dpdt[i] =           rho * s * cos ( t ) * cos ( pi * x[i] ) * sin ( pi * y[i] );
    dpdx[i] =  - pi   * rho * s * sin ( t ) * sin ( pi * x[i] ) * sin ( pi * y[i] );
    dpdxx[i] = - pi2  * rho * s * sin ( t ) * cos ( pi * x[i] ) * sin ( pi * y[i] );
    dpdy[i] =    pi   * rho * s * sin ( t ) * cos ( pi * x[i] ) * cos ( pi * y[i] );
    dpdyy[i] = - pi2  * rho * s * sin ( t ) * cos ( pi * x[i] ) * sin ( pi * y[i] );

    us[i] = dudt[i] + u[i] * dudx[i] + v[i] * dudy[i] + dpdx[i] / rho - nu * ( dudxx[i] + dudyy[i] );
    vs[i] = dvdt[i] + u[i] * dvdx[i] + v[i] * dvdy[i] + dpdy[i] / rho - nu * ( dvdxx[i] + dvdyy[i] );
    ps[i] = dudx[i] + dvdy[i];
  }

  return;
}
//****************************************************************************80

void grid_2d ( int x_num, double x_lo, double x_hi, int y_num, double y_lo, 
  double y_hi, double x[], double y[] )

//****************************************************************************80
//
//  Purpose:
//
//    GRID_2D returns a regular 2D grid.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int X_NUM, the number of X values to use.
//
//    double X_LO, X_HI, the range of X values.
//
//    int Y_NUM, the number of Y values to use.
//
//    double Y_LO, Y_HI, the range of Y values.
//
//  Output:
//
//    double X[X_NUM*Y_NUM], Y[X_NUM*Y_NUM], 
//    the coordinates of the grid.
//
{
  int i;
  int j;
  double xi;
  double yj;

  if ( x_num == 1 )
  {
    for ( j = 0; j < y_num; j++ )
    {
      for ( i = 0; i < x_num; i++ )
      {
        x[i+j*x_num] = ( x_lo + x_hi ) / 2.0;
      }
    }
  }
  else
  {
    for ( i = 0; i < x_num; i++ )
    {
      xi = ( ( double ) ( x_num - i - 1 ) * x_lo   
           + ( double ) (         i     ) * x_hi ) 
           / ( double ) ( x_num     - 1 );
      for ( j = 0; j < y_num; j++ )
      {
        x[i+j*x_num] = xi;
      }
    }
  }

  if ( y_num == 1 )
  {
    for ( j = 0; j < y_num; j++ )
    {
      for ( i = 0; i < x_num; i++ )
      {
        y[i+j*x_num] = ( y_lo + y_hi ) / 2.0;
      }
    }
  }
  else
  {
    for ( j = 0; j < y_num; j++ )
    {
      yj = ( ( double ) ( y_num - j - 1 ) * y_lo   
           + ( double ) (         j     ) * y_hi ) 
           / ( double ) ( y_num     - 1 );
      for ( i = 0; i < x_num; i++ )
      {
        y[i+j*x_num] = yj;
      }
    }
  }

  return;
}
//****************************************************************************80

void ns2de_gnuplot ( string header, int n, double x[], double y[], double u[], 
  double v[], double p[], double s )

//****************************************************************************80
//
//  Purpose:
//
//    NS2DE_GNUPLOT writes the Navier-Stokes solution to files for GNUPLOT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 July 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    string HEADER, a header to be used to name the files.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the evaluation points.
//
//    double U[N], V[N], P[N], the solution samples.
//
//    double S, a scale factor for the velocity vectors.
//
{
  string command_filename;
  ofstream command_unit;
  string data_filename;
  ofstream data_unit;
  int i;
  string plot_filename;
//
//  Write the data file.
//
  data_filename = header + "_data.txt";

  data_unit.open ( data_filename.c_str ( ) );

  for ( i = 0; i < n; i++ )
  {
    data_unit << "  " << x[i]
              << "  " << y[i]
              << "  " << u[i]
              << "  " << v[i]
              << "  " << s * u[i]
              << "  " << s * v[i]
              << "  " << p[i] << "\n";
  }

  data_unit.close ( );

  cout << "\n";
  cout << "  Data written to '" << data_filename << "'\n";
//
//  Write the command file.
//
  command_filename = header + "_commands.txt";
  plot_filename = header + ".png";

  command_unit.open ( command_filename.c_str ( ) );

  command_unit << "#  " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output '" << plot_filename << "'\n";
  command_unit << "#\n";
  command_unit << "#  Add titles and labels.\n";
  command_unit << "#\n";
  command_unit << "set xlabel '<--- X --->'\n";
  command_unit << "set ylabel '<--- Y --->'\n";
  command_unit << "set title 'Navier-Stokes velocity field'\n";
  command_unit << "unset key\n";
  command_unit << "#\n";
  command_unit << "#  Add grid lines.\n";
  command_unit << "#\n";
  command_unit << "set grid\n";
  command_unit << "set size ratio -1\n";
  command_unit << "#\n";
  command_unit << "#  Timestamp the plot.\n";
  command_unit << "#\n";
  command_unit << "set timestamp\n";
  command_unit << "plot '" << data_filename 
               << "' using 1:2:5:6 with vectors \\\n";
  command_unit << "  head filled lt 2 linecolor rgb 'blue'\n";
  command_unit << "quit\n";

  command_unit.close ( );

  cout << "  Commands written to '" << command_filename << "'\n";

  return;
}
//****************************************************************************80

double r8vec_amax ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_AMAX returns the maximum absolute value in an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in the array.
//
//    double A[N], the array.
//
//  Output:
//
//    double AMAX, the value of the entry
//    of largest magnitude.
//
{
  double amax;
  int i;

  amax = 0.0;
  for ( i = 0; i < n; i++ )
  {
    if ( amax < fabs ( a[i] ) )
    {
      amax = fabs ( a[i] );
    }
  }

  return amax;
}
//****************************************************************************80

double r8vec_amin ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_AMIN returns the minimum absolute value in an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 September 2005
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in the array.
//
//    double A[N], the array.
//
//  Output:
//
//    double R8VEC_AMIN, the value of the entry
//    of smallest magnitude.
//
{
  int i;
  const double r8_huge = 1.79769313486231571E+308;
  double value;

  value = r8_huge;
  for ( i = 0; i < n; i++ )
  {
    if ( fabs ( a[i] ) < value )
    {
      value = fabs ( a[i] );
    }
  }

  return value;
}
//****************************************************************************80

void r8vec_linspace ( int n, double a_first, double a_last, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_LINSPACE creates a vector of linearly spaced values.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//    4 points evenly spaced between 0 and 12 will yield 0, 4, 8, 12.
//
//    In other words, the interval is divided into N-1 even subintervals,
//    and the endpoints of intervals are used as the points.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 April 2014
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in the vector.
//
//    double A_FIRST, A_LAST, the first and last entries.
//
//  Output:
//
//    double A[N], a vector of linearly spaced data.
//
{
  int i;

  if ( n == 1 )
  {
    a[0] = ( a_first + a_last ) / 2.0;
  }
  else
  {
    for ( i = 0; i < n; i++ )
    {
      a[i] = ( ( double ) ( n - 1 - i ) * a_first 
             + ( double ) (         i ) * a_last ) 
             / ( double ) ( n - 1     );
    }
  }
  return;
}
//****************************************************************************80

double r8vec_max ( int n, double r8vec[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_MAX returns the value of the maximum element in an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 August 2010
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in the array.
//
//    double R8VEC[N], a pointer to the first entry of the array.
//
//  Output:
//
//    double R8VEC_MAX, the value of the maximum element.  This
//    is set to 0.0 if N <= 0.
//
{
  int i;
  double value;

  value = r8vec[0];

  for ( i = 1; i < n; i++ )
  {
    if ( value < r8vec[i] )
    {
      value = r8vec[i];
    }
  }
  return value;
}
//****************************************************************************80

double r8vec_min ( int n, double r8vec[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_MIN returns the value of the minimum element in an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 July 2005
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in the array.
//
//    double R8VEC[N], the array to be checked.
//
//  Output:
//
//    double R8VEC_MIN, the value of the minimum element.
//
{
  int i;
  double value;

  value = r8vec[0];

  for ( i = 1; i < n; i++ )
  {
    if ( r8vec[i] < value )
    {
      value = r8vec[i];
    }
  }
  return value;
}
//****************************************************************************80

double r8vec_norm_l2 ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_NORM_L2 returns the L2 norm of an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//    The vector L2 norm is defined as:
//
//      R8VEC_NORM_L2 = sqrt ( sum ( 1 <= I <= N ) A(I)^2 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 March 2003
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in A.
//
//    double A[N], the vector whose L2 norm is desired.
//
//  Output:
//
//    double R8VEC_NORM_L2, the L2 norm of A.
//
{
  int i;
  double v;

  v = 0.0;

  for ( i = 0; i < n; i++ )
  {
    v = v + a[i] * a[i];
  }
  v = sqrt ( v );

  return v;
}
//****************************************************************************80

double *r8vec_uniform_ab_new ( int n, double a, double b, int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_AB_NEW returns a scaled pseudorandom R8VEC.
//
//  Discussion:
//
//    Each dimension ranges from A to B.
//
//    This routine implements the recursion
//
//      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
//      u = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Second Edition,
//    Springer, 1987,
//    ISBN: 0387964673,
//    LC: QA76.9.C65.B73.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, December 1986, pages 362-376.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998,
//    ISBN: 0471134031,
//    LC: T57.62.H37.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, Number 2, 1969, pages 136-143.
//
//  Input:
//
//    int N, the number of entries in the vector.
//
//    double A, B, the lower and upper limits of the pseudorandom values.
//
//    int &SEED, a seed for the random number generator.
//
//  Output:
//
//    double R8VEC_UNIFORM_AB_NEW[N], the vector of pseudorandom values.
//
//    int &SEED, a seed for the random number generator.
//
{
  int i;
  const int i4_huge = 2147483647;
  int k;
  double *r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8VEC_UNIFORM_AB_NEW - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  r = new double[n];

  for ( i = 0; i < n; i++ )
  {
    k = seed / 127773;

    seed = 16807 * ( seed - k * 127773 ) - k * 2836;

    if ( seed < 0 )
    {
      seed = seed + i4_huge;
    }

    r[i] = a + ( b - a ) * ( double ) ( seed ) * 4.656612875E-10;
  }

  return r;
}
//****************************************************************************80

void resid_gms ( double nu, double rho, int n, double x[], double y[], double t, 
  double ur[], double vr[], double pr[] )

//****************************************************************************80
//
//  Purpose:
//
//    resid_gms evaluates the residual of the GMS flow.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 August 2020
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double UR[N], VR[N], PR[N], the residuals.
//
{
  int i;
  double *u;
  double *dudt;
  double *dudx;
  double *dudxx;
  double *dudy;
  double *dudyy;
  double *us;
  double *v;
  double *dvdt;
  double *dvdx;
  double *dvdxx;
  double *dvdy;
  double *dvdyy;
  double *vs;
  double *p;
  double *dpdt;
  double *dpdx;
  double *dpdxx;
  double *dpdy;
  double *dpdyy;
  double *ps;

  u = new double[n];
  dudt = new double[n];
  dudx = new double[n];
  dudxx = new double[n];
  dudy = new double[n];
  dudyy = new double[n];
  us = new double[n];
  v = new double[n];
  dvdt = new double[n];
  dvdx = new double[n];
  dvdxx = new double[n];
  dvdy = new double[n];
  dvdyy = new double[n];
  vs = new double[n];
  p = new double[n];
  dpdt = new double[n];
  dpdx = new double[n];
  dpdxx = new double[n];
  dpdy = new double[n];
  dpdyy = new double[n];
  ps = new double[n];

  all_gms ( nu, rho, n, x, y, t,
    u, dudt, dudx, dudxx, dudy, dudyy, us, 
    v, dvdt, dvdx, dvdxx, dvdy, dvdyy, vs, 
    p, dpdt, dpdx, dpdxx, dpdy, dpdyy, ps );

  for ( i = 0; i < n; i++ )
  {
    ur[i] = dudt[i] + u[i] * dudx[i] + v[i] * dudy[i] 
          + dpdx[i] / rho - nu * ( dudxx[i] + dudyy[i] ) - us[i];
    vr[i] = dvdt[i] + u[i] * dvdx[i] + v[i] * dvdy[i] 
          + dpdy[i] / rho - nu * ( dvdxx[i] + dvdyy[i] ) - vs[i];
    pr[i] = dudx[i] + dvdy[i] - ps[i];
  }

  delete [] u;
  delete [] dudt;
  delete [] dudx;
  delete [] dudxx;
  delete [] dudy;
  delete [] dudyy;
  delete [] us;
  delete [] v;
  delete [] dvdt;
  delete [] dvdx;
  delete [] dvdxx;
  delete [] dvdy;
  delete [] dvdyy;
  delete [] vs;
  delete [] p;
  delete [] dpdt;
  delete [] dpdx;
  delete [] dpdxx;
  delete [] dpdy;
  delete [] dpdyy;
  delete [] ps;

  return;
}
//****************************************************************************80

void resid_lukas ( double nu, double rho, int n, double x[], double y[], 
  double t, double ur[], double vr[], double pr[] )

//****************************************************************************80
//
//  Purpose:
//
//    RESID_LUKAS returns Lukas Bystricky residuals.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double UR[N], VR[N], PR[N], the residuals in the U, 
//    V and P equations.
//
{
  double dpdx;
  double dpdy;
  double dudt;
  double dudx;
  double dudxx;
  double dudy;
  double dudyy;
  double dvdt;
  double dvdx;
  double dvdxx;
  double dvdy;
  double dvdyy;
  double *f;
  double *g;
  double *h;
  int i;
  const double r8_pi = 3.141592653589793;
  double u;
  double v;
//
//  Get the right hand sides.
//
  f = new double[n];
  g = new double[n];
  h = new double[n];

  rhs_lukas ( nu, rho, n, x, y, t, f, g, h );
//
//  Form the functions and derivatives of the left hand side.
//
  for ( i = 0; i < n; i++ )
  {
    u = - cos ( r8_pi * x[i] ) / r8_pi;
    dudt = 0.0;
    dudx = sin ( r8_pi * x[i] );
    dudxx = r8_pi * cos ( r8_pi * x[i] );
    dudy = 0.0;
    dudyy = 0.0;

    v = - y[i] * sin ( r8_pi * x[i] );
    dvdt = 0.0;
    dvdx = - r8_pi * y[i] * cos ( r8_pi * x[i] );
    dvdxx = + r8_pi * r8_pi * y[i] * sin ( r8_pi * x[i] );
    dvdy = - sin ( r8_pi * x[i] );
    dvdyy = 0.0;

    dpdx = 0.0;
    dpdy = 0.0;
//
//  Evaluate the residuals.
//
    ur[i] = dudt + u * dudx + v * dudy 
      + ( 1.0 / rho ) * dpdx - nu * ( dudxx + dudyy ) - f[i];

    vr[i] = dvdt + u * dvdx + v * dvdy 
      + ( 1.0 / rho ) * dpdy - nu * ( dvdxx + dvdyy ) - g[i];

    pr[i] = dudx + dvdy - h[i];
  }
//
//  Free memory.
//
  delete [] f;
  delete [] g;
  delete [] h;

  return;
}
//****************************************************************************80

void resid_poiseuille ( double nu, double rho, int n, double x[], double y[], 
  double t, double ur[], double vr[], double pr[] )

//****************************************************************************80
//
//  Purpose:
//
//    RESID_POISEUILLE returns Poiseuille residuals.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 July 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double UR[N], VR[N], PR[N], the residuals in the U, 
//    V and P equations.
//
{
  double dpdx;
  double dpdy;
  double dudt;
  double dudx;
  double dudxx;
  double dudy;
  double dudyy;
  double dvdt;
  double dvdx;
  double dvdxx;
  double dvdy;
  double dvdyy;
  double *f;
  double *g;
  double *h;
  int i;
  double u;
  double v;
//
//  Get the right hand sides.
//
  f = new double[n];
  g = new double[n];
  h = new double[n];

  rhs_poiseuille ( nu, rho, n, x, y, t, f, g, h );
//
//  Form the functions and derivatives of the left hand side.
//
  for ( i = 0; i < n; i++ )
  {
    u = 1.0 - y[i] * y[i];
    dudt = 0.0;
    dudx = 0.0;
    dudxx = 0.0;
    dudy = - 2.0 * y[i];
    dudyy = - 2.0;

    v = 0.0;
    dvdt = 0.0;
    dvdx = 0.0;
    dvdxx = 0.0;
    dvdy = 0.0;
    dvdyy = 0.0;

    dpdx = - 2.0 * rho * nu;
    dpdy = 0.0;
//
//  Evaluate the residuals.
//
    ur[i] = dudt + u * dudx + v * dudy 
      + ( 1.0 / rho ) * dpdx - nu * ( dudxx + dudyy ) - f[i];

    vr[i] = dvdt + u * dvdx + v * dvdy 
      + ( 1.0 / rho ) * dpdy - nu * ( dvdxx + dvdyy ) - g[i];

    pr[i] = dudx + dvdy - h[i];
  }
//
//  Free memory.
//
  delete [] f;
  delete [] g;
  delete [] h;

  return;
}
//****************************************************************************//

void resid_spiral ( double nu, double rho, int n, double x[], double y[], 
  double t, double ur[], double vr[], double pr[] )

//****************************************************************************//
//
//  Purpose:
//
//    RESID_SPIRAL evaluates Spiral residuals.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Maxim Olshanskii, Leo Rebholz,
//    Application of barycenter refined meshes in linear elasticity
//    and incompressible fluid dynamics,
//    ETNA: Electronic Transactions in Numerical Analysis, 
//    Volume 38, pages 258-274, 2011.
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double UR[N], VR[N], PR[N], the right hand sides.
//
{
  double *dpdx;
  double *dpdy;
  double *dudt;
  double *dudx;
  double *dudxx;
  double *dudy;
  double *dudyy;
  double *dvdt;
  double *dvdx;
  double *dvdxx;
  double *dvdy;
  double *dvdyy;
  double *f;
  double *g;
  double *h;
  int i;
  double *p;
  double *u;
  double *v;

  dpdx = new double[n];
  dpdy = new double[n];
  dudt = new double[n];
  dudx = new double[n];
  dudxx = new double[n];
  dudy = new double[n];
  dudyy = new double[n];
  dvdt = new double[n];
  dvdx = new double[n];
  dvdxx = new double[n];
  dvdy = new double[n];
  dvdyy = new double[n];
  f = new double[n];
  g = new double[n];
  h = new double[n];
  p = new double[n];
  u = new double[n];
  v = new double[n];
//
//  Get the right hand side functions.
//
  rhs_spiral ( nu, rho, n, x, y, t, f, g, h );
//
//  Form the functions and derivatives for the left hand side.
//
  for ( i = 0; i < n; i++ )
  {
    u[i] = ( 1.0 + nu * t ) * 2.0 
      * ( pow ( x[i], 4 ) - 2.0 * pow ( x[i], 3 ) + pow ( x[i], 2 ) )
      * ( 2.0 * pow ( y[i], 3 ) - 3.0 * pow ( y[i], 2 ) + y[i] );

    dudt[i] = nu * 2.0 
      * ( pow ( x[i], 4 ) - 2.0 * pow ( x[i], 3 ) + pow ( x[i], 2 ) )
      * ( 2.0 * pow ( y[i], 3 ) - 3.0 * pow ( y[i], 2 ) + y[i] );

    dudx[i] = ( 1.0 + nu * t ) * 2.0 
      * ( 4.0 * pow ( x[i], 3 ) - 6.0 * pow ( x[i], 2 ) + 2.0 * x[i] )
      * ( 2.0 * pow ( y[i], 3 ) - 3.0 * pow ( y[i], 2 ) + y[i] );

    dudxx[i] = ( 1.0 + nu * t ) * 2.0 
      * ( 12.0 * pow ( x[i], 2 ) - 12.0 * x[i] + 2.0 )
      * ( 2.0 * pow ( y[i], 3 ) - 3.0 * pow ( y[i], 2 ) + y[i] );

    dudy[i] = ( 1.0 + nu * t ) * 2.0 
      * ( pow ( x[i], 4 ) - 2.0 * pow ( x[i], 3 ) + pow ( x[i], 2 ) )
      * ( 6.0 * pow ( y[i], 2 ) - 6.0 * y[i] + 1.0 );

    dudyy[i] = ( 1.0 + nu * t ) * 2.0 
      * ( pow ( x[i], 4 ) - 2.0 * pow ( x[i], 3 ) + pow ( x[i], 2 ) )
      * ( 12.0 * y[i] - 6.0 );

    v[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 2.0 * pow ( x[i], 3 ) - 3.0 * pow ( x[i], 2 ) + x[i] )  
      * ( pow ( y[i], 4 ) - 2.0 * pow ( y[i], 3 ) + pow ( y[i], 2 ) );

    dvdt[i] = - nu * 2.0 
      * ( 2.0 * pow ( x[i], 3 ) - 3.0 * pow ( x[i], 2 ) + x[i] )  
      * ( pow ( y[i], 4 ) - 2.0 * pow ( y[i], 3 ) + pow ( y[i], 2 ) );

    dvdx[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 6.0 * pow ( x[i], 2 ) - 6.0 * x[i] + 1.0 )  
      * ( pow ( y[i], 4 ) - 2.0 * pow ( y[i], 3 ) + pow ( y[i], 2 ) );

    dvdxx[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 12.0 * x[i] - 6.0 )  
      * ( pow ( y[i], 4 ) - 2.0 * pow ( y[i], 3 ) + pow ( y[i], 2 ) );

    dvdy[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 2.0 * pow ( x[i], 3 ) - 3.0 * pow ( x[i], 2 ) + x[i] )  
      * ( 4.0 * pow ( y[i], 3 ) - 6.0 * pow ( y[i], 2 ) + 2.0 * y[i] );

    dvdyy[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 2.0 * pow ( x[i], 3 ) - 3.0 * pow ( x[i], 2 ) + x[i] )  
      * ( 12.0 * pow ( y[i], 2 ) - 12.0 * y[i] + 2.0 );

    p[i] = rho * y[i];
    dpdx[i] = 0.0;
    dpdy[i] = rho;

    ur[i] = dudt[i] - nu * ( dudxx[i] + dudyy[i] ) 
      + u[i] * dudx[i] + v[i] * dudy[i] + dpdx[i] / rho - f[i];

    vr[i] = dvdt[i] - nu * ( dvdxx[i] + dvdyy[i] ) 
      + u[i] * dvdx[i] + v[i] * dvdy[i] + dpdy[i] / rho - g[i];

    pr[i] = dudx[i] + dvdy[i] - h[i];
  }

  delete [] dpdx;
  delete [] dpdy;
  delete [] dudt;
  delete [] dudx;
  delete [] dudxx;
  delete [] dudy;
  delete [] dudyy;
  delete [] dvdt;
  delete [] dvdx;
  delete [] dvdxx;
  delete [] dvdy;
  delete [] dvdyy;
  delete [] f;
  delete [] g;
  delete [] h;
  delete [] p;
  delete [] u;
  delete [] v;

  return;
}
//****************************************************************************80

void resid_taylor ( double nu, double rho, int n, double x[], double y[], 
  double t, double ur[], double vr[], double pr[] )

//****************************************************************************80
//
//  Purpose:
//
//    RESID_TAYLOR returns Taylor residuals.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Geoffrey Taylor,
//    On the decay of vortices in a viscous fluid,
//    Philosophical Magazine,
//    Volume 46, 1923, pages 671-674.
//
//    Geoffrey Taylor, A E Green,
//    Mechanism for the production of small eddies from large ones,
//    Proceedings of the Royal Society of London, 
//    Series A, Volume 158, 1937, pages 499-521.
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double UR[N], VR[N], PR[N], the residuals in the U, 
//    V and P equations.
//
{
  double dpdx;
  double dpdy;
  double dudt;
  double dudx;
  double dudxx;
  double dudy;
  double dudyy;
  double dvdt;
  double dvdx;
  double dvdxx;
  double dvdy;
  double dvdyy;
  double *f;
  double *g;
  double *h;
  int i;
  double p;
  const double r8_pi = 3.141592653589793;
  double u;
  double v;
//
//  Get the right hand sides.
//
  f = new double[n];
  g = new double[n];
  h = new double[n];

  rhs_taylor ( nu, rho, n, x, y, t, f, g, h );
//
//  Form the functions and derivatives for the left hand side.
//
  for ( i = 0; i < n; i++ )
  {
    u  =  -                          
        cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dudx =                       r8_pi 
      * sin ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dudxx =              r8_pi * r8_pi 
      * cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dudy =  -                    r8_pi 
      * cos ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dudyy =              r8_pi * r8_pi 
      * cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dudt =  + 2.0 * nu * r8_pi * r8_pi 
      * cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );

    v  =                             
        sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dvdx =                       r8_pi 
      * cos ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dvdxx = -            r8_pi * r8_pi 
      * sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dvdy =  -                    r8_pi 
      * sin ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dvdyy = -            r8_pi * r8_pi 
      * sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dvdt =  - 2.0 * nu * r8_pi * r8_pi 
      * sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );

    p =   - 0.25 * rho * 
      ( cos ( 2.0 * r8_pi * x[i] ) + cos ( 2.0 * r8_pi * y[i] ) );
    dpdx =  + 0.5  * rho * r8_pi * sin ( 2.0 * r8_pi * x[i] );
    dpdy =  + 0.5  * rho * r8_pi * sin ( 2.0 * r8_pi * y[i] );
//
//  Time scaling.
//
    u     = u     * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudx  = dudx  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudxx = dudxx * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudy  = dudy  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudyy = dudyy * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudt  = dudt  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );

    v     = v     * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdx  = dvdx  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdxx = dvdxx * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdy  = dvdy  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdyy = dvdyy * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdt  = dvdt  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );

    p    =   p    * exp ( - 4.0 * r8_pi * r8_pi * nu * t );
    dpdx =  dpdx  * exp ( - 4.0 * r8_pi * r8_pi * nu * t );
    dpdy =  dpdy  * exp ( - 4.0 * r8_pi * r8_pi * nu * t );
//
//  Evaluate the residuals.
//
    ur[i] = dudt + u * dudx + v * dudy 
      + ( 1.0 / rho ) * dpdx - nu * ( dudxx + dudyy ) - f[i];

    vr[i] = dvdt + u * dvdx + v * dvdy 
      + ( 1.0 / rho ) * dpdy - nu * ( dvdxx + dvdyy ) - g[i];

    pr[i] = dudx + dvdy - h[i];
  }
//
//  Free memory.
//
  delete [] f;
  delete [] g;
  delete [] h;

  return;
}
//****************************************************************************80

void resid_vortex ( double nu, double rho, int n, double x[], double y[], 
  double t, double ur[], double vr[], double pr[] )

//****************************************************************************80
//
//  Purpose:
//
//    RESID_VORTEX returns Vortex residuals.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 July 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double UR[N], VR[N], PR[N], the residuals in the U, 
//    V and P equations.
//
{
  double dpdx;
  double dpdy;
  double dudt;
  double dudx;
  double dudxx;
  double dudy;
  double dudyy;
  double dvdt;
  double dvdx;
  double dvdxx;
  double dvdy;
  double dvdyy;
  double *f;
  double *g;
  double *h;
  int i;
  double p;
  const double r8_pi = 3.141592653589793;
  double u;
  double v;
//
//  Get the right hand sides.
//
  f = new double[n];
  g = new double[n];
  h = new double[n];

  rhs_vortex ( nu, rho, n, x, y, t, f, g, h );
//
//  Form the functions and derivatives for the left hand side.
//
  for ( i = 0; i < n; i++ )
  {
    u  =  -                          
        cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dudx =                       r8_pi 
      * sin ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dudxx =              r8_pi * r8_pi 
      * cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dudy =  -                    r8_pi 
      * cos ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dudyy =              r8_pi * r8_pi 
      * cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dudt =  + 2.0 * nu * r8_pi * r8_pi 
      * cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );

    v  =                             
        sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dvdx =                       r8_pi 
      * cos ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dvdxx = -            r8_pi * r8_pi 
      * sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dvdy =  -                    r8_pi 
      * sin ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    dvdyy = -            r8_pi * r8_pi 
      * sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    dvdt =  - 2.0 * nu * r8_pi * r8_pi 
      * sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );

    p =   - 0.25 * rho * 
      ( cos ( 2.0 * r8_pi * x[i] ) + cos ( 2.0 * r8_pi * y[i] ) );
    dpdx =  + 0.5  * rho * r8_pi * sin ( 2.0 * r8_pi * x[i] );
    dpdy =  + 0.5  * rho * r8_pi * sin ( 2.0 * r8_pi * y[i] );
//
//  Time scaling.
//
    u     = u     * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudx  = dudx  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudxx = dudxx * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudy  = dudy  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudyy = dudyy * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dudt  = dudt  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );

    v     = v     * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdx  = dvdx  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdxx = dvdxx * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdy  = dvdy  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdyy = dvdyy * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    dvdt  = dvdt  * exp ( - 2.0 * r8_pi * r8_pi * nu * t );

    p    =   p    * exp ( - 4.0 * r8_pi * r8_pi * nu * t );
    dpdx =  dpdx  * exp ( - 4.0 * r8_pi * r8_pi * nu * t );
    dpdy =  dpdy  * exp ( - 4.0 * r8_pi * r8_pi * nu * t );
//
//  Evaluate the residuals.
//
    ur[i] = dudt + u * dudx + v * dudy 
      + ( 1.0 / rho ) * dpdx - nu * ( dudxx + dudyy ) - f[i];

    vr[i] = dvdt + u * dvdx + v * dvdy 
      + ( 1.0 / rho ) * dpdy - nu * ( dvdxx + dvdyy ) - g[i];

    pr[i] = dudx + dvdy - h[i];
  }
//
//  Free memory.
//
  delete [] f;
  delete [] g;
  delete [] h;

  return;
}
//****************************************************************************80

void rhs_gms ( double nu, double rho, int n, double x[], double y[], double t, 
  double us[], double vs[], double ps[] )

//****************************************************************************80
//
//  Purpose:
//
//    rhs_gms evaluates the source terms of the GMS flow.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 August 2020
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double US[N], VS[N], PS[N], the source terms.
//
{
  double *u;
  double *dudt;
  double *dudx;
  double *dudxx;
  double *dudy;
  double *dudyy;
  double *v;
  double *dvdt;
  double *dvdx;
  double *dvdxx;
  double *dvdy;
  double *dvdyy;
  double *p;
  double *dpdt;
  double *dpdx;
  double *dpdxx;
  double *dpdy;
  double *dpdyy;

  u = new double[n];
  dudt = new double[n];
  dudx = new double[n];
  dudxx = new double[n];
  dudy = new double[n];
  dudyy = new double[n];
  v = new double[n];
  dvdt = new double[n];
  dvdx = new double[n];
  dvdxx = new double[n];
  dvdy = new double[n];
  dvdyy = new double[n];
  p = new double[n];
  dpdt = new double[n];
  dpdx = new double[n];
  dpdxx = new double[n];
  dpdy = new double[n];
  dpdyy = new double[n];

  all_gms ( nu, rho, n, x, y, t,
    u, dudt, dudx, dudxx, dudy, dudyy, us, 
    v, dvdt, dvdx, dvdxx, dvdy, dvdyy, vs, 
    p, dpdt, dpdx, dpdxx, dpdy, dpdyy, ps );

  delete [] u;
  delete [] dudt;
  delete [] dudx;
  delete [] dudxx;
  delete [] dudy;
  delete [] dudyy;
  delete [] v;
  delete [] dvdt;
  delete [] dvdx;
  delete [] dvdxx;
  delete [] dvdy;
  delete [] dvdyy;
  delete [] p;
  delete [] dpdt;
  delete [] dpdx;
  delete [] dpdxx;
  delete [] dpdy;
  delete [] dpdyy;

  return;
}
//****************************************************************************80

void rhs_lukas ( double nu, double rho, int n, double x[], double y[], double t, 
  double f[], double g[], double h[] )

//****************************************************************************80
//
//  Purpose:
//
//    RHS_LUKAS evaluates Lukas Bystricky right hand sides.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double F[N], G[N], H[N], the right hand sides.
//
{
  double *dpdx;
  double *dpdy;
  double *dudt;
  double *dudx;
  double *dudxx;
  double *dudy;
  double *dudyy;
  double *dvdt;
  double *dvdx;
  double *dvdxx;
  double *dvdy;
  double *dvdyy;
  int i;
  double *p;
  const double r8_pi = 3.141592653589793;
  double *u;
  double *v;

  dpdx = new double[n];
  dpdy = new double[n];
  dudt = new double[n];
  dudx = new double[n];
  dudxx = new double[n];
  dudy = new double[n];
  dudyy = new double[n];
  dvdt = new double[n];
  dvdx = new double[n];
  dvdxx = new double[n];
  dvdy = new double[n];
  dvdyy = new double[n];
  p = new double[n];
  u = new double[n];
  v = new double[n];

  for ( i = 0; i < n; i++ )
  {
    u[i] = - cos ( r8_pi * x[i] ) / r8_pi;
    dudt[i] = 0.0;
    dudx[i] = sin ( r8_pi * x[i] );
    dudxx[i] = r8_pi * cos ( r8_pi * x[i] );
    dudy[i] = 0.0;
    dudyy[i] = 0.0;

    v[i] = - y[i] * sin ( r8_pi * x[i] );
    dvdt[i] = 0.0;
    dvdx[i] = - r8_pi * y[i] * cos ( r8_pi * x[i] );
    dvdxx[i] = + r8_pi * r8_pi * y[i] * sin ( r8_pi * x[i] );
    dvdy[i] = - sin ( r8_pi * x[i] );
    dvdyy[i] = 0.0;

    p[i] = 0.0;
    dpdx[i] = 0.0;
    dpdy[i] = 0.0;

    f[i] = dudt[i] - nu * ( dudxx[i] + dudyy[i] ) 
      + u[i] * dudx[i] + v[i] * dudy[i] + dpdx[i] / rho;

    g[i] = dvdt[i] - nu * ( dvdxx[i] + dvdyy[i] ) 
      + u[i] * dvdx[i] + v[i] * dvdy[i] + dpdy[i] / rho;

    h[i] = dudx[i] + dvdy[i];
  }

  delete [] dpdx;
  delete [] dpdy;
  delete [] dudt;
  delete [] dudx;
  delete [] dudxx;
  delete [] dudy;
  delete [] dudyy;
  delete [] dvdt;
  delete [] dvdx;
  delete [] dvdxx;
  delete [] dvdy;
  delete [] dvdyy;
  delete [] p;
  delete [] u;
  delete [] v;

  return;
}
//****************************************************************************80

void rhs_poiseuille ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] )

//****************************************************************************80
//
//  Purpose:
//
//    RHS_POISEUILLE evaluates Poiseuille right hand sides.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 July 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double F[N], G[N], H[N], the right hand sides.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    f[i] = 0.0;
    g[i] = 0.0;
    h[i] = 0.0;
  }

  return;
}
//****************************************************************************//

void rhs_spiral ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] )

//****************************************************************************//
//
//  Purpose:
//
//    RHS_SPIRAL evaluates Spiral right hand sides.
//
//  Discussion:
//
//    The right hand side is artificially determined by the requirement
//    that the specified values of U, V and P satisfy the discretized
//    Navier Stokes and continuity equations.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Maxim Olshanskii, Leo Rebholz,
//    Application of barycenter refined meshes in linear elasticity
//    and incompressible fluid dynamics,
//    ETNA: Electronic Transactions in Numerical Analysis, 
//    Volume 38, pages 258-274, 2011.
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double F[N], G[N], H[N], the right hand sides.
//
{
  double *dpdx;
  double *dpdy;
  double *dudt;
  double *dudx;
  double *dudxx;
  double *dudy;
  double *dudyy;
  double *dvdt;
  double *dvdx;
  double *dvdxx;
  double *dvdy;
  double *dvdyy;
  int i;
  double *p;
  double *u;
  double *v;

  dpdx = new double[n];
  dpdy = new double[n];
  dudt = new double[n];
  dudx = new double[n];
  dudxx = new double[n];
  dudy = new double[n];
  dudyy = new double[n];
  dvdt = new double[n];
  dvdx = new double[n];
  dvdxx = new double[n];
  dvdy = new double[n];
  dvdyy = new double[n];
  p = new double[n];
  u = new double[n];
  v = new double[n];

  for ( i = 0; i < n; i++ )
  {
    u[i] = ( 1.0 + nu * t ) * 2.0 
      * ( pow ( x[i], 4 ) - 2.0 * pow ( x[i], 3 ) + pow ( x[i], 2 ) )
      * ( 2.0 * pow ( y[i], 3 ) - 3.0 * pow ( y[i], 2 ) + y[i] );

    dudt[i] = nu * 2.0 
      * ( pow ( x[i], 4 ) - 2.0 * pow ( x[i], 3 ) + pow ( x[i], 2 ) )
      * ( 2.0 * pow ( y[i], 3 ) - 3.0 * pow ( y[i], 2 ) + y[i] );

    dudx[i] = ( 1.0 + nu * t ) * 2.0 
      * ( 4.0 * pow ( x[i], 3 ) - 6.0 * pow ( x[i], 2 ) + 2.0 * x[i] )
      * ( 2.0 * pow ( y[i], 3 ) - 3.0 * pow ( y[i], 2 ) + y[i] );

    dudxx[i] = ( 1.0 + nu * t ) * 2.0 
      * ( 12.0 * pow ( x[i], 2 ) - 12.0 * x[i] + 2.0 )
      * ( 2.0 * pow ( y[i], 3 ) - 3.0 * pow ( y[i], 2 ) + y[i] );

    dudy[i] = ( 1.0 + nu * t ) * 2.0 
      * ( pow ( x[i], 4 ) - 2.0 * pow ( x[i], 3 ) + pow ( x[i], 2 ) )
      * ( 6.0 * pow ( y[i], 2 ) - 6.0 * y[i] + 1.0 );

    dudyy[i] = ( 1.0 + nu * t ) * 2.0 
      * ( pow ( x[i], 4 ) - 2.0 * pow ( x[i], 3 ) + pow ( x[i], 2 ) )
      * ( 12.0 * y[i] - 6.0 );

    v[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 2.0 * pow ( x[i], 3 ) - 3.0 * pow ( x[i], 2 ) + x[i] )  
      * ( pow ( y[i], 4 ) - 2.0 * pow ( y[i], 3 ) + pow ( y[i], 2 ) );

    dvdt[i] = - nu * 2.0 
      * ( 2.0 * pow ( x[i], 3 ) - 3.0 * pow ( x[i], 2 ) + x[i] )  
      * ( pow ( y[i], 4 ) - 2.0 * pow ( y[i], 3 ) + pow ( y[i], 2 ) );

    dvdx[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 6.0 * pow ( x[i], 2 ) - 6.0 * x[i] + 1.0 )  
      * ( pow ( y[i], 4 ) - 2.0 * pow ( y[i], 3 ) + pow ( y[i], 2 ) );

    dvdxx[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 12.0 * x[i] - 6.0 )  
      * ( pow ( y[i], 4 ) - 2.0 * pow ( y[i], 3 ) + pow ( y[i], 2 ) );

    dvdy[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 2.0 * pow ( x[i], 3 ) - 3.0 * pow ( x[i], 2 ) + x[i] )  
      * ( 4.0 * pow ( y[i], 3 ) - 6.0 * pow ( y[i], 2 ) + 2.0 * y[i] );

    dvdyy[i] = - ( 1.0 + nu * t ) * 2.0 
      * ( 2.0 * pow ( x[i], 3 ) - 3.0 * pow ( x[i], 2 ) + x[i] )  
      * ( 12.0 * pow ( y[i], 2 ) - 12.0 * y[i] + 2.0 );

    p[i] = rho * y[i];
    dpdx[i] = 0.0;
    dpdy[i] = rho;

    f[i] = dudt[i] - nu * ( dudxx[i] + dudyy[i] ) 
      + u[i] * dudx[i] + v[i] * dudy[i] + dpdx[i] / rho;

    g[i] = dvdt[i] - nu * ( dvdxx[i] + dvdyy[i] ) 
      + u[i] * dvdx[i] + v[i] * dvdy[i] + dpdy[i] / rho;

    h[i] = dudx[i] + dvdy[i];
  }

  delete [] dpdx;
  delete [] dpdy;
  delete [] dudt;
  delete [] dudx;
  delete [] dudxx;
  delete [] dudy;
  delete [] dudyy;
  delete [] dvdt;
  delete [] dvdx;
  delete [] dvdxx;
  delete [] dvdy;
  delete [] dvdyy;
  delete [] p;
  delete [] u;
  delete [] v;

  return;
}
//****************************************************************************80

void rhs_taylor ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] )

//****************************************************************************80
//
//  Purpose:
//
//    RHS_TAYLOR returns Taylor right hand sides.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Geoffrey Taylor,
//    On the decay of vortices in a viscous fluid,
//    Philosophical Magazine,
//    Volume 46, 1923, pages 671-674.
//
//    Geoffrey Taylor, A E Green,
//    Mechanism for the production of small eddies from large ones,
//    Proceedings of the Royal Society of London, 
//    Series A, Volume 158, 1937, pages 499-521.
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double F[N], G[N], H[N], the right hand sides in the U, 
//    V and P equations.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    f[i] = 0.0;
    g[i] = 0.0;
    h[i] = 0.0;
  }

  return;
}
//****************************************************************************80

void rhs_vortex ( double nu, double rho, int n, double x[], double y[], 
  double t, double f[], double g[], double h[] )

//****************************************************************************80
//
//  Purpose:
//
//    RHS_VORTEX returns Vortex right hand sides.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 July 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double F[N], G[N], H[N], the right hand sides in the U, 
//    V and P equations.
//
{
  int i;
  const double r8_pi = 3.141592653589793;

  for ( i = 0; i < n; i++ )
  {
    f[i] = - 2.0 * nu * r8_pi * r8_pi 
      * cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    g[i] =   2.0 * nu * r8_pi * r8_pi 
      * sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    h[i] = 0.0;
  }

  return;
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
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
//****************************************************************************80

void uvp_gms ( double nu, double rho, int n, double x[], double y[], double t, 
  double u[], double v[], double p[] )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_gms evaluates the state variables of the GMS flow.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 August 2020
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double U[N], V[N], P[N], the state variables.
//
{
  double *dudt;
  double *dudx;
  double *dudxx;
  double *dudy;
  double *dudyy;
  double *us;
  double *dvdt;
  double *dvdx;
  double *dvdxx;
  double *dvdy;
  double *dvdyy;
  double *vs;
  double *dpdt;
  double *dpdx;
  double *dpdxx;
  double *dpdy;
  double *dpdyy;
  double *ps;

  dudt = new double[n];
  dudx = new double[n];
  dudxx = new double[n];
  dudy = new double[n];
  dudyy = new double[n];
  us = new double[n];
  dvdt = new double[n];
  dvdx = new double[n];
  dvdxx = new double[n];
  dvdy = new double[n];
  dvdyy = new double[n];
  vs = new double[n];
  dpdt = new double[n];
  dpdx = new double[n];
  dpdxx = new double[n];
  dpdy = new double[n];
  dpdyy = new double[n];
  ps = new double[n];

  all_gms ( nu, rho, n, x, y, t,
    u, dudt, dudx, dudxx, dudy, dudyy, us, 
    v, dvdt, dvdx, dvdxx, dvdy, dvdyy, vs, 
    p, dpdt, dpdx, dpdxx, dpdy, dpdyy, ps );

  delete [] dudt;
  delete [] dudx;
  delete [] dudxx;
  delete [] dudy;
  delete [] dudyy;
  delete [] us;
  delete [] dvdt;
  delete [] dvdx;
  delete [] dvdxx;
  delete [] dvdy;
  delete [] dvdyy;
  delete [] vs;
  delete [] dpdt;
  delete [] dpdx;
  delete [] dpdxx;
  delete [] dpdy;
  delete [] dpdyy;
  delete [] ps;

  return;
}
//****************************************************************************80

void uvp_lukas ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] )

//****************************************************************************80
//
//  Purpose:
//
//    UVP_LUKAS evaluates Lukas Bystricky's solution.
//
//  Discussion:
//
//    There is no time dependence.
//
//    The pressure is 0.
//
//    The preferred domain is the unit square.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 March 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double U[N], V[N], P[N], the velocity components and
//    pressure at each of the points.
//
{
  int i;
  const double r8_pi = 3.141592653589793;

  for ( i = 0; i < n; i++ )
  {
    u[i] = - cos ( r8_pi * x[i] ) / r8_pi;
    v[i] = - y[i] *  sin ( r8_pi * x[i] );
    p[i] = - 0.0;
  }

  return;
}
//****************************************************************************80

void uvp_poiseuille ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] )

//****************************************************************************80
//
//  Purpose:
//
//    UVP_POISEUILLE evaluate Poiseuille solutions.
//
//  Discussion:
//
//    There is no time dependence.
//
//    The vertical velocity is zero.
//
//    The preferred domain is a channel bounded by y = -1 and y = +1,
//    along which the boundary condition u = 0 and v = 0 will be satisfied.
//    A parabolic inflow may then be imposed along some line, such as x=0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 July 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double U[N], V[N], P[N], the velocity components and
//    pressure at each of the points.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    u[i] = 1.0 - y[i] * y[i];
    v[i] = 0.0;
    p[i] = - 2.0 * rho * nu;
  }

  return;
}
//****************************************************************************//

void uvp_spiral ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] )

//****************************************************************************//
//
//  Purpose:
//
//    UVP_SPIRAL evaluates Spiral solutions.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 February 2011
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Maxim Olshanskii, Leo Rebholz,
//    Application of barycenter refined meshes in linear elasticity
//    and incompressible fluid dynamics,
//    ETNA: Electronic Transactions in Numerical Analysis, 
//    Volume 38, pages 258-274, 2011.
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the fluid density.
//
//    int N, the number of nodes.
//
//    double X[N], Y[N], the coordinates of nodes.
//
//    double T, the current time.
//
//  Output:
//
//    double U[N], V[N], the X and Y velocity.
//
//    double P[N], the pressure.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    u[i] = ( 1.0 + nu * t ) * 2.0 
      * pow ( x[i], 2 ) * pow ( x[i] - 1.0, 2 )
      * y[i] * ( 2.0 * y[i] - 1.0 ) * ( y[i] - 1.0 );

    v[i] = - ( 1.0 + nu * t ) * 2.0 
      * x[i] * ( 2.0 * x[i] - 1.0 ) * ( x[i] - 1.0 )  
      * pow ( y[i], 2 ) * pow ( y[i] - 1.0, 2 );

    p[i] = rho * y[i];
  }

  return;
}
//****************************************************************************80

void uvp_taylor ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] )

//****************************************************************************80
//
//  Purpose:
//
//    UVP_TAYLOR evaluates Taylor solutions.
//
//  Discussion:
//
//    This flow is known as a Taylor-Green vortex.
//
//    The given velocity and pressure fields are exact solutions for the 2D 
//    incompressible time-dependent Navier Stokes equations over any region.
//
//    To define a typical problem, one chooses a bounded spatial region 
//    and a starting time, and then imposes boundary and initial conditions
//    by referencing the exact solution appropriately.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 January 2015
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Geoffrey Taylor,
//    On the decay of vortices in a viscous fluid,
//    Philosophical Magazine,
//    Volume 46, 1923, pages 671-674.
//
//    Geoffrey Taylor, A E Green,
//    Mechanism for the production of small eddies from large ones,
//    Proceedings of the Royal Society of London, 
//    Series A, Volume 158, 1937, pages 499-521.
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double U[N], V[N], P[N], the velocity components and
//    pressure at each of the points.
//
{
  int i;
  const double r8_pi = 3.141592653589793;

  for ( i = 0; i < n; i++ )
  {
    u[i] = - cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    v[i] =   sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    p[i] = - 0.25 * rho 
      * ( cos ( 2.0 * r8_pi * x[i] ) + cos ( 2.0 * r8_pi * y[i] ) );

    u[i] = u[i] * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    v[i] = v[i] * exp ( - 2.0 * r8_pi * r8_pi * nu * t );
    p[i] = p[i] * exp ( - 4.0 * r8_pi * r8_pi * nu * t );
  }

  return;
}
//****************************************************************************80

void uvp_vortex ( double nu, double rho, int n, double x[], double y[], 
  double t, double u[], double v[], double p[] )

//****************************************************************************80
//
//  Purpose:
//
//    UVP_VORTEX evaluates Vortex solutions.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 July 2015
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    double NU, the kinematic viscosity.
//
//    double RHO, the density.
//
//    int N, the number of evaluation points.
//
//    double X[N], Y[N], the coordinates of the points.
//
//    double T, the time coordinate or coordinates.
//
//  Output:
//
//    double U[N], V[N], P[N], the velocity components and
//    pressure at each of the points.
//
{
  int i;
  const double r8_pi = 3.141592653589793;

  for ( i = 0; i < n; i++ )
  {
    u[i] = - cos ( r8_pi * x[i] ) * sin ( r8_pi * y[i] );
    v[i] =   sin ( r8_pi * x[i] ) * cos ( r8_pi * y[i] );
    p[i] = - 0.25 * rho 
      * ( cos ( 2.0 * r8_pi * x[i] ) + cos ( 2.0 * r8_pi * y[i] ) );
  }

  return;
}
