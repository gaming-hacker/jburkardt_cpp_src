# include <cmath>
# include <cstdlib>
# include <cstdio>
# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "weekday.hpp"

//****************************************************************************80

char digit_to_ch ( int i )

//****************************************************************************80
//
//  Purpose:
//
//    DIGIT_TO_CH returns the base 10 digit character corresponding to a digit.
//
//  Example:
//
//     I     C
//   -----  ---
//     0    '0'
//     1    '1'
//   ...    ...
//     9    '9'  
//    10    '*'
//   -83    '*'
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 June 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the digit, which should be between 0 and 9.
//
//    Output, char DIGIT_TO_CH, the appropriate character '0' 
//    through '9' or '*'.
//
{
  char c;

  if ( 0 <= i && i <= 9 )
  {
    c = '0' + i;
  }
  else
  {
    c = '*';
  }

  return c;
}
//****************************************************************************80

int i4_max ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MAX returns the maximum of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, are two integers to be compared.
//
//    Output, int I4_MAX, the larger of I1 and I2.
//
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
//****************************************************************************80

int i4_min ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MIN returns the minimum of two I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, two integers to be compared.
//
//    Output, int I4_MIN, the smaller of I1 and I2.
//
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
//****************************************************************************80

int i4_modp ( int i, int j )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MODP returns the nonnegative remainder of I4 division.
//
//  Discussion:
//
//    If 
//      NREM = I4_MODP ( I, J ) 
//      NMULT = ( I - NREM ) / J
//    then
//      I = J * NMULT + NREM
//    where NREM is always nonnegative.
//
//    The MOD function computes a result with the same sign as the
//    quantity being divided.  Thus, suppose you had an angle A,
//    and you wanted to ensure that it was between 0 and 360.
//    Then mod(A,360) would do, if A was positive, but if A
//    was negative, your result would be between -360 and 0.
//
//    On the other hand, I4_MODP(A,360) is between 0 and 360, always.
//
//        I         J     MOD  I4_MODP   I4_MODP Factorization
// 
//      107        50       7       7    107 =  2 *  50 + 7
//      107       -50       7       7    107 = -2 * -50 + 7
//     -107        50      -7      43   -107 = -3 *  50 + 43
//     -107       -50      -7      43   -107 =  3 * -50 + 43
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 May 1999
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the number to be divided.
//
//    Input, int J, the number that divides I.
//
//    Output, int I4_MODP, the nonnegative remainder when I is 
//    divided by J.
//
{
  int value;

  if ( j == 0 )
  {
    cerr << "\n";
    cerr << "I4_MODP - Fatal error!\n";
    cerr << "  I4_MODP ( I, J ) called with J = " << j << "\n";
    exit ( 1 );
  }

  value = i % j;

  if ( value < 0 )
  {
    value = value + abs ( j );
  }

  return value;
}
//****************************************************************************80

int i4_wrap ( int ival, int ilo, int ihi )

//****************************************************************************80
//
//  Purpose:
//
//    I4_WRAP forces an I4 to lie between given limits by wrapping.
//
//  Example:
//
//    ILO = 4, IHI = 8
//
//    I   Value
//
//    -2     8
//    -1     4
//     0     5
//     1     6
//     2     7
//     3     8
//     4     4
//     5     5
//     6     6
//     7     7
//     8     8
//     9     4
//    10     5
//    11     6
//    12     7
//    13     8
//    14     4
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 August 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int IVAL, an integer value.
//
//    Input, int ILO, IHI, the desired bounds for the integer value.
//
//    Output, int I4_WRAP, a "wrapped" version of IVAL.
//
{
  int jhi;
  int jlo;
  int value;
  int wide;

  jlo = i4_min ( ilo, ihi );
  jhi = i4_max ( ilo, ihi );

  wide = jhi + 1 - jlo;

  if ( wide == 1 )
  {
    value = jlo;
  }
  else
  {
    value = jlo + i4_modp ( ival - jlo, wide );
  }

  return value;
}
//****************************************************************************80

void jed_to_weekday ( double jed, int *w, double *f )

