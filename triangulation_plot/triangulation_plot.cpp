# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <ctime>
# include <string>

using namespace std;

int main ( int argc, char *argv[] );
char ch_cap ( char ch );
bool ch_eqi ( char ch1, char ch2 );
int ch_to_digit ( char ch );
int file_column_count ( string filename );
int file_row_count ( string filename );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_modp ( int i, int j );
int i4_wrap ( int ival, int ilo, int ihi );
int *i4mat_data_read ( string input_filename, int m, int n );
void i4mat_header_read ( string input_filename, int &m, int &n );
void i4mat_transpose_print_some ( int m, int n, int a[], int ilo, int jlo, 
  int ihi, int jhi, string title );
void mesh_base_zero ( int node_num, int element_order, 
  int element_num, int element_node[] );
double r8_huge ( );
void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo, 
  int ihi, int jhi, string title );
int r8_nint ( double x );
double *r8mat_data_read ( string input_filename, int m, int n );
void r8mat_header_read ( string input_filename, int &m, int &n );
int s_len_trim ( string s );
int s_to_i4 ( string s, int *last, bool *error );
bool s_to_i4vec ( string s, int n, int ivec[] );
double s_to_r8 ( string s, int *lchar, bool *error );
bool s_to_r8vec ( string s, int n, double rvec[] );
int s_word_count ( string s );
void timestamp ( );
void triangulation_order3_plot ( string plot_filename, int node_num, 
  double node_xy[], int element_num, int element_node[], int node_show, 
  int element_show );
void triangulation_order4_plot ( string plot_filename, int node_num, 
  double node_xy[], int element_num, int element_node[], int node_show, 
  int element_show );
void triangulation_order6_plot ( string plot_filename, int node_num, 
  double node_xy[], int element_num, int element_node[], int node_show, 
  int element_show );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for TRIANGULATION_PLOT.
