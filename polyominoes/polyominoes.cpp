# include <cstdlib>
# include <cstring>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <iostream>

using namespace std;

# include "polyominoes.hpp"

//****************************************************************************80

void i4mat_copy ( int m, int n, int a1[], int a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_COPY copies one I4MAT to another.
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
//    27 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int A1[M*N], the matrix to be copied.
//
//    Output, int A2[M*N], the copy of A1.
//
{
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }
  return;
}
//****************************************************************************80

int *i4mat_copy_new ( int m, int n, int a1[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_COPY_NEW copies an I4MAT to a "new" I4MAT.
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
//    27 August 2008
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int A1[M*N], the matrix to be copied.
//
//    Output, int I4MAT_COPY_NEW[M*N], the copy of A1.
//
{
  int *a2;
  int i;
  int j;

  a2 = new int[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a2[i+j*m] = a1[i+j*m];
    }
  }
  return a2;
}
//****************************************************************************80

void i4mat_flip_cols ( int m, int n, int a[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_FLIP_COLS swaps the columns of an I4MAT.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
//
//    To "flip" the columns of an I4MAT is to start with something like
//
//      11 12 13 14 15
//      21 22 23 24 25
//      31 32 33 34 35
//      41 42 43 44 45
//      51 52 53 54 55
//
//    and return
//
//      15 14 13 12 11
//      25 24 23 22 21
//      35 34 33 32 31
//      45 44 43 42 41
//      55 54 53 52 51
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 June 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input/output, int A[M*N], the matrix whose columns are to be flipped.
//
{
  int b;
  int i;
  int j;

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < ( n / 2 ); j++ )
    {
      b              = a[i+     j *m];
      a[i+     j *m] = a[i+(n-1-j)*m];
      a[i+(n-1-j)*m] = b;
    }
  }
  return;
}
//****************************************************************************80

void i4mat_flip_rows ( int m, int n, int a[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_FLIP_ROWS swaps the rows of an I4MAT.
//
//  Discussion:
//
//    An I4MAT is an MxN array of I4's, stored by (I,J) -> [I+J*M].
//
//    To "flip" the rows of an I4MAT is to start with something like
//
//      11 12 13 14 15
//      21 22 23 24 25
//      31 32 33 34 35
//      41 42 43 44 45
//      51 52 53 54 55
//
//    and return
//
//      51 52 53 54 55
//      41 42 43 44 45
//      31 32 33 34 35
//      21 22 23 24 25
//      11 12 13 14 15
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 June 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input/output, int A[M*N], the matrix whose rows are to be flipped.
//
{
  int b;
  int i;
  int j;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < ( m / 2 ); i++ )
    {
      b            = a[    i+j*m];
      a[    i+j*m] = a[m-1-i+j*m];
      a[m-1-i+j*m] = b;
    }
  }
  return;
}
//****************************************************************************80

int i4mat_sum ( int m, int n, int a[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_SUM returns the sum of the entries of an I4MAT.
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
//    01 May 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows in A.
//
//    Input, int N, the number of columns in A.
//
//    Input, int A[M*N], the M by N matrix.
//
//    Output, int I4MAT_SUM, the sum of the entries.
//
{
  int i;
  int j;
  int value;

  value = 0;

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      value = value + a[i+j*m];
    }
  }
  return value;
}
//****************************************************************************80

void i4mat_transpose ( int m, int n, int a[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4MAT_TRANSPOSE transposes an I4MAT.
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
//    16 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, the number of rows in A.
//
//    Input, int N, the number of columns in A.
//
//    Input, int A[M*N], the M by N matrix.
//
//    Output, int A[N*M], the transposed matrix.
//
{
  int *b;
  int i;
  int j;

  b = new int[n*m];
  
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      b[j+i*n] = a[i+j*m];
    }
  }

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[j+i*n] = b[j+i*n];
    }
  }
 
  delete [] b;

  return;
}
//****************************************************************************80

