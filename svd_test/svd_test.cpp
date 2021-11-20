# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <ctime>
# include <cstring>

using namespace std;

# include "linpack_d.hpp"
# include "blas1_d.hpp"
# include "blas0.hpp"

int main ( int argc, char *argv[] );
unsigned long get_seed ( );
double *pseudo_inverse ( int m, int n, double u[], double s[], 
  double v[] );
void pseudo_linear_solve_test ( int m, int n, double a[], 
  double a_pseudo[], int *seed );
void pseudo_product_test ( int m, int n, double a[], double a_pseudo[] );
int r8_nint ( double x );
double r8mat_dif_fro ( int m, int n, double a[], double b[] );
double r8mat_norm_fro ( int m, int n, double a[] );
void r8mat_svd_linpack ( int m, int n, double a[], double u[], double s[], 
  double v[] );
double *r8mat_uniform_01_new ( int m, int n, int *seed );
double r8vec_norm_l2 ( int n, double a[] );
double *r8vec_uniform_01_new ( int n, int *seed );
void rank_one_print_test ( int m, int n, double a[], double u[], 
  double s[], double v[] );
void rank_one_test ( int m, int n, double a[], double u[], double s[], 
  double v[] );
int s_len_trim ( char *s );
void svd_product_test ( int m, int n, double a[], double u[], 
  double s[], double v[] );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for SVD_TEST.
//
//  Discussion:
//
//    SVD_TEST demonstrates the singular value decomposition.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 September 2006
//
//  Author:
//
//    John Burkardt
//
//  Usage:
//
//    svd_test m n
//
//  Command Parameters:
//
//    Command parameter, integer M, N, the number of rows and columns
//    of the matrix.
//
//  Local Parameters:
//
//    Local, double A[M*N], the matrix whose singular value
//    decomposition we are investigating.
//
//    Local, double S[M*N], the diagonal factor
//    in the singular value decomposition of A.
//
//    Local, int SEED, a seed used to define the random number generator.
//
//    Output, double U[M*M], the first orthogonal factor
//    in the singular value decomposition of A.
//
//    Output, double V[N*N], the second orthogonal factor
//    in the singular value decomposition of A.
//
{
  double *a;
  double *a_pseudo;
  int i;
  int j;
  int m;
  int n;
  double *s;
  int seed;
  char string[80];
  double *u;
  double *v;

  timestamp ( );

  cout << "\n";
  cout << "SVD_TEST:\n";
  cout << "  C++ version\n";
  cout << "\n";
  cout << "  Compiled on " << __DATE__ << " at " << __TIME__ << ".\n";
  cout << "\n";
  cout << "  Demonstrate the singular value decomposition (SVD)\n";
  cout << "\n";
  cout << "  A real MxN matrix A can be factored as:\n";
  cout << "\n";
  cout << "    A = U * S * V'\n";
  cout << "\n";
  cout << "  where\n";
  cout << "\n";
  cout << "    U = MxM orthogonal,\n";
  cout << "    S = MxN zero except for diagonal,\n";
  cout << "    V = NxN orthogonal.\n";
  cout << "\n";
  cout << "  The diagonal of S contains only nonnegative numbers\n";
  cout << "  and these are arranged in descending order.\n";
//
//  If M was not on the command line, get it now.
//
  if ( argc < 2 ) 
  {
    cout << "\n";
    cout << "SVD_TEST:\n";
    cout << "  Please enter the value of M:\n";
    cout << "  (Number of rows in matrix A).\n";
    cout << "  (We prefer M <= 10!).\n";

    cin.getline ( string, sizeof ( string ) );
  }
  else 
  {
    strcpy ( string, argv[1] );
  }
  m = atoi ( string );
  cout << "\n";
  cout << "  Matrix row order    M = " << m << "\n";
//
//  If N was not on the command line, get it now.
//
  if ( argc < 3 ) 
  {
    cout << "\n";
    cout << "SVD_TEST:\n";
    cout << "  Please enter the value of N:\n";
    cout << "  (Number of columns in matrix A).\n";
    cout << "  (We prefer N <= 10!).\n";

    cin.getline ( string, sizeof ( string ) );
  }
  else 
  {
    strcpy ( string, argv[2] );
  }
  n = atoi ( string );
  cout << "  Matrix column order N = " << n << "\n";
//
//  If SEED was not on the command line, use GET_SEED.
//
  if ( argc < 4 ) 
  {
    seed = get_seed ( );
    cout << "  Random number SEED    = " << seed << "\n";
    cout << "  (Chosen by the program.)\n";
  }
  else 
  {
    strcpy ( string, argv[3] );
    seed = atoi ( string );
    cout << "  Random number SEED    = " << seed << "\n";
    cout << "  (Chosen by the user.)\n";
  }
//
//  Set aside space for the arrays.
//
  u = new double[m*m];
  s = new double[m*n];
  v = new double[n*n];
//
//  Generate the matrix.
//
  cout << "\n";
  cout << "  We choose a \"random\" matrix A, with integral\n";
  cout << "  values between 0 and 10.\n";

  a = r8mat_uniform_01_new ( m, n, &seed );

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+m*j] = r8_nint ( 10.0 * a[i+m*j] );
    }
  }
  r8mat_print ( m, n, a, "  The matrix A:\n" );
