# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "elliptic_integral.hpp"

int main ( );
void rc_test ( );
void rc_test2 ( );
void rd_test ( );
void rf_test ( );
void rj_test ( );
void elliptic_ea_test ( );
void elliptic_ek_test ( );
void elliptic_em_test ( );
void elliptic_fa_test ( );
void elliptic_fk_test ( );
void elliptic_fm_test ( );
void elliptic_pia_test ( );
void elliptic_pik_test ( );
void elliptic_pim_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
/*
  Purpose:

    MAIN is the main program for ELLIPTIC_INTEGRAL_TEST.

  Discussion:

    ELLIPTIC_INTEGRAL_TEST tests ELLIPTIC_INTEGRAL.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  timestamp ( );
  printf ( "\n" );
  printf ( "ELLIPTIC_INTEGRAL_TEST\n" );
  printf ( "  C version\n" );
  printf ( "  ELLIPTIC_INTEGRAL evaluates elliptic integral functions\n" );
  printf ( "  using Carlson's elliptic functions.\n" );

  rc_test ( );
  rc_test2 ( );
  rd_test ( );
  rf_test ( );
  rj_test ( );

  elliptic_ea_test ( );
  elliptic_ek_test ( );
  elliptic_em_test ( );

  elliptic_fa_test ( );
  elliptic_fk_test ( );
  elliptic_fm_test ( );

  elliptic_pia_test ( );
  elliptic_pik_test ( );
  elliptic_pim_test ( );
/*
  Terminate.
*/
  printf ( "\n" );
  printf ( "ELLIPTIC_INTEGRAL_TEST\n" );
  printf ( "  Normal end of execution.\n" );
  printf ( "\n" );
  timestamp ( );

  return 0;
}
//****************************************************************************80

void rc_test ( )

//****************************************************************************80
/*
  Purpose:

    RC_TEST tests RC.

  Discussion:

    This driver tests the function for the
    integral RC(X,Y).  The first six sets of values of X and Y are
    extreme points of the region of valid arguments defined by the
    machine-dependent constants LOLIM and UPLIM.  The values of LOLIM,
    UPLIM, X, Y, and ERRTOL (see comments in void) may be used on
    most machines but provide a severe test of robustness only on the
    ibm 360/370 series.  The seventh set tests the failure exit.  The
    next three sets are check values: RC(0,0.25) = RC(0.0625,0.125) = PI
    and RC(2.25,2) = LN(2).  The remaining sets show the dependence on X
    when Y = 1.  Fixing Y entails no loss here because RC is homogeneous.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 June 2018

  Author:

    Original FORTRAN77 version by Bille Carlson, Elaine Notis.
    This C version by John Burkardt.
*/
{
  double eliptc;
  double errtol;
  int i;
  int ierr;
  static double x[] = {
   1.51E-78, 
   3.01E-78, 
   0.00E+00, 
   0.99E+75, 
   0.00E+00, 
   0.99E+75, 
   0.00E+00, 
   0.00E+00, 
   6.25E-02, 
   2.25E+00, 
   0.01E+00, 
   0.02E+00, 
   0.05E+00, 
   0.10E+00, 
   0.20E+00, 
   0.40E+00, 
   0.60E+00, 
   0.80E+00, 
   1.00E+00, 
   1.20E+00, 
   1.50E+00, 
   2.00E+00, 
   3.00E+00, 
   4.00E+00, 
   5.00E+00, 
   1.00E+01, 
   2.00E+01, 
   5.00E+01, 
   1.00E+02, 
   1.00E+03, 
   1.00E+04, 
   1.00E+05, 
   1.00E+06, 
   1.00E+07, 
   1.00E+08, 
   1.00E+09, 
   1.00E+10, 
   1.00E+12, 
   1.00E+15, 
   1.00E+20, 
   1.00E+30, 
   1.00E+40, 
   1.00E+50 };

  static double y[] = { 
   1.51E-78, 
   0.55E-78, 
   3.01E-78, 
   0.55E-78, 
   0.99E+75, 
   0.99E+75, 
   2.00E-78, 
   2.50E-01, 
   1.25E-01, 
   2.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00 };

  printf ( "\n" );
  printf ( "RC_TEST\n" );
  printf ( "  RC evaluates the elementary integral RC(X,Y)\n" );

  printf ( "\n" );
  printf ( "              X                          Y                         RC(X,Y)\n" );
  printf ( "\n" );

  errtol = 1.0E-3;

  for ( i = 0; i < 43; i++ )
  {
    eliptc = rc ( x[i], y[i], errtol, &ierr );
    if ( ierr == 0 )
    {
      printf ( "  %27.16g%27.16g%27.16g\n", x[i], y[i], eliptc );
    }
    else
    {
      printf ( "  %27.16g%27.16g  ***Error***\n", x[i], y[i] );
    }
  }

  return;
}
//****************************************************************************80

