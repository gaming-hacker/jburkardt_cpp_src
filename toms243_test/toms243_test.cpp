# include <cmath>
# include <complex>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "toms243.hpp"

int main ( );
void c8_log_values ( int &n_data, complex <double> &z, complex <double> &fz );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    TOMS243_TEST tests TOMS243.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 January 2019
//
//  Author:
//
//    John Burkardt
//
{
  complex <double> fx1;
  complex <double> fx2;
  int n_data;
  streamsize ss;
  complex <double> x;
//
//  Save the current precision.
//
  ss = cout.precision ( );

  timestamp ( );
  cout << "\n";
  cout << "TOMS243_TEST:\n";
  cout << "  C++ version\n";
  cout << "  TOMS243 computes the natural logarithm of a complex value.\n";
  cout << "\n";
  cout << "               X                               FX exact\n";
  cout << "                                               FX computed\n";
  cout << "\n";

  n_data = 0;

  while ( true )
  {
    c8_log_values ( n_data, x, fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = toms243 ( x );

    cout << "  ( " 
         << setw(8)  << setprecision ( 4 )  << real ( x ) << "," 
         << setw(8)  << setprecision ( 4 )  << imag ( x ) << ")  ( " 
         << setw(18) << setprecision ( 12 ) << real ( fx1 ) << "," 
         << setw(18) << setprecision ( 12 ) << imag ( fx1 ) << ")\n";
    cout << "                        ( " 
         << setw(18) << setprecision ( 12 ) << real ( fx2 ) << "," 
         << setw(18) << setprecision ( 12 ) << imag ( fx2 ) << ")\n";
  }
//
//  Restore the default precision.
//
  cout.precision ( ss );

  cout << "\n";
  cout << "TOMS243_TEST:\n";
  cout << "  Normal end of execution:\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void c8_log_values ( int &n_data, complex <double> &z, complex <double> &fz )

//****************************************************************************80
//
//  Purpose:
//
//    C8_LOG_VALUES: the logarithm of a complex value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 January 2019
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    David Collens,
//    Algorithm 243: Logarithm of a Complex Number,
//    Communications of the Association for Computing Machinery,
//    Volume 7, Number 11, November 1964, page 660.
//
//  Parameters:
//
//    Input/output, int &N_DATA.  The user sets N_DATA to 0 before the
//    first call.  On each call, the routine increments N_DATA by 1, and
//    returns the corresponding data; when there is no more data, the
//    output value of N_DATA will be 0 again.
//
//    Output, complex <double> &Z, the argument of the function.
//
//    Output, complex <double> &FZ, the value of the function.
//
{
# define N_MAX 12

  static complex <double> fz_vec[N_MAX] = {
    complex <double> ( 1.039720770839918, - 2.356194490192345 ), 
    complex <double> ( 0.804718956217050, + 2.677945044588987 ),
    complex <double> ( 0.346573590279973, - 2.356194490192345 ), 
    complex <double> ( 0.000000000000000, + 3.141592653589793 ), 
    complex <double> ( 0.693147180559945, - 1.570796326794897 ), 
    complex <double> ( 0.000000000000000, - 1.570796326794897 ), 
    complex <double> ( 0.000000000000000, + 1.570796326794897 ), 
    complex <double> ( 0.693147180559945, + 1.570796326794897 ), 
    complex <double> ( 0.346573590279973, - 0.785398163397448 ), 
    complex <double> ( 0.000000000000000, + 0.000000000000000 ), 
    complex <double> ( 1.039720770839918, - 0.785398163397448 ), 
    complex <double> ( 0.804718956217050, + 0.463647609000806 ) };
  static complex <double> z_vec[N_MAX] = {
    complex <double> ( -2.0, - 2.0 ), 
    complex <double> ( -2.0, + 1.0 ), 
    complex <double> ( -1.0, - 1.0 ), 
    complex <double> ( -1.0, + 0.0 ), 
    complex <double> (  0.0, - 2.0 ), 
    complex <double> (  0.0, - 1.0 ), 
    complex <double> (  0.0, + 1.0 ), 
    complex <double> (  0.0, + 2.0 ), 
    complex <double> (  1.0, - 1.0 ), 
    complex <double> (  1.0, + 0.0 ), 
    complex <double> (  2.0, - 2.0 ), 
    complex <double> (  2.0, + 1.0 ) };

  if ( n_data < 0 )
  {
    n_data = 0;
  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )
  {
    n_data = 0;
    z = complex <double> ( 0.0, 0.0 );
    fz = complex <double> ( 0.0, 0.0 );
  }
  else
  {
    z  = z_vec[n_data-1];
    fz = fz_vec[n_data-1];
  }

  return;
# undef N_MAX
}

