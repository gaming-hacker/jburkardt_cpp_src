# include <cstdlib>
# include <cstring>
# include <iomanip>
# include <iostream>

using namespace std;

# include "chrpak.hpp"

int main ( );
void test001 ( );
void test005 ( );
void test0055 ( );

void ch_cap_test ( );
void ch_count_file_add_test ( );
void ch_index_first_test ( );
void ch_index_last_test ( );
void ch_is_digit_test ( );
void ch_is_isbn_digit_test ( );
void ch_low_test ( );
void ch_pad_test ( );
void ch_to_digit_test ( );
void ch_to_rot13_test ( );
void ch_uniform_test ( );
void s_last_ch_test5 ( );
void digit_to_ch_test ( );
void test022 ( );
void i4_to_isbn_digit_test ( );
void i4_to_month_abb_test ( );
void test058 ( );
void i4_to_unary_test ( );
void isbn_digit_to_i4_test ( );
void s_adjustl_test ( );
void s_begin_test ( );
void test091 ( );
void test093 ( );
void test094 ( );
void test0975 ( );
void s_digits_count_test ( );
void s_eqi_test ( );
void s_escape_tex_test ( );
void test1035 ( );
void test1036 ( );
void test105 ( );
void s_last_ch_test ( );
void s_len_trim_test ( );
void s_replace_ch_test ( );
void s_reverse_test ( );
void s_s_subanagram_test ( );
void s_scrabble_points_test ( );
void s_sort_a_test ( );
void s_substring_test ( );
void s_to_caesar_test ( );
void s_to_digits_test ( );
void s_to_format_test ( );
void s_to_isbn_digits_test ( );
void s_to_rot13_test ( );
void s_word_count_test ( );
void s_word_extract_first_test ( );
void word_next_read_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for CHRPAK_TEST.
//
//  Discussion:
//
//    CHRPAK_TEST tests the CHRPAK library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    31 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "CHRPAK_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the CHRPAK library.\n";

  print_sizes ( );

  test001 ( );
//
//  TEST005 not ready, since BASE_TO_I4 not available yet.
//
//test005 ( );
  test0055 ( );

  ch_cap_test ( );
  ch_count_file_add_test ( );
  ch_index_first_test ( );
  ch_index_last_test ( );
  ch_is_digit_test ( );
  ch_is_isbn_digit_test ( );
  ch_low_test ( );
  ch_pad_test ( );
  ch_to_digit_test ( );
  ch_to_rot13_test ( );
  ch_uniform_test ( );

  s_last_ch_test5 ( );

  digit_to_ch_test ( );

  test022 ( );

  i4_to_isbn_digit_test ( );
  i4_to_month_abb_test ( );

  test058 ( );

  i4_to_unary_test ( );

  isbn_digit_to_i4_test ( );

  s_adjustl_test ( );
  s_begin_test ( );

  test091 ( );
  test093 ( );
  test094 ( );
  test0975 ( );

  s_digits_count_test ( );
  s_eqi_test ( );
  s_escape_tex_test ( );

  test1035 ( );
  test1036 ( );
  test105 ( );

  s_last_ch_test ( );
  s_len_trim_test ( );
  s_replace_ch_test ( );
  s_reverse_test ( );
  s_s_subanagram_test ( );
  s_scrabble_points_test ( );
  s_sort_a_test ( );
  s_substring_test ( );
  s_to_caesar_test ( );
  s_to_digits_test ( );
  s_to_format_test ( );
  s_to_isbn_digits_test ( );
  s_to_rot13_test ( );
  s_word_count_test ( );
  s_word_extract_first_test ( );

  word_next_read_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "CHRPAK_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test001 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST001 tests A_TO_I4 and I4_TO_A.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    09 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  char a;
  int i;
  int i2;

  cout << "\n";
  cout << "TEST001\n";
  cout << "  A_TO_I4: Alphabetic character => I\n";
  cout << "  I4_TO_A: I => Alphabetic character\n";
  cout << "\n";
  cout << "  1:26 = A:Z\n";
  cout << "  27:52 = a:z\n";
  cout << "\n";
  cout << "   I  ==>  A  ==>  I\n";
  cout << "\n";

  for ( i = 0; i <= 55; i = i + 3 )
  { 
    a = i4_to_a ( i );
    i2 = a_to_i4 ( a );
    cout << "  " << setw(8) << i
         << "  '" << a << "'"
         << "  " << setw(8) << i2 << "\n"; 
  }
 
  return;
}
//****************************************************************************80

void test005 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST005 tests BASE_TO_I4 and I4_TO_BASE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 January 2007
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 6

  int base;
  int base_test[TEST_NUM] = { -1, 1, 2, 3, 4, 8 };
  int i1;
  int i2;
  int i_test[TEST_NUM] = { 5, 5, 21, -243, 16, 15 };
  char *s;
  int test;

  cout << "\n";
  cout << "TEST005\n";
  cout << "  BASE_TO_I4 converts an integer in some other\n";
  cout << "  base into base 10.\n";
  cout << "  I4_TO_BASE converts an integer base 10 to \n";
  cout << "  its representation in another base;\n";
  cout << "\n";
  cout << "  BASE, I, I4_TO_BASE(I), BASE_TO_I4(I4_TO_BASE(I))\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  { 
    i1 = i_test[test];
    base = base_test[test];
//  s = i4_to_base ( i1, base );
    i2 = base_to_i4 ( s, base );

    cout << "  " << setw(8)  << base
         << "  " << setw(8)  << i1
         << "  " << setw(20) << s
         << "  " << setw(8)  << i2 << "\n";
 
    delete [] s;
  }
 
  return;
# undef TEST_NUM
}
//****************************************************************************80