void rc_test2 ( )

//****************************************************************************80
/*
  Purpose:

    RC_TEST2 checks RC by examining special values.

  Discussion:

    This driver compares values of (LOG X)/(X-1) and ARCTAN(X)
    calculated on one hand from the void RC and on the other
    from library LOG and ARCTAN routines.  to avoid over/underflows
    for extreme values of X, we write (LOG X)/(X-1) = RC(Y,X/Y)/SQRT(Y),
    where Y = (1+X)/2, and ARCTAN(X) = SQRT(X)*RC(Z,Z+X), where Z = 1/X.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 June 2018

  Author:

    Original FORTRAN77 version by Bille Carlson, Elaine Notis.
    This C version by John Burkardt.
*/
{
  double errtol;
  int i;
  double ibmarc;
  double ibmlog;
  int ierr;
  int ipower;
  int j;
  int m;
  double myarc;
  double mylog;
  double v;
  double w;
  double x;
  static double x_vec[] = {
   1.0E-75, 
   1.0E-15, 
   1.0E-03, 
   1.0E-01, 
   2.0E-01, 
   5.0E-01, 
   1.0E+00, 
   2.0E+00, 
   5.0E+00, 
   1.0E+01, 
   1.0E+03, 
   1.0E+15, 
   1.0E+75 };
  double y;
  double z;

  printf ( "\n" );
  printf ( "RC_TEST2\n" );
  printf ( "  Compare LOG(X)/(X-1) and ARCTAN(X) with\n" );
  printf ( "  values based on RC.\n" );

  printf ( "\n" );
  printf ( "     X                From LOG                   From RC\n" );
  printf ( "\n" );

  errtol = 1.0E-3;

  for ( j = 1; j <= 10; j++ )
  {
    x = 0.2 * ( double ) ( j );
    y = ( 1.0 + x ) / 2.0;
    v = x / y;
    mylog = rc ( y, v, errtol, &ierr ) / sqrt ( y );
    if ( j == 5 )
    {
      printf ( "%9.1g     **** ZERO DIVIDE *****%27.16g\n", x, mylog );
    }
    else
    {
      ibmlog = log ( x ) / ( x - 1.0 );
      printf ( "%9.1g     %27.16g%27.16g\n", x, ibmlog, mylog );
    }
  }

  printf ( "\n" );
  printf ( "  Extreme values of X\n" );
  printf ( "\n" );
  printf ( "     X                From LOG                   From RC\n" );
  printf ( "\n" );

  for ( i = 0; i < 16; i++ )
  {
    ipower = - 75 + 10 * i;
    x = pow ( 10.0, ipower );
    y = ( 1.0 + x ) / 2.0;
    v = x / y;
    mylog = rc ( y, v, errtol, &ierr ) / sqrt ( y );
    ibmlog = log ( x ) / ( x - 1.0 );
    printf ( "%9.1g,%27.16g%27.16g\n", x, ibmlog, mylog );
  }

  printf ( "\n" );
  printf ( "     X              From ARCTAN                 From RC\n" );
  printf ( "\n" );

  for ( m = 0; m < 13; m++ )
  {
    x = x_vec[m];
    z = 1.0 / x;
    w = z + x;
    myarc = sqrt ( x ) * rc ( z, w, errtol, &ierr );
    ibmarc = atan ( x );
    printf ( "%9.1g%27.16g%27.16g\n", x, ibmarc, myarc );
  }

  return;
}
//****************************************************************************80

