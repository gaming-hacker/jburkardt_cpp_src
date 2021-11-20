# include <cmath>
# include <ctime>
# include <iomanip>
# include <iostream>

# include <Accelerate/Accelerate.h>

using namespace std;

int main ( );
void dgemm_test ( );
void dtrmm_test ( );
void dtrsm_test ( );
void r8mat_print ( int m, int n, double a[], string title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, string title );
double *r8mat_test ( char trans, int lda, int m, int n );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for BLAS_OSX_TEST.
//
//  Discussion:
//
//    BLAS_OSX_TEST tests the BLAS library on Macintosh OSX.
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
  cout << "BLAS_OSX_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the BLAS library on Macintosh OSX.\n";

  dgemm_test ( );
  dtrmm_test ( );
  dtrsm_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "BLAS_OSX_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void dgemm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DGEMM_TEST tests DGEMM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 February 2014
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double alpha;
  double *b;
  double beta;
  double *c;
  int k;
  int lda;
  int ldb;
  int ldc;
  int m;
  int n;
  char transa;
  char transb;
  char transc;

  cout << "\n";
  cout << "DGEMM_TEST\n";
  cout << "  DGEMM carries out matrix multiplications\n";
  cout << "  for double precision real matrices.\n";
  cout << "\n";
  cout << "  1: C = alpha * A  * B  + beta * C;\n";
  cout << "  2: C = alpha * A' * B  + beta * C;\n";
  cout << "  3: C = alpha * A  * B' + beta * C;\n";
  cout << "  4: C = alpha * A' * B' + beta * C;\n";
  cout << "\n";
  cout << "  We carry out all four calculations, but in each case,\n";
  cout << "  we choose our input matrices so that we get the same result.\n";
