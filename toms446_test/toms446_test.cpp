# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "toms446.hpp"

int main ( );

void cheby_test ( );
void dfrnt_test ( );
void echeb_test ( );
void edcheb_test ( );
void mltply_test ( );
void ntgrt_test ( );
double *functn ( double x );
double *functn_d ( double x );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for TOMS446_TEST.
//
//  Discussion:
//
//    TOMS446_TEST tests the TOMS446 library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2011
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "TOMS446_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the TOMS446 library.\n";

  cheby_test ( );
  dfrnt_test ( );
  echeb_test ( );
  edcheb_test ( );
  mltply_test ( );
  ntgrt_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "TOMS446_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void cheby_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    CHEBY_TEST tests CHEBY, which computes Chebyshev series.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2011
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int j;
  int nf = 5;
  int npl = 10;
  double *x;

  cout << "\n";
  cout << "CHEBY_TEST\n";
  cout << "  CHEBY computes the Chebyshev series for several functions.\n";

  x = cheby ( nf, npl, functn );

  cout << "\n";
  cout << "          Sin(x)          Cos(x)        Sin(2x)         Cos(2x)           X^5\n";
  cout << "\n";

  for ( i = 0; i < npl; i++ )
  {
    for ( j = 0; j < nf; j++ )
    {
      cout << "  " << fixed << setw(14) << x[i+j*npl];
    }
    cout << "\n";
  }
  delete [] x;

  return;
}
//****************************************************************************80

void dfrnt_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DFRNT_TEST tests DFRNT, which computes the Chebyshev series of a derivative.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2011
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int j;
  int nf = 5;
  int npl = 10;
  double *x;
  double *x2;
  double *x3;

  cout << "\n";
  cout << "DFRNT_TEST\n";
  cout << "  DFRNT computes the Chebyshev series for the derivative\n";
  cout << "  of several functions.\n";

  x = cheby ( nf, npl, functn );
  x2 = new double[npl];

  for ( j = 0; j < nf; j++ )
  {
    for ( i = 0; i < npl; i++ )
    {
      x2[i] = x[i+j*npl];
    }
    x3 = dfrnt ( x2, npl );
    for ( i = 0; i < npl; i++ )
    {
      x[i+j*npl] = x3[i];
    }
    delete [] x3;
  }

  cout << "\n";
  cout << "  Chebyshev series for d/dx of:\n";
  cout << "\n";
  cout << "        Sin(x)      Cos(x)    Sin(2x)     Cos(2x)       X^5\n";
  cout << "\n";

  for ( i = 0; i < npl; i++ )
  {
    for ( j = 0; j < nf; j++ )
    {
      cout << "  " << fixed << setw(14) << x[i+j*npl];
    }
    cout << "\n";
  }

  delete [] x;
  delete [] x2;

  return;
}
//****************************************************************************80

void echeb_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ECHEB_TEST tests ECHEB, which evaluates a Chebyshev series.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2011
//
//  Author:
//
//    John Burkardt
//
{
  double fval;
  double *fxj;
  int i;
  int j;
  int k;
  int nf = 5;
  int npl = 10;
  int nx;
  double *x;
  double *x2;
  double xval;

  nx = 6;

  cout << "\n";
  cout << "ECHEB_TEST\n";
  cout << "  ECHEB evaluates a Chebyshev series.\n";

  x = cheby ( nf, npl, functn );
  x2 = new double[npl];

  for ( j = 0; j < nf; j++ )
  {
    for ( i = 0; i < npl; i++ )
    {
      x2[i] = x[i+j*npl];
    }

    cout << "\n";
    if ( j == 0 )
    {
      cout << "  Sin(x)\n";
    }
    else if ( j == 1 )
    {
      cout << "  Cos(x)\n";
    }
    else if ( j == 2 )
    {
      cout << "  Sin(2x)\n";
    }
    else if ( j == 3 )
    {
      cout << "  Cos(2x)\n";
    }
    else if ( j == 4 )
    {
      cout << "  x^5\n";
    }

    cout << "\n";

    for ( k = 0; k < nx; k++ )
    {
      xval = 2.0 * ( double ) ( k ) / ( double ) ( nx - 1 ) - 1.0;

      fxj = functn ( xval );

      fval = echeb ( xval, x2, npl );

      cout << "  " << setw(14) << xval
           << "  " << setw(14) << fxj[j]
           << "  " << setw(14) << fval << "\n";
      delete [] fxj;
    }
  }
  delete [] x;
  delete [] x2;

  return;
}
//****************************************************************************80