void rd_test ( )

//****************************************************************************80
/*
  Purpose:

    RD_TEST tests RD.

  Discussion:

    This driver tests the function for the
    integral RD(X,Y,Z), which is symmetric in X and Y.  The first
    twelve sets of values of X, Y, Z are extreme points of the region of
    valid arguments defined by the machine-dependent constants LOLIM
    and UPLIM.  The values of LOLIM, UPLIM, X, Y, Z, and ERRTOL (see
    comments in void) may be used on most machines but provide a
    severe test of robustness only on the ibm 360/370 series.  The
    thirteenth set tests the failure exit.  The fourteenth set is a
    check value: RD(0,2,1) = 3B = 3(PI)/4A, where A and B are the
    lemniscate constants.  The remaining sets show the dependence
    on Z when Y = 1 (no loss of generality because of homogeneity)
    and X = 0.5 (midway between the complete case X = 0 and the
    degenerate case X = Y).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 June 2018

  Author:

    Original FORTRAN77 version by Bille Carlson, Elaine Notis.
    This C version by John Burkardt.
*/
{
  double eliptc;
  double errtol;
  int i;
  int ierr;
  static double x[] = {
   0.00E+00, 
   0.55E-78, 
   0.00E+00, 
   0.55E-78, 
   0.00E+00, 
   0.55E-78, 
   0.00E+00, 
   0.55E-78, 
   3.01E-51, 
   3.01E-51, 
   0.99E+48, 
   0.99E+48, 
   0.00E+00, 
   0.00E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00 };

  static double y[] = { 
   6.01E-51, 
   6.01E-51, 
   6.01E-51, 
   6.01E-51, 
   0.99E+48, 
   0.99E+48, 
   0.99E+48, 
   0.99E+48, 
   3.01E-51, 
   3.01E-51, 
   0.99E+48, 
   0.99E+48, 
   3.01E-51, 
   2.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00 };

  static double z[] = {
   6.01E-51, 
   6.01E-51, 
   0.99E+48, 
   0.99E+48, 
   6.01E-51, 
   6.01E-51, 
   0.99E+48, 
   0.99E+48, 
   6.01E-51, 
   0.99E+48, 
   6.01E-51, 
   0.99E+48, 
   1.00E+00, 
   1.00E+00, 
   1.00E-10, 
   1.00E-05, 
   1.00E-02, 
   1.00E-01, 
   2.00E-01, 
   5.00E-01, 
   1.00E+00, 
   2.00E+00, 
   5.00E+00, 
   1.00E+01, 
   1.00E+02, 
   1.00E+05, 
   1.00E+10 };
          
  printf ( "\n" );
  printf ( "RD_TEST\n" );
  printf ( "  RD evaluates the Carlson elliptic integral\n" );
  printf ( "  of the second kind, RD(X,Y,Z)\n" );
  printf ( "\n" );
  printf ( "               X                          Y" );
  printf ( "                          Z                         RD(X,Y,Z)\n" );
  printf ( "\n" );

  errtol = 1.0E-03;

  for ( i = 0; i < 27; i++ )
  {
    eliptc = rd ( x[i], y[i], z[i], errtol, &ierr );
    if (ierr == 0 )
    {
      printf ( "%27.16g%27.16g%27.16g%27.16g\n", x[i], y[i], z[i], eliptc );
    }
    else
    {
      printf ( "%27.16g%27.16g%27.16g  ***Error***\n", x[i], y[i], z[i] );
    }
  }

  return;
}
//****************************************************************************80

void rf_test ( )