//
//  Discussion:
//
//    TRIANGULATION_PLOT plots a triangulated set of nodes.
//
//  Usage:
//
//    triangulation_plot prefix node_vis element_vis
//
//    where:
//
//    'prefix' is the common prefix for the node and element files:
//
//    * prefix_nodes.txt,     the node coordinates.
//    * prefix_elements.txt,  the nodes that make up each element.
//    * prefix.eps, the plot of the triangulation (output).
//
//    'node_vis' indicates the node visibility:
//
//    0: do not show the nodes;
//    1:        show the nodes;
//    2:        show the nodes, and label them.
//
//    'element_vis' indicates the element visibility:
//
//    0: do not show the elements;
//    1:        show the elements;
//    2:        show the elements, and label them.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    04 October 2009
//
//  Author:
//
//    John Burkardt
//
{
  int dim_num;
  string element_filename;
  int *element_node;
  int element_num;
  int element_order;
  int element_show;
  string node_filename;
  int node_num;
  int node_show;
  double *node_xy;
  string plot_filename;
  string prefix;

  timestamp ( );
  cout << "\n";
  cout << "TRIANGULATION_PLOT\n";
  cout << "  C++ version:\n";
  cout << "  Read a node dataset of NODE_NUM points in 2 dimensions.\n";
  cout << "  Read an associated triangulation dataset of \n";
  cout << "  ELEMENT_NUM element in a triangulation of order\n";
  cout << "  ELEMENT_ORDER = 3, 4, or 6 .\n";
  cout << "\n";
  cout << "  Make an EPS plot of the triangulated data.\n";
  cout << "\n";
  cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << ".\n";
//
//  Get the filename prefix.
//
  if ( argc <= 1 ) 
  {
    cout << "\n";
    cout << "TRIANGULATION_PLOT:\n";
    cout << "  Please enter the filename prefix.\n";

    cin >> prefix;
  }
  else 
  {
    prefix = argv[1];
  } 
//
//  Get the node visibility.
//
  if ( argc <= 2 ) 
  {
    cout << "\n";
    cout << "  Enter the option for showing the nodes:\n";
    cout << "  0: do not show the nodes;\n";
    cout << "  1:        show the nodes;\n";
    cout << "  2:        show the nodes, and label them.\n";
    cin >> node_show;
  }
  else 
  {
    node_show = atoi ( argv[2] );
  } 
//
//  Get the element visibility.
//
  if ( argc <= 3 ) 
  {
    cout << "\n";
    cout << "  Enter the option for showing the elements:\n";
    cout << "  0: do not show the elements;\n";
    cout << "  1:        show the elements;\n";
    cout << "  2:        show the elements, and label them.\n";
    cin >> element_show;
  }
  else 
  {
    element_show = atoi ( argv[3] );
  }
//
//  Create the filenames.
//
  node_filename = prefix + "_nodes.txt";
  element_filename = prefix + "_elements.txt";
  plot_filename = prefix + ".eps";
//
//  Read the node data.
//
  r8mat_header_read ( node_filename, dim_num, node_num );

  cout << "\n";
  cout << "  Read the header of \"" << node_filename << "\".\n";
  cout << "\n";
  cout << "  Spatial dimension DIM_NUM = " << dim_num << "\n";
  cout << "  Number of nodes NODE_NUM  = " << node_num << "\n";

  node_xy = r8mat_data_read ( node_filename, dim_num, node_num );

  cout << "\n";
  cout << "  Read the data in \"" << node_filename << "\".\n";

  r8mat_transpose_print_some ( dim_num, node_num, node_xy, 1, 1, 5, 5, 
    "  5 by 5 portion of data read from file:" );
//
//  Read the element data.
//
  i4mat_header_read ( element_filename, element_order, element_num );

  cout << "\n";
  cout << " Read the header of \"" << element_filename << "\".\n";
  cout << "\n";
  cout << "  Element order ELEMENT_ORDER = " << element_order << "\n";
  cout << "  Number of elements ELEMENT_NUM  = " << element_num << "\n";

  element_node = i4mat_data_read ( element_filename, 
    element_order, element_num );

  cout << "\n";
  cout << "  Read the data in \"" << element_filename << "\".\n";

  i4mat_transpose_print_some ( element_order, element_num, element_node, 
    1, 1, 5, 5, "  5 by 5 portion of data read from file:" );
//
//  Detect and correct 1-based node indexing.
//
  mesh_base_zero ( node_num, element_order, element_num, element_node );
//
//  Create the output file.
//
  if ( element_order == 3 )
  {
    triangulation_order3_plot ( plot_filename, node_num, node_xy, 
      element_num, element_node, node_show, element_show );
  }
  else if ( element_order == 4 )
  {
    triangulation_order4_plot ( plot_filename, node_num, node_xy, 
      element_num, element_node, node_show, element_show );
  }
  else if ( element_order == 6 )
  {
    triangulation_order6_plot ( plot_filename, node_num, node_xy, 
      element_num, element_node, node_show, element_show );
  }

  cout << "\n";
  cout << "  Created the EPS file \"" << plot_filename << "\".\n";
//
//  Free memory.
//
  delete [] node_xy;
  delete [] element_node;
//
//  Terminate.
//
  cout << "\n";
  cout << "TRIANGULATION_PLOT:\n";
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
//    CH_TO_DIGIT returns the integer value of a base 10 digit.
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
//    Output, int CH_TO_DIGIT, the corresponding integer value.  If the
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
//    Most lines of the file are presumed to consist of COLUMN_NUM words, separated
//    by spaces.  There may also be some blank lines, and some comment lines,
//    which have a "#" in column 1.
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
//    30 January 2009
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
  char text[255];
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
    input.getline ( text, sizeof ( text ) );

    if ( input.eof ( ) )
    {
      break;
    }

    if ( s_len_trim ( text ) == 0 )
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
      input.getline ( text, sizeof ( text ) );

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

int file_row_count ( string filename )

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
//    30 January 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string FILENAME, the name of the input file.
//
//    Output, int FILE_ROW_COUNT, the number of rows found.
//
{
  int comment_num;
  ifstream input;
  int record_num;
  int row_num;
  char text[255];

  row_num = 0;
  comment_num = 0;
  record_num = 0;

  input.open ( filename.c_str ( ) );

  if ( !input )
  {
    cerr << "\n";
    cerr << "FILE_ROW_COUNT - Fatal error!\n";
    cerr << "  Could not open the file: \"" << filename << "\"\n";
    exit ( 1 );
  }

  for ( ; ; )
  {
    input.getline ( text, sizeof ( text ) );

    if ( input.eof ( ) )
    {
      break;
    }

    record_num = record_num + 1;

    if ( text[0] == '#' )
    {
      comment_num = comment_num + 1;
      continue;
    }

    if ( s_len_trim ( text ) == 0 )
    {
      comment_num = comment_num + 1;
      continue;
    }

    row_num = row_num + 1;

  }

  input.close ( );

  return row_num;
}
//****************************************************************************

int i4_max ( int i1, int i2 )

//****************************************************************************
//
//  Purpose:
//
//    I4_MAX returns the maximum of two integers.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, are two integers to be compared.
//
//    Output, int I4_MAX, the larger of I1 and I2.
//
{
  int value;

  if ( i2 < i1 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
//****************************************************************************

int i4_min ( int i1, int i2 )

//****************************************************************************
//
//  Purpose:
//
//    I4_MIN returns the smaller of two integers.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    13 October 1998
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I1, I2, two integers to be compared.
//
//    Output, int I4_MIN, the smaller of I1 and I2.
//
{
  int value;

  if ( i1 < i2 )
  {
    value = i1;
  }
  else
  {
    value = i2;
  }
  return value;
}
//*********************************************************************

int i4_modp ( int i, int j )

//*********************************************************************
//
//  Purpose:
//
//    I4_MODP returns the nonnegative remainder of integer division.
//
//  Discussion:
//
//    If 
//      NREM = I4_MODP ( I, J ) 
//      NMULT = ( I - NREM ) / J
//    then
//      I = J * NMULT + NREM
//    where NREM is always nonnegative.
//
//    The MOD function computes a result with the same sign as the
//    quantity being divided.  Thus, suppose you had an angle A,
//    and you wanted to ensure that it was between 0 and 360.
//    Then mod(A,360) would do, if A was positive, but if A
//    was negative, your result would be between -360 and 0.
//
//    On the other hand, I4_MODP(A,360) is between 0 and 360, always.
//
//  Example:
//
//        I         J     MOD  I4_MODP   I4_MODP Factorization
// 
//      107        50       7       7    107 =  2 *  50 + 7
//      107       -50       7       7    107 = -2 * -50 + 7
//     -107        50      -7      43   -107 = -3 *  50 + 43
//     -107       -50      -7      43   -107 =  3 * -50 + 43
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 May 1999
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int I, the number to be divided.
//
//    Input, int J, the number that divides I.
//
//    Output, int I4_MODP, the nonnegative remainder when I is 
//    divided by J.
//
{
  int value;

  if ( j == 0 )
  {
    cout << "\n";
    cout << "I4_MODP - Fatal error!\n";
    cout << "  I4_MODP ( I, J ) called with J = " << j << "\n";
    exit ( 1 );
  }

  value = i % j;

  if ( value < 0 )
  {
    value = value + abs ( j );
  }

  return value;
}
//****************************************************************************80*

int i4_wrap ( int ival, int ilo, int ihi )

//****************************************************************************80*
//
//  Purpose:
//
//    I4_WRAP forces an integer to lie between given limits by wrapping.
//
//  Example:
//
//    ILO = 4, IHI = 8
//
//    I  I4_WRAP
//
//    -2     8
//    -1     4
//     0     5
//     1     6
//     2     7
//     3     8
//     4     4
//     5     5
//     6     6
//     7     7
//     8     8
//     9     4
//    10     5
//    11     6
//    12     7
//    13     8
//    14     4
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 August 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int IVAL, an integer value.
//
//    Input, int ILO, IHI, the desired bounds for the integer value.
//
//    Output, int I4_WRAP, a "wrapped" version of IVAL.
//
{
  int jhi;
  int jlo;
  int value;
  int wide;

  jlo = i4_min ( ilo, ihi );
  jhi = i4_max ( ilo, ihi );

  wide = jhi + 1 - jlo;

  if ( wide == 1 )
  {
    value = jlo;
  }
  else
  {
    value = jlo + i4_modp ( ival - jlo, wide );
  }

  return value;
}
//****************************************************************************80

int *i4mat_data_read ( string input_filename, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_DATA_READ reads data from an I4MAT file.
//
//  Discussion:
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
//    Output, int I4MAT_DATA_READ[M*N], the table data.
//
{
  bool error;
  ifstream input;
  int i;
  int j;
  string line;
  int *table;
  int *x;

  input.open ( input_filename.c_str ( ) );

  if ( !input )
  {
    cerr << "\n";
    cerr << "I4MAT_DATA_READ - Fatal error!\n";
    cerr << "  Could not open the input file: \"" << input_filename << "\"\n";
    return NULL;
  }

  table = new int[m*n];

  x = new int[m];

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

    error = s_to_i4vec ( line, m, x );

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

void i4mat_header_read ( string input_filename, int &m, int &n )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_HEADER_READ reads the header from an I4MAT file.
//
//  Discussion:
//
//    An I4MAT is an array of I4's.
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
//    Output, int &M, the number of spatial dimensions.
//
//    Output, int &N, the number of points
//
{
  m = file_column_count ( input_filename );

  if ( m <= 0 )
  {
    cerr << "\n";
    cerr << "I4MAT_HEADER_READ - Fatal error!\n";
    cerr << "  FILE_COLUMN_COUNT failed.\n";
    exit ( 1 );
  }

  n = file_row_count ( input_filename );

  if ( n <= 0 )
  {
    cerr << "\n";
    cerr << "I4MAT_HEADER_READ - Fatal error!\n";
    cerr << "  FILE_ROW_COUNT failed.\n";
    exit ( 1 );
  }

  return;
}
//****************************************************************************80

void i4mat_transpose_print_some ( int m, int n, int a[], int ilo, int jlo, 
  int ihi, int jhi, string title )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_TRANSPOSE_PRINT_SOME prints some of an I4MAT, transposed.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 June 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows of the matrix.
//    M must be positive.
//
//    Input, int N, the number of columns of the matrix.
//    N must be positive.
//
//    Input, int A[M*N], the matrix.
//
//    Input, int ILO, JLO, IHI, JHI, designate the first row and
//    column, and the last row and column to be printed.
//
//    Input, string TITLE, a title for the matrix.
//
{
# define INCX 10

  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  if ( 0 < s_len_trim ( title ) )
  {
    cout << "\n";
    cout << title << "\n";
  }
//
//  Print the columns of the matrix, in strips of INCX.
//
  for ( i2lo = ilo; i2lo <= ihi; i2lo = i2lo + INCX )
  {
    i2hi = i2lo + INCX - 1;
    i2hi = i4_min ( i2hi, m );
    i2hi = i4_min ( i2hi, ihi );

    cout << "\n";
//
//  For each row I in the current range...
//
//  Write the header.
//
    cout << "  Row: ";
    for ( i = i2lo; i <= i2hi; i++ )
    {
      cout << setw(6) << i << "  ";
    }
    cout << "\n";
    cout << "  Col\n";
    cout << "\n";
//
//  Determine the range of the rows in this strip.
//
    j2lo = i4_max ( jlo, 1 );
    j2hi = i4_min ( jhi, n );

    for ( j = j2lo; j <= j2hi; j++ )
    {
//
//  Print out (up to INCX) entries in column J, that lie in the current strip.
//
      cout << setw(5) << j << "  ";
      for ( i = i2lo; i <= i2hi; i++ )
      {
        cout << setw(6) << a[i-1+(j-1)*m] << "  ";
      }
      cout << "\n";
    }
  }

  return;
# undef INCX
}
//****************************************************************************80

void mesh_base_zero ( int node_num, int element_order, int element_num, 
  int element_node[] )

//****************************************************************************80
//
//  Purpose:
//
//    MESH_BASE_ZERO ensures that the element definition is zero-based.
//
//  Discussion:
//
//    The ELEMENT_NODE array contains nodes indices that form elements.
//    The convention for node indexing might start at 0 or at 1.
//    Since a C++ program will naturally assume a 0-based indexing, it is
//    necessary to check a given element definition and, if it is actually
//    1-based, to convert it.
//
//    This function attempts to detect 1-based node indexing and correct it.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    02 October 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NODE_NUM, the number of nodes.
//
//    Input, int ELEMENT_ORDER, the order of the elements.
//
//    Input, int ELEMENT_NUM, the number of elements.
//
//    Input/output, int ELEMENT_NODE[ELEMENT_ORDER*ELEMENT_NUM], the element
//    definitions.
//
{
  int element;
  int node;
  int node_max;
  int node_min;
  int order;

  node_min = node_num + 1;
  node_max = -1;
  for ( element = 0; element < element_num; element++ )
  {
    for ( order = 0; order < element_order; order++ )
    {
      node = element_node[order+element*element_order];
      node_min = i4_min ( node_min, node );
      node_max = i4_max ( node_max, node );
    }
  }

  if ( node_min == 1 && node_max == node_num )
  {
    cout << "\n";
    cout << "MESH_BASE_ZERO:\n";
    cout << "  The element indexing appears to be 1-based!\n";
    cout << "  This will be converted to 0-based.\n";
    for ( element = 0; element < element_num; element++ )
    {
      for ( order = 0; order < element_order; order++ )
      {
        element_node[order+element*element_order] =
          element_node[order+element*element_order] - 1;
      }
    }
  }
  else if ( node_min == 0 && node_max == node_num - 1 )
  {
    cout << "\n";
    cout << "MESH_BASE_ZERO:\n";
    cout << "  The element indexing appears to be 0-based!\n";
    cout << "  No conversion is necessary.\n";
  }
  else
  {
    cout << "\n";
    cout << "MESH_BASE_ZERO - Warning!\n";
    cout << "  The element indexing is not of a recognized type.\n";
    cout << "  NODE_MIN = " << node_min << "\n";
    cout << "  NODE_MAX = " << node_max << "\n";
    cout << "  NODE_NUM = " << node_num << "\n";
  }
  return;
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

int r8_nint ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_NINT returns the nearest integer to an R8.
//
//  Example:
//
//        X         Value
//
//      1.3         1
//      1.4         1
//      1.5         1 or 2
//      1.6         2
//      0.0         0
//     -0.7        -1
//     -1.1        -1
//     -1.6        -2
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, the value.
//
//    Output, int R8_NINT, the nearest integer to X.
//
{
  int s;
  int value;

  if ( x < 0.0 )
  {
    s = -1;
  }
  else
  {
    s = 1;
  }
  value = s * ( int ) ( fabs ( x ) + 0.5 );

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

void r8mat_header_read ( string input_filename, int &m, int &n )

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
//    Output, int &M, the number of spatial dimensions.
//
//    Output, int &N, the number of points.
//
{
  m = file_column_count ( input_filename );

  if ( m <= 0 )
  {
    cerr << "\n";
    cerr << "R8MAT_HEADER_READ - Fatal error!\n";
    cerr << "  FILE_COLUMN_COUNT failed.\n";
    exit ( 1 );
  }

  n = file_row_count ( input_filename );

  if ( n <= 0 )
  {
    cerr << "\n";
    cerr << "R8MAT_HEADER_READ - Fatal error!\n";
    cerr << "  FILE_ROW_COUNT failed.\n";
    exit ( 1 );
  }

  return;
}
//****************************************************************************80

void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo, 
  int ihi, int jhi, string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_TRANSPOSE_PRINT_SOME prints some of an R8MAT, transposed.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values,  stored as a vector 
//    in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, double A[M*N], an M by N matrix to be printed.
//
//    Input, int ILO, JLO, the first row and column to print.
//
//    Input, int IHI, JHI, the last row and column to print.
//
//    Input, string TITLE, an optional title.
//
{
# define INCX 5

  int i;
  int i2;
  int i2hi;
  int i2lo;
  int inc;
  int j;
  int j2hi;
  int j2lo;

  if ( 0 < s_len_trim ( title ) )
  {
    cout << "\n";
    cout << title << "\n";
  }

  for ( i2lo = i4_max ( ilo, 1 ); i2lo <= i4_min ( ihi, m ); i2lo = i2lo + INCX )
  {
    i2hi = i2lo + INCX - 1;
    i2hi = i4_min ( i2hi, m );
    i2hi = i4_min ( i2hi, ihi );

    inc = i2hi + 1 - i2lo;

    cout << "\n";
    cout << "  Row: ";
    for ( i = i2lo; i <= i2hi; i++ )
    {
      cout << setw(7) << i << "       ";
    }
    cout << "\n";
    cout << "  Col\n";
    cout << "\n";

    j2lo = i4_max ( jlo, 1 );
    j2hi = i4_min ( jhi, n );

    for ( j = j2lo; j <= j2hi; j++ )
    {
      cout << setw(5) << j << " ";
      for ( i2 = 1; i2 <= inc; i2++ )
      {
        i = i2lo - 1 + i2;
        cout << setw(14) << a[(i-1)+(j-1)*m];
      }
      cout << "\n";
    }
  }

  return;
# undef INCX
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

bool s_to_i4vec ( string s, int n, int ivec[] )

//****************************************************************************80
//
//  Purpose:
//
//    S_TO_I4VEC reads an I4VEC from a string.
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
//    Output, int IVEC[N], the values read from the string.
//
//    Output, bool S_TO_I4VEC, is TRUE if an error occurred.
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
    ivec[i] = s_to_i4 ( s.substr(begin,length), &lchar, &error );

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
//    24 September 2003
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
  const struct tm *tm;
  time_t now;

  now = time ( NULL );
  tm = localtime ( &now );

  strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm );

  cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
//****************************************************************************80

void triangulation_order3_plot ( string plot_filename, int node_num, 
  double node_xy[], int element_num, int element_node[], int node_show, 
  int element_show )

//****************************************************************************80
//
//  Purpose:
//
//    TRIANGULATION_ORDER3_PLOT plots a 3-node triangulation.
//
//  Discussion:
//
//    The triangulation is most usually a Delaunay triangulation,
//    but this is not necessary.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string PLOT_FILENAME, the name of the output file.
//
//    Input, int NODE_NUM, the number of nodes.
//
//    Input, double NODE_XY[2*NODE_NUM], the coordinates of the nodes.
//
//    Input, int ELEMENT_NUM, the number of elements.
//
//    Input, int ELEMENT_NODE[3*ELEMENT_NUM], lists, for each element,
//    the indices of the nodes that form the vertices of the element.
//
//    Input, int NODE_SHOW:
//    0, do not show nodes;
//    1, show nodes;
//    2, show nodes and label them.
//
//    Input, int ELEMENT_SHOW:
//    0, do not show elements;
//    1, show elements;
//    2, show elements and label them.
//
{
  double ave_x;
  double ave_y;
  int circle_size;
  int delta;
  int e;
  ofstream plot_unit;
  int i;
  int node;
  int element;
  double x_max;
  double x_min;
  int x_ps;
  int x_ps_max = 576;
  int x_ps_max_clip = 594;
  int x_ps_min = 36;
  int x_ps_min_clip = 18;
  double x_scale;
  double y_max;
  double y_min;
  int y_ps;
  int y_ps_max = 666;
  int y_ps_max_clip = 684;
  int y_ps_min = 126;
  int y_ps_min_clip = 108;
  double y_scale;
//
//  We need to do some figuring here, so that we can determine
//  the range of the data, and hence the height and width
//  of the piece of paper.
//
  x_max = -r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( x_max < node_xy[0+node*2] )
     {
       x_max = node_xy[0+node*2];
     }
  }
  x_min = r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( node_xy[0+node*2] < x_min )
     {
       x_min = node_xy[0+node*2];
     }
  }
  x_scale = x_max - x_min;

  x_max = x_max + 0.05 * x_scale;
  x_min = x_min - 0.05 * x_scale;
  x_scale = x_max - x_min;

  y_max = -r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( y_max < node_xy[1+node*2] )
     {
       y_max = node_xy[1+node*2];
     }
  }
  y_min = r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( node_xy[1+node*2] < y_min )
     {
       y_min = node_xy[1+node*2];
     }
  }
  y_scale = y_max - y_min;

  y_max = y_max + 0.05 * y_scale;
  y_min = y_min - 0.05 * y_scale;
  y_scale = y_max - y_min;

  if ( x_scale < y_scale )
  {
    delta = r8_nint ( ( double ) ( x_ps_max - x_ps_min )
      * ( y_scale - x_scale ) / ( 2.0 * y_scale ) );

    x_ps_max = x_ps_max - delta;
    x_ps_min = x_ps_min + delta;

    x_ps_max_clip = x_ps_max_clip - delta;
    x_ps_min_clip = x_ps_min_clip + delta;

    x_scale = y_scale;
  }
  else if ( y_scale < x_scale )
  {
    delta = r8_nint ( ( double ) ( y_ps_max - y_ps_min ) 
      * ( x_scale - y_scale ) / ( 2.0 * x_scale ) );

    y_ps_max = y_ps_max - delta;
    y_ps_min = y_ps_min + delta;

    y_ps_max_clip = y_ps_max_clip - delta;
    y_ps_min_clip = y_ps_min_clip + delta;

    y_scale = x_scale;
  }

  plot_unit.open ( plot_filename.c_str ( ) );

  if ( !plot_unit )
  {
    cout << "\n";
    cout << "TRIANGULATION_ORDER3_PLOT - Fatal error!\n";
    cout << "  Could not open the output EPS file.\n";
    exit ( 1 );
  }

  plot_unit << "%!PS-Adobe-3.0 EPSF-3.0\n";
  plot_unit << "%%Creator: triangulation_order3_plot.C\n";
  plot_unit << "%%Title: " << plot_filename << "\n";
  plot_unit << "%%Pages: 1\n";
  plot_unit << "%%BoundingBox:  "
    << x_ps_min << "  "
    << y_ps_min << "  "
    << x_ps_max << "  "
    << y_ps_max << "\n";
  plot_unit << "%%Document-Fonts: Times-Roman\n";
  plot_unit << "%%LanguageLevel: 1\n";
  plot_unit << "%%EndComments\n";
  plot_unit << "%%BeginProlog\n";
  plot_unit << "/inch {72 mul} def\n";
  plot_unit << "%%EndProlog\n";
  plot_unit << "%%Page:      1     1\n";
  plot_unit << "save\n";
  plot_unit << "%\n";
  plot_unit << "%  Increase line width from default 0.\n";
  plot_unit << "%\n";
  plot_unit << "2 setlinewidth\n";
  plot_unit << "%\n";
  plot_unit << "% Set the RGB line color to very light gray.\n";
  plot_unit << "%\n";
  plot_unit << " 0.9000 0.9000 0.9000 setrgbcolor\n";
  plot_unit << "%\n";
  plot_unit << "% Draw a gray border around the page.\n";
  plot_unit << "%\n";
  plot_unit << "newpath\n";
  plot_unit << x_ps_min << "  "
            << y_ps_min << "  moveto\n";
  plot_unit << x_ps_max << "  "
            << y_ps_min << "  lineto\n";
  plot_unit << x_ps_max << "  "
            << y_ps_max << "  lineto\n";
  plot_unit << x_ps_min << "  "
            << y_ps_max << "  lineto\n";
  plot_unit << x_ps_min << "  "
            << y_ps_min << "  lineto\n";
  plot_unit << "stroke\n";
  plot_unit << "%\n";
  plot_unit << "% Set RGB line color to black.\n";
  plot_unit << "%\n";
  plot_unit << " 0.0000 0.0000 0.0000 setrgbcolor\n";
  plot_unit << "%\n";
  plot_unit << "%  Set the font and its size:\n";
  plot_unit << "%\n";
  plot_unit << "/Times-Roman findfont\n";
  plot_unit << "0.50 inch scalefont\n";
  plot_unit << "setfont\n";
  plot_unit << "%\n";
  plot_unit << "%  Print a title:\n";
  plot_unit << "%\n";
  plot_unit << "%  210  702 moveto\n";
  plot_unit << "%(Pointset) show\n";
  plot_unit << "%\n";
  plot_unit << "% Define a clipping polygon\n";
  plot_unit << "%\n";
  plot_unit << "newpath\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_min_clip << "  moveto\n";
  plot_unit << x_ps_max_clip << "  "
            << y_ps_min_clip << "  lineto\n";
  plot_unit << x_ps_max_clip << "  "
            << y_ps_max_clip << "  lineto\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_max_clip << "  lineto\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_min_clip << "  lineto\n";
  plot_unit << "clip newpath\n";
//
//  Draw the nodes.
//
  if ( node_num <= 200 )
  {
    circle_size = 5;
  }
  else if ( node_num <= 500 )
  {
    circle_size = 4;
  }
  else if ( node_num <= 1000 )
  {
    circle_size = 3;
  }
  else if ( node_num <= 5000 )
  {
    circle_size = 2;
  }
  else
  {
    circle_size = 1;
  }

  if ( 1 <= node_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Draw filled dots at each node:\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the color to blue:\n";
    plot_unit << "%\n";
    plot_unit << "0.000  0.150  0.750  setrgbcolor\n";
    plot_unit << "%\n";

    for ( node = 0; node < node_num; node++ )
    {
      x_ps = ( int ) (
        ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
        + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max                     - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
        + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max                     - y_min ) );

      plot_unit << "newpath  " 
        << x_ps << "  " 
        << y_ps << "  "
        << circle_size << " 0 360 arc closepath fill\n";
    }
  }
//
//  Label the nodes.
//
  if ( 2 <= node_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Label the nodes:\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the color to darker blue:\n";
    plot_unit << "%\n";
    plot_unit << "0.000  0.250  0.850  setrgbcolor\n";
    plot_unit << "/Times-Roman findfont\n";
    plot_unit << "0.20 inch scalefont\n";
    plot_unit << "setfont\n";

    plot_unit << "%\n";

    for ( node = 0; node < node_num; node++ )
    { 
      x_ps = ( int ) (
        ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
        + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max                     - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
        + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max                     - y_min ) );

      plot_unit << "newpath  " 
        << x_ps     << "  " 
        << y_ps + 5 << "  moveto ("
        << node+1   << ") show\n";
    }
  }
//
//  Draw the elements.
//
  if ( 1 <= element_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Set the RGB color to red.\n";
    plot_unit << "%\n";
    plot_unit << "0.900  0.200  0.100 setrgbcolor\n";
    plot_unit << "%\n";
    plot_unit << "%  Draw the elements.\n";
    plot_unit << "%\n";

    for ( element = 0; element < element_num; element++ )
    {
      plot_unit << "newpath\n";

      for ( i = 0; i <= 3; i++ )
      {
        e = i4_wrap ( i, 0, 2 );

        node = element_node[e+element*3];

        x_ps = ( int ) (
          ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
          + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
          / ( x_max                     - x_min ) );

        y_ps = ( int ) (
          ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
          + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
          / ( y_max                     - y_min ) );

        if ( i == 0 )
        {
          plot_unit << x_ps << "  " << y_ps << "  moveto\n";
        } 
        else
        {
          plot_unit << x_ps << "  " << y_ps << "  lineto\n";
        }
      }
      plot_unit << "stroke\n";
    }
  }
//
//  Label the elements.
//
  if ( 2 <= element_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Label the elements.\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the RGB color to darker red.\n";
    plot_unit << "%\n";
    plot_unit << "0.950  0.250  0.150 setrgbcolor\n";
    plot_unit << "/Times-Roman findfont\n";
    plot_unit << "0.20 inch scalefont\n";
    plot_unit << "setfont\n";
    plot_unit << "%\n";

    for ( element = 0; element < element_num; element++ )
    {
      ave_x = 0.0;
      ave_y = 0.0;

      for ( i = 0; i < 3; i++ )
      {
        node = element_node[i+element*3];
        ave_x = ave_x + node_xy[0+node*2];
        ave_y = ave_y + node_xy[1+node*2];
      }
      ave_x = ave_x / 3.0;
      ave_y = ave_y / 3.0;

      x_ps = ( int ) (
        ( ( x_max - ave_x         ) * ( double ) ( x_ps_min )  
        + (       + ave_x - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max         - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - ave_y         ) * ( double ) ( y_ps_min )  
        + (         ave_y - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max         - y_min ) );

      plot_unit << x_ps << "  " 
                << y_ps << "  moveto ("
                << element << ") show\n";
    }
  }

  plot_unit << "%\n";
  plot_unit << "restore  showpage\n";
  plot_unit << "%\n";
  plot_unit << "%  End of page.\n";
  plot_unit << "%\n";
  plot_unit << "%%Trailer\n";
  plot_unit << "%%EOF\n";

  plot_unit.close ( );

  return;
}
//****************************************************************************80

void triangulation_order4_plot ( string plot_filename, int node_num, 
  double node_xy[], int element_num, int element_node[], int node_show, 
  int element_show )

//****************************************************************************80
//
//  Purpose:
//
//    TRIANGULATION_ORDER4_PLOT plots a 4-node triangulation.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string PLOT_FILENAME, the name of the output file.
//
//    Input, int NODE_NUM, the number of nodes.
//
//    Input, double NODE_XY[2*NODE_NUM], the coordinates of the nodes.
//
//    Input, int ELEMENT_NUM, the number of elements.
//
//    Input, int ELEMENT_NODE[4*ELEMENT_NUM], lists, for each element,
//    the indices of the nodes that form the vertices of the element,
//    and the centroid.
//
//    Input, int NODE_SHOW:
//    0, do not show nodes;
//    1, show nodes;
//    2, show nodes and label them.
//
//    Input, int TRIANGLE_SHOW:
//    0, do not show elements;
//    1, show elements;
//    2, show elements and label them.
//
{
  double ave_x;
  double ave_y;
  int circle_size;
  int delta;
  int e;
  ofstream plot_unit;
  int i;
  int node;
  int element;
  double x_max;
  double x_min;
  int x_ps;
  int x_ps_max = 576;
  int x_ps_max_clip = 594;
  int x_ps_min = 36;
  int x_ps_min_clip = 18;
  double x_scale;
  double y_max;
  double y_min;
  int y_ps;
  int y_ps_max = 666;
  int y_ps_max_clip = 684;
  int y_ps_min = 126;
  int y_ps_min_clip = 108;
  double y_scale;
//
//  We need to do some figuring here, so that we can determine
//  the range of the data, and hence the height and width
//  of the piece of paper.
//
  x_max = -r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( x_max < node_xy[0+node*2] )
     {
       x_max = node_xy[0+node*2];
     }
  }
  x_min = r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( node_xy[0+node*2] < x_min )
     {
       x_min = node_xy[0+node*2];
     }
  }
  x_scale = x_max - x_min;

  x_max = x_max + 0.05 * x_scale;
  x_min = x_min - 0.05 * x_scale;
  x_scale = x_max - x_min;

  y_max = -r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( y_max < node_xy[1+node*2] )
     {
       y_max = node_xy[1+node*2];
     }
  }
  y_min = r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( node_xy[1+node*2] < y_min )
     {
       y_min = node_xy[1+node*2];
     }
  }
  y_scale = y_max - y_min;

  y_max = y_max + 0.05 * y_scale;
  y_min = y_min - 0.05 * y_scale;
  y_scale = y_max - y_min;

  if ( x_scale < y_scale )
  {
    delta = r8_nint ( ( double ) ( x_ps_max - x_ps_min )
      * ( y_scale - x_scale ) / ( 2.0 * y_scale ) );

    x_ps_max = x_ps_max - delta;
    x_ps_min = x_ps_min + delta;

    x_ps_max_clip = x_ps_max_clip - delta;
    x_ps_min_clip = x_ps_min_clip + delta;

    x_scale = y_scale;
  }
  else if ( y_scale < x_scale )
  {
    delta = r8_nint ( ( double ) ( y_ps_max - y_ps_min ) 
      * ( x_scale - y_scale ) / ( 2.0 * x_scale ) );

    y_ps_max = y_ps_max - delta;
    y_ps_min = y_ps_min + delta;

    y_ps_max_clip = y_ps_max_clip - delta;
    y_ps_min_clip = y_ps_min_clip + delta;

    y_scale = x_scale;
  }

  plot_unit.open ( plot_filename.c_str ( ) );

  if ( !plot_unit )
  {
    cout << "\n";
    cout << "TRIANGULATION_ORDER3_PLOT - Fatal error!\n";
    cout << "  Could not open the output EPS file.\n";
    exit ( 1 );
  }

  plot_unit << "%!PS-Adobe-3.0 EPSF-3.0\n";
  plot_unit << "%%Creator: triangulation_order4_plot.C\n";
  plot_unit << "%%Title: " << plot_filename << "\n";
  plot_unit << "%%Pages: 1\n";
  plot_unit << "%%BoundingBox:  "
    << x_ps_min << "  "
    << y_ps_min << "  "
    << x_ps_max << "  "
    << y_ps_max << "\n";
  plot_unit << "%%Document-Fonts: Times-Roman\n";
  plot_unit << "%%LanguageLevel: 1\n";
  plot_unit << "%%EndComments\n";
  plot_unit << "%%BeginProlog\n";
  plot_unit << "/inch {72 mul} def\n";
  plot_unit << "%%EndProlog\n";
  plot_unit << "%%Page:      1     1\n";
  plot_unit << "save\n";
  plot_unit << "%\n";
  plot_unit << "%  Increase line width from default 0.\n";
  plot_unit << "%\n";
  plot_unit << "2 setlinewidth\n";
  plot_unit << "%\n";
  plot_unit << "% Set the RGB line color to very light gray.\n";
  plot_unit << "%\n";
  plot_unit << " 0.9000 0.9000 0.9000 setrgbcolor\n";
  plot_unit << "%\n";
  plot_unit << "% Draw a gray border around the page.\n";
  plot_unit << "%\n";
  plot_unit << "newpath\n";
  plot_unit << x_ps_min << "  "
            << y_ps_min << "  moveto\n";
  plot_unit << x_ps_max << "  "
            << y_ps_min << "  lineto\n";
  plot_unit << x_ps_max << "  "
            << y_ps_max << "  lineto\n";
  plot_unit << x_ps_min << "  "
            << y_ps_max << "  lineto\n";
  plot_unit << x_ps_min << "  "
            << y_ps_min << "  lineto\n";
  plot_unit << "stroke\n";
  plot_unit << "%\n";
  plot_unit << "% Set RGB line color to black.\n";
  plot_unit << "%\n";
  plot_unit << " 0.0000 0.0000 0.0000 setrgbcolor\n";
  plot_unit << "%\n";
  plot_unit << "%  Set the font and its size:\n";
  plot_unit << "%\n";
  plot_unit << "/Times-Roman findfont\n";
  plot_unit << "0.50 inch scalefont\n";
  plot_unit << "setfont\n";
  plot_unit << "%\n";
  plot_unit << "%  Print a title:\n";
  plot_unit << "%\n";
  plot_unit << "%  210  702 moveto\n";
  plot_unit << "%(Pointset) show\n";
  plot_unit << "%\n";
  plot_unit << "% Define a clipping polygon\n";
  plot_unit << "%\n";
  plot_unit << "newpath\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_min_clip << "  moveto\n";
  plot_unit << x_ps_max_clip << "  "
            << y_ps_min_clip << "  lineto\n";
  plot_unit << x_ps_max_clip << "  "
            << y_ps_max_clip << "  lineto\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_max_clip << "  lineto\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_min_clip << "  lineto\n";
  plot_unit << "clip newpath\n";
