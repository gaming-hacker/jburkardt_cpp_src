# include <cstdlib>
# include <ctime>
# include <iostream>
# include <string>

using namespace std;

int main ( int argc, char *argv[] );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for ARGS_TO_STRINGS
//
//  Discussion:
//
//    ARGS_TO_STRINGS converts command line arguments to strings.
//
//    Invoke the program with a command like 
//
//      args_to_strings bob joe fred
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  string s;

  timestamp ( );
 
  cout << "\n";
  cout << "ARGS_TO_STRINGS:\n";
  cout << "  C++ version\n";
  cout << "  Read each commandline argument and store it as a string.\n";
  cout << "\n";
  cout << "  Number of commandline arguments is " << argc << ".\n";
  cout << "\n";

  for ( i = 0; i < argc; i++ )
  {
    cout << "  Character Arg[" << i << "] = \"" << argv[i] << "\"\n";
//
//  Using an assignment statement, the character string is automatically
//  converted to a C++ string.
//
    s = argv[i];
    cout << "  String    Arg[" << i << "] = \"" << s << "\"\n";
  }
//
//  Terminate.
//
  cout << "\n";
  cout << "ARGS_TO_STRINGS:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
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
//    19 March 2018
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

