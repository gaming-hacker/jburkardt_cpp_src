# include <cstdlib>
# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "atbash.hpp"

//****************************************************************************80

string atbash_encrypt ( string plain )

//****************************************************************************80
//
//  Purpose:
//
//    ATBASH_ENCRYPT encrypts a string using the ATBASH code.
//
//  Discussion:
//
//    Only the alphabetic characters will be encrypted.
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
//  Parameters:
//
//    Input, string PLAIN, the string to be encrypted.
//
//    Output, string ATBASH_ENCRYPT, the encrypted version of the string.
//
{
  string crypt;
  int i;
  int plain_len;
//
//  Create space for the encrypted string.
//
  plain_len = plain.length ( );

  crypt = plain;
//
//  Convert plain text characters to unsigned integers,
//  and reverse the index.
//
  for ( i = 0; i < plain_len; i++ )
  {
    if ( 'a' <= plain[i] && plain[i] <= 'z' )
    {
      crypt[i] = 'a' + 'z' - plain[i];
    }
    else if ( 'A' <= plain[i] && plain[i] <= 'Z' )
    {
      crypt[i] = 'A' + 'Z' - plain[i];
    }
    else
    {
      crypt[i] = plain[i];
    }
  }
      
  return crypt;
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