void test0055 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST0055 tests BYTE_TO_INT and INT_TO_BYTE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
  int ival;
  unsigned int ival2;
  unsigned char string[4];

  cout << "\n";
  cout << "TEST0055\n";
  cout << "  INT_TO_BYTE converts an unsigned int to a string,\n";
  cout << "  BYTE_TO_INT converts it back.\n";
  cout << "\n";
  cout << "    IVAL   Recovered IVAL\n";
  cout << "\n";

  ival = 3;
  int_to_byte ( ival, string );
  byte_to_int ( string, &ival2 );
  cout << "  "
       << setw(9) << ival << "  " 
       << setw(9) << ival2 << "\n";

  ival = 1952;
  int_to_byte ( ival, string );
  byte_to_int ( string, &ival2 );
  cout << "  "
       << setw(9) << ival << "  " 
       << setw(9) << ival2 << "\n";

  ival = 123456789;
  int_to_byte ( ival, string );
  byte_to_int ( string, &ival2 );
  cout << "  "
       << setw(9) << ival << "  " 
       << setw(9) << ival2 << "\n";

  return;
}
//****************************************************************************80

void ch_cap_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_CAP_TEST tests CH_CAP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    04 June 2015
//
//  Author:
//
//    John Burkardt
//
{
  char c;

  cout << "\n";
  cout << "CH_CAP_TEST\n";
  cout << "  CH_CAP uppercases a character.\n";
  cout << "\n";
  cout << "  C  CH_CAP(C)\n";
  cout << "\n";

  c = 'F';
  cout << "  " << c << "  " << ch_cap ( c ) << "\n";
  c = 'f';
  cout << "  " << c << "  " << ch_cap ( c ) << "\n";
  c = '1';
  cout << "  " << c << "  " << ch_cap ( c ) << "\n";
  c = 'b';
  cout << "  " << c << "  " << ch_cap ( c ) << "\n";
  c = 'B';
  cout << "  " << c << "  " << ch_cap ( c ) << "\n";

  return;
}
//****************************************************************************80

void ch_count_file_add_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_COUNT_FILE_ADD_TEST tests CH_COUNT_FILE_ADD.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 June 2015
//
//  Author:
//
//    John Burkardt
//
{
  int count[256];
  string title;

  cout << "\n";
  cout << "CH_COUNT_FILE_ADD_TEST\n";
  cout << "  CH_COUNT_FILE_ADD adds the characters in a file\n";
  cout << "  to a character count.\n";

  cout << "  DEBUG, call C_COUNT_INIT:\n";

  ch_count_init ( count );

  cout << "  DEBUG, call C_COUNT_FILE_ADD:\n";

  ch_count_file_add ( "chrpak_test.cpp", count );

  cout << "  DEBUG, call C_COUNT_PRINT:\n";

  title = "Raw character count data:";
  ch_count_print ( count, title );

  return;
}
//****************************************************************************80

void ch_index_first_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_INDEX_FIRST_TEST tests CH_INDEX_FIRST.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 September 2010
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  int j;
  string s;

  cout << "\n";
  cout << "CH_INDEX_FIRST_TEST\n";
  cout << "  CH_INDEX_FIRST searches a string for a character.\n";

  s = "Joel prefers graphics to graphs.";

  cout << "\n";
  cout << "  The test string, in quotes:\n";
  cout << "\n";

  cout << "  \"" << s << "\"\n";

  c = 'g';
  j = ch_index_first ( s, c );

  cout << "  The first occurrence of '" << c << "' is at index " << j << ".\n";

  return;
}
//****************************************************************************80

void ch_index_last_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_INDEX_LAST_TEST tests CH_INDEX_LAST.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  int j;
  char s[26];

  cout << "\n";
  cout << "CH_INDEX_LAST_TEST\n";
  cout << "  CH_INDEX_LAST finds the last occurrence of a character.\n";

  strcpy ( s, "HELLO World, how ARE you?" );

  cout << "\n";
  cout << "  The test string, in quotes:\n";
  cout << "\n";

  cout << "  \"" << s << "\"\n";

  c = 'o';
  j = ch_index_last ( s, c );
  cout << "  Last occurrence of " << c << " is at " << j << ".\n";

  return;
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
  cout << "  C  CH_IS_DIGIT(C)\n";
  cout << "\n";

  for ( i = 0; i < 13; i++ )
  {
    c = c_test[i];
    value = ch_is_digit ( c );
    cout << " '" << setw(1) << c
         << "' " << setw(6) << value << "\n";
  }

  return;
}
//****************************************************************************80

void ch_is_isbn_digit_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_IS_ISBN_DIGIT_TEST tests CH_IS_ISBN_DIGIT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 September 2015
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  char c_test[16] = { 
    '0', '1', '2', '3', '4', 
    '5', '6', '7', '8', '9', 
    'X', 'x', 'Y', '*', '?', 
    ' ' };
  int i;
  bool value;

  cout << "\n";
  cout << "CH_IS_ISBN_DIGIT_TEST\n";
  cout << "  CH_IS_ISBN_DIGIT is TRUE if a character represents an ISBN digit.\n";
  cout << "\n";
  cout << "  C  CH_IS_ISBN_DIGIT(C)\n";
  cout << "\n";

  for ( i = 0; i < 16; i++ )
  {
    c = c_test[i];
    value = ch_is_isbn_digit ( c );
    cout << " '" << setw(1) << c
         << "' " << setw(6) << value << "\n";
  }

  return;
}
//****************************************************************************80

void ch_low_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_LOW_TEST tests CH_LOW.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 5

  char c1;
  char c2;
  char c_test[TEST_NUM] = { 'F', 'f', '1', 'b', 'B' };
  int test;

  cout << "\n";
  cout << "CH_LOW_TEST\n";
  cout << "  CH_LOW lowercases a character.\n";
  cout << "\n";
  cout << "  C  CH_LOW(C)\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  {
    c1 = c_test[test];
    c2 = ch_low ( c1 );

    cout << "  " << c1 << "  " << c2 << "\n";
  }

  return;
# undef TEST_NUM
}
//****************************************************************************80

