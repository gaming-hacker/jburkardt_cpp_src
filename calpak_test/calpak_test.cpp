# include <cmath>
# include <cstdlib>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "calpak.hpp"

int main ( );
void ch_cap_test ( );
void datenum_to_jed_test ( );
void datenum_values_test ( );
void day_list_common_test ( );
void easter_gregorian_ds_test ( );
void easter_gregorian_egr_test ( );
void easter_gregorian_egr2_test ( );
void easter_gregorian_knuth_test ( );
void easter_gregorian_stewart_test ( );
void easter_julian_egr_test ( );
void easter_julian_egr2_test ( );
void gps_to_jed_test ( );
void i4_modp_test ( );
void i4_normal_ab_test ( );
void i4_uniform_ab_test ( );
void i4_wrap_test ( );
void jed_ce_values_test ( );
void jed_is_legal_test ( );
void jed_mjd_values_test ( );
void jed_rd_values_test ( );
void jed_to_datenum_test ( );
void jed_to_gps_test ( );
void jed_to_noon_nearest_test ( );
void jed_to_noon_next_test ( );
void jed_to_weekday_test ( );
void jed_weekday_values_test ( );
void month_to_month_name_common_test ( );
void month_to_month_name_common3_test ( );
void r8_mod_test ( );
void r8_nint_test ( );
void r8_uniform_01_test ( );
void r8_uniform_ab_test ( );
void weekday_to_name_common_test ( );
void weekday_to_name_common2_test ( );
void weekday_to_name_common3_test ( );
void weekday_values_test ( );
void y_to_s_common_test ( );
void year_length_days_common_test ( );
void year_to_golden_number_test ( );
void ymd_to_decimal_test ( );
void ymd_to_weekday_common_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for CALPAK_TEST.
//
//  Discussion:
//
//    CALPAK_TEST tests the CALPAK library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 January 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "CALPAK_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the CALPAK library.\n";

  ch_cap_test ( );
  datenum_to_jed_test ( );
  datenum_values_test ( );
  day_list_common_test ( );
  easter_gregorian_ds_test ( );
  easter_gregorian_egr_test ( );
  easter_gregorian_egr2_test ( );
  easter_gregorian_knuth_test ( );
  easter_gregorian_stewart_test ( );
  easter_julian_egr_test ( );
  easter_julian_egr2_test ( );
  gps_to_jed_test ( );
  i4_modp_test ( );
  i4_normal_ab_test ( );
  i4_uniform_ab_test ( );
  i4_wrap_test ( );
  jed_ce_values_test ( );
  jed_is_legal_test ( );
  jed_mjd_values_test ( );
  jed_rd_values_test ( );
  jed_to_datenum_test ( );
  jed_to_gps_test ( );
  jed_to_noon_nearest_test ( );
  jed_to_noon_next_test ( );
  jed_to_weekday_test ( );
  jed_weekday_values_test ( );
  month_to_month_name_common_test ( );
  month_to_month_name_common3_test ( );
  r8_mod_test ( );
  r8_nint_test ( );
  r8_uniform_01_test ( );
  r8_uniform_ab_test ( );
  weekday_to_name_common_test ( );
  weekday_to_name_common2_test ( );
  weekday_to_name_common3_test ( );
  weekday_values_test ( );
  y_to_s_common_test ( );
  year_length_days_common_test ( );
  year_to_golden_number_test ( );
  ymd_to_decimal_test ( );
  ymd_to_weekday_common_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "CALPAK_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
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

void datenum_to_jed_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DATENUM_TO_JED_TEST tests DATENUM_TO_JED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  double date_num;
  int i;
  double jed1;
  double jed3;
  double jed_epoch;

  cout << "\n";
  cout << "DATENUM_TO_JED_TEST\n";
  cout << "  DATENUM_TO_JED: Matlab DATENUM -> JED.\n";
  cout << "\n";
  cout << "  JED (in)    DATENUM             JED (out)\n";
  cout << "\n";

  jed_epoch = epoch_to_jed_datenum ( );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    if ( jed_epoch <= jed1 )
    {
      date_num = jed_to_datenum ( jed1 );
      jed3 = datenum_to_jed ( date_num );

      cout << "  " << setw(11) << jed1
           << "  " << setw(11) << date_num
           << "  " << setw(11) << jed3 << "\n";
    }
  }

  return;
}
//****************************************************************************80

void datenum_values_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DATENUM_VALUES_TEST tests DATENUM_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  double date_num;
  int m;
  int n_data;
  int y;

  cout << "\n";
  cout << "DATENUM_VALUES_TEST:\n";
  cout << "  DATENUM_VALUES returns values of \n";
  cout << "  the MATLAB datenum for a given Y/M/D date.\n";
  cout << "\n";
  cout << "     Y     M     D  DATENUM\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    datenum_values ( n_data, y, m, d, date_num );

    if ( n_data == 0 )
    {
      break;
    }
    cout << "  " << setw(4) << y
         << "  " << setw(4) << m
         << "  " << setw(4) << d 
         << "  " << setw(11) << date_num << "\n";
  }
  return;
}
//****************************************************************************80

