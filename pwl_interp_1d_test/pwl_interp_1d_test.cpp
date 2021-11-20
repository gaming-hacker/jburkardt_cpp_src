# include <cmath>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>
# include <sstream>

using namespace std;

# include "pwl_interp_1d.hpp"
# include "test_interp.hpp"
# include "r8lib.hpp"

int main ( );
void pwl_basis_1d_test ( );
void pwl_value_1d_test ( );
void pwl_interp_1d_test01 ( int prob );
string i4_to_string ( int i4 );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for PWL_INTERP_1D_TEST.
//
//  Discusion:
//
//    PWL_INTERP_1D_TEST tests the PWL_INTERP_1D library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 July 2015
//
//  Author:
//
//    John Burkardt
//
{
  int prob;
  int prob_num;

  timestamp ( );
  cout << "\n";
  cout << "PWL_INTERP_1D_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the PWL_INTERP_1D library.\n";
  cout << "  The R8LIB library is needed.\n";
  cout << "  The test needs the TEST_INTERP library.\n";

  pwl_basis_1d_test ( );

  pwl_value_1d_test ( );

  prob_num = p00_prob_num ( );
  for ( prob = 1; prob <= prob_num; prob++ )
  {
    pwl_interp_1d_test01 ( prob );
  }
//
//  Terminate.
//
  cout << "\n";
  cout << "PWL_INTERP_1D_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void pwl_basis_1d_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    PWL_BASIS_1D_TEST tests PWL_BASIS_1D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 July 2015
//
//  Author:
//
//    John Burkardt
//
{
  double *lb;
  int nd = 4;
  int ni = 21;
  double x_max;
  double x_min;
  double xd[4] = { 0.0, 2.0, 5.0, 10.0 };
  double *xi;

  cout << "\n";
  cout << "PWL_BASIS_1D_TEST:\n";
  cout << "  PWL_BASIS_1D evaluates the piecewise linear 1D basis\n";
  cout << "  functions.\n";

  x_min = 0.0;
  x_max = 10.0;
  xi = r8vec_linspace_new ( ni, x_min, x_max );

  lb = pwl_basis_1d ( nd, xd, ni, xi );

  r8mat_print ( ni, nd, lb, "  The piecewise linear basis functions:" );

  delete [] lb;
  delete [] xi;

  return;
}
//****************************************************************************80

void pwl_value_1d_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    PWL_VALUE_1D_TEST tests PWL_VALUE_1D.
//
//  Discussion:
//
//    f(x) = x^3 - 12 x^2 + 39 x - 28 = ( x - 1 ) * ( x - 4 ) * ( x - 7 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified: 
//
//    01 July 2015
//
//  Author:
//
//    John Burkardt
//
{
  int nd = 4;
  int ni = 21;
  double x_max;
  double x_min;
  double xd[4] = { 0.0, 2.0, 5.0, 10.0 };
  double yd[4] = { -28.0, +10.0, -8.0, +162.0 };
  double *xi;
  double *yi;
 
  cout << "\n";
  cout << "PWL_VALUE_1D_TEST:\n";
  cout << "  PWL_VALUE_1D evaluates a piecewise linear 1D interpolant.\n";

  x_min = 0.0;
  x_max = 10.0;
  xi = r8vec_linspace_new ( ni, x_min, x_max );

  yi = pwl_value_1d ( nd, xd, yd, ni, xi );

  r8vec2_print ( ni, xi, yi, "  Table of interpolant values:" );

  delete [] xi;
  delete [] yi;

  return;
}
//****************************************************************************80

void pwl_interp_1d_test01 ( int prob )

//****************************************************************************80
//
//  Purpose:
//
//    PWL_INTERP_1D_TEST01 tests PWL_INTERP_1D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 May 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int PROB, the problem index.
//
{
  string command_filename;
  ofstream command_unit;
  string data_filename;
  ofstream data_unit;
  int i;
  double interp_error;
  string interp_filename;
  ofstream interp_unit;
  int j;
  int nd;
  int ni;
  string output_filename;
  string title;
  double *xd;
  double *xi;
  double xmax;
  double xmin;
  double *xy;
  double *yd;
  double *yi;

  cout << "\n";
  cout << "PWL_INTERP_1D_TEST01:\n";
  cout << "  PWL_INTERP_1D evaluates the piecewise linear interpolant.\n";
  cout << "  Interpolate data from TEST_INTERP problem #" << prob << "\n";

  nd = p00_data_num ( prob );
  cout << "  Number of data points = " << nd << "\n";

  xy = p00_data ( prob, 2, nd );
  
  r8mat_transpose_print ( 2, nd, xy, "  Data array:" );

  xd = new double[nd];
  yd = new double[nd];

  for ( i = 0; i < nd; i++ )
  {
    xd[i] = xy[0+2*i];
    yd[i] = xy[1+2*i];
  }
//
//  #1:  Does interpolant match function at interpolation points?
//
  ni = nd;

  xi = new double[ni];
  for ( i = 0; i < ni; i++ )
  {
    xi[i] = xd[i];
  }

  yi = pwl_value_1d ( nd, xd, yd, ni, xi );

  interp_error = r8vec_diff_norm ( ni, yi, yd ) / ( double ) ( ni );

  cout << "\n";
  cout << "  L2 interpolation error averaged per interpolant node = " << interp_error << "\n";
//
//  Create data file.
//
  data_filename = "data" + i4_to_string ( prob ) + ".txt";
  data_unit.open ( data_filename.c_str ( ) );
  for ( j = 0; j < nd; j++ )
  {
    data_unit << "  " << xd[j]
              << "  " << yd[j] << "\n";
  }
  data_unit.close ( );
  cout << "\n";
  cout << "  Created graphics data file \"" << data_filename << "\".\n";
//
//  Create interp file.
//
  delete [] xi;
  delete [] yi;

  ni = 501;
  xmin = r8vec_min ( nd, xd );
  xmax = r8vec_max ( nd, xd );
  xi = r8vec_linspace_new ( ni, xmin, xmax );
  yi = pwl_value_1d ( nd, xd, yd, ni, xi );

  interp_filename = "interp" + i4_to_string ( prob ) + ".txt";
  interp_unit.open ( interp_filename.c_str ( ) );
  for ( j = 0; j < ni; j++ )
  {
    interp_unit << "  " << xi[j]
                << "  " << yi[j] << "\n";
  }
  interp_unit.close ( );
  cout << "  Created graphics interp file \"" << interp_filename << "\".\n";
//
//  Plot the data and the interpolant.
//
  command_filename = "commands" + i4_to_string ( prob ) + ".txt";
  command_unit.open ( command_filename.c_str ( ) );

  output_filename = "plot" + i4_to_string ( prob ) + ".png";

  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output '" << output_filename << "'\n";
  command_unit << "set xlabel '<---X--->'\n";
  command_unit << "set ylabel '<---Y--->'\n";
  command_unit << "set title 'Data versus Nearest Neighbor Interpolant'\n";
  command_unit << "set grid\n";
  command_unit << "set style data lines\n";
  command_unit << "plot '" << data_filename 
               << "' using 1:2 with points pt 7 ps 2 lc rgb 'blue',\\\n";
  command_unit << "     '" << interp_filename 
               << "' using 1:2 lw 3 linecolor rgb 'red'\n";

  command_unit.close ( );
  cout << "  Created graphics command file \"" << command_filename << "\".\n";
//
//  Free memory.
//
  delete [] xd;
  delete [] xi;
  delete [] xy;
  delete [] yd;
  delete [] yi;

  return;
}
//****************************************************************************80

string i4_to_string ( int i4 )

//****************************************************************************80
//
//  Purpose:
//
//    I4_TO_STRING converts an I4 to a C++ string.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 January 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I4, an integer.
//
//    Input, string FORMAT, the format string.
//
//    Output, string I4_TO_STRING, the string.
//
{
  ostringstream fred;
  string value;

  fred << i4;

  value = fred.str ( );

  return value;
}
