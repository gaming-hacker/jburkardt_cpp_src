# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "navier_stokes_2d_exact.hpp"

int main ( );

void uvp_gms_test ( );
void uvp_gms_test2 ( );
void rhs_gms_test ( );
void resid_gms_test ( );
void gnuplot_gms_test ( );
void uvp_lukas_test ( );
void uvp_lukas_test2 ( );
void rhs_lukas_test ( );
void resid_lukas_test ( );
void gnuplot_lukas_test ( );
void uvp_poiseuille_test ( );
void uvp_poiseuille_test2 ( );
void rhs_poiseuille_test ( );
void resid_poiseuille_test ( );
void gnuplot_poiseuille_test ( );
void parameter_poiseuille_test ( );
void uvp_spiral_test ( );
void uvp_spiral_test2 ( );
void rhs_spiral_test ( );
void resid_spiral_test ( );
void gnuplot_spiral_test ( );
void parameter_spiral_test ( );
void uvp_taylor_test ( );
void uvp_taylor_test2 ( );
void rhs_taylor_test ( );
void resid_taylor_test ( );
void gnuplot_taylor_test ( );
void parameter_taylor_test ( );
void uvp_vortex_test ( );
void uvp_vortex_test2 ( );
void rhs_vortex_test ( );
void resid_vortex_test ( );
void gnuplot_vortex_test ( );
void parameter_vortex_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    navier_stokes_2d_exact_test tests navier_stokes_2d_exact().
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
{
  timestamp ( );
  cout << "\n";
  cout << "navier_stokes_2d_exact_test\n";
  cout << "  C++ version\n";
  cout << "  Test navier_stokes_2d_exact().\n";
//
//  GMS Flow.
//
  uvp_gms_test ( );
  uvp_gms_test2 ( );
  rhs_gms_test ( );
  resid_gms_test ( );
  gnuplot_gms_test ( );
//
//  Lukas Bystricky Flow.
//
  uvp_lukas_test ( );
  uvp_lukas_test2 ( );
  rhs_lukas_test ( );
  resid_lukas_test ( );
  gnuplot_lukas_test ( );
//
//  Poiseuille Flow.
//
  uvp_poiseuille_test ( );
  uvp_poiseuille_test2 ( );
  rhs_poiseuille_test ( );
  resid_poiseuille_test ( );
  gnuplot_poiseuille_test ( );
  parameter_poiseuille_test ( );
//
//  Spiral Flow.
//
  uvp_spiral_test ( );
  uvp_spiral_test2 ( );
  rhs_spiral_test ( );
  resid_spiral_test ( );
  gnuplot_spiral_test ( );
  parameter_spiral_test ( );
//
//  Taylor Flow.
//
  uvp_taylor_test ( );
  uvp_taylor_test2 ( );
  rhs_taylor_test ( );
  resid_taylor_test ( );
  gnuplot_taylor_test ( );
  parameter_taylor_test ( );
//
//  Vortex Flow.
//
  uvp_vortex_test ( );
  uvp_vortex_test2 ( );
  rhs_vortex_test ( );
  resid_vortex_test ( );
  gnuplot_vortex_test ( );
  parameter_vortex_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "navier_stokes_2d_exact_test\n";
  cout << "  Normal end of execution.\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void uvp_gms_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_gms_test samples the GMS flow at a specific time.
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
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  cout << "\n";
  cout << "uvp_gms_test\n";
  cout << "  GMS flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  at time T = 1,\n";
  cout << "  over the [-1,+1]x[-1,+1] square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  p = new double[n];
  u = new double[n];
  v = new double[n];

  r8_lo = -1.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );

  uvp_gms ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_gms_test2 ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_gms_test2 samples the GMS flow on the boundary.
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
{
  int i;
  int n;
  double nu;
  double *p;
  double r8_hi;
  double r8_lo;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  cout << "\n";
  cout << "uvp_gms_test2\n";
  cout << "  GMS flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  at time T = 1,\n";
  cout << "  over the boundary of the [-1,+1]x[-1,+1] square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 400;

  p = new double[n];
  u = new double[n];
  v = new double[n];
  x = new double[n];
  y = new double[n];

  r8_lo = -1.0;
  r8_hi = 1.0;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_gms ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void rhs_gms_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    rhs_gms_test samples the GMS right hand side at a specific time.
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
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  cout << "\n";
  cout << "rhs_gms_test\n";
  cout << "  GMS flow:\n";
  cout << "  Sample the Navier-Stokes right hand sides\n";
  cout << "  at time T = 1,\n";
  cout << "  over the [-1,+1]x[-1,+1] square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  f = new double[n];
  g = new double[n];
  h = new double[n];

  r8_lo = -1.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );

  rhs_gms ( nu, rho, n, x, y, t, f, g, h );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  F:"
       << "  " << setw(14) << r8vec_min ( n, f )
       << "  " << setw(14) << r8vec_max ( n, f ) << "\n";
  cout << "  G:"
       << "  " << setw(14) << r8vec_min ( n, g )
       << "  " << setw(14) << r8vec_max ( n, g ) << "\n";
  cout << "  H:"
       << "  " << setw(14) << r8vec_min ( n, h )
       << "  " << setw(14) << r8vec_max ( n, h ) << "\n";

  delete [] f;
  delete [] g;
  delete [] h;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void resid_gms_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    resid_gms_test samples the GMS residual at a specific time.
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
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  cout << "\n";
  cout << "resid_gms_test\n";
  cout << "  GMS flow:\n";
  cout << "  Sample the Navier-Stokes residuals\n";
  cout << "  at time T = 1,\n";
  cout << "  over the [-1,+1]x[-1,+1] square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  pr = new double[n];
  ur = new double[n];
  vr = new double[n];

  r8_lo = -1.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );

  resid_gms ( nu, rho, n, x, y, t, ur, vr, pr );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  Ur:"
       << "  " << setw(14) << r8vec_amin ( n, ur )
       << "  " << setw(14) << r8vec_amax ( n, ur ) << "\n";
  cout << "  Vr:"
       << "  " << setw(14) << r8vec_amin ( n, vr )
       << "  " << setw(14) << r8vec_amax ( n, vr ) << "\n";
  cout << "  Pr:"
       << "  " << setw(14) << r8vec_amin ( n, pr )
       << "  " << setw(14) << r8vec_amax ( n, pr ) << "\n";

  delete [] pr;
  delete [] ur;
  delete [] vr;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void gnuplot_gms_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    gnuplot_gms_test plots the GMS flow.
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
{
  string header;
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  nu = 1.0;
  rho = 1.0;
  t = 1.0;

  cout << "\n";
  cout << "gnuplot_gms_test:\n";
  cout << "  GMS flow:\n";
  cout << "  Generate a velocity field on a regular grid.\n";
  cout << "  Store in GNUPLOT data and command files.\n";

  x_lo = -1.0;
  x_hi = 1.0;

  y_lo = -1.0;
  y_hi = 1.0;

  x = new double[x_num*y_num];
  y = new double[x_num*y_num];

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  n = x_num * y_num;

  u = new double[x_num*y_num];
  v = new double[x_num*y_num];
  p = new double[x_num*y_num];

  uvp_gms ( nu, rho, n, x, y, t, u, v, p );

  header = "gms";
  s = 0.25;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_lukas_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_lukas_test samples Lukas Bystricky's flow at the initial time.
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
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "uvp_lukas_test\n";
  cout << "  Lukas Bystricky Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  at the initial time T = 0, over the unit square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  p = new double[n];
  u = new double[n];
  v = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  uvp_lukas ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_lukas_test2 ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_lukas_test2 samples Lukas Bystricky's flow on the boundary.
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
{
  int i;
  int n;
  double nu;
  double *p;
  double r8_hi;
  double r8_lo;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  cout << "\n";
  cout << "uvp_lukas_test2\n";
  cout << "  Lukas Bystricky Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  on the boundary\n";
  cout << "  at the initial time T = 0, over the unit square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 400;

  p = new double[n];
  u = new double[n];
  v = new double[n];
  x = new double[n];
  y = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_lukas ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void rhs_lukas_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    rhs_lukas_test samples Lukas Bystricky's right hand side at the initial time.
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
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "rhs_lukas_test\n";
  cout << "  Lukas Bystricky Flow:\n";
  cout << "  Sample the Navier-Stokes right hand sides\n";
  cout << "  at the initial time T = 0, using the unit square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  f = new double[n];
  g = new double[n];
  h = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  rhs_lukas ( nu, rho, n, x, y, t, f, g, h );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  F:"
       << "  " << setw(14) << r8vec_min ( n, f )
       << "  " << setw(14) << r8vec_max ( n, f ) << "\n";
  cout << "  G:"
       << "  " << setw(14) << r8vec_min ( n, g )
       << "  " << setw(14) << r8vec_max ( n, g ) << "\n";
  cout << "  H:"
       << "  " << setw(14) << r8vec_min ( n, h )
       << "  " << setw(14) << r8vec_max ( n, h ) << "\n";

  delete [] f;
  delete [] g;
  delete [] h;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void resid_lukas_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    resid_lukas_test samples Lukas Bystricky's residual at the initial time.
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
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "resid_lukas_test\n";
  cout << "  Lukas Bystricky Flow:\n";
  cout << "  Sample the Navier-Stokes residuals\n";
  cout << "  at the initial time T = 0, on the unit square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  pr = new double[n];
  ur = new double[n];
  vr = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  resid_lukas ( nu, rho, n, x, y, t, ur, vr, pr );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  Ur:"
       << "  " << setw(14) << r8vec_amin ( n, ur )
       << "  " << setw(14) << r8vec_amax ( n, ur ) << "\n";
  cout << "  Vr:"
       << "  " << setw(14) << r8vec_amin ( n, vr )
       << "  " << setw(14) << r8vec_amax ( n, vr ) << "\n";
  cout << "  Pr:"
       << "  " << setw(14) << r8vec_amin ( n, pr )
       << "  " << setw(14) << r8vec_amax ( n, pr ) << "\n";

  delete [] pr;
  delete [] ur;
  delete [] vr;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void gnuplot_lukas_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    gnuplot_lukas_test plots Lukas Bystricky's flow.
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
{
  string header;
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  cout << "\n";
  cout << "gnuplot_lukas_test:\n";
  cout << "  Lukas Bystricky Flow:\n";
  cout << "  Generate a velocity field on a regular grid.\n";
  cout << "  Store in GNUPLOT data and command files.\n";

  x_lo = 0.0;
  x_hi = 1.0;

  y_lo = 0.0;
  y_hi = 1.0;

  x = new double[x_num*y_num];
  y = new double[x_num*y_num];

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = new double[x_num*y_num];
  v = new double[x_num*y_num];
  p = new double[x_num*y_num];

  uvp_lukas ( nu, rho, n, x, y, t, u, v, p );

  header = "lukas";
  s = 0.25;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_poiseuille_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_poiseuille_test samples Poiseuille flow at the initial time.
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
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "uvp_poiseuille_test\n";
  cout << "  Poiseuille Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  at the initial time T = 0, over a channel region.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  p = new double[n];
  u = new double[n];
  v = new double[n];

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, x_lo, x_hi, seed );
  y = r8vec_uniform_ab_new ( n, y_lo, y_hi, seed );
  t = 0.0;

  uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_poiseuille_test2 ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_poiseuille_test2 samples Poiseuille flow on the boundary.
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
{
  int i;
  int n;
  double nu;
  double *p;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  cout << "\n";
  cout << "uvp_poiseuille_test2\n";
  cout << "  Poiseuille Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  on the boundary\n";
  cout << "  at the initial time T = 0, over a channel region.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 400;

  p = new double[n];
  u = new double[n];
  v = new double[n];
  x = new double[n];
  y = new double[n];

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;

  r8vec_linspace ( 100, x_lo, x_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = y_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = x_hi;
  }
  r8vec_linspace ( 100, y_lo, y_hi, y+100 );

  r8vec_linspace ( 100, x_hi, x_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = y_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = x_lo;
  }
  r8vec_linspace ( 100, y_hi, y_lo, y+300 );

  uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void rhs_poiseuille_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    rhs_poiseuille_test samples Poiseuille right hand sides.
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
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "rhs_poiseuille_test\n";
  cout << "  Poiseuille Flow:\n";
  cout << "  Sample the Navier-Stokes right hand sides\n";
  cout << "  at the initial time T = 0, over a channel region.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  f = new double[n];
  g = new double[n];
  h = new double[n];

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, x_lo, x_hi, seed );
  y = r8vec_uniform_ab_new ( n, y_lo, y_hi, seed );
  t = 0.0;

  rhs_poiseuille ( nu, rho, n, x, y, t, f, g, h );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  F:"
       << "  " << setw(14) << r8vec_min ( n, f )
       << "  " << setw(14) << r8vec_max ( n, f ) << "\n";
  cout << "  G:"
       << "  " << setw(14) << r8vec_min ( n, g )
       << "  " << setw(14) << r8vec_max ( n, g ) << "\n";
  cout << "  H:"
       << "  " << setw(14) << r8vec_min ( n, h )
       << "  " << setw(14) << r8vec_max ( n, h ) << "\n";

  delete [] f;
  delete [] g;
  delete [] h;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void resid_poiseuille_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    resid_poiseuille_test samples Poiseuille residuals.
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
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "resid_poiseuille_test\n";
  cout << "  Poiseuille Flow:\n";
  cout << "  Sample the Navier-Stokes residuals\n";
  cout << "  at the initial time T = 0, over a channel region.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  pr = new double[n];
  ur = new double[n];
  vr = new double[n];

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, x_lo, x_hi, seed );
  y = r8vec_uniform_ab_new ( n, y_lo, y_hi, seed );
  t = 0.0;

  resid_poiseuille ( nu, rho, n, x, y, t, ur, vr, pr );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  Ur:"
       << "  " << setw(14) << r8vec_amin ( n, ur )
       << "  " << setw(14) << r8vec_amax ( n, ur ) << "\n";
  cout << "  Vr:"
       << "  " << setw(14) << r8vec_amin ( n, vr )
       << "  " << setw(14) << r8vec_amax ( n, vr ) << "\n";
  cout << "  Pr:"
       << "  " << setw(14) << r8vec_amin ( n, pr )
       << "  " << setw(14) << r8vec_amax ( n, pr ) << "\n";

  delete [] pr;
  delete [] ur;
  delete [] vr;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void gnuplot_poiseuille_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    gnuplot_poiseuille_test plots the Poiseuille flow.
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
{
  string header;
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  cout << "\n";
  cout << "gnuplot_poiseuille_test:\n";
  cout << "  Poiseuille Flow:\n";
  cout << "  Generate a velocity field on a regular grid.\n";
  cout << "  Store in GNUPLOT data and command files.\n";

  x_lo = 0.0;
  x_hi = 6.0;

  y_lo = -1.0;
  y_hi = +1.0;

  x = new double[x_num*y_num];
  y = new double[x_num*y_num];

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = new double[x_num*y_num];
  v = new double[x_num*y_num];
  p = new double[x_num*y_num];

  uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

  header = "poiseuille";
  s = 5.00;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void parameter_poiseuille_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    PARAMETER_poiseuille_test monitors Poiseuille solution norms for NU, RHO.
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
{
  int i;
  int j;
  int k;
  int n;
  double nu;
  double *p;
  double p_norm;
  double rho;
  int seed;
  double t;
  double *u;
  double u_norm;
  double *v;
  double v_norm;
  double *x;
  double x_hi;
  double x_lo;
  double *y;
  double y_hi;
  double y_lo;

  cout << "\n";
  cout << "PARAMETER_poiseuille_test\n";
  cout << "  Poiseuille Flow:\n";
  cout << "  Monitor solution norms over time for various\n";
  cout << "  values of NU, RHO.\n";

  n = 1000;

  u = new double[n];
  v = new double[n];
  p = new double[n];

  x_lo = 0.0;
  x_hi = 6.0;
  y_lo = -1.0;
  y_hi = +1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, x_lo, x_hi, seed );
  y = r8vec_uniform_ab_new ( n, y_lo, y_hi, seed );
//
//  Vary RHO.
//
  cout << "\n";
  cout << "  RHO affects the pressure scaling.\n";
  cout << "\n";
  cout << "     RHO         NU           T     ||U||       ||V||       ||P||\n";
  cout << "\n";

  nu = 1.0;
  rho = 1.0;

  for ( j = 1; j <= 3; j++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      cout << "  " << setw(10) << rho
           << "  " << setw(10) << nu
           << "  " << setw(8) << t
           << "  " << setw(10) << u_norm
           << "  " << setw(10) << v_norm
           << "  " << setw(10) << p_norm << "\n";
    }
    cout << "\n";
    rho = rho / 100.0;
  }
/*
  Vary NU.
*/
  cout << "\n";
  cout << "  NU affects the time scaling.\n";
  cout << "\n";
  cout << "     RHO         NU           T     ||U||       ||V||       ||P||\n";
  cout << "\n";

  nu = 1.0;
  rho = 1.0;

  for ( i = 1; i <= 4; i++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_poiseuille ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      cout << "  " << setw(10) << rho
           << "  " << setw(10) << nu
           << "  " << setw(8) << t
           << "  " << setw(10) << u_norm
           << "  " << setw(10) << v_norm
           << "  " << setw(10) << p_norm << "\n";
    }

    cout << "\n";

    nu = nu / 10.0;
  }

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_spiral_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_spiral_test samples the Spiral flow at the initial time.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "uvp_spiral_test\n";
  cout << "  Spiral Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  at the initial time T = 0, over the unit square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  p = new double[n];
  u = new double[n];
  v = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_spiral_test2 ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_spiral_test2 samples the Spiral flow on the boundary.
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
{
  int i;
  int n;
  double nu;
  double *p;
  double r8_hi;
  double r8_lo;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  cout << "\n";
  cout << "uvp_spiral_test2\n";
  cout << "  Spiral Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  on the boundary\n";
  cout << "  at the initial time T = 0, over the unit square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 400;

  p = new double[n];
  u = new double[n];
  v = new double[n];
  x = new double[n];
  y = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void rhs_spiral_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    rhs_spiral_test samples the Spiral right hand side.
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
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "rhs_spiral_test\n";
  cout << "  Spiral Flow:\n";
  cout << "  Sample the Navier-Stokes right hand sides\n";
  cout << "  at the initial time T = 0, using the unit square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  f = new double[n];
  g = new double[n];
  h = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  rhs_spiral ( nu, rho, n, x, y, t, f, g, h );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  F:"
       << "  " << setw(14) << r8vec_min ( n, f )
       << "  " << setw(14) << r8vec_max ( n, f ) << "\n";
  cout << "  G:"
       << "  " << setw(14) << r8vec_min ( n, g )
       << "  " << setw(14) << r8vec_max ( n, g ) << "\n";
  cout << "  H:"
       << "  " << setw(14) << r8vec_min ( n, h )
       << "  " << setw(14) << r8vec_max ( n, h ) << "\n";

  delete [] f;
  delete [] g;
  delete [] h;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void resid_spiral_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    resid_spiral_test samples the Spiral residual.
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
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "resid_spiral_test\n";
  cout << "  Spiral Flow:\n";
  cout << "  Sample the Navier-Stokes residuals\n";
  cout << "  at the initial time T = 0, on the unit square.\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  pr = new double[n];
  ur = new double[n];
  vr = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  resid_spiral ( nu, rho, n, x, y, t, ur, vr, pr );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  Ur:"
       << "  " << setw(14) << r8vec_amin ( n, ur )
       << "  " << setw(14) << r8vec_amax ( n, ur ) << "\n";
  cout << "  Vr:"
       << "  " << setw(14) << r8vec_amin ( n, vr )
       << "  " << setw(14) << r8vec_amax ( n, vr ) << "\n";
  cout << "  Pr:"
       << "  " << setw(14) << r8vec_amin ( n, pr )
       << "  " << setw(14) << r8vec_amax ( n, pr ) << "\n";

  delete [] pr;
  delete [] ur;
  delete [] vr;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void gnuplot_spiral_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    gnuplot_spiral_test plots the Spiral flow.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  string header;
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  cout << "\n";
  cout << "gnuplot_spiral_test:\n";
  cout << "  Spiral Flow:\n";
  cout << "  Generate a velocity field on a regular grid.\n";
  cout << "  Store in GNUPLOT data and command files.\n";

  x_lo = 0.0;
  x_hi = 1.0;

  y_lo = 0.0;
  y_hi = 1.0;

  x = new double[x_num*y_num];
  y = new double[x_num*y_num];

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = new double[x_num*y_num];
  v = new double[x_num*y_num];
  p = new double[x_num*y_num];

  uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

  header = "spiral";
  s = 5.00;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void parameter_spiral_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    PARAMETER_spiral_test monitors Spiral solution norms for NU, RHO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int j;
  int k;
  int n;
  double nu;
  double *p;
  double p_norm;
  double rho;
  int seed;
  double t;
  double *u;
  double u_norm;
  double *v;
  double v_norm;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  cout << "\n";
  cout << "PARAMETER_spiral_test\n";
  cout << "  Spiral Flow:\n";
  cout << "  Monitor solution norms over time for various\n";
  cout << "  values of NU, RHO.\n";

  n = 1000;

  u = new double[n];
  v = new double[n];
  p = new double[n];

  r8_lo = 0.0;
  r8_hi = 1.0;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
//
//  Vary RHO.
//
  cout << "\n";
  cout << "  RHO affects the pressure scaling.\n";
  cout << "\n";
  cout << "     RHO         NU           T     ||U||       ||V||       ||P||\n";
  cout << "\n";

  nu = 1.0;
  rho = 1.0;

  for ( j = 1; j <= 3; j++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      cout << "  " << setw(10) << rho
           << "  " << setw(10) << nu
           << "  " << setw(8) << t
           << "  " << setw(10) << u_norm
           << "  " << setw(10) << v_norm
           << "  " << setw(10) << p_norm << "\n";
    }
    cout << "\n";
    rho = rho / 100.0;
  }