//
//  Get the SVD from LINPACK.
//
  r8mat_svd_linpack ( m, n, a, u, s, v );
//
//  Print the SVD.
//
  r8mat_print ( m, m, u, "  The orthogonal factor U:" );

  r8mat_print ( m, n, s, "  The diagonal factor S:" );

  r8mat_print ( n, n, v, "  The orthogonal factor V:" );
//
//  Check that A = U * S * V'.
//
  svd_product_test ( m, n, a, u, s, v );
//
//  Compute the norm of the difference between A and the successive
//  sums of rank one approximants.
//
  rank_one_test ( m, n, a, u, s, v );
//
//  Actually print the sums of rank one approximants.
//
  rank_one_print_test ( m, n, a, u, s, v );
//
//  Compute the pseudoinverse.
//
  a_pseudo = pseudo_inverse ( m, n, u, s, v );

  r8mat_print ( n, m, a_pseudo, "  The pseudoinverse of A:" );
//
//  Test A*A+ = I+, A+*A = I+
//
  pseudo_product_test ( m, n, a, a_pseudo );
//
//  Demonstrate the use of the pseudoinverse for linear systems.
//
  pseudo_linear_solve_test ( m, n, a, a_pseudo, &seed );
//
//  Free memory.
//
  delete [] a;
  delete [] a_pseudo;
  delete [] s;
  delete [] u;
  delete [] v;
//
//  Terminate.
//
  cout << "\n";
  cout << "SVD_TEST:\n";
  cout << "  Normal end of execution.\n";

  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

unsigned long get_seed ( )

//****************************************************************************80
//
//  Purpose:
//
//    GET_SEED returns a random seed for the random number generator.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    17 September 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, unsigned long GET_SEED, a random seed value.
//
{
# define UNSIGNED_LONG_MAX 4294967295UL

  time_t clock;
  int hours;
  int minutes;
  int seconds;
  struct tm *lt;
  static unsigned long seed = 0;
  time_t tloc;
//
//  If the internal seed is 0, generate a value based on the time.
//
  if ( seed == 0 )
  {
    clock = time ( &tloc );
    lt = localtime ( &clock );
//
//  Extract HOURS.
//
    hours = lt->tm_hour;
//
//  In case of 24 hour clocks, shift so that HOURS is between 1 and 12.
//
    if ( 12 < hours )
    {
      hours = hours - 12;
    }
//
//  Move HOURS to 0, 1, ..., 11
//
    hours = hours - 1;

    minutes = lt->tm_min;

    seconds = lt->tm_sec;

    seed = seconds + 60 * ( minutes + 60 * hours );
//
//  We want values in [1,43200], not [0,43199].
//
    seed = seed + 1;
//
//  Remap SEED from [1,43200] to [1,UNSIGNED_LONG_MAX].
//
    seed = ( unsigned long ) 
      ( ( ( double ) seed )
      * ( ( double ) UNSIGNED_LONG_MAX ) / ( 60.0 * 60.0 * 12.0 ) );
  }
//
//  Never use a seed of 0.
//
  if ( seed == 0 )
  {
    seed = 1;
  }

  return seed;

# undef UNSIGNED_LONG_MAX
}
//****************************************************************************80