void ch_pad_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_PAD_TEST tests CH_PAD.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
  int ch_index;
  int null_index;
  int result;
  char s[25];

  cout << "\n";
  cout << "CH_PAD_TEST\n";
  cout << "  CH_PAD places spaces around a character.\n";

  cout << "\n";
  strcpy ( s, "I vant to be alone!" );
  cout << "  The string is : \"" << s << "\"\n";
  cout << "  We will try to place spaces around the A in ALONE.\n";

  ch_index = 13;
  null_index = strlen ( s );

  result = ch_pad ( &ch_index, &null_index, s, 25 );

  if ( result != 0 ) 
  {
    cout << "  The operation failed.\n";
  }
  else 
  {
    cout << "  The string is : \"" << s << "\"\n";
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

void ch_to_rot13_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_TO_ROT13_TEST tests CH_TO_ROT13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 March 2006
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  char s1[80];
  int s1_length;
  char s2[80];
  char s3[80];

  cout << "\n";
  cout << "CH_TO_ROT13_TEST\n";
  cout << "  CH_TO_ROT13 \"encodes\" a character using ROT13.\n";

  strcpy ( s1, "ABCDEFGHIJKLMNOPQRSTUVQXYZ" );
  s1_length = charstar_len_trim ( s1 );

  strcpy ( s2, " " );
  strcpy ( s3, " " );
//
//  Notice that we also copy the trailing NULL character from S1 to S2 and S3.
//
  for ( i = 0; i <= s1_length; i++ )
  {
    *(s2+i) = ch_to_rot13 ( *(s1+i) );
    *(s3+i) = ch_to_rot13 ( *(s2+i) );
  }

  cout << "\n";
  cout << "             CH  :" << s1 << "\n";
  cout << "       ROT13(CH) :" << s2 << "\n";
  cout << " ROT13(ROT13(CH)):" << s3 << "\n";

  strcpy ( s1, "  CH_TO_ROT13 \"encodes\" a character using ROT13." );
  s1_length = charstar_len_trim ( s1 );

  strcpy ( s2, " " );
  strcpy ( s3, " " );

  for ( i = 0; i <= s1_length; i++ )
  {
    *(s2+i) = ch_to_rot13 ( *(s1+i) );
    *(s3+i) = ch_to_rot13 ( *(s2+i) );
  }

  cout << "\n";
  cout << "             CH  :" << s1 << "\n";
  cout << "       ROT13(CH) :" << s2 << "\n";
  cout << " ROT13(ROT13(CH)):" << s3 << "\n";

  return;
}
//****************************************************************************80

void ch_uniform_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CH_UNIFORM_TEST tests CH_UNIFORM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  char ch;
  char chi;
  char clo;
  int count[26];
  int i;
  int j;
  int seed;
 
  cout << "\n";
  cout << "CH_UNIFORM_TEST\n";
  cout << "  CH_UNIFORM returns a random character.\n";

  for ( i = 0; i < 26; i++ )
  {
    count[i] = 0;
  }

  clo = 'D';
  chi = 'W';
  seed = 123456789;
 
  cout << "\n";
  cout << "   I  A  Count\n";
  cout << "\n";

  for ( i = 1; i <= 100000; i++ )
  {
    ch = ch_uniform ( clo, chi, seed );

    j = a_to_i4 ( ch );
    count[j-1] = count[j-1] + 1;
  }

  for ( i = 1; i <= 26; i++ )
  {
    cout << "  " << setw(2) << i
         << "  " << i4_to_a ( i )
         << "  " << setw(5) << count[i-1] << "\n";
  }

  return;
}
//****************************************************************************80

void s_last_ch_test5 ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_LAST_CH_TEST5 tests CHARSTAR_LEN_TRIM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
  char s[11];
  int test;

  cout << "\n";
  cout << "S_LAST_CH_TEST5\n";
  cout << "  CHARSTAR_LEN_TRIM reports the length of a string to the last nonblank.\n";
  cout << "\n";
  cout << "  Here are some strings, and their lengths:\n";
  cout << "\n";

  for ( test = 0; test < 4; test++ )
  {
    if ( test == 0 )
    {
      strcpy ( s, "HELLO" );
    }
    else if ( test == 1 )
    {
      strcpy ( s, "  B la nk" );
    }
    else if ( test == 2 )
    {
      strcpy ( s, " ");
    }
    else if ( test == 3 )
    {
      strcpy ( s, "1234567890" );
    }
    cout << " \"" << s << "\"  " << charstar_len_trim ( s ) << "\n";
  }

  return;
}
//****************************************************************************80

void digit_to_ch_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DIGIT_TO_CH_TEST tests DIGIT_TO_CH.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  int i;
  int i2;

  cout << "\n";
  cout << "DIGIT_TO_CH_TEST\n";
  cout << "  DIGIT_TO_CH: character -> decimal digit\n";
  cout << "\n";

  for ( i = -2; i <= 11; i++ )
  {
    c = digit_to_ch ( i );
    i2 = ch_to_digit ( c );
    cout << "  " << setw(6) << i
         << "  " << setw(1) << c
         << "  " << setw(6) << i2 << "\n";
  }

  return;
}
//****************************************************************************80

void test022 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST022 tests HEX_DIGIT_TO_I4 and I4_TO_HEX_DIGIT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    31 August 2009
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  int i;
  int i2;

  cout << "\n";
  cout << "TEST022\n";
  cout << "  HEX_DIGIT_TO_I4: hexadecimal digit -> I4,\n";
  cout << "  I4_TO_HEX_DIGIT: I4 -> hexadecimal digit.\n";
  cout << "\n";
 
  for ( i = - 2; i <= 17; i++ )
  {
    c = i4_to_hex_digit ( i );
    i2 = hex_digit_to_i4 ( c );
    cout << "  " << setw(8) << i
         << "  " << "'"     << c << "'"
         << "  " << setw(8) << i2 << "\n";
  }
 
  return;
}
//****************************************************************************80

