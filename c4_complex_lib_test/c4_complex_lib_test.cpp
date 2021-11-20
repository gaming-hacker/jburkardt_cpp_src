# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

using namespace std;

# include "c4_complex_lib.hpp"

int main ( );
void test01 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for C4_COMPLEX_LIB_TEST.
//
//  Discussion:
//
//    C4_COMPLEX_LIB_TEST tests the C4_COMPLEX_LIB library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 September 2013
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "C4_COMPLEX_LIB_TEST\n";
  cout << "  C++ version.\n";
  cout << "  Test the C4_COMPLEX_LIB library.\n";

  test01 ( );
  test02 ( );
  test03 ( );
  test04 ( );
  test05 ( );
  test06 ( );
  test07 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "C4_COMPLEX_LIB_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test01 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tests c4_complex assignment.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
{
  c4_complex c1;
  c4_complex c2;
  float d1 = 1.0;
  float d2 = 2.0;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Test assignment of a value to c4_complex.\n";
  cout << "\n";
  cout << "  float D1 = " << d1 << "\n";
  cout << "  float D2 = " << d2 << "\n";
  cout << "\n";
  c1 = c4_complex ( d1, d2 );
  cout << "  C1 = c4_complex ( d1, d2 ) = " << c1 << "\n";
  c1 = c4_complex ( d1 );
  cout << "  C1 = c4_complex ( d1 ) = " << c1 << "\n";
  c2 = c1;
  cout << "  C2 = C1 = " << c2 << "\n";

  return;
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 tests c4_complex addition.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
{
  c4_complex c1 = c4_complex ( 100.0, 10.0 );
  c4_complex c2;
  c4_complex c3;
  float d1 = 1.0;

  c1 = c4_complex ( 100.0, 10.0 );
  c2 = c4_complex ( 99.0, 9.0 );

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Test c4_complex addition.\n";
  cout << "\n";
  cout << "  float D1 = " << d1 << "\n";
  cout << "  c4_complex C1 = " << c1 << "\n";
  cout << "  c4_complex C2 = " << c2 << "\n";
  cout << "\n";
  c3 = c1 + c2;
  cout << "  C3 = C1 + C2 = " << c3 << "\n";
  c3 = c1 + d1;
  cout << "  C3 = C1 + D1 = " << c3 << "\n";
  c3 = d1 + c1;
  cout << "  C3 = C1 + D1 = " << c3 << "\n";
  c3 = c1 + c1;
  cout << "  C3 = C1 + C1 = " << c3 << "\n";

  return;
}
//****************************************************************************80

void test03 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST03 tests c4_complex subtraction.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
{
  c4_complex c1 = c4_complex ( 100.0, 10.0 );
  c4_complex c2;
  c4_complex c3;
  float d1 = 1.0;

  c1 = c4_complex ( 100.0, 10.0 );
  c2 = c4_complex ( 99.0, 9.0 );

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Test c4_complex addition.\n";
  cout << "\n";
  cout << "  float D1 = " << d1 << "\n";
  cout << "  c4_complex C1 = " << c1 << "\n";
  cout << "  c4_complex C2 = " << c2 << "\n";
  cout << "\n";
  c3 = c1 - c2;
  cout << "  C3 = C1 - C2 = " << c3 << "\n";
  c3 = c1 - d1;
  cout << "  C3 = C1 - D1 = " << c3 << "\n";
  c3 = d1 - c1;
  cout << "  C3 = C1 - D1 = " << c3 << "\n";
  c3 = c1 - c1;
  cout << "  C3 = C1 - C1 = " << c3 << "\n";

  return;
}
//****************************************************************************80

void test04 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST04 tests c4_complex conjugation.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
{
  c4_complex c1 = c4_complex ( 100.0, 10.0 );
  c4_complex c2;

  c1 = c4_complex ( 100.0, 10.0 );

  cout << "\n";
  cout << "TEST04\n";
  cout << "  Test c4_complex conjugation.\n";
  cout << "\n";
  cout << "  c4_complex C1 = " << c1 << "\n";
  cout << "\n";
  c2 = ~c1;
  cout << "  C2 = ~C1 = " << c2 << "\n";

  return;
}
//****************************************************************************80

void test05 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST05 tests c4_complex multiplication.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
{
  c4_complex c1 = c4_complex ( 1.0, 2.0 );
  c4_complex c2 = c4_complex ( 3.0, 4.0 );
  c4_complex c3;
  float d1 = 5.0;
  float d2 = 6.0;

  cout << "\n";
  cout << "TEST05\n";
  cout << "  Test c4_complex multiplication.\n";
  cout << "\n";
  cout << "  couble D1 = " << d1 << "\n";
  cout << "  couble D2 = " << d2 << "\n";
  cout << "  c4_complex C1 = " << c1 << "\n";
  cout << "  c4_complex C2 = " << c2 << "\n";

  cout << "\n";
  c3 = d1 * c1;
  cout << "  C3 = D1 * C1 = " << c3 << "\n";
  c3 = c2 * d2;
  cout << "  C3 = C2 * D2 = " << c3 << "\n";
  c3 = c1 * c2;
  cout << "  C3 = C1 * C2 = " << c3 << "\n";

  return;
}
//****************************************************************************80

void test06 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST06 tests c4_complex division.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2005
//
{
  c4_complex c1 = c4_complex ( 1.0, 2.0 );
  c4_complex c2 = c4_complex ( 3.0, 4.0 );
  c4_complex c3;
  float d1 = 5.0;
  float d2 = 6.0;

  cout << "\n";
  cout << "TEST06\n";
  cout << "  Test c4_complex division.\n";
  cout << "\n";
  cout << "  float D1 = " << d1 << "\n";
  cout << "  float D2 = " << d2 << "\n";
  cout << "  c4_complex C1 = " << c1 << "\n";
  cout << "  c4_complex C2 = " << c2 << "\n";

  cout << "\n";
  c3 = d1 / c1;
  cout << "  C3 = D1 / C1 = " << c3 << "\n";
  c3 = c2 / d2;
  cout << "  C3 = C2 / D2 = " << c3 << "\n";
  c3 = c1 / c2;
  cout << "  C3 = C1 / C2 = " << c3 << "\n";

  return;
}
//****************************************************************************80

void test07 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST07 tests real and imaginary part retrieval.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 October 2005
//
{
  c4_complex c1 = c4_complex ( 1.0, 2.0 );
  float d1;

  cout << "\n";
  cout << "TEST07\n";
  cout << "  Test c4_complex real and imaginary parts.\n";
  cout << "\n";
  cout << "  c4_complex C1 = " << c1 << "\n";

  cout << "\n";
  d1 = c1.real();
  cout << "  D1 = C1.real ( ) = " << d1 << "\n";
  d1 = c1.imaginary();
  cout << "  D1 = C1.imaginary ( ) = " << d1 << "\n";

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
//    24 September 2003
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
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