//****************************************************************************80
/*
  Purpose:

    RF_TEST tests RF.

  Discussion:

    This driver tests the function for the
    integral RF(X,Y,Z), which is symmetric in X, Y, Z.  The first nine
    sets of values of X, Y, Z are extreme points of the region of valid
    arguments defined by the machine-dependent constants LOLIM and
    UPLIM.  The values of LOLIM, UPLIM, X, Y, Z, and ERRTOL (see
    comments in void) may be used on most machines but provide a
    severe test of robustness only on the ibm 360/370 series.  The
    tenth set tests the failure exit.  The eleventh set is a check
    value: RF(0,1,2) = A, where A is the first lemniscate constant.
    The remaining sets show the dependence on Z when Y = 1 (no loss of
    generality because of homogeneity) and X = 0.5 (midway between the
    complete case X = 0 and the degenerate case X = Y).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 June 2018

  Author:

    Original FORTRAN77 version by Bille Carlson, Elaine Notis.
    This C version by John Burkardt.
*/
{
  double eliptc;
  double errtol;
  int i;
  int ierr;
  static double x[] = {
   1.51E-78, 
   1.51E-78, 
   0.00E+00, 
   0.00E+00, 
   0.00E+00, 
   0.99E+75, 
   0.55E-78, 
   0.55E-78, 
   0.55E-78, 
   0.00E+00, 
   0.00E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00 };

  static double y[] = {
   1.51E-78, 
   1.51E-78, 
   3.01E-78, 
   3.01E-78, 
   0.99E+75, 
   0.99E+75, 
   3.01E-78, 
   3.01E-78, 
   0.99E+75, 
   2.00E-78, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00 };

  static double z[] = {
   1.51E-78, 
   0.99E+75, 
   3.01E-78, 
   0.99E+75, 
   0.99E+75, 
   0.99E+75, 
   3.01E-78, 
   0.99E+75, 
   0.99E+75, 
   1.00E+00, 
   2.00E+00, 
   1.00E+00, 
   1.10E+00, 
   1.20E+00, 
   1.30E+00, 
   1.40E+00, 
   1.50E+00, 
   1.60E+00, 
   1.70E+00, 
   1.80E+00, 
   1.90E+00, 
   2.00E+00, 
   2.20E+00, 
   2.40E+00, 
   2.60E+00, 
   2.80E+00, 
   3.00E+00, 
   3.50E+00, 
   4.00E+00, 
   4.50E+00, 
   5.00E+00, 
   6.00E+00, 
   7.00E+00, 
   8.00E+00, 
   9.00E+00, 
   1.00E+01, 
   2.00E+01, 
   3.00E+01, 
   4.00E+01, 
   5.00E+01, 
   1.00E+02, 
   2.00E+02, 
   5.00E+02, 
   1.00E+03, 
   1.00E+04, 
   1.00E+05, 
   1.00E+06, 
   1.00E+08, 
   1.00E+10, 
   1.00E+12, 
   1.00E+15, 
   1.00E+20, 
   1.00E+30, 
   1.00E+40, 
   1.00E+50 };

  printf ( "\n" );
  printf ( "RF_TEST\n" );
  printf ( "  RF evaluates the Carlson elliptic integral\n" );
  printf ( "  of the first kind, RF(X,Y,Z)\n" );
  printf ( "\n" );
  printf ( "               X                          Y" );
  printf ( "                          Z                         RF(X,Y,Z)\n" );
  printf ( " \n" );

  errtol = 1.0E-3;

  for ( i = 0; i < 55; i++ )
  {
    eliptc = rf ( x[i], y[i], z[i], errtol, &ierr );
    if (ierr == 0 )
    {
      printf ( "%27.16g%27.16g%27.16g%27.16g\n", x[i], y[i], z[i], eliptc );
    }
    else
    {
      printf ( "%27.16g%27.16g%27.16g  ***Error***\n", x[i], y[i], z[i] );
    }
  }

  return;
}
//****************************************************************************80

void rj_test ( )

