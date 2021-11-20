# include <cmath>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "stochastic_diffusion.hpp"

int main ( );
void diffusivity_1d_pwc_test ( );
void diffusivity_1d_xk_test ( );
void diffusivity_2d_bnt_contour ( );
void diffusivity_2d_elman_contour ( );
void diffusivity_2d_ntw_contour ( );
void diffusivity_2d_pwc_test ( );
void diffusivity_2d_pwc_contour ( int h, int w, double a, double b, double c, 
  double d );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for stochastic_diffusion_test.
//
//  Discussion:
//
//    stochastic_diffusion_test tests STOCHASTIC_DIFFUSION.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 March 2019
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "stochastic_diffusion_test\n";
  cout << "  C++ version\n";
  cout << "  Test stochastic_diffusion.\n";

  diffusivity_1d_pwc_test ( );
  diffusivity_1d_xk_test ( );
  diffusivity_2d_bnt_contour ( );
  diffusivity_2d_elman_contour ( );
  diffusivity_2d_ntw_contour ( );
  diffusivity_2d_pwc_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "stochastic_diffusion_test\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void diffusivity_1d_pwc_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    diffusivity_1d_pwc_test tests diffusivity_1d_pwc.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 March 2019
//
//  Author:
//
//    John Burkardt
//
{
  string command_filename = "diffusivity_1d_pwc_commands.txt";
  ofstream command_unit;
  string data_filename = "diffusivity_1d_pwc_data.txt";
  ofstream data_unit;
  int j;
  int nc;
  int np;
  double vc[] = { 1.0,  1.5,  3.0,   1.2, 1.0, 0.8, 0.2,  0.4, 0.8, 1.0 };
  double *vp;
  double vp_max;
  double x_max;
  double x_min;
  double xc[] = { -0.9, -0.5, -0.45, -0.1, 0.2, 0.3, 0.32, 0.7, 0.85 };
  double *xp;

  cout << "\n";
  cout << "diffusivity_1d_pwc_test\n";
  cout << "  Test diffusivity_1d_pwc.\n";
//
//  Set up the spatial grid.
//
  nc = 10;
//
//  Sample the diffusivity.
//
  np = 100;
  x_min = -1.0;
  x_max = +1.0;
  xp = r8vec_linspace_new ( np, x_min, x_max );
//
//  Compute the diffusivity field.
//
  vp = diffusivity_1d_pwc ( nc, xc, vc, np, xp );
//
//  Create data file.
//
  data_unit.open ( data_filename.c_str ( ) );
  for ( j = 0; j < np; j++ )
  {
    data_unit << "  " << setw(14) << xp[j]
              << "  " << setw(14) << vp[j] << "\n";
  }
  data_unit.close ( );
  cout << "\n";
  cout << "  Created graphics data file '" << data_filename << "'\n";
//
//  Create the command file.
//
  vp_max = r8vec_max ( np, vp );

  command_unit.open ( command_filename.c_str ( ) );

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output 'diffusivity_1d_pwc.png'\n";
  command_unit << "set xlabel '<---X--->'\n";
  command_unit << "set ylabel '<---Rho(X)--->'\n";
  command_unit << "set yrange [0.0:" << vp_max << "]\n";
  command_unit << "set title 'PWC 1D Stochastic diffusivity function'\n";
  command_unit << "set grid\n";
  command_unit << "set style data lines\n";
  command_unit << "plot '" << data_filename << "' using 1:2 lw 3 linecolor rgb 'red'\n";

  command_unit.close ( );

  cout << "  Created graphics command file '" << command_filename << "'\n";
//
//  Free memory.
//
  delete [] vp;
  delete [] xp;

  return;
}
//****************************************************************************80

