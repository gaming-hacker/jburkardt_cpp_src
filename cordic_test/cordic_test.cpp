# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "cordic.hpp"

int main ( );
void arccos_cordic_test ( );
void arcsin_cordic_test ( );
void arctan_cordic_test ( );
void cbrt_cordic_test ( );
void cossin_cordic_test1 ( );
void cossin_cordic_test2 ( );
void exp_cordic_test ( );
void ln_cordic_test ( );
void multiply_cordic_test ( );
void sqrt_cordic_test ( );
void tan_cordic_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for CORDIC_TEST.
//
//  Discussion:
//
//    CORDIC_TEST tests the CORDIC library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "CORDIC_TEST:\n";
  cout << "  C++ version,\n";
  cout << "  Test the CORDIC library.\n";

  arccos_cordic_test ( );
  arcsin_cordic_test ( );
  arctan_cordic_test ( );
  cbrt_cordic_test ( );
  cossin_cordic_test1 ( );
  cossin_cordic_test2 ( );
  exp_cordic_test ( );
  ln_cordic_test ( );
  multiply_cordic_test ( );
  sqrt_cordic_test ( );
  tan_cordic_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "CORDIC_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void arccos_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ARCCOS_CORDIC_TEST demonstrates the use of ARCCOS_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a1;
  double a2;
  double d;
  int n;
  int n_data;
  double t;

  cout << "\n";
  cout << "ARCCOS_CORDIC_TEST:\n";
  cout << "  ARCCOS_CORDIC computes the arccosine of T\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "      T    N        ArcCos(T)  ArcCos(T)      Difference\n";
  cout <<
    "                   Tabulated   CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    arccos_values ( n_data, t, a1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      a2 = arccos_cordic ( t, n );

      d = a1 - a2;

      cout
           << setw(12) << setprecision ( 4 ) << t  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << a1  << "  "
           << setw(16) << setprecision ( 8 ) << a2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void arcsin_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ARCSIN_CORDIC_TEST demonstrates the use of ARCSIN_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a1;
  double a2;
  double d;
  int n;
  int n_data;
  double t;

  cout << "\n";
  cout << "ARCSIN_CORDIC_TEST:\n";
  cout << "  ARCSIN_CORDIC computes the arcsine of T\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "      T    N        ArcSin(T)  ArcSin(T)      Difference\n";
  cout <<
    "                   Tabulated   CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    arcsin_values ( n_data, t, a1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      a2 = arcsin_cordic ( t, n );

      d = a1 - a2;

      cout
           << setw(12) << setprecision ( 4 ) << t  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << a1  << "  "
           << setw(16) << setprecision ( 8 ) << a2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void arctan_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ARCTAN_CORDIC_TEST demonstrates the use of ARCTAN_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 January 2012