//****************************************************************************80
//
//  Purpose:
//
//    JED_TO_WEEKDAY computes the day of the week from a JED.
//
//  Discussion:
//
//    BC 4713/01/01 => JED = 0.0 was noon on a Monday.
//
//    jedmod = mod ( 0.0, 7.0 ) = 0.0
//    j = mod ( nint ( 0 ), 7 ) = 0
//    f = ( 0.0 + 0.5 ) - real ( j ) = 0.5
//    w = i4_wrap ( 0 + 2, 1, 7 ) = 2 = MONDAY
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 November 2002
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Edward Richards,
//    Mapping Time, The Calendar and Its History,
//    Oxford, 1999.
//
//  Parameters:
//
//    Input, double JED, the Julian Ephemeris Date.
//
//    Output, int W, the day of the week of the date.
//    The days are numbered from Sunday through Saturday, 1 through 7.
//
//    Output, double F, the fractional part of the day.
//
{
  int j;
  double jedmod;

  jedmod = r8_mod ( jed, 7.0 );

  j = ( r8_nint ( jedmod ) % 7 );

  *f = ( jedmod + 0.5 ) - ( double ) ( j );

  *w = i4_wrap ( j + 2, 1, 7 );

  return;
}
//****************************************************************************80

void jed_to_weekday_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_TO_WEEKDAY_TEST tests JED_TO_WEEKDAY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2017
//
//  Author:
//
//    John Burkardt
//
{
  double f;
  double jed;
  int n_data;
  int w;
  int w2;

  cout << "\n";
  cout << "JED_TO_WEEKDAY_TEST\n";
  cout << "  JED_TO_WEEKDAY determines the weekday\n";
  cout << "  corresponding to a JED:\n";
  cout << "\n";
  cout << "             JED  W     W\n";
  cout << "                  True  Computed\n";
  cout << "\n";

  for ( ; ; )
  {
    jed_weekday_values ( n_data, jed, w );

    if ( n_data == 0 )
    {
      break;
    }

    jed_to_weekday ( jed, &w2, &f );

    cout << "  " << setw(14) << jed
         << "  " << setw(4) << w
         << "  " << setw(8) << w2
         << "  " << setw(8) << f << "\n";
  }
  return;
}
//****************************************************************************80

void jed_weekday_values ( int &n_data, double &jed, int &weekday )

//****************************************************************************80
//
//  Purpose:
//
//    JED_WEEKDAY_VALUES returns the day of the week for Julian Ephemeris Dates.
//
//  Discussion:
//
//    The JED (Julian Ephemeris Date) is a calendrical system which counts days,
//    starting from noon on 1 January 4713 BCE.
//
//    Weekdays are numbered as follows:
//
//    1  Sunday
//    2  Monday
//    3  Tuesday
//    4  Wednesday
//    5  Thursday
//    6  Friday
//    7  Saturday
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2004
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Edward Reingold and Nachum Dershowitz,
//    Calendrical Calculations: The Millennium Edition,
//    Cambridge University Press, 2001,
//    ISBN: 0 521 77752 6
//
//  Parameters:
//
//    Input/output, int &N_DATA.  The user sets N_DATA to 0 before the
//    first call.  On each call, the routine increments N_DATA by 1, and
//    returns the corresponding data; when there is no more data, the
//    output value of N_DATA will be 0 again.
//
//    Output, double &JED, the Julian Ephemeris Date.
//
//    Output, int &WEEKDAY, the day of the week.
//
{
# define N_MAX 33

  static double jed_vec[N_MAX] = {
    1507231.5E+00,
    1660037.5E+00,
    1746893.5E+00,
    1770641.5E+00,
    1892731.5E+00,
    1931579.5E+00,
    1974851.5E+00,
    2091164.5E+00,
    2121509.5E+00,
    2155779.5E+00,
    2174029.5E+00,
    2191584.5E+00,
    2195261.5E+00,
    2229274.5E+00,
    2245580.5E+00,
    2266100.5E+00,
    2288542.5E+00,
    2290901.5E+00,
    2323140.5E+00,
    2334848.5E+00,
    2348020.5E+00,
    2366978.5E+00,
    2385648.5E+00,
    2392825.5E+00,
    2416223.5E+00,
    2425848.5E+00,
    2430266.5E+00,
    2430833.5E+00,
    2431004.5E+00,
    2448698.5E+00,
    2450138.5E+00,
    2465737.5E+00,
    2486076.5E+00 };

  static int weekday_vec[N_MAX] = {
    1, 4, 4, 1, 4,
    2, 7, 1, 1, 6,
    7, 6, 1, 1, 4,
    7, 7, 7, 4, 1,
    6, 1, 2, 4, 1,
    1, 2, 2, 5, 3,
    1, 4, 1 };

  if ( n_data < 0 )
  {
    n_data = 0;
  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )
  {
    n_data = 0;
    jed = 0.0;
    weekday = 0;
  }
  else
  {
    jed = jed_vec[n_data-1];
    weekday = weekday_vec[n_data-1];
  }

  return;
# undef N_MAX
}
//****************************************************************************80

