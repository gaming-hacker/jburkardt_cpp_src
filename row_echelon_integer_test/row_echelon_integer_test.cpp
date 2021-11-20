# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "row_echelon_integer.hpp"

int main ( );
void i4_gcd_test ( );
void i4_max_test ( );
void i4_min_test ( );
void i4mat_print_test ( );
void i4mat_print_some_test ( );
void i4mat_ref_test ( );
void i4mat_row_reduce_test ( );
void i4mat_row_swap_test ( );
void i4mat_rref_test ( );
void i4mat_u_solve_test ( );
void i4vec_binary_next_test ( );
void i4vec_is_binary_test ( );
void i4vec_print_test ( );
void i4vec_red_test ( );
void i4vec_transpose_print_test ( );
void ksub_next4_test ( );
void r8vec_is_integer_test ( );
void r8vec_print_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for ROW_ECHELON_INTEGER_TEST.
//
//  Discussion:
//
//    ROW_ECHELON_INTEGER_TEST tests the ROW_ECHELON_INTEGER library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 September 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "ROW_ECHELON_INTEGER_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the ROW_ECHELON_INTEGER library.\n";

  i4_gcd_test ( );
  i4_max_test ( );
  i4_min_test ( );

  i4mat_print_test ( );
  i4mat_print_some_test ( );
  i4mat_ref_test ( );
  i4mat_row_reduce_test ( );
  i4mat_row_swap_test ( );
  i4mat_rref_test ( );
  i4mat_u_solve_test ( );

  i4vec_binary_next_test ( );
  i4vec_is_binary_test ( );
  i4vec_print_test ( );
  i4vec_red_test ( );
  i4vec_transpose_print_test ( );

  ksub_next4_test ( );

  r8vec_is_integer_test ( );
  r8vec_print_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "ROW_ECHELON_INTEGER_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void i4_gcd_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_GCD_TEST tests I4_GCD.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 September 2005
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int i_test[7] = { 36, 49, 0, 12, 36, 1, 91 };
  int j;
  int j_test[7] = { 30, -7, 71, 12, 49, 42, 28 };
  int test;
 
  cout << "\n";
  cout << "I4_GCD_TEST\n";
  cout << "  I4_GCD computes the greatest common factor,\n";
  cout << "\n";
  cout << "     I     J   I4_GCD\n";
  cout << "\n";

  for ( test = 0; test < 7; test++ )
  {
    i = i_test[test];
    j = j_test[test];
    cout << "  " << setw(6) << i
         << "  " << setw(6) << j
         << "  " << setw(6) << i4_gcd ( i, j ) << "\n";
  }

  return;
}
//****************************************************************************80

void i4_max_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MAX_TEST tests I4_MAX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 March 2015
//
//  Author:
//
//    John Burkardt
//
{
  int a;
  int a_test[] = { -57,  66, -17, -49, -92, -88, -20,   60,  80, -81 };
  int b;
  int b_test[] = {  92,  12, -87, -78,  27, -10,  51, -100, -30, -98 };
  int c;
  int i;

  cout << "\n";
  cout << "I4_MAX_TEST\n";
  cout << "  I4_MAX returns the maximum of two I4's.\n";
  cout << "\n";
  cout << "       A       B      C=I4_MAX(A,B)\n";
  cout << "\n";

  for ( i = 0; i < 10; i++ )
  {
    a = a_test[i];
    b = b_test[i];
    c = i4_max ( a, b );
    cout << "  " << setw(8) << a
         << "  " << setw(8) << b
         << "  " << setw(8) << c << "\n";
  }

  return;
}
//****************************************************************************80

void i4_min_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4_MIN_TEST tests I4_MIN.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 March 2015
//
//  Author:
//
//    John Burkardt
//
{
  int a;
  int a_test[] = { -57,  66, -17, -49, -92, -88, -20,   60,  80, -81 };
  int b;
  int b_test[] = {  92,  12, -87, -78,  27, -10,  51, -100, -30, -98 };
  int c;
  int i;

  cout << "\n";
  cout << "I4_MIN_TEST\n";
  cout << "  I4_MIN returns the minimum of two I4's.\n";
  cout << "\n";
  cout << "       A       B      C=I4_MIN(A,B)\n";
  cout << "\n";

  for ( i = 0; i < 10; i++ )
  {
    a = a_test[i];
    b = b_test[i];
    c = i4_min ( a, b );
    cout << "  " << setw(8) << a
         << "  " << setw(8) << b
         << "  " << setw(8) << c << "\n";
  }

  return;
}
//****************************************************************************80

