# include <cmath>
# include <complex>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "i8lib.hpp"

int main ( );
void i8_choose_test ( );
void i8_xor_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for I8LIB_TEST.
//
//  Discussion:
//
//    I8LIB_TEST tests the I8LIB library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 April 2010
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "I8LIB_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test I8LIB.\n";

  i8_choose_test ( );
  i8_xor_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "I8LIB_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void i8_choose_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    i8_choose_test tests I8_CHOOSE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 June 2010
//
//  Author:
//
//    John Burkardt
//
{
  long long int cnk;
  long long int k;
  long long int n;

  cout << "\n";
  cout << "i8_choose_test\n";
  cout << "  I8_CHOOSE evaluates C(N,K).\n";
  cout << "\n";
  cout << "     N     K    CNK\n";
  cout << "\n";

  for ( n = 0; n <= 4; n++ )
  {
    for ( k = 0; k <= n; k++ )
    {
      cnk = i8_choose ( n, k );

      cout << setw(6) << n   << "  "
           << setw(6) << k   << "  "
           << setw(6) << cnk << "\n";
    }
  }

  return;
}
//****************************************************************************80

void i8_xor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    i8_xor_test tests I8_XOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    27 June 2010
//
//  Author:
//
//    John Burkardt
//
{
  long long int i;
  long long int i_lo = 0LL;
  long long int i_hi = 100LL;
  long long int j;
  long long int k;
  long long int l;
  long long int seed;
  int test;
  int test_num = 10;

  seed = 123456789LL;

  cout << "\n";
  cout << "i8_xor_test\n";
  cout << "  I8_XOR returns the bitwise exclusive OR of\n";
  cout << "  two I8's.\n";
  cout << "  The operator ^ should generally be used instead.\n";
  cout << "\n";
  cout << "       I       J  I8_XOR(I,J)\n";
  cout << "\n";

  for ( test = 1; test <= test_num; test++ )
  {
    i = i8_uniform_ab ( i_lo, i_hi, &seed );
    j = i8_uniform_ab ( i_lo, i_hi, &seed );
    k = i8_xor ( i, j );
    l = i ^ j;

    cout << "  " << setw(6) << i 
         << "  " << setw(6) << j 
         << "  " << setw(6) << k 
         << "  " << setw(6) << l << "\n";
  }

  return;
}