void day_list_common_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DAY_LIST_COMMON_TEST tests DAY_LIST_COMMON.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    24 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int d1;
  int d2;
  int m1;
  int m2;
  string s;
  int y1;
  int y2;

  d1 = 1;
  d2 = 31;
  m1 = 9;
  m2 = 12;
  y1 = 2012;
  y2 = 2012;

  cout << "\n";
  cout << "DAY_LIST_COMMON_TEST\n";
  cout << "  DAY_LIST_COMMON prints a list of days between\n";
  cout << "  two given YMD dates in the common calendar.\n";
  cout << "\n";

  s = ymd_to_s_common ( y1, m1, d1 );
  cout << "  Initial date: " << s << "\n";
  s = ymd_to_s_common ( y2, m2, d2 );
  cout << "  Final date:   " << s << "\n";
  cout << "\n";

  day_list_common ( y1, m1, d1, y2, m2, d2 );

  return;
}
//****************************************************************************80

void easter_gregorian_ds_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EASTER_GREGORIAN_DS_TEST tests EASTER_GREGORIAN_DS.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    24 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  string s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  cout << "\n";
  cout << "EASTER_GREGORIAN_DS_TEST\n";
  cout << "  For the Gregorian calendar,\n";
  cout << "  for a given year, compute the day and month of Easter.\n";
  cout << "  EASTER_GREGORIAN_DS uses Duffett-Smith''s algorithm.\n";
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    cout << "\n";
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  CORRECT:  " << s << "\n";

    easter_gregorian_ds ( y, m, d );
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  COMPUTED: " << s << "\n";
  }

  return;
}
//****************************************************************************80

void easter_gregorian_egr_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EASTER_GREGORIAN_EGR_TEST tests EASTER_GREGORIAN_EGR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    24 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  string s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  cout << "\n";
  cout << "EASTER_GREGORIAN_EGR_TEST\n";
  cout << "  For the Gregorian calendar,\n";
  cout << "  for a given year, compute the day and month of Easter.\n";
  cout << "  EASTER_GREGORIAN_EGR uses Richard's algorithm #1.\n";
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    cout << "\n";
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  CORRECT:  " << s << "\n";

    easter_gregorian_egr ( y, m, d );
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  COMPUTED: " << s << "\n";
  }

  return;
}
//****************************************************************************80

void easter_gregorian_egr2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EASTER_GREGORIAN_EGR2_TEST tests EASTER_GREGORIAN_EGR2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    02 January 2018
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  string s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  cout << "\n";
  cout << "EASTER_GREGORIAN_EGR2_TEST\n";
  cout << "  For the Gregorian calendar,\n";
  cout << "  for a given year, compute the day and month of Easter.\n";
  cout << "  EASTER_GREGORIAN_EGR2 uses Richard's algorithm #2.\n";
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    cout << "\n";
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  CORRECT:  " << s << "\n";

    easter_gregorian_egr2 ( y, m, d );
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  COMPUTED: " << s << "\n";
  }

  return;
}
//****************************************************************************80

void easter_gregorian_knuth_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EASTER_GREGORIAN_KNUTH_TEST tests EASTER_GREGORIAN_KNUTH.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    02 January 2018
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  string s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  cout << "\n";
  cout << "EASTER_GREGORIAN_KNUTH_TEST\n";
  cout << "  For the Gregorian calendar,\n";
  cout << "  for a given year, compute the day and month of Easter.\n";
  cout << "  EASTER_GREGORIAN_KNUTH uses Knuth's algorithm.\n";
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    cout << "\n";
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  CORRECT:  " << s << "\n";

    easter_gregorian_knuth ( y, m, d );
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  COMPUTED: " << s << "\n";
  }

  return;
}
//****************************************************************************80

void easter_gregorian_stewart_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EASTER_GREGORIAN_STEWART_TEST tests EASTER_GREGORIAN_STEWART.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    02 January 2018
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int d_test[10] = {
    30,    12,    4,  23,   15,   31,   20,   11,   27,   16 };
  int i;
  int m;
  int m_test[10] = {
    3,     4,    4,    4,    4,    3,    4,    4,    3,    4 };
  const int ntest = 10;
  string s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  cout << "\n";
  cout << "EASTER_GREGORIAN_STEWART_TEST\n";
  cout << "  For the Gregorian calendar,\n";
  cout << "  for a given year, compute the day and month of Easter.\n";
  cout << "  EASTER_GREGORIAN_STEWART uses Stewart's algorithm.\n";
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];

    cout << "\n";
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  CORRECT:  " << s << "\n";

    easter_gregorian_stewart ( y, m, d );
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  COMPUTED: " << s << "\n";
  }

  return;
}
//****************************************************************************80