void edcheb_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    EDCHEB_TEST tests EDCHEB, which evaluates the derivative of a Chebyshev series.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2011
//
//  Author:
//
//    John Burkardt
//
{
  double fval;
  double *fxj;
  int i;
  int j;
  int k;
  int nf = 5;
  int npl = 10;
  int nx;
  double *x;
  double *x2;
  double xval;

  nx = 6;

  cout << "\n";
  cout << "EDCHEB_TEST\n";
  cout << "  EDCHEB evaluates the derivative of a Chebyshev series.\n";

  x = cheby ( nf, npl, functn );
  x2 = new double[npl];

  for ( j = 0; j < nf; j++ )
  {
    for ( i = 0; i < npl; i++ )
    {
      x2[i] = x[i+j*npl];
    }

    cout << "\n";
    if ( j == 0 )
    {
      cout << "  Sin(x)\n";
    }
    else if ( j == 1 )
    {
      cout << "  Cos(x)\n";
    }
    else if ( j == 2 )
    {
      cout << "  Sin(2x)\n";
    }
    else if ( j == 3 )
    {
      cout << "  Cos(2x)\n";
    }
    else if ( j == 4 )
    {
      cout << "  x^5\n";
    }

    cout << "\n";

    for ( k = 0; k < nx; k++ )
    {
      xval = 2.0 * ( double ) ( k ) / ( double ) ( nx - 1 ) - 1.0;

      fxj = functn_d ( xval );

      fval = edcheb ( xval, x2, npl );

      cout << "  " << setw(14) << xval
           << "  " << setw(14) << fxj[j]
           << "  " << setw(14) << fval << "\n";
      delete [] fxj;
    }
  }
  delete [] x;
  delete [] x2;

  return;
}
//****************************************************************************80

void mltply_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    MLTPLY_TEST tests MLTPLY, which multiplies two Chebyshev series.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2011
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int nf = 5;
  int npl = 10;
  double *x;
  double *x1;
  double *x2;
  double *x3;

  cout << "\n";
  cout << "MLTPLY_TEST\n";
  cout << "  MLTPLY computes the product of two Chebyshev series.\n";
  cout << "\n";
  cout << "  Multiply series for SIN(X) and COS(X)\n";
  cout << "  and compare with series for 1/2*SIN(2X).\n";

  x = cheby ( nf, npl, functn );

  x1 = new double[npl];
  x2 = new double[npl];

  for ( i = 0; i < npl; i++ )
  {
    x1[i] = x[i+0*npl];
    x2[i] = x[i+1*npl];
    x[i+2*npl] = 0.5 * x[i+2*npl];
  }
  x3 = mltply_new ( x1, x2, npl );

  cout << "\n";
  cout << "          Sin(x)          Cos(x)       1/2*Sin(2x)         RESULT\n";
  cout << "\n";

  for ( i = 0; i < npl; i++ )
  {
    cout << "  " << setw(14) << x[i+0*npl]
         << "  " << setw(14) << x[i+1*npl]
         << "  " << setw(14) << x[i+2*npl]
         << "  " << setw(14) << x3[i] << "\n";
  }
  delete [] x;
  delete [] x1;
  delete [] x2;
  delete [] x3;

  return;
}
//****************************************************************************80

void ntgrt_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    NTGRT_TEST tests NTGRT, which computes the Chebyshev series of an indefinite integral.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2011
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int j;
  int nf = 5;
  int npl = 10;
  double *x;
  double *x2;
  double *x3;

  cout << "\n";
  cout << "NTGRT_TEST\n";
  cout << "  NTGRT computes the Chebyshev series for the indefinite\n";
  cout << "  integral of several functions.\n";

  x = cheby ( nf, npl, functn );
  x2 = new double[npl];

  for ( j = 0; j < nf; j++ )
  {
    for ( i = 0; i < npl; i++ )
    {
      x2[i] = x[i+j*npl];
    }
    x3 = ntgrt ( x2, npl );
    for ( i = 0; i < npl; i++ )
    {
      x[i+j*npl] = x3[i];
    }
    delete [] x3;
  }

  cout << "\n";
  cout << "  Chebyshev series for indefinite integral of:\n";
  cout << "\n";
  cout << "        Sin(x)      Cos(x)    Sin(2x)     Cos(2x)       X^5\n";
  cout << "\n";

  for ( i = 0; i < npl; i++ )
  {
    for ( j = 0; j < nf; j++ )
    {
      cout << "  " << fixed << setw(14) << x[i+j*npl];
    }
    cout << "\n";
  }
  delete [] x;
  delete [] x2;

  return;
}
//****************************************************************************80

double *functn ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    FUNCTN evaluates several functions at X.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    24 September 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the evaluation point.
//
//    Output, double FXJ[5], the derivative values.
//
{
  double *fxj;
  
  fxj = new double[5];

  fxj[0] = sin ( x );
  fxj[1] = cos ( x );
  fxj[2] = sin ( 2.0 * x );
  fxj[3] = cos ( 2.0 * x );
  fxj[4] = pow ( x, 5 );

  return fxj;
}
//****************************************************************************80

double *functn_d ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    FUNCTN_D evaluates the derivatives of several functions at X.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 September 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the evaluation point.
//
//    Output, double FXJ[5], the derivative values.
//
{
  double *fxj;

  fxj = new double[5];

  fxj[0] =  cos ( x );
  fxj[1] = -sin ( x );
  fxj[2] =  2.0 * cos ( 2.0 * x );
  fxj[3] = -2.0 * sin ( 2.0 * x );
  fxj[4] =  5.0 * pow ( x, 4 );

  return fxj;
}
