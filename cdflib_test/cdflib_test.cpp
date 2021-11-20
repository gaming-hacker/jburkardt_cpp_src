# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "cdflib.hpp"

int main ( );
void beta_inc_test ( );
void cdfbet_test ( );
void cdfbin_test ( );
void cdfchi_test ( );
void cdfchn_test ( );
void cdff_test ( );
void cdffnc_test ( );
void cdfgam_test ( );
void cdfnbn_test ( );
void cdfnor_test ( );

void cdfpoi_test ( );
void cdft_test ( );
void cumbet_test ( );
void cumbin_test ( );
void cumchi_test ( );
void cumchn_test ( );
void cumf_test ( );
void cumfnc_test ( );
void cumgam_test ( );
void cumnbn_test ( );

void cumnor_test ( );
void cumpoi_test ( );
void cumt_test ( );
void beta_test ( );
void error_f_test ( );
void gamma_test ( );
void gamma_inc_test ( );
void psi_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdflib_test() tests cdflib().
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 February 2007
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "cdflib_test():\n";
  cout << "  C++ version\n";
  cout << "  Test cdflib().\n";

  beta_inc_test ( );
  cdfbet_test ( );
  cdfbin_test ( );
  cdfchi_test ( );
  cdfchn_test ( );
  cdff_test ( );
  cdffnc_test ( );
  cdfgam_test ( );
  cdfnbn_test ( );
  cdfnor_test ( );

  cdfpoi_test ( );
  cdft_test ( );
  cumbet_test ( );
  cumbin_test ( );
  cumchi_test ( );
  cumchn_test ( );
  cumf_test ( );
  cumfnc_test ( );
  cumgam_test ( );
  cumnbn_test ( );

  cumnor_test ( );
  cumpoi_test ( );
  cumt_test ( );
  beta_test ( );
  error_f_test ( );
  gamma_test ( );
  gamma_inc_test ( );
  psi_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "cdflib_test():\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void beta_inc_test ( )

//****************************************************************************80
//
//  Purpose:
//
//   beta_inc_test tests BETA_INC and BETA_INC_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int ierror;
  int n_data;
  double x;
  double y;

  cout << "\n";
  cout << "beta_inc_test\n";
  cout << "  BETA_INC computes the incomplete Beta ratio.\n";
  cout << "  BETA_INC_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X         Y         A         B         CDF           CDF\n";
  cout <<
    "                                           (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    y = 1.0 - x;

    beta_inc ( &a, &b, &x, &y, &cdf_compute, &ccdf_compute, &ierror );

    cout << setw(10) << x
         << setw(10) << y
         << setw(10) << a
         << setw(10) << b
         << setw(14) << cdf_lookup
         << setw(14) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "    X         Y         A         B         1-CDF         CCDF\n";
  cout <<
    "                                           (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    y = 1.0 - x;

    beta_inc ( &a, &b, &x, &y, &cdf_compute, &ccdf_compute, &ierror );

    cout << setw(10) << x
         << setw(10) << y
         << setw(10) << a
         << setw(10) << b
         << setw(14) << ccdf_lookup
         << setw(14) << ccdf_compute << "\n";

  }

  return;
}
//****************************************************************************80

void cdfbet_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdfbet_test tests CDFBET.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double bound;
  double p;
  double q;
  int status;
  int which;
  double x;
  double y;

  cout << "\n";
  cout << "cdfbet_test\n";
  cout << "  CDFBET computes one missing parameter from the BETA CDF:\n";
  cout << "\n";
  cout << "   BETA_CDF ( (P,Q), (X,Y), A, B )\n";
  cout << "\n";
  cout << "      P           Q               X           Y"
       << "            A           B\n";
  cout << "\n";

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 0.25;
      y = 1.0 - x;
      a = 2.0;
      b = 3.0;
    }
    else if ( which == 2 )
    {
      p = 0.261719;
      q = 1.0 - p;
      x = -1.0;
      y = -1.0;
      a = 2.0;
      b = 3.0;
    }
    else if ( which == 3 )
    {
      p = 0.261719;
      q = 1.0 - p;
      x = 0.25;
      y = 1.0 - x;
      a = -1.0;
      b = 3.0;
    }
    else if ( which == 4 )
    {
      p = 0.261719;
      q = 1.0 - p;
      x = 0.25;
      y = 1.0 - x;
      a = 2.0;
      b = -1.0;
    }

    cdfbet ( &which, &p, &q, &x, &y, &a, &b, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFBET returned STATUS = " << status << "\n";
      continue;
    }
    cout                  << "  "
         << setw(10) << p << "  "
         << setw(10) << q << "  "
         << setw(10) << x << "  "
         << setw(10) << y << "  "
         << setw(10) << a << "  "
         << setw(10) << b << "\n";
  }

  return;
}
//****************************************************************************80