void easter_julian_egr_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EASTER_JULIAN_EGR_TEST tests EASTER_JULIAN_EGR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 January 2018
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int d_test[10] = {
    27,    19,   11,  30,   15,    5,   27,   11,    1,   23 };
  double f;
  int i;
  double jed;
  int m;
  int m_test[10] = {
    4,     4,    4,    4,    4,    5,    4,    4,    5,    4 };
  const int ntest = 10;
  string s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  cout << "\n";
  cout << "EASTER_JULIAN_EGR_TEST\n";
  cout << "  For the Julian calendar,\n";
  cout << "  for a given year, compute the day and month of Easter.\n";
  cout << "  EASTER_JULIAN_EGR uses Richards''s algorithm #1.\n";
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];
    f = 0.5;

    cout << "\n";
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  CORRECT (Gregorian): " << s << "\n";

    jed = ymdf_to_jed_gregorian ( y, m, d, f );
    jed_to_ymdf_julian ( jed, y, m, d, f );

    s = ymd_to_s_julian ( y, m, d );
    cout << "  CORRECT (Julian):    " << s << "\n";

    easter_julian_egr ( y, m, d );
    s = ymd_to_s_julian ( y, m, d );
    cout << "  COMPUTED             " << s << "\n";
  }

  return;
}
//****************************************************************************80

void easter_julian_egr2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EASTER_JULIAN_EGR2_TEST tests EASTER_JULIAN_EGR2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 January 2018
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int d_test[10] = {
    27,    19,   11,  30,   15,    5,   27,   11,    1,   23 };
  double f;
  int i;
  double jed;
  int m;
  int m_test[10] = {
    4,     4,    4,    4,    4,    5,    4,    4,    5,    4 };
  const int ntest = 10;
  string s;
  int y;
  int y_test[10] = { 
    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006 };

  cout << "\n";
  cout << "EASTER_JULIAN_EGR2_TEST\n";
  cout << "  For the Julian calendar,\n";
  cout << "  for a given year, compute the day and month of Easter.\n";
  cout << "  EASTER_JULIAN_EGR2 uses Richards''s algorithm #2.\n";
 
  for ( i = 0; i < ntest; i++ )
  {
    y = y_test[i];
    m = m_test[i];
    d = d_test[i];
    f = 0.5;

    cout << "\n";
    s = ymd_to_s_gregorian ( y, m, d );
    cout << "  CORRECT (Gregorian): " << s << "\n";

    jed = ymdf_to_jed_gregorian ( y, m, d, f );
    jed_to_ymdf_julian ( jed, y, m, d, f );

    s = ymd_to_s_julian ( y, m, d );
    cout << "  CORRECT (Julian):    " << s << "\n";

    easter_julian_egr2 ( y, m, d );
    s = ymd_to_s_julian ( y, m, d );
    cout << "  COMPUTED             " << s << "\n";
  }

  return;
}
//****************************************************************************80

void gps_to_jed_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    GPS_TO_JED_TEST tests GPS_TO_JED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int c2;
  int i;
  double jed_epoch;
  double jed1;
  double jed3;
  double sec2;
  int w2;

  cout << "\n";
  cout << "GPS_TO_JED_TEST\n";
  cout << "  GPS_TO_JED: GPS -> JED.\n";
  cout << "\n";
  cout << "   JED (in)       GPS (C/W/S)                   JED (out)\n";
  cout << "\n";

  jed_epoch = epoch_to_jed_gps ( );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    if ( jed_epoch <= jed1 )
    {
      jed_to_gps ( jed1, c2, w2, sec2 );

      jed3 = gps_to_jed ( c2, w2, sec2 );

      cout << "  " << setw(11) << jed1
           << "  " << c2 << "/" << w2 << "/" << sec2 << " (GPS)"
           << "  " << setw(11) << jed3 << "\n";
    }
  }

  return;
}
//****************************************************************************80

void i4_modp_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MODP_TEST tests I4_MODP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define TEST_NUM 4

  int ndivid[TEST_NUM] = { 50, -50, 50, -50 };
  int nmult;
  int nrem;
  int number[TEST_NUM] = { 107, 107, -107, -107 };
  int test;

  cout << "\n";
  cout << "I4_MODP_TEST\n";
  cout << "  I4_MODP factors a number\n";
  cout << "  into a multiple and a remainder.\n";
  cout << "\n";
  cout << "    Number   Divisor  Multiple Remainder\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  {
    nrem = i4_modp ( number[test], ndivid[test] );
    nmult = number[test] / ndivid[test];

    cout << "  " << setw(10) << number[test]
         << "  " << setw(10) << ndivid[test]
         << "  " << setw(10) << nmult
         << "  " << setw(10) << nrem << "\n";
  }

  cout << "\n";
  cout << "  Repeat using C++ percent operator:\n";
  cout << "\n";

  for ( test = 0; test < TEST_NUM; test++ )
  {
    nrem = ( number[test] % ndivid[test] );
    nmult = number[test] / ndivid[test];

    cout << "  " << setw(10) << number[test]
         << "  " << setw(10) << ndivid[test]
         << "  " << setw(10) << nmult
         << "  " << setw(10) << nrem << "\n";
  }

  return;