void diffusivity_1d_xk_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    diffusivity_1d_xk_test tests diffusivity_1d_xk.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 August 2013
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Dongbin Xiu, George Karniadakis,
//    Modeling uncertainty in steady state diffusion problems via
//    generalized polynomial chaos,
//    Computer Methods in Applied Mechanics and Engineering,
//    Volume 191, 2002, pages 4927-4948.
//
{
  double *dc;
  double dc_max;
  double dc0;
  string command_filename = "diffusivity_1d_xk_commands.txt";
  ofstream command_unit;
  string data_filename = "diffusivity_1d_xk_data.txt";
  ofstream data_unit;
  int j;
  int m;
  int n;
  int seed;
  double *omega;
  double *x;
  double x_min;
  double x_max;

  cout << "\n";
  cout << "diffusivity_1d_xk_test\n";
  cout << "  Plot the stochastic diffusivity function\n";
  cout << "  defined by diffusivity_1d_xk.\n";
//
//  Set up the spatial grid.
//
  n = 51;
  x_min = -1.0;
  x_max = +1.0;
  x = r8vec_linspace_new ( n, x_min, x_max );
//
//  Sample the OMEGA values.
//
  m = 5;
  seed = 123456789;
  omega = r8vec_normal_01_new ( m, seed );
//
//  Compute the diffusivity field.
//
  dc0 = 10.0;
  dc = diffusivity_1d_xk ( dc0, m, omega, n, x );
//
//  Create data file.
//
  data_unit.open ( data_filename.c_str ( ) );
  for ( j = 0; j < n; j++ )
  {
    data_unit
      << "  " << setw(14) << x[j]
      << "  " << setw(14) << dc[j] << "\n";
  }
  data_unit.close ( );
  cout << "\n";
  cout << "  Created graphics data file '" << data_filename << "'\n";
//
//  Create the command file.
//
  dc_max = r8vec_max ( n, dc );

  command_unit.open ( command_filename.c_str ( ) );

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output 'diffusivity_1d_xk.png'\n";
  command_unit << "set xlabel '<---X--->'\n";
  command_unit << "set ylabel '<---DC(X)--->'\n";
  command_unit << "set yrange [0.0:" << dc_max << "]\n";
  command_unit << "set title 'XK Stochastic diffusivity function'\n";
  command_unit << "set grid\n";
  command_unit << "set style data lines\n";
  command_unit << "plot '" << data_filename << "' using 1:2 lw 3 linecolor rgb 'red'\n";

  command_unit.close ( );

  cout << "  Created graphics command file '" << command_filename << "'\n";
//
//  Free memory.
//
  delete [] dc;
  delete [] omega;
  delete [] x;

  return;
}
//****************************************************************************80

void diffusivity_2d_bnt_contour ( )

//****************************************************************************80
//
//  Purpose:
//
//    diffusivity_2d_bnt_contour displays contour plots of a 2D stochastic diffusivity function.
//
//  Discussion:
//
//    The diffusivity function is computed by diffusivity_2d_bnt.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 August 2013
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Ivo Babuska, Fabio Nobile, Raul Tempone,
//    A stochastic collocation method for elliptic partial differential equations
//    with random input data,
//    SIAM Journal on Numerical Analysis,
//    Volume 45, Number 3, 2007, pages 1005-1034.
//
{
  string command_filename = "diffusivity_2d_bnt_commands.txt";
  ofstream command_unit;
  string data_filename = "diffusivity_2d_bnt_data.txt";
  ofstream data_unit;
  double *dc;
  double dc0;
  int i;
  int j;
  int m = 4;
  int n;
  int nx = 41;
  int ny = 31;
  double *omega;
  int seed;
  double *xmat;
  double *xvec;
  double *ymat;
  double *yvec;

  cout << "\n";
  cout << "diffusivity_2d_bnt_contour\n";
  cout << "  Display contour or surface plots of the stochastic\n";
  cout << "  diffusivity function defined by diffusivity_2d_bnt.\n";
  cout << "\n";
  cout << "  The first plot uses uniform random values for OMEGA.\n";
  cout << "  The second uses Gaussian (normal) random values.\n";
//
//  Set the spatial grid.
//
  xvec = r8vec_linspace_new ( nx, -1.5, 0.0 );
  yvec = r8vec_linspace_new ( ny, -0.4, 0.8 );

  xmat = new double[nx*ny];
  ymat = new double[nx*ny];
  r8vec_mesh_2d ( nx, ny, xvec, yvec, xmat, ymat );
//
//  Sample OMEGA.
//
  seed = 123456789;
  omega = r8vec_uniform_01_new ( m, seed );
//
//  Compute the diffusivity field.
//
  dc0 = 10.0;
  n = nx * ny;
  dc = diffusivity_2d_bnt ( dc0, omega, n, xmat, ymat );
//
//  Create a data file.
//
  data_unit.open ( data_filename.c_str() );
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      data_unit 
        << "  " << setw(14) << xmat[i+j*nx]
        << "  " << setw(14) << ymat[i+j*nx]
        << "  " << setw(14) << dc[i+j*nx] << "\n";
    }
    data_unit << "\n";
  }
  data_unit.close ( );
  cout << "\n";
  cout << "  Created graphics data file '" << data_filename << "'.\n";