void i4_to_isbn_digit_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_TO_ISBN_DIGIT_TEST tests I4_TO_ISBN_DIGIT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 September 2015
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  int i4;

  cout << "\n";
  cout << "I4_TO_ISBN_DIGIT_TEST\n";
  cout << "  I4_TO_ISBN_DIGIT converts digits 0 to 10 to an ISBN digit.\n";
  cout << "\n";

  for ( i4 = 0; i4 <= 10; i4++ )
  {
    c = i4_to_isbn_digit ( i4 );
    cout << "  " << setw(2) << i4
         << "  '" << c << "'\n";
  }

  return;
}
//****************************************************************************80

void i4_to_month_abb_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_TO_MONTH_ABB_TEST tests I4_TO_MONTH_ABB.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  string s;

  cout << "\n";
  cout << "I4_TO_MONTH_ABB_TEST\n";
  cout << "  I4_TO_MONTH_ABB returns the name of the I-th month.\n";
  cout << "\n";
  cout << "  I  Month\n";
  cout << "\n";

  for ( i = 0; i <= 12; i++ ) 
  {
    s = i4_to_month_abb ( i ) ;
    cout << "  " << i << " " << s << "\n";
  }

  return;
}
//****************************************************************************80

void test058 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST058 tests I4_TO_S and S_TO_I4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 8

  bool error;
  int i;
  int last;
  string s_test[TEST_NUM] = {
    "0", "9", "10", "11", " -124 56 AbC", "25,50,5", "+15.9", "  123abc" 
  };
  string s1;
  string s2;
  int test;

  cout << "\n";
  cout << "TEST058\n";
  cout << "  I4_TO_S:  int ->    string;\n";
  cout << "  S_TO_I4:  string -> I4.\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  {
    s1 = s_test[test];
    i  = s_to_i4 ( s1, last, error );
    s2 = i4_to_s ( i );
    cout << "  " << "\"" << s1 << "\""
         << "  "         << i  
         << "  " << "\"" << s2 << "\"" << "\n";
  }

  return;
# undef TEST_NUM
}
//****************************************************************************80

void i4_to_unary_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_TO_UNARY_TEST tests I4_TO_UNARY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 3

  int i4;
  int i4_test[TEST_NUM] = { -5, 0, 7 };
  string s;
  int test;

  cout << "\n";
  cout << "I4_TO_UNARY_TEST\n";
  cout << "  I4_TO_UNARY converts an integer to unary.\n";
  cout << "\n";
  cout << "  I4  I4_TO_UNARY(I4)\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  { 
    i4 = i4_test[test];
    s = i4_to_unary ( i4 );
    cout << "  " << setw(8) << i4
         << "  \"" << s << "\"\n";
  }
 
  return;
# undef TEST_NUM
}
//****************************************************************************80

void isbn_digit_to_i4_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ISBN_DIGIT_TO_I4_TEST tests ISBN_DIGIT_TO_I4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 September 2015
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  char c_test[16] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'X', 'x', 'Y', '*', '?', ' ' };
  int i;
  int i4;

  cout << "\n";
  cout << "ISBN_DIGIT_TO_I4_TEST\n";
  cout << "  ISBN_DIGIT_TO_I4 converts an ISBN digit to an I4\n";
  cout << "\n";

  for ( i = 0; i < 16; i++ )
  {
    c = c_test[i];
    i4 = isbn_digit_to_i4 ( c );
    cout << "  '" << c
         << "'  " << setw(2) << i4 << "\n";
  }

  return;
}
//****************************************************************************80

void s_adjustl_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_ADJUSTL_TEST tests S_ADJUSTL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
{
  string s1;
  string s2;

  cout << "\n";
  cout << "S_ADJUSTL_TEST\n";
  cout << "  S_ADJUSTL justifies a string to the left;\n";
  cout << "\n";
  cout << "             Original   S_ADJUSTL\n";
  cout << "           ----------  ---------- \n";
  cout << "\n";

  s1 = "  Hello!  ";
  s2 = s_adjustl ( s1 );
  cout << "\"" << s1 << "\"  "
       << "\"" << s2 << "\"\n";

  s1 = "Ouch!     ";
  s2 = s_adjustl ( s1 );
  cout << "\"" << s1 << "\"  "
       << "\"" << s2 << "\"\n";

  s1 = "  A B C   ";
  s2 = s_adjustl ( s1 );
  cout << "\"" << s1 << "\"  "
       << "\"" << s2 << "\"\n";
  
  return;
}
//****************************************************************************80

void s_begin_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_BEGIN_TEST tests S_BEGIN.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 September 2010
//
//  Author:
//
//    John Burkardt
//
{
  string s1;
  string s2;

  cout << "\n";
  cout << "S_BEGIN_TEST\n";
  cout << "  S_BEGIN is true if string 1 begins with string 2.\n";

  s1 = "Look for the lily in the field.";
  s2 = "Look for";

  cout << "\n";
  cout << "  S1: \"" << s1 << "\"\n";
  cout << "  S2: \"" << s2 << "\"\n";
  cout << "  SBEGIN ( S1, S2 ) = " << s_begin ( s1, s2 ) << "\n";

  s1 = "Look for";
  s2 = "Look for the lily in the field.";

  cout << "\n";
  cout << "  S1: \"" << s1 << "\"\n";
  cout << "  S2: \"" << s2 << "\"\n";
  cout << "  SBEGIN ( S1, S2 ) = " << s_begin ( s1, s2 ) << "\n";

  s1 = "Look for the lily in the field.";
  s2 = "Look out!";

  cout << "\n";
  cout << "  S1: \"" << s1 << "\"\n";
  cout << "  S2: \"" << s2 << "\"\n";
  cout << "  SBEGIN ( S1, S2 ) = " << s_begin ( s1, s2 ) << "\n";

  return;
}
//****************************************************************************80

