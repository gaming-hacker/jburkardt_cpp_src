# include <cstdlib>
# include <iostream>
# include <iomanip>

using namespace std;

# include "machar.hpp"

int main ( );
void r4_machar_test ( );
void r8_machar_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for MACHAR_TEST.
//
//  Discussion:
//
//    MACHAR_TEST tests the MACHAR library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 November 2006
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "MACHAR_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the MACHAR library.\n";

  r4_machar_test ( );
  r8_machar_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "MACHAR_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void r4_machar_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R4_MACHAR_TEST tests R4_MACHAR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    24 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  float eps;
  float epsneg;
  long int ibeta;
  long int iexp;
  long int irnd;
  long int it;
  long int machep;
  long int maxexp;
  long int minexp;
  long int negep;
  long int ngrd;
  float xmax;
  float xmin;

  cout << "\n";
  cout << "R4_MACHAR_TEST\n";
  cout << "  R4_MACHAR computes single\n";
  cout << "  precision machine constants.\n";

  r4_machar ( &ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp,
    &minexp, &maxexp, &eps, &epsneg, &xmin, &xmax );

  cout << "\n";
  cout << "  IBETA =  " << ibeta << "\n";
  cout << "  IT =     " << it << "\n";
  cout << "  IRND =   " << irnd << "\n";
  cout << "  NGRD =   " << ngrd << "\n";
  cout << "  MACHEP = " << machep << "\n";
  cout << "  NEGEP =  " << negep << "\n";
  cout << "  IEXP =   " << iexp << "\n";
  cout << "  MINEXP = " << minexp << "\n";
  cout << "  MAXEXP = " << maxexp << "\n";
  cout << setw(26) << setprecision(16) << "  EPS =    " << eps << "\n";
  cout << setw(26) << setprecision(16) << "  EPSNEG = " << epsneg << "\n";
  cout << setw(26) << setprecision(16) << "  XMIN =   " << xmin << "\n";
  cout << setw(26) << setprecision(16) << "  XMAX =   " << xmax << "\n";

  return;
}
//****************************************************************************80

void r8_machar_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_MACHAR_TEST tests R8_MACHAR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    24 April 2007
//
//  Author:
//
//    John Burkardt
//
{
  double eps;
  double epsneg;
  long int ibeta;
  long int iexp;
  long int irnd;
  long int it;
  long int machep;
  long int maxexp;
  long int minexp;
  long int negep;
  long int ngrd;
  double xmax;
  double xmin;

  cout << "\n";
  cout << "R8_MACHAR_TEST\n";
  cout << "  R8_MACHAR computes double\n";
  cout << "  precision machine constants.\n";

  r8_machar ( &ibeta, &it, &irnd, &ngrd, &machep, &negep, &iexp,
    &minexp, &maxexp, &eps, &epsneg, &xmin, &xmax );

  cout << "\n";
  cout << "  IBETA =  " << ibeta << "\n";
  cout << "  IT =     " << it << "\n";
  cout << "  IRND =   " << irnd << "\n";
  cout << "  NGRD =   " << ngrd << "\n";
  cout << "  MACHEP = " << machep << "\n";
  cout << "  NEGEP =  " << negep << "\n";
  cout << "  IEXP =   " << iexp << "\n";
  cout << "  MINEXP = " << minexp << "\n";
  cout << "  MAXEXP = " << maxexp << "\n";
  cout << setw(26) << setprecision(16) << "  EPS =    " << eps << "\n";
  cout << setw(26) << setprecision(16) << "  EPSNEG = " << epsneg << "\n";
  cout << setw(26) << setprecision(16) << "  XMIN =   " << xmin << "\n";
  cout << setw(26) << setprecision(16) << "  XMAX =   " << xmax << "\n";

  return;
}
