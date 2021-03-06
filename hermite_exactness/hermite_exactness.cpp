# include <cstdlib>
# include <cmath>
# include <iostream>
# include <fstream>
# include <iomanip>
# include <ctime>
# include <cstring>

using namespace std;

int main ( int argc, char *argv[] );
char ch_cap ( char ch );
bool ch_eqi ( char ch1, char ch2 );
int ch_to_digit ( char ch );
int file_column_count ( string input_filename );
int file_row_count ( string input_filename );
double hermite_integral ( int n, int option );
double hermite_monomial_quadrature ( int expon, int order, int option,
  double w[], double x[] );
double r8_abs ( double x );
double r8_factorial2 ( int n );
double r8_huge ( );
double *r8mat_data_read ( string input_filename, int m, int n );
void r8mat_header_read ( string input_filename, int *m, int *n );
int s_len_trim ( string s );
int s_to_i4 ( string s, int *last, bool *error );
double s_to_r8 ( string s, int *lchar, bool *error );
bool s_to_r8vec ( string s, int n, double rvec[] );
int s_word_count ( string s );
void timestamp ( );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for HERMITE_EXACTNESS.
//
//  Discussion:
//
//    This program investigates a standard Gauss-Hermite quadrature rule
//    by using it to integrate monomials over (-oo,+oo), and comparing the
//    approximate result to the known exact value.
//
//    The user specifies:
//    * the "root" name of the R, W and X files that specify the rule;
//    * DEGREE_MAX, the maximum monomial degree to be checked.
//    * the OPTION (unweighted/physicist weight/probabilist weight)
//
//    OPTION indicates the weight function and normalization:
//    0, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
//    1, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
//    2, Integral ( -oo < x < +oo ) x^n exp(-x*x/2)             dx.
//    3, Integral ( -oo < x < +oo ) x^n exp(-x*x)   / sqrt (pi) dx.
//    4, Integral ( -oo < x < +oo ) x^n exp(-x*x/2) / sqrt(2pi) dx.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 June 2013
//
//  Author:
//
//    John Burkardt
//
{
  int degree;
  int degree_max;
  int dim_num;
  int dim_num2;
  int i;
  int option;
  int order;
  int point_num;
  int point_num2;
  double quad_error;
  string quad_filename;
  string quad_r_filename;;
  string quad_w_filename;
  string quad_x_filename;
  double *r;
  double *w;
  double *x;

  timestamp ( );
  cout << "\n";
  cout << "HERMITE_EXACTNESS\n";
  cout << "  C++ version\n";
  cout << "\n";
  cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << ".\n";
  cout << "\n";
  cout << "  Investigate the polynomial exactness of a Gauss-Hermite\n";
  cout << "  quadrature rule by integrating exponentially weighted\n";
  cout << "  monomials up to a given degree over the (-oo,+oo) interval.\n";
//
//  Get the quadrature file rootname.
//
  if ( 1 < argc )
  {
    quad_filename = argv[1];
  }
  else
  {
    cout << "\n";
    cout << "  Enter the quadrature file rootname:\n";
    cin >> quad_filename;
  }

  cout << "\n";
  cout << "  The quadrature file rootname is \"" << quad_filename << "\".\n";
//
//  Create the names of:
//    the quadrature X file;
//    the quadrature W file;
//    the quadrature R file;
//
  quad_w_filename = quad_filename + "_w.txt";
  quad_x_filename = quad_filename + "_x.txt";
  quad_r_filename = quad_filename + "_r.txt";
//
//  Get the maximum degree:
//
  if ( 2 < argc )
  {
    degree_max = atoi ( argv[2] );

  }
  else
  {
    cout << "\n";
    cout << "  Enter DEGREE_MAX, the maximum monomial degree to check.\n";
    cin >> degree_max;
  }
  cout << "\n";
  cout << "  The requested maximum monomial degree is = " << degree_max << "\n";
//
//  The third command line argument is OPTION.
//
  if ( 3 < argc )
  {
    option = atoi ( argv[3] );
  }
  else
  {
    cout << "\n";
    cout << "HERMITE_EXACTNESS:\n";
    cout << "  OPTION specifies the weight function rho(x):\n";
    cout << "\n";
    cout << "  0, rho(x) = 1\n";
    cout << "  1, rho(x) = exp ( -x*x  )\n";
    cout << "  2, rho(x) = exp ( -x*x/2)\n";
    cout << "  3, rho(x) = exp ( -x*x  ) / sqrt( pi)\n";
    cout << "  4, rho(x) = exp ( -x*x/2) / sqrt(2pi)\n";
    cout << "\n";
    cout << "  Please enter OPTION:\n";
    cin >> option;
  }

  if ( option < 0 || 4 < option )
  {
    cerr << "\n";
    cerr << "HERMITE_EXACTNESS - Fatal error!\n";
    cerr << "  Illegal value of OPTION.\n";
    exit ( 1 );
  }
//
//  Summarize the input.
//
  cout << "\n";
  cout << "HERMITE_EXACTNESS: User input:\n";
  cout << "  Quadrature rule X file = \"" << quad_x_filename << "\".\n";
  cout << "  Quadrature rule W file = \"" << quad_w_filename << "\".\n";
  cout << "  Quadrature rule R file = \"" << quad_r_filename << "\".\n";
  cout << "  Maximum degree to check = " << degree_max << "\n";
//
//  Read the X file.
//
  r8mat_header_read ( quad_x_filename, &dim_num, &order );

  if ( dim_num != 1 )
  {
    cerr << "\n";
    cerr << "HERMITE_EXACTNESS - Fatal error!\n";
    cerr << "  The spatial dimension of X should be 1.\n";
    cerr << " The implicit input dimension was DIM_NUM = " << dim_num << "\n";
    exit ( 1 );
  }

  cout << "\n";
  cout << "  Spatial dimension = " << dim_num << "\n";
  cout << "  Number of points  = " << order << "\n";

  x = r8mat_data_read ( quad_x_filename, dim_num, order );
//
//  Read the W file.
//
  r8mat_header_read ( quad_w_filename, &dim_num2, &point_num );

  if ( dim_num2 != 1 )
  {
    cerr << "\n";
    cerr << "HERMITE_EXACTNESS - Fatal error!\n";
    cerr << "  The quadrature weight file should have exactly\n";
    cerr << "  one value on each line.\n";
    exit ( 1 );
  }

  if ( point_num != order )
  {
    cerr << "\n";
    cerr << "HERMITE_EXACTNESS - Fatal error!\n";
    cerr << "  The quadrature weight file should have exactly\n";
    cerr << "  the same number of lines as the abscissa file.\n";
    exit ( 1 );
  }

  w = r8mat_data_read ( quad_w_filename, dim_num, order );
//
//  Read the R file.
//
  r8mat_header_read ( quad_r_filename, &dim_num2, &point_num2 );

  if ( dim_num2 != dim_num )
  {
    cerr << "\n";
    cerr << "HERMITE_EXACTNESS - Fatal error!\n";
    cerr << "  The quadrature region file should have the\n";
    cerr << "  same number of values on each line as the\n";
    cerr << "  abscissa file does.\n";
    exit ( 1 );
  }

  if ( point_num2 != 2 )
  {
    cerr << "\n";
    cerr << "HERMITE_EXACTNESS - Fatal error!\n";
    cerr << "  The quadrature region file should have two lines.\n";
    exit ( 1 );
  }

  r = r8mat_data_read ( quad_r_filename, dim_num, point_num2 );
//
//  Print the input quadrature rule.
//
  cout << "\n";
  cout << "  The quadrature rule to be tested is\n";
  cout << "  a Gauss-Hermite rule\n";
  cout << "  ORDER = " << order << "\n";
  cout << "\n";
  if ( option == 0 )
  {
    cout << "  OPTION = 0, the unweighted rule for:\n";
    cout << "  Integral ( -oo < x < +oo ) f(x) dx\n";
  }
  else if ( option == 1 )
  {
    cout << "  OPTION = 1, the physicist weighted rule for:\n";
    cout << "  Integral ( -oo < x < +oo ) f(x) * exp(-x*x) dx\n";
  }
  else if ( option == 2 )
  {
    cout << "  OPTION = 2, the probabilist weighted rule for:\n";
    cout << "  Integral ( -oo < x < +oo ) f(x) * exp(-x*x/2) dx\n";
  }
  else if ( option == 3 )
  {
    cout << "  OPTION = 3, the physicist normalized weighted rule for:\n";
    cout << "  Integral ( -oo < x < +oo ) f(x) * exp(-x*x) / sqrt(pi) dx\n";
  }
  else if ( option == 4 )
  {
    cout << "  OPTION = 4, the probabilist normalized weighted rule for:\n";
    cout << "  Integral ( -oo < x < +oo ) f(x) * exp(-x*x/2) / sqrt(2 pi) dx\n";
  }
  cout << "\n";
  cout << "  Weights W:\n";
  cout << "\n";
  for ( i = 0; i < order; i++ )
  {
    cout << "  w[" << setw(2) << i
         << "] = " << setw(24) << setprecision(16) << w[i] << "\n";
  }
  cout << "\n";
  cout << "  Abscissas X:\n";
  cout << "\n";
  for ( i = 0; i < order; i++ )
  {
    cout << "  x[" << setw(2) << i
         << "] = " << setw(24) << setprecision(16) << x[i] << "\n";
  }
  cout << "\n";
  cout << "  Region R:\n";
  cout << "\n";

  for ( i = 0; i < 2; i++ )
  {
    cout << "  r[" << setw(2) << i
         << "] = " << setw(24) << setprecision(16) << r[i] << "\n";
  }
//
//  Explore the monomials.
//
  cout << "\n";
  cout << "  A Gauss-Hermite rule would be able to exactly\n";
  cout << "  integrate monomials up to and including degree = " <<
   2 * order - 1 << "\n";
  cout << "\n";
  cout << "  Degree          Error\n";
  cout << "\n";

  for ( degree = 0; degree <= degree_max; degree++ )
  {
    quad_error = hermite_monomial_quadrature ( degree, order, option, w, x );

    cout << "  " << setw(2) << degree
         << "  " << setw(24) << setprecision(16) << quad_error << "\n";
  }
//
//  Free memory.
//
  delete [] w;
  delete [] x;
  delete [] r;
//
//  Terminate.
//
  cout << "\n";
  cout << "HERMITE_EXACTNESS:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

char ch_cap ( char ch )

//****************************************************************************80
//
//  Purpose:
//
//    CH_CAP capitalizes a single character.
//
//  Discussion:
//
//    This routine should be equivalent to the library "toupper" function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 July 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, char CH, the character to capitalize.
//
//    Output, char CH_CAP, the capitalized character.
//
{
  if ( 97 <= ch && ch <= 122 ) 
  {
    ch = ch - 32;
  }   

  return ch;
}
//****************************************************************************80

bool ch_eqi ( char ch1, char ch2 )

//****************************************************************************80
//
//  Purpose:
//
//    CH_EQI is true if two characters are equal, disregarding case.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 June 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, char CH1, CH2, the characters to compare.
//
//    Output, bool CH_EQI, is true if the two characters are equal,
//    disregarding case.
//
{
  if ( 97 <= ch1 && ch1 <= 122 ) 
  {
    ch1 = ch1 - 32;
  } 
  if ( 97 <= ch2 && ch2 <= 122 ) 
  {
    ch2 = ch2 - 32;
  }     

  return ( ch1 == ch2 );
}
//****************************************************************************80

int ch_to_digit ( char ch )

//****************************************************************************80
//
//  Purpose:
//
//    CH_TO_DIGIT returns the value of a base 10 digit.
//
//  Example:
//
//     CH  DIGIT
//    ---  -----
//    '0'    0
//    '1'    1
//    ...  ...
//    '9'    9
//    ' '    0
//    'X'   -1
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 June 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, char CH, the decimal digit, '0' through '9' or blank are legal.
//
//    Output, int CH_TO_DIGIT, the corresponding value.  If the 
//    character was 'illegal', then DIGIT is -1.
//
{
  int digit;

  if ( '0' <= ch && ch <= '9' )
  {
    digit = ch - '0';
  }
  else if ( ch == ' ' )
  {
    digit = 0;
  }
  else
  {
    digit = -1;
  }

  return digit;
}
//****************************************************************************80

int file_column_count ( string filename )

//****************************************************************************80
//
//  Purpose:
//
//    FILE_COLUMN_COUNT counts the columns in the first line of a file.
//
//  Discussion:
//
//    The file is assumed to be a simple text file.
//
//    Most lines of the file are presumed to consist of COLUMN_NUM words, 
//    separated by spaces.  There may also be some blank lines, and some 
//    comment lines, which have a "#" in column 1.
//
//    The routine tries to find the first non-comment non-blank line and
//    counts the number of words in that line.
//
//    If all lines are blanks or comments, it goes back and tries to analyze
//    a comment line.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string FILENAME, the name of the file.
//
//    Output, int FILE_COLUMN_COUNT, the number of columns assumed 
//    to be in the file.
//
{
  int column_num;
  ifstream input;
  bool got_one;
  string text;
//
//  Open the file.
//
  input.open ( filename.c_str ( ) );

  if ( !input )
  {
    column_num = -1;
    cerr << "\n";
    cerr << "FILE_COLUMN_COUNT - Fatal error!\n";
    cerr << "  Could not open the file:\n";
    cerr << "  \"" << filename << "\"\n";
    return column_num;
  }
//
//  Read one line, but skip blank lines and comment lines.
//
  got_one = false;

  for ( ; ; )
  {
    getline ( input, text );

    if ( input.eof ( ) )
    {
      break;
    }

    if ( s_len_trim ( text ) <= 0 )
    {
      continue;
    }

    if ( text[0] == '#' )
    {
      continue;
    }
    got_one = true;
    break;
  }

  if ( !got_one )
  {
    input.close ( );

    input.open ( filename.c_str ( ) );

    for ( ; ; )
    {
      input >> text;

      if ( input.eof ( ) )
      {
        break;
      }

      if ( s_len_trim ( text ) == 0 )
      {
        continue;
      }
      got_one = true;
      break;
    }
  }

  input.close ( );

  if ( !got_one )
  {
    cerr << "\n";
    cerr << "FILE_COLUMN_COUNT - Warning!\n";
    cerr << "  The file does not seem to contain any data.\n";
    return -1;
  }

  column_num = s_word_count ( text );

  return column_num;
}
//****************************************************************************80

int file_row_count ( string input_filename )

//****************************************************************************80
//
//  Purpose:
//
//    FILE_ROW_COUNT counts the number of row records in a file.
//
//  Discussion:
//
//    It does not count lines that are blank, or that begin with a
//    comment symbol '#'.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 February 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string INPUT_FILENAME, the name of the input file.
//
//    Output, int FILE_ROW_COUNT, the number of rows found.
//
{
  int comment_num;
  ifstream input;
  string line;
  int record_num;
  int row_num;

  row_num = 0;
  comment_num = 0;
  record_num = 0;

  input.open ( input_filename.c_str ( ) );

  if ( !input )
  {
    cerr << "\n";
    cerr << "FILE_ROW_COUNT - Fatal error!\n";
    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";
    return (-1);
  }

  for ( ; ; )
  {
    getline ( input, line );

    if ( input.eof ( ) )
    {
      break;
    }

    record_num = record_num + 1;

    if ( line[0] == '#' )
    {
      comment_num = comment_num + 1;
      continue;
    }

    if ( s_len_trim ( line ) == 0 )
    {
      comment_num = comment_num + 1;
      continue;
    }

    row_num = row_num + 1;

  }

  input.close ( );

  return row_num;
}
//****************************************************************************80

double hermite_integral ( int n, int option )

//****************************************************************************80
//
//  Purpose:
//
//    HERMITE_INTEGRAL evaluates a monomial Hermite integral.
//
//  Discussion:
//
//    H(n,1) = Integral ( -oo < x < oo ) x^n exp(-x^2) dx
//    H(n,1) is 0 for n odd.
//    H(n,1) = (n-1)!! * sqrt(pi) / 2^(n/2) for n even.
//
//    H(n,2) = Integral ( -oo < x < +oo ) x^n exp(-x^2/2) dx
//    H(n,2) is 0 for n odd.
//    H(n,2) = (n-1)!! * sqrt(2*pi) for n even.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 June 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the order of the integral.  
//    0 <= N.
//
//    Input, int OPTION, the integral has the form:
//    0, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
//    1, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
//    2, Integral ( -oo < x < +oo ) x^n exp(-x*x/2)             dx.
//    3, Integral ( -oo < x < +oo ) x^n exp(-x*x)   / sqrt (pi) dx.
//    4, Integral ( -oo < x < +oo ) x^n exp(-x*x/2) / sqrt(2pi) dx.
//
//    Output, double HERMITE_INTEGRAL, the value of the integral.
//
{
  const double r8_pi = 3.141592653589793;
  double value;

  if ( n < 0 )
  {
    value = - r8_huge ( );
  }
  else if ( ( n % 2 ) == 1 )
  {
    value = 0.0;
  }
  else if ( option == 0 )
  {
    value = r8_factorial2 ( n - 1 ) * sqrt ( r8_pi ) / pow ( 2.0, n / 2 );
  }
  else if ( option == 1 )
  {
    value = r8_factorial2 ( n - 1 ) * sqrt ( r8_pi ) / pow ( 2.0, n / 2 );
  }
  else if ( option == 2 )
  {
    value = r8_factorial2 ( n - 1 ) * sqrt ( 2.0 * r8_pi );
  }
  else if ( option == 3 )
  {
    value = r8_factorial2 ( n - 1 ) / pow ( 2.0, n / 2 );
  }
  else if ( option == 4 )
  {
    value = r8_factorial2 ( n - 1 );
  }
  return value;
}
//****************************************************************************80

double hermite_monomial_quadrature ( int expon, int order, int option,
  double w[], double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    HERMITE_MONOMIAL_QUADRATURE applies a quadrature rule to a monomial.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 June 2013
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int EXPON, the exponent.
//
//    Input, int ORDER, the number of points in the rule.
//
//    Input, int OPTION, the integral has the form:
//    0, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
//    1, Integral ( -oo < x < +oo ) x^n exp(-x*x)               dx.
//    2, Integral ( -oo < x < +oo ) x^n exp(-x*x/2)             dx.
//    3, Integral ( -oo < x < +oo ) x^n exp(-x*x)   / sqrt (pi) dx.
//    4, Integral ( -oo < x < +oo ) x^n exp(-x*x/2) / sqrt(2pi) dx.
//
//    Input, double W[ORDER], the quadrature weights.
//
//    Input, double X[ORDER], the quadrature points.
//
//    Output, double HERMITE_MONOMIAL_QUADRATURE, the quadrature error.
//
{
  double exact;
  int i;
  double quad;
  double quad_error;
//
//  Get the exact value of the integral of the unscaled monomial.
//
  exact = hermite_integral ( expon, option );
//
//  Evaluate the unweighted monomial at the quadrature points.
//
  quad = 0.0;
  if ( option == 0 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * exp ( - x[i] * x[i] ) * pow ( x[i], expon );
    }
  }
  else if ( option == 1 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * pow ( x[i], expon );
    }
  }
  else if ( option == 2 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * pow ( x[i], expon );
    }
  }
  else if ( option == 3 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * pow ( x[i], expon );
    }
  }
  else if ( option == 4 )
  {
    for ( i = 0; i < order; i++ )
    {
      quad = quad + w[i] * pow ( x[i], expon );
    }
  }