double *pseudo_inverse ( int m, int n, double u[], double s[], 
  double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    PSEUDO_INVERSE computes the pseudoinverse.
//
//  Discussion:
//
//    Given the singular value decomposition of a real MxN matrix A:
//
//      A = U * S * V'
//
//    where 
//
//      U is MxM orthogonal,
//      S is MxN, and entirely zero except for the diagonal;
//      V is NxN orthogonal.
//
//    the pseudo inverse is the NxM matrix A+ with the form
//
//      A+ = V * S+ * U'
//
//    where 
//
//      S+ is the NxM matrix whose nonzero diagonal elements are
//      the inverses of the corresponding diagonal elements of S.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 September 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix A.
//
//    Input, double A[M*N], the matrix whose singular value
//    decomposition we are investigating.
//
//    Input, double U[M*M], S[M*N], V[N*N], the factors
//    that form the singular value decomposition of A.
//
//    Output, double PSEUDO_INVERSE[N*M], the pseudo_inverse of A.
//
{
  double *a_pseudo;
  int i;
  int j;
  int k;
  double *sp;
  double *sput;

  sp = new double[n*m];
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      if ( i == j && s[i+i*m] != 0.0 )
      {
        sp[i+j*n] = 1.0 / s[i+i*m];
      }
      else
      {
        sp[i+j*n] = 0.0;
      }
    }
  }

  sput = new double[n*m];
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < m; j++ )
    {
      sput[i+j*n] = 0.0;
      for ( k = 0; k < m; k++ )
      {
        sput[i+j*n] = sput[i+j*n] + sp[i+k*n] * u[j+k*m];
      }
    }
  }

  a_pseudo = new double[n*m];
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < m; j++ )
    {
      a_pseudo[i+j*n] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        a_pseudo[i+j*n] = a_pseudo[i+j*n] + v[i+k*n] * sput[k+j*n];
      }
    }
  }

  delete [] sp;

  return a_pseudo;
}
//****************************************************************************80