double r8_mod ( double x, double y )

//****************************************************************************80
//
//  Purpose:
//
//    R8_MOD returns the remainder of R8 division.
//
//  Discussion:
//
//    If
//      REM = R8_MOD ( X, Y )
//      RMULT = ( X - REM ) / Y
//    then
//      X = Y * RMULT + REM
//    where REM has the same sign as X, and abs ( REM ) < Y.
//
//  Example:
//
//        X         Y     R8_MOD   R8_MOD  Factorization
//
//      107        50       7     107 =  2 *  50 + 7
//      107       -50       7     107 = -2 * -50 + 7
//     -107        50      -7    -107 = -2 *  50 - 7
//     -107       -50      -7    -107 =  2 * -50 - 7
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
//  Parameters:
//
//    Input, double X, the number to be divided.
//
//    Input, double Y, the number that divides X.
//
//    Output, double R8_MOD, the remainder when X is divided by Y.
//
{
  double value;

  if ( y == 0.0 )
  {
    cerr << "\n";
    cerr << "R8_MOD - Fatal error!\n";
    cerr << "  R8_MOD ( X, Y ) called with Y = " << y << "\n";
    exit ( 1 );
  }

  value = x - ( ( double ) ( ( int ) ( x / y ) ) ) * y;

  if ( x < 0.0 && 0.0 < value )
  {
    value = value - fabs ( y );
  }
  else if ( 0.0 < x && value < 0.0 )
  {
    value = value + fabs ( y );
  }

  return value;
}
//****************************************************************************80