void test091 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST091 tests S_BEHEAD_SUBSTRING.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    30 January 2006
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 4

  int i;
  char s[21];
  char s_old[21];
  char sub[21];

  cout << "\n";
  cout << "TEST091\n";
  cout << "  S_BEHEAD_SUBSTRING removes an initial substring from a \n";
  cout << "  string, if it occurs.\n";
  cout << "\n";
  cout << "  ------String--------  -----SUB------------  ---Beheaded----\n";
  cout << "\n";

  for ( i = 1; i <= TEST_NUM; i++ )
  {
    if ( i == 1 )
    {
      strcpy ( s,   "    HELLO World!" );
      strcpy ( sub, "HELLO" );
    }
    else if ( i == 2 )
    {
      strcpy ( s,   "12345678901234567890" );
      strcpy ( sub, "12345" );
    }
    else if ( i == 3 )
    {
      strcpy ( s,   "0.314159E+01" );
      strcpy ( sub, "314" );
    }
    else if ( i == 4 )
    {
      strcpy ( s,   "!@#$%a^&A(){}[]\\|<>?" );
      strcpy ( sub, "!@#$%a^&A(){}[]\\|<>?" );
    }

    strcpy ( s_old, s );

    s_behead_substring ( s, sub );

    cout << "  " << setw(20) << s_old
         << "  " << setw(20) << sub
         << "  " << setw(20) << s << "\n";
  }

  return;
# undef TEST_NUM
}
//****************************************************************************80

void test093 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST093 tests S_BLANKS_DELETE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    30 August 2009
//
//  Author:
//
//    John Burkardt
//
{
  string s1;
  string s2;

  s1 = " HELLO    World   !! !  ";
 
  cout << "\n";
  cout << "TEST093\n";
  cout << "  S_BLANKS_DELETE removes double blanks.\n";
  cout << "\n";
  cout << "  Original string:\n";
  cout << "\n";
  cout << "    \"" << s1 << "\"\n";

  s2 = s_blanks_delete ( s1 );

  cout << "\n";
  cout << "  After S_BLANKS_DELETE:\n";
  cout << "\n";
  cout << "    \"" << s2 << "\"\n";

  return;
}
//****************************************************************************80

void test094 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST094 tests S_CAP, S_LOW and S_WORD_CAP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 5

  string s_test[TEST_NUM] = {
    "HELLO World   !! !  ",
    "12345678901234567890",
    "Abc Def Ghi Jkl Mno ",
    "!@#$%a^&A(){}[]\\|<>?",
    "it is time to turn the page." };

  string s;
  string s1;
  string s2;
  string s3;
  int test;
  
  cout << "\n";
  cout << "TEST094\n";
  cout << "  S_CAP capitalizes all characters in a string;\n";
  cout << "  S_LOW lowercases all characters;\n";
  cout << "  S_WORD_CAP initial-capitalizes words in a string;\n";
  cout << "\n";
  cout << "  ------Original------  -----Capitalized-----";
  cout << "-----Lower Cased-----  -----Word_Caps-----\n";
  cout << "\n";
 
  for ( test = 0; test < TEST_NUM; test++ )
  {
    s = s_test[test];
    s1 = s_cap ( s );
    s2 = s_low ( s );
    s3 = s_word_cap ( s );

    cout << "  " << "\"" << s << "\""
         << "  " << "\""<< s1 << "\""
         << "  " << "\""<< s2 << "\""
         << "  " << "\""<< s3 << "\"" << "\n";
  }
 
  return;
# undef TEST_NUM
}
//****************************************************************************80

void test0975 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST0975 tests S_CH_COUNT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    30 August 2009
//
//  Author:
//
//    John Burkardt
//
{
  char ch = 'b';
  int ch_count;
  string s = "Bob is debobbing the bobber!";

  cout << "\n";
  cout << "TEST0975\n";
  cout << "  S_CH_COUNT counts occurrences of a character.\n";
 
  cout << "\n";
  cout << "  String =     \"" << s << "\".\n";
  cout << "  Character is \"" << ch << "\".\n";

  ch_count = s_ch_count ( s, ch );

  cout << "  Number of occurrences = " << ch_count << "\n";

  return;
}
//****************************************************************************80

void s_digits_count_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_DIGITS_COUNT_TEST tests S_DIGITS_COUNT.
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
  int n;
  string s;
 
  cout << "\n";
  cout << "S_DIGITS_COUNT_TEST\n";
  cout << "  S_DIGITS_COUNT counts the digits in a string.\n";
  cout << "\n";

  s = "34E94-70.6";
  n = s_digits_count ( s );
  cout << "  We count " << n << " digits in '" << s << "'\n";

  s = "Not a one!";
  n = s_digits_count ( s );
  cout << "  We count " << n << " digits in '" << s << "'\n";

  s = "!8*k >>>> & SEVEN-0.3";
  n = s_digits_count ( s );
  cout << "  We count " << n << " digits in '" << s << "'\n";

  return;
}
//****************************************************************************80

void s_eqi_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_EQI_TEST tests S_EQI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
{
  string s1;
  string s2;

  cout << "\n";
  cout << "S_EQI_TEST\n";
  cout << "  S_EQI reports if two strings are equal, ignoring case.\n";

  s1 = "HELLO";
  s2 = "HeLLO";

  cout << "\n";
  cout << "  String 1:\n";
  cout << "\n";
  cout << "  \"" << s1 << "\"\n";

  cout << "\n";
  cout << "  String2:\n";
  cout << "\n";
  cout << "  \"" << s2 << "\"\n";

  cout << "\n";
  cout << "  S_EQI(S1,S2) = " << s_eqi ( s1, s2 ) << "\n";

  s1 = "HELP ME";
  s2 = "HELP";

  cout << "\n";
  cout << "  String 1:\n";
  cout << "\n";
  cout << "  \"" << s1 << "\"\n";

  cout << "\n";
  cout << "  String2:\n";
  cout << "\n";
  cout << "  \"" << s2 << "\"\n";

  cout << "\n";
  cout << "  S_EQI(S1,S2) = " << s_eqi ( s1, s2 ) << "\n";

  return;
}
//****************************************************************************80