/*
  Vary NU.
*/
  cout << "\n";
  cout << "  NU affects the time scaling.\n";
  cout << "\n";
  cout << "     RHO         NU           T     ||U||       ||V||       ||P||\n";
  cout << "\n";

  nu = 1.0;
  rho = 1.0;

  for ( i = 1; i <= 4; i++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_spiral ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      cout << "  " << setw(10) << rho
           << "  " << setw(10) << nu
           << "  " << setw(8) << t
           << "  " << setw(10) << u_norm
           << "  " << setw(10) << v_norm
           << "  " << setw(10) << p_norm << "\n";
    }

    cout << "\n";

    nu = nu / 10.0;
  }

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_taylor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_taylor_test samples the Taylor solution at the initial time.
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
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "uvp_taylor_test\n";
  cout << "  Taylor Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  at the initial time T = 0, using a region that is\n";
  cout << "  the square centered at (1.5,1.5) with 'radius' 1.0,\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  p = new double[n];
  u = new double[n];
  v = new double[n];

  r8_lo = 0.5;
  r8_hi = +2.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_taylor_test2 ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_taylor_test2 samples the Taylor solution on the boundary at the initial time.
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
{
  int i;
  int n;
  double nu;
  double *p;
  double r8_hi;
  double r8_lo;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  cout << "\n";
  cout << "uvp_taylor_test2\n";
  cout << "  Taylor Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  on the boundary\n";
  cout << "  at the initial time T = 0, using a region that is\n";
  cout << "  the square centered at (1.5,1.5) with 'radius' 1.0,\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 400;

  p = new double[n];
  u = new double[n];
  v = new double[n];
  x = new double[n];
  y = new double[n];

  r8_lo = 0.5;
  r8_hi = +2.5;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void rhs_taylor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    rhs_taylor_test samples the Taylor right hand side at the initial time.
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
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "rhs_taylor_test\n";
  cout << "  Taylor Flow:\n";
  cout << "  Sample the Navier-Stokes right hand sides\n";
  cout << "  at the initial time T = 0, using a region that is\n";
  cout << "  the square centered at (1.5,1.5) with 'radius' 1.0,\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  f = new double[n];
  g = new double[n];
  h = new double[n];

  r8_lo = 0.5;
  r8_hi = +2.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  rhs_taylor ( nu, rho, n, x, y, t, f, g, h );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  F:"
       << "  " << setw(14) << r8vec_min ( n, f )
       << "  " << setw(14) << r8vec_max ( n, f ) << "\n";
  cout << "  G:"
       << "  " << setw(14) << r8vec_min ( n, g )
       << "  " << setw(14) << r8vec_max ( n, g ) << "\n";
  cout << "  H:"
       << "  " << setw(14) << r8vec_min ( n, h )
       << "  " << setw(14) << r8vec_max ( n, h ) << "\n";

  delete [] f;
  delete [] g;
  delete [] h;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void resid_taylor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    resid_taylor_test samples the Taylor residual at the initial time.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "resid_taylor_test\n";
  cout << "  Taylor Flow:\n";
  cout << "  Sample the Navier-Stokes residuals\n";
  cout << "  at the initial time T = 0, using a region that is\n";
  cout << "  the square centered at (1.5,1.5) with 'radius' 1.0,\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  pr = new double[n];
  ur = new double[n];
  vr = new double[n];

  r8_lo = 0.5;
  r8_hi = +2.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  resid_taylor ( nu, rho, n, x, y, t, ur, vr, pr );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  Ur:"
       << "  " << setw(14) << r8vec_amin ( n, ur )
       << "  " << setw(14) << r8vec_amax ( n, ur ) << "\n";
  cout << "  Vr:"
       << "  " << setw(14) << r8vec_amin ( n, vr )
       << "  " << setw(14) << r8vec_amax ( n, vr ) << "\n";
  cout << "  Pr:"
       << "  " << setw(14) << r8vec_amin ( n, pr )
       << "  " << setw(14) << r8vec_amax ( n, pr ) << "\n";

  delete [] pr;
  delete [] ur;
  delete [] vr;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void gnuplot_taylor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    gnuplot_taylor_test plots the Taylor flow.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  string header;
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  cout << "\n";
  cout << "gnuplot_taylor_test:\n";
  cout << "  Taylor Flow:\n";
  cout << "  Generate a Taylor vortex velocity field on a regular grid.\n";
  cout << "  Store in GNUPLOT data and command files.\n";

  x_lo = 0.5;
  x_hi = 2.5;

  y_lo = 0.5;
  y_hi = 2.5;

  x = new double[x_num*y_num];
  y = new double[x_num*y_num];

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = new double[x_num*y_num];
  v = new double[x_num*y_num];
  p = new double[x_num*y_num];

  uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

  header = "taylor";
  s = 0.10;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void parameter_taylor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    PARAMETER_taylor_test monitors Taylor solution norms for various values of NU, RHO.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int j;
  int k;
  int n;
  double nu;
  double *p;
  double p_norm;
  double rho;
  int seed;
  double t;
  double *u;
  double u_norm;
  double *v;
  double v_norm;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  cout << "\n";
  cout << "PARAMETER_taylor_test\n";
  cout << "  Taylor Flow:\n";
  cout << "  Monitor solution norms over time for various\n";
  cout << "  values of NU, RHO.\n";

  n = 1000;

  u = new double[n];
  v = new double[n];
  p = new double[n];

  r8_lo = 0.5;
  r8_hi = +2.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
//
//  Vary RHO.
//
  cout << "\n";
  cout << "  RHO affects the pressure scaling.\n";
  cout << "\n";
  cout << "     RHO         NU           T     ||U||       ||V||       ||P||\n";
  cout << "\n";

  nu = 1.0;
  rho = 1.0;

  for ( j = 1; j <= 3; j++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      cout << "  " << setw(10) << rho
           << "  " << setw(10) << nu
           << "  " << setw(8) << t
           << "  " << setw(10) << u_norm
           << "  " << setw(10) << v_norm
           << "  " << setw(10) << p_norm << "\n";
    }
    cout << "\n";
    rho = rho / 100.0;
  }