void i4vec_copy ( int n, int a1[], int a2[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4VEC_COPY copies an I4VEC.
//
//  Discussion:
//
//    An I4VEC is a vector of I4's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 April 2007
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in the vectors.
//
//    Input, int A1[N], the vector to be copied.
//
//    Output, int A2[N], the copy of A1.
//
{
  int i;

  for ( i = 0; i < n; i++ )
  {
    a2[i] = a1[i];
  }
  return;
}
//****************************************************************************80

int *i4rows_copy_new ( int m, int n, int a1[] )

//****************************************************************************80
//
//  Purpose:
//
//    I4MROWS_COPY_NEW copies an I4ROWS to a "new" I4MAT.
//
//  Discussion:
//
//    An I4ROWS is an MxN array of I4's, stored by (I,J) -> [I*N+J].
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input, int A1[M*N], the matrix to be copied.
//
//    Output, int I4ROWS_COPY_NEW[M*N], the copy of A1.
//
{
  int *a2;
  int i;
  int j;

  a2 = new int[m*n];

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      a2[i*n+j] = a1[i*n+j];
    }
  }
  return a2;
}
//****************************************************************************80

int *i4rows_zeros_new ( int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    I4ROWS_ZEROS_NEW returns a new zeroed I4ROWS.
//
//  Discussion:
//
//    An I4ROWS is a doubly dimensioned array of I4 values, stored as a vector
//    in row-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Output, int I4ROWS_ZEROS_NEW[M*N], the new zeroed matrix.
//
{
  int *a;
  int i;
  int j;

  a = new int[m*n];

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      a[i*n+j] = 0;
    }
  }
  return a;
}
//*****************************************************************************/

void pentomino_matrix ( char name, int &p_m, int &p_n, int **p )

//*****************************************************************************/
//
//  Purpose:
//
//    PENTOMINO_MATRIX returns a 0/1 matrix defining a particular pentomino.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, char NAME, is 'f', 'i', 'l', 'n', 'p', 't', 'u', 'v', 'w', 'x', 
//    'y' or 'z'.
//
//    Output, int &P_M, &P_N, the number of rows and columns of the
//    representation.
//
//    Output, int P[P_M*P_N], a matrix of 0's and 1's that indicates
//    the shape of the pentomino.
//
{
  int f_mat[3*3] = {
     0, 1, 1,
     1, 1, 0,
     0, 1, 0 };
  int i_mat[5] = {
    1,
    1,
    1,
    1,
    1 };
  int l_mat[4*2] = {
    1, 0,
    1, 0,
    1, 0,
    1, 1 };
  int n_mat[2*4] = {
    1, 1, 0, 0,
    0, 1, 1, 1 };
  int p_mat[3*2] = {
    1, 1,
    1, 1,
    1, 0 };
  int t_mat[3*3] = {
    1, 1, 1,
    0, 1, 0,
    0, 1, 0 };
  int u_mat[2*3] = {
    1, 0, 1,
    1, 1, 1 };
  int v_mat[3*3] = {
    1, 0, 0,
    1, 0, 0,
    1, 1, 1 };
  int w_mat[3*3] = {
    1, 0, 0,
    1, 1, 0,
    0, 1, 1 };
  int x_mat[3*3] = {
    0, 1, 0,
    1, 1, 1,
    0, 1, 0 };
  int y_mat[2*4] = {
    0, 0, 1, 0,
    1, 1, 1, 1 };
  int z_mat[3*3] = {
    1, 1, 0,
    0, 1, 0,
    0, 1, 1 };

  if ( name == 'f' || name == 'F' )
  {
    p_m = 3;
    p_n = 3;
    *p = i4rows_copy_new ( p_m, p_n, f_mat ); 
  }
  else if ( name == 'i' || name == 'I' )
  {
    p_m = 5;
    p_n = 1;
    *p = i4rows_copy_new ( p_m, p_n, i_mat ); 
  }
  else if ( name == 'l' || name == 'L' )
  {
    p_m = 4;
    p_n = 2;
    *p = i4rows_copy_new ( p_m, p_n, l_mat ); 
  }
  else if ( name == 'n' || name == 'N' )
  {
    p_m = 2;
    p_n = 4;
    *p = i4rows_copy_new ( p_m, p_n, n_mat ); 
  }
  else if ( name == 'p' || name == 'P' )
  {
    p_m = 3;
    p_n = 2;
    *p = i4rows_copy_new ( p_m, p_n, p_mat ); 
  }
  else if ( name == 't' || name == 'T' )
  {
    p_m = 3;
    p_n = 3;
    *p = i4rows_copy_new ( p_m, p_n, t_mat ); 
  }
  else if ( name == 'u' || name == 'U' )
  {
    p_m = 2;
    p_n = 3;
    *p = i4rows_copy_new ( p_m, p_n, u_mat ); 
  }
  else if ( name == 'v' || name == 'V' )
  {
    p_m = 3;
    p_n = 3;
    *p = i4rows_copy_new ( p_m, p_n, v_mat ); 
  }
  else if ( name == 'w' || name == 'W' )
  {
    p_m = 3;
    p_n = 3;
    *p = i4rows_copy_new ( p_m, p_n, w_mat ); 
  }
  else if ( name == 'x' || name == 'X' )
  {
    p_m = 3;
    p_n = 3;
    *p = i4rows_copy_new ( p_m, p_n, x_mat ); 
  }
  else if ( name == 'y' || name == 'Y' )
  {
    p_m = 2;
    p_n = 4;
    *p = i4rows_copy_new ( p_m, p_n, y_mat ); 
  }
  else if ( name == 'z' || name == 'Z' )
  {
    p_m = 3;
    p_n = 3;
    *p = i4rows_copy_new ( p_m, p_n, z_mat ); 
  }
  else
  {
    cout << "\n";
    cout << "PENTOMINO_MATRIX - Fatal error!\n";
    cout << "  Illegal name = '" << name << "'\n";
    cout << "  Legal names: f, i, l, n, p, t, u, v, w, x, y, z.\n";
    exit ( 1 );
  }

  return;
}
//****************************************************************************80

