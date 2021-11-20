# include <cstdlib>
# include <iomanip>
# include <iostream>

using namespace std;

# include "polyominoes.hpp"

int main ( );
void pentomino_matrix_test ( );
void pentomino_plot_test ( );
void polyomino_condense_test ( );
void polyomino_condense_demo ( int mp, int np, int p[] );
void polyomino_embed_list_test ( );
void polyomino_embed_number_test ( );
void polyomino_enumerate_test ( );
void polyomino_enumerate_chiral_test ( );
void polyomino_enumerate_fixed_test ( );
void polyomino_enumerate_free_test ( );
void polyomino_index_test ( );
void polyomino_lp_write_test ( );
void polyomino_monohedral_example_reid_size ( int &m, int &n );
void polyomino_monohedral_example_reid_system ( int m, int n, int a[], int b[] );
void polyomino_transform_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for polyominoes_test.
//
//  Discussion:
//
//    polyominoes_test tests polyominoes.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 April 2020
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "polyominoes_test\n";
  cout << "  C++ version\n";
  cout << "  Test polyominoes.\n";

  pentomino_matrix_test ( );
  pentomino_plot_test ( );
  polyomino_condense_test ( );
  polyomino_embed_number_test ( );
  polyomino_embed_list_test ( );
  polyomino_enumerate_test ( );
  polyomino_index_test ( );
  polyomino_lp_write_test ( );
  polyomino_transform_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "polyominoes_test\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void pentomino_matrix_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    PENTOMINO_MATRIX_TEST tests PENTOMINO_MATRIX.
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
{
  int i;
  int j;
  int k;
  int *p;
  int p_m;
  int p_n;
  char pentominoes[12] = 
    { 'F', 'I', 'L', 'N', 'P', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

  cout << "\n";
  cout << "PENTOMINO_MATRIX_TEST\n";
  cout <<"  PENTOMINO_MATRIX returns a 0/1 matrix representing a pentomino.\n";

  for ( k = 0; k < 12; k++ )
  {
    pentomino_matrix ( pentominoes[k], p_m, p_n, &p );
    cout << "\n";
    cout << "  " << pentominoes[k] << " pentomino (" << p_m << "," << p_n << "):\n";
    cout << "\n";
    for ( i = 0; i < p_m; i++ )
    {
      cout << "    " ;
      for ( j = 0; j < p_n; j++ )
      {
        cout << p[i*p_n+j];
      }
      cout << "\n";
    }
    delete [] p;
  }

  return;
}
//****************************************************************************80

void pentomino_plot_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    PENTOMINO_PLOT_TEST tests PENTOMINO_PLOT.
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
{
  int k;
  string label;
  int *p;
  int p_m;
  int p_n;
  char pentominoes[12] = 
    { 'F', 'I', 'L', 'N', 'P', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

  cout << "\n";
  cout << "PENTOMINO_PLOT_TEST\n";
  cout << "  PENTOMINO_PLOT plots a pentomino.\n";

  for ( k = 0; k < 12; k++ )
  {
    pentomino_matrix ( pentominoes[k], p_m, p_n, &p );
    label = pentominoes[k];
    pentomino_plot ( p_m, p_n, p, label );
  }

  return;
}
//****************************************************************************80

void polyomino_condense_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_CONDENSE_TEST tests POLYOMINO_CONDENSE.
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
//  Local parameters:
//
//    Local, int MP, NP, the number of rows and columns in the representation
//    of the polyomino P.
//
//    Local, int P[MP*NP], a matrix representing the polyomino.  
//
{
  int mp;
  int np;
  int p1[] = { 0, 1, 1, 1, 1, 0, 0, 1, 0 };
  int p2[] = { 0, 1, 2, 1, 3, 0, 0, -9, 0 };
  int p3[] = { 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0 };
  int p4[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

  cout << "\n";
  cout << "POLYOMINO_CONDENSE_TEST:\n";
  cout << "  C++ version\n";
  cout << "  POLYOMINO_CONDENSE 'cleans up' a matrix that is supposed\n";
  cout << "  to represent a polyomino:\n";
  cout << "  * nonzero entries are set to 1;\n";
  cout << "  * initial and final zero rows and columns are deleted.\n";
//
//  Nothing happens:
//
  mp = 3;
  np = 3;
  polyomino_condense_demo ( mp, np, p1 );
//
//  Nonzero, but non-one entries are set to 1.
//
  mp = 3;
  np = 3;
  polyomino_condense_demo ( mp, np, p2 );
//
//  Extraneous zero rows and columns are removed.
//
  mp = 3;
  np = 4;
  polyomino_condense_demo ( mp, np, p3 );
//
//  Null matrices are detected.
//
  mp = 2;
  np = 4;
  polyomino_condense_demo ( mp, np, p4 );
//
//  Terminate.
//
  cout << "\n";
  cout << "POLYOMINO_CONDENSE_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return;
}
//****************************************************************************80

void polyomino_condense_demo ( int mp, int np, int p[] )

//****************************************************************************80
//
//  Purpose:
//
//    polyomino_condense_demo demonstrates POLYOMINO_CONDENSE.
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
//    Input, int P[MP*NP], a matrix representing the polyomino.  
//
//    Local, int MQ, NQ, the number of rows and columns in the representation
//    of the condensed polyomino Q.
//
//    Local, int Q[MQ*NQ], a matrix representing the condensed polyomino.  
//
{
  string label;
  int mq;
  int nq;
  int *q;

  label = "  The initial (" + to_string ( mp ) + "," + to_string ( np ) + ") polynomino P:";
  polyomino_print ( mp, np, p, label );

  polyomino_condense ( mp, np, p, mq, nq, &q );

  label = "  The condensed (" + to_string ( mq ) + "," + to_string ( nq ) + ") polynomino Q:";
  polyomino_print ( mq, nq, q, label );

  if ( *q )
  {
    delete [] q;
  }

  return;
}
//****************************************************************************80

void polyomino_embed_list_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_EMBED_LIST_TEST tests POLYOMINO_EMBED_LIST.
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
{
  int i;
  int j;
  int k;
  int *list;
  int mk;
  int nk;
  int mp = 3;
  int mq;
  int mr = 4;
  int np = 2;
  int nq;
  int nr = 4;
  int number;
  int p[3*2] = {
    0, 0, 1,
    1, 1, 1 };
  int q[4*4];
  int r[4*4] = { 
    0, 1, 1, 1,
    1, 1, 1, 0,
    1, 0, 1, 1,
    1, 1, 1, 1 };

  cout << "\n";
  cout << "POLYOMINO_EMBED_LIST_TEST:\n";
  cout << "  POLYOMINO_EMBED_LIST lists the offsets used\n";
  cout << "  to embed a fixed polyomino in a region.\n";

  polyomino_print ( mr, nr, r, "  The given region R:" );

  polyomino_print ( mp, np, p, "  The given polyomino P:" );
//
//  Get the number of embeddings.
//
  number = polyomino_embed_number ( mr, nr, r, mp, np, p );

  cout << "\n";
  cout << "  As a fixed polyomino, P can be embedded in R in " << number << " ways\n";
/*
  Get the list of embeddings.
*/
  list = polyomino_embed_list ( mr, nr, r, mp, np, p, number );

  for ( k = 0; k < number; k++ )
  {
    mk = list[k+0*number];
    nk = list[k+1*number];
    mq = mr;
    nq = nr;

    for ( j = 0; j < nq; j++ )
    {
      for ( i = 0; i < mq; i++ )
      {
        q[i+j*mq] = r[i+j*mr];
      }
    }

    for ( j = 0; j < np; j++ )
    {
      for ( i = 0; i < mp; i++ )
      {
        q[i+mk+(j+nk)*mq] = q[i+mk+(j+nk)*mq] + p[i+j*mp];
      }
    }

    cout << "\n";
    cout << "  Embedding number " << k << ":\n";
    cout << "\n";
    for ( i = 0; i < mq; i++ )
    {
      for ( j = 0; j < nq; j++ )
      {
        cout << " " << q[i+j*mq];
      }
      cout << "\n";
    }
  }

  delete [] list;

  return;
}
//****************************************************************************80

void polyomino_embed_number_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_EMBED_NUMBER_TEST tests POLYOMINO_EMBED_NUMBER.
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
{
  int mp = 3;
  int mr = 4;
  int np = 2;
  int nr = 4;
  int number;
  int p[3*2] = {
    0, 0, 1,
    1, 1, 1 };
  int r[4*4] = { 
    0, 1, 1, 1,
    1, 1, 1, 0,
    1, 0, 1, 1,
    1, 1, 1, 1 };

  cout << "\n";
  cout << "POLYOMINO_EMBED_NUMBER_TEST:\n";
  cout << "  POLYOMINO_EMBED_NUMBER reports the number of ways a\n";
  cout << "  fixed polyomino can be embedded in a region.\n";

  polyomino_print ( mr, nr, r, "  The given region R:" );

  polyomino_print ( mp, np, p, "  The given polyomino P:" );

  number = polyomino_embed_number ( mr, nr, r, mp, np, p );

  cout << "\n";
  cout << "  As a fixed polyomino, P can be embedded in R in " << number << " ways\n";

  return;
}
//****************************************************************************80

void polyomino_enumerate_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_ENUMERATE_TEST tests the POLYOMINO_ENUMERATE library.
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
{
  cout << "\n";
  cout << "POLYOMINO_ENUMERATE_TEST:\n";
  cout << "  C++ version,\n";
  cout << "  POLYOMINO_ENUMERATE enumerates various classes of polyomino.\n";

  polyomino_enumerate_chiral_test ( );
  polyomino_enumerate_fixed_test ( );
  polyomino_enumerate_free_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "POLYOMINO_ENUMERATE_TEST:\n";
  cout << "  Normal end of execution.\n";

  return;
}
//****************************************************************************80

void polyomino_enumerate_chiral_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_ENUMERATE_CHIRAL_TEST tests POLYOMINO_ENUMERATE_CHIRAL.
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
{
  int n_data;
  long long int number;
  int order;

  cout << "\n";
  cout << "POLYOMINO_ENUMERATE_CHIRAL_TEST:\n";
  cout << "  POLYOMINO_ENUMERATE_CHIRAL returns the number of chiral\n";
  cout << "  polyominoes of a given order;\n";

  n_data = 0;
  cout << "\n";
  cout << "   Order      Number\n";
  cout << "\n";

  for ( ; ; )
  {
    polyomino_enumerate_chiral ( n_data, order, number );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "  " << setw(4) << order
         << "  " << setw(24) << number << "\n";
  }
  return;
}
//****************************************************************************80

void polyomino_enumerate_fixed_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_ENUMERATE_FIXED_TEST tests POLYOMINO_ENUMERATE_FIXED.
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
{
  int n_data;
  long long int number;
  int order;

  cout << "\n";
  cout << "POLYOMINO_ENUMERATE_FIXED_TEST:\n";
  cout << "  POLYOMINO_ENUMERATE_FIXED returns the number of fixed\n";
  cout << "  polyominoes of a given order;\n";

  n_data = 0;
  cout << "\n";
  cout << "   Order      Number\n";
  cout << "\n";

  for ( ; ; )
  {
    polyomino_enumerate_fixed ( n_data, order, number );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "  " << setw(4) << order
         << "  " << setw(24) << number << "\n";
  }
  return;
}
//****************************************************************************80

void polyomino_enumerate_free_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_ENUMERATE_FREE_TEST tests POLYOMINO_ENUMERATE_FREE.
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
{
  int n_data;
  long long int number;
  int order;

  cout << "\n";
  cout << "POLYOMINO_ENUMERATE_FREE_TEST:\n";
  cout << "  POLYOMINO_ENUMERATE_FREE returns the number of free\n";
  cout << "  polyominoes of a given order;\n";

  n_data = 0;
  cout << "\n";
  cout << "   Order      Number\n";
  cout << "\n";

  for ( ; ; )
  {
    polyomino_enumerate_free ( n_data, order, number );

    if ( n_data == 0 )
    {
      break;
    }

    cout << "  " << setw(4) << order
         << "  " << setw(24) << number << "\n";
  }
  return;
}
//****************************************************************************80

void polyomino_index_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_INDEX_TEST tests POLYOMINO_INDEX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    30 April 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int j;
  int m = 3;
  int n = 4;
//
//  P is listed in column-major order;
//
  int p[3*4] = { 
    1, 1, 0,
    0, 1, 1,
    1, 1, 1,
    1, 0, 0 };
  int *pin;

  cout << "\n";
  cout << "POLYOMINO_INDEX_TEST\n";
  cout << "  C++ version\n";
  cout << "  POLYOMINO_INDEX assigns an index to each nonzero entry\n";
  cout << "  of a polyomino.\n";

  polyomino_print ( m, n, p, "  The polyomino P:" );

  pin = polyomino_index ( m, n, p );

  cout << "\n";
  cout << "  PIN: Index vector for P:\n";
  cout << "\n";
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      cout << " " << pin[i+j*m];
    }
    cout << "\n";
  }
//
//  Free memory.
//
  delete [] pin;
//
//  Terminate.
//
  cout << "\n";
  cout << "POLYOMINO_INDEX_TEST\n";
  cout << "  Normal end of execution.\n";

  return;
}
//****************************************************************************80