void i4mat_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_PRINT_TEST tests I4MAT_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int a[5*4];
  int i;
  int j;
  int m = 5;
  int n = 4;

  cout << "\n";
  cout << "I4MAT_PRINT_TEST\n";
  cout << "  I4MAT_PRINT prints an I4MAT.\n";

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( i + 1 ) * 10 + ( j + 1 );
    }
  }

  i4mat_print ( m, n, a, "  The matrix:" );

  return;
}
//****************************************************************************80

void i4mat_print_some_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_PRINT_SOME_TEST tests I4MAT_PRINT_SOME.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int a[5*4];
  int i;
  int j;
  int m = 5;
  int n = 4;

  cout << "\n";
  cout << "I4MAT_PRINT_SOME_TEST\n";
  cout << "  I4MAT_PRINT_SOME prints some of an I4MAT.\n";

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( i + 1 ) * 10 + ( j + 1 );
    }
  }

  i4mat_print_some ( m, n, a, 1, 0, 3, 1, "  The I4MAT, rows 1:3, cols 0:1:" );

  return;
}
//****************************************************************************80

void i4mat_ref_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_REF_TEST tests I4MAT_REF.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int a[4*7] = {
    1, -2, 3, -1,
    3, -6, 9, -3,
    0,  0, 0,  0,
    2, -2, 0,  1,
    6, -8, 6,  0,
    3,  3, 6,  9,
    1,  1, 2,  3 };
  int det;
  int m = 4;
  int n = 7;

  cout << "\n";
  cout << "I4MAT_REF_TEST\n";
  cout << "  I4MAT_REF computes the integer row echelon form (IREF) of a matrix.\n";

  i4mat_print ( m, n, a, "  Input A:" );

  det = i4mat_ref ( m, n, a );

  cout << "\n";
  cout << "  Pseudo-determinant = " << det << "\n";

  i4mat_print ( m, n, a, "  IREF form:" );

  return;
}
//****************************************************************************80

void i4mat_row_reduce_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_ROW_REDUCE_TEST tests I4MAT_ROW_REDUCE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int a[5*3] = {
    12,   4, -12, 30, 0, 
    88,   8,  88, 18, 4, 
     9, 192,  94, 42, 8 };
  int i;
  int m = 5;
  int n = 3;

  cout << "\n";
  cout << "I4MAT_ROW_REDUCE_TEST\n";
  cout << "  I4MAT_ROW_REDUCE divides a common factor from row I of an I4MAT;\n";

  i4mat_print ( m, n, a, "  Original matrix:" );

  for ( i = m - 1; 0 <= i; i-- )
  {
    i4mat_row_reduce ( m, n, i, a );

    i4mat_print ( m, n, a, "  After reducing a row:" );
  }

  return;
}
//****************************************************************************80

void i4mat_row_swap_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_ROW_SWAP_TEST tests I4MAT_ROW_SWAP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2018
//
//  Author:
//
//    John Burkardt
//
{
  int a[5*4];
  int i;
  int i1;
  int i2;
  int j;
  int m = 5;
  int n = 4;

  cout << "\n";
  cout << "I4MAT_ROW_SWAP_TEST\n";
  cout << "  I4MAT_ROW_SWAP swaps two rows of an I4MAT.\n";

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      a[i+j*m] = 10 * ( i + 1 ) + j + 1;
    }
  }

  i4mat_print ( m, n, a, "  Input A:" );

  i1 = 1;
  i2 = 4;
  cout << "\n";
  cout << "  Swap rows " << i1 << " and " << i2 << "\n";

  i4mat_row_swap ( m, n, a, i1, i2 );

  i4mat_print ( m, n, a, "  Modified matrix:" );

  return;
}
//****************************************************************************80

void i4mat_rref_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_RREF_TEST tests I4MAT_RREF.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    27 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int a[4*7] = {
    1, -2, 3, -1,
    3, -6, 9, -3,
    0,  0, 0,  0,
    2, -2, 0,  1,
    6, -8, 6,  0,
    3,  3, 6,  9,
    1,  1, 2,  3 };
  int det;
  int m = 4;
  int n = 7;

  cout << "\n";
  cout << "I4MAT_RREF_TEST\n";
  cout << "  I4MAT_RREF computes the \n";
  cout << "  integer row reduced echelon form (IRREF) of a matrix.\n";

  i4mat_print ( m, n, a, "  Input A:" );

  det = i4mat_rref ( m, n, a );

  cout << "\n";
  cout << "  Pseudo-determinant = " << det << "\n";

  i4mat_print ( m, n, a, "  IRREF form:" );

  return;
}
//****************************************************************************80