void pentomino_plot ( int p_m, int p_n, int p[], string label )

//****************************************************************************80
//
//  Purpose:
//
//    PENTOMINO_PLOT plots a particular pentomino in a 5x5 grid.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    22 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int P_M, P_N, the number of rows and columns of the
//    representation.
//
//    Input, int P[P_M*P_N], a matrix of 0's and 1's.
//    1 <= P_M, P_N <= 5.  There should be exactly 5 values of one.
//
//    Input, string LABEL, a title for the plot.
//
{
  string color;
  int *color_index;
  string command_filename;
  ofstream command_unit;
  int i;
  int i_reverse;
  int j;
  int k;
  int m = 5;
  int n = 5;
  string plot_filename;

  command_filename = label + "_commands.txt";
  plot_filename = label + ".png";
//
//  Initially, the grid is entirely white (color 0)
//
  color_index = i4rows_zeros_new ( m, n );
//
//  Place the pentomino on the grid, so that it is "snug" in the upper left corner.
//
  for ( i = 0; i < p_m; i++ )
  {
    for ( j = 0; j < p_n; j++ )
    {
      color_index[i*n+j] = p[i*p_n+j];
    }
  }
//
//  Create the command file.
//
  command_unit.open ( command_filename.c_str ( ) );
  command_unit << "# " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "# Usage:\n";
  command_unit << "#  gnuplot < " << command_filename << "\n";
  command_unit << "#\n";
  command_unit << "set term png\n";
  command_unit << "set output '" << plot_filename << "'\n";
  command_unit << "set title '" << label << "'\n";
//
//  Get a plot of TRUE SQUARES.
//
  command_unit << "set xrange [ 0 : 5 ]\n";
  command_unit << "set yrange [ 0 : 5 ]\n";
  command_unit << "set size square\n";
  command_unit << "unset border\n";
  command_unit << "unset tics\n";
  command_unit << "set nokey\n";

  k = 0;
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      k = k + 1;

      if ( color_index[i*n+j] == 0 )
      {
        color = "white";
      }
      else if ( color_index[i*n+j] == 1 )
      {
        color = "black";
      }

      i_reverse = m - 1 - i;
      command_unit << "set object " << k 
        << " rect from " << j 
        << ", " << i_reverse
        << " to " << j + 1
        << ", " << i_reverse + 1 << " back\n";
      command_unit << "set object " << k 
        << " rect fc rgb '" << color 
        << "' fillstyle solid 1.0\n";
    }
  }
//
//  If you don't have some bogus PLOT command here, all the previous work
//  results in no plot all.  Way to go, gnuplot!
//  Here, we plot the function y = -1, which is out of range and won't show up.
//
  command_unit << "plot -1 with lines\n";
  command_unit.close ( );

  cout << "  PENTOMINO_PLOT created command file '" << command_filename << "'\n";