void s_escape_tex_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_ESCAPE_TEX_TEST tests S_ESCAPE_TEX.
//
//  Discussion:
//
//    Since "\" is also a C++ escape character, to do this example we have
//    to enter "\\" in the initialization of S1; this actually puts just 
//    a plain old "\" there.  Oh, the joys of escape sequences!
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
  string s1 = "The file A_B.TXT is {I think__so} of size 2^8 or C\\B.";
  string s2;

  cout << "\n";
  cout << "S_ESCAPE_TEX_TEST\n";
  cout << "  S_ESCAPE_TEX \"protects\" characters in a string\n";
  cout << "  that might otherwise be interpreted as TeX\n";
  cout << "  escape characters.\n";

  cout << "\n";
  cout << "  Original string:\n";
  cout << "\n";
  cout << "  \"" << s1 << "\".\n";

  s2 = s_escape_tex ( s1 );

  cout << "\n";
  cout << "  De-escaped string:\n";
  cout << "\n";
  cout << "  \"" << s2 << "\".\n";

  return;
}
//****************************************************************************80

void test1035 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST1035 tests S_FIRST_CH.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    30 August 2009
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  string s;
  int s_index;

  cout << "\n";
  cout << "TEST1035\n";
  cout << "  S_FIRST_CH finds the first occurrence of a character.\n";

  s = "Look for the lily in the field.";

  cout << "\n";
  cout << "  The test string, in quotes:\n";
  cout << "\n";
  cout << "  \"" << s << "\"\n";

  c = 'l';
  s_index = s_first_ch ( s, c );

  if ( s_index == - 1 )
  {
    cout << "\n";
    cout << "  The character '" << c << "' does not occur.\n";
  }
  else
  {
    cout << "\n";
    cout << "  The character '" << c 
         << "' first occurs in position " << s_index << ".\n";
  }
  return;
}
//****************************************************************************80

void test1036 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST1036 tests S_FIRST_NONBLANK.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
  char *first;
  char s[40];

  cout << "\n";
  cout << "TEST1036\n";
  cout << "  S_FIRST_NONBLANK finds a pointer to the first \n";
  cout << "  nonblank character in a string.\n";

  strcpy ( s, "     HELLO World, how ARE you?" );

  cout << "\n";
  cout << "  The test string, in quotes:\n";
  cout << "\n";
  cout << "  \"" << s << "\"\n";

  first = s_first_nonblank ( s );

  cout << "\n";
  cout << "  The string shifted left, using the pointer:\n";
  cout << "\n";
  cout << "  \"" << first << "\"\n";

  return;
}
//****************************************************************************80

void test105 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST105 tests S_INC_C.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  char s[30];

  cout << "\n";
  cout << "TEST105\n";
  cout << "  S_INC_C can \"increment\" the characters in a string.\n";

  strcpy ( s, "Tax" );

  cout << "\n";
  cout << "  Starting string: \"" << s << "\"\n";
  cout << "\n";
  cout << "  Incremented forms:\n";
  cout << "\n";

  for ( i = 1; i <= 5; i++ )
  {
    s_inc_c ( s );
    cout << "  " << s << "\n";
  }
 
  strcpy ( s, "aB34c* 8zY" );
 
  cout << "\n";
  cout << "  Starting string: \"" << s << "\"\n";
  cout << "\n";
  cout << "  Incremented forms:\n";
  cout << "\n";

  for ( i = 1; i <= 5; i++ )
  {
    s_inc_c ( s );
    cout << "  " << s << "\n";
  }
 
  return;
}
//****************************************************************************80

void s_last_ch_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_LAST_CH_TEST tests S_LAST_CH.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 September 2010
//
//  Author:
//
//    John Burkardt
//
{
  char c;
  string s;
  string t;

  cout << "\n";
  cout << "S_LAST_CH_TEST\n";
  cout << "  S_LAST_CH finds the last occurrence of a character.\n";

  s = "Look for last . in file_name.cpp";

  cout << "\n";
  cout << "  The test string, in quotes:\n";
  cout << "\n";

  cout << "  \"" << s << "\"\n";

  c = '.';
  t = s_last_ch ( s, c );

  cout << "\n";
  cout << "  The string, starting with the last occurrence of '"
    << c << "':\n";

  cout << "\n";
  cout << "  \"" << t << "\"\n";

  return;
}
//****************************************************************************80

void s_len_trim_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_LEN_TRIM_TEST tests S_LEN_TRIM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
{
  string s;
  int test;

  cout << "\n";
  cout << "S_LEN_TRIM_TEST\n";
  cout << "  S_LEN_TRIM reports the length of a string to the last nonblank.\n";
  cout << "\n";
  cout << "  Here are some strings, and their lengths:\n";
  cout << "\n";

  for ( test = 0; test < 4; test++ )
  {
    if ( test == 0 )
    {
      s = "HELLO";
    }
    else if ( test == 1 )
    {
      s = "  B la nk";
    }
    else if ( test == 2 )
    {
      s = " ";
    }
    else if ( test == 3 )
    {
      s = "1234567890";
    }
    cout << " \"" << s << "\"  " << s_len_trim ( s ) << "\n";
  }

  return;
}
//****************************************************************************80

void s_replace_ch_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_REPLACE_CH_TEST tests S_REPLACE_CH.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
  char c1;
  char c2;
  string s_test = "No pennies now.";
  string s1;
  string s2;

  cout << "\n";
  cout << "S_REPLACE_CH_TEST\n";
  cout << "  S_REPLACE_CH replaces one character by another;\n";
  cout << "\n";
  cout << "    C1  C2  Original String  Modified String\n";
  cout << "\n";

  c1 = 'n';
  c2 = 't';
  s1 = s_test;

  s2 = s_replace_ch ( s1, c1, c2 );

  cout << "     " << c1
       << "   " << c2
       << "   " << s1
       << "   " << s2 << "\n";

  return;
}
//****************************************************************************80

void s_reverse_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_REVERSE_TEST tests S_REVERSE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
  string s = "A man, a plan, a canal, Panama!";
  string s2;

  cout << "\n";
  cout << "S_REVERSE_TEST\n";
  cout << "  S_REVERSE reverses a string.\n";
  cout << "\n";
  cout << "  Before: \"" << s << "\".\n";
  s2 = s_reverse ( s );
  cout << "  After:  \"" << s2 << "\".\n";
 
  return;
}
//****************************************************************************80