# undef TEST_NUM
}
//****************************************************************************80

void i4_normal_ab_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_NORMAL_AB_TEST tests I4_NORMAL_AB.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double mu;
  int r;
  int seed;
  double sigma;

  cout << "\n";
  cout << "I4_NORMAL_AB_TEST\n";
  cout << "  I4_NORMAL_AB computes pseudonormal integer values\n";
  cout << "  with mean MU and standard deviation SIGMA.\n";

  mu = 70.0;
  sigma = 10.0;
  seed = 123456789;

  cout << "\n";
  cout << "  The mean = " << mu << "\n";
  cout << "  The standard deviation = " << sigma << "\n";
  cout << "  SEED = " << seed << "\n";
  cout << "\n";

  for ( i = 1; i <= 10; i++ )
  {
    r = i4_normal_ab ( mu, sigma, seed );
    cout << "  " << setw(8) << i
         << "  " << setw(8) << r << "\n";
  }

  return;
}
//****************************************************************************80

void i4_uniform_ab_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_UNIFORM_AB_TEST tests I4_UNIFORM_AB.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 October 2014
//
//  Author:
//
//    John Burkardt
//
{
  int a = -100;
  int b = 200;
  int i;
  int j;
  int seed = 123456789;

  cout << "\n";
  cout << "I4_UNIFORM_AB_TEST\n";
  cout << "  I4_UNIFORM_AB computes pseudorandom values\n";
  cout << "  in an interval [A,B].\n";

  cout << "\n";
  cout << "  The lower endpoint A = " << a << "\n";
  cout << "  The upper endpoint B = " << b << "\n";
  cout << "  The initial seed is " << seed << "\n";
  cout << "\n";

  for ( i = 1; i <= 20; i++ )
  {
    j = i4_uniform_ab ( a, b, seed );

    cout << "  " << setw(8) << i
         << "  " << setw(8) << j << "\n";
  }

  return;
}
//****************************************************************************80

void i4_wrap_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_WRAP_TEST tests I4_WRAP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 September 2005
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int ihi = 8;
  int ilo = 4;

  cout << "\n";
  cout << "I4_WRAP_TEST\n";
  cout << "  I4_WRAP forces an integer to lie within given limits.\n";
  cout << "\n";
  cout << "  ILO = " << ilo << "\n";
  cout << "  IHI = " << ihi << "\n";
  cout << "\n";
  cout << "     I  I4_WRAP(I)\n";
  cout << "\n";

  for ( i = -10; i <= 20; i++ )
  {
    cout << "  " << setw(6) << i
         << "  " << setw(6) << i4_wrap ( i, ilo, ihi ) << "\n";
  }

  return;
}
//****************************************************************************80

void jed_ce_values_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_CE_VALUES_TEST tests JED_CE_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    04 May 2006
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  double f;
  double jed;
  int n_data;
  int m;
  int y;

  cout << "\n";
  cout << "JED_CE_VALUES_TEST:\n";
  cout << "  JED_CE_VALUES returns:\n";
  cout << "  JED, a Julian Ephemeris Date, and\n";
  cout << "  YMDF, the corresponding year, month, day, fraction.\n";
  cout << "\n";
  cout << "        JED          Y   M   D    F\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    jed_ce_values ( n_data, jed, y, m, d, f );

    if ( n_data == 0 )
    {
      break;
    }
    cout << "  " << setw(12) << jed
         << "  " << setw(6)  << y
         << "  " << setw(2)  << m
         << "  " << setw(2)  << d
         << "  " << setw(6)  << f << "\n";
  }
  return;
}
//****************************************************************************80

void jed_is_legal_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_IS_LEGAL_TEST tests JED_IS_LEGAL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double jed;
  int jed_num = 7;
  double jed_values[7] = { -100.0, -1.0, 0.0, 1.0, 1.5, 100.0, 50000.0 };
  bool legal;

  cout << "\n";
  cout << "JED_IS_LEGAL_TEST\n";
  cout << "  JED_IS_LEGAL determines if a JED is legal,\n";
  cout << "\n";
  cout << "               JED  JED_IS_LEGAL:\n";
  cout << "\n";
  for ( i = 0; i < jed_num; i++ )
  {
    jed = jed_values[i];
    legal = jed_is_legal ( jed );
    if ( legal )
    {
      cout << "  " << setw(16) << jed
           << "  True\n";
    }
    else
    {
      cout << "  " << setw(16) << jed
           << "  False\n";
    }
  }

  return;
}
//****************************************************************************80

