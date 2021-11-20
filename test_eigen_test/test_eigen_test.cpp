# include <cmath>
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "test_eigen.hpp"

int main ( );
void r8nsymm_gen_test ( );
void r8symm_gen_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for TEST_EIGEN_TEST.
//
//  Discussion:
//
//    TEST_EIGEN_TEST tests the TEST_EIGEN library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "TEST_EIGEN_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the TEST_EIGEN library.\n";

  r8symm_gen_test ( );
  r8nsymm_gen_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "TEST_EIGEN_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void r8symm_gen_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8SYMM_GEN_TEST tests R8SYMM_GEN to make symmetric test matrices.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    20 February 2012
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *aq;
  int *bin;
  double *bin_limit;
  int bin_num = 10;
  int i;
  int j;
  double *lambda;
  double *lambda2;
  double lambda_dev = 1.0;
  double lambda_max;
  double lambda_mean = 1.0;
  double lambda_min;
  int n = 100;
  double *q;
  int seed = 123456789;

  cout << "\n";
  cout << "R8SYMM_GEN_TEST\n";
  cout << "  R8SYMM_GEN generates an arbitrary size symmetric matrix\n";
  cout << "  with known eigenvalues and eigenvectors.\n";

  a = new double[n*n];
  q = new double[n*n];
  lambda = new double[n];

  r8symm_gen ( n, lambda_mean, lambda_dev, &seed, a, q, lambda );
//
//  Get the eigenvalue range.
//
  lambda_min = r8vec_min ( n, lambda );
  lambda_max = r8vec_max ( n, lambda );

  cout << "\n";
  cout << "  LAMBDA_MIN = " << lambda_min << "\n";
  cout << "  LAMBDA_MAX = " << lambda_max << "\n";
//
//  Bin the eigenvalues.
//
  bin = new int[bin_num+2];
  bin_limit = new double[bin_num+1];

  r8vec_bin ( n, lambda, bin_num, lambda_min, lambda_max, bin, bin_limit );

  r8bin_print ( bin_num, bin, bin_limit, "  Lambda bins:" );

  if ( false )
  {
    r8mat_print ( n, n, a, "  The matrix A:" );
  }

  if ( false )
  {
    r8mat_print ( n, n, q, "  The eigenvector matrix Q:" );
  }

  aq = r8mat_mm_new ( n, n, n, a, q );

  lambda2 = new double[n];

  for ( j = 0; j < n; j++ )
  {
    lambda2[j] = 0.0;
    for ( i = 0; i < n; i++ )
    {
      lambda2[j] = lambda2[j] + pow ( aq[i+j*n], 2 );
    }
    lambda2[j] = sqrt ( lambda2[j] );
  }

  r8vec2_print ( n, lambda, lambda2, "  LAMBDA versus the column norms of A*Q:" );
//
//  Free memory.
//
  delete [] a;
  delete [] aq;
  delete [] bin;
  delete [] bin_limit;
  delete [] lambda;
  delete [] lambda2;
  delete [] q;

  return;
}
//****************************************************************************80

void r8nsymm_gen_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8NSYMM_GEN_TEST tests R8NSYMM_GEN.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double *aqr;
  int *bin;
  double *bin_limit;
  int bin_num = 10;
  int i;
  int j;
  double *lambda;
  double *lambda2;
  double lambda_dev = 1.0;
  double lambda_max;
  double lambda_mean = 1.0;
  double lambda_min;
  int n = 100;
  double *ql;
  double *qr;
  int seed = 123456789;

  cout << "\n";
  cout << "R8NSYMM_GEN_TEST\n";
  cout << "  R8NSYMM_GEN generates an arbitrary size nonsymmetric matrix\n";
  cout << "  with known eigenvalues and eigenvectors.\n";

  a = new double[n*n];
  ql = new double[n*n];
  qr = new double[n*n];
  lambda = new double[n];

  r8nsymm_gen ( n, lambda_mean, lambda_dev, &seed, a, ql, qr, lambda );
//
//  Get the eigenvalue range.
//
  lambda_min = r8vec_min ( n, lambda );
  lambda_max = r8vec_max ( n, lambda );

  cout << "\n";
  cout << "  LAMBDA_MIN = " << lambda_min << "\n";
  cout << "  LAMBDA_MAX = " << lambda_max << "\n";
//
//  Bin the eigenvalues.
//
  bin = new int[bin_num+2];
  bin_limit = new double[bin_num+1];

  r8vec_bin ( n, lambda, bin_num, lambda_min, lambda_max, bin, bin_limit );

  r8bin_print ( bin_num, bin, bin_limit, "  Lambda bins:" );

  if ( false )
  {
    r8mat_print ( n, n, a, "  The matrix A:" );
  }

  if ( false )
  {
    r8mat_print ( n, n, qr, "  The eigenvector matrix QR:" );
  }

  aqr = r8mat_mm_new ( n, n, n, a, qr );

  lambda2 = new double[n];

  for ( j = 0; j < n; j++ )
  {
    lambda2[j] = 0.0;
    for ( i = 0; i < n; i++ )
    {
      lambda2[j] = lambda2[j] + pow ( aqr[i+j*n], 2 );
    }
    lambda2[j] = sqrt ( lambda2[j] );
  }

  r8vec2_print ( n, lambda, lambda2, "  LAMBDA versus the column norms of A*Q:" );
//
//  Free memory.
//
  delete [] a;
  delete [] aqr;
  delete [] bin;
  delete [] bin_limit;
  delete [] lambda;
  delete [] lambda2;
  delete [] ql;
  delete [] qr;

  return;
}