void cdfbin_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdfbin_test tests CDFBIN.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double ompr;
  double p;
  double pr;
  double q;
  double s;
  int status;
  int which;
  double xn;

  cout << "\n";
  cout << "cdfbin_test\n";
  cout << "  CDFBIN computes one missing parameter from the\n";
  cout << "  Binomial CDF:\n";
  cout << "\n";
  cout << "   BINOMIAL_CDF ( (P,Q), S, XN, (PR,OMPR) )\n";
  cout << "\n";
  cout << "      P           Q                S          "
       << "XN         PR         OMPR\n";
  cout << "\n";

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      s = 5.0;
      xn = 8.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 2 )
    {
      p = 0.067347;
      q = 1.0 - p;
      s = -1.0;
      xn = 8.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 3 )
    {
      p = 0.067347;
      q = 1.0 - p;
      s = 5.0;
      xn = -1.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 4 )
    {
      p = 0.067347;
      q = 1.0 - p;
      s = 5.0;
      xn = 8.0;
      pr = -1.0;
      ompr = -1.0;
    }

    cdfbin ( &which, &p, &q, &s, &xn, &pr, &ompr, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFBIN returned STATUS = " << status << "\n";
      continue;
    }
    cout                     << "  "
         << setw(10) << p    << "  "
         << setw(10) << q    << "  "
         << setw(10) << s    << "  "
         << setw(10) << xn   << "  "
         << setw(10) << pr   << "  "
         << setw(10) << ompr << "\n";
  }

  return;
}
//****************************************************************************80

void cdfchi_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdfchi_test tests CDFCHI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double df;
  double p;
  double q;
  int status;
  int which;
  double x;

  cout << "\n";
  cout << "cdfchi_test\n";
  cout << "  CDFCHI computes one missing parameter from the\n";
  cout << "  Chi Square CDF:\n";
  cout << "\n";
  cout << "   CHI_CDF ( (P,Q), X, DF )\n";
  cout << "\n";
  cout << "      P           Q                X          DF\n";
  cout << "\n";

  for ( which = 1; which <= 3; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 5.0;
      df = 8.0;
    }
    else if ( which == 2 )
    {
      p = 0.242424;
      q = 1.0 - p;
      x = -1.0;
      df = 8.0;
    }
    else if ( which == 3 )
    {
      p = 0.242424;
      q = 1.0 - p;
      x = 5.0;
      df = -1.0;
    }

    cdfchi ( &which, &p, &q, &x, &df, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFCHI returned STATUS = " << status << "\n";
      continue;
    }
    cout                     << "  "
         << setw(10) << p    << "  "
         << setw(10) << q    << "  "
         << setw(10) << x    << "  "
         << setw(10) << df   << "\n";
  }
  return;
}
//****************************************************************************80

void cdfchn_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdfchn_test tests CDFCHN.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double df;
  double p;
  double pnonc;
  double q;
  int status;
  int which;
  double x;

  cout << "\n";
  cout << "cdfchn_test\n";
  cout << "  CDFCHN computes one missing parameter from the\n";
  cout << "  Chi Square CDF:\n";
  cout << "\n";
  cout << "   CHI_Noncentral_CDF ( (P,Q), X, DF, PNONC )\n";
  cout << "\n";
  cout << "     P         Q             X        DF     PNONC\n";
  cout << "\n";

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 5.0;
      df = 8.0;
      pnonc = 0.5;
    }
    else if ( which == 2 )
    {
      p = 0.211040;
      q = 1.0 - p;
      x = -1.0;
      df = 8.0;
      pnonc = 0.5;
    }
    else if ( which == 3 )
    {
      p = 0.211040;
      q = 1.0 - p;
      x = 5.0;
      df = -1.0;
      pnonc = 0.5;
    }
    else if ( which == 4 )
    {
      p = 0.211040;
      q = 1.0 - p;
      x = 5.0;
      df = 8.0;
      pnonc = -1.0;
    }

    cdfchn ( &which, &p, &q, &x, &df, &pnonc, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFCHN returned STATUS = " << status << "\n";
      continue;
    }

    cout <<                     "  "
         << setw(8) << p     << "  "
         << setw(8) << q     << "  "
         << setw(8) << x     << "  "
         << setw(8) << df    << "  "
         << setw(8) << pnonc << "\n";
  }
  return;
}
//****************************************************************************80