void polyomino_lp_write_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_LP_WRITE_TEST tests POLYOMINO_LP_WRITE.
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
{
  int *a;
  int *b;
  string filename = "reid.lp";
  string label = "\\ LP file for the Reid example, created by POLYOMINO_LP_WRITE.";
  int m;
  int n;

  cout << "\n";
  cout << "POLYOMINO_LP_WRITE_TEST:\n";
  cout << "  C++ version\n";
  cout << "  POLYOMINO_LP_WRITE writes an LP file associated\n";
  cout << "  with a binary programming problem for tiling a region\n";
  cout << "  with copies of a single polyomino.\n";
//
//  Get the coefficients and right hand side for the Reid system.
//
  polyomino_monohedral_example_reid_size ( m, n );

  a = new int[m*n];
  b = new int[m];

  polyomino_monohedral_example_reid_system ( m, n, a, b );
//
//  Create the LP file.
//
  polyomino_lp_write ( filename, label, m, n, a, b );

  cout << "\n";
  cout << "  Created the LP file '" << filename << "'\n";
//
//  Free memory.
//
  delete [] a;
  delete [] b;
//
//  Terminate.
//
  cout << "\n";
  cout << "POLYOMINO_LP_WRITE_TEST:\n";
  cout << "  Normal end of execution.\n";

  return;
}
//****************************************************************************80