void s_s_subanagram_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_S_SUBANAGRAM_TEST tests S_S_SUBANAGRAM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 4

  string s1;
  string s1_test[TEST_NUM] = {
    "Get a priest!", 
    "Get a priest!", 
    "Get a priest!", 
    "Get a priest!" };
  string s2;
  string s2_test[TEST_NUM] = {
    "stripe", 
    "pastor", 
    "a sip", 
    "tag!" };
  int test;
  bool value;

  cout << "\n";
  cout << "S_S_SUBANAGRAM_TEST\n";
  cout << "  S_S_SUBANAGRAM is TRUE if S2 is a \"subanagram\"\n";
  cout << "  of S1.\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  {
    s1 = s1_test[test];
    s2 = s2_test[test];

    value = s_s_subanagram ( s1, s2 );

    cout << "  \"" << s1 << "\""
         << "  \"" << s2 << "\""
         << "  " << value << "\n";
  }

  return;
# undef TEST_NUM
}
//****************************************************************************80

void s_scrabble_points_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_SCRABBLE_POINTS_TEST tests S_SCRABBLE_POINTS.
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
{
  int i;
  string s;
  int value;

  cout << "\n";
  cout << "S_SCRABBLE_POINTS_TEST\n";
  cout << "  S_SCRABBLE_POINTS returns the value of a string\n";
  cout << "  as a Scrabble word.\n";
  cout << "\n";
  cout << "   I  ----S-------   Value\n";
  cout << "\n";
  for ( i = 1; i <= 12; i++ )
  {
    s = i4_to_month_name ( i );
    value = s_scrabble_points ( s );
    cout << "  " << setw(2) << i
         << "  " << setw(9) << s
         << "  " << setw(6) << value << "\n";
  }

  return;
}
//****************************************************************************80

void s_sort_a_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_SORT_A_TEST tests S_SORT_A.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 5

  string s;
  string s_test[TEST_NUM] = {
    "HELLO World   !! !  ",
    "12345678901234567890",
    "Abc Def Ghi Jkl Mno ",
    "AbleBakerCharlieDelt",
    "What? You have seen?" };
  string s2;
  int test;

  cout << "\n";
  cout << "S_SORT_A_TEST\n";
  cout << "  S_SORT_A ascending sorts a string.\n";
  cout << "\n";
  cout << "  -------String-------  -------Sorted-------\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  {
    s = s_test[test];
    s2 = s_sort_a ( s );
    cout << "  " << "\"" << s << "\""
         << "  " << "\"" << s2 << "\"" << "\n";
  }

  return;
# undef TEST_NUM
}
//****************************************************************************80

void s_substring_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_SUBSTRING_TEST tests S_SUBSTRING.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
  int a;
  int b;
  char s[21];

  cout << "\n";
  cout << "S_SUBSTRING_TEST\n";
  cout << "  S_SUBSTRING returns a substring of a given string.\n";
  cout << "\n";
  cout << "      S                  A   B    S(A:B)\n";
  cout << "  --------------------  --  --  ----------\n";
  cout << "\n";

  strcpy ( s, "abcdefghijklmnopqrts" );
  a = 6;
  b = 10;

  cout << "  "
       << setw(20) << s << "  "
       << setw(2)  << a << "  "
       << setw(2)  << b << "  "
                   << s_substring ( s, a, b ) << "\n";

  a = 15;
  b = 15;

  cout << "  "
       << setw(20) << s << "  "
       << setw(2)  << a << "  "
       << setw(2)  << b << "  "
                   << s_substring ( s, a, b ) << "\n";

  a = 17;
  b = 20;

  cout << "  "
       << setw(20) << s << "  "
       << setw(2)  << a << "  "
       << setw(2)  << b << "  "
                   << s_substring ( s, a, b ) << "\n";
  return;
}
//****************************************************************************80

void s_to_caesar_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_CAESAR_TEST tests the S_TO_CAESAR library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 January 2016
//
//  Author:
//
//    John Burkardt
//
{
  int k;
  string s1;
  string s2;
  string s3;

  cout << "\n";
  cout << "S_TO_CAESAR_TEST\n";
  cout << "  S_TO_CAESAR applies a Caesar Shift cipher to a string.\n";

  cout << "\n";
  cout << "  S2 = S_TO_CAESAR ( S1, K ), varying K.\n";
  cout << "\n";
  cout << "   K  ---------------S1----------------  ---------------S2----------------\n";
  cout << "\n";
  for ( k = -5; k <= 5; k++ )
  {
    s1 = "A man, a plan, a canal: Panama!";
    s2 = s_to_caesar ( s1, k );
    cout << "  " << setw(2) << k
         << "  '" << s1
         << "'  '" << s2 << "'\n";
  }

  cout << "\n";
  cout << "  S2 = S_TO_CAESAR ( S1,  K ).\n";
  cout << "  S3 = S_TO_CAESAR ( S2, -K )\n";
  cout << "\n";
  cout << "   K  ------------S1------------  ------------S2------------  ------------S3------------\n";
  cout << "\n";
  for ( k = -5; k <= 5; k++ )
  {
    s1 = "The key is under the mat";
    s2 = s_to_caesar ( s1, k );
    s3 = s_to_caesar ( s2, -k );
    cout << "  " << setw(2) << k
         << "  '" << s1
         << "'  '" << s2 
         << "'  '" << s3 << "'\n";
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

void s_to_format_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_FORMAT_TEST tests S_TO_FORMAT
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 7

  char c;
  int i;
  int m;
  int r;
  char s[21];
  int w;
 
  cout << "\n";
  cout << "S_TO_FORMAT_TEST\n";
  cout << "  S_TO_FORMAT, string -> FORTRAN format RcW.M;\n";
  cout << "\n";
  cout << "  --------String------       R  c     W       M\n";
  cout << "\n";

  for ( i = 1; i <= TEST_NUM; i++ )
  {
    if ( i == 1 ) 
    {
      strcpy ( s, "a80" );
    }
    else if ( i == 2 ) 
    {
      strcpy ( s, "f8.4" );
    }
    else if ( i == 3 ) 
    {
      strcpy ( s, "3g14.6" );
    }
    else if ( i == 4 ) 
    {
      strcpy ( s, "i12" );
    }
    else if ( i == 5 ) 
    {
      strcpy ( s, "12l1" );
    }
    else if ( i == 6 )
    {
      strcpy ( s, "(10o11)" );
    }
    else if ( i == 7 ) 
    {
      strcpy ( s, " ( 5 z 11.7  )" );
    }

    s_to_format ( s, &r, &c, &w, &m );

    cout << "  "
         << setw(20) << s << "  "
         << setw(6)  << r << "  "
                     << c
         << setw(6)  << w << "  "
         << setw(6)  << m << "\n";
  }

  return;
# undef TEST_NUM
}
//****************************************************************************80

void s_to_isbn_digits_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_ISBN_DIGITS_TEST tests S_TO_ISBN_DIGITS.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 September 2015
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
  cout << "S_TO_ISBN_DIGITS_TEST\n";
  cout << "  S_TO_ISBN_DIGITS: string -> ISBN digit vector\n";

  s = "34E9X-70.6";
  cout << "\n";
  cout << "  Test string: '" << s << "'\n";
  n = 5;
  dvec = s_to_isbn_digits ( s, n );
  i4vec_print ( n, dvec, "  Extracted 5 digits:" );
  delete [] dvec;

  s = "34E9X-70.6";
  cout << "\n";
  cout << "  Test string: '" << s << "'\n";
  n = 7;
  dvec = s_to_isbn_digits ( s, n );
  i4vec_print ( n, dvec, "  Extracted 7 digits:" );
  delete [] dvec;

  return;
}
//****************************************************************************80