//
//  Author:
//
//    John Burkardt
//
{
  double a1;
  double a2;
  double d;
  int n;
  int n_data;
  double r;
  double s;
  int seed;
  double x;
  double y;
  double z;

  seed = 123456789;

  cout << "\n";
  cout << "ARCTAN_CORDIC_TEST:\n";
  cout << "  ARCTAN_CORDIC computes the arctangent of Y/X\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "      X      Y    N       ArcTan(Y/X) ArcTan(Y/X)      Difference\n";
  cout <<
    "                           Tabulated   CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    arctan_values ( n_data, z, a1 );

    if ( n_data == 0 )
    {
      break;
    }

    r = r8_uniform_01 ( seed );

    x = r;
    y = r * z;

    s = r8_uniform_01 ( seed );

    if ( s < 0.5 )
    {
      x = -x;
      y = -y;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      a2 = arctan_cordic ( x, y, n );

      d = a1 - a2;

      cout
           << setw(12) << setprecision ( 4 ) << x  << "  "
           << setw(12) << setprecision ( 4 ) << y  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << a1  << "  "
           << setw(16) << setprecision ( 8 ) << a2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void cbrt_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CBRT_CORDIC_TEST demonstrates the use of CBRT_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double d;
  double fx1;
  double fx2;
  int n;
  int n_data;
  double x;

  cout << "\n";
  cout << "CBRT_CORDIC_TEST:\n";
  cout << "  CBRT_CORDIC computes the cube root\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "    X      N          Cbrt(X)     Cbrt(X)        Difference\n";
  cout <<
    "                     Tabulated   CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    cbrt_values ( n_data, x, fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      fx2 = cbrt_cordic ( x, n );

      d = fx1 - fx2;

      cout
           << setw(12) << setprecision ( 4 ) << x  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << fx1  << "  "
           << setw(16) << setprecision ( 8 ) << fx2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void cossin_cordic_test1 ( )

//****************************************************************************80
//
//  Purpose:
//
//    COSSIN_CORDIC_TEST1 demonstrates the use of COSSIN_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double c1;
  double c2;
  double d;
  int n;
  int n_data;
  double s2;

  cout << "\n";
  cout << "COSSIN_CORDIC_TEST1:\n";
  cout << "  COSSIN_CORDIC computes the cosine and sine\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "          A        N      Cos(A)           Cos(A)           Difference\n";
  cout << "                          Tabulated        CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    cos_values ( n_data, a, c1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      cossin_cordic ( a, n, c2, s2 );

      d = c1 - c2;

      cout
           << setw(12) << setprecision ( 4 ) << a  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << c1  << "  "
           << setw(16) << setprecision ( 8 ) << c2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void cossin_cordic_test2 ( )

//****************************************************************************80
//
//  Purpose:
//
//    COSSIN_CORDIC_TEST2 demonstrates the use of COSSIN_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double c2;
  double d;
  int n;
  int n_data;
  double s1;
  double s2;

  cout << "\n";
  cout << "COSSIN_CORDIC_TEST2:\n";
  cout << "  COSSIN_CORDIC computes the cosine and sine\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "          A        N      Sin(A)           Sin(A)           Difference\n";
  cout << "                          Tabulated        CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    sin_values ( n_data, a, s1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      cossin_cordic ( a, n, c2, s2 );

      d = s1 - s2;

      cout
           << setw(12) << setprecision ( 4 ) << a  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << s1  << "  "
           << setw(16) << setprecision ( 8 ) << s2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void exp_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EXP_CORDIC_TEST demonstrates the use of EXP_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double d;
  double fx1;
  double fx2;
  int n;
  int n_data;
  double x;

  cout << "\n";
  cout << "EXP_CORDIC_TEST:\n";
  cout << "  EXP_CORDIC computes the exponential function\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "    X      N           Exp(X)      Exp(X)        Difference\n";
  cout <<
    "                     Tabulated   CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    exp_values ( n_data, x, fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      fx2 = exp_cordic ( x, n );

      d = fx1 - fx2;

      cout
           << setw(12) << setprecision ( 4 ) << x  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << fx1  << "  "
           << setw(16) << setprecision ( 8 ) << fx2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void ln_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    LN_CORDIC_TEST demonstrates the use of LN_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double d;
  double fx1;
  double fx2;
  int n;
  int n_data;
  double x;

  cout << "\n";
  cout << "LN_CORDIC_TEST:\n";
  cout << "  LN_CORDIC computes the natural logarithm\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "    X      N            Ln(X)       Ln(X)        Difference\n";
  cout <<
    "                     Tabulated   CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    ln_values ( n_data, x, fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      fx2 = ln_cordic ( x, n );

      d = fx1 - fx2;

      cout
           << setw(12) << setprecision ( 4 ) << x  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << fx1  << "  "
           << setw(16) << setprecision ( 8 ) << fx2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void multiply_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    MULTIPLY_CORDIC_TEST tests MULTIPLY_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 June 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int seed;
  double r;
  double x;
  double y;
  double z1;
  double z2;

  cout << "\n";
  cout << "MULTIPLY_CORDIC_TEST:\n";
  cout << "  MULTIPLY_CORDIC computes Z = X * Y\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout << "        X             Y               Z                 Z\n";
  cout << "                                      (X*Y)             (CORDIC)\n";
  cout << "\n";

  seed = 123456789;

  for ( i = 1; i <= 20; i++ )
  {
    r = r8_uniform_01 ( seed );
    x = - 100.0 + 200.0 * r;
    r = r8_uniform_01 ( seed );
    y = - 100.0 + 200.0 * r;
    z1 = x * y;
    z2 = multiply_cordic ( x, y );
    cout << "  " << setw(12) << setprecision(8) << x
         << "  " << setw(12) << setprecision(8) << x
         << "  " << setw(16) << setprecision(8) << z1
         << "  " << setw(16) << setprecision(8) << z2 << "\n";
  }

  return;
}
//****************************************************************************80

void sqrt_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    SQRT_CORDIC_TEST demonstrates the use of SQRT_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    21 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double d;
  double fx1;
  double fx2;
  int n;
  int n_data;
  double x;

  cout << "\n";
  cout << "SQRT_CORDIC_TEST:\n";
  cout << "  SQRT_CORDIC computes the square root\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "    X      N          Sqrt(X)     Sqrt(X)        Difference\n";
  cout <<
    "                     Tabulated   CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    sqrt_values ( n_data, x, fx1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      fx2 = sqrt_cordic ( x, n );

      d = fx1 - fx2;

      cout
           << setw(12) << setprecision ( 4 ) << x  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << fx1  << "  "
           << setw(16) << setprecision ( 8 ) << fx2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}
//****************************************************************************80

void tan_cordic_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    TAN_CORDIC_TEST demonstrates the use of TAN_CORDIC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double d;
  int n;
  int n_data;
  double t1;
  double t2;
  double theta;

  cout << "\n";
  cout << "TAN_CORDIC_TEST:\n";
  cout << "  TAN_CORDIC computes the tangent of THETA\n";
  cout << "  using the CORDIC algorithm.\n";
  cout << "\n";
  cout <<
    "  THETA    N         Tan(THETA)  Tan(THETA)      Difference\n";
  cout <<
    "                     Tabulated   CORDIC\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    tan_values ( n_data, theta, t1 );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "\n";
    for ( n = 0; n <= 25; n = n + 5 )
    {
      t2 = tan_cordic ( theta, n );

      d = t1 - t2;

      cout
           << setw(12) << setprecision ( 4 ) << theta  << "  "
           << setw(4)                        << n  << "  "                                 << "  "
           << setw(16) << setprecision ( 8 ) << t1  << "  "
           << setw(16) << setprecision ( 8 ) << t2  << "  "
           << setw(12) << setprecision ( 4 ) << d << "\n";
    }
  }
  return;
}

