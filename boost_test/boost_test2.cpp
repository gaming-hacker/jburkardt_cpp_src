# include <boost/regex.hpp>
# include <iostream>
# include <string>

using namespace std;

//****************************************************************************80

int main ( )

//****************************************************************************80
{
  std::string line;
  boost::regex pat( "^Subject: (Re: |Aw: )*(.*)" );

  cout << "\n";
  cout << "BOOST_TEST2:\n";
  cout << "  Demonstrate the regular expression processing library.\n";

  while ( std::cin )
  {
    std::getline ( std::cin, line );

    boost::smatch matches;

    if ( boost::regex_match ( line, matches, pat ) )
    {
      std::cout << matches[2] << std::endl;
    }
  }
//
//  Terminate.
//
  cout << "\n";
  cout << "BOOST_TEST2:\n";
  cout << "  Normal end of execution.\n";

  return 0;
}