//
//  C = alpha * A * B + beta * C.
//
  transa = 'N';
  transb = 'N';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = m;
  a = r8mat_test ( transa, lda, m, k );
  ldb = k;
  b = r8mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r8mat_test ( transc, ldc, m, n );

  cblas_dgemm ( CblasColMajor, CblasNoTrans, CblasNoTrans, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r8mat_print ( m, n, c, "  C = alpha * A * B + beta * C:" );

  delete [] a;
  delete [] b;
  delete [] c;
//
//  C = alpha * A' * B + beta * C.
//
  transa = 'T';
  transb = 'N';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = k;
  a = r8mat_test ( transa, lda, m, k );
  ldb = k;
  b = r8mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r8mat_test ( transc, ldc, m, n );

  cblas_dgemm ( CblasColMajor, CblasTrans, CblasNoTrans, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r8mat_print ( m, n, c, "  C = alpha * A' * B + beta * C:" );

  delete [] a;
  delete [] b;
  delete [] c;
//
//  C = alpha * A * B' + beta * C.
//
  transa = 'N';
  transb = 'T';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = m;
  a = r8mat_test ( transa, lda, m, k );
  ldb = n;
  b = r8mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r8mat_test ( transc, ldc, m, n );

  cblas_dgemm ( CblasColMajor, CblasNoTrans, CblasTrans, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r8mat_print ( m, n, c, "  C = alpha * A * B' + beta * C:" );

  delete [] a;
  delete [] b;
  delete [] c;
//
//  C = alpha * A' * B' + beta * C.
//
  transa = 'T';
  transb = 'T';
  transc = 'N';
  m = 4;
  n = 5;
  k = 3;
  alpha = 2.0;
  lda = k;
  a = r8mat_test ( transa, lda, m, k );
  ldb = n;
  b = r8mat_test ( transb, ldb, k, n );
  beta = 3.0;
  ldc = m;
  c = r8mat_test ( transc, ldc, m, n );

  cblas_dgemm (  CblasColMajor, CblasTrans, CblasTrans,  m, n, k, alpha, a, lda, b, ldb, beta, c, ldc );

  r8mat_print ( m, n, c, "  C = alpha * A' * B' + beta * C:" );

  delete [] a;
  delete [] b;
  delete [] c;

  return;
}
//****************************************************************************80

void dtrmm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DTRMM_TEST tests DTRMM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2014
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double alpha;
  double *b;
  char diag;
  int i;
  int j;
  int lda;
  int ldb;
  int m;
  int n;
  char transa;
  char transb;

  cout << "\n";
  cout << "DTRMM_TEST\n";
  cout << "  DTRMM multiplies a triangular matrix A and a\n";
  cout << "  rectangular matrix B\n";
  cout << "\n";
  cout << "  1: B = alpha * A  * B;\n";
  cout << "  2: B = alpha * A' * B;\n";
//
//  B = alpha * A * B.
//
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = ( double * ) malloc ( lda * m * sizeof ( double ) );
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( double ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r8mat_test ( transb, ldb, m, n );

  cblas_dtrmm ( CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, m, n, alpha, a, lda, b, ldb );

  r8mat_print ( m, n, b, "  B = alpha * A * B:" );

  delete [] a;
  delete [] b;
//
//  B = alpha * A' * B.
//
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = ( double * ) malloc ( lda * m * sizeof ( double ) );
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( double ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r8mat_test ( transb, ldb, m, n );

  cblas_dtrmm ( CblasColMajor, CblasLeft, CblasUpper, CblasTrans, CblasNonUnit, m, n, alpha, a, lda, b, ldb );

  r8mat_print ( m, n, b, "  B = alpha * A' * B:" );
  
  delete [] a;
  delete [] b;

  return;
}
//****************************************************************************80

void dtrsm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    DTRSM_TEST tests DTRSM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    07 April 2014
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double alpha;
  double *b;
  char diag;
  int i;
  int j;
  int lda;
  int ldb;
  int m;
  int n;
  char transa;
  char transb;

  cout << "\n";
  cout << "DTRSM_TEST\n";
  cout << "  DTRSM solves a linear system involving a triangular\n";
  cout << "  matrix A and a rectangular matrix B.\n";
  cout << "\n";
  cout << "  1: Solve A  * X  = alpha * B;\n";
  cout << "  2: Solve A' * X  = alpha * B;\n";
  cout << "  3: Solve X  * A  = alpha * B;\n";
  cout << "  4: Solve X  * A' = alpha * B;\n";
//
//  Solve A * X = alpha * B.
//
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = ( double * ) malloc ( lda * m * sizeof ( double ) );

  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( double ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r8mat_test ( transb, ldb, m, n );

  cblas_dtrsm ( CblasColMajor, CblasLeft, CblasUpper, CblasNoTrans, CblasNonUnit, m, n, alpha, a, lda, b, ldb );

  r8mat_print ( m, n, b, "  X = inv ( A ) * alpha * B:" );

  delete [] a;
  delete [] b;
//
//  Solve A' * X = alpha * B.
//
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = m;
  ldb = m;

  a = ( double * ) malloc ( lda * m * sizeof ( double ) );
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( double ) ( i + j + 2 );
    }
    for ( i = j + 1; i < m; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r8mat_test ( transb, ldb, m, n );

  cblas_dtrsm ( CblasColMajor, CblasLeft, CblasUpper, CblasTrans, CblasNonUnit, m, n, alpha, a, lda, b, ldb );

  r8mat_print ( m, n, b, "  X = inv ( A' ) * alpha * B:" );

  delete [] a;
  delete [] b;
/*
  Solve X * A = alpha * B.
*/
  transa = 'N';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = n;
  ldb = m;

  a = ( double * ) malloc ( lda * n * sizeof ( double ) );
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( double ) ( i + j + 2 );
    }
    for ( i = j + 1; i < n; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r8mat_test ( transb, ldb, m, n );

  cblas_dtrsm ( CblasColMajor, CblasRight, CblasUpper, CblasNoTrans, CblasNonUnit, m, n, alpha, a, lda, b, ldb );

  r8mat_print ( m, n, b, "  X = alpha * B * inv ( A ):" );

  delete [] a;
  delete [] b;
//
//  Solve X * A'' = alpha * B.
//
  transa = 'T';
  diag = 'N';
  m = 4;
  n = 5;
  alpha = 2.0;
  lda = n;
  ldb = m;

  a = ( double * ) malloc ( lda * n * sizeof ( double ) );
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i <= j; i++ )
    {
      a[i+j*lda] = ( double ) ( i + j + 2 );
    }
    for ( i = j + 1; i < n; i++ )
    {
      a[i+j*lda] = 0.0;
    }
  }

  transb = 'N';
  b = r8mat_test ( transb, ldb, m, n );

  cblas_dtrsm (  CblasColMajor, CblasRight, CblasUpper, CblasTrans, CblasNonUnit, m, n, alpha, a, lda, b, ldb );

  r8mat_print ( m, n, b, "  X = alpha * B * inv ( A' ):" );

  delete [] a;
  delete [] b;

  return;
}
//****************************************************************************80

void r8mat_print ( int m, int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT prints an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//    Entry A(I,J) is stored as A[I+J*M]
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    10 September 2009
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
//    Input, double A[M*N], the M by N matrix.
//
//    Input, string TITLE, a title.
//
{
  r8mat_print_some ( m, n, a, 1, 1, m, n, title );

  return;
}
//****************************************************************************80

void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, string title )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT_SOME prints some of an R8MAT.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 June 2013
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
//    Input, double A[M*N], the matrix.
//
//    Input, int ILO, JLO, IHI, JHI, designate the first row and
//    column, and the last row and column to be printed.
//
//    Input, string TITLE, a title.
//
{
# define INCX 5

  int i;
  int i2hi;
  int i2lo;
  int j;
  int j2hi;
  int j2lo;

  cout << "\n";
  cout << title << "\n";

  if ( m <= 0 || n <= 0 )
  {
    cout << "\n";
    cout << "  (None)\n";
    return;
  }
//
//  Print the columns of the matrix, in strips of 5.
//
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    if ( n < j2hi )
    {
      j2hi = n;
    }
    if ( jhi < j2hi )
    {
      j2hi = jhi;
    }
    cout << "\n";
//
//  For each column J in the current range...
//
//  Write the header.
//
    cout << "  Col:    ";
    for ( j = j2lo; j <= j2hi; j++ )
    {
      cout << setw(7) << j - 1 << "       ";
    }
    cout << "\n";
    cout << "  Row\n";
    cout << "\n";
//
//  Determine the range of the rows in this strip.
//
    if ( 1 < ilo )
    {
      i2lo = ilo;
    }
    else
    {
      i2lo = 1;
    }
    if ( ihi < m )
    {
      i2hi = ihi;
    }
    else
    {
      i2hi = m;
    }

    for ( i = i2lo; i <= i2hi; i++ )
    {
//
//  Print out (up to) 5 entries in row I, that lie in the current strip.
//
      cout << setw(5) << i - 1 << ": ";
      for ( j = j2lo; j <= j2hi; j++ )
      {
        cout << setw(12) << a[i-1+(j-1)*m] << "  ";
      }
      cout << "\n";
    }
  }

  return;
# undef INCX
}
//****************************************************************************80