void pseudo_linear_solve_test ( int m, int n, double a[], 
  double a_pseudo[], int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    PSEUDO_LINEAR_SOLVE_TEST uses the pseudoinverse for linear systems.
//
//  Discussion:
//
//    Given an MxN matrix A, and its pseudoinverse A+:
//
//      "Solve" A  * x = b by x = A+  * b.
//
//      "Solve" A' * x = b by x = A+' * b.
//
//    When the system is overdetermined, the solution minimizes the
//    L2 norm of the residual.  
//
//    When the system is underdetermined, the solution
//    is the solution of minimum L2 norm.     
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    15 September 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix A.
//
//    Input, double A[M*N], the matrix whose singular value
//    decomposition we are investigating.
//
//    Input, double A_PSEUDO[N*M], the pseudo_inverse of A.
//
//    Input/output, int *SEED, a seed for the random number generator.
//
{
  double *bm;
  double *bn;
  int i;
  int j;
  double *rm;
  double *rn;
  double *xm1;
  double *xm2;
  double *xn1;
  double *xn2;

  cout << "\n";
  cout << "PSEUDO_LINEAR_SOLVE_TEST\n";
//
//  A * x = b, b in range of A.
//
  xn1 = r8vec_uniform_01_new ( n, seed );
  for ( i = 0; i < n; i++ )
  {
    xn1[i] = r8_nint ( 10.0 * xn1[i] );
  }

  bm = new double[m];
  for ( i = 0; i < m; i++ )
  {
    bm[i] = 0.0;
    for ( j = 0; j < n; j++ )
    {
      bm[i] = bm[i] + a[i+j*m] * xn1[j];
    }
  }

  xn2 = new double[n];
  for ( i = 0; i < n; i++ )
  {
    xn2[i] = 0.0;
    for ( j = 0; j < m; j++ )
    {
      xn2[i] = xn2[i] + a_pseudo[i+j*n] * bm[j];
    }
  }

  rm = new double[m];
  for ( i = 0; i < m; i++ )
  {
    rm[i] = bm[i];
    for ( j = 0; j < n; j++ )
    {
      rm[i] = rm[i] - a[i+j*m] * xn2[j];
    }
  }

  cout << "\n";
  cout << "  Given:\n";
  cout << "    b = A * x1\n";
  cout << "  so that b is in the range of A, solve\n";
  cout << "    A * x = b\n";
  cout << "  using the pseudoinverse:\n";
  cout << "    x2 = A+ * b.\n";
  cout << "\n";
  cout << "  Norm of x1 = " << r8vec_norm_l2 ( n, xn1 ) << "\n";
  cout << "  Norm of x2 = " << r8vec_norm_l2 ( n, xn2 ) << "\n";
  cout << "  Norm of residual = " << r8vec_norm_l2 ( m, rm ) << "\n";

  delete [] bm;
  delete [] rm;
  delete [] xn1;
  delete [] xn2;
//
//  A * x = b, b not in range of A.
//
  if ( n < m )
  {
    cout << "\n";
    cout << "  For N < M, most systems A*x=b will not be\n";
    cout << "  exactly and uniquely solvable, except in the\n";
    cout << "  least squares sense.\n";
    cout << "\n";
    cout << "  Here is an example:\n";

    bm = r8vec_uniform_01_new ( m, seed );

    xn2 = new double[n];
    for ( i = 0; i < n; i++ )
    {
      xn2[i] = 0.0;
      for ( j = 0; j < m; j++ )
      {
        xn2[i] = xn2[i] + a_pseudo[i+j*n] * bm[j];
      }
    }

    rm = new double[m];
    for ( i = 0; i < m; i++ )
    {
      rm[i] = bm[i];
      for ( j = 0; j < n; j++ )
      {
        rm[i] = rm[i] - a[i+j*m] * xn2[j];
      }
    }

    cout << "\n";
    cout << "  Given b is NOT in the range of A, solve\n";
    cout << "    A * x = b\n";
    cout << "  using the pseudoinverse:\n";
    cout << "    x2 = A+ * b.\n";
    cout << "\n";
    cout << "  Norm of x2 = " << r8vec_norm_l2 ( n, xn2 ) << "\n";
    cout << "  Norm of residual = " << r8vec_norm_l2 ( m, rm ) << "\n";

    delete [] bm;
    delete [] rm;
    delete [] xn2;
  }
//
//  A' * x = b, b is in the range of A'.
//
  xm1 = r8vec_uniform_01_new ( m, seed );
  for ( i = 0; i < m; i++ )
  {
    xm1[i] = r8_nint ( 10.0 * xm1[i] );
  }

  bn = new double[n];
  for ( i = 0; i < n; i++ )
  {
    bn[i] = 0.0;
    for ( j = 0; j < m; j++ )
    {
      bn[i] = bn[i] + a[j+i*m] * xm1[j];
    }
  }

  xm2 = new double[m];
  for ( i = 0; i < m; i++ )
  {
    xm2[i] = 0.0;
    for ( j = 0; j < n; j++ )
    {
      xm2[i] = xm2[i] + a_pseudo[j+i*n] * bn[j];
    }
  }

  rn = new double[n];
  for ( i = 0; i < n; i++ )
  {
    rn[i] = bn[i];
    for ( j = 0; j < m; j++ )
    {
      rn[i] = rn[i] - a[j+i*m] * xm2[j];
    }
  }
  cout << "\n";
  cout << "  Given:\n";
  cout << "    b = A' * x1\n";
  cout << "  so that b is in the range of A', solve\n";
  cout << "    A' * x = b\n";
  cout << "  using the pseudoinverse:\n";
  cout << "    x2 = A+' * b.\n";
  cout << "\n";
  cout << "  Norm of x1 = " << r8vec_norm_l2 ( m, xm1 ) << "\n";
  cout << "  Norm of x2 = " << r8vec_norm_l2 ( m, xm2 ) << "\n";
  cout << "  Norm of residual = " << r8vec_norm_l2 ( n, rn ) << "\n";

  delete [] bn;
  delete [] rn;
  delete [] xm1;
  delete [] xm2;
//
//  A' * x = b, b is not in the range of A'.

  if ( m < n )
  {
    cout << "\n";
    cout << "  For M < N, most systems A'*x=b will not be\n";
    cout << "  exactly and uniquely solvable, except in the\n";
    cout << "  least squares sense.\n";
    cout << "\n";
    cout << "  Here is an example:\n";

    bn = r8vec_uniform_01_new ( n, seed );

    xm2 = new double[m];
    for ( i = 0; i < m; i++ )
    {
      xm2[i] = 0.0;
      for ( j = 0; j < n; j++ )
      {
        xm2[i] = xm2[i] + a_pseudo[j+i*n] * bn[j];
      }
    }

    rn = new double[n];
    for ( i = 0; i < n; i++ )
    {
      rn[i] = bn[i];
      for ( j = 0; j < m; j++ )
      {
        rn[i] = rn[i] - a[j+i*m] * xm2[j];
      }
    }

    cout << "\n";
    cout << "  Given b is NOT in the range of A', solve\n";
    cout << "    A' * x = b\n";
    cout << "  using the pseudoinverse:\n";
    cout << "    x2 = A+ * b.\n";
    cout << "\n";
    cout << "  Norm of x2 = " << r8vec_norm_l2 ( m, xm2 ) << "\n";
    cout << "  Norm of residual = " << r8vec_norm_l2 ( n, rn ) << "\n";

    delete [] bn;
    delete [] rn;
    delete [] xm2;
  }

  return;
}
//****************************************************************************80

void pseudo_product_test ( int m, int n, double a[], double a_pseudo[] )

//****************************************************************************80
//
//  Purpose:
//
//    PSEUDO_PRODUCT_TEST examines pseudoinverse products.
//
//  Discussion:
//
//    Given an MxN matrix A, and its pseudoinverse A+, we must have
//
//      A+ * A * A+ = A+
//      A * A+ * A = A
//      ( A * A+ )' = A * A+ (MxM symmetry)
//      ( A+ * A )' = A+ * A (NxN symmetry)
//
//    If M <= N, A * A+ may be "interesting" (equal to or "like" the identity),
//    if N <= M, A+ * A may be "interesting" (equal to or "like" the identity).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 September 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix A.
//
//    Input, double A[M*N], the matrix whose singular value
//    decomposition we are investigating.
//
//    Input, double A_PSEUDO[N*M], the pseudo_inverse of A.
//
{
  double *bmm;
  double *bmn;
  double *bnm;
  double *bnn;
  double dif1;
  double dif2;
  double dif3;
  double dif4;
  int i;
  int j;
  int k;

  cout << "\n";
  cout << "PSEUDO_PRODUCT_TEST\n";
  cout << "\n";
  cout << "  The following relations MUST hold:\n";
  cout << "\n";
  cout << "   A  * A+ * A  = A\n";
  cout << "   A+ * A  * A+ = A+\n";
  cout << " ( A  * A+ ) is MxM symmetric;\n";
  cout << " ( A+ * A  ) is NxN symmetric\n";
//
//  Compute A * A+ * A.
//
  bnn = new double[n*n];
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      bnn[i+j*n] = 0.0;
      for ( k = 0; k < m; k++ )
      {
        bnn[i+j*n] = bnn[i+j*n] + a_pseudo[i+k*n] * a[k+j*m];
      }
    }
  }
  bmn = new double[m*n];

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      bmn[i+j*m] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        bmn[i+j*m] = bmn[i+j*m] + a[i+k*m] * bnn[k+j*n];
      }
    }
  }
  dif1 = r8mat_dif_fro ( m, n, a, bmn );

  delete [] bmn;
  delete [] bnn;