void jed_mjd_values_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_MJD_VALUES_TEST tests JED_MJD_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double jed;
  int n_data;
  double mjd;

  cout << "\n";
  cout << "JED_MJD_VALUES_TEST:\n";
  cout << "  JED_MJD_VALUES returns:\n";
  cout << "  JED, a Julian Ephemeris Date, and\n";
  cout << "  MJD, the corresponding Modified Julian Day count.\n";
  cout << "\n";
  cout << "   JED      MJD\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    jed_mjd_values ( n_data, jed, mjd );

    if ( n_data == 0 )
    {
      break;
    }
    cout                    << "  "
         << setw(12) << jed << "  "
         << setw(12) << mjd << "\n";
  }
  return;
}
//****************************************************************************80

void jed_rd_values_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_RD_VALUES_TEST tests JED_RD_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    12 June 2007
//
//  Author:
//
//    John Burkardt
//
{
  double jed;
  int n_data;
  double rd;

  cout << "\n";
  cout << "JED_RD_VALUES_TEST:\n";
  cout << "  JED_RD_VALUES returns:\n";
  cout << "  JED, a Julian Ephemeris Date, and\n";
  cout << "  RD, the corresponding Reingold Dershowitz Day count.\n";
  cout << "\n";
  cout << "   JED      RD\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    jed_rd_values ( n_data, jed, rd );

    if ( n_data == 0 )
    {
      break;
    }
    cout                    << "  "
         << setw(12) << jed << "  "
         << setw(12) << rd  << "\n";
  }
  return;
}
//****************************************************************************80

void jed_to_datenum_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_TO_DATENUM_TEST tests JED_TO_DATENUM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  double date_num;
  int i;
  double jed1;
  double jed3;
  double jed_epoch;

  cout << "\n";
  cout << "JED_TO_DATENUM_TEST\n";
  cout << "  JED_TO_DATENUM: Matlab DATENUM -> JED.\n";
  cout << "\n";
  cout << "  JED (in)    DATENUM             JED (out)\n";
  cout << "\n";

  jed_epoch = epoch_to_jed_datenum ( );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    if ( jed_epoch <= jed1 )
    {
      date_num = jed_to_datenum ( jed1 );
      jed3 = datenum_to_jed ( date_num );

      cout << "  " << setw(11) << jed1
           << "  " << setw(11) << date_num
           << "  " << setw(11) << jed3 << "\n";
    }
  }

  return;
}
//****************************************************************************80

void jed_to_gps_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_TO_GPS_TEST tests JED_TO_GPS.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int c2;
  int i;
  double jed_epoch;
  double jed1;
  double jed3;
  double sec2;
  int w2;

  cout << "\n";
  cout << "JED_TO_GPS_TEST\n";
  cout << "  JED_TO_GPS: JED => GPS.\n";
  cout << "\n";
  cout << "   JED (in)       GPS (C/W/S)                   JED (out)\n";
  cout << "\n";

  jed_epoch = epoch_to_jed_gps ( );

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    if ( jed_epoch <= jed1 )
    {
      jed_to_gps ( jed1, c2, w2, sec2 );

      jed3 = gps_to_jed ( c2, w2, sec2 );

      cout << "  " << setw(11) << jed1
           << "  " << c2 << "/" << w2 << "/" << sec2 << " (GPS)"
           << "  " << setw(11) << jed3 << "\n";
    }
  }

  return;
}
//****************************************************************************80

void jed_to_noon_nearest_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_TO_NOON_NEAREST_TEST tests JED_TO_NOON_NEAREST.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int d1;
  int d2;
  double f1;
  double f2;
  int i;
  double jed1;
  double jed2;
  int m1;
  int m2;
  string s1;
  string s2;
  int y1;
  int y2;

  cout << "\n";
  cout << "JED_TO_NOON_NEAREST_TEST\n";
  cout << "  JED_TO_NOON_NEAREST: JED => JED (nearest noon).\n";
  cout << "\n";
  cout << "   JED        JED (nearest noon)\n";
  cout << "\n";

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    jed_to_ymdf_common ( jed1, y1, m1, d1, f1 );

    s1 = ymdf_to_s_common ( y1, m1, d1, f1 );

    jed2 = jed_to_noon_nearest ( jed1 );

    jed_to_ymdf_common ( jed2, y2, m2, d2, f2 );

    s2 = ymdf_to_s_common ( y2, m2, d2, f2 );
    
    cout << "  " << setw(11) << jed1
         << "  " << s1
         << "  " << setw(11) << jed2
         << "  " << s2 << "\n";
  }

  return;
}
//****************************************************************************80

