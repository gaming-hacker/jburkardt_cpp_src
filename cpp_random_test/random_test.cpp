# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>

using namespace std;

int main ( int argc, char *argv[] );
void test01 ( );
void test02 ( );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    RANDOM_TEST generates random numbers using RANDOM().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 September 2006
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );

  cout << "\n";
  cout << "RANDOM_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Generate random numbers using\n";
  cout << "  SRANDOM to set the seed, and\n";
  cout << "  RANDOM to return the random values.\n";
  cout << "\n";
  cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << "\n";

  test01 ( );
  test02 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "RANDOM_TEST:\n";
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
//    TEST01 simply calls RANDOM a few times.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 September 2006
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  unsigned int seed = 123456789;
  long int x;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Call SRANDOM to initialize the seed.\n";
  cout << "  Call RANDOM to generate some values.\n";
  cout << "\n";
  cout << "  Initial SEED = " << seed << "\n";

  srandom ( seed );
  cout << "\n";
  cout << "      Step    RANDOM()\n";
  cout << "\n";

  for ( i = 0; i < 10; i++ )
  {
    x = random ( );
    cout << "  " << setw(8) << i
         << "  " << setw(12) << x << "\n";
  }
  return;
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 uses RANDOM to generate real values in [0,1];
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 September 2006
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  unsigned int seed = 123456789;
  long int x;
  double y;

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Call SRANDOM to initialize the seed.\n";
  cout << "  Call RANDOM to generate some values.\n";
  cout << "  Set X = ( double ) RANDOM ( ) / ( double ) RAND_MAX\n";
  cout << "  so that X is a random real in [0,1].\n";

  cout << "\n";
  cout << "  RAND_MAX = " << RAND_MAX << "\n";

  cout << "\n";
  cout << "  Initial SEED = " << seed << "\n";
  srandom ( seed );

  cout << "\n";
  cout << "      Step    RANDOM()      RANDOM()/RAND_MAX\n";
  cout << "\n";

  for ( i = 0; i < 10; i++ )
  {
    x = random ( );

    y = ( double ) x / ( double ) RAND_MAX;

    cout << "  " << setw(8) << i
         << "  " << setw(12) << x
         << "  " << setw(12) << y << "\n";
  }
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
//    May 31 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 October 2003
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