//
//  Free memory.
//
  delete [] color_index;

  return;
}
//****************************************************************************80

void polyomino_condense ( int mp, int np, int p[], int &mq, int &nq, int **q )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_CONDENSE condenses a polyomino.
//
//  Discussion:
//
//    A polyomino is a shape formed by connecting unit squares edgewise.
//
//    A polyomino can be represented by an MxN matrix, whose entries are
//    1 for squares that are part of the polyomino, and 0 otherwise.
//
//    This program is given an MxN matrix that is meant to represent a 
//    polyomino.  It first replaces all nonzero entries by the value 1.
//    It then "condenses" the matrix, if possible, by removing initial and
//    final rows and columns that are entirely zero.
//
//    While this procedure might save a slight amount of space, its purpose
//    is to simplify the task of manipulating polyominos, embedding them in
//    larger shapes, and detecting whether two polyominos describe the same
//    shape.
//
//    It is entirely possible, and usual, that the output quantities are
//    simply copies of the input quantities.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int MP, NP, the number of rows and columns in the representation
//    of the polyomino P.
//
//    Input, int P[MP*NP], a matrix of 0's and 1's representing the 
//    polyomino.  
//
//    Output, int &MQ, &NQ, the number of rows and columns of the
//    condensed polyomino.
//
//    Output, int *Q[MQ*NQ], the representation of the condensed
//    polyomino.
//
{
  int i;
  int i_max;
  int i_min;
  int j;
  int j_max;
  int j_min;
//
//  Discard nonsense.
//
  if ( mp <= 0 || np <= 0 )
  {
    mq = 0;
    nq = 0;
    q = NULL;
    return;
  }
//
//  Seek first and last nonzero rows, columns.
//
  i_min = -1;
  for ( i = 0; i < mp; i++ )
  {
    for ( j = 0; j < np; j++ )
    {
      if ( p[i+j*mp] != 0 )
      {
        i_min = i;
        break;
      }
    }
    if ( i_min != -1 ) 
    {
      break;
    }
  }
//
//  If I_MIN = -1, then we have a null matrix.
//
  if ( i_min == -1 )
  {
    mq = 0;
    nq = 0;
    q = NULL;
    return;
  }

  i_max = mp;
  for ( i = mp - 1; 0 <= i; i-- )
  {
    for ( j = 0; j < np; j++ )
    {
      if ( p[i+j*mp] != 0 )
      {
        i_max = i;
        break;
      }
    }
    if ( i_max != mp ) 
    {
      break;
    }
  }

  j_min = -1;
  for ( j = 0; j < np; j++ )
  {
    for ( i = 0; i < mp; i++ )
    {
      if ( p[i+j*mp] != 0 )
      {
        j_min = j;
        break;
      }
    }
    if ( j_min != -1 ) 
    {
      break;
    }
  }

  j_max = np;
  for ( j = np - 1; 0 <= j; j-- )
  {
    for ( i = 0; i < mp; i++ )
    {
      if ( p[i+j*mp] != 0 )
      {
        j_max = j;
        break;
      }
    }
    if ( j_max != np ) 
    {
      break;
    }
  }
//
//  Measure the nonzero block.
//
  mq = i_max + 1 - i_min;
  nq = j_max + 1 - j_min;
  *q = new int [ mq * nq ];
//
//  Copy the nonzero block.
//
  for ( j = 0; j < nq; j++ )
  {
    for ( i = 0; i < mq; i++ )
    {
      if ( p[(i+i_min)+(j+j_min)*mp] != 0 )
      {
        (*q)[i+j*mq] = 1;
      }
      else
      {
        (*q)[i+j*mq] = 0;
      }
    }
  }

  return;
}
//****************************************************************************80

int *polyomino_embed_list ( int mr, int nr, int r[], int mp, int np, int p[], 
  int number )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_EMBED_LIST lists the polyomino embeddings in a region.