void jed_to_noon_next_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_TO_NOON_NEXT_TEST tests JED_TO_NOON_NEXT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int d1;
  int d2;
  double f1;
  double f2;
  int i;
  double jed1;
  double jed2;
  int m1;
  int m2;
  string s1;
  string s2;
  int y1;
  int y2;

  cout << "\n";
  cout << "JED_TO_NOON_NEXT_TEST\n";
  cout << "  JED_TO_NOON_NEXT: JED => JED (next noon).\n";
  cout << "\n";
  cout << "   JED        JED (next noon)\n";
  cout << "\n";

  i = 0;

  while ( true )
  {
    i = i + 1;
    jed1 = jed_test ( i );

    if ( jed1 < 0.0 )
    {
      break;
    }

    jed_to_ymdf_common ( jed1, y1, m1, d1, f1 );

    s1 = ymdf_to_s_common ( y1, m1, d1, f1 );

    jed2 = jed_to_noon_next ( jed1 );

    jed_to_ymdf_common ( jed2, y2, m2, d2, f2 );

    s2 = ymdf_to_s_common ( y2, m2, d2, f2 );
    
    cout << "  " << setw(11) << jed1
         << "  " << s1
         << "  " << setw(11) << jed2
         << "  " << s2 << "\n";
  }

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
//    10 December 2017
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

    jed_to_weekday ( jed, w2, f );

    cout << "  " << setw(14) << jed
         << "  " << setw(4) << w
         << "  " << setw(8) << w2
         << "  " << setw(8) << f << "\n";
  }
  return;
}
//****************************************************************************80

void jed_weekday_values_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    JED_WEEKDAY_VALUES_TEST tests JED_WEEKDAY_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 September 2013
//
//  Author:
//
//    John Burkardt
//
{
  double jed;
  int n_data;
  int weekday;
  string weekday_name[7] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", 
    "Friday", "Saturday" };

  cout << "\n";
  cout << "JED_WEEKDAY_VALUES_TEST:\n";
  cout << "  JED_WEEKDAY_VALUES returns Julian Ephemeris Dates \n";
  cout << "  (JED) and the corresponding weekday\n";
  cout << "\n";
  cout << "   JED      #  Weekday\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    jed_weekday_values ( n_data, jed, weekday );

    if ( n_data == 0 )
    {
      break;
    }
    cout                            << "  "
         << setw(12) << jed         << "  "
         << setw(1)  << weekday     << "  "
         << weekday_name[weekday-1] << "\n";
  }
  return;
}
//****************************************************************************80

void month_to_month_name_common_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    MONTH_TO_MONTH_NAME_COMMON_TEST tests MONTH_TO_MONTH_NAME_COMMON.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 May 2010
//
//  Author:
//
//    John Burkardt
//
{
  int m;
  string month_name;

  cout << "\n";
  cout << "MONTH_TO_MONTH_NAME_COMMON_TEST\n";
  cout << "  For the Common calendar,\n";
  cout << "  MONTH_TO_MONTH_NAME_COMMON names the months:\n";
  cout << "\n";

  for ( m = 1; m <= 12; m++ )
  {
    month_name = month_to_month_name_common ( m );
    cout << "  " << setw(2) << m
         << "  " << month_name << "\n";
  }

  return;
}
//****************************************************************************80

void month_to_month_name_common3_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    MONTH_TO_MONTH_NAME_COMMON3_TEST tests MONTH_TO_MONTH_NAME_COMMON3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int m;
  string month_name;

  cout << "\n";
  cout << "MONTH_TO_MONTH_NAME_COMMON3_TEST\n";
  cout << "  For the Common calendar,\n";
  cout << "  MONTH_TO_MONTH_NAME_COMMON3 names the months:\n";
  cout << "\n";

  for ( m = 1; m <= 12; m++ )
  {
    month_name = month_to_month_name_common3 ( m );
    cout << "  " << setw(2) << m
         << "  " << month_name << "\n";
  }

  return;
}
//****************************************************************************80

void r8_mod_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_MOD_TEST tests R8_MOD.
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
  int seed = 123456789;
  int test;
  int test_num = 10;
  double x;
  double x_hi = 10.0;
  double x_lo = -10.0;
  double y;
  double z1;
  double z2;

  cout << "\n";
  cout << "R8_MOD_TEST\n";
  cout << "  R8_MOD returns the remainder after division.\n";
  cout << "  R8_MOD ( X, Y ) has the same sign as X.\n";
  cout << "\n";
  cout << "      X         Y    FMOD(X,Y)    R8_MOD(X,Y)\n";
  cout << "\n";

  for ( test = 1; test <= test_num; test++ )
  {
    x = r8_uniform_ab ( x_lo, x_hi, seed );
    y = r8_uniform_ab ( x_lo, x_hi, seed );

    z1 =   fmod ( x, y );
    z2 = r8_mod ( x, y );

    cout << "  " << setw(12) << x
         << "  " << setw(12) << y
         << "  " << setw(12) << z1
         << "  " << setw(12) << z2 << "\n";
  }

  return;
}
//****************************************************************************80

void r8_nint_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_NINT_TEST tests R8_NINT
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 September 2005
//
//  Author:
//
//    John Burkardt
//
{
  double b;
  double c;
  int seed = 123456789;
  int test;
  int test_num = 10;
  double x;

  cout << "\n";
  cout << "R8_NINT_TEST\n";
  cout << "  R8_NINT produces the nearest integer.\n";
  cout << "\n";
  cout << "      X      R8_NINT(X)\n";
  cout << "\n";

  b = -10.0;
  c = +10.0;

  for ( test = 1; test <= test_num; test++ )
  {
    x = r8_uniform_ab ( b, c, seed );
    cout << setw(10) << x << "  "
         << setw(6)  << r8_nint ( x ) << "\n";
  }

  return;
}
//****************************************************************************80

