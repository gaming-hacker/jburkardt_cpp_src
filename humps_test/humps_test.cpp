# include <cmath>
# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <iostream>

using namespace std;

# include "humps.hpp"

int main ( );
void humps_antideriv_test ( );
void humps_deriv_test ( );
void humps_deriv2_test ( );
void humps_fun_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for humps_test.
//
//  Discussion:
//
//    humps_test tests humps.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "humps_test\n";
  cout << "  C++ version\n";
  cout << "  Test humps.\n";

  humps_antideriv_test ( );
  humps_fun_test ( );
  humps_deriv_test ( );
  humps_deriv2_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "humps_test\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void humps_antideriv_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    humps_antideriv_test tests humps_antideriv.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  int i;
  int n;
  double *x;
  double *y;

  cout << "\n";
  cout << "humps_antideriv_test\n";
  cout << "  Test humps_antideriv.\n";

  a = 0.0;
  b = 2.0;
  n = 101;
  x = new double[n];
  y = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( n - i ) * a + i * b ) / ( n - 1 );
    y[i] = humps_antideriv ( x[i] );
  }
  plot_xy ( n, x, y, "humps_antideriv" );

  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void humps_fun_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    humps_fun_test tests humps_fun.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  int i;
  int n;
  double *x;
  double *y;

  cout << "\n";
  cout << "humps_fun_test\n";
  cout << "  Test humps_fun.\n";

  a = 0.0;
  b = 2.0;
  n = 101;
  x = new double[n];
  y = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( n - i ) * a + i * b ) / ( n - 1 );
    y[i] = humps_fun ( x[i] );
  }
  plot_xy ( n, x, y, "humps_fun" );

  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void humps_deriv_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    humps_deriv_test tests humps_deriv.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  int i;
  int n;
  double *x;
  double *y;

  cout << "\n";
  cout << "humps_deriv_test\n";
  cout << "  Test humps_deriv.\n";

  a = 0.0;
  b = 2.0;
  n = 101;
  x = new double[n];
  y = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( n - i ) * a + i * b ) / ( n - 1 );
    y[i] = humps_deriv ( x[i] );
  }
  plot_xy ( n, x, y, "humps_deriv" );

  delete [] x;
  delete [] y;

  return;
}
//****************************************************************************80

void humps_deriv2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    humps_deriv2_test tests humps_deriv2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 August 2019
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  int i;
  int n;
  double *x;
  double *y;

  cout << "\n";
  cout << "humps_deriv2_test\n";
  cout << "  Test humps_deriv2.\n";

  a = 0.0;
  b = 2.0;
  n = 101;
  x = new double[n];
  y = new double[n];
  for ( i = 0; i < n; i++ )
  {
    x[i] = ( ( n - i ) * a + i * b ) / ( n - 1 );
    y[i] = humps_deriv2 ( x[i] );
  }
  plot_xy ( n, x, y, "humps_deriv2" );

  delete [] x;
  delete [] y;

  return;
}