//
//  Compute A+ * A * A+.
//
  bmm = new double[m*m];
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < m; j++ )
    {
      bmm[i+j*m] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        bmm[i+j*m] = bmm[i+j*m] + a[i+k*m] * a_pseudo[k+j*n];
      }
    }
  }

  bnm = new double[n*m];

  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < m; j++ )
    {
      bnm[i+j*n] = 0.0;
      for ( k = 0; k < m; k++ )
      {
        bnm[i+j*n] = bnm[i+j*n] + a_pseudo[i+k*n] * bmm[k+j*m];
      }
    }
  }

  dif2 = r8mat_dif_fro ( n, m, a_pseudo, bnm );

  delete [] bnm;
  delete [] bmm;
//
//  Compute norm of A * A+ - (A * A+)'.
//
  bmm = new double[m*m];
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < m; j++ )
    {
      bmm[i+j*m] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        bmm[i+j*m] = bmm[i+j*m] + a[i+k*m] * a_pseudo[k+j*n];
      }
    }
  }
  dif3 = 0.0;
  for ( j = 0; j < m; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      dif3 = dif3 + pow ( bmm[i+j*m] - bmm[j+i*m], 2 );
    }
  }
  dif3 = sqrt ( dif3 );

  delete [] bmm;
//
//  Compute norm of A+ * A - (A+ * A)'
//
  bnn = new double[n*n];
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      bnn[i+j*n] = 0.0;
      for ( k = 0; k < m; k++ )
      {
        bnn[i+j*n] = bnn[i+j*n] + a_pseudo[i+k*n] * a[k+j*m];
      }
    }
  }
  dif4 = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < n; i++ )
    {
      dif4 = dif4 + pow ( bnn[i+j*n] - bnn[j+i*n], 2 );
    }
  }
  dif4 = sqrt ( dif4 );

  delete [] bnn;
//
//  Report.
//
  cout << "\n";
  cout << "  Here are the Frobenius norms of the errors\n";
  cout << "  in these relationships:\n";
  cout << "\n";
  cout << "   A  * A+ * A  = A            " << dif1 << "\n";
  cout << "   A+ * A  * A+ = A+           " << dif2 << "\n";
  cout << " ( A  * A+ ) is MxM symmetric; " << dif3 << "\n";
  cout << " ( A+ * A  ) is NxN symmetric; " << dif4 << "\n";

  cout << "\n";
  cout << "  In some cases, the matrix A * A+\n";
  cout << "  may be interesting (if M <= N, then\n";
  cout << "  it MIGHT look like the identity.)\n";
  cout << "\n";
  bmm = new double[m*m];
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < m; j++ )
    {
      bmm[i+j*m] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        bmm[i+j*m] = bmm[i+j*m] + a[i+k*m] * a_pseudo[k+j*n];
      }
    }
  }
  r8mat_print ( m, m, bmm, "  A * A+:" );

  delete [] bmm;

  cout << "\n";
  cout << "  In some cases, the matrix A+ * A\n";
  cout << "  may be interesting (if N <= M, then\n";
  cout << "  it MIGHT look like the identity.)\n";
  cout << "\n";

  bnn = new double[n*n];
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      bnn[i+j*n] = 0.0;
      for ( k = 0; k < m; k++ )
      {
        bnn[i+j*n] = bnn[i+j*n] + a_pseudo[i+k*n] * a[k+j*m];
      }
    }
  }

  r8mat_print ( n, n, bnn, "  A+ * A" );

  delete [] bnn;

  return;
}
//****************************************************************************80