//
//  Draw the nodes.
//
  if ( node_num <= 200 )
  {
    circle_size = 5;
  }
  else if ( node_num <= 500 )
  {
    circle_size = 4;
  }
  else if ( node_num <= 1000 )
  {
    circle_size = 3;
  }
  else if ( node_num <= 5000 )
  {
    circle_size = 2;
  }
  else
  {
    circle_size = 1;
  }

  if ( 1 <= node_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Draw filled dots at each node:\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the color to blue:\n";
    plot_unit << "%\n";
    plot_unit << "0.000  0.150  0.750  setrgbcolor\n";
    plot_unit << "%\n";

    for ( node = 0; node < node_num; node++ )
    {
      x_ps = ( int ) (
        ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
        + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max                     - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
        + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max                     - y_min ) );

      plot_unit << "newpath  " 
        << x_ps << "  " 
        << y_ps << "  "
        << circle_size << " 0 360 arc closepath fill\n";
    }
  }
//
//  Label the nodes.
//
  if ( 2 <= node_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Label the nodes:\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the color to darker blue:\n";
    plot_unit << "%\n";
    plot_unit << "0.000  0.250  0.850  setrgbcolor\n";
    plot_unit << "/Times-Roman findfont\n";
    plot_unit << "0.20 inch scalefont\n";
    plot_unit << "setfont\n";

    plot_unit << "%\n";

    for ( node = 0; node < node_num; node++ )
    { 
      x_ps = ( int ) (
        ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
        + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max                     - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
        + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max                     - y_min ) );

      plot_unit << "newpath  " 
        << x_ps     << "  " 
        << y_ps + 5 << "  moveto ("
        << node+1   << ") show\n";
    }
  }
