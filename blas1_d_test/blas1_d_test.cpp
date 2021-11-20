# include <cmath>
# include <complex>
# include <cstdlib>
# include <ctime>
# include <iostream>
# include <iomanip>

using namespace std;

# include "blas0.hpp"
# include "blas1_d.hpp"

int main ( );
void dasum_test ( );
void daxpy_test ( );
void dcopy_test ( );
void ddot_test ( );
void dnrm2_test ( );
void drot_test ( );
void drotg_test ( );
void dscal_test ( );
void dswap_test ( );
void idamax_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for BLAS1_D_TEST.
//
//  Discussion:
//
//    BLAS1_D_TEST tests the BLAS1_D library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "BLAS1_D_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the BLAS1_D library.\n";

  dasum_test ( );
  daxpy_test ( );
  dcopy_test ( );
  ddot_test ( );
  dnrm2_test ( );
  drot_test ( );
  drotg_test ( );
  dscal_test ( );
  dswap_test ( );
  idamax_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "BLAS1_D_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void dasum_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DASUM_TEST tests DASUM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define LDA 6
# define MA 5
# define NA 4
# define NX 10

  double a[LDA*NA];
  int i;
  int j;
  double x[NX];

  for ( i = 0; i < NX; i++ )
  {
    x[i] = pow ( -1.0, i + 1 ) * ( double ) ( 2 * ( i + 1 ) );
  }

  cout << "\n";
  cout << "DASUM_TEST\n";
  cout << "  DASUM adds the absolute values of elements of a vector.\n";
  cout << "\n";
  cout << "  X = \n";
  cout << "\n";
  for ( i = 0; i < NX; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "\n";
  }

  cout << "\n";
  cout << "  DASUM ( NX,   X, 1 ) =    " << dasum ( NX,   x, 1 )    << "\n";
  cout << "  DASUM ( NX/2, X, 2 ) =    " << dasum ( NX/2, x, 2 )    << "\n";
  cout << "  DASUM ( 2,    X, NX/2 ) = " << dasum ( 2,    x, NX/2 ) << "\n";

  for ( i = 0; i < MA; i++ )
  {
    for ( j = 0; j < NA; j++ )
    {
      a[i+j*LDA] = pow ( -1.0, i + 1 + j + 1)
        * ( double ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  cout << "\n";
  cout << "  Demonstrate with a matrix A:\n";
  cout << "\n";
  for ( i = 0; i < MA; i++ )
  {
    for ( j = 0; j < NA; j++ )
    {
      cout << "  " << setw(14) << a[i+j*LDA];
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "  DASUM(MA,A(1,2),1) =   " << dasum ( MA, a+0+1*LDA, 1 )   << "\n";
  cout << "  DASUM(NA,A(2,1),LDA) = " << dasum ( NA, a+1+0*LDA, LDA ) << "\n";

  return;
# undef LDA
# undef MA
# undef NA
# undef NX
}
//****************************************************************************80

void daxpy_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DAXPY_TEST tests DAXPY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 6

  double da;
  int i;
  double x[N];
  double y[N];

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  cout << "\n";
  cout << "DAXPY_TEST\n";
  cout << "  DAXPY adds a multiple of vector X to vector Y.\n";
  cout << "\n";
  cout << "  X =\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "\n";
  }
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << y[i]  << "\n";
  }

  da = 1.0;
  daxpy ( N, da, x, 1, y, 1 );
  cout << "\n";
  cout << "  DAXPY ( N, " << da << ", X, 1, Y, 1 )\n";
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << y[i]  << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  da = -2.0;
  daxpy ( N, da, x, 1, y, 1 );
  cout << "\n";
  cout << "  DAXPY ( N, " << da << ", X, 1, Y, 1 )\n";
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << y[i]  << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  da = 3.0;
  daxpy ( 3, da, x, 2, y, 1 );
  cout << "\n";
  cout << "  DAXPY ( 3, " << da << ", X, 2, Y, 1 )\n";
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << y[i]  << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  da = -4.0;
  daxpy ( 3, da, x, 1, y, 2 );
  cout << "\n";
  cout << "  DAXPY ( 3, " << da << ", X, 1, Y, 2 )\n";
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << y[i]  << "\n";
  }

  return;
# undef N
}
//****************************************************************************80