void r8_uniform_01_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_UNIFORM_01_TEST tests R8_UNIFORM_01.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    12 September 2005
//
//  Author:
//
//    John Burkardt
//
{
# define N 1000

  int i;
  double max;
  double mean;
  double min;
  int seed = 123456789;
  double x[N];
  double variance;

  cout << "\n";
  cout << "R8_UNIFORM_01_TEST\n";
  cout << "  R8_UNIFORM_01 samples a uniform random distribution in [0,1].\n";
  cout << "  distributed random numbers.\n";
  cout << "  Using initial random number seed = " << seed << "\n";

  for ( i = 0; i < N; i++ )
  {
    x[i] = r8_uniform_01 ( seed );
  }

  cout << "\n";
  cout << "  First few values:\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  " << setw(6) << i
         << "  " << setw(14) << x[i] << "\n";
  }
  for ( i = 0; i < N; i++ )
  {
    if ( x[i] < min )
    {
      min = x[i];
    }
    if ( max < x[i] )
    {
      max = x[i];
    }
    mean = mean + x[i];
  }
  mean = mean / ( double ) N;

  variance = 0.0;
  for ( i = 0; i < N; i++ )
  {
    variance = variance + pow ( x[i] - mean, 2 );
  }
  variance = variance / ( double ) N;

  cout << "\n";
  cout << "  Number of samples was " << N << "\n";
  cout << "  Minimum value was " << min << "\n";
  cout << "  Maximum value was " << max << "\n";
  cout << "  Average value was " << mean << "\n";
  cout << "  Variance was      " << variance << "\n";

  return;
# undef N
}
//****************************************************************************80

void r8_uniform_ab_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_UNIFORM_AB_TEST tests R8_UNIFORM_AB.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double c;
  int i;
  int seed;

  b = 10.0;
  c = 25.0;
  seed = 17;

  cout << "\n";
  cout << "R8_UNIFORM_AB_TEST\n";
  cout << "  R8_UNIFORM_AB produces a random real in a given range.\n";
  cout << "\n";
  cout << "  Using range " << b << " <= A <= " << c << ".\n";
  cout << "\n";

  cout << "\n";
  cout << "      I       A\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    a = r8_uniform_ab ( b, c, seed );
    cout << setw ( 6 )  << i << " "
         << setw ( 10 ) << a << "\n";
  }

  return;
}
//****************************************************************************80

void weekday_to_name_common_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    WEEKDAY_TO_NAME_COMMON_TEST tests WEEKDAY_TO_NAME_COMMON.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  string s;

  cout << "\n";
  cout << "WEEKDAY_TO_NAME_COMMON_TEST\n";
  cout << "  WEEKDAY_TO_NAME_COMMON names the days of the week,\n";
  cout << "\n";

  for ( i = 1; i <= 7; i++ )
  {
    s = weekday_to_name_common ( i );
    cout << "  " << setw(4) << i
         << "  " << s << "\n";
  }

  return;
}
//****************************************************************************80

void weekday_to_name_common2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    WEEKDAY_TO_NAME_COMMON2_TEST tests WEEKDAY_TO_NAME_COMMON2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  string s;

  cout << "\n";
  cout << "WEEKDAY_TO_NAME_COMMON2_TEST\n";
  cout << "  WEEKDAY_TO_NAME_COMMON2 names the days of the week,\n";
  cout << "\n";

  for ( i = 1; i <= 7; i++ )
  {
    s = weekday_to_name_common2 ( i );
    cout << "  " << setw(4) << i
         << "  " << s << "\n";
  }

  return;
}
//****************************************************************************80

void weekday_to_name_common3_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    WEEKDAY_TO_NAME_COMMON3_TEST tests WEEKDAY_TO_NAME_COMMON3.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  string s;

  cout << "\n";
  cout << "WEEKDAY_TO_NAME_COMMON3_TEST\n";
  cout << "  WEEKDAY_TO_NAME_COMMON3 names the days of the week,\n";
  cout << "\n";

  for ( i = 1; i <= 7; i++ )
  {
    s = weekday_to_name_common3 ( i );
    cout << "  " << setw(4) << i
         << "  " << s << "\n";
  }

  return;
}
//****************************************************************************80

void weekday_values_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    WEEKDAY_VALUES_TEST tests WEEKDAY_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 January 2015
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int m;
  int n_data;
  int w;
  int y;

  cout << "\n";
  cout << "WEEKDAY_VALUES_TEST:\n";
  cout << "  WEEKDAY_VALUES returns values of \n";
  cout << "  the weekday for a given Y/M/D date.\n";
  cout << "\n";
  cout << "     Y     M     D     W\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    weekday_values ( n_data, y, m, d, w );

    if ( n_data == 0 )
    {
      break;
    }
    cout << "  " << setw(4) << y
         << "  " << setw(4) << m
         << "  " << setw(4) << d 
         << "  " << setw(4) << w << "\n";
  }
  return;
}
//****************************************************************************80

