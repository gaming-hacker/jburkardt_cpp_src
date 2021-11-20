# include <boost/lambda/lambda.hpp>
# include <iostream>
# include <iterator>
# include <algorithm>

using namespace std;

int main ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    BOOST_TEST1 reads integers, multiplies by 3, and writes them out.
//
//  Discussion:
//
//    The program reads integers from the standard input, and writes out
//    3 times the value of each quantity input.  The program doesn't terminate,
//    and continues to read and triple until killed.
//
//  Modified:
//
//    20 April 2011
//
{
  using namespace boost::lambda;
  typedef std::istream_iterator<int> in;

  std::for_each
  (
    in ( std::cin ), 
    in ( ), 
    std::cout << (_1 * 3) << " "
  );
//
//  Terminate.
//
  cout << "\n";
  cout << "BOOST_TEST1:\n";
  cout << "  Normal end of execution.\n";

  return 0;
}
