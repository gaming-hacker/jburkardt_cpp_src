# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <stdint.h>

using namespace std;

# include "ziggurat.hpp"

int main ( );
void shr3_seeded_test1 ( );
void test02 ( );
void test03 ( );
void test04 ( );
void shr3_seeded_test2 ( int sample_num );
void test06 ( int sample_num );
void test07 ( int sample_num );
void test08 ( int sample_num );
void test09 ( );
void test10 ( );
void test11 ( );
void shr3_seeded_test3 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for ZIGGURAT_TEST.
//
//  Discussion:
//
//    ZIGGURAT_TEST tests the ZIGGURAT library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  int sample_num = 1000000;

  timestamp ( );
  cout << "\n";
  cout << "ZIGGURAT_TEST\n";
  cout << "  C++ version:\n";
  cout << "  Test the ZIGGURAT library.\n";
//
//  Make sure that SEED controls the sequence, and can restart it.
//
  shr3_seeded_test1 ( );
  test02 ( );
  test03 ( );
  test04 ( );
//
//  Measure the time it takes to generate 10,000 variables.
//
  shr3_seeded_test2 ( sample_num );
  test06 ( sample_num );
  test07 ( sample_num );
  test08 ( sample_num );
//
//  Sample 10 values of the unsigned integer 32 bit generators.
//
  test09 ( );
  test10 ( );
  test11 ( );
  shr3_seeded_test3 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "ZIGGURAT_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void shr3_seeded_test1 ( )

//****************************************************************************80
//
//  Purpose:
//
//    SHR3_SEEDED_TEST1 tests SHR3_SEEDED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int j;
  uint32_t seed;
  uint32_t value;

  cout << "\n";
  cout << "SHR3_SEEDED_TEST1\n";
  cout << "  SHR3_SEEDED returns pseudorandom uniformly distributed\n";
  cout << "  unsigned 32 bit integers.\n";
  cout << "\n";
  cout << "    Step        Signed      Unsigned   SHR3_SEEDED\n";
  cout << "                  Seed          Seed\n";
  cout << "\n";

  for ( j = 0; j < 3; j++ )
  {
    if ( ( j % 2 ) == 0 )
    {
      seed = ( uint32_t ) 123456789;
    }
    else
    {
      seed = ( uint32_t ) 987654321;
    }

    cout << "\n";
    cout << "  " << setw(6)  << 0
         << "  " << setw(12) << ( int ) seed
         << "  " << setw(12) << seed << "\n";
    cout << "\n";

    for ( i = 1; i <= 10; i++ )
    {
      value = shr3_seeded ( seed );

      cout << "  " << setw(6)  << i
           << "  " << setw(12) << ( int ) seed
           << "  " << setw(12) << seed
           << "  " << setw(12) << value << "\n";
    }
  }

  return;
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 tests R4_UNI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int j;
  uint32_t seed;
  float value;

  cout << "\n";
  cout << "TEST02\n";
  cout << "  R4_UNI returns pseudorandom uniformly distributed\n";
  cout << "  floats (single precision reals) between 0 and 1.\n";

  for ( j = 0; j < 3; j++ )
  {
    if ( ( j % 2 ) == 0 )
    {
      seed = 123456789;
    }
    else
    {
      seed = 987654321;
    }

    cout << "\n";
    cout << "  " << setw(6)  << 0
         << "  " << setw(12) << ( int ) seed
         << "  " << setw(12) << seed << "\n";
    cout << "\n";

    for ( i = 1; i <= 10; i++ )
    {
      value = r4_uni ( seed );

      cout << "  " << setw(6)  << i
           << "  " << setw(12) << ( int ) seed
           << "  " << setw(12) << seed
           << "  " << setw(14) << value << "\n";
    }
  }

  return;
}
//****************************************************************************80

void test03 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST03 tests R4_NOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  float fn[128];
  int i;
  int j;
  uint32_t kn[128];
  uint32_t seed;
  float value;
  float wn[128];

  cout << "\n";
  cout << "TEST03\n";
  cout << "  R4_NOR returns pseudorandom normally distributed\n";
  cout << "  floats (single precision reals) between 0 and 1.\n";

  r4_nor_setup ( kn, fn, wn );

  for ( j = 0; j < 3; j++ )
  {
    if ( ( j % 2 ) == 0 )
    {
      seed = 123456789;
    }
    else
    {
      seed = 987654321;
    }

    cout << "\n";
    cout << "  " << setw(6)  << 0
         << "  " << setw(12) << ( int ) seed
         << "  " << setw(12) << seed << "\n";
    cout << "\n";

    for ( i = 1; i <= 10; i++ )
    {
      value = r4_nor ( seed, kn, fn, wn );

      cout << "  " << setw(6)  << i
           << "  " << setw(12) << ( int ) seed
           << "  " << setw(12) << seed
           << "  " << setw(14) << value << "\n";
    }
  }

  return;
}
//****************************************************************************80