int r8_nint ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    R8_NINT returns the nearest integer to a double precision value.
//
//  Example:
//
//        X         R8_NINT
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

double r8mat_dif_fro ( int m, int n, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_DIF_FRO returns the Frobenius norm of the difference of R8MAT's.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    The Frobenius norm is defined as
//
//      R8MAT_NORM_FRO = sqrt (
//        sum ( 1 <= I <= M ) sum ( 1 <= j <= N ) A(I,J)^2 )
//
//    The matrix Frobenius norm is not derived from a vector norm, but
//    is compatible with the vector L2 norm, so that:
//
//      r8vec_norm_l2 ( A * x ) <= r8mat_norm_fro ( A ) * r8vec_norm_l2 ( x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 September 2006
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
//    Input, double A[M*N], double B[M*N], the matrices for which we
//    want the Frobenius norm of the difference.
//
//    Output, double R8MAT_DIF_FRO, the Frobenius norm of ( A - B ).
//
{
  int i;
  int j;
  double value;

  value = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      value = value + pow ( a[i+j*m] - b[i+j*m], 2 );
    }
  }
  value = sqrt ( value );

  return value;
}
//****************************************************************************80

double r8mat_norm_fro ( int m, int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_NORM_FRO returns the Frobenius norm of a R8MAT.
//
//  Discussion: 							    
//
//    An R8MAT is a doubly dimensioned array of double precision values, which
//    may be stored as a vector in column-major order.
//
//    The Frobenius norm is defined as
//
//      R8MAT_NORM_FRO = sqrt (
//        sum ( 1 <= I <= M ) sum ( 1 <= j <= N ) A(I,J)^2 )
//
//    The matrix Frobenius norm is not derived from a vector norm, but
//    is compatible with the vector L2 norm, so that:
//
//      r8vec_norm_l2 ( A * x ) <= r8mat_norm_fro ( A ) * r8vec_norm_l2 ( x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 October 2005
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
//    Input, double A[M*N], the matrix whose Frobenius
//    norm is desired.
//
//    Output, double R8MAT_NORM_FRO, the Frobenius norm of A.
//
{
  int i;
  int j;
  double value;

  value = 0.0;
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      value = value + pow ( a[i+j*m], 2 );
    }
  }
  value = sqrt ( value );

  return value;
}
//****************************************************************************80

void r8mat_svd_linpack ( int m, int n, double a[], double u[], double s[], 
  double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_SVD_LINPACK gets the SVD of a matrix using a call to LINPACK.
//
//  Discussion:
//
//    The singular value decomposition of a real MxN matrix A has the form:
//
//      A = U * S * V'
//
//    where 
//
//      U is MxM orthogonal,
//      S is MxN, and entirely zero except for the diagonal;
//      V is NxN orthogonal.
//
//    Moreover, the nonzero entries of S are positive, and appear
//    in order, from largest magnitude to smallest.
//
//    This routine calls the LINPACK routine DSVDC to compute the
//    factorization.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 September 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix A.
//
//    Input, double A[M*N], the matrix whose singular value
//    decomposition we are investigating.
//
//    Output, double U[M*M], S[M*N], V[N*N], the factors
//    that form the singular value decomposition of A.
//
{
  double *a_copy;
  double *e;
  int i;
  int info;
  int j;
  int lda;
  int ldu;
  int ldv;
  int job;
  double *sdiag;
  double *work;
//
//  The correct size of E and SDIAG is min ( m+1, n).
//
  a_copy = new double[m*n];
  e = new double[m+n];
  sdiag = new double[m+n];
  work = new double[m];
//
//  Compute the eigenvalues and eigenvectors.
//
  job = 11;
  lda = m;
  ldu = m;
  ldv = n;
//
//  The input matrix is destroyed by the routine.  Since we need to keep
//  it around, we only pass a copy to the routine.
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    { 
      a_copy[i+j*m] = a[i+j*m];
    }
  }
  info = dsvdc ( a_copy, lda, m, n, sdiag, e, u, ldu, v, ldv, work, job );
 
  if ( info != 0 )
  {
    cout << "\n";
    cout << "R8MAT_SVD_LINPACK - Failure!\n";
    cout << "  The SVD could not be calculated.\n";
    cout << "  LINPACK routine DSVDC returned a nonzero\n";
    cout << "  value of the error flag, INFO = " << info << "\n";
    return;
  }
//
//  Make the MxN matrix S from the diagonal values in SDIAG.
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      if ( i == j )
      {
        s[i+j*m] = sdiag[i];
      }
      else
      {
        s[i+j*m] = 0.0;
      }
    }
  }