int r8_nint ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_NINT returns the nearest integer to an R8.
//
//  Example:
//
//        X         Value
//
//      1.3         1
//      1.4         1
//      1.5         1 or 2
//      1.6         2
//      0.0         0
//     -0.7        -1
//     -1.1        -1
//     -1.6        -2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the value.
//
//    Output, int R8_NINT, the nearest integer to X.
//
{
  int value;

  if ( x < 0.0 )
  {
    value = - ( int ) ( fabs ( x ) + 0.5 );
  }
  else
  {
    value =   ( int ) ( fabs ( x ) + 0.5 );
  }

  return value;
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
//  Parameters:
//
//    None
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

string weekday_to_name_common ( int w )

//****************************************************************************80
//
//  Purpose:
//
//    WEEKDAY_TO_NAME_COMMON returns the name of a Common weekday.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int W, the weekday index.
//
//    Output, string WEEKDAY_TO_NAME_COMMON, the weekday name.
//
{
  string s;
  static string weekday_list[7] = { 
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", 
    "Friday", "Saturday" };

  if ( 1 <= w && w <= 7 )
  {
    s = weekday_list[w-1];
    return s;
  }
  else
  {
    cerr << "\n";
    cerr << "WEEKDAY_TO_NAME_COMMON\n";
    cerr << "  Illegal weekday.\n";
    exit ( 1 );
  }
}
//****************************************************************************80

void weekday_values ( int &n_data, int &y, int &m, int &d, int &w )

//****************************************************************************80
//
//  Purpose:
//
//    WEEKDAY_VALUES returns the day of the week for various dates.
//
//  Discussion:
//
//    The CE or Common Era calendar is used, under the
//    hybrid Julian/Gregorian Calendar, with a transition from Julian
//    to Gregorian.  The day after 04 October 1582 was 15 October 1582.
//
//    The year before 1 AD or CE is 1 BC or BCE.  In this data set,
//    years BC/BCE are indicated by a negative year value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 May 2012
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Edward Reingold, Nachum Dershowitz,
//    Calendrical Calculations: The Millennium Edition,
//    Cambridge University Press, 2001,
//    ISBN: 0 521 77752 6
//    LC: CE12.R45.
//
//  Parameters:
//
//    Input/output, int &N_DATA.  The user sets N_DATA to 0
//    before the first call.  On each call, the routine increments N_DATA by 1,
//    and returns the corresponding data; when there is no more data, the
//    output value of N_DATA will be 0 again.
//
//    Output, int &Y, &M, &D, the Common Era date.
//
//    Output, int &W, the day of the week.  Sunday = 1.
//
{
# define N_MAX 34

  static int d_vec[N_MAX] = {
    30,
     8,
    26,
     3,
     7,
    18,
     7,
    19,
    14,
    18,
    16,
     3,
    26,
    20,
     4,
    25,
    31,
     9,
    24,
    10,
    30,
    24,
    19,
     2,
    27,
    19,
    25,
    29,
    19,
     7,
    17,
    25,
    10,
    18 };
  static int m_vec[N_MAX] = {
     7,
    12,
     9,
    10,
     1,
     5,
    11,
     4,
    10,
     5,
     3,
     3,
     3,
     4,
     6,
     1,
     3,
     9,
     2,
     6,
     6,
     7,
     6,
     8,
     3,
     4,
     8,
     9,
     4,
    10,
     3,
     2,
    11,
     7 };
  static int w_vec[N_MAX] = {
    1,
    4,
    4,
    1,
    4,
    2,
    7,
    1,
    7,
    1,
    6,
    7,
    6,
    1,
    1,
    4,
    7,
    7,
    7,
    4,
    1,
    6,
    1,
    2,
    4,
    1,
    1,
    2,
    2,
    5,
    3,
    1,
    4,
    1 };
  static int y_vec[N_MAX] = {
    - 587,
    - 169,
       70,
      135,
      470,
      576,
      694,
     1013,
     1066,
     1096,
     1190,
     1240,
     1288,
     1298,
     1391,
     1436,
     1492,
     1553,
     1560,
     1648,
     1680,
     1716,
     1768,
     1819,
     1839,
     1903,
     1929,
     1941,
     1943,
     1943,
     1992,
     1996,
     2038,
     2094 };

  if ( n_data < 0 )
  {
    n_data = 0;
  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )
  {
    n_data = 0;
    y = 0;
    m = 0;
    d = 0;
    w = 0;
  }
  else
  {
    y = y_vec[n_data-1];
    m = m_vec[n_data-1];
    d = d_vec[n_data-1];
    w = w_vec[n_data-1];
  }

  return;
# undef N_MAX
}
//****************************************************************************80

int y_common_to_astronomical ( int y )

//****************************************************************************80
//
//  Purpose:
//
//    Y_COMMON_TO_ASTRONOMICAL converts a Common year to an Astronomical year.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int Y, the Common year.
//
//    Output, int Y_COMMON_TO_ASTRONOMICAL, the Astronomical year.
//
{
  int y2;

  if ( y < 0 )
  {
    y2 = y + 1;
  }
  else if ( y == 0 )
  {
    cerr << "\n";
    cerr << "Y_COMMON_TO_ASTRONOMICAL - Fatal error!\n";
    cerr << "  Common calendar does not have a year 0.\n";
    exit ( 1 );
  }
  else
  {
    y2 = y;
  }

  return y2;
}
//****************************************************************************80

string ymd_to_s_common ( int y, int m, int d )

//****************************************************************************80
//
//  Purpose:
//
//    YMD_TO_S_COMMON writes a Common YMD date into a string.
//
//  Format:
//
//    CE YYYY/MM/DD
//    BCE YYYY/MM/DD
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int Y, M, D, the YMD date.
//
//    Output, string YMD_TO_S_COMMON, a representation of the date.
//
{
  char char_vec[14];
  string s;

  if ( y < 0 )
  {
    sprintf ( char_vec, "BCE %d/%02d/%02d", - y, m, d );
  }
  else
  {
    sprintf ( char_vec, "CE %d/%02d/%02d", y, m, d );
  }
  s = string ( char_vec );

  return s;
}
//****************************************************************************80

int ymd_to_weekday_common ( int y, int m, int d )

//****************************************************************************80
//
//  Purpose:
//
//    YMD_TO_WEEKDAY_COMMON returns the weekday of a Common YMD date.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int Y, int M, int D, the YMD date.
//
//    Output, int W, is the week day number of the date, with
//    1 for Sunday, through 7 for Saturday.
//
{
  double f1;
  double f2;
  double jed;
  int w;

  f1 = 0.5;
  jed = ymdf_to_jed_common ( y, m, d, f1 );

  jed_to_weekday ( jed, &w, &f2 );

  return w;
}
//****************************************************************************80

void ymd_to_weekday_common_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    YMD_TO_WEEKDAY_COMMON_TEST tests YMD_TO_WEEKDAY_COMMON.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 July 2017
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int m;
  int n_data;
  string s1;
  string s2;
  string s3;
  int w1;
  int w2;
  int y;

  cout << "\n";
  cout << "YMD_TO_WEEKDAY_COMMON_TEST\n";
  cout << "  YMD_TO_WEEKDAY_COMMON returns the day of the week\n";
  cout << "  for dates in the Common calendar.\n";
  cout << "\n";
  cout << "  YMD                   Weekday    Weekday\n";
  cout << "                        Tabulated  Computed\n";
  cout << "\n";

  for ( ; ; )
  {
    weekday_values ( n_data, y, m, d, w1 );

    if ( n_data == 0 )
    {
      break;
    }

    s3 = ymd_to_s_common ( y, m, d );
    w2 = ymd_to_weekday_common ( y, m, d );
    s1 = weekday_to_name_common ( w1 );
    s2 = weekday_to_name_common ( w2 );

    cout << "  " << setw(20) << s3
         << "  " << setw(9)  << s1
         << "  " << setw(9)  << s2 << "\n";
  }
  return;
}
//****************************************************************************80