void cdff_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdff_test tests CDFF.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double dfd;
  double dfn;
  double f;
  double p;
  double q;
  int status;
  int which;

  cout << "\n";
  cout << "cdff_test\n";
  cout << "  CDFF computes one missing parameter from the\n";
  cout << "  F CDF:\n";
  cout << "\n";
  cout << "   F_CDF ( (P,Q), F, DFN, DFD )\n";
  cout << "\n";
  cout << "     P         Q             F       DFN       DFD\n";
  cout << "\n";

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      f = 5.0;
      dfn = 8.0;
      dfd = 3.0;
    }
    else if ( which == 2 )
    {
      p = 0.893510;
      q = 1.0 - p;
      f = -1.0;
      dfn = 8.0;
      dfd = 3.0;
    }
    else if ( which == 3 )
    {
      p = 0.893510;
      q = 1.0 - p;
      f = 5.0;
      dfn = -1.0;
      dfd = 3.0;
    }
    else if ( which == 4 )
    {
      p = 0.893510;
      q = 1.0 - p;
      f = 5.0;
      dfn = 8.0;
      dfd = -1.0;
    }

    cdff ( &which, &p, &q, &f, &dfn, &dfd, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFF returned STATUS = " << status << "\n";
      continue;
    }

    cout <<                   "  "
         << setw(8) << p   << "  "
         << setw(8) << q   << "  "
         << setw(8) << f   << "  "
         << setw(8) << dfn << "  "
         << setw(8) << dfd << "\n";
  }
  return;
}
//****************************************************************************80

void cdffnc_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdffnc_test tests CDFFNC.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double dfd;
  double dfn;
  double f;
  double p;
  double pnonc;
  double q;
  int status;
  int which;

  cout << "\n";
  cout << "cdffnc_test\n";
  cout << "  CDFFNC computes one missing parameter from the\n";
  cout << "  noncentral F CDF:\n";
  cout << "\n";
  cout << "   F_noncentral_CDF ( (P,Q), F, DFN, DFD, PNONC )\n";
  cout << "\n";
  cout << "         P         Q         F       DFN       DFD     PNONC\n";
  cout << "\n";

  for ( which = 1; which <= 5; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      f = 5.0;
      dfn = 8.0;
      dfd = 3.0;
      pnonc = 17.648016;
    }
    else if ( which == 2 )
    {
      p = 0.60;
      q = 1.0 - p;
      f = -1.0;
      dfn = 8.0;
      dfd = 3.0;
      pnonc = 17.648016;
    }
    else if ( which == 3 )
    {
      p = 0.60;
      q = 1.0 - p;
      f = 5.0;
      dfn = -1.0;
      dfd = 3.0;
      pnonc = 17.648016;
    }
    else if ( which == 4 )
    {
      p = 0.60;
      q = 1.0 - p;
      f = 5.0;
      dfn = 8.0;
      dfd = -1.0;
      pnonc = 17.648016;
    }
    else if ( which == 5 )
    {
      p = 0.60;
      q = 1.0 - p;
      f = 5.0;
      dfn = 8.0;
      dfd = 3.0;
      pnonc = -1.0;
    }

    cdffnc ( &which, &p, &q, &f, &dfn, &dfd, &pnonc, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFFNC returned STATUS = " << status << "\n";
      continue;
    }

    cout <<                   "  "
         << setw(8) << p     << "  "
         << setw(8) << q     << "  "
         << setw(8) << f     << "  "
         << setw(8) << dfn   << "  "
         << setw(8) << dfd   << "  "
         << setw(8) << pnonc << "\n";
  }

  return;
}
//****************************************************************************80

void cdfgam_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdfgam_test tests CDFGAM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double p;
  double q;
  double scale;
  double shape;
  int status;
  int which;
  double x;

  cout << "\n";
  cout << "cdfgam_test\n";
  cout << "  CDFGAM computes one missing parameter from the\n";
  cout << "  Gamma CDF:\n";
  cout << "\n";
  cout << "   Gamma_CDF ( (P,Q), X, SHAPE, SCALE )\n";
  cout << "\n";
  cout << "    P         Q              X     SHAPE     SCALE\n";
  cout << "\n";

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 5.0;
      shape = 8.0;
      scale = 3.0;
    }
    else if ( which == 2 )
    {
      p = 0.981998;
      q = 1.0 - p;
      x = -1.0;
      shape = 8.0;
      scale = 3.0;
    }
    else if ( which == 3 )
    {
      p = 0.981998;
      q = 1.0 - p;
      x = 5.0;
      shape = -1.0;
      scale = 3.0;
    }
    else if ( which == 4 )
    {
      p = 0.981998;
      q = 1.0 - p;
      x = 5.0;
      shape = 8.0;
      scale = -1.0;
    }

    cdfgam ( &which, &p, &q, &x, &shape, &scale, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFGAM returned STATUS = " << status << "\n";
      continue;
    }

    cout <<                     "  "
         << setw(8) << p     << "  "
         << setw(9) << q     << "  "
         << setw(8) << x     << "  "
         << setw(8) << shape << "  "
         << setw(8) << scale << "\n";
  }

  return;
}
//****************************************************************************80