//
//  Draw the elements.
//
  if ( 1 <= element_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Set the RGB color to red.\n";
    plot_unit << "%\n";
    plot_unit << "0.900  0.200  0.100 setrgbcolor\n";
    plot_unit << "%\n";
    plot_unit << "%  Draw the elements.\n";
    plot_unit << "%\n";

    for ( element = 0; element < element_num; element++ )
    {
      plot_unit << "newpath\n";

      for ( i = 0; i <= 3; i++ )
      {
        e = i4_wrap ( i, 0, 2 );

        node = element_node[e+element*4];

        x_ps = ( int ) (
          ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
          + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
          / ( x_max                     - x_min ) );

        y_ps = ( int ) (
          ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
          + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
          / ( y_max                     - y_min ) );

        if ( i == 0 )
        {
          plot_unit << x_ps << "  " << y_ps << "  moveto\n";
        } 
        else
        {
          plot_unit << x_ps << "  " << y_ps << "  lineto\n";
        }
      }
      plot_unit << "stroke\n";
    }
  }
//
//  Label the elements.
//
  if ( 2 <= element_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Label the elements.\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the RGB color to darker red.\n";
    plot_unit << "%\n";
    plot_unit << "0.950  0.250  0.150 setrgbcolor\n";
    plot_unit << "/Times-Roman findfont\n";
    plot_unit << "0.20 inch scalefont\n";
    plot_unit << "setfont\n";
    plot_unit << "%\n";

    for ( element = 0; element < element_num; element++ )
    {
      ave_x = 0.0;
      ave_y = 0.0;

      for ( i = 0; i < 3; i++ )
      {
        node = element_node[i+element*4];
        ave_x = ave_x + node_xy[0+node*2];
        ave_y = ave_y + node_xy[1+node*2];
      }
      ave_x = ave_x / 3.0;
      ave_y = ave_y / 3.0;

      x_ps = ( int ) (
        ( ( x_max - ave_x         ) * ( double ) ( x_ps_min )  
        + (       + ave_x - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max         - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - ave_y         ) * ( double ) ( y_ps_min )  
        + (         ave_y - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max         - y_min ) );

      plot_unit << x_ps << "  " 
                << y_ps << "  moveto ("
                << element+1 << ") show\n";
    }
  }

  plot_unit << "%\n";
  plot_unit << "restore  showpage\n";
  plot_unit << "%\n";
  plot_unit << "%  End of page.\n";
  plot_unit << "%\n";
  plot_unit << "%%Trailer\n";
  plot_unit << "%%EOF\n";

  plot_unit.close ( );

  return;
}
//****************************************************************************80