void test04 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST04 tests R4_EXP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  float fe[256];
  int i;
  int j;
  uint32_t ke[256];
  uint32_t seed;
  float value;
  float we[256];

  cout << "\n";
  cout << "TEST04\n";
  cout << "  R4_EXP returns pseudorandom exponentially distributed\n";
  cout << "  floats (single precision reals) between 0 and 1.\n";

  r4_exp_setup ( ke, fe, we );

  for ( j = 0; j < 3; j++ )
  {
    if ( ( j % 2 ) == 0 )
    {
      seed = 123456789;
    }
    else
    {
      seed = 987654321;
    }

    cout << "\n";
    cout << "  " << setw(6)  << 0
         << "  " << setw(12) << ( int ) seed
         << "  " << setw(12) << seed << "\n";
    cout << "\n";

    for ( i = 1; i <= 10; i++ )
    {
      value = r4_exp ( seed, ke, fe, we );

      cout << "  " << setw(6)  << i
           << "  " << setw(12) << ( int ) seed
           << "  " << setw(12) << seed
           << "  " << setw(14) << value << "\n";
    }
  }

  return;
}
//****************************************************************************80

void shr3_seeded_test2 ( int sample_num )

//****************************************************************************80
//
//  Purpose:
//
//    SHR3_SEEDED_TEST2 times SHR3_SEEDED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  double ctime;
  int sample;
  uint32_t seed;
  uint32_t value;

  cout << "\n";
  cout << "SHR3_SEEDED_TEST2\n";
  cout << "  Measure the time it takes SHR3_SEEDED to generate\n";
  cout << "  " << sample_num << " unsigned 32 bit integers.\n";

  seed = 123456789;

  ctime = cpu_time ( );

  for ( sample = 0; sample < sample_num; sample++ )
  {
    value = shr3_seeded ( seed );
  }
  ctime = cpu_time ( ) - ctime;

  cout << "\n";
  cout << "  Final value = " << value << "\n";
  cout << "  " << ctime << " seconds.\n";

  return;
}
//****************************************************************************80

void test06 ( int sample_num )

//****************************************************************************80
//
//  Purpose:
//
//    TEST06 times R4_UNI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  double ctime;
  int sample;
  uint32_t seed;
  float value;

  cout << "\n";
  cout << "TEST06\n";
  cout << "  Measure the time it takes R4_UNI to generate\n";
  cout << "  " << sample_num << " uniformly random floats.\n";

  seed = 123456789;

  ctime = cpu_time ( );

  for ( sample = 0; sample < sample_num; sample++ )
  {
    value = r4_uni ( seed );
  }
  ctime = cpu_time ( ) - ctime;

  cout << "\n";
  cout << "  Final value = " << value << "\n";
  cout << "  " << ctime << " seconds.\n";

  return;
}
//****************************************************************************80

void test07 ( int sample_num )

//****************************************************************************80
//
//  Purpose:
//
//    TEST07 times R8_NOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  double ctime;
  float fn[128];
  uint32_t kn[128];
  int sample;
  uint32_t seed;
  float value;
  float wn[129];

  cout << "\n";
  cout << "TEST07\n";
  cout << "  Measure the time it takes R8_NOR to generate\n";
  cout << "  " << sample_num << " normal random floats.\n";

  r4_nor_setup ( kn, fn, wn );

  seed = 123456789;

  ctime = cpu_time ( );

  for ( sample = 0; sample < sample_num; sample++ )
  {
    value = r4_nor ( seed, kn, fn, wn );
  }
  ctime = cpu_time ( ) - ctime;

  cout << "\n";
  cout << "  Final value = " << value << "\n";
  cout << "  " << ctime << " seconds.\n";

  return;
}
//****************************************************************************80

void test08 ( int sample_num )

//****************************************************************************80
//
//  Purpose:
//
//    TEST08 times R4_EXP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  double ctime;
  float fe[256];
  uint32_t ke[256];
  int sample;
  uint32_t seed;
  float value;
  float we[256];

  cout << "\n";
  cout << "TEST08\n";
  cout << "  Measure the time it takes R4_EXP to generate\n";
  cout << "  " << sample_num << " exponential random floats.\n";

  r4_exp_setup ( ke, fe, we );

  seed = 123456789;

  ctime = cpu_time ( );

  for ( sample = 0; sample < sample_num; sample++ )
  {
    value = r4_exp ( seed, ke, fe, we );
  }
  ctime = cpu_time ( ) - ctime;

  cout << "\n";
  cout << "  Final value = " << value << "\n";
  cout << "  " << ctime << " seconds.\n";

  return;
}
//****************************************************************************80