//
//  Note that we do NOT need to transpose the V that comes out of LINPACK!
//
  delete [] a_copy;
  delete [] e;
  delete [] sdiag;
  delete [] work;

  return;
}
//****************************************************************************80

double *r8mat_uniform_01_new ( int m, int n, int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_UNIFORM_01_NEW returns a unit pseudorandom R8MAT.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = 16807 * seed mod ( 2^31 - 1 )
//      unif = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Springer Verlag, pages 201-202, 1983.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, pages 362-376, 1986.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, pages 136-143, 1969.
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns.
//
//    Input/output, int *SEED, the "seed" value.  Normally, this
//    value should not be 0.  On output, SEED has 
//    been updated.
//
//    Output, double R8MAT_UNIFORM_01_NEW[M*N], a matrix of pseudorandom values.
//
{
  int i;
  int j;
  int k;
  double *r;

  r = new double[m*n];

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      k = *seed / 127773;

      *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

      if ( *seed < 0 )
      {
        *seed = *seed + 2147483647;
      }

      r[i+j*m] = ( double ) ( *seed ) * 4.656612875E-10;
    }
  }

  return r;
}
//****************************************************************************80

double r8vec_norm_l2 ( int n, double a[] )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_NORM_L2 returns the L2 norm of an R8VEC.
//
//  Discussion:
//
//    The vector L2 norm is defined as:
//
//      R8VEC_NORM_L2 = sqrt ( sum ( 1 <= I <= N ) A(I)**2 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    01 March 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of entries in A.
//
//    Input, double A[N], the vector whose L2 norm is desired.
//
//    Output, double R8VEC_NORM_L2, the L2 norm of A.
//
{
  int i;
  double v;

  v = 0.0;

  for ( i = 0; i < n; i++ )
  {
    v = v + a[i] * a[i];
  }
  v = sqrt ( v );

  return v;
}
//****************************************************************************80

double *r8vec_uniform_01_new ( int n, int *seed )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01_NEW returns a unit pseudorandom R8VEC.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = 16807 * seed mod ( 2^31 - 1 )
//      unif = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Springer Verlag, pages 201-202, 1983.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, pages 362-376, 1986.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, pages 136-143, 1969.
//
//  Parameters:
//
//    Input, int N, the number of entries in the vector.
//
//    Input/output, int *SEED, a seed for the random number generator.
//
//    Output, double R8VEC_UNIFORM_01_NEW[N], the vector of pseudorandom values.
//
{
  int i;
  int k;
  double *r;

  r = new double[n];

  for ( i = 0; i < n; i++ )
  {
    k = *seed / 127773;

    *seed = 16807 * ( *seed - k * 127773 ) - k * 2836;

    if ( *seed < 0 )
    {
      *seed = *seed + 2147483647;
    }

    r[i] = ( double ) ( *seed ) * 4.656612875E-10;
  }

  return r;
}
//****************************************************************************80

void rank_one_print_test ( int m, int n, double a[], double u[], 
  double s[], double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    RANK_ONE_PRINT_TEST prints the sums of rank one matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 September 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix A.
//
//    Input, double A[M*N], the matrix whose singular value
//    decomposition we are investigating.
//
//    Input, double U[M*M], S[M*N], V[N*N], the factors
//    that form the singular value decomposition of A.
//
{
  int i;
  int j;
  int k;
  int r;
  double *svt;
  char title[100];
  double *usvt;

//a_norm = r8mat_norm_fro ( m, n, a );

  cout << "\n";
  cout << "RANK_ONE_PRINT_TEST:\n";
  cout << "  Print the sums of R rank one matrices.\n";

  for ( r = 0; r <= i4_min ( m, n ); r++ )
  {
    svt = new double[r*n];
    for ( i = 0; i < r; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        svt[i+j*r] = 0.0;
        for ( k = 0; k < r; k++ )
        {
          svt[i+j*r] = svt[i+j*r] + s[i+k*m] * v[j+k*n];
        }
      }
    }
    usvt = new double[m*n];

    for ( i = 0; i < m; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        usvt[i+j*m] = 0.0;
        for ( k = 0; k < r; k++ )
        { 
          usvt[i+j*m] = usvt[i+j*m] + u[i+k*m] * svt[k+j*r];
        }
      }
    }

    sprintf ( title, "  Rank R = %d", r );
    r8mat_print ( m, n, usvt, title );


    delete [] svt;
    delete [] usvt;
  }

  r8mat_print ( m, n, a, "  Original matrix A:" );

  return;
}
//****************************************************************************80