//
//  Discusion:
//
//    A region R is a subset of an MRxNR grid of squares.
//
//    A polyomino P is a subset of an MPxNP grid of squares.
//
//    Both objects are represented by binary matrices, with the property that
//    there are no initial or final zero rows or columns.
//
//    For this computation, we regard P as a "fixed" polyomino; in other words,
//    no reflections or rotations will be allowed.
//
//    An "embedding" of P into R is an offset (MI,NJ) such that 
//      P(I,J) = R(I+MI,J+NJ) 
//      for 1 <= I <= MP, 1 <= J <= NP, and 
//      for 0 <= MI <= MR-MP, 0 <= MJ <= NR-NP.
//    We can detect an embedding simply by taking what amounts to a kind of
//    dot product of P with a corresponding subregion of R.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 May 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int MR, NR, the number of rows and columns in the representation
//    of the region R.
//
//    Input, int R(MR,NR), a matrix of 0's and 1's representing the 
//    region.
//
//    Input, int MP, NP, the number of rows and columns in the representation
//    of the polyomino P.
//
//    Input, int P[MP*NP], a matrix of 0's and 1's representing the 
//    polyomino.
//
//    Input, int NUMBER, the number of embeddings.
//
//    Output, int POLYOMINO_EMBED_LIST[NUMBER*2], for each embedding, the I 
//    and J offsets applied to the polyomino P.
//
{
  int i;
  int j;
  int k;
  int *list;
  int mi;
  int nj;
  int pr;
  int srp;

  list = new int [ number * 2 ];
//
//  Count the 1's in P.
//
  pr = i4mat_sum ( mp, np, p );
//
//  For each possible (I,J) coordinate of the upper left corner of a subset of R,
//  see if it matches P.
//
  k = 0;
  for ( mi = 0; mi <= mr - mp; mi++ )
  {
    for ( nj = 0; nj <= nr - np; nj++ )
    {
      srp = 0;
      for ( j = 0; j < np; j++ )
      {
        for ( i = 0; i < mp; i++ )
        {
          srp = srp + p[i+j*mp] * r[i+mi+(j+nj)*mr];
        }
      }
      if ( srp == pr )
      {
        list[k+0*number] = mi;
        list[k+1*number] = nj;
        k = k + 1;
      }
    }
  }

  return list;
}
//****************************************************************************80

int polyomino_embed_number ( int mr, int nr, int r[], int mp, int np, int p[] )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_EMBED_NUMBER counts the number of polyomino embeddings in a region.
//
//  Discusion:
//
//    A region R is a subset of an MRxNR grid of squares.
//
//    A polyomino P is a subset of an MPxNP grid of squares.
//
//    Both objects are represented by binary matrices, with the property that
//    there are no initial or final zero rows or columns.
//
//    For this computation, we regard P as a "fixed" polyomino; in other words,
//    no reflections or rotations will be allowed.
//
//    An "embedding" of P into R is an offset (MI,NJ) such that 
//      P(I,J) = R(I+MI,J+NJ) 
//      for 1 <= I <= MP, 1 <= J <= NP, and 
//      for 0 <= MI <= MR-MP, 0 <= MJ <= NR-NP.
//    We can detect an embedding simply by taking what amounts to a kind of
//    dot product of P with a corresponding subregion of R.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 May 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int MR, NR, the number of rows and columns in the representation
//    of the region R.
//
//    Input, int R[MR*NR], a matrix of 0's and 1's representing the 
//    region.
//
//    Input, int MP, NP, the number of rows and columns in the representation
//    of the polyomino P.
//
//    Input, int P[MP*NP], a matrix of 0's and 1's representing the 
//    polyomino.
//
//    Output, int POLYOMINO_EMBED_NUMBER, the number of distinct embeddings of 
//    P into R.
//
{
  int i;
  int j;
  int mi;
  int nj;
  int number;
  int pr;
  int srp;

  number = 0;
//
//  Count the 1's in P.
//
  pr = i4mat_sum ( mp, np, p );
//
//  For each possible (I,J) coordinate of the upper left corner of a subset of R,
//  see if it matches P.
//
  for ( mi = 0; mi <= mr - mp; mi++ )
  {
    for ( nj = 0; nj <= nr - np; nj++ )
    {
      srp = 0;
      for ( j = 0; j < np; j++ )
      {
        for ( i = 0; i < mp; i++ )
        {
          srp = srp + p[i+j*mp] * r[i+mi+(j+nj)*mr];
        }
      }
      if ( srp == pr )
      {
        number = number + 1;
      }     
    }
  }

  return number;
}
//****************************************************************************80

void polyomino_enumerate_chiral ( int &n_data, int &order, 
  long long int &number )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_ENUMERATE_CHIRAL counts chiral polyominoes (allowing holes).