int ymd_to_weekday_english ( int y, int m, int d )

//****************************************************************************80
//
//  Purpose:
//
//    YMD_TO_WEEKDAY_ENGLISH returns the weekday of an English YMD date.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int Y, int M, int D, the YMD date.
//
//    Output, int W, is the week day number of the date, with
//    1 for Sunday, through 7 for Saturday.
//
{
  double f1;
  double f2;
  double jed;
  int w;

  f1 = 0.5;

  jed = ymdf_to_jed_english ( y, m, d, f1 );

  jed_to_weekday ( jed, &w, &f2 );

  return w;
}
//****************************************************************************80

int ymd_to_weekday_gregorian ( int y, int m, int d )

//****************************************************************************80
//
//  Purpose:
//
//    YMD_TO_WEEKDAY_GREGORIAN returns the weekday of a Gregorian YMD date.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int Y, int M, int D, the YMD date.
//
//    Output, int W, is the week day number of the date, with
//    1 for Sunday, through 7 for Saturday.
//
{
  double f1;
  double f2;
  double jed;
  int w;

  f1 = 0.5;

  jed = ymdf_to_jed_gregorian ( y, m, d, f1 );

  jed_to_weekday ( jed, &w, &f2 );

  return w;
}
//****************************************************************************80

char ymdf_compare ( int y1, int m1, int d1, double f1, int y2, int m2, int d2, 
  double f2 )