void rank_one_test ( int m, int n, double a[], double u[], double s[], 
  double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    RANK_ONE_TEST compares A to the sum of rank one matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 September 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix A.
//
//    Input, double A[M*N], the matrix whose singular value
//    decomposition we are investigating.
//
//    Input, double U[M*M], S[M*N], V[N*N], the factors
//    that form the singular value decomposition of A.
//
{
  double a_norm;
  double dif_norm;
  int i;
  int j;
  int k;
  int r;
  double *svt;
  double *usvt;

  a_norm = r8mat_norm_fro ( m, n, a );

  cout << "\n";
  cout << "RANK_ONE_TEST:\n";
  cout << "  Compare A to the sum of R rank one matrices.\n";
  cout << "\n";
  cout << "         R    Absolute      Relative\n";
  cout << "              Error         Error\n";
  cout << "\n";

  for ( r = 0; r <= i4_min ( m, n ); r++ ) 
  {
    svt = new double[r*n];
    for ( i = 0; i < r; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        svt[i+j*r] = 0.0;
        for ( k = 0; k < r; k++ )
        {
          svt[i+j*r] = svt[i+j*r] + s[i+k*m] * v[j+k*n];
        }
      }
    }
    usvt = new double[m*n];

    for ( i = 0; i < m; i++ )
    {
      for ( j = 0; j < n; j++ )
      {
        usvt[i+j*m] = 0.0;
        for ( k = 0; k < r; k++ )
        { 
          usvt[i+j*m] = usvt[i+j*m] + u[i+k*m] * svt[k+j*r];
        }
      }
    }
    dif_norm = r8mat_dif_fro ( m, n, a, usvt );

    cout << "  " << setw(8) << r
         << "  " << setw(14) << dif_norm
         << "  " << setw(14) << dif_norm / a_norm << "\n";

    delete [] svt;
    delete [] usvt;
  }
  return;
}
//****************************************************************************80

int s_len_trim ( char *s )

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
//    26 April 2003
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, char *S, a pointer to a string.
//
//    Output, int S_LEN_TRIM, the length of the string to the last nonblank.
//    If S_LEN_TRIM is 0, then the string is entirely blank.
//
{
  int n;
  char *t;

  n = strlen ( s );
  t = s + strlen ( s ) - 1;

  while ( 0 < n ) 
  {
    if ( *t != ' ' )
    {
      return n;
    }
    t--;
    n--;
  }

  return n;
}
//****************************************************************************80

void svd_product_test ( int m, int n, double a[], double u[], 
  double s[], double v[] )

//****************************************************************************80
//
//  Purpose:
//
//    SVD_PRODUCT_TEST tests that A = U * S * V'.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 September 2006
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int M, N, the number of rows and columns in the matrix A.
//
//    Input, double A[M*N], the matrix whose singular value
//    decomposition we are investigating.
//
//    Input, double U[M*M], S[M*N], V[N*N], the factors
//    that form the singular value decomposition of A.
//
{
  double a_norm;
  double dif_norm;
  int i;
  int j;
  int k;
  double *svt;
  double *usvt;

  a_norm = r8mat_norm_fro ( m, n, a );

  svt = new double[m*n];
  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      svt[i+j*m] = 0.0;
      for ( k = 0; k < n; k++ )
      {
        svt[i+j*m] = svt[i+j*m] + s[i+k*m] * v[j+k*n];
      }
    }
  }
  usvt = new double[m*n];

  for ( i = 0; i < m; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      usvt[i+j*m] = 0.0;
      for ( k = 0; k < m; k++ )
      {
        usvt[i+j*m] = usvt[i+j*m] + u[i+k*m] * svt[k+j*m];
      }
    }
  }

  r8mat_print ( m, n, usvt, "  The product U * S * V':" );

  dif_norm = r8mat_dif_fro ( m, n, a, usvt );

  cout << "\n";
  cout << "  Frobenius Norm of A, A_NORM = " << a_norm << "\n";
  cout << "\n";
  cout << "  ABSOLUTE ERROR for A = U*S*V'\n";
  cout << "  Frobenius norm of difference A-U*S*V' = " << dif_norm << "\n";
  cout << "\n";
  cout << "  RELATIVE ERROR for A = U*S*V':\n";
  cout << "  Ratio of DIF_NORM / A_NORM = " << dif_norm / a_norm << "\n";

  delete [] svt;
  delete [] usvt;

  return;
}

