# include <cstdlib>
# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "atbash.hpp"

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    ATBASH_TEST tests ATBASH.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );

  cout << "\n";
  cout << "ATBASH_TEST\n";
  cout << "  C++ version\n";
  cout << "  ATBASH_ENCRYPT encrypts a plain text using the Atbash\n";
  cout << "  substitution cipher.\n";

  atbash_test01 ( );
  atbash_test02 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "ATBASH_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void atbash_test01 ( )

//****************************************************************************80
//
//  Purpose:
//
//    ATBASH_TEST01 tests ATBASH with a short phrase.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  string crypt;
  string decrypt;
  string plain = "A man, a plan, a canal - Panama!";

  cout << "\n";
  cout << "ATBASH_TEST01\n";
  cout << "  Apply ATBASH to a short phrase.\n";

  crypt = atbash_encrypt ( plain );
  decrypt = atbash_encrypt ( crypt );
  cout << "\n";
  cout << "PLAIN:   '" << plain << "'\n";
  cout << "CRYPT:   '" << crypt << "'\n";
  cout << "DECRYPT: '" << decrypt << "'\n";

  return;
}
//****************************************************************************80

void atbash_test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    ATBASH_TEST02 tests ATBASH with another phrase.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  string crypt;
  string decrypt;
  string plain = "There are a thousand hacking at the branches of evil for every one who is striking at its root.";

  cout << "\n";
  cout << "ATBASH_TEST02\n";
  cout << "  Apply ATBASH to a longer phrase.\n";

  crypt = atbash_encrypt ( plain );
  decrypt = atbash_encrypt ( crypt );
  cout << "\n";
  cout << "PLAIN:   '" << plain << "'\n";
  cout << "CRYPT:   '" << crypt << "'\n";
  cout << "DECRYPT: '" << decrypt << "'\n";

  return;
}