void triangulation_order6_plot ( string plot_filename, int node_num, 
  double node_xy[], int element_num, int element_node[], int node_show, 
  int element_show )

//****************************************************************************80
//
//  Purpose:
//
//    TRIANGULATION_ORDER6_PLOT plots a 6-node triangulation.
//
//  Discussion:
//
//    The triangulation is most usually a Delaunay triangulation,
//    but this is not necessary.
//
//    This routine has been specialized to deal correctly ONLY with
//    a mesh of 6 node elements, with the property that starting
//    from local node 1 and traversing the edges of the element will
//    result in encountering local nodes 1, 4, 2, 5, 3, 6 in that order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string PLOT_FILENAME, the name of the file to create.
//
//    Input, int NODE_NUM, the number of nodes.
//
//    Input, double NODE_XY[2*NODE_NUM], the coordinates of the nodes.
//
//    Input, int ELEMENT_NUM, the number of elements.
//
//    Input, int ELEMENT_NODE[6*ELEMENT_NUM], lists, for each element,
//    the indices of the nodes that form the vertices and midsides
//    of the element.
//
//    Input, int NODE_SHOW:
//    0, do not show nodes;
//    1, show nodes;
//    2, show nodes and label them.
//
//    Input, int ELEMENT_SHOW:
//    0, do not show element;
//    1, show elements;
//    2, show elements and label them.
//
{
  double ave_x;
  double ave_y;
  int circle_size;
  int delta;
  ofstream plot_unit;
  int i;
  int ip1;
  int node;
  int element;
  int order[6] = { 0, 3, 1, 4, 2, 5 };
  double x_max;
  double x_min;
  int x_ps;
  int x_ps_max = 576;
  int x_ps_max_clip = 594;
  int x_ps_min = 36;
  int x_ps_min_clip = 18;
  double x_scale;
  double y_max;
  double y_min;
  int y_ps;
  int y_ps_max = 666;
  int y_ps_max_clip = 684;
  int y_ps_min = 126;
  int y_ps_min_clip = 108;
  double y_scale;
//
//  We need to do some figuring here, so that we can determine
//  the range of the data, and hence the height and width
//  of the piece of paper.
//
  x_max = -r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( x_max < node_xy[0+node*2] )
     {
       x_max = node_xy[0+node*2];
     }
  }
  x_min = r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( node_xy[0+node*2] < x_min )
     {
       x_min = node_xy[0+node*2];
     }
  }
  x_scale = x_max - x_min;

  x_max = x_max + 0.05 * x_scale;
  x_min = x_min - 0.05 * x_scale;
  x_scale = x_max - x_min;

  y_max = -r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( y_max < node_xy[1+node*2] )
     {
       y_max = node_xy[1+node*2];
     }
  }
  y_min = r8_huge ( );
  for ( node = 0; node < node_num; node++ )
  {
     if ( node_xy[1+node*2] < y_min )
     {
       y_min = node_xy[1+node*2];
     }
  }
  y_scale = y_max - y_min;

  y_max = y_max + 0.05 * y_scale;
  y_min = y_min - 0.05 * y_scale;
  y_scale = y_max - y_min;

  if ( x_scale < y_scale )
  {
    delta = r8_nint ( ( double ) ( x_ps_max - x_ps_min )
      * ( y_scale - x_scale ) / ( 2.0 * y_scale ) );

    x_ps_max = x_ps_max - delta;
    x_ps_min = x_ps_min + delta;

    x_ps_max_clip = x_ps_max_clip - delta;
    x_ps_min_clip = x_ps_min_clip + delta;

    x_scale = y_scale;
  }
  else if ( y_scale < x_scale )
  {
    delta = r8_nint ( ( double ) ( y_ps_max - y_ps_min ) 
      * ( x_scale - y_scale ) / ( 2.0 * x_scale ) );

    y_ps_max = y_ps_max - delta;
    y_ps_min = y_ps_min + delta;

    y_ps_max_clip = y_ps_max_clip - delta;
    y_ps_min_clip = y_ps_min_clip + delta;

    y_scale = x_scale;
  }

  plot_unit.open ( plot_filename.c_str ( ) );

  if ( !plot_unit )
  {
    cout << "\n";
    cout << "TRIANGULATION_ORDER6_PLOT - Fatal error!\n";
    cout << "  Could not open the output EPS file.\n";
    exit ( 1 );
  }

  plot_unit << "%!PS-Adobe-3.0 EPSF-3.0\n";
  plot_unit << "%%Creator: triangulation_order6_plot.C\n";
  plot_unit << "%%Title: " << plot_filename << "\n";
  plot_unit << "%%Pages: 1\n";
  plot_unit << "%%BoundingBox:  "
    << x_ps_min << "  "
    << y_ps_min << "  "
    << x_ps_max << "  "
    << y_ps_max << "\n";
  plot_unit << "%%Document-Fonts: Times-Roman\n";
  plot_unit << "%%LanguageLevel: 1\n";
  plot_unit << "%%EndComments\n";
  plot_unit << "%%BeginProlog\n";
  plot_unit << "/inch {72 mul} def\n";
  plot_unit << "%%EndProlog\n";
  plot_unit << "%%Page:      1     1\n";
  plot_unit << "save\n";
  plot_unit << "%\n";
  plot_unit << "%  Increase line width from default 0.\n";
  plot_unit << "%\n";
  plot_unit << "2 setlinewidth\n";
  plot_unit << "%\n";
  plot_unit << "% Set the RGB line color to very light gray.\n";
  plot_unit << "%\n";
  plot_unit << " 0.9000 0.9000 0.9000 setrgbcolor\n";
  plot_unit << "%\n";
  plot_unit << "% Draw a gray border around the page.\n";
  plot_unit << "%\n";
  plot_unit << "newpath\n";
  plot_unit << x_ps_min << "  "
            << y_ps_min << "  moveto\n";
  plot_unit << x_ps_max << "  "
            << y_ps_min << "  lineto\n";
  plot_unit << x_ps_max << "  "
            << y_ps_max << "  lineto\n";
  plot_unit << x_ps_min << "  "
            << y_ps_max << "  lineto\n";
  plot_unit << x_ps_min << "  "
            << y_ps_min << "  lineto\n";
  plot_unit << "stroke\n";
  plot_unit << "%\n";
  plot_unit << "% Set RGB line color to black.\n";
  plot_unit << "%\n";
  plot_unit << " 0.0000 0.0000 0.0000 setrgbcolor\n";
  plot_unit << "%\n";
  plot_unit << "%  Set the font and its size:\n";
  plot_unit << "%\n";
  plot_unit << "/Times-Roman findfont\n";
  plot_unit << "0.50 inch scalefont\n";
  plot_unit << "setfont\n";
  plot_unit << "%\n";
  plot_unit << "%  Print a title:\n";
  plot_unit << "%\n";
  plot_unit << "%  210  702 moveto\n";
  plot_unit << "%(Pointset) show\n";
  plot_unit << "%\n";
  plot_unit << "% Define a clipping polygon\n";
  plot_unit << "%\n";
  plot_unit << "newpath\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_min_clip << "  moveto\n";
  plot_unit << x_ps_max_clip << "  "
            << y_ps_min_clip << "  lineto\n";
  plot_unit << x_ps_max_clip << "  "
            << y_ps_max_clip << "  lineto\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_max_clip << "  lineto\n";
  plot_unit << x_ps_min_clip << "  "
            << y_ps_min_clip << "  lineto\n";
  plot_unit << "clip newpath\n";