void cdfnbn_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdfnbn_test tests CDFNBN.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double f;
  double ompr;
  double p;
  double pr;
  double q;
  double s;
  int status;
  int which;

  cout << "\n";
  cout << "cdfnbn_test\n";
  cout << "  CDFNBN computes one missing parameter from the\n";
  cout << "  Negative_Binomial CDF:\n";
  cout << "\n";
  cout << "   Negative_BINOMIAL_CDF ( (P,Q), F, S, (PR,OMPR) )\n";
  cout << "\n";
  cout << "    P         Q               F         S       PR        OMPR\n";
  cout << "\n";

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      f = 3.0;
      s = 5.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 2 )
    {
      p = 0.988752;
      q = 1.0 - p;
      f = -1.0;
      s = 5.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 3 )
    {
      p = 0.988752;
      q = 1.0 - p;
      f = 3.0;
      s = -1.0;
      pr = 0.875;
      ompr = 1.0 - pr;
    }
    else if ( which == 4 )
    {
      p = 0.988752;
      q = 1.0 - p;
      f = 3.0;
      s = 5.0;
      pr = -1.0;
      ompr = -1.0;
    }

    cdfnbn ( &which, &p, &q, &f, &s, &pr, &ompr, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFNBN returned STATUS = " << status << "\n";
      continue;
    }
    cout <<                    "  "
         << setw(8) << p    << "  "
         << setw(9) << q    << "  "
         << setw(8) << f    << "  "
         << setw(8) << s    << "  "
         << setw(8) << pr   << "  "
         << setw(8) << ompr << "\n";
  }

  return;
}
//****************************************************************************80

void cdfnor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdfnor_test tests CDFNOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double mean;
  double p;
  double q;
  double sd;
  int status;
  int which;
  double x;

  cout << "\n";
  cout << "cdfnor_test\n";
  cout << "  CDFNOR computes one missing parameter from the\n";
  cout << "  Normal CDF:\n";
  cout << "\n";
  cout << "   Normal_CDF ( (P,Q), X, MEAN, SD )\n";
  cout << "\n";
  cout << "    P         Q               X      MEAN       SD\n";
  cout << "\n";

  for ( which = 1; which <= 4; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      x = 3.0;
      mean = 5.0;
      sd = 0.875;
    }
    else if ( which == 2 )
    {
      p = 0.011135;
      q = 1.0 - p;
      x = -1.0;
      mean = 5.0;
      sd = 0.875;
    }
    else if ( which == 3 )
    {
      p = 0.011135;
      q = 1.0 - p;
      x = 3.0;
      mean = -1.0;
      sd = 0.875;
    }
    else if ( which == 4 )
    {
      p = 0.011135;
      q = 1.0 - p;
      x = 3.0;
      mean = 5.0;
      sd = -1.0;
    }

    cdfnor ( &which, &p, &q, &x, &mean, &sd, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFNOR returned STATUS = " << status << "\n";
      continue;
    }
    cout <<                    "  "
         << setw(9) << p    << "  "
         << setw(8) << q    << "  "
         << setw(8) << x    << "  "
         << setw(8) << mean << "  "
         << setw(8) << sd   << "\n";
  }

  return;
}
//****************************************************************************80

void cdfpoi_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdfpoi_test tests CDFPOI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double p;
  double q;
  double s;
  int status;
  int which;
  double xlam;

  cout << "\n";
  cout << "cdfpoi_test\n";
  cout << "  CDFPOI computes one missing parameter from the\n";
  cout << "  Poisson CDF:\n";
  cout << "\n";
  cout << "   POISSON_CDF ( (P,Q), S, XLAM )\n";
  cout << "\n";
  cout << "     P         Q         S         XLAM\n";
  cout << "\n";

  for ( which = 1; which <= 3; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      s = 3.0;
      xlam = 5.0;
    }
    else if ( which == 2 )
    {
      p = 0.265026;
      q = 1.0 - p;
      s = -1.0;
      xlam = 5.0;
    }
    else if ( which == 3 )
    {
      p = 0.265026;
      q = 1.0 - p;
      s = 3.0;
      xlam = -1.0;
    }

    cdfpoi ( &which, &p, &q, &s, &xlam, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFPOI returned STATUS = " << status << "\n";
      continue;
    }
    cout <<                    "  "
         << setw(9) << p    << "  "
         << setw(9) << q    << "  "
         << setw(9) << s    << "  "
         << setw(9) << xlam << "\n";
  }

  return;
}
//****************************************************************************80