//****************************************************************************80
//
//  Purpose:
//
//    YMDF_COMPARE compares two YMDF dates.
//
//  Discussion:
//
//    The comparison should work for a pair of dates in any calendar.
//
//    No check is made that the dates are actually legitimate.  It is
//    assumed that the calling routine has already ensured that the
//    dates are properly "normalized".
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int Y1, int M1, int D1, double F1, the 
//    first YMDF date.
//
//    Input, int Y2, int M2, int D2, double F2, the 
//    second YMDF date.
//
//    Output, char YMDF_COMPARE:
//    '<' if date 1 precedes date 2;
//    '=' if date 1 equals date 2;
//    '>' if date 1 follows date 2;
//
{
  char cmp;

  cmp = '?';

  if ( y1 < y2 )
  {
    cmp = '<';
  }
  else if ( y1 > y2 )
  {
    cmp = '>';
  }
  else
  {
    if ( m1 < m2 )
    {
      cmp = '<';
    }
    else if ( m1 > m2 )
    {
      cmp = '>';
    }
    else
    {
      if ( d1 < d2 )
      {
        cmp = '<';
      }
      else if ( d1 > d2 )
      {
        cmp = '>';
      }
      else
      {
        if ( f1 < f2 )
        {
          cmp = '<';
        }
        else if ( f1 > f2 )
        {
          cmp = '>';
        }
        else
        {
          cmp = '=';
        }
      }
    }
  }
  return cmp;
}
//****************************************************************************80

double ymdf_to_jed_common ( int y, int m, int d, double f )

//****************************************************************************80
//
//  Purpose:
//
//    YMDF_TO_JED_COMMON converts a Common YMDF date to a JED.
//
//  Discussion:
//
//    The "common" calendar is meant to be the calendar which is Julian up to
//    day JED = 2299160, and Gregorian from day JED = 2299161 and after.
//
//    The Julian Ephemeris Date is essentially a count of the number
//    of days that have elapsed since noon, 1 January 4713 BC, at
//    Greenwich, England.  Strictly speaking, the Julian Ephemeris Date
//    is counted from noon, and thus day "0" began at noon on 1 January 4713 BC,
//    and ended at noon on 2 January 4713 BC.
//
//    The Julian Ephemeris Date was devised by Joseph Scaliger in 1583.
//
//    The Julian Ephemeris Date has been adopted by astronomers as
//    a convenient reference for dates.
//
//  Example:
//
//       Y   M     D         JED
//    --------------     -------
//    BC 4713 Jan  1           0
//    AD 1968 May 23     2440000
//    AD 1984 Dec 31     2446065
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int Y, M, D, double F, the YMDF date.
//
//    Output, double YMDF_TO_JED_COMMON, the Julian Ephemeris Date.
//
{
  char cmp;
  int d1;
  int d2;
  double f1;
  double f2;
  double jed;
  int m1;
  int m2;
  int y1;
  int y2;
//
//  Copy the month and year.
//
  y1 = y;
  m1 = m;
  d1 = d;
  f1 = f;

  y2 = 1582;
  m2 = 10;
  d2 = 4+1;
  f2 = 0.0;

  cmp = ymdf_compare ( y1, m1, d1, f1, y2, m2, d2, f2 );

  if ( cmp == '<' )
  {
    jed = ymdf_to_jed_julian ( y1, m1, d1, f1 );
    return jed;
  }
//
//  Use the Gregorian calendar for dates strictly after 1752/9/13.
//
  y2 = 1582;
  m2 = 10;
  d2 = 15-1;
  f2 = 0.0;

  cmp = ymdf_compare ( y1, m1, d1, f1, y2, m2, d2, f2 );

  if ( cmp == '>' )
  {
    jed = ymdf_to_jed_gregorian ( y1, m1, d1, f1 );
    return jed;
  }

  cerr << "\n";
  cerr << " 'YMDF_TO_JED_COMMON - Fatal error!\n";
  cerr << "  Illegal date!\n";
  exit ( 1 );
}
//****************************************************************************80

double ymdf_to_jed_english ( int y, int m, int d, double f )