//
//  Create the command file.
//
  command_unit.open ( command_filename.c_str() );

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output 'diffusivity_2d_bnt.png'\n";
  command_unit << "set xlabel '<---X--->'\n";
  command_unit << "set ylabel '<---Y--->'\n";
  command_unit << "set zlabel '<---DC(X,Y)--->'\n";
  command_unit << "set title 'BNT Stochastic diffusivity function'\n";
  command_unit << "set contour\n";
  command_unit << "set timestamp\n";
  command_unit << "set cntrparam levels 10\n";
  command_unit << "#set view map\n";
  command_unit << "set view 75, 75\n";
  command_unit << "unset key\n";
  command_unit << "splot '" << data_filename << "'\n";

  command_unit.close ( );

  cout << "  Created graphics command file '" << command_filename << "'\n";

  delete [] dc;
  delete [] omega;
  delete [] xmat;
  delete [] xvec;
  delete [] ymat;
  delete [] yvec;

  return;
}
//****************************************************************************80

void diffusivity_2d_elman_contour ( )

//****************************************************************************80
//
//  Purpose:
//
//    diffusivity_2d_elman_contour displays a contour plot of a 2D stochastic diffusivity function.
//
//  Discussion:
//
//    The diffusivity function is computed by DIFFUSIVITY_2D_ELMAN.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 August 2013
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Howard Elman, Darran Furnaval,
//    Solving the stochastic steady-state diffusion problem using multigrid,
//    IMA Journal on Numerical Analysis,
//    Volume 27, Number 4, 2007, pages 675-688.
//
{
  double a;
  double cl;
  string command_filename = "diffusivity_2d_elman_commands.txt";
  ofstream command_unit;
  string data_filename = "diffusivity_2d_elman_data.txt";
  ofstream data_unit;
  double *dc;
  double dc0;
  int i;
  int j;
  int m_1d = 5;
  int nx = 51;
  int ny = 51;
  double *omega;
  int seed;
  double *xmat;
  double *xvec;
  double *ymat;
  double *yvec;

  cout << "\n";
  cout << "diffusivity_2d_elman_contour\n";
  cout << "  Display contour or surface plots of the stochastic\n";
  cout << "  diffusivity function defined by diffusivity_2d_elman.\n";
//
//  Set the spatial grid.
//
  a = 1.0;
  xvec = r8vec_linspace_new ( nx, -a, a );
  yvec = r8vec_linspace_new ( ny, -a, a );

  xmat = new double[nx*ny];
  ymat = new double[nx*ny];
  r8vec_mesh_2d ( nx, ny, xvec, yvec, xmat, ymat );
//
//  Sample OMEGA.
//
  seed = 123456789;
  omega = r8vec_normal_01_new ( m_1d * m_1d, seed );
//
//  Compute the diffusivity field.
//
  cl = 0.1;
  dc0 = 10.0;
  dc = diffusivity_2d_elman ( a, cl, dc0, m_1d, omega, nx, nx, xmat, ymat );
//
//  Create a data file.
//
  data_unit.open ( data_filename.c_str ( ) );
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      data_unit
        << "  " << setw(14) << xmat[i+j*nx]
        << "  " << setw(14) << ymat[i+j*nx]
        << "  " << setw(14) << dc[i+j*nx] << "\n";
    }
    data_unit << "\n";
  }
  data_unit.close ( );
  cout << "\n";
  cout << "  Created graphics data file '" << data_filename << "'\n";