void i4mat_u_solve_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_U_SOLVE_TEST tests I4MAT_U_SOLVE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 July 2015
//
//  Author:
//
//    John Burkardt
//
{
//
//  Each row of this definition is a COLUMN of the matrix.
//
  int a[4*4] = {
    1, 0, 0,  0,
    2, 3, 0,  0,
    4, 5, 6,  0,
    7, 8, 9, 10 };
  int b[4] = { 45, 53, 54, 40 };
  int i;
  int j;
  int n = 4;
  double *r;
  double rnorm;
  double *x;

  cout << "\n";
  cout << "I4MAT_U_SOLVE_TEST\n";
  cout << "  I4MAT_U_SOLVE solves an upper triangular system.\n";

  i4mat_print ( n, n, a, "  Input matrix A:" );

  i4vec_print ( n, b, "  Right hand side b:" );

  x = i4mat_u_solve ( n, a, b );

  r8vec_print ( n, x, "  Solution x:" );

  r = new double[n];
  rnorm = 0.0;
  for ( i = 0; i < n; i++ )
  {
    r[i] = ( double ) b[i];
    for ( j = 0; j < n; j++ )
    {
      r[i] = r[i] - ( double ) a[i+j*n] * x[j];
    }
    rnorm = rnorm + r[i] * r[i];
  }
  rnorm = sqrt ( rnorm );

  cout << "\n";
  cout << "  Norm of residual = " << rnorm << "\n";

  delete [] r;
  delete [] x;

  return;
}
//****************************************************************************80

void i4vec_binary_next_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_BINARY_NEXT_TEST tests I4VEC_BINARY_NEXT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    31 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  int bvec[3];
  int i;
  int n = 3;

  cout << "\n";
  cout << "I4VEC_BINARY_NEXT_TEST\n";
  cout << "  I4VEC_BINARY_NEXT generates the next binary vector.\n";
  cout << "\n";
 
  for ( i = 0; i < n; i++ )
  {
    bvec[i] = 0;
  }

  while ( true )
  {
    i4vec_transpose_print ( n, bvec, "" );

    if ( i4vec_is_one ( n, bvec ) )
    {
      break;
    }

    i4vec_binary_next ( n, bvec );
  }

  return;
}
//****************************************************************************80

void i4vec_is_binary_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_IS_BINARY_TEST tests I4VEC_IS_BINARY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  int n = 3;
  int x1[3] = { 0, 0, 0 };
  int x2[3] = { 1, 0, 1 };
  int x3[3] = { 0, 2, 1 };

  cout << "\n";
  cout << "I4VEC_IS_BINARY_TEST\n";
  cout << "  I4VEC_IS_BINARY is TRUE if an I4VEC only contains\n";
  cout << "  0 or 1 entries.\n";

  cout << "\n";
  i4vec_transpose_print ( n, x1, "  X:" );
  if ( i4vec_is_binary ( n, x1 ) )
  {
    cout << "  X is binary.\n";
  }
  else
  {
    cout << "  X is NOT binary.\n";
  }

  cout << "\n";
  i4vec_transpose_print ( n, x2, "  X:" );
  if ( i4vec_is_binary ( n, x2 ) )
  {
    cout << "  X is binary.\n";
  }
  else
  {
    cout << "  X is NOT binary.\n";
  }

  cout << "\n";
  i4vec_transpose_print ( n, x3, "  X:" );
  if ( i4vec_is_binary ( n, x3 ) )
  {
    cout << "  X is binary.\n";
  }
  else
  {
    cout << "  X is NOT binary.\n";
  }

  return;
}
//****************************************************************************80

void i4vec_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_PRINT_TEST tests I4VEC_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 October 2014
//
//  Author:
//
//    John Burkardt
//
{
  int n = 4;
  int v[4] = { 91, 92, 93, 94 };

  cout << "\n";
  cout << "I4VEC_PRINT_TEST\n";
  cout << "  I4VEC_PRINT prints an I4VEC\n";

  i4vec_print ( n, v, "  Here is the I4VEC:" );

  return;
}
//****************************************************************************80

void i4vec_red_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_RED_TEST tests I4VEC_RED.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int a[5*3] = {
    12,   4, -12, 30, 0, 
    88,   8,  88, 18, 4, 
     9, 192,  94, 42, 8 };
  int i;
  int j;
  int m = 5;
  int n = 3;
  int row[3];

  cout << "\n";
  cout << "I4VEC_RED_TEST\n";
  cout << "  I4VEC_RED divides out any common factors in the\n";
  cout << "  entries of an I4VEC.\n";

  i4mat_print ( m, n, a, "  Apply I4VEC_RED to each row of this matrix:" );

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      row[j] = a[i+j*m];
    }
    i4vec_red ( n, row );
    for ( j = 0; j < n; j++ )
    {
      a[i+j*m] = row[j];
    }
  }

  i4mat_print ( m, n, a, "  Reduced matrix:" );

  return;
}
//****************************************************************************80

