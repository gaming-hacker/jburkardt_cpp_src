# include <cmath>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "f2c.h"
# include "blaswrap.h"
# include "clapack.h"

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
void r8vec_print ( int n, double a[], string title );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for CBLAS_TEST.
//
//  Discussion:
//
//    CBLAS_TEST tests the CBLAS library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "CBLAS_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the CBLAS library.\n";
//
//  Test the double precision real level 1 CBLAS:
//
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
  cout << "CBLAS_TEST:\n";
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
//    05 October 2018
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

  doublereal a[LDA*NA];
  integer i;
  integer INCX;
  integer j;
  integer N;
  doublereal x[NX];

  for ( i = 0; i < NX; i++ )
  {
    x[i] = pow ( -1.0, i + 1 ) * ( doublereal ) ( 2 * ( i + 1 ) );
  }

  cout << "\n";
  cout << "DASUM_TEST\n";
  cout << "  DASUM adds the absolute values of elements of a vector.\n";
  cout << "\n";
  cout << "  X = \n";
  cout << "\n";
  for ( i = 0; i < NX; i++ )
  {
    cout << "  " << i + 1 << "  " << x[i] << "\n";
  }

  cout << "\n";

  N = NX;
  INCX = 1;
  cout << "  DASUM ( NX,   X, 1 ) =    " << dasum_ ( &N, x, &INCX ) << "\n";

  N = NX / 2;
  INCX = 2;
  cout << "  DASUM ( NX/2, X, 2 ) =    " <<  dasum_ ( &N, x, &INCX ) << "\n";

  N = 2;
  INCX = NX / 2;
  cout << "  DASUM ( 2,    X, NX/2 ) = " <<  dasum_ ( &N, x, &INCX ) << "\n";

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
      cout << "  " << a[i+j*LDA];
    }
    cout << "\n";
  }

  cout << "\n";
  N = MA;
  INCX = 1;
  cout << "  DASUM(MA,A(1,2),1) =   " << dasum_ ( &N, a+0+1*LDA, &INCX ) << "\n";

  N = NA;
  INCX = LDA;
  cout << "  DASUM(NA,A(2,1),LDA) = " << dasum_ ( &N, a+1+0*LDA, &INCX ) << "\n";

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
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  doublereal da;
  integer i;
  integer INCX;
  integer INCY;
  integer N;
  doublereal x[6];
  doublereal y[6];

  for ( i = 0; i < 6; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < 6; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  cout << "\n";
  cout << "DAXPY_TEST\n";
  cout << "  DAXPY adds a multiple of vector X to vector Y.\n";
  cout << "\n";
  cout << "  X =\n";
  cout << "\n";
  for ( i = 0; i < 6; i++ )
  {
    cout << "  " << i+1 << "  " << x[i] << "\n";
  }
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < 6; i++ )
  {
    cout << "  " << i+1 << "  " << y[i] << "\n";
  }

  N = 6;
  da = 1.0;
  INCX = 1;
  INCY = 1;

  daxpy_ ( &N, &da, x, &INCX, y, &INCY );
  cout << "\n";
  cout << "  DAXPY ( N, " << da << ", X, 1, Y, 1 )\n";
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < 6; i++ )
  {
    cout << "  " << i+1 << "  " << y[i] << "\n";
  }

  for ( i = 0; i < 6; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  N = 6;
  da = -2.0;
  INCX = 1;
  INCY = 1;

  daxpy_ ( &N, &da, x, &INCX, y, &INCY );
  cout << "\n";
  cout << "  DAXPY ( N, " << da << ", X, 1, Y, 1 )\n";
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < 6; i++ )
  {
    cout << "  " << i+1 << "  " << y[i] << "\n";
  }

  for ( i = 0; i < 6; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  N = 3;
  da = 3.0;
  INCX = 2;
  INCY = 1;

  daxpy_ ( &N, &da, x, &INCX, y, &INCY );
  cout << "\n";
  cout << "  DAXPY ( 3, " << da << ", X, 2, Y, 1 )\n";
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < 6; i++ )
  {
    cout << "  " << i+1 << "  " << y[i] << "\n";
  }

  for ( i = 0; i < 6; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  N = 3;
  da = -4.0;
  INCX = 1;
  INCY = 2;

  daxpy_ ( &N, &da, x, &INCX, y, &INCY );
  cout << "\n";
  cout << "  DAXPY ( 3, " << da << ", X, 1, Y, 2 )\n";
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < 6; i++ )
  {
    cout << "  " << i+1 << "  " << y[i] << "\n";
  }

  return;
}
//****************************************************************************80