//
//  Draw the nodes.
//
  if ( node_num <= 200 )
  {
    circle_size = 5;
  }
  else if ( node_num <= 500 )
  {
    circle_size = 4;
  }
  else if ( node_num <= 1000 )
  {
    circle_size = 3;
  }
  else if ( node_num <= 5000 )
  {
    circle_size = 2;
  }
  else
  {
    circle_size = 1;
  }

  if ( 1 <= node_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Draw filled dots at each node:\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the color to blue:\n";
    plot_unit << "%\n";
    plot_unit << "0.000  0.150  0.750  setrgbcolor\n";
    plot_unit << "%\n";

    for ( node = 0; node < node_num; node++ )
    {
      x_ps = ( int ) (
        ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
        + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max                     - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
        + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max                     - y_min ) );

      plot_unit << "newpath  " 
        << x_ps << "  " 
        << y_ps << "  "
        << circle_size << " 0 360 arc closepath fill\n";
    }
  }
//
//  Label the nodes.
//
  if ( 2 <= node_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Label the nodes:\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the color to darker blue:\n";
    plot_unit << "%\n";
    plot_unit << "0.000  0.250  0.850  setrgbcolor\n";
    plot_unit << "/Times-Roman findfont\n";
    plot_unit << "0.20 inch scalefont\n";
    plot_unit << "setfont\n";

    plot_unit << "%\n";

    for ( node = 0; node < node_num; node++ )
    { 
      x_ps = ( int ) (
        ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
        + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max                     - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
        + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max                     - y_min ) );

      plot_unit << "newpath  " 
        << x_ps     << "  " 
        << y_ps + 5 << "  moveto ("
        << node+1   << ") show\n";
    }
  }