void s_to_rot13_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_ROT13_TEST tests S_TO_ROT13.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 August 2009
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 3

  string s;
  string s2;
  string s3;
  string s_test[TEST_NUM] = {
    "abcdefghijklmnopqrstuvwxyz",
    "Cher",
    "James Thurston Howell" };
  int test;

  cout << "\n";
  cout << "S_TO_ROT13_TEST\n";
  cout << "  S_TO_ROT13 encrypts a string.\n";
  cout << "\n";
 
  for ( test = 0; test < TEST_NUM; test++ )
  {
    s = s_test[test];
    cout << "\n";
    cout << "  Original:      " << s << "\n";
    s2 = s_to_rot13 ( s );
    cout << "  Rotated once:  " << s2  << "\n";
    s3 = s_to_rot13 ( s2 );
    cout << "  Rotated twice: " << s3  << "\n";
  }
  return;
# undef TEST_NUM
}
//****************************************************************************80

void s_word_count_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_WORD_COUNT_TEST tests S_WORD_COUNT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 January 2007
//
//  Author:
//
//    John Burkardt
//
{
  char s[40];

  cout << "\n";
  cout << "S_WORD_COUNT_TEST\n";
  cout << "  S_WORD_COUNT counts the words in a string\n";
  cout << "\n";
  cout << "  STRING                      Words\n";
  cout << "\n";
 
  strcpy ( s, "?" );
  cout << "  " 
       << setw(32) << s << "  "
       << setw(12) << s_word_count ( s ) << "\n";

  strcpy ( s, "A man, a plan, a canal - Panama!" );
  cout << "  "
       << setw(32) << s << "  "
       << setw(12) << s_word_count ( s ) << "\n";

  strcpy ( s, " justone!word,-@#$ " );
  cout << "  "
       << setw(32) << s << "  "
       << setw(12) << s_word_count ( s ) << "\n";

  strcpy ( s, "How about a day in the park?" );
  cout << "  "
       << setw(32) << s << "  "
       << setw(12) << s_word_count ( s ) << "\n";

  return;
}
//****************************************************************************80

void s_word_extract_first_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    S_WORD_EXTRACT_FIRST_TEST tests S_WORD_EXTRACT_FIRST.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 October 2010
//
//  Author:
//
//    John Burkardt
//
{
  string s;
  string s1;
  string s2;

  s = "Just an incontrovertible sample of text!";

  cout << "\n";
  cout << "S_WORD_EXTRACT_FIRST_TEST\n";
  cout << "  S_WORD_EXTRACT_FIRST extracts the first word from a string.\n";
  cout << "\n";
  cout << "  Our input string is:\n";
  cout << "  \"" << s << "\".\n";
  cout << "\n";

  for ( ; ; )
  {
    s_word_extract_first ( s, s1, s2 );

    if ( s1 == "" )
    {
      cout << "\n";
      cout << "  Reached the last word.\n";
      break;
    }

    cout << "  \"" << s1 << "\"\n";
    s = s2;
  }
  return;
}
//****************************************************************************80

void word_next_read_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    WORD_NEXT_READ_TEST tests WORD_NEXT_READ.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 October 2010
//
//  Author:
//
//    John Burkardt
//
{
  bool done;
  string s = "  Here is a string, (you see) with x[1] = {gamma}!";
  string w;
  int word_num;

  cout << "\n";
  cout << "WORD_NEXT_READ_TEST\n";
  cout << "  WORD_NEXT_READ returns each word from a string.\n";
  cout << "  It pays attention to various parentheses and brackets.\n";
  cout << "\n";
  cout << "  We use the following string:\n";
  cout << "    \"" << s << "\".\n";
  cout << "\n";
  cout << "  Here are the individual words:\n";
  cout << "\n";

  done = true;
  word_num = 0;

  for ( ; ; )
  {
    w = word_next_read ( s, &done );
 
    if ( done )
    {
      cout << "\n";
      cout << "  Number of words was " << word_num << "\n";
      break;
    }

    word_num = word_num + 1;

    cout << "  " << setw(6) << word_num
         << "  \"" << w << "\".\n";
  }
  return;
}