//
//  Create the command file.
//
  command_unit.open ( command_filename.c_str() );

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output 'diffusivity_2d_elman.png'\n";
  command_unit << "set xlabel '<---X--->'\n";
  command_unit << "set ylabel '<---Y--->'\n";
  command_unit << "set zlabel '<---DC(X,Y)--->'\n";
  command_unit << "set title 'Elman Stochastic diffusivity function'\n";
  command_unit << "set contour\n";
  command_unit << "set timestamp\n";
  command_unit << "set cntrparam levels 10\n";
  command_unit << "#set view map\n";
  command_unit << "set view 75, 75\n";
  command_unit << "unset key\n";
  command_unit << "splot '" << data_filename << "'\n";

  command_unit.close ( );

  cout << "  Created graphics command file '" << command_filename << "'\n";

  delete [] dc;
  delete [] omega;
  delete [] xmat;
  delete [] xvec;
  delete [] ymat;
  delete [] yvec;

  return;
}
//****************************************************************************80

void diffusivity_2d_ntw_contour ( )

//****************************************************************************80
//
//  Purpose:
//
//    diffusivity_2d_ntw_contour displays a contour plot of a 2D stochastic diffusivity function.
//
//  Discussion:
//
//    The diffusivity function is computed by diffusivity_2d_ntw.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 August 2013
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Fabio Nobile, Raul Tempone, Clayton Webster,
//    A Sparse Grid Stochastic Collocation Method for Partial Differential
//    Equations with Random Input Data,
//    SIAM Journal on Numerical Analysis,
//    Volume 46, Number 5, 2008, pages 2309-2345.
//
{
  double cl;
  string command_filename = "diffusivity_2d_ntw_commands.txt";
  ofstream command_unit;
  double d;
  string data_filename = "diffusivity_2d_ntw_data.txt";
  ofstream data_unit;
  double *dc;
  double dc0;
  int i;
  int j;
  int m = 21;
  int nx = 101;
  int ny = 101;
  double *omega;
  int seed;
  double *xmat;
  double *xvec;
  double *ymat;
  double *yvec;

  cout << "\n";
  cout << "diffusivity_2d_ntw_contour\n";
  cout << "  Display contour or surface plots of the stochastic\n";
  cout << "  diffusivity function defined by diffusivity_2d_ntw.\n";
//
//  Set the spatial grid.
//
  d = 1.0;
  xvec = r8vec_linspace_new ( nx, 0.0, d );
  yvec = r8vec_linspace_new ( ny, 0.0, d );

  xmat = new double[nx*ny];
  ymat = new double[nx*ny];
  r8vec_mesh_2d ( nx, ny, xvec, yvec, xmat, ymat );
//
//  Sample OMEGA.
//  We rescale to  [-sqrt(3),sqrt(3)].
//
  seed = 123456789;
  omega = r8vec_uniform_01_new ( m, seed );
  for ( i = 0; i < m; i++ )
  {
    omega[i] = ( 1.0 - omega[i] ) * ( - sqrt ( 3.0 ) ) 
             +         omega[i]   *     sqrt ( 3.0 );
  }
//
//  Evaluate the diffusivity field.
//
  cl = 0.1;
  dc0 = 0.5;
  dc = diffusivity_2d_ntw ( cl, dc0, m, omega, nx * ny, xmat, ymat );
//
//  Create a data file.
//
  data_unit.open ( data_filename.c_str ( ) );
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      data_unit 
        << "  " << setw(14) << xmat[i+j*nx]
        << "  " << setw(14) << ymat[i+j*nx]
        << "  " << setw(14) << dc[i+j*nx] << "\n";
    }
    data_unit << "\n";
  }
  data_unit.close ( );
  cout << "\n";
  cout << "  Created graphics data file '" << data_filename << "'\n";
//
//  Create the command file.
//
  command_unit.open ( command_filename.c_str ( ) );

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output 'diffusivity_2d_ntw.png'\n";
  command_unit << "set xlabel '<---X--->'\n";
  command_unit << "set ylabel '<---Y--->'\n";
  command_unit << "set zlabel '<---DC(X,Y)--->'\n";
  command_unit << "set title 'NTW Stochastic diffusivity function'\n";
  command_unit << "set contour\n";
  command_unit << "set timestamp\n";
  command_unit << "set cntrparam levels 15\n";
  command_unit << "#set view map\n";
  command_unit << "set view 65, 65\n";
  command_unit << "set key\n";
  command_unit << "splot '" << data_filename << "'\n";

  command_unit.close ( );

  cout << "  Created graphics command file '" << command_filename << "'.\n";

  delete [] dc;
  delete [] omega;
  delete [] xmat;
  delete [] xvec;
  delete [] ymat;
  delete [] yvec;

  return;
}
//****************************************************************************80