void cdft_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cdft_test tests CDFT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double bound;
  double df;
  double p;
  double q;
  int status;
  double t;
  int which;

  cout << "\n";
  cout << "cdft_test\n";
  cout << "  CDFT computes one missing parameter from the\n";
  cout << "  T CDF:\n";
  cout << "\n";
  cout << "   T_CDF ( (P,Q), T, DF )\n";
  cout << "\n";
  cout << "    P         Q         T         DF\n";
  cout << "\n";

  for ( which = 1; which <= 3; which++ )
  {
    if ( which == 1 )
    {
      p = -1.0;
      q = -1.0;
      t = 3.0;
      df = 5.0;
    }
    else if ( which == 2 )
    {
      p = 0.984950;
      q = 1.0 - p;
      t = -1.0;
      df = 5.0;
    }
    else if ( which == 3 )
    {
      p = 0.984950;
      q = 1.0 - p;
      t = 3.0;
      df = -1.0;
    }

    cdft ( &which, &p, &q, &t, &df, &status, &bound );

    if ( status != 0 )
    {
      cout << "\n";
      cout << "  CDFT returned STATUS = " << status << "\n";
      continue;
    }
    cout <<                  "  "
         << setw(9) << p  << "  "
         << setw(9) << q  << "  "
         << setw(9) << t  << "  "
         << setw(9) << df << "\n";
  }

  return;
}
//****************************************************************************80