void dcopy_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DCOPY_TEST demonstrates DCOPY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
  double a[5*5];
  int i;
  int j;
  double x[10];
  double y[10];

  cout << "\n";
  cout << "DCOPY_TEST\n";
  cout << "  DCOPY copies one vector into another.\n";
  cout << "\n";

  for ( i = 0; i < 10; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < 10; i++ )
  {
    y[i] = ( double ) ( 10 * ( i + 1 ) );
  }

  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      a[i+j*5] = ( double ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  cout << "\n";
  cout << "  X =\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "\n";
  }
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << y[i]  << "\n";
  }
  cout << "\n";
  cout << "  A =\n";
  cout << "\n";
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      cout << "  " << setw(14) << a[i+j*5];
    }
      cout << "\n";
  }

  dcopy ( 5, x, 1, y, 1 );
  cout << "\n";
  cout << "  DCOPY ( 5, X, 1, Y, 1 )\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << y[i]  << "\n";
  }

  for ( i = 0; i < 10; i++ )
  {
    y[i] = ( double ) ( 10 * ( i + 1 ) );
  }

  dcopy ( 3, x, 2, y, 3 );
  cout << "\n";
  cout << "  DCOPY ( 3, X, 2, Y, 3 )\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << y[i]  << "\n";
  }

  dcopy ( 5, x, 1, a, 1 );
  cout << "\n";
  cout << "  DCOPY ( 5, X, 1, A, 1 )\n";
  cout << "\n";
  cout << "  A =\n";
  cout << "\n";
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      cout << "  " << setw(14) << a[i+j*5];
    }
      cout << "\n";
  }

  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      a[i+j*5] = ( double ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  dcopy ( 5, x, 2, a, 5 );
  cout << "\n";
  cout << "  DCOPY ( 5, X, 2, A, 5 )\n";
  cout << "\n";
  cout << "  A =\n";
  cout << "\n";
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      cout << "  " << setw(14) << a[i+j*5];
    }
      cout << "\n";
  }

  return;
}
//****************************************************************************80

void ddot_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DDOT_TEST demonstrates DDOT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define LDA 10
# define LDB 7
# define LDC 6

  double a[LDA*LDA];
  double b[LDB*LDB];
  double c[LDC*LDC];
  int i;
  int j;
  double sum1;
  double x[N];
  double y[N];

  cout << "\n";
  cout << "DDOT_TEST\n";
  cout << "  DDOT computes the dot product of vectors.\n";
  cout << "\n";

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = - ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*LDA] = ( double ) ( i + 1 + j + 1 );
    }
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      b[i+j*LDB] = ( double ) ( ( i + 1 ) - ( j + 1 ) );
    }
  }

  sum1 = ddot ( N, x, 1, y, 1 );

  cout << "\n";
  cout << "  Dot product of X and Y is " << sum1 << "\n";
//
//  To multiply a ROW of a matrix A times a vector X, we need to
//  specify the increment between successive entries of the row of A:
//
  sum1 = ddot ( N, a+1+0*LDA, LDA, x, 1 );

  cout << "\n";
  cout << "  Product of row 2 of A and X is " << sum1 << "\n";
//
//  Product of a column of A and a vector is simpler:
//
  sum1 = ddot ( N, a+0+1*LDA, 1, x, 1 );

  cout << "\n";
  cout << "  Product of column 2 of A and X is " << sum1 << "\n";
//
//  Here's how matrix multiplication, c = a*b, could be done
//  with DDOT:
//
  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      c[i+j*LDC] = ddot ( N, a+i, LDA, b+0+j*LDB, 1 );
    }
  }

  cout << "\n";
  cout << "  Matrix product computed with DDOT:\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      cout << "  " << setw(14) << c[i+j*LDC];
    }
    cout << "\n";
  }

  return;
# undef N
# undef LDA
# undef LDB
# undef LDC
}

//****************************************************************************80

void dnrm2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DNRM2_TEST demonstrates DNRM2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 5
# define LDA 10
//
//  These parameters illustrate the fact that matrices are typically
//  dimensioned with more space than the user requires.
//
  double a[LDA*LDA];
  int i;
  int j;
  double x[N];

  cout << "\n";
  cout << "DNRM2_TEST\n";
  cout << "  DNRM2 computes the Euclidean norm of a vector.\n";
  cout << "\n";
//
//  Compute the euclidean norm of a vector:
//
  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  cout << "\n";
  cout << "  X =\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "\n";
  }
  cout << "\n";
  cout << "  The 2-norm of X is " << dnrm2 ( N, x, 1 ) << "\n";
//
//  Compute the euclidean norm of a row or column of a matrix:
//
  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*LDA] = ( double ) ( i + 1 + j + 1 );
    }
  }

  cout << "\n";
  cout << "  The 2-norm of row 2 of A is "
       << dnrm2 ( N, a+1+0*LDA, LDA ) << "\n";

  cout << "\n";
  cout << "  The 2-norm of column 2 of A is "
       << dnrm2 ( N, a+0+1*LDA, 1 ) << "\n";

  return;
# undef N
# undef LDA
}
//****************************************************************************80