void i4vec_transpose_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_TRANSPOSE_PRINT_TEST tests I4VEC_TRANSPOSE_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 October 2006
//
//  Author:
//
//    John Burkardt
//
{
  int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
  int n = 12;

  cout << "\n";
  cout << "I4VEC_TRANSPOSE_PRINT_TEST\n";
  cout << "  I4VEC_TRANSPOSE_PRINT prints an integer vector\n";
  cout << "  with 5 entries to a row, and an optional title.\n";

  i4vec_print ( n, a, "  Output from I4VEC_PRINT:" );

  cout << "\n";
  cout << "  Now call I4VEC_TRANSPOSE_PRINT with a short title:\n";
  cout << "\n";

  i4vec_transpose_print ( n, a, "  My array:  " );

  cout << "\n";
  cout << "  Now call I4VEC_TRANSPOSE_PRINT with no title:\n";
  cout << "\n";

  i4vec_transpose_print ( n, a, " " );

  return;
}
//****************************************************************************80

void ksub_next4_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    KSUB_NEXT4_TEST tests KSUB_NEXT4.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    02 December 2006
//
//  Author:
//
//    John Burkardt
//
{
# define K 3

  int a[K];
  bool done;
  int i;
  int n = 5;
  int rank;

  cout << "\n";
  cout << "KSUB_NEXT4_TEST\n";
  cout << "  KSUB_NEXT4 generates K subsets of an N set.\n";
  cout << "  N = " << n << "\n";
  cout << "  K = " << K << "\n";
  cout << "\n";
  cout << "Rank    Subset\n";
  cout << "\n";

  done = true;
  rank = 0;
 
  for ( ; ; )
  {
    ksub_next4 ( n, K, a, done );
 
    if ( done )
    {
      break;
    }

    rank = rank + 1;
    cout << setw(4) << rank << "  ";
    cout << "  ";
    for ( i = 0; i < K; i++ )
    {
      cout << setw(4) << a[i] << "  ";
    }
    cout << "\n";

  }
 
  return;
# undef K
}
//****************************************************************************80

void r8vec_is_integer_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_IS_INTEGER_TEST tests R8VEC_IS_INTEGER.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int n = 6;
  double x1[6] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
  double x2[6] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.5 };
  double x3[6] = { 1.0, 2.0, 3.0000001, 4.0, 5.0, 6.0 };
  double x4[6] = { 1.0, 2.0, 300000000.2, 4.0, 5.0, 6.0 };

  cout << "\n";
  cout << "R8VEC_IS_INTEGER_TEST\n";
  cout << "  R8VEC_IS_INTEGER is TRUE if an R8VEC only contains\n";
  cout << "  integer entries.\n";

  cout << "\n";
  cout << "  Example 1: Obviously integer:\n";
  cout << "\n";
  r8vec_transpose_print ( n, x1, "  X:" );
  if ( r8vec_is_integer ( n, x1 ) )
  {
    cout << "  X is integer.\n";
  }
  else
  {
    cout << "  X is NOT integer.\n";
  }

  cout << "\n";
  cout << "  Example 2: Obviously NOT integer:\n";
  cout << "\n";
  r8vec_transpose_print ( n, x2, "  X:" );
  if ( r8vec_is_integer ( n, x2 ) )
  {
    cout << "  X is integer.\n";
  }
  else
  {
    cout << "  X is NOT integer.\n";
  }

  cout << "\n";
  cout << "  Example 3: Not obviously not integer:\n";
  cout << "\n";
  r8vec_transpose_print ( n, x3, "  X:" );
  if ( r8vec_is_integer ( n, x3 ) )
  {
    cout << "  X is integer.\n";
  }
  else
  {
    cout << "  X is NOT integer.\n";
  }

  cout << "\n";
  cout << "  Example 4: Not obviously not integer:\n";
  cout << "\n";
  r8vec_transpose_print ( n, x4, "  X:" );
  if ( r8vec_is_integer ( n, x4 ) )
  {
    cout << "  X is integer.\n";
  }
  else
  {
    cout << "  X is NOT integer.\n";
  }

  return;
}
//****************************************************************************80

void r8vec_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT_TEST tests R8VEC_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
  double a[4] = { 123.456, 0.000005, -1.0E+06, 3.14159265 };
  int n = 4;

  cout << "\n";
  cout << "R8VEC_PRINT_TEST\n";
  cout << "  R8VEC_PRINT prints an R8VEC.\n";

  r8vec_print ( n, a, "  The R8VEC:" );

  return;
}