//
//  Draw the elements.
//
  if ( 1 <= element_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Set the RGB color to red.\n";
    plot_unit << "%\n";
    plot_unit << "0.900  0.200  0.100 setrgbcolor\n";
    plot_unit << "%\n";
    plot_unit << "%  Draw the elements.\n";
    plot_unit << "%\n";

    for ( element = 0; element < element_num; element++ )
    {
      ip1 = order[0];
      node = element_node[ip1+element*6];

      x_ps = ( int ) (
        ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
        + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max                     - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
        + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max                     - y_min ) );

      plot_unit << "newpath  " << x_ps << "  " << y_ps << "  moveto\n";

      for ( i = 0; i < 6; i++ )
      {
        ip1 = ( ( i + 1 ) % 6 );
        node = element_node[order[ip1]+element*6];

        x_ps = ( int ) (
          ( ( x_max - node_xy[0+node*2]         ) * ( double ) ( x_ps_min )  
          + (       + node_xy[0+node*2] - x_min ) * ( double ) ( x_ps_max ) ) 
          / ( x_max                     - x_min ) );

        y_ps = ( int ) (
          ( ( y_max - node_xy[1+node*2]         ) * ( double ) ( y_ps_min )  
          + (         node_xy[1+node*2] - y_min ) * ( double ) ( y_ps_max ) ) 
          / ( y_max                     - y_min ) );

        plot_unit << x_ps << "  " << y_ps << "  lineto\n";
      }
      plot_unit << "stroke\n";
    }
  }