/*
  Vary NU.
*/
  cout << "\n";
  cout << "  NU affects the time scaling.\n";
  cout << "\n";
  cout << "     RHO         NU           T     ||U||       ||V||       ||P||\n";
  cout << "\n";

  nu = 1.0;
  rho = 1.0;

  for ( i = 1; i <= 4; i++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_taylor ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      cout << "  " << setw(10) << rho
           << "  " << setw(10) << nu
           << "  " << setw(8) << t
           << "  " << setw(10) << u_norm
           << "  " << setw(10) << v_norm
           << "  " << setw(10) << p_norm << "\n";
    }

    cout << "\n";

    nu = nu / 10.0;
  }

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_vortex_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_vortex_test samples the Vortex solution at the initial time.
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
{
  int n;
  double nu;
  double *p;
  double rho;
  int seed;
  double t;
  double *u;
  double *v;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "uvp_vortex_test\n";
  cout << "  Vortex Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  at the initial time T = 0, using a region that is\n";
  cout << "  the square centered at (1.0,1.0) with 'radius' 0.5,\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  p = new double[n];
  u = new double[n];
  v = new double[n];

  r8_lo = 0.5;
  r8_hi = +1.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void uvp_vortex_test2 ( )

//****************************************************************************80
//
//  Purpose:
//
//    uvp_vortex_test2 samples the Vortex solution on the boundary at the initial time.
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
{
  int i;
  int n;
  double nu;
  double *p;
  double r8_hi;
  double r8_lo;
  double rho;
  double t;
  double *u;
  double *v;
  double *x;
  double *y;

  nu = 1.0;
  rho = 1.0;
  t = 0.0;

  cout << "\n";
  cout << "uvp_vortex_test2\n";
  cout << "  Vortex Flow:\n";
  cout << "  Estimate the range of velocity and pressure\n";
  cout << "  on the boundary\n";
  cout << "  at the initial time T = 0, using a region that is\n";
  cout << "  the square centered at (1.0,1.0) with 'radius' 0.5,\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 400;

  p = new double[n];
  u = new double[n];
  v = new double[n];
  x = new double[n];
  y = new double[n];

  r8_lo = 0.5;
  r8_hi = +1.5;

  r8vec_linspace ( 100, r8_lo, r8_hi, x );
  for ( i = 0; i < 100; i++ )
  {
    y[i] = r8_lo;
  }

  for ( i = 100; i < 200; i++ )
  {
    x[i] = r8_hi;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+100 );

  r8vec_linspace ( 100, r8_hi, r8_lo, x+200 );
  for ( i = 200; i < 300; i++ )
  {
    y[i] = r8_hi;
  }

  for ( i = 300; i < 400; i++ )
  {
    x[i] = r8_lo;
  }
  r8vec_linspace ( 100, r8_lo, r8_hi, y+300 );

  uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  U:"
       << "  " << setw(14) << r8vec_min ( n, u )
       << "  " << setw(14) << r8vec_max ( n, u ) << "\n";
  cout << "  V:"
       << "  " << setw(14) << r8vec_min ( n, v )
       << "  " << setw(14) << r8vec_max ( n, v ) << "\n";
  cout << "  P:"
       << "  " << setw(14) << r8vec_min ( n, p )
       << "  " << setw(14) << r8vec_max ( n, p ) << "\n";

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void rhs_vortex_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    rhs_vortex_test samples the Vortex right hand side at the initial time.
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
{
  double *f;
  double *g;
  double *h;
  int n;
  double nu;
  double rho;
  int seed;
  double t;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "rhs_vortex_test\n";
  cout << "  Vortex Flow:\n";
  cout << "  Sample the Navier-Stokes right hand sides\n";
  cout << "  at the initial time T = 0, using a region that is\n";
  cout << "  the square centered at (1.0,1.0) with 'radius' 0.5,\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  f = new double[n];
  g = new double[n];
  h = new double[n];

  r8_lo = 0.5;
  r8_hi = +1.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  rhs_vortex ( nu, rho, n, x, y, t, f, g, h );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  F:"
       << "  " << setw(14) << r8vec_min ( n, f )
       << "  " << setw(14) << r8vec_max ( n, f ) << "\n";
  cout << "  G:"
       << "  " << setw(14) << r8vec_min ( n, g )
       << "  " << setw(14) << r8vec_max ( n, g ) << "\n";
  cout << "  H:"
       << "  " << setw(14) << r8vec_min ( n, h )
       << "  " << setw(14) << r8vec_max ( n, h ) << "\n";

  delete [] f;
  delete [] g;
  delete [] h;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void resid_vortex_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    resid_vortex_test samples the Vortex residual at the initial time.
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
{
  int n;
  double nu;
  double *pr;
  double rho;
  int seed;
  double t;
  double *ur;
  double *vr;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  nu = 1.0;
  rho = 1.0;

  cout << "\n";
  cout << "resid_vortex_test\n";
  cout << "  Vortex Flow:\n";
  cout << "  Sample the Navier-Stokes residuals\n";
  cout << "  at the initial time T = 0, using a region that is\n";
  cout << "  the square centered at (1.0,1.0) with 'radius' 0.5,\n";
  cout << "  Kinematic viscosity NU = " << nu << "\n";
  cout << "  Fluid density RHO = " << rho << "\n";

  n = 1000;

  pr = new double[n];
  ur = new double[n];
  vr = new double[n];

  r8_lo = 0.5;
  r8_hi = +1.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  t = 0.0;

  resid_vortex ( nu, rho, n, x, y, t, ur, vr, pr );

  cout << "\n";
  cout << "           Minimum       Maximum\n";
  cout << "\n";
  cout << "  Ur:"
       << "  " << setw(14) << r8vec_amin ( n, ur )
       << "  " << setw(14) << r8vec_amax ( n, ur ) << "\n";
  cout << "  Vr:"
       << "  " << setw(14) << r8vec_amin ( n, vr )
       << "  " << setw(14) << r8vec_amax ( n, vr ) << "\n";
  cout << "  Pr:"
       << "  " << setw(14) << r8vec_amin ( n, pr )
       << "  " << setw(14) << r8vec_amax ( n, pr ) << "\n";

  delete [] pr;
  delete [] ur;
  delete [] vr;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void gnuplot_vortex_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    gnuplot_vortex_test plots the Vortex flow.
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
{
  string header;
  int n;
  double nu;
  double *p;
  double rho;
  double s;
  double t;
  double *u;
  double *v;
  double *x;
  double x_hi;
  double x_lo;
  int x_num = 21;
  double *y;
  double y_hi;
  double y_lo;
  int y_num = 21;

  cout << "\n";
  cout << "gnuplot_vortex_test:\n";
  cout << "  Vortex Flow:\n";
  cout << "  Generate a Vortex vortex velocity field on a regular grid.\n";
  cout << "  Store in GNUPLOT data and command files.\n";

  x_lo = 0.5;
  x_hi = 1.5;

  y_lo = 0.5;
  y_hi = 1.5;

  x = new double[x_num*y_num];
  y = new double[x_num*y_num];

  grid_2d ( x_num, x_lo, x_hi, y_num, y_lo, y_hi, x, y );

  nu = 1.0;
  rho = 1.0;
  n = x_num * y_num;
  t = 0.0;

  u = new double[x_num*y_num];
  v = new double[x_num*y_num];
  p = new double[x_num*y_num];

  uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

  header = "vortex";
  s = 0.10;
  ns2de_gnuplot ( header, n, x, y, u, v, p, s );

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void parameter_vortex_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    PARAMETER_vortex_test monitors Vortex solution norms for various values of NU, RHO.
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
{
  int i;
  int j;
  int k;
  int n;
  double nu;
  double *p;
  double p_norm;
  double rho;
  int seed;
  double t;
  double *u;
  double u_norm;
  double *v;
  double v_norm;
  double *x;
  double r8_hi;
  double r8_lo;
  double *y;

  cout << "\n";
  cout << "PARAMETER_vortex_test\n";
  cout << "  Vortex Flow:\n";
  cout << "  Monitor solution norms over time for various\n";
  cout << "  values of NU, RHO.\n";

  n = 1000;

  u = new double[n];
  v = new double[n];
  p = new double[n];

  r8_lo = 0.5;
  r8_hi = +1.5;
  seed = 123456789;

  x = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
  y = r8vec_uniform_ab_new ( n, r8_lo, r8_hi, seed );
//
//  Vary RHO.
//
  cout << "\n";
  cout << "  RHO affects the pressure scaling.\n";
  cout << "\n";
  cout << "     RHO         NU           T     ||U||       ||V||       ||P||\n";
  cout << "\n";

  nu = 1.0;
  rho = 1.0;

  for ( j = 1; j <= 3; j++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      cout << "  " << setw(10) << rho
           << "  " << setw(10) << nu
           << "  " << setw(8) << t
           << "  " << setw(10) << u_norm
           << "  " << setw(10) << v_norm
           << "  " << setw(10) << p_norm << "\n";
    }
    cout << "\n";
    rho = rho / 100.0;
  }
/*
  Vary NU.
*/
  cout << "\n";
  cout << "  NU affects the time scaling.\n";
  cout << "\n";
  cout << "     RHO         NU           T     ||U||       ||V||       ||P||\n";
  cout << "\n";

  nu = 1.0;
  rho = 1.0;

  for ( i = 1; i <= 4; i++ )
  {
    for ( k = 0; k <= 5; k++ )
    {
      t = ( double ) ( k ) / 5.0;

      uvp_vortex ( nu, rho, n, x, y, t, u, v, p );

      u_norm = r8vec_norm_l2 ( n, u ) / ( double ) ( n );
      v_norm = r8vec_norm_l2 ( n, v ) / ( double ) ( n );
      p_norm = r8vec_norm_l2 ( n, p ) / ( double ) ( n );

      cout << "  " << setw(10) << rho
           << "  " << setw(10) << nu
           << "  " << setw(8) << t
           << "  " << setw(10) << u_norm
           << "  " << setw(10) << v_norm
           << "  " << setw(10) << p_norm << "\n";
    }

    cout << "\n";

    nu = nu / 10.0;
  }

  delete [] p;
  delete [] u;
  delete [] v;
  delete [] x;
  delete [] y;

  return;
}