//****************************************************************************80
/*
  Purpose:

    RJ_TEST tests RJ.

  Discussion:

    This driver tests the function for the
    integral Rj(X,Y,Z,P), which is symmetric in X, Y, Z.  The first
    twenty sets of values of X, Y, Z, P are extreme points of the region
    of valid arguments defined by the machine-dependent constants
    LOLIM and UPLIM.  The values of LOLIM, UPLIM, X, Y, Z, P, and
    ERRTOL (see comments in void) may be used on most machines
    but provide a severe test of robustness only on the ibm 360/370
    series.  The twenty-first set tests the failure exit.  The twenty-
    second set is a check value:
      RJ(2,3,4,5) = 0.1429757966715675383323308.
    The remaining sets show the dependence on Z and P
    when Y = 1 (no loss of generality because of homogeneity) and
    X = 0.5 (midway between the complete case x = 0 and the degenerate
    case X = Y).

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    02 June 2018

  Author:

    Original FORTRAN77 version by Bille Carlson, Elaine Notis.
    This C version by John Burkardt.
*/
{
  double eliptc;
  double errtol;
  int i;
  int ierr;

  static double p[] = { 
   2.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   1.00E+00, 
   5.00E+00, 
   0.25E+00, 
   0.75E+00, 
   1.00E+00, 
   2.00E+00, 
   0.25E+00, 
   0.75E+00, 
   1.50E+00, 
   4.00E+00, 
   0.25E+00, 
   0.75E+00, 
   3.00E+00, 
   1.00E+01, 
   0.25E+00, 
   0.75E+00, 
   5.00E+00, 
   2.00E+01, 
   0.25E+00, 
   0.75E+00, 
   5.00E+01, 
   2.00E+02 };

  static double x[]  = {
   1.01E-26, 
   1.01E-26, 
   0.00E+00, 
   0.00E+00, 
   0.00E+00, 
   2.99E+24, 
   0.55E-78, 
   0.55E-78, 
   0.55E-78, 
   2.01E-26, 
   1.01E-26, 
   1.01E-26, 
   0.00E+00, 
   0.00E+00, 
   0.00E+00, 
   2.99E+24, 
   0.55E-78, 
   0.55E-78, 
   0.55E-78, 
   2.01E-26, 
   0.00E+00, 
   2.00E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00, 
   0.50E+00 };

  static double y[] = {
   1.01E-26, 
   1.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.99E+24, 
   2.99E+24, 
   2.01E-26, 
   2.01E-26, 
   2.99E+24, 
   2.01E-26, 
   1.01E-26, 
   1.01E-26, 
   2.01E-26, 
   2.01E-26, 
   2.99E+24, 
   2.99E+24, 
   2.01E-26, 
   2.01E-26, 
   2.99E+24, 
   2.01E-26, 
   1.90E-26, 
   3.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00 };

  static double z[] = {
   1.01E-26, 
   2.99E+24, 
   2.01E-26, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.01E-26, 
   2.99E+24, 
   2.99E+24, 
   2.01E-26, 
   1.01E-26, 
   2.99E+24, 
   2.01E-26, 
   2.99E+24, 
   2.99E+24, 
   2.99E+24, 
   2.01E-26, 
   2.99E+24, 
   2.99E+24, 
   2.01E-26, 
   1.90E-26, 
   4.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   1.00E+00, 
   2.00E+00, 
   2.00E+00, 
   2.00E+00, 
   2.00E+00, 
   5.00E+00, 
   5.00E+00, 
   5.00E+00, 
   5.00E+00, 
   1.00E+01, 
   1.00E+01, 
   1.00E+01, 
   1.00E+01, 
   1.00E+02, 
   1.00E+02, 
   1.00E+02, 
   1.00E+02 };

  printf ( "\n" );
  printf ( "RJ_TEST\n" );
  printf ( "  RJ evaluates the Carlson elliptic integral\n" );
  printf ( "  of the third kind, RJ(X,Y,Z,P)\n" );
  printf ( "\n" );
  printf ( "               X                          Y" );
  printf ( "                          Z                         P" );
  printf ( "                         RJ(X,Y,Z,P)\n" );
  printf ( "\n" );

  errtol = 1.0E-3;

  for ( i = 0; i < 42; i++ )
  {
    eliptc = rj ( x[i], y[i], z[i], p[i], errtol, &ierr );
    if (ierr == 0 )
    {
      printf ( "%27.16g%27.16g%27.16g%27.16g%27.16g\n", x[i], y[i], z[i], p[i], eliptc );
    }
    else
    {
      printf ( "%27.16g%27.16g%27.16g%27.16g  ***Error***\n", x[i], y[i], z[i], p[i] );
    }
  }

  return;
}
//****************************************************************************80

