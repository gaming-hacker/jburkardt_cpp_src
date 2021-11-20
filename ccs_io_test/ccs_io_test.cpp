# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <ctime>
# include <cstring>

using namespace std;

# include "ccs_io.hpp"

int main ( );
void test01 ( );
void test02 ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for ccs_IO_TEST.
//
//  Discussion:
//
//    ccs_IO_TEST tests the ccs_IO library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2014
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "ccs_io_test\n";
  cout << "  C++ version\n";
  cout << "  Test the ccs_io library.\n";

  test01 ( );
  test02 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "ccs_io_test\n";
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
//    TEST01 tests ccs_WRITE using a tiny matrix.
//
//  Discussion:
//
//    This test uses a trivial matrix whose full representation is:
//
//          2  3  0  0  0
//          3  0  4  0  6
//      A = 0 -1 -3  2  0
//          0  0  1  0  0
//          0  4  2  0  1
//
//    The 1-based CCS representation is
//
//      #  ICC  CCC  ACC
//     --  ---  ---  ---
//      1    1    1    2
//      2    2         3
//
//      3    1    3    3
//      4    3        -1
//      5    5         4
//
//      6    2    6    4
//      7    3        -3
//      8    4         1
//      9    5         2
//
//     10    3   10    2
//
//     11    2   11    6
//     12    5         1
//
//     13    *   13
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2014
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define NCC 12

  double acc[NCC] = {
    2.0,  3.0,
    3.0, -1.0,  4.0,
    4.0, -3.0,  1.0, 2.0,
    2.0,
    6.0, 1.0 };
  int ccc[N+1] = {
    1, 3, 6, 10, 11, 13 };
  int icc[NCC] = {
    1, 2,
    1, 3, 5,
    2, 3, 4, 5,
    3,
    2, 5 };
  int m = N;
  int n = N;
  int ncc = NCC;
  string prefix = "simple";

  cout << "\n";
  cout << "TEST01\n";
  cout << "  Write a sparse matrix in CCS format to 3 files.\n";
//
//  Full storage statistics
//
  cout << "\n";
  cout << "  Full rows    M = " << m << "\n";
  cout << "  Full columns N = " << n << "\n";
  cout << "  Full storage   = " << m * n << "\n";
//
//  Decrement the 1-based data.
//
  i4vec_dec ( n + 1, ccc );
  i4vec_dec ( ncc, icc );
//
//  Print the CCS matrix.
//
  ccs_print ( m, n, ncc, icc, ccc, acc, "  The matrix in 0-based CCS format:" );
//
//  Write the matrix to 3 files.
//
  ccs_write ( prefix, ncc, n, icc, ccc, acc );

  return;
# undef NCC
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 tests ccs_HEADER_READ and ccs_DATA_READ.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 July 2014
//
//  Author:
//
//    John Burkardt
//
{
  double *acc;
  int *ccc;
  int *icc;
  int m;
  int n;
  int ncc;
  string prefix = "simple";

  cout << "\n";
  cout << "TEST02\n";
  cout << "  Read a sparse matrix in CCS format from 3 files.\n";
//
//  Read the header.
//
  ccs_header_read ( prefix, ncc, n );
//
//  Allocate space.
//
  acc = new double[ncc];
  ccc = new int[n+1];
  icc = new int[ncc];
//
//  Read the matrix data.
//
  ccs_data_read ( prefix, ncc, n, icc, ccc, acc );
//
//  Print the CCS matrix.
//
  m = n;
  ccs_print ( m, n, ncc, icc, ccc, acc, "  The matrix in 0-based CCS format:" );
//
//  Free memory.
//
  delete [] acc;
  delete [] ccc;
  delete [] icc;

  return;
}