void dcopy_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DCOPY_TEST tests DCOPY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  doublereal a[5*5];
  integer i;
  integer INCX;
  integer INCY;
  integer j;
  integer N;
  doublereal x[10];
  doublereal y[10];

  cout << "\n";
  cout << "DCOPY_TEST\n";
  cout << "  DCOPY copies one vector into another.\n";
  cout << "\n";

  for ( i = 0; i < 10; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < 10; i++ )
  {
    y[i] = ( doublereal ) ( 10 * ( i + 1 ) );
  }

  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      a[i+j*5] = ( doublereal ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  cout << "\n";
  cout << "  X =\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  " << i + 1 << x[i] << "\n";
  }
  cout << "\n";
  cout << "  Y =\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  " << i+1 << "  " << y[i] << "\n";
  }
  cout << "\n";
  cout << "  A =\n";
  cout << "\n";
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      cout << "  " << a[i+j*5];
    }
      cout << "\n";
  }

  N = 5;
  INCX = 1;
  INCY = 1;
  dcopy_ ( &N, x, &INCX, y, &INCY );
  cout << "\n";
  cout << "  DCOPY ( 5, X, 1, Y, 1 )\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  " << i+1 << "  " << y[i] << "\n";
  }

  for ( i = 0; i < 10; i++ )
  {
    y[i] = ( doublereal ) ( 10 * ( i + 1 ) );
  }

  N = 3;
  INCX = 2;
  INCY = 3;
  dcopy_ ( &N, x, &INCX, y, &INCY );
  cout << "\n";
  cout << "  DCOPY ( 3, X, 2, Y, 3 )\n";
  cout << "\n";
  for ( i = 0; i < 10; i++ )
  {
    cout << "  " << i+1 << "  " << y[i] << "\n";
  }

  N = 5;
  INCX = 1;
  INCY = 1;
  dcopy_ ( &N, x, &INCX, a, &INCY );
  cout << "\n";
  cout << "  DCOPY ( 5, X, 1, A, 1 )\n";
  cout << "\n";
  cout << "  A =\n";
  cout << "\n";
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      cout << "  " << a[i+j*5];
    }
      cout << "\n";
  }

  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      a[i+j*5] = ( doublereal ) ( 10 * ( i + 1 ) + j + 1 );
    }
  }

  N = 5;
  INCX = 2;
  INCY = 5;
  dcopy_ ( &N, x, &INCX, a, &INCY );
  cout << "\n";
  cout << "  DCOPY ( 5, X, 2, A, 5 )\n";
  cout << "\n";
  cout << "  A =\n";
  cout << "\n";
  for ( i = 0; i < 5; i++ )
  {
    for ( j = 0; j < 5; j++ )
    {
      cout << "  " << a[i+j*5];
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
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
# define LDA 10
# define LDB 7
# define LDC 6

  doublereal a[LDA*LDA];
  doublereal b[LDB*LDB];
  doublereal c[LDC*LDC];
  integer i;
  integer INCX;
  integer INCY;
  integer j;
  integer N;
  doublereal sum1;
  doublereal x[10];
  doublereal y[10];

  cout << "\n";
  cout << "DDOT_TEST\n";
  cout << "  DDOT computes the dot product of vectors.\n";
  cout << "\n";

  N = 10;
  for ( i = 0; i < N; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = - ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      a[i+j*LDA] = ( doublereal ) ( i + 1 + j + 1 );
    }
  }

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      b[i+j*LDB] = ( doublereal ) ( ( i + 1 ) - ( j + 1 ) );
    }
  }

  N = 10;
  INCX = 1;
  INCY = 1;
  sum1 = ddot_ ( &N, x, &INCX, y, &INCY );

  cout << "\n";
  cout << "  Dot product of X and Y is " << sum1 << "\n";