void polyomino_monohedral_example_reid_size ( int &m, int &n )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_MONOHEDRAL_EXAMPLE_REID_SIZE returns the size of the Reid system.
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
//    Output, int &M, &N, the number of equations and variables.
//
{
  m = 9;
  n = 10;

  return;
}
//****************************************************************************80

void polyomino_monohedral_example_reid_system ( int m, int n, int a[], int b[] )

//****************************************************************************80
/*
  Purpose:

    POLYOMINO_MONOHEDRAL_EXAMPLE_REID_SYSTEM sets up the Reid linear system.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    17 May 2018

  Author:

    John Burkardt

  Parameters:

    Output, double A[9*10], the system matrix.

    Output, double B[9], the right hand side.
*/
{
/*
  Note that the matrix is specified in column major form.
*/
  int a_save[9*10] = {
    1,1,0,0,0,0,0,0,2,
    0,0,1,1,0,0,0,0,2,
    0,0,0,1,1,0,0,0,2,
    0,0,0,0,0,1,1,0,2,
    0,0,0,0,0,0,1,1,2,
    1,0,1,0,0,0,0,0,2,
    0,1,0,1,0,0,0,0,2,
    0,0,1,0,0,1,0,0,2,
    0,0,0,1,0,0,1,0,2,
    0,0,0,0,1,0,0,1,2};

  int b_save[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 8 };
 
  i4mat_copy ( 9, 10, a_save, a );
  i4vec_copy ( 9, b_save, b );

  return;
}
//****************************************************************************80

