# include <cstdlib>
# include <cctype>
# include <iostream>
# include <string>

using namespace std;

# include "byname.hpp"

//****************************************************************************80

double byname ( string action, string name, double *value_in )

//****************************************************************************80
//
//  Purpose:
//
//    byname() controls a set of named persistent data.
//
//  Discussion:
//
//    Three values are stored, named ALPHA, BETA and GAMMA.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 May 2021
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    string ACTION (case insensitive, only first character important)
//    ""        defaults to "Print"
//    "Get"     get the value;
//    "Print"   print the value;
//    "Reset"   reset value to default;
//    "Set"     set the value;
//
//    string NAME, the name of the parameter (case insensitive)
//    "ALPHA"
//    "BETA"
//    "GAMMA"
//    "*" (all variables)
//    NAME is required for "Get" and "Set".  
//    NAME, if omitted, is assumed "*" for "Print" and "Reset".
//
//    double *VALUE_IN.
//    Only used for "Set" command.
//
//  Output:
//
//    double *VALUE_OUT.
//    If NAME was specified on input, and was not "*", then
//    VALUE_OUT is the current value of the corresponding variable.
//    Otherwise, VALUE_OUT is empty.
//
{
  char action2;
  static double alpha = 1.0;
  static double alpha_default = 1.0;
  static double beta = 2.0;
  static double beta_default = 2.0;
  static double gamma = 3.0;
  static double gamma_default = 3.0;
  bool match;
  char name2;
  double value_out;
//
//  Check action.
//
  if ( action == "" )
  {
    action2 = 'p';
  }
  else
  {
    action2 = action[0];
    action2 = tolower ( action2 );
    match = 
      ( action2 == 'g' ) |
      ( action2 == 'p' ) |
      ( action2 == 'r' ) |
      ( action2 == 's' ) ;

    if ( ! match )
    {
      cout << "\n";
      cout << "byname: Fatal error!\n";
      cout << "  Legal actions are 'g', 'p', 'r', 's', not '" << action << "'\n";
      exit ( 1 );
    }
  }
//
//  Check name.
//
  if ( name == "" )
  {
    name2 = '*';
  }
  else
  {
    name2 = name[0];
    name2 = tolower ( name2 );

    match = 
      ( name2 == 'a' ) |
      ( name2 == 'b' ) |
      ( name2 == 'g' ) |
      ( name2 == '*' );

    if ( ! match )
    {
      cout << "\n";
      cout << "byname: Fatal error!\n";
      cout << "  Legal names are 'alpha', 'beta', 'gamma', '*', not '" << name << "'\n";
      exit ( 1 );
    }
  }
//
//  Check value.
//
  if ( ( action2 == 's' ) & ( ! value_in ) )
  {
    cout << "\n";
    cout << "byname: Fatal error!\n";
    cout << "  'set, name' command but no 'value'.\n";
    exit ( 1 );
  }
//
//  Carry out requested action.
//
  value_out = 0.0;

  if ( action2 == 'g' )
  {
    if ( name2 == 'a' )
    {
      value_out = alpha;
    }
    else if ( name2 == 'b' )
    {
      value_out = beta;
    }
    else if ( name2 == 'g' )
    {
      value_out = gamma;
    }
  }
  else if ( action2 == 'p' )
  {
    if ( ( name2 == 'a' ) | ( name2 == '*' ) )
    {
      cout << "alpha = " << alpha << "\n";
    }
    if ( name2 == 'a' )
    {
      value_out = alpha;
    }
    if ( ( name2 == 'b' ) | ( name2 == '*' ) )
    {
      cout << "beta = " << beta << "\n";
    }
    if ( name2 == 'b' )
    {
      value_out = beta;
    }
    if ( ( name2 == 'g' ) | ( name2 == '*' ) )
    {
      cout << "gamma = " << gamma << "\n";
    }
    if ( name2 == 'g' )
    {
      value_out = gamma;
    }
  }
  else if ( action2 == 'r' )
  {
    if ( ( name2 == 'a' ) | ( name2 == '*' ) )
    {
      alpha = alpha_default;
    }
    if ( name2 == 'a' )
    {
      value_out = alpha;
    }
    if ( ( name2 == 'b' ) | ( name2 == '*' ) )
    {
      beta = beta_default;
    }
    if ( name2 == 'b' )
    {
      value_out = beta;
    }
    if ( ( name2 == 'g' ) | ( name2 == '*' ) )
    {
      gamma = gamma_default;
    }
    if ( name2 == 'g' )
    {
      value_out = gamma;
    }
  }
  else if ( action2 == 's' )
  {
    if ( name2 == 'a' )
    {
      alpha = *value_in;
      value_out = alpha;
    }
    if ( name2 == 'b' )
    {
      beta = *value_in;
      value_out = beta;
    }
    if ( name2 == 'g' )
    {
      gamma = *value_in;
      value_out = gamma;
    }
  }

  return value_out;
}