void y_to_s_common_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Y_TO_S_COMMON_TEST tests Y_TO_S_COMMON.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double mu;
  string s;
  int seed;
  double sigma;
  int y;

  cout << "\n";
  cout << "Y_TO_S_COMMON_TEST:\n";
  cout << "  Y_TO_S_COMMON converts a year Y to a string S.\n";
  cout << "\n";
  cout << "       Y  'S'\n";
  cout << "\n";

  mu = 0.0;
  sigma = 1000.0;
  seed = 123456789;

  for ( i = 1; i <= 10; i++ )
  {
    y = i4_normal_ab ( mu, sigma, seed );
    s = y_to_s_common ( y );
    cout << "  " << setw(6) << y
         << "  '" << s << "'\n";
  }

  return;
}
//****************************************************************************80

void year_length_days_common_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    YEAR_LENGTH_DAYS_COMMON_TEST tests YEAR_LENGTH_DAYS_COMMON.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  string sy;
  int y;

  cout << "\n";
  cout << "YEAR_LENGTH_DAYS_COMMON_TEST\n";
  cout << "  For the Common calendar:\n";
  cout << "  YEAR_LENGTH_DAYS_COMMON gives the length of a year.\n";
  cout << "\n";
  cout << "  Year  Length\n";
  cout << "\n";

  for ( y = 1580; y <= 1585; y++ )
  {
    sy = y_to_s_common ( y );
    cout << "  " << setw(10) << sy
         << "  " << setw(6) << year_length_days_common ( y ) << "\n";
  }

  for ( y = 1750; y <= 1755; y++ )
  {
    sy = y_to_s_common ( y );
    cout << "  " << setw(10) << sy
         << "  " << setw(6) << year_length_days_common ( y ) << "\n";
  }

  for ( y = 1000; y <= 2000; y = y + 100 )
  {
    sy = y_to_s_common ( y );
    cout << "  " << setw(10) << sy
         << "  " << setw(6) << year_length_days_common ( y ) << "\n";
  }

  return;
}
//****************************************************************************80

void year_to_golden_number_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    YEAR_TO_GOLDEN_NUMBER_TEST tests YEAR_TO_GOLDEN_NUMBER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 December 2017
//
//  Author:
//
//    John Burkardt
//
{
  int g;
  string s;
  int y;

  cout << "\n";
  cout << "YEAR_TO_GOLDEN_NUMBER_TEST\n";
  cout << "  YEAR_TO_GOLDEN_NUMBER determines the golden\n";
  cout << "  number of a year.\n";
  cout << "\n";
  cout << "  Year  Golden Number\n";
  cout << "\n";

  for ( y = -2; y <= 20; y++ )
  {
    if ( y != 0 )
    {
      s = y_to_s_common ( y );
      g = year_to_golden_number ( y );
      cout << "  " << s
           << "  " << g << "\n";
    }
  }
  return;
}
//****************************************************************************80

void ymd_to_decimal_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    YMD_TO_DECIMAL_TEST tests YMD_TO_DECIMAL
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 October 2012
//
//  Author:
//
//    John Burkardt
//
{
  int d;
  int dhi = 1;
  int dlo = 1;
  double f;
  double fhi = 0.0;
  double flo = 0.0;
  int i;
  int m;
  int mhi = 1;
  int mlo = 1;
  string s;
  int seed = 123456789;
  int y;
  double yf;
  int yhi = 1970;
  int ylo = 1960;

  cout << "\n";
  cout << "YMD_TO_DECIMAL_TEST\n";
  cout << "  YMD_TO_DECIMAL converts a date to a year and decimal.\n";
  cout << "\n";
  cout << "  YMD                         Y.F\n";
  cout << "\n";
 
  for ( i = 1; i <= 10; i++ )
  {
    ymdf_uniform_common ( ylo, mlo, dlo, flo, yhi, mhi, dhi, fhi, 
      seed, y, m, d, f );

    s = ymd_to_s_common ( y, m, d );

    yf = ymd_to_decimal ( y, m, d );
//
//  Apparently, precision 8 means how many digits total, including
//  those BEFORE the decimal place.  Because the default for reals
//  is not "f" but "e" or "g"...  Yet another clumsy and misleading
//  feature of IOMANIP.
//
    cout << "  " << setw(13) << s << "   "
         << "  " << setw(14) << setprecision(8) << yf << "\n";
  }

  return;
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
//    26 December 2017
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
  cout << "  for dates in the Common calendar:\n";
  cout << "\n";
  cout << "  YMD                   Weekday    Weekday\n";
  cout << "                        Tabulated  Computed\n";
  cout << "\n";

  n_data = 0;

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
         << "  " << setw(9) << s1
         << "  " << setw(9) << s2 << "\n";
  }
  return;
}