//
//  Discussion:
//
//    Polyominoes are connected planar shapes formed by adjoining unit squares.
//
//    The number of unit squares in a polyomino is its order.
//
//    If we do not ignore reflections, but ignore rotations when comparing 
//    then we are considering the class of "chiral" polyominoes.  In that case,
//    for instance, there are 18 fixed polyominoes of order 5.
//
//    As the order increases, the number of polyominoes grows very rapidly.
//    The list offered here goes no further than order 28, but the later
//    numbers in the list are too large to represent as 32 byte integers. 
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 May 2018
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Solomon Golomb,
//    Polyominoes: Puzzles, Patterns, Problems, and Packings,
//    Princeton University Press, 1996,
//    ISBN: 9780691024448
//
//  Parameters:
//
//    Input/output, int &N_DATA.  The user sets N_DATA to 0 
//    before the first call.  On each call, the routine increments N_DATA by 1, 
//    and returns the corresponding data; when there is no more data, the
//    output value of N_DATA will be 0 again.
//
//    Output, int &ORDER, the order of a polyomino.
//
//    Output, long long int &NUMBER, the number of chiral polyominos 
//    of this order.
//
{
# define N_MAX 31

  static long long int number_vec[N_MAX] = {  
    1L, 
    1L,
    1L,
    2L,
    7L,
    18L, 
    60L,
    196L,
    704L,
    2500L,
    9189L, 
    33896L,
    126759L,
    476270L,
    1802312L,
    6849777L, 
    26152418L,
    100203194L,
    385221143L,
    1485200848L,
    5741256764L, 
    22245940545L,
    86383382827L,
    336093325058L,
    1309998125640L,
    5114451441106L, 
    19998172734786L,
    78306011677182L,
    307022182222506L,
    1205243866707468L,
    4736694001644862L };
  static int order_vec[N_MAX] = {
    0, 
    1,  2,  3,  4,  5, 
    6,  7,  8,  9, 10, 
   11, 12, 13, 14, 15, 
   16, 17, 18, 19, 20, 
   21, 22, 23, 24, 25, 
   26, 27, 28, 29, 30 };

  if ( n_data < 0 )
  {
    n_data = 0;
  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )
  {
    n_data = 0;
    order = 0;
    number = 0;
  }
  else
  {
    order = order_vec[n_data-1];
    number = number_vec[n_data-1];
  }

  return;
# undef N_MAX
}
//****************************************************************************80

void polyomino_enumerate_fixed ( int &n_data, int &order, 
  long long int &number )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_ENUMERATE_FIXED counts fixed polyominoes (allowing holes).
//
//  Discussion:
//
//    Polyominoes are connected planar shapes formed by adjoining unit squares.
//
//    The number of unit squares in a polyomino is its order.
//
//    If we do not ignore reflections and rotations when comparing polyominoes,
//    then we are considering the class of "fixed" polyominoes.  In that case,
//    for instance, there are 65 fixed polyominoes of order 5.
//
//    As the order increases, the number of polyominoes grows very rapidly.
//    The list offered here goes no further than order 28, but the later
//    numbers in the list are too large to represent as 32 byte integers. 
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Solomon Golomb,
//    Polyominoes: Puzzles, Patterns, Problems, and Packings,
//    Princeton University Press, 1996,
//    ISBN: 9780691024448
//
//  Parameters:
//
//    Input/output, int &N_DATA.  The user sets N_DATA to 0 
//    before the first call.  On each call, the routine increments N_DATA by 1, 
//    and returns the corresponding data; when there is no more data, the
//    output value of N_DATA will be 0 again.
//
//    Output, int &ORDER, the order of a polyomino.
//
//    Output, long long int &NUMBER, the number of fixed polyominos 
//    of this order.
//
{
# define N_MAX 29

  static long long int number_vec[N_MAX] = {  
    1L, 
    1L, 
    2L, 
    6L, 
    19L, 
    63L, 
    216L, 
    760L, 
    2725L, 
    9910L, 
    36446L, 
    135268L, 
    505861L, 
    1903890L, 
    7204874L, 
    27394666L, 
    104592937L, 
    400795844L, 
    1540820542L, 
    5940738676L, 
    22964779660L, 
    88983512783L, 
    345532572678L, 
    1344372335524L, 
    5239988770268L, 
    20457802016011L, 
    79992676367108L, 
    313224032098244L, 
    1228088671826973L };
  static int order_vec[N_MAX] = {
    0, 
    1,  2,  3,  4,  5, 
    6,  7,  8,  9, 10, 
   11, 12, 13, 14, 15, 
   16, 17, 18, 19, 20, 
   21, 22, 23, 24, 25, 
   26, 27, 28 };

  if ( n_data < 0 )
  {
    n_data = 0;
  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )
  {
    n_data = 0;
    order = 0;
    number = 0;
  }
  else
  {
    order = order_vec[n_data-1];
    number = number_vec[n_data-1];
  }

  return;
# undef N_MAX
}
//****************************************************************************80