//****************************************************************************80
//
//  Purpose:
//
//    YMDF_TO_JED_ENGLISH converts an English YMDF date to a JED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int Y, int M, int D, double F, the YMDF date.
//
//    Output, double JED, the Julian Ephemeris Date.
//
{
  char cmp;
  int d1;
  int d2;
  double f1;
  double f2;
  double jed;
  int m1;
  int m2;
  int y1;
  int y2;
//
//  Use the Julian Calendar for dates strictly before 1752/9/3.
//
  y1 = 1752;
  m1 = 9;
  d1 = 3;
  f1 = 0.0;

  cmp = ymdf_compare ( y, m, d, f, y1, m1, d1, f1 );

  if ( cmp == '<' )
  {
    jed = ymdf_to_jed_julian ( y, m, d, f );
    return jed;
  }
//
//  Use the Gregorian calendar for dates strictly after 1752/9/13.
//
  y2 = 1752;
  m2 = 9;
  d2 = 13;
  f2 = 0.0;

  cmp = ymdf_compare ( y, m, d, f, y2, m2, d2, f2 );

  if ( cmp == '>' )
  {
    jed = ymdf_to_jed_gregorian ( y, m, d, f );
    return jed;
  }
//
//  Error return if the date falls between the transition dates.
//
  cerr << "\n";
  cerr << "YMDF_TO_JED_ENGLISH - Fatal error!\n";
  cerr << "  Date is illegal.\n";
  exit ( 1 );
}
//****************************************************************************80

double ymdf_to_jed_gregorian ( int y, int m, int d, double f )

//****************************************************************************80
//
//  Purpose:
//
//    YMDF_TO_JED_GREGORIAN converts a Gregorian YMDF date to a JED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 January 2009
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Edward Richards,
//    Algorithm E,
//    Mapping Time, The Calendar and Its History,
//    Oxford, 1999, pages 323-324.
//
//  Parameters:
//
//    Input, int Y, int M, int D, double F, the YMDF date.
//
//    Output, double YMDF_TO_JED_GREGORIAN, the corresponding JED.
//
{
  int d_prime;
  int g;
  double jed;
  int j1;
  int j2;
  int m_prime;
  int y_prime;
//
//  Account for the missing year 0 by moving negative years up one.
//
  y = y_common_to_astronomical ( y );
//
//  Convert the calendar date to a computational date.
//
  y_prime = y + 4716 - ( 14 - m ) / 12;
  m_prime = ( ( m + 9 ) % 12 );
  d_prime = d - 1;
//
//  Convert the computational date to a JED.
//
  j1 = ( 1461 * y_prime ) / 4;

  j2 = ( 153 * m_prime + 2 ) / 5;

  g = ( 3 * ( ( y_prime + 184 ) / 100 ) / 4 ) - 38;

  jed = ( double ) ( j1 + j2 + d_prime - 1401 - g ) - 0.5;
  jed = jed + f;

  return jed;
}
//****************************************************************************80

double ymdf_to_jed_julian ( int y, int m, int d, double f )

//****************************************************************************80
//
//  Purpose:
//
//    YMDF_TO_JED_JULIAN converts a Julian YMDF date to a JED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 March 2010
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Edward Richards,
//    Algorithm E,
//    Mapping Time, The Calendar and Its History,
//    Oxford, 1999, pages 323-324.
//
//  Parameters:
//
//    Input, int Y, int M, int D, double F, the YMDF date.
//
//    Output, double YMDF_TO_JED_JULIAN, the Julian Ephemeris Date.
//
{
  int d_prime;
  double jed;
  int j1;
  int j2;
  int m_prime;
  int y_prime;
//
//  Account for the missing year 0 by moving negative years up one.
//
  y = y_common_to_astronomical ( y );
//
//  Convert the calendar date to a computational date.
//
  y_prime = y + 4716 - ( 14 - m ) / 12;
  m_prime = ( ( m + 9 ) % 12 );
  d_prime = d - 1;
//
//  Convert the computational date to a JED.
//
  j1 = ( 1461 * y_prime ) / 4;

  j2 = ( 153 * m_prime + 2 ) / 5;

  jed = ( double ) ( j1 + j2 + d_prime - 1401 ) - 0.5;
  jed = jed + f;

  return jed;
}
