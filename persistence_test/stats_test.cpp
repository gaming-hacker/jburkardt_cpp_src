# include <cmath>
# include <cstdlib>
# include <iostream>

using namespace std;

# include "r8lib.hpp"
# include "stats.hpp"

int main ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    stats_test() tests stats().
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
{
  int i;
  int n;
  int nvec = 10;
  double x_max;
  double x_max2;
  double x_mean;
  double x_mean2;
  double x_min;
  double x_min2;
  double x_std;
  double x_std2;
  double x_sum;
  double x_sum2;
  double x_var;
  double x_var2;
  double x;
  double *xvec;
  int *i_null = NULL;
  double *d_null = NULL;

  timestamp ( );
  cout << "\n";
  cout << "stats_test():\n";
  cout << "  C++ version\n";
  cout << "  Test stats(), with the interface:\n";
  cout << "  stats(x,n,x_sum,x_min,x_mean,x_max,x_var,x_std)\n";
  cout << "\n";
  cout << "  Call 10 times with random values;\n";
  cout << "  Compare results with vector calculation.\n";

  cout << "\n";
  xvec = new double[nvec];
  for ( i = 0; i < nvec; i++ )
  {
    xvec[i] = drand48 ( );
    cout << "    x[" << i << "] = " << xvec[i] << "\n";
  }
//
//  Zero everything out.
//
  stats ( d_null, i_null, d_null, d_null, d_null, d_null, d_null, d_null );
//
//  Load 10 values of X, but don't ask for output.
//
  for ( i = 0; i < nvec; i++ )
  {
    x = xvec[i];
    stats ( &x, i_null, d_null, d_null, d_null, d_null, d_null, d_null );
  }
//
//  Only get output at end.
//
  x = INFINITY;
  stats ( &x, &n, &x_sum, &x_min, &x_mean, &x_max, &x_var, &x_std );
//
//  Recompute data using a vector.
//
  x_sum2 = r8vec_sum ( nvec, xvec );
  x_min2 = r8vec_min ( nvec, xvec );
  x_mean2 = r8vec_mean ( nvec, xvec );
  x_max2 = r8vec_max ( nvec, xvec );
  x_var2 = r8vec_variance_sample ( nvec, xvec );
  x_std2 = r8vec_std_sample ( nvec, xvec );

  cout << "\n";
  cout << "    n1    = " << n      << ", n2    = " << nvec    << "\n";
  cout << "    sum1  = " << x_sum  << ", sum2  = " << x_sum2  << "\n";
  cout << "    min1  = " << x_min  << ", min2  = " << x_min2  << "\n";
  cout << "    mean1 = " << x_mean << ", mean2 = " << x_mean2 << "\n";
  cout << "    max1  = " << x_max  << ", max2  = " << x_max2  << "\n";
  cout << "    var1  = " << x_var  << ", var2  = " << x_var2  << "\n";
  cout << "    std1  = " << x_std  << ", std2  = " << x_std2  << "\n";

  delete [] xvec;
//
//  Terminate.
//
  cout << "\n";
  cout << "stats_test():\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}