//
//  To multiply a ROW of a matrix A times a vector X, we need to
//  specify the increment between successive entries of the row of A:
//
  N = 10;
  INCX = LDA;
  INCY = 1;
  sum1 = ddot_ ( &N, a+1+0*LDA, &INCX, x, &INCY );

  cout << "\n";
  cout << "  Product of row 2 of A and X is " << sum1 << "\n";
//
//  Product of a column of A and a vector is simpler:
//
  N = 10;
  INCX = 1;
  INCY = 1;
  sum1 = ddot_ ( &N, a+0+1*LDA, &INCX, x, &INCY );

  cout << "\n";
  cout << "  Product of column 2 of A and X is " << sum1 << "\n";
//
//  Here's how matrix multiplication, c = a*b, could be done with DDOT:
//
  N = 10;
  INCX = LDA;
  INCY = 1;

  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      c[i+j*LDC] = ddot_ ( &N, a+i, &INCX, b+0+j*LDB, &INCY );
    }
  }

  cout << "\n";
  cout << "  Matrix product computed with DDOT:\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    for ( j = 0; j < N; j++ )
    {
      cout << "  " << c[i+j*LDC];
    }
    cout << "\n";
  }

  return;
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
//    DNRM2_TEST tests DNRM2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  doublereal *X;
  integer INCX;
  integer N;
  doublereal VALUE;

  N = 3;
  X = ( doublereal * ) malloc ( N * sizeof ( doublereal ) );
  X[0] = 1.0;
  X[1] = 2.0;
  X[2] = 3.0;
  INCX = 1;

  cout << "\n";
  cout << "DNRM2_TEST\n";
  cout << "  For a double precision real vector (D)\n";
  cout << "  DNRM2 computes the Euclidean norm.\n";

  r8vec_print ( N, X, "  The vector X:" );

  VALUE = dnrm2_ ( &N, X, &INCX );

  cout << "\n";
  cout << "  VALUE = " << VALUE << "\n";

  return;
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
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  doublereal c;
  integer i;
  integer INCX;
  integer INCY;
  integer N;
  doublereal s;
  doublereal x[6];
  doublereal y[6];

  N = 6;
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
    cout << "  " << i+1 << "  " << x[i] << "  " << y[i] << "\n";
  }

  N = 6;
  INCX = 1;
  INCY = 1;
  c = 0.5;
  s = sqrt ( 1.0 - c * c );

  drot_ ( &N, x, &INCX, y, &INCY, &c, &s );

  cout << "\n";
  cout << "  DROT ( N, X, 1, Y, 1, " << c << ", " << s << " )\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  " << i+1 << "  " << x[i] << "  " << y[i] << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( doublereal ) ( ( i + 1 ) * ( i + 1 ) - 12 );
  }

  N = 6;
  INCX = 1;
  INCY = 1;
  c = x[0] / sqrt ( x[0] * x[0] + y[0] * y[0] );
  s = y[0] / sqrt ( x[0] * x[0] + y[0] * y[0] );

  drot_ ( &N, x, &INCX, y, &INCY, &c, &s );

  cout << "\n";
  cout << "  DROT ( N, X, 1, Y, 1, " << c << ", " << s << " )\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  " << i+1 << "  " << x[i] << "  " << y[i] << "\n";
  }

  return;
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
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  doublereal a;
  doublereal b;
  doublereal c;
  doublereal r;
  doublereal s;
  doublereal sa;
  doublereal sb;
  integer test;
  doublereal z;

  cout << "\n";
  cout << "DROTG_TEST\n";
  cout << "  DROTG generates a real Givens rotation\n";
  cout << "    (  C  S ) * ( A ) = ( R )\n";
  cout << "    ( -S  C )   ( B )   ( 0 )\n";
  cout << "\n";

  for ( test = 1; test <= 5; test++ )
  {
    if ( test == 1 )
    {
      a =  0.218418;
      b =  0.956318;
    }
    else if ( test == 2 )
    {
      a =  0.829509;
      b =  0.561695;
    }
    else if ( test == 3 )
    {
      a =  0.415307;
      b =  0.066119;
    }
    else if ( test == 4 )
    {
      a =  0.257578;
      b =  0.109957;
    }
    else if ( test == 5 )
    {
      a =  0.043829;
      b =  0.633966;
    }

    sa = a;
    sb = b;

    drotg_ ( &sa, &sb, &c, &s );

    r = sa;
    z = sb;

    cout << "\n";
    cout << "  A =  " << a << ",  B =  " << b << "\n";
    cout << "  C =  " << c << ",  S =  " << s << "\n";
    cout << "  R =  " << r << ",  Z =  " << z << "\n";
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
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  doublereal da;
  integer i;
  integer INCX;
  integer N;
  doublereal x[6];

  N = 6;
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
    cout << "  " << i + 1 << x[i] << "\n";
  }

  N = 6;
  da = 5.0;
  INCX = 1;
  dscal_ ( &N, &da, x, &INCX );
  cout << "\n";
  cout << "  DSCAL ( N, " << da << ", X, 1 )\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  " << i + 1 << x[i] << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( double ) ( i + 1 );
  }

  N = 3;
  da = -2.0;
  INCX = 2;
  dscal_ ( &N, &da, x, &INCX );

  N = 6;
  cout << "\n";
  cout << "  DSCAL ( 3, " << da << ", X, 2 )\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  " << i + 1 << x[i] << "\n";
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
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  integer i;
  integer INCX;
  integer INCY;
  integer N;
  double x[6];
  double y[6];

  N = 6;
  for ( i = 0; i < N; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  cout << "\n";
  cout << "DSWAP_TEST\n";
  cout << "  DSWAP swaps two vectors.\n";
  cout << "\n";
  cout << "  X and Y:\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  " << i+1 << "  " << x[i] << "  " << y[i] << "\n";
  }

  N = 6;
  INCX = 1;
  INCY = 1;
  dswap_ ( &N, x, &INCX, y, &INCY );
  cout << "\n";
  cout << "  DSWAP ( N, X, 1, Y, 1 )\n";
  cout << "\n";
  cout << "  X and Y:\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  " << i+1 << "  " << x[i] << "  " << y[i] << "\n";
  }

  for ( i = 0; i < N; i++ )
  {
    x[i] = ( doublereal ) ( i + 1 );
  }

  for ( i = 0; i < N; i++ )
  {
    y[i] = ( doublereal ) ( 100 * ( i + 1 ) );
  }

  N = 3;
  INCX = 2;
  INCY = 1;
  dswap_ ( &N, x, &INCX, y, &INCY );
  cout << "\n";
  cout << "  DSWAP ( 3, X, 2, Y, 1 )\n";

  N = 6;
  cout << "\n";
  cout << "  X and Y:\n";
  cout << "\n";
  for ( i = 0; i < N; i++ )
  {
    cout << "  " << i+1 << "  " << x[i] << "  " << y[i] << "\n";
  }

  return;
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
//    05 October 2018
//
//  Author:
//
//    John Burkardt
//
{
  integer i;
  integer i1;
  integer incx;
  integer n = 11;
  doublereal *x;;

  x = ( doublereal * ) malloc ( n * sizeof ( doublereal ) );

  cout << "\n";
  cout << "IDAMAX_TEST\n";
  cout << "  IDAMAX returns the index of maximum magnitude;\n";

  for ( i = 1; i <= n; i++ )
  {
    x[i-1] = ( doublereal ) ( ( 7 * i ) % 11 ) - ( doublereal ) ( n / 2 );
  }

  cout << "\n";
  cout << "  The vector X:\n";
  cout << "\n";

  for ( i = 0; i < n; i++ )
  {
    cout << "  " << i + 1 << "  " << x[i] << "\n";
  }

  incx = 1;

  i1 = idamax_ ( &n, x, &incx );

  cout << "\n";
  cout << "  The index of maximum magnitude = " << i1 << "\n";

  free ( x );

  return;
}
//****************************************************************************80

void r8vec_print ( int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT prints an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(8)  << i
         << ": " << setw(14) << a[i]  << "\n";
  }

  return;
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
}