void diffusivity_2d_pwc_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    diffusivity_2d_pwc_test tests diffusivity_2d_pwc.
//
//  Discussion:
//
//    This function calls diffusivity_2d_pwc_contour, which evaluates
//    diffusivity_2d_pwc() over a given [a,b]x[c,d] grid.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 March 2019
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double c;
  double d;
  int h;
  int w;

  h = 5;
  w = 4;
  a = -1.0;
  b = +1.0;
  c = -1.0;
  d = +1.0;
  diffusivity_2d_pwc_contour ( h, w, a, b, c, d );

  return;
}
//****************************************************************************80

void diffusivity_2d_pwc_contour ( int h, int w, double a, double b, double c, 
  double d )

//****************************************************************************80
//
//  Purpose:
//
//    diffusivity_2d_pwc_contour displays a contour plot of a 2D stochastic diffusivity function.
//
//  Discussion:
//
//    The diffusivity function is computed by diffusivity_2d_pwc.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 March 2019
//
//  Author:
//
//    John Burkardt
//
{
  string command_filename = "diffusivity_2d_pwc_commands.txt";
  ofstream command_unit;
  string data_filename = "diffusivity_2d_pwc_data.txt";
  ofstream data_unit;
  int i;
  int j;
  int n;
  int nx;
  int ny;
  double *omega;
  double *rho;
  int seed;
  double *xmat;
  double *xvec;
  double *ymat;
  double *yvec;

  cout << "\n";
  cout << "diffusivity_2d_pwc_contour\n";
  cout << "  Display contour or surface plots of the stochastic\n";
  cout << "  diffusivity function defined by diffusivity_2d_pwc.\n";
  cout << "\n";
  cout << "  Underlying grid is " << w << " elements wide (X) and " << h << " high (Y)\n";

  nx = 101;
  ny = 101;
//
//  Set the spatial grid.
//
  xvec = r8vec_linspace_new ( nx, a, b );
  yvec = r8vec_linspace_new ( ny, c, d );

  xmat = new double[nx*ny];
  ymat = new double[nx*ny];
  r8vec_mesh_2d ( nx, ny, xvec, yvec, xmat, ymat );
//
//  Sample OMEGA.
//
  seed = 123456789;
  omega = r8vec_uniform_ab_new ( h * w, 0.5, 1.5, seed );

  n = nx * ny;
//
//  Compute the diffusivity field.
//
  rho = diffusivity_2d_pwc ( h, w, a, b, c, d, omega, n, xmat, ymat );
//
//  Create a data file.
//
  data_unit.open ( data_filename.c_str ( ) );
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      data_unit
        << "  " << setw(14) << xmat[i+j*nx]
        << "  " << setw(14) << ymat[i+j*nx]
        << "  " << setw(14) << rho[i+j*nx] << "\n";
    }
    data_unit << "\n";
  }
  data_unit.close ( );
  cout << "\n";
  cout << "  Created graphics data file '" << data_filename << "'\n";
//
//  Create the command file.
//
  command_unit.open ( command_filename.c_str() );

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output 'diffusivity_2d_pwc.png'\n";
  command_unit << "set xlabel '<---X--->'\n";
  command_unit << "set ylabel '<---Y--->'\n";
  command_unit << "set zlabel '<---Rho(X,Y)--->'\n";
  command_unit << "set title 'PWC Stochastic diffusivity function'\n";
  command_unit << "set contour\n";
  command_unit << "set timestamp\n";
  command_unit << "set cntrparam levels 10\n";
  command_unit << "#set view map\n";
  command_unit << "set view 75, 75\n";
  command_unit << "unset key\n";
  command_unit << "splot '" << data_filename << "'\n";

  command_unit.close ( );

  cout << "  Created graphics command file '" << command_filename << "'\n";

  delete [] omega;
  delete [] rho;
  delete [] xmat;
  delete [] xvec;
  delete [] ymat;
  delete [] yvec;

  return;
}