void cumbet_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumbet_test tests CUMBET, BETA_INC_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int n_data;
  double x;
  double y;

  cout << "\n";
  cout << "cumbet_test\n";
  cout << "  CUMBET computes the Beta CDF\n";
  cout << "  BETA_INC_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X         Y         A         B         CDF           CDF\n";
  cout <<
    "                                           (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    y = 1.0 - x;

    cumbet ( &x, &y, &a, &b, &cdf_compute, &ccdf_compute );

    cout << " "
         << setw(9) << x           << "  "
         << setw(9) << y           << "  "
         << setw(9) << a           << "  "
         << setw(9) << b           << "  "
         << setw(9) << cdf_lookup  << "  "
         << setw(9) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "    X         Y         A         B         1-CDF         CCDF\n";
  cout <<
    "                                           (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    beta_inc_values ( &n_data, &a, &b, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    y = 1.0 - x;

    cumbet ( &x, &y, &a, &b, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(9) << x            << "  "
         << setw(9) << y            << "  "
         << setw(9) << a            << "  "
         << setw(9) << b            << "  "
         << setw(9) << ccdf_lookup  << "  "
         << setw(9) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumbin_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumbin_test tests CUMBIN, BINOMIAL_CDF_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int n_data;
  double ompr;
  int s;
  double s_double;
  double pr;
  int x;
  double x_double;

  cout << "\n";
  cout << "cumbin_test\n";
  cout << "  CUMBIN computes the Binomial CDF\n";
  cout << "  BINOMIAL_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "   X   S    Pr       CDF           CDF\n";
  cout << "                    (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    binomial_cdf_values ( &n_data, &x, &pr, &s, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ompr = 1.0 - pr;

    s_double = ( double ) s;
    x_double = ( double ) x;

    cumbin ( &s_double, &x_double, &pr, &ompr, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(2)  << s           << "  "
         << setw(2)  << x           << "  "
         << setw(8)  << pr          << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "   X   S    Pr       1-CDF         CCDF\n";
  cout << "                    (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    binomial_cdf_values ( &n_data, &x, &pr, &s, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    ompr = 1.0 - pr;

    s_double = ( double ) s;
    x_double = ( double ) x;

    cumbin ( &s_double, &x_double, &pr, &ompr, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(2)  << s            << "  "
         << setw(2)  << x            << "  "
         << setw(8)  << pr           << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumchi_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumchi_test tests CUMCHI, CHI_SQUARE_CDF_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int df;
  double df_double;
  int n_data;
  double x;

  cout << "\n";
  cout << "cumchi_test\n";
  cout << "  CUMCHI computes the chi square CDF\n";
  cout << "  CHI_SQUARE_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X       DF    CDF           CDF\n";
  cout << "                 (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    chi_square_cdf_values ( &n_data, &df, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    df_double = ( double ) df;

    cumchi ( &x, &df_double, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << x           << "  "
         << setw(2)  << df          << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "    X       DF    1-CDF         CCDF\n";
  cout << "                 (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    chi_square_cdf_values ( &n_data, &df, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    df_double = ( double ) df;

    cumchi ( &x, &df_double, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << x            << "  "
         << setw(2)  << df           << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumchn_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumchn_test tests CUMCHN, CHI_NONCENTRAL_CDF_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int df;
  double df_double;
  double lambda;
  int n_data;
  double x;

  cout << "\n";
  cout << "cumchn_test\n";
  cout << "  CUMCHN computes the CDF for the noncentral chi-squared\n";
  cout << "  distribution.\n";
  cout << "  CHI_NONCENTRAL_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    DF    Lambda    X         CDF           CDF\n";
  cout << "                             (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    chi_noncentral_cdf_values ( &n_data, &x, &lambda, &df, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    df_double = ( double ) df;

    cumchn ( &x, &df_double, &lambda, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(6)  << df          << "  "
         << setw(8)  << lambda      << "  "
         << setw(8)  << x           << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "    DF    Lambda    X         1-CDF         CCDF\n";
  cout << "                             (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    chi_noncentral_cdf_values ( &n_data, &x, &lambda, &df, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    df_double = ( double ) df;

    cumchn ( &x, &df_double, &lambda, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(6)  << df           << "  "
         << setw(8)  << lambda       << "  "
         << setw(8)  << x            << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumf_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumf_test tests CUMF, F_CDF_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int dfd;
  double dfd_double;
  int dfn;
  double dfn_double;
  int n_data;
  double x;

  cout << "\n";
  cout << "cumf_test\n";
  cout << "  CUMF computes the F CDF\n";
  cout << "  F_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X      DFN DFD    CDF           CDF\n";
  cout << "                     (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    f_cdf_values ( &n_data, &dfn, &dfd, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    dfn_double = ( double ) dfn;
    dfd_double = ( double ) dfd;

    cumf ( &x, &dfn_double, &dfd_double, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << x           << "  "
         << setw(2)  << dfn         << "  "
         << setw(2)  << dfd         << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";

  }

  cout << "\n";
  cout << "    X      DFN DFD    1-CDF         CCDF\n";
  cout << "                     (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    f_cdf_values ( &n_data, &dfn, &dfd, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    dfn_double = ( double ) dfn;
    dfd_double = ( double ) dfd;

    cumf ( &x, &dfn_double, &dfd_double, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << x            << "  "
         << setw(2)  << dfn          << "  "
         << setw(2)  << dfd          << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumfnc_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumfnc_test tests CUMFNC, F_NONCENTRAL_CDF_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int dfd;
  double dfd_double;
  int dfn;
  double dfn_double;
  double lambda;
  int n_data;
  double x;

  cout << "\n";
  cout << "cumfnc_test\n";
  cout << "  CUMFNC computes the noncentral F CDF\n";
  cout << "  F_NONCENTRAL_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X      DFN DFD    LAMBDA    CDF           CDF\n";
  cout << "                               (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    f_noncentral_cdf_values ( &n_data, &dfn, &dfd, &lambda, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    dfn_double = ( double ) dfn;
    dfd_double = ( double ) dfd;

    cumfnc ( &x, &dfn_double, &dfd_double, &lambda, &cdf_compute,
      &ccdf_compute );

    cout << "  "
         << setw(8)  << x           << "  "
         << setw(2)  << dfn         << "  "
         << setw(2)  << dfd         << "  "
         << setw(8)  << lambda      << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "    X      DFN DFD    LAMBDA    1-CDF         CCDF\n";
  cout << "                               (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    f_noncentral_cdf_values ( &n_data, &dfn, &dfd, &lambda, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    dfn_double = ( double ) dfn;
    dfd_double = ( double ) dfd;

    cumfnc ( &x, &dfn_double, &dfd_double, &lambda, &cdf_compute,
      &ccdf_compute );

    cout << "  "
         << setw(8)  << x            << "  "
         << setw(2)  << dfn          << "  "
         << setw(2)  << dfd          << "  "
         << setw(8)  << lambda       << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumgam_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumgam_test tests CUMGAM, GAMMA_INC_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int n_data;
  double x;

  cout << "\n";
  cout << "cumgam_test\n";
  cout << "  CUMGAM computes the Gamma CDF\n";
  cout << "  GAMMA_INC_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    A         X         CDF           CDF\n";
  cout << "                        (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    gamma_inc_values ( &n_data, &a, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    cumgam ( &x, &a, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << a           << "  "
         << setw(8)  << x           << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "    A         X         CDF           CDF\n";
  cout << "                        (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    gamma_inc_values ( &n_data, &a, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    cumgam ( &x, &a, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << a            << "  "
         << setw(8)  << x            << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumnbn_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumnbn_test tests cumnbn() and negative_binomial_cdf_values()
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int f;
  double f_double;
  int n_data;
  double ompr;
  int s;
  double s_double;
  double pr;

  cout << "\n";
  cout << "cumnbn_test():\n";
  cout << "  cumnbn() computes the Negative Binomial CDF\n";
  cout << "  negative_binomial_cdf_values() looks up some values.\n";
  cout << "\n";
  cout << "   F   S    Pr       CDF           CDF\n";
  cout << "                     (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    negative_binomial_cdf_values ( &n_data, &f, &s, &pr, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ompr = 1.0 - pr;

    f_double = ( double ) f;
    s_double = ( double ) s;

    cumnbn ( &f_double, &s_double, &pr, &ompr, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(2)  << f           << "  "
         << setw(2)  << s           << "  "
         << setw(8)  << pr          << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "   F   S    Pr       1-CDF         CCDF\n";
  cout << "                     (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    negative_binomial_cdf_values ( &n_data, &f, &s, &pr, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    ompr = 1.0 - pr;

    f_double = ( double ) f;
    s_double = ( double ) s;

    cumnbn ( &f_double, &s_double, &pr, &ompr, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(2)  << f            << "  "
         << setw(2)  << s            << "  "
         << setw(8)  << pr           << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumnor_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumnor_test tests CUMNOR, NORMAL_CDF_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int n_data;
  double x;

  cout << "\n";
  cout << "cumnor_test\n";
  cout << "  CUMNOR computes the Normal CDF\n";
  cout << "  NORMAL_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X         CDF           CDF\n";
  cout << "              (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    normal_cdf_values ( &n_data, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    cumnor ( &x, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << x           << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "    X         1-CDF         CCDF\n";
  cout << "              (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    normal_cdf_values ( &n_data, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    cumnor ( &x, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << x            << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumpoi_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumpoi_test tests CUMPOI, POISSON_CDF_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double  cdf_lookup;
  double lambda;
  int n_data;
  int x;
  double x_double;

  cout << "\n";
  cout << "cumpoi_test\n";
  cout << "  CUMPOI computes the Poisson CDF\n";
  cout << "  POISSON_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "     X    LAMBDA    CDF           CDF\n";
  cout << "                   (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    poisson_cdf_values ( &n_data, &lambda, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    x_double = ( double ) x;

    cumpoi ( &x_double, &lambda, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(4)  << x           << "  "
         << setw(8)  << lambda      << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "     X    LAMBDA    1-CDF         CCDF\n";
  cout << "                   (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    poisson_cdf_values ( &n_data, &lambda, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    x_double = ( double ) x;
    ccdf_lookup = 1.0 - cdf_lookup;

    cumpoi ( &x_double, &lambda, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(4)  << x            << "  "
         << setw(8)  << lambda       << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void cumt_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    cumt_test tests CUMT, STUDENT_CDF_VALUES.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double ccdf_compute;
  double ccdf_lookup;
  double cdf_compute;
  double cdf_lookup;
  int df;
  double df_double;
  int n_data;
  double x;

  cout << "\n";
  cout << "cumt_test\n";
  cout << "  CUMT computes the Student T CDF\n";
  cout << "  STUDENT_CDF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X       DF    CDF           CDF\n";
  cout << "                 (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    student_cdf_values ( &n_data, &df, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }
    df_double = ( double ) df;

    cumt ( &x, &df_double, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << x           << "  "
         << setw(2)  << df          << "  "
         << setw(12) << cdf_lookup  << "  "
         << setw(12) << cdf_compute << "\n";
  }

  cout << "\n";
  cout << "    X       DF    1-CDF         CCDF\n";
  cout << "                 (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    student_cdf_values ( &n_data, &df, &x, &cdf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    ccdf_lookup = 1.0 - cdf_lookup;

    df_double = ( double ) df;

    cumt ( &x, &df_double, &cdf_compute, &ccdf_compute );

    cout << "  "
         << setw(8)  << x            << "  "
         << setw(2)  << df           << "  "
         << setw(12) << ccdf_lookup  << "  "
         << setw(12) << ccdf_compute << "\n";
  }

  return;
}
//****************************************************************************80

void beta_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    beta_test tests BETA.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  double b;
  double apb;
  double beta1;
  double beta2;

  cout << "\n";
  cout << "beta_test\n";
  cout << "  BETA evaluates the Beta function;\n";
  cout << "  GAMMA_X evaluates the Gamma function.\n";

  a = 2.2;
  b = 3.7;
  apb = a + b;

  beta1 = beta ( a, b );
  beta2 = gamma_x ( &a ) * gamma_x ( &b ) / gamma_x ( &apb );

  cout << "\n";
  cout << "  Argument A =                   " << a << "\n";
  cout << "  Argument B =                   " << b << "\n";
  cout << "  Beta(A,B) =                    " << beta1 << "\n";
  cout << "  (Expected value = 0.0454 )\n";
  cout << "\n";
  cout << "  Gamma(A)*Gamma(B)/Gamma(A+B) = " << beta2 << "\n";

  return;
}
//****************************************************************************80

void error_f_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    error_f_test tests ERROR_F, ERROR_FC, ERF_VALUES..
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 November 2006
//
//  Author:
//
//    John Burkardt
//
{
  double erf_compute;
  double erf_lookup;
  double erfc_compute;
  double erfc_lookup;
  int ind;
  int n_data;
  double x;

  cout << "\n";
  cout << "error_f_test\n";
  cout << "  ERROR_F computes the error function ERF;\n";
  cout << "  ERROR_FC the complementary error function ERFC.\n";
  cout << "  ERF_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X         ERF           ERF\n";
  cout << "              (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    erf_values ( &n_data, &x, &erf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    erf_compute = error_f ( &x );

    cout << "  "
         << setw(8)  << x           << "  "
         << setw(12) << erf_lookup  << "  "
         << setw(12) << erf_compute << "\n";
  }

  cout << "\n";
  cout << "    X         ERFC          ERFC\n";
  cout << "              (Lookup)      (Computed)\n";
  cout << "\n";

  ind = 0;
  n_data = 0;

  for ( ; ; )
  {
    erf_values ( &n_data, &x, &erf_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    erfc_lookup = 1.0 - erf_lookup;
    erfc_compute = error_fc ( &ind, &x );

    cout << "  "
         << setw(8)  << x            << "  "
         << setw(12) << erfc_lookup  << "  "
         << setw(12) << erfc_compute << "\n";
  }

  return;
}
//****************************************************************************80

void gamma_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    gamma_test tests GAMMA_X.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 February 2021
//
//  Author:
//
//    John Burkardt
//
{
  double gamma_x_compute;
  double gamma_lookup;
  int n_data;
  double tgamma_compute;
  double x;

  cout << "\n";
  cout << "gamma_test\n";
  cout << "  GAMMA_X computes the Gamma function;\n";
  cout << "  tgamma() computes the Gamma function (math library)\n";
  cout << "  GAMMA_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X         GAMMA         tgamma()     GAMMA_X\n";
  cout << "              (Lookup)                   (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    gamma_values ( &n_data, &x, &gamma_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    tgamma_compute = tgamma ( x );

    gamma_x_compute = gamma_x ( &x );

    cout << "  " << setw(8)  << x
         << "  " << setw(12) << gamma_lookup
         << "  " << setw(12) << tgamma_compute 
         << "  " << setw(12) << gamma_x_compute << "\n";
  }

  return;
}
//****************************************************************************80

void gamma_inc_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    gamma_inc_test tests GAMMA_INC, GAMMA_INC_INV.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double a;
  int i;
  int ierror;
  int ind;
  double p;
  double q;
  int test_num = 10;
  double x;
  double x0;
  double x2;

  a = 3.0;
  ind = 1;
  x0 = 0;

  cout << "\n";
  cout << "gamma_inc_test\n";
  cout << "  GAMMA_INC evaluates the incomplete Gamma ratio;\n";
  cout << "  GAMMA_INC_INV inverts it.\n";
  cout << "\n";
  cout << "  Parameters:\n";
  cout << "\n";
  cout << "    A = " << a << "\n";
  cout << "\n";
  cout << "    X             P             Q             Inverse\n";
  cout << "\n";

  for ( i = 0; i <= test_num; i++ )
  {
    x = ( double ) i / ( double ) test_num;

    gamma_inc ( &a, &x, &p, &q, &ind );

    gamma_inc_inv ( &a, &x2, &x0, &p, &q, &ierror );

    cout << "  "
         << setw(12) << x  << "  "
         << setw(12) << p  << "  "
         << setw(12) << q  << "  "
         << setw(12) << x2 << "\n";
  }

  return;
}
//****************************************************************************80

void psi_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    psi_test tests PSI.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    14 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double psi_compute;
  double psi_lookup;
  int n_data;
  double x;

  cout << "\n";
  cout << "psi_test\n";
  cout << "  PSI computes the Psi function;\n";
  cout << "  PSI_VALUES looks up some values.\n";
  cout << "\n";
  cout << "    X         PSI           PSI\n";
  cout << "              (Lookup)      (Computed)\n";
  cout << "\n";

  n_data = 0;

  for ( ; ; )
  {
    psi_values ( &n_data, &x, &psi_lookup );

    if ( n_data == 0 )
    {
      break;
    }

    psi_compute = psi ( &x );

    cout << "  "
         << setw(8)  << x           << "  "
         << setw(12) << psi_lookup  << "  "
         << setw(12) << psi_compute << "\n";
  }

  return;
}