void elliptic_ea_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_EA_TEST tests ELLIPTIC_EA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double a;
  double fx;
  double fx2;
  int n_data;

  printf ( "\n" );
  printf ( "ELLIPTIC_EA_TEST:\n" );
  printf ( "  ELLIPTIC_EA returns values of\n" );
  printf ( "  the complete elliptic integral of the\n" );
  printf ( "  second kind, with parameter angle A.\n" );
  printf ( "\n" );
  printf ( "      A       E(A)          E(A)\n" );
  printf ( "          Tabulated         Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_ea_values ( &n_data, &a, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = elliptic_ea ( a );

    printf ( "  %14.6f  %24.16g  %24.16g\n", a, fx, fx2 );
  }

  return;
}
//****************************************************************************80

void elliptic_ek_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_EK_TEST tests ELLIPTIC_EK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  double k;
  int n_data;

  printf ( "\n" );
  printf ( "ELLIPTIC_EK_TEST:\n" );
  printf ( "  ELLIPTIC_EK returns values of\n" );
  printf ( "  the complete elliptic integral of the\n" );
  printf ( "  second kind, with parameter K.\n" );
  printf ( "\n" );
  printf ( "      K       E(K)          E(K)\n" );
  printf ( "          Tabulated         Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_ek_values ( &n_data, &k, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = elliptic_ek ( k );

    printf ( "  %14.6f  %24.16g  %24.16g\n", k, fx, fx2 );
  }
  return;
}
//****************************************************************************80

void elliptic_em_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_EM_TEST tests ELLIPTIC_EM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  double m;
  int n_data;

  printf ( "\n" );
  printf ( "ELLIPTIC_EM_TEST:\n" );
  printf ( "  ELLIPTIC_EM returns values of\n" );
  printf ( "  the complete elliptic integral of the\n" );
  printf ( "  second kind, with parameter M.\n" );
  printf ( "\n" );
  printf ( "      M       E(M)          E(M)\n" );
  printf ( "          Tabulated         Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_em_values ( &n_data, &m, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = elliptic_em ( m );

    printf ( "  %14.6f  %24.16g  %24.16g\n", m, fx, fx2 );
  }
  return;
}
//****************************************************************************80

void elliptic_fa_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_FA_TEST tests ELLIPTIC_FA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double a;
  double fx;
  double fx2;
  int n_data;

  printf ( "\n" );
  printf ( "ELLIPTIC_FA_TEST:\n" );
  printf ( "  ELLIPTIC_FA returns values of\n" );
  printf ( "  the complete elliptic integral of the first\n" );
  printf ( "  kind, with parameter angle A.\n" );
  printf ( "\n" );
  printf ( "      A       F(A)          F(A)\n" );
  printf ( "          Tabulated         Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_fa_values ( &n_data, &a, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = elliptic_fa ( a );

    printf ( "  %14.6f  %24.16g  %24.16g\n", a, fx, fx2 );
  }
  return;
}
//****************************************************************************80

void elliptic_fk_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_FK_TEST tests ELLIPTIC_FK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  double k;
  int n_data;

  printf ( "\n" );
  printf ( "ELLIPTIC_FK_TEST:\n" );
  printf ( "  ELLIPTIC_FK returns values of\n" );
  printf ( "  the complete elliptic integral of the first\n" );
  printf ( "  kind, with parameter K.\n" );
  printf ( "\n" );
  printf ( "      K       F(K)          F(K)\n" );
  printf ( "          Tabulated         Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_fk_values ( &n_data, &k, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = elliptic_fk ( k );

    printf ( "  %14.6f  %24.16g  %24.16g\n", k, fx, fx2 );
  }
  return;
}
//****************************************************************************80

