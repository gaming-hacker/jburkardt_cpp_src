# include <cmath>
# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <iostream>

using namespace std;

# include "upc.hpp"

int main ( );
void ch_is_digit_test ( );
void ch_to_digit_test ( );
void s_to_digits_test ( );
void upc_check_digit_calculate_test ( );
void upc_is_valid_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for UPC_TEST.
//
//  Discussion:
//
//    UPC_TEST tests the UPC library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 September 2015
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "UPC_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the UPC library.\n";

  ch_is_digit_test ( );
  ch_to_digit_test ( );
  s_to_digits_test ( );
  upc_check_digit_calculate_test ( );
  upc_is_valid_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "UPC_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void ch_is_digit_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_IS_DIGIT_TEST tests CH_IS_DIGIT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 September 2015
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  char c_test[13] = { 
    '0', '1', '2', '3', '4', 
    '5', '6', '7', '8', '9', 
    'X', '?', ' ' };
  int i;
  bool value;

  cout << "\n";
  cout << "CH_IS_DIGIT_TEST\n";
  cout << "  CH_IS_DIGIT is TRUE if a character represents a digit.\n";
  cout << "\n";
  cout << "       C  CH_IS_DIGIT(C)\n";
  cout << "\n";

  for ( i = 0; i < 13; i++ )
  {
    c = c_test[i];
    value = ch_is_digit ( c );
    cout << "  " << setw(6) << i
         << " '" << setw(1) << c
         << "' " << setw(6) << value << "\n";
  }

  return;
}
//****************************************************************************80

void ch_to_digit_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_TO_DIGIT_TEST tests CH_TO_DIGIT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2015
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  char c_test[13] = { 
    '0', '1', '2', '3', '4', 
    '5', '6', '7', '8', '9', 
    'X', '?', ' ' };
  int i;
  int i2;

  cout << "\n";
  cout << "CH_TO_DIGIT_TEST\n";
  cout << "  CH_TO_DIGIT: character -> decimal digit\n";
  cout << "\n";

  for ( i = 0; i < 13; i++ )
  {
    c = c_test[i];
    i2 = ch_to_digit ( c );
    cout << "  " << setw(6) << i
         << "  " << setw(1) << c
         << "  " << setw(6) << i2 << "\n";
  }

  return;
}
//****************************************************************************80

void s_to_digits_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_DIGITS_TEST tests S_TO_DIGITS.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 September 2015
//
//  Author:
//
//   John Burkardt
//
{
  int *dvec;
  int n;
  string s;

  cout << "\n";
  cout << "S_TO_DIGITS_TEST\n";
  cout << "  S_TO_DIGITS: string -> digit vector\n";

  s = "34E94-70.6";
  cout << "\n";
  cout << "  Test string: '" << s << "'\n";
  n = 5;
  dvec = s_to_digits ( s, n );
  i4vec_print ( n, dvec, "  Extracted 5 digits:" );
  delete [] dvec;

  s = "34E94-70.6";
  cout << "\n";
  cout << "  Test string: '" << s << "'\n";
  n = 7;
  dvec = s_to_digits ( s, n );
  i4vec_print ( n, dvec, "  Extracted 7 digits:" );
  delete [] dvec;

  return;
}
//****************************************************************************80

void upc_check_digit_calculate_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    UPC_CHECK_DIGIT_CALCULATE_TEST tests UPC_CHECK_DIGIT_CALCULATE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2015
//
//  Author:
//
//    John Burkardt
//
{
  int d1;
  int d2;
  string s1;

  cout << "\n";
  cout << "UPC_CHECK_DIGIT_CALCULATE_TEST\n";
  cout << "  UPC_CHECK_DIGIT_CALCULATE calculates the 12-th digit\n";
  cout << "  (the check digit) of a UPC.\n";
  cout << "\n";
//
//  Supply the full code, with dashes.
//
  s1 = "6-39382-00039-3";
  d1 = 3;
  d2 = upc_check_digit_calculate ( s1 );
  cout << "  Check digit of '" << s1 << "' is " << d2 << ", expecting " << d1 << "\n";
//
//  Supply a partial code, with spaces.
//
  s1 = "0 43000 18170";
  d1 = 6;
  d2 = upc_check_digit_calculate ( s1 );
  cout << "  Check digit of '" << s1 << "' is " << d2 << ", expecting " << d1 << "\n";
//
//  Supply a partial code, no spaces.
//
  s1 = "30074660601";
  d1 = 7;
  d2 = upc_check_digit_calculate ( s1 );
  cout << "  Check digit of '" << s1 << "' is " << d2 << ", expecting " << d1 << "\n";
//
//  Supply a partial code, no spaces.
//
  s1 = "24689753124";
  d1 = 5;
  d2 = upc_check_digit_calculate ( s1 );
  cout << "  Check digit of '" << s1 << "' is " << d2 << ", expecting " << d1 << "\n";
//
//  Supply a partial code, no spaces.
//
  s1 = "13579864213";
  d1 = 9;
  d2 = upc_check_digit_calculate ( s1 );
  cout << "  Check digit of '" << s1 << "' is " << d2 << ", expecting " << d1 << "\n";

  return;
}
//****************************************************************************80

void upc_is_valid_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    UPC_IS_VALID_TEST tests UPC_IS_VALID.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2015
//
//  Author:
//
//    John Burkardt
//
{
  string s1;
  bool value1;
  bool value2;

  cout << "\n";
  cout << "UPC_IS_VALID_TEST\n";
  cout << "  UPC_IS_VALID reports whether a UPC is valid.\n";
  cout << "\n";
//
//  Supply a valid code, with dashes.
//
  s1 = "6-39382-00039-3";
  value1 = true;
  value2 = upc_is_valid ( s1 );
  cout << "  Validity of '" << s1 << "' is " << value2 << ", expecting " << value1 << "\n";
//
//  Modify one digit.
//
  s1 = "6-39352-00039-3";
  value1 = false;
  value2 = upc_is_valid ( s1 );
  cout << "  Validity of '" << s1 << "' is " << value2 << ", expecting " << value1 << "\n";
//
//  Supply a valid code, with spaces.
//
  s1 = "0 43000 18170 6";
  value1 = true;
  value2 = upc_is_valid ( s1 );
  cout << "  Validity of '" << s1 << "' is " << value2 << ", expecting " << value1 << "\n";
//
//  Modify the check digit.
//
  s1 = "0 43000 18170 9";
  value1 = false;
  value2 = upc_is_valid ( s1 );
  cout << "  Validity of '" << s1 << "' is " << value2 << ", expecting " << value1 << "\n";

  return;
}