void drot_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DROT_TEST tests DROT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 6

  double c;
  int i;
  double s;
  double x[N];
  double y[N];

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( ( i + 1 ) * ( i + 1 ) - 12 );
  }

  cout << "\n";
  cout << "DROT_TEST\n";
  cout << "  DROT carries out a Givens rotation.\n";
  cout << "\n";
  cout << "  X and Y\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "  "
         << setw(14) << y[i]  << "\n";
  }

  c = 0.5;
  s = sqrt ( 1.0 - c * c );
  drot ( N, x, 1, y, 1, c, s );
  cout << "\n";
  cout << "  DROT ( N, X, 1, Y, 1, " << c << "," << s << " )\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "  "
         << setw(14) << y[i]  << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( ( i + 1 ) * ( i + 1 ) - 12 );
  }

  c = x[0] / sqrt ( x[0] * x[0] + y[0] * y[0] );
  s = y[0] / sqrt ( x[0] * x[0] + y[0] * y[0] );
  drot ( N, x, 1, y, 1, c, s );
  cout << "\n";
  cout << "  DROT ( N, X, 1, Y, 1, " << c << "," << s << " )\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "  "
         << setw(14) << y[i]  << "\n";
  }

  return;
# undef N
}
//****************************************************************************80

void drotg_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DROTG_TEST tests DROTG.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double c;
  double r;
  double s;
  double sa;
  double sb;
  int seed;
  int test;
  int test_num = 5;
  double z;

  cout << "\n";
  cout << "DROTG_TEST\n";
  cout << "  DROTG generates a real Givens rotation\n";
  cout << "    (  C  S ) * ( A ) = ( R )\n";
  cout << "    ( -S  C )   ( B )   ( 0 )\n";
  cout << "\n";

  seed = 123456789;

  for ( test = 1; test <= test_num; test++ )
  {
    a = r8_uniform_01 ( seed );
    b = r8_uniform_01 ( seed );

    sa = a;
    sb = b;

    drotg ( &sa, &sb, &c, &s );

    r = sa;
    z = sb;

    cout << "\n";
    cout << "  A =  " << a << "  B =  " << b << "\n";
    cout << "  C =  " << c << "  S =  " << s << "\n";
    cout << "  R =  " << r << "  Z =  " << z << "\n";
    cout << "   C*A+S*B = " <<  c * a + s * b << "\n";
    cout << "  -S*A+C*B = " << -s * a + c * b << "\n";
  }

  return;
}
//****************************************************************************80

void dscal_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DSCAL_TEST tests DSCAL.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 6

  double da;
  int i;
  double x[N];

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  cout << "\n";
  cout << "DSCAL_TEST\n";
  cout << "  DSCAL multiplies a vector by a scalar.\n";
  cout << "\n";
  cout << "  X =\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "\n";
  }

  da = 5.0;
  dscal ( N, da, x, 1 );
  cout << "\n";
  cout << "  DSCAL ( N, " << da << ", X, 1 )\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  da = -2.0;
  dscal ( 3, da, x, 2 );
  cout << "\n";
  cout << "  DSCAL ( 3, " << da << ", X, 2 )\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "\n";
  }

  return;
# undef N
}
//****************************************************************************80

void dswap_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DSWAP_TEST tests DSWAP.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 6

  int i;
  double x[N];
  double y[N];

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  cout << "\n";
  cout << "DSWAP_TEST\n";
  cout << "  DSWAP swaps two vectors.\n";
  cout << "\n";
  cout << "  X and Y:\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "  "
         << setw(14) << y[i]  << "\n";
  }

  dswap ( N, x, 1, y, 1 );
  cout << "\n";
  cout << "  DSWAP ( N, X, 1, Y, 1 )\n";
  cout << "\n";
  cout << "  X and Y:\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "  "
         << setw(14) << y[i]  << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( double ) ( 100 * ( i + 1 ) );
  }

  dswap ( 3, x, 2, y, 1 );
  cout << "\n";
  cout << "  DSWAP ( 3, X, 2, Y, 1 )\n";

  cout << "\n";
  cout << "  X and Y:\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  "
         << setw(6)  << i + 1 << "  "
         << setw(14) << x[i]  << "  "
         << setw(14) << y[i]  << "\n";
  }

  return;
# undef N
}
//****************************************************************************80

void idamax_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    IDAMAX_TEST demonstrates IDAMAX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    23 February 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 11

  int i;
  int i1;
  int incx;
  double x[N];

  cout << "\n";
  cout << "IDAMAX_TEST\n";
  cout << "  IDAMAX returns the index of maximum magnitude;\n";

  for ( i = 1; i <= N; i++ )
  {
    x[i-1] = ( double ) ( ( 7 * i ) % 11 ) - ( double ) ( N / 2 );
  }

  cout << "\n";
  cout << "  The vector X:\n";
  cout << "\n";

  for ( i = 1; i <= N; i++ )
  {
    cout << "  " << setw(6) << i
         << "  " << setw(8) << x[i-1] << "\n";
  }

  incx = 1;

  i1 = idamax ( N, x, incx );

  cout << "\n";
  cout << "  The index of maximum magnitude = " << i1 << "\n";

  return;
# undef N
}