void elliptic_fm_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_FM_TEST tests ELLIPTIC_FM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double fx;
  double fx2;
  double m;
  int n_data;

  printf ( "\n" );
  printf ( "ELLIPTIC_FM_TEST:\n" );
  printf ( "  ELLIPTIC_FM returns values of\n" );
  printf ( "  the complete elliptic integral of the first\n" );
  printf ( "  kind, with parameter M.\n" );
  printf ( "\n" );
  printf ( "      M       F(M)          F(M)\n" );
  printf ( "          Tabulated         Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_fm_values ( &n_data, &m, &fx );

    if ( n_data == 0 )
    {
      break;
    }

    fx2 = elliptic_fm ( m );

    printf ( "  %14.6f  %24.16g  %24.16g\n", m, fx, fx2 );
  }
  return;
}
//****************************************************************************80

void elliptic_pia_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_PIA_TEST tests ELLIPTIC_PIA.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double a;
  double n;
  int n_data;
  double pia1;
  double pia2;

  printf ( "\n" );
  printf ( "ELLIPTIC_PIA_TEST:\n" );
  printf ( "  ELLIPTIC_PIA returns values of\n" );
  printf ( "  the complete elliptic integral of the\n" );
  printf ( "  third kind, with parameter angle A.\n" );
  printf ( "\n" );
  printf ( "      N     A   Pi(N,A)      Pi(N,A)\n" );
  printf ( "                Tabulated    Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_pia_values ( &n_data, &n, &a, &pia1 );

    if ( n_data == 0 )
    {
      break;
    }

    pia2 = elliptic_pia ( n, a );

    printf ( "  %14.6g  %14.6f  %24.16g  %24.16g\n", n, a, pia1, pia2 );
  }
  return;
}
//****************************************************************************80

void elliptic_pik_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_PIK_TEST tests ELLIPTIC_PIK.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double k;
  double n;
  int n_data;
  double pik1;
  double pik2;

  printf ( "\n" );
  printf ( "ELLIPTIC_PIK_TEST:\n" );
  printf ( "  ELLIPTIC_PIK returns values of\n" );
  printf ( "  the complete elliptic integral of the\n" );
  printf ( "  third kind, with parameter K.\n" );
  printf ( "\n" );
  printf ( "      N     K    Pi(N,K)           Pi(N,K)\n" );
  printf ( "                 Tabulated         Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_pik_values ( &n_data, &n, &k, &pik1 );

    if ( n_data == 0 )
    {
      break;
    }

    pik2 = elliptic_pik ( n, k );

    printf ( "  %14.6g  %14.6f  %24.16g  %24.16g\n", n, k, pik1, pik2 );
  }
  return;
}
//****************************************************************************80

void elliptic_pim_test ( )

//****************************************************************************80
/*
  Purpose:

    ELLIPTIC_PIM_TEST tests ELLIPTIC_PIM.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    03 June 2018

  Author:

    John Burkardt
*/
{
  double m;
  double n;
  int n_data;
  double pim1;
  double pim2;

  printf ( "\n" );
  printf ( "ELLIPTIC_PIM_TEST:\n" );
  printf ( "  ELLIPTIC_PIM returns values of\n" );
  printf ( "  the complete elliptic integral of the\n" );
  printf ( "  third kind, with parameter modulus M.\n" );
  printf ( "\n" );
  printf ( "      N     M    Pi(N,M)           Pi(N,M)\n" );
  printf ( "                 Tabulated         Calculated\n" );
  printf ( "\n" );

  n_data = 0;
 
  while ( true )
  {
    elliptic_pim_values ( &n_data, &n, &m, &pim1 );

    if ( n_data == 0 )
    {
      break;
    }

    pim2 = elliptic_pim ( n, m );

    printf ( "  %14.6g  %14.6f  %24.16g  %24.16g\n", n, m, pim1, pim2 );
  }

  return;
}
