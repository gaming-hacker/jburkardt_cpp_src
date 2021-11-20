# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "st_io.hpp"

int main ( );
void r8st_write_test ( );
void r8st_read_test ( );
void r8st_sort_a_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for ST_IO_TEST.
//
//  Discussion:
//
//    ST_IO_TEST tests the ST_IO library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 September 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "ST_IO_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the ST_IO library.\n";
//
//  Real double precision tests.
//
  r8st_write_test ( );
  r8st_read_test ( );
  r8st_sort_a_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "ST_IO_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void r8st_write_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8ST_WRITE_TEST tests R8ST_WRITE.
//
//  Discussion:
//
//    The matrix is:
//
//      11  12   0   0  15
//      21  22   0   0   0
//       0   0  33   0  35
//       0   0   0  44   0
//      51   0  53   0  55
//
//    The index vectors are 1 based, and so have to be converted to
//    0-base before being written.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2014
//
//  Author:
//
//    John Burkardt
//
{
  double ast[11] = {
    51.0, 12.0, 11.0, 33.0, 15.0, 
    53.0, 55.0, 22.0, 35.0, 44.0, 
    21.0 };
  int i_max;
  int i_min;
  int ist[11] = {
     5, 1, 1, 3, 1, 5, 5, 2, 3, 4, 2 };
  int j_max;
  int j_min;
  int jst[11] = {
     1, 2, 1, 3, 5, 3, 5, 2, 5, 4, 1 };
  int m = 5;
  int n = 5;
  int nst = 11;
  string output_filename = "a5by5_r8.st";

  cout << "\n";
  cout << "R8ST_WRITE_TEST\n";
  cout << "  R8ST_WRITE writes an R8ST file.\n";

  i4vec_dec ( nst, ist );
  i4vec_dec ( nst, jst );

  i_min = i4vec_min ( nst, ist );
  i_max = i4vec_max ( nst, ist );
  j_min = i4vec_min ( nst, jst );
  j_max = i4vec_max ( nst, jst );

  r8st_header_print ( i_min, i_max, j_min, j_max, m, n, nst );

  r8st_print ( m, n, nst, ist, jst, ast, 
    "  Sparse Triple data:" );

  r8st_write ( output_filename, m, n, nst, ist, jst, ast );

  cout << "\n";
  cout << "  Wrote the matrix data to '" << output_filename << "'\n";

  return;
}
//****************************************************************************80

void r8st_read_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8ST_READ_TEST tests R8ST_HEADER_READ, R8ST_DATA_READ.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2014
//
//  Author:
//
//    John Burkardt
//
{
  double *ast;
  int i_max;
  int i_min;
  string input_filename = "kershaw_r8.st";
  int *ist;
  int j_max;
  int j_min;
  int *jst;
  int m;
  int n;
  int nst;

  cout << "\n";
  cout << "R8ST_READ_TEST\n";
  cout << "  R8ST_HEADER_READ reads the header from an R8ST file.\n";
  cout << "  R8ST_DATA_READ reads the data from an R8ST file.\n";
  cout << "\n";
  cout << "  Read the data from '" << input_filename << "'\n";

  r8st_header_read ( input_filename, i_min, i_max, j_min, j_max, m, n, nst );

  r8st_header_print ( i_min, i_max, j_min, j_max, m, n, nst );

  ast = new double[nst];
  ist = new int[nst];
  jst = new int[nst];

  r8st_data_read ( input_filename, m, n, nst, ist, jst, ast );

  r8st_print ( m, n, nst, ist, jst, ast, 
    "  Sparse Triplet data read from file:" );

  delete [] ast;
  delete [] ist;
  delete [] jst;

  return;
}
//****************************************************************************80

void r8st_sort_a_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8ST_SORT_A_TEST tests R8ST_SORT_A.
//
//  Discussion:
//
//    The matrix is:
//
//      11  12   0   0  15
//      21  22   0   0   0
//       0   0  33   0  35
//       0   0   0  44   0
//      51   0  53   0  55
//
//    The index vectors are 1 based, and so have to be converted to
//    0-base before being written.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 July 2014
//
//  Author:
//
//    John Burkardt
//
{
  double ast[11] = {
    51.0, 12.0, 11.0, 33.0, 15.0, 
    53.0, 55.0, 22.0, 35.0, 44.0, 
    21.0 };
  int i_max;
  int i_min;
  int ist[11] = {
     5, 1, 1, 3, 1, 5, 5, 2, 3, 4, 2 };
  int j_max;
  int j_min;
  int jst[11] = {
     1, 2, 1, 3, 5, 3, 5, 2, 5, 4, 1 };
  int m = 5;
  int n = 5;
  int nst = 11;

  cout << "\n";
  cout << "R8ST_SORT_A_TEST\n";
  cout << "  R8ST_SORT_A sorts an R8ST matrix by columns.\n";

  i_min = i4vec_min ( nst, ist );
  i_max = i4vec_max ( nst, ist );
  j_min = i4vec_min ( nst, jst );
  j_max = i4vec_max ( nst, jst );

  r8st_header_print ( i_min, i_max, j_min, j_max, m, n, nst );

  r8st_print ( m, n, nst, ist, jst, ast, "  Matrix data before sorting:" );

  r8st_sort_a ( m, n, nst, ist, jst, ast );

  r8st_print ( m, n, nst, ist, jst, ast, "  Matrix data sorted by column:" );

  return;
}