//
//  Label the elements.
//
  if ( 2 <= element_show )
  {
    plot_unit << "%\n";
    plot_unit << "%  Label the elements.\n";
    plot_unit << "%\n";
    plot_unit << "%  Set the RGB color to darker red.\n";
    plot_unit << "%\n";
    plot_unit << "0.950  0.250  0.150 setrgbcolor\n";
    plot_unit << "/Times-Roman findfont\n";
    plot_unit << "0.20 inch scalefont\n";
    plot_unit << "setfont\n";
    plot_unit << "%\n";

    for ( element = 0; element < element_num; element++ )
    {
      ave_x = 0.0;
      ave_y = 0.0;

      for ( i = 0; i < 6; i++ )
      {
        node = element_node[i+element*6];
        ave_x = ave_x + node_xy[0+node*2];
        ave_y = ave_y + node_xy[1+node*2];
      }

      ave_x = ave_x / 6.0;
      ave_y = ave_y / 6.0;

      x_ps = ( int ) (
        ( ( x_max - ave_x         ) * ( double ) ( x_ps_min )  
        + (       + ave_x - x_min ) * ( double ) ( x_ps_max ) ) 
        / ( x_max         - x_min ) );

      y_ps = ( int ) (
        ( ( y_max - ave_y         ) * ( double ) ( y_ps_min )  
        + (         ave_y - y_min ) * ( double ) ( y_ps_max ) ) 
        / ( y_max         - y_min ) );

      plot_unit << setw(4) << x_ps << "  "
                << setw(4) << y_ps << "  "
                << "moveto (" << element << ") show\n";
    }
  }

  plot_unit << "%\n";
  plot_unit << "restore showpage\n";
  plot_unit << "%\n";
  plot_unit << "% End of page\n";
  plot_unit << "%\n";
  plot_unit << "%%Trailer\n";
  plot_unit << "%%EOF\n";

  plot_unit.close ( );

  return;
}