void polyomino_transform_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    POLYOMINO_TRANSFORM_TEST tests POLYOMINO_TRANSFORM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 April 2018
//
//  Author:
//
//    John Burkardt
//
//  Local parameters:
//
//    Local, int M, N, the number of rows and columns in the representation
//    of the polyomino P.
//
//    Local, int P[M*N], a matrix of 0's and 1's representing the 
//    polyomino.  The matrix should be "tight", that is, there should be a
//    1 in row 1, and in column 1, and in row M, and in column N.
//
{
  string label;
  int m = 3;
  int mq;
  int n = 3;
  int nq;
//
//  P is given by columns, not rows.
//
  int p[3*3] = { 
    0, 1, 0,
    1, 1, 1,
    1, 0, 0 }; 
  int *q;
  int reflect;
  int rotate;

  cout << "\n";
  cout << "POLYOMINO_TRANSFORM_TEST:\n";
  cout << "  C++ version\n";
  cout << "  POLYOMINO_TRANSFORM can transform a polyomino.\n";
  cout << "  Generate all 8 combinations of rotation and reflection\n";
  cout << "  applied to a polyomino represented by a binary matrix.\n";

  polyomino_print ( m, n, p, "  The given polyomino P:" );

  for ( reflect = 0; reflect <= 1; reflect ++ )
  {
    for ( rotate = 0; rotate <= 3; rotate++ )
    {
      polyomino_transform ( m, n, p, rotate, reflect, mq, nq, &q );
      
      label = "  P after " + to_string ( reflect ) + " reflections and " + to_string ( rotate ) + " rotations:";

      polyomino_print ( mq, nq, q, label );
      delete [] q;
    }
  }
//
//  Terminate.
//
  cout << "\n";
  cout << "POLYOMINO_TRANSFORM_TEST:\n";
  cout << "  Normal end of execution.\n";

  return;
}