void test09 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST09 tests CONG_SEEDED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  int j;
  uint32_t jcong_new;
  uint32_t jcong_in;
  uint32_t jcong_old;

  cout << "\n";
  cout << "TEST09\n";
  cout << "  CONG_SEEDED is a generator of pseudorandom uniformly\n";
  cout << "  distributed unsigned 32 bit integers.\n";
  cout << "\n";
  cout << "    Input Seed   Output Seed  Output Value\n";
  cout << "\n";

  jcong_new = 234567891;

  for ( j = 1; j <= 10; j++ )
  {
    jcong_old = jcong_new;
    jcong_in = jcong_new;
    jcong_new = cong_seeded ( jcong_in );
    cout << "  " << setw(12) << jcong_old
         << "  " << setw(12) << jcong_in
         << "  " << setw(12) << jcong_new << "\n";
  }

  return;
}
//****************************************************************************80

void test10 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST10 tests KISS_SEEDED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  int j;
  uint32_t jcong_in;
  uint32_t jcong_old;
  uint32_t jsr_in;
  uint32_t jsr_old;
  uint32_t w_in;
  uint32_t w_old;
  uint32_t value;
  uint32_t z_in;
  uint32_t z_old;

  cout << "\n";
  cout << "TEST10\n";
  cout << "  KISS_SEEDED is a generator of pseudorandom uniformly\n";
  cout << "  distributed unsigned 32 bit integers.\n";
  cout << "\n";
  cout << "              JCONG           JSR             W             Z         Value\n";
  cout << "\n";

  jcong_in = 234567891;
  jsr_in = 123456789;
  w_in = 345678912;
  z_in = 456789123;

  for ( j = 1; j <= 10; j++ )
  {
    jcong_old = jcong_in;
    jsr_old = jsr_in;
    w_old = w_in;
    z_old = z_in;
    value = kiss_seeded ( jcong_in, jsr_in, w_in, z_in );
    cout << "  In "
         << "  " << setw(12) << jcong_old
         << "  " << setw(12) << jsr_old
         << "  " << setw(12) << w_old
         << "  " << setw(12) << z_old << "\n";
    cout << "  Out"
         << "  " << setw(12) << jcong_in
         << "  " << setw(12) << jsr_in
         << "  " << setw(12) << w_in
         << "  " << setw(12) << z_in
         << "  " << setw(12) << value << "\n";
  }

  return;
}
//****************************************************************************80

void test11 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST11 tests MWC_SEEDED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  int j;
  uint32_t w_in;
  uint32_t w_old;
  uint32_t value;
  uint32_t z_in;
  uint32_t z_old;

  cout << "\n";
  cout << "TEST11\n";
  cout << "  MWC_SEEDED is a generator of pseudorandom uniformly\n";
  cout << "  distributed unsigned 32 bit integers.\n";
  cout << "\n";
  cout << "       Input W       Input Z      Output W      Output Z  Output Value\n";
  cout << "\n";

  w_in = 345678912;
  z_in = 456789123;

  for ( j = 1; j <= 10; j++ )
  {
    w_old = w_in;
    z_old = z_in;
    value = mwc_seeded ( w_in, z_in );
    cout << "  " << setw(12) << w_old
         << "  " << setw(12) << z_old
         << "  " << setw(12) << w_in
         << "  " << setw(12) << z_in
         << "  " << setw(12) << value << "\n";
  }

  return;
}
//****************************************************************************80

void shr3_seeded_test3 ( )

//****************************************************************************80
//
//  Purpose:
//
//    SHR3_SEEDED_TEST3 tests SHR3_SEEDED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 October 2013
//
//  Author:
//
//    John Burkardt
//
{
  int j;
  uint32_t jsr_new;
  uint32_t jsr_in;
  uint32_t jsr_old;

  cout << "\n";
  cout << "SHR3_SEEDED_TEST3\n";
  cout << "  SHR3_SEEDED is a generator of pseudorandom uniformly\n";
  cout << "  distributed unsigned 32 bit integers.\n";
  cout << "\n";
  cout << "    Input Seed   Output Seed  Output Value\n";
  cout << "\n";

  jsr_new = 123456789;

  for ( j = 1; j <= 10; j++ )
  {
    jsr_old = jsr_new;
    jsr_in = jsr_new;
    jsr_new = shr3_seeded ( jsr_in );
    cout << "  " << setw(12) << jsr_old
         << "  " << setw(12) << jsr_in
         << "  " << setw(12) << jsr_new << "\n";
  }

  return;
}