void polyomino_enumerate_free ( int &n_data, int &order, 
  long long int &number )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_ENUMERATE_FREE counts free polyominoes (allowing holes).
//
//  Discussion:
//
//    Polyominoes are connected planar shapes formed by adjoining unit squares.
//
//    The number of unit squares in a polyomino is its order.
//
//    If we ignore reflections and rotations when comparing polyominoes,
//    then we are considering the class of "free" polyominoes.  In that case,
//    for instance, there are just 12 free polyominoes of order 5, the
//    so called "pentominoes".
//
//    As the order increases, the number of polyominoes grows very rapidly.
//    The list offered here goes no further than order 28, but the later
//    numbers in the list are too large to represent as 32 byte integers. 
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    13 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Solomon Golomb,
//    Polyominoes: Puzzles, Patterns, Problems, and Packings,
//    Princeton University Press, 1996,
//    ISBN: 9780691024448
//
//  Parameters:
//
//    Input/output, int &N_DATA.  The user sets N_DATA to 0 
//    before the first call.  On each call, the routine increments N_DATA by 1, 
//    and returns the corresponding data; when there is no more data, the
//    output value of N_DATA will be 0 again.
//
//    Output, int &ORDER, the order of a polyomino.
//
//    Output, long long int &NUMBER, the number of free polyominos of 
//    this order.
//
{
# define N_MAX 29

  static long long int number_vec[N_MAX] = {  
    1L,   
    1L, 
    1L, 
    2L, 
    5L, 
    12L, 
    35L, 
    108L, 
    369L, 
    1285L, 
    4655L, 
    17073L, 
    63600L, 
    238591L, 
    901971L, 
    3426576L, 
    13079255L, 
    50107909L, 
    192622052L, 
    742624232L, 
    2870671950L, 
    11123060678L, 
    43191857688L, 
    168047007728L, 
    654999700403L, 
    2557227044764L, 
    9999088822075L, 
    39153010938487L, 
    153511100594603L };
  static int order_vec[N_MAX] = {  
    0, 
    1,  2,  3,  4,  5, 
    6,  7,  8,  9, 10, 
   11, 12, 13, 14, 15, 
   16, 17, 18, 19, 20, 
   21, 22, 23, 24, 25, 
   26, 27, 28 };

  if ( n_data < 0 )
  {
    n_data = 0;
  }

  n_data = n_data + 1;

  if ( N_MAX < n_data )
  {
    n_data = 0;
    order = 0;
    number = 0;
  }
  else
  {
    order = order_vec[n_data-1];
    number = number_vec[n_data-1];
  }

  return;
# undef N_MAX
}
//****************************************************************************80

int *polyomino_index ( int m, int n, int p[] )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_INDEX assigns an index to each nonzero entry of a polyomino.
//
//  Example:
//
//    P = 
//      1 0 1 1
//      1 1 1 0
//      0 1 1 0
//
//    PIN =
//      1 0 2 3
//      4 5 6 0
//      0 7 8 0
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 May 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the array that
//    represents the polyomino.
//
//    Input, int P[M*N], the polyomino.  It is assumed that every entry
//    is a 0 or a 1.
//
//    Output, int *PIN[M*N], the index of each nonzero entry.
//
{
  int i;
  int j;
  int k;
  int *pin;

  pin = new int[ m * n ];

  k = 0;
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( p[i+j*m] != 0 )
      {
        k = k + 1;
        pin[i+j*m] = k;
      }
      else
      {
        pin[i+j*m] = 0;
      }
    }
  }
  return pin;
}
//****************************************************************************80