//
//  Absolute error for cases where exact integral is zero,
//  Relative error otherwise.
//
  if ( exact == 0.0 )
  {
    quad_error = r8_abs ( quad );
  }
  else
  {
    quad_error = r8_abs ( quad - exact ) / r8_abs ( exact );
  }
  return quad_error;
}
//****************************************************************************80

double r8_abs ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_ABS returns the absolute value of an R8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 November 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the quantity whose absolute value is desired.
//
//    Output, double R8_ABS, the absolute value of X.
//
{
  double value;

  if ( 0.0 <= x )
  {
    value = x;
  } 
  else
  {
    value = -x;
  }
  return value;
}
//****************************************************************************80

double r8_factorial2 ( int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8_FACTORIAL2 computes the double factorial function.
//
//  Formula:
//
//    FACTORIAL2( N ) = Product ( N * (N-2) * (N-4) * ... * 2 )  (N even)
//                    = Product ( N * (N-2) * (N-4) * ... * 1 )  (N odd)
//
//  Example:
//
//     N    N!!
//
//     0     1
//     1     1
//     2     2
//     3     3
//     4     8
//     5    15
//     6    48
//     7   105
//     8   384
//     9   945
//    10  3840
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    22 January 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the argument of the double factorial 
//    function.  If N is less than 1, R8_FACTORIAL2 is returned as 1.0.
//
//    Output, double R8_FACTORIAL2, the value of the double factorial function.
//
{
  int n_copy;
  double value;

  value = 1.0;

  if ( n < 1 )
  {
    return value;
  }

  n_copy = n;

  while ( 1 < n_copy )
  {
    value = value * ( double ) n_copy;
    n_copy = n_copy - 2;
  }

  return value;
}
//****************************************************************************80

double r8_huge ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_HUGE returns a "huge" R8.
//
//  Discussion:
//
//    The value returned by this function is NOT required to be the
//    maximum representable R8.  This value varies from machine to machine,
//    from compiler to compiler, and may cause problems when being printed.
//    We simply want a "very large" but non-infinite number.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 October 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double R8_HUGE, a "huge" R8 value.
//
{
  double value;

  value = 1.0E+30;

  return value;
}
//****************************************************************************80

double *r8mat_data_read ( string input_filename, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_DATA_READ reads the data from an R8MAT file.
//
//  Discussion:
//
//    An R8MAT is an array of R8's.
//
//    The file is assumed to contain one record per line.
//
//    Records beginning with '#' are comments, and are ignored.
//    Blank lines are also ignored.
//
//    Each line that is not ignored is assumed to contain exactly (or at least)
//    M real numbers, representing the coordinates of a point.
//
//    There are assumed to be exactly (or at least) N such records.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 February 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string INPUT_FILENAME, the name of the input file.
//
//    Input, int M, the number of spatial dimensions.
//
//    Input, int N, the number of points.  The program
//    will stop reading data once N values have been read.
//
//    Output, double R8MAT_DATA_READ[M*N], the table data.
//
{
  bool error;
  ifstream input;
  int i;
  int j;
  string line;
  double *table;
  double *x;

  input.open ( input_filename.c_str ( ) );

  if ( !input )
  {
    cerr << "\n";
    cerr << "R8MAT_DATA_READ - Fatal error!\n";
    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";
    return NULL;
  }

  table = new double[m*n];

  x = new double[m];

  j = 0;

  while ( j < n )
  {
    getline ( input, line );

    if ( input.eof ( ) )
    {
      break;
    }

    if ( line[0] == '#' || s_len_trim ( line ) == 0 )
    {
      continue;
    }

    error = s_to_r8vec ( line, m, x );

    if ( error )
    {
      continue;
    }

    for ( i = 0; i < m; i++ )
    {
      table[i+j*m] = x[i];
    }
    j = j + 1;

  }

  input.close ( );

  delete [] x;

  return table;
}
//****************************************************************************80
 
void r8mat_header_read ( string input_filename, int *m, int *n )
 
//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_HEADER_READ reads the header from an R8MAT file.
//
//  Discussion:
//
//    An R8MAT is an array of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 February 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string INPUT_FILENAME, the name of the input file.
//
//    Output, int *M, the number of spatial dimensions.
//
//    Output, int *N, the number of points.
//
{
  *m = file_column_count ( input_filename );

  if ( *m <= 0 )
  {
    cerr << "\n";
    cerr << "R8MAT_HEADER_READ - Fatal error!\n";
    cerr << "  FILE_COLUMN_COUNT failed.\n";
    *n = -1;
    return;
  }

  *n = file_row_count ( input_filename );

  if ( *n <= 0 )
  {
    cerr << "\n";
    cerr << "R8MAT_HEADER_READ - Fatal error!\n";
    cerr << "  FILE_ROW_COUNT failed.\n";
    return;
  }

  return;
}
//****************************************************************************80

int s_len_trim ( string s )

//****************************************************************************80
//
//  Purpose:
//
//    S_LEN_TRIM returns the length of a string to the last nonblank.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string S, a string.
//
//    Output, int S_LEN_TRIM, the length of the string to the last nonblank.
//    If S_LEN_TRIM is 0, then the string is entirely blank.
//
{
  int n;

  n = s.length ( );

  while ( 0 < n ) 
  {
    if ( s[n-1] != ' ' )
    {
      return n;
    }
    n = n - 1;
  }

  return n;
}
//****************************************************************************80

int s_to_i4 ( string s, int *last, bool *error )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_I4 reads an I4 from a string.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string S, a string to be examined.
//
//    Output, int *LAST, the last character of S used to make IVAL.
//
//    Output, bool *ERROR is TRUE if an error occurred.
//
//    Output, int *S_TO_I4, the integer value read from the string.
//    If the string is blank, then IVAL will be returned 0.
//
{
  char c;
  int i;
  int isgn;
  int istate;
  int ival;

  *error = false;
  istate = 0;
  isgn = 1;
  i = 0;
  ival = 0;

  for ( ; ; ) 
  {
    c = s[i];
    i = i + 1;
//
//  Haven't read anything.
//
    if ( istate == 0 )
    {
      if ( c == ' ' )
      {
      }
      else if ( c == '-' )
      {
        istate = 1;
        isgn = -1;
      }
      else if ( c == '+' )
      {
        istate = 1;
        isgn = + 1;
      }
      else if ( '0' <= c && c <= '9' )
      {
        istate = 2;
        ival = c - '0';
      }
      else
      {
        *error = true;
        return ival;
      }
    }
//
//  Have read the sign, expecting digits.
//
    else if ( istate == 1 )
    {
      if ( c == ' ' )
      {
      }
      else if ( '0' <= c && c <= '9' )
      {
        istate = 2;
        ival = c - '0';
      }
      else
      {
        *error = true;
        return ival;
      }
    }
//
//  Have read at least one digit, expecting more.
//
    else if ( istate == 2 )
    {
      if ( '0' <= c && c <= '9' )
      {
        ival = 10 * (ival) + c - '0';
      }
      else
      {
        ival = isgn * ival;
        *last = i - 1;
        return ival;
      }

    }
  }
//
//  If we read all the characters in the string, see if we're OK.
//
  if ( istate == 2 )
  {
    ival = isgn * ival;
    *last = s_len_trim ( s );
  }
  else
  {
    *error = true;
    *last = 0;
  }

  return ival;
}
//****************************************************************************80

double s_to_r8 ( string s, int *lchar, bool *error )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_R8 reads an R8 from a string.
//
//  Discussion:
//
//    This routine will read as many characters as possible until it reaches
//    the end of the string, or encounters a character which cannot be
//    part of the real number.
//
//    Legal input is:
//
//       1 blanks,
//       2 '+' or '-' sign,
//       2.5 spaces
//       3 integer part,
//       4 decimal point,
//       5 fraction part,
//       6 'E' or 'e' or 'D' or 'd', exponent marker,
//       7 exponent sign,
//       8 exponent integer part,
//       9 exponent decimal point,
//      10 exponent fraction part,
//      11 blanks,
//      12 final comma or semicolon.
//
//    with most quantities optional.
//
//  Example:
//
//    S                 R
//
//    '1'               1.0
//    '     1   '       1.0
//    '1A'              1.0
//    '12,34,56'        12.0
//    '  34 7'          34.0
//    '-1E2ABCD'        -100.0
//    '-1X2ABCD'        -1.0
//    ' 2E-1'           0.2
//    '23.45'           23.45
//    '-4.2E+2'         -420.0
//    '17d2'            1700.0
//    '-14e-2'         -0.14
//    'e2'              100.0
//    '-12.73e-9.23'   -12.73 * 10.0^(-9.23)
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string S, the string containing the
//    data to be read.  Reading will begin at position 1 and
//    terminate at the end of the string, or when no more
//    characters can be read to form a legal real.  Blanks,
//    commas, or other nonnumeric data will, in particular,
//    cause the conversion to halt.
//
//    Output, int *LCHAR, the number of characters read from
//    the string to form the number, including any terminating
//    characters such as a trailing comma or blanks.
//
//    Output, bool *ERROR, is true if an error occurred.
//
//    Output, double S_TO_R8, the real value that was read from the string.
//
{
  char c;
  int ihave;
  int isgn;
  int iterm;
  int jbot;
  int jsgn;
  int jtop;
  int nchar;
  int ndig;
  double r;
  double rbot;
  double rexp;
  double rtop;
  char TAB = 9;

  nchar = s_len_trim ( s );
  *error = false;
  r = 0.0;
  *lchar = -1;
  isgn = 1;
  rtop = 0.0;
  rbot = 1.0;
  jsgn = 1;
  jtop = 0;
  jbot = 1;
  ihave = 1;
  iterm = 0;

  for ( ; ; )
  {
    c = s[*lchar+1];
    *lchar = *lchar + 1;
//
//  Blank or TAB character.
//
    if ( c == ' ' || c == TAB )
    {
      if ( ihave == 2 )
      {
      }
      else if ( ihave == 6 || ihave == 7 )
      {
        iterm = 1;
      }
      else if ( 1 < ihave )
      {
        ihave = 11;
      }
    }
//
//  Comma.
//
    else if ( c == ',' || c == ';' )
    {
      if ( ihave != 1 )
      {
        iterm = 1;
        ihave = 12;
        *lchar = *lchar + 1;
      }
    }
//
//  Minus sign.
//
    else if ( c == '-' )
    {
      if ( ihave == 1 )
      {
        ihave = 2;
        isgn = -1;
      }
      else if ( ihave == 6 )
      {
        ihave = 7;
        jsgn = -1;
      }
      else
      {
        iterm = 1;
      }
    }
//
//  Plus sign.
//
    else if ( c == '+' )
    {
      if ( ihave == 1 )
      {
        ihave = 2;
      }
      else if ( ihave == 6 )
      {
        ihave = 7;
      }
      else
      {
        iterm = 1;
      }
    }
//
//  Decimal point.
//
    else if ( c == '.' )
    {
      if ( ihave < 4 )
      {
        ihave = 4;
      }
      else if ( 6 <= ihave && ihave <= 8 )
      {
        ihave = 9;
      }
      else
      {
        iterm = 1;
      }
    }
//
//  Exponent marker.
//
    else if ( ch_eqi ( c, 'E' ) || ch_eqi ( c, 'D' ) )
    {
      if ( ihave < 6 )
      {
        ihave = 6;
      }
      else
      {
        iterm = 1;
      }
    }
//
//  Digit.
//
    else if ( ihave < 11 && '0' <= c && c <= '9' )
    {
      if ( ihave <= 2 )
      {
        ihave = 3;
      }
      else if ( ihave == 4 )
      {
        ihave = 5;
      }
      else if ( ihave == 6 || ihave == 7 )
      {
        ihave = 8;
      }
      else if ( ihave == 9 )
      {
        ihave = 10;
      }

      ndig = ch_to_digit ( c );

      if ( ihave == 3 )
      {
        rtop = 10.0 * rtop + ( double ) ndig;
      }
      else if ( ihave == 5 )
      {
        rtop = 10.0 * rtop + ( double ) ndig;
        rbot = 10.0 * rbot;
      }
      else if ( ihave == 8 )
      {
        jtop = 10 * jtop + ndig;
      }
      else if ( ihave == 10 )
      {
        jtop = 10 * jtop + ndig;
        jbot = 10 * jbot;
      }

    }
//
//  Anything else is regarded as a terminator.
//
    else
    {
      iterm = 1;
    }
//
//  If we haven't seen a terminator, and we haven't examined the
//  entire string, go get the next character.
//
    if ( iterm == 1 || nchar <= *lchar + 1 )
    {
      break;
    }

  }
//
//  If we haven't seen a terminator, and we have examined the
//  entire string, then we're done, and LCHAR is equal to NCHAR.
//
  if ( iterm != 1 && (*lchar) + 1 == nchar )
  {
    *lchar = nchar;
  }
//
//  Number seems to have terminated.  Have we got a legal number?
//  Not if we terminated in states 1, 2, 6 or 7!
//
  if ( ihave == 1 || ihave == 2 || ihave == 6 || ihave == 7 )
  {
    *error = true;
    return r;
  }
//
//  Number seems OK.  Form it.
//
  if ( jtop == 0 )
  {
    rexp = 1.0;
  }
  else
  {
    if ( jbot == 1 )
    {
      rexp = pow ( 10.0, jsgn * jtop );
    }
    else
    {
      rexp = jsgn * jtop;
      rexp = rexp / jbot;
      rexp = pow ( 10.0, rexp );
    }

  }

  r = isgn * rexp * rtop / rbot;

  return r;
}
//****************************************************************************80

bool s_to_r8vec ( string s, int n, double rvec[] )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_R8VEC reads an R8VEC from a string.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string S, the string to be read.
//
//    Input, int N, the number of values expected.
//
//    Output, double RVEC[N], the values read from the string.
//
//    Output, bool S_TO_R8VEC, is true if an error occurred.
//
{
  int begin;
  bool error;
  int i;
  int lchar;
  int length;

  begin = 0;
  length = s.length ( );
  error = 0;

  for ( i = 0; i < n; i++ )
  {
    rvec[i] = s_to_r8 ( s.substr(begin,length), &lchar, &error );

    if ( error )
    {
      return error;
    }
    begin = begin + lchar;
    length = length - lchar;
  }

  return error;
}
//****************************************************************************80

int s_word_count ( string s )

//****************************************************************************80
//
//  Purpose:
//
//    S_WORD_COUNT counts the number of "words" in a string.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    05 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string S, the string to be examined.
//
//    Output, int S_WORD_COUNT, the number of "words" in the string.
//    Words are presumed to be separated by one or more blanks.
//
{
  bool blank;
  int char_count;
  int i;
  int word_count;

  word_count = 0;
  blank = true;

  char_count = s.length ( );

  for ( i = 0; i < char_count; i++ )
  {
    if ( isspace ( s[i] ) )
    {
      blank = true;
    }
    else if ( blank )
    {
      word_count = word_count + 1;
      blank = false;
    }
  }

  return word_count;
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
# undef TIME_SIZE
}