double *r8mat_test ( char trans, int lda, int m, int n )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_TEST sets up a test matrix.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//  
//  Modified:
//
//    10 February 2014
//
//  Author:
//
//    John Burkardt.
//
//  Parameters:
//
//    Input, char TRANS, indicates whether matrix is to be transposed.
//    'N', no transpose.
//    'T', transpose the matrix.
//
//    Input, int LDA, the leading dimension of the matrix.
//
//    Input, int M, N, the number of rows and columns of the matrix.
//
//    Output, double R8MAT_TEST[?], the matrix.
//    if TRANS is 'N', then the matrix is stored in LDA*N entries,
//    as an M x N matrix;
//    if TRANS is 'T', then the matrix is stored in LDA*M entries,
//    as an N x M matrix.
//
{
  double *a;
  int i;
  int j;

  if ( trans == 'N' )
  {
    a = new double[lda*n];

    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        a[i+j*lda] = ( double ) ( 10 * ( i + 1 ) + ( j + 1 ) );
      }
    }
  }
  else
  {
    a = new double[lda*m];

    for ( j = 0; j < n; j++ )
    {
      for ( i = 0; i < m; i++ )
      {
        a[j+i*lda] = ( double ) ( 10 * ( i + 1 ) + ( j + 1 ) );
      }
    }
  }
  return a;
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