void polyomino_lp_write ( string filename, string label, int m, int n, int a[], 
  int b[] )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_LP_WRITE writes an LP file for the polyomino problem.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 May 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, string FILENAME, the output filename.
//
//    Input, string LABEL, the problem title.
//
//    Input, int M, the number of equations
//
//    Input, int N, the number of variables.
//
//    Input, int A[M*N], the coefficients.
//
//    Input, int B[M], the right hand sides.
//
{
  bool first;
  int i;
  int j;
  ofstream output;
//
//  Open the file.
//
  output.open ( filename.c_str ( ) );

  if ( ! output ) 
  {
    cerr << "\n";
    cerr << "POLYOMINO_LP_WRITE - Error!\n";
    cerr << "  Could not open the output file.\n";
    exit ( 1 );
  }

  output << label << "\n";
  output << "\n";

  output << "Maximize\n";
  output << "  Obj: 0\n";

  output << "Subject to\n";

  for ( i = 0; i < m; i++ )
  {
    first = true;
    for ( j = 0; j< n; j++ )
    {
      if ( a[i+j*m] != 0 )
      {
        if ( a[i+j*m] < 0 )
        {
          output << " -";
        }
        else if ( ! first )
        {
          output << " +";
        }

        if ( abs ( a[i+j*m] ) == 1 )
        {
          output << " x" << j + 1;
        }
        else
        {
          output << " " <<  abs ( a[i+j*m] ) << " x" << j + 1;
        }
        first = false;
      }
    }
    output << " = " << b[i] << "\n";
  }

  output << "Binary\n";
  output << " ";
  for ( j = 0; j < n; j++ )
  {
    output << " x" << j + 1;
  }
  output << "\n";

  output << "End\n";
//
//  Close the file.
//
  output.close ( );

  return;
}
//****************************************************************************80

void polyomino_print ( int m, int n, int p[], string label )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_PRINT prints a polyomino.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the representation
//    of the polyomino P.
//
//    Input, int P[M*N], a matrix of 0's and 1's representing the 
//    polyomino.  The matrix should be "tight", that is, there should be a
//    1 in row 1, and in column 1, and in row M, and in column N.
//
//    Input, string LABEL, a title for the polyomino.
//
{
  int i;
  int j;

  cout << "\n";
  cout << label << "\n";
  cout << "\n";
  if ( m <= 0 || n <= 0 )
  {
    cout << "  [ Null matrix ]\n";
  }
  else
  {
    for ( i = 0; i < m; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        cout << " " << p[i+j*m];
      }
      cout << "\n";
    }
  }
  return;
}
//****************************************************************************80

void polyomino_transform ( int m, int n, int p[], int rotate, int reflect, 
  int &mq, int &nq, int **q )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_TRANSFORM transforms a polyomino.
//
//  Discussion:
//
//    A polyomino can be rotated or reflected.
//
//    This program is given a polyomino and returns the resulting polyomino
//    after the specified reflection and rotation.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    17 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the representation
//    of the polyomino P.
//
//    Input, int P[M*N], a matrix of 0's and 1's representing the 
//    polyomino.  The matrix should be "tight", that is, there should be a
//    1 in row 1, and in column 1, and in row M, and in column N.
//
//    Input, int ROTATE, is 0, 1, 2, or 3, the number of 90 degree
//    counterclockwise rotations to be applied.
//
//    Input, int REFLECT, is 0 or 1.  If it is 1, then each row of the
//    polyomino matrix is to be reflected before any rotations are performed.
//
//    Output, int &MQ, &NQ, the number of rows and columns of the
//    representation of the transformed polyomino
//
//    Output, int Q[MQ*NQ], the representation of the transformed
//    polyomino.
//
{
  int k;
  int r;
  int s;

  mq = m;
  nq = n;

  reflect = ( reflect % 2 );

  *q = i4mat_copy_new ( m, n, p );

  if ( reflect == 1 )
  {
    i4mat_flip_cols ( mq, nq, *q );
  }

  rotate = ( rotate % 4 );

  for ( k = 1; k <= rotate; k++ )
  {
    i4mat_transpose ( mq, nq, *q );
    r = mq;
    s = nq;
    mq = s;
    nq = r;
    i4mat_flip_rows ( mq, nq, *q );
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
//    19 March 2018
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
