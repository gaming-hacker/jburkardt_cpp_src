# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "minpack.hpp"

//****************************************************************************80

void chkder ( int m, int n, double x[], double fvec[], double fjac[],
  int ldfjac, double xp[], double fvecp[], int mode, double err[] )

//****************************************************************************80
//
//  Purpose:
//
//    chkder() checks the gradients of M functions in N variables.
//
//  Discussion:
//
//    This function checks the gradients of M nonlinear functions
//    in N variables, evaluated at a point x, for consistency with
//    the functions themselves.  The user must call chkder twice,
//    first with mode = 1 and then with mode = 2.
//
//    mode = 1: on input, x must contain the point of evaluation.
//    on output, xp is set to a neighboring point.
//
//    mode = 2. on input, fvec must contain the functions and the
//    rows of fjac must contain the gradients
//    of the respective functions each evaluated
//    at x, and fvecp must contain the functions
//    evaluated at xp.
//    on output, err contains measures of correctness of
//    the respective gradients.
//
//    The function does not perform reliably if cancellation or
//    rounding errors cause a severe loss of significance in the
//    evaluation of a function. therefore, none of the components
//    of x should be unusually small (in particular, zero) or any
//    other value which may cause loss of significance.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2010
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//    Input, int M, the number of functions.
//
//    Input, int N, the number of variables.
//
//    Input, double X[N], the point at which the jacobian is to be checked.
//
//    Input, double FVEC(M).  On input, when mode = 2,
//    this must contain the functions evaluated at x.
//
//    Input, double FDJAC(LDFJAC,N).  On input when mode = 2,
//    the rows of fjac must contain the gradients of
//    the respective functions evaluated at x.
//
//    Input, int LDFJAC, the leading dimension of the array fjac,
//    which must not be less than M.
//
//    Output, double XP[N], created when the input value of MODE is 1.
//    This is a neighboring point of X.
//
//    Input, double FVECP[M].  On input when mode = 2,
//    fvecp must contain the functions evaluated at xp.
//
//    Input, integer MODE.  This should be set to 1 on the first call
//    and 2 thereafter.
//
//    Output, double ERR[M].  On output when mode = 2,
//    err contains measures of correctness of the respective
//    gradients.  If there is no severe loss of significance,
//    then if err(i) is 1.0 the i-th gradient is correct,
//    while if err(i) is 0.0 the i-th gradient is incorrect.
//    For values of err between 0.0 and 1.0, the categorization
//    is less certain.  In general, a value of err(i) greater
//    than 0.5 indicates that the i-th gradient is probably
//    correct, while a value of err(i) less than 0.5 indicates
//    that the i-th gradient is probably incorrect.
//
{
  double eps;
  double epsf;
  double epslog;
  double epsmch;
  const double factor = 100.0;
  int i;
  int j;
  double temp;
//
//  EPSMCH is the machine precision.
//
  epsmch = r8_epsilon ( );
//
  eps = sqrt ( epsmch );
//
//  MODE = 1.
//
  if ( mode == 1 )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( x[j] == 0.0 )
      {
        temp = eps;
      }
      else
      {
        temp = eps * fabs ( x[j] );
      }
      xp[j] = x[j] + temp;
    }
  }
//
//  MODE = 2.
//
  else
  {
    epsf = factor * epsmch;
    epslog = log10 ( eps );
    for ( i = 0; i < m; i++ )
    {
      err[i] = 0.0;
    }

    for ( j = 0; j < n; j++ )
    {
      if ( x[j] == 0.0 )
      {
        temp = 1.0;
      }
      else
      {
        temp = fabs ( x[j] );
      }
      for ( i = 0; i < m; i++ )
      {
        err[i] = err[i] + temp * fjac[i+j*ldfjac];
      }
    }

    for ( i = 0; i < m; i++ )
    {
      temp = 1.0;
      if ( fvec[i] != 0.0 &&
           fvecp[i] != 0.0 &&
           epsf * fabs ( fvec[i] ) <= fabs ( fvecp[i] - fvec[i] ) )
      {
        temp = eps * fabs ( ( fvecp[i] - fvec[i] ) / eps - err[i] )
          / ( fabs ( fvec[i] ) + fabs ( fvecp[i] ) );

        if ( temp <= epsmch )
        {
          err[i] = 1.0;
        }
        else if ( temp < eps )
        {
          err[i] = ( log10 ( temp ) - epslog ) / epslog;
        }
        else
        {
          err[i] = 0.0;
        }
      }
    }
  }
  return;
}
//****************************************************************************80

void dogleg ( int n, double r[], int lr, double diag[], double qtb[],
  double delta, double x[], double wa1[], double wa2[] )

//****************************************************************************80
//
//  Purpose:
//
//    dogleg() combines Gauss-Newton and gradient for a minimizing step.
//
//  Discussion:
//
//    Given an M by N matrix A, an n by n nonsingular diagonal
//    matrix d, an m-vector b, and a positive number delta, the
//    problem is to determine the convex combination x of the
//    gauss-newton and scaled gradient directions that minimizes
//    (a*x - b) in the least squares sense, subject to the
//    restriction that the euclidean norm of d*x be at most delta.
//
//    This function completes the solution of the problem
//    if it is provided with the necessary information from the
//    qr factorization of a. 
//
//    That is, if a = q*r, where q has orthogonal columns and r is an upper 
//    triangular matrix, then dogleg expects the full upper triangle of r and
//    the first n components of Q'*b.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2010
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//    Input, int N, the order of R.
//
//    Input, double R[LR], the upper triangular matrix R stored by rows.
//
//    Input, int LR, the size of the storage for R, which should be at
//    least (n*(n+1))/2.
//
//    Input, double DIAG[N], the diagonal elements of the matrix D.
//
//    Input, double QTB[N], the first n elements of the vector 
//    (q transpose)*b.
//
//    Input, double DELTA, an upper bound on the euclidean norm of d*x.
//
//    Output, double X[N], contains the desired convex combination of the 
//    gauss-newton direction and the scaled gradient direction.
//
//    Workspace, WA1[N].
//
//    Workspace, WA2[N].
//
{
  double alpha;
  double bnorm;
  double epsmch;
  double gnorm;
  int i;
  int j;
  int jj;
  int jp1;
  int k;
  int l;
  double qnorm;
  double sgnorm;
  double sum;
  double temp;
//
//  EPSMCH is the machine precision.
//
  epsmch = r8_epsilon ( );
//
//  Calculate the Gauss-Newton direction.
//
  jj = ( n * ( n + 1 ) ) / 2 + 1;

  for ( k = 1; k <= n; k++ )
  {
    j = n - k + 1;
    jp1 = j + 1;
    jj = jj - k;
    l = jj + 1;
    sum = 0.0;
    for ( i = jp1; i <= n; i++ )
    {
      sum = sum + r[l-1] * x[i-1];
      l = l + 1;
    }
    temp = r[jj-1];
    if ( temp == 0.0 )
    {
      l = j;
      for ( i = 1; i <= j; i++ )
      {
        temp = r8_max ( temp, fabs ( r[l-1] ) );
        l = l + n - i;
      }
      temp = epsmch * temp;
      if ( temp == 0.0 )
      {
        temp = epsmch;
      }
    }
    x[j-1] = ( qtb[j-1] - sum ) / temp;
  }
//
//  Test whether the Gauss-Newton direction is acceptable.
//
  for ( j = 0; j < n; j++ )
  {
    wa1[j] = 0.0;
    wa2[j] = diag[j] * x[j];
  }
  qnorm = enorm ( n, wa2 );

  if ( qnorm <= delta )
  {
    return;
  }
//
//  The Gauss-Newton direction is not acceptable.
//  Calculate the scaled gradient direction.
//
  l = 0;
  for ( j = 0; j < n; j++ )
  {
    temp = qtb[j];
    for ( i = j; i < n; i++ )
    {
      wa1[i-1] = wa1[i-1] + r[l-1] * temp;
      l = l + 1;
    }
    wa1[j] = wa1[j] / diag[j];
  }
//
//  Calculate the norm of the scaled gradient and test for
//  the special case in which the scaled gradient is zero.
//
  gnorm = enorm ( n, wa1 );
  sgnorm = 0.0;
  alpha = delta / qnorm;
//
//  Calculate the point along the scaled gradient
//  at which the quadratic is minimized.
//
  if ( gnorm != 0.0 )
  {
    for ( j = 0; j < n; j++ )
    {
      wa1[j] = ( wa1[j] / gnorm ) / diag[j];
    }
    l = 0;
    for ( j = 0; j < n; j++ )
    {
      sum = 0.0;
      for ( i = j; i < n; i++ )
      {
        sum = sum + r[l] * wa1[i];
        l = l + 1;
      }
      wa2[j] = sum;
    }
    temp = enorm ( n, wa2 );
    sgnorm = ( gnorm / temp ) / temp;
    alpha = 0.0;
//
//  If the scaled gradient direction is not acceptable,
//  calculate the point along the dogleg at which the quadratic is minimized.
//
    if ( sgnorm < delta)
    {
      bnorm = enorm ( n, qtb );
      temp = ( bnorm / gnorm ) * ( bnorm / qnorm ) * ( sgnorm / delta );
      temp = temp - ( delta / qnorm ) * ( sgnorm / delta ) * ( sgnorm / delta )
        + sqrt ( pow ( temp - ( delta / qnorm ), 2 )
        + ( 1.0 - ( delta / qnorm ) * ( delta / qnorm ) )
        * ( 1.0 - ( sgnorm / delta ) * ( sgnorm / delta ) ) );
      alpha = ( ( delta / qnorm )
        * ( 1.0 - ( sgnorm / delta ) * ( sgnorm / delta ) ) ) / temp;
    }
  }
//
//  Form appropriate convex combination of the Gauss-Newton
//  direction and the scaled gradient direction.
//
  temp = ( 1.0 - alpha ) * r8_min ( sgnorm, delta );
  for ( j = 0; j < n; j++ )
  {
    x[j] = temp * wa1[j] + alpha * x[j];
  }
  return;
}
//****************************************************************************80

double enorm ( int n, double x[] )

//****************************************************************************80
//
//  Purpose:
//
//    enorm() returns the Euclidean norm of a vector.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2010
//
//  Author:
//
//    John Burkardt
//
//  Input:
//
//    int N, the number of entries in A.
//
//    double X[N], the vector whose norm is desired.
//
//  Output:
//
//    double ENORM, the norm of X.
//
{
  int i;
  double value;

  value = 0.0;
  for ( i = 0; i < n; i++ )
  {
    value = value + x[i] * x[i];
  }
  value = sqrt ( value );
  return value;
}
//****************************************************************************80

void fdjac1 ( void fcn ( int n, double x[], double f[], int &iflag ),
  int n, double x[], double fvec[], double fjac[], int ldfjac, int &iflag,
  int ml, int mu, double epsfcn, double wa1[], double wa2[] )

//****************************************************************************80
//
//  Purpose:
//
//    fdjac1() estimates an N by N Jacobian matrix using forward differences.
//
//  Discussion:
//
//    This function computes a forward-difference approximation
//    to the N by N jacobian matrix associated with a specified
//    problem of N functions in N variables. 
//
//    If the jacobian has a banded form, then function evaluations are saved 
//    by only approximating the nonzero terms.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2010
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//       fcn is the name of the user-supplied subroutine which
//         calculates the functions. fcn must be declared
//         in an external statement in the user calling
//         program, and should be written as follows.
//
//         subroutine fcn(n,x,fvec,iflag)
//         integer n,iflag
//         double precision x(n),fvec(n)
//         ----------
//         calculate the functions at x and
//         return this vector in fvec.
//         ----------
//         return
//         end
//
//         the value of iflag should not be changed by fcn unless
//         the user wants to terminate execution of fdjac1.
//         in this case set iflag to a negative integer.
//
//    Input, int N, the number of functions and variables.
//
//    Input, double X[N], the evaluation point.
//
//    Input, double FVEC[N], the functions evaluated at X.
//
//    Output, double FJAC[N*N], the approximate jacobian matrix at X.
//
//       ldfjac is a positive integer input variable not less than n
//         which specifies the leading dimension of the array fjac.
//
//       iflag is an integer variable which can be used to terminate
//         the execution of fdjac1. see description of fcn.
//
//       ml is a nonnegative integer input variable which specifies
//         the number of subdiagonals within the band of the
//         jacobian matrix. if the jacobian is not banded, set
//         ml to at least n - 1.
//
//       epsfcn is an input variable used in determining a suitable
//         step length for the forward-difference approximation. this
//         approximation assumes that the relative errors in the
//         functions are of the order of epsfcn. if epsfcn is less
//         than the machine precision, it is assumed that the relative
//         errors in the functions are of the order of the machine
//         precision.
//
//       mu is a nonnegative integer input variable which specifies
//         the number of superdiagonals within the band of the
//         jacobian matrix. if the jacobian is not banded, set
//         mu to at least n - 1.
//
//       wa1 and wa2 are work arrays of length n. if ml + mu + 1 is at
//         least n, then the jacobian is considered dense, and wa2 is
//         not referenced.
{
  double eps;
  double epsmch;
  double h;
  int i;
  int j;
  int k;
  int msum;
  double temp;
//
//  EPSMCH is the machine precision.
//
  epsmch = r8_epsilon ( );

  eps = sqrt ( r8_max ( epsfcn, epsmch ) );
  msum = ml + mu + 1;
//
//  Computation of dense approximate jacobian.
//
  if ( n <= msum )
  {
    for ( j = 0; j < n; j++ )
    {
      temp = x[j];
      h = eps * fabs ( temp );
      if ( h == 0.0 )
      {
        h = eps;
      }
      x[j] = temp + h;
      fcn ( n, x, wa1, iflag );
      if ( iflag < 0 )
      {
        break;
      }
      x[j] = temp;
      for ( i = 0; i < n; i++ )
      {
        fjac[i+j*ldfjac] = ( wa1[i] - fvec[i] ) / h;
      }
    }
  }
//
//  Computation of a banded approximate jacobian.
//
  else
  {
    for ( k = 0; k < msum; k++ )
    {
      for ( j = k; j < n; j = j + msum )
      {
        wa2[j] = x[j];
        h = eps * fabs ( wa2[j] );
        if ( h == 0.0 )
        {
          h = eps;
        }
        x[j] = wa2[j] + h;
      }
      fcn ( n, x, wa1, iflag );
      if ( iflag < 0 )
      {
        break;
      }
      for ( j = k; j < n; j = j + msum )
      {
        x[j] = wa2[j];
        h = eps * fabs ( wa2[j] );
        if ( h == 0.0 )
        {
          h = eps;
        }
        for ( i = 0; i < n; i++ )
        {
          if ( j - mu <= i && i <= j + ml )
          {
            fjac[i+j*ldfjac] = ( wa1[i] - fvec[i] ) / h;
          }
          else
          {
            fjac[i+j*ldfjac] = 0.0;
          }
        }
      }
    }
  }
  return;
}
//****************************************************************************80

void fdjac2 ( void fcn ( int m, int n, double x[], double fvec[], int &iflag ),
  int m, int n, double x[], double fvec[], double fjac[], int ldfjac,
  int &iflag, double epsfcn, double wa[] )

//****************************************************************************80
//
//  Purpose:
//
//    fdjac2() estimates an M by N Jacobian matrix using forward differences.
//
//  Discussion:
//
//    This function computes a forward-difference approximation
//    to the M by N jacobian matrix associated with a specified
//    problem of M functions in N variables.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2010
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//       fcn is the name of the user-supplied subroutine which
//         calculates the functions. fcn must be declared
//         in an external statement in the user calling
//         program, and should be written as follows.
//
//         subroutine fcn(m,n,x,fvec,iflag)
//         integer m,n,iflag
//         double precision x(n),fvec(m)
//         ----------
//         calculate the functions at x and
//         return this vector in fvec.
//         ----------
//         return
//         end
//
//         the value of iflag should not be changed by fcn unless
//         the user wants to terminate execution of fdjac2.
//         in this case set iflag to a negative integer.
//
//    Input, int M, the number of functions.
//
//    Input, int N, the number of variables.  N must not exceed M.
//
//    Input, double X[N], the point at which the jacobian is to be estimated.
//
//       fvec is an input array of length m which must contain the
//         functions evaluated at x.
//
//       fjac is an output m by n array which contains the
//         approximation to the jacobian matrix evaluated at x.
//
//       ldfjac is a positive integer input variable not less than m
//         which specifies the leading dimension of the array fjac.
//
//       iflag is an integer variable which can be used to terminate
//         the execution of fdjac2. see description of fcn.
//
//       epsfcn is an input variable used in determining a suitable
//         step length for the forward-difference approximation. this
//         approximation assumes that the relative errors in the
//         functions are of the order of epsfcn. if epsfcn is less
//         than the machine precision, it is assumed that the relative
//         errors in the functions are of the order of the machine
//         precision.
//
//    Workspace, double WA[M].
//
{
  double eps;
  double epsmch;
  double h;
  int i;
  int j;
  double temp;
//
//  EPSMCH is the machine precision.
//
  epsmch = r8_epsilon ( );
  eps = sqrt ( r8_max ( epsfcn, epsmch ) );

  for ( j = 0; j < n; j++ )
  {
    temp = x[j];
    if ( temp == 0.0 )
    {
      h = eps;
    }
    else
    {
      h = eps * fabs ( temp );
    }
    x[j] = temp + h;
    fcn ( m, n, x, wa, iflag );
    if ( iflag < 0 )
    {
      break;
    }
    x[j] = temp;
    for ( i = 0; i < m; i++ )
    {
      fjac[i+j*ldfjac] = ( wa[i] - fvec[i] ) / h;
    }
  }
  return;
}
//****************************************************************************80

int hybrd ( void fcn ( int n, double x[], double fvec[], int &iflag ),
  int n, double x[],
  double fvec[], double xtol, int maxfev, int ml, int mu, double epsfcn,
  double diag[], int mode, double factor, int nprint, int nfev,
  double fjac[], int ldfjac, double r[], int lr, double qtf[], double wa1[],
  double wa2[], double wa3[], double wa4[] )

//****************************************************************************80
//
//  Purpose:
//
//    hybrd() finds a zero of a system of N nonlinear equations.
//
//  Discussion:
//
//    The purpose of HYBRD is to find a zero of a system of
//    N nonlinear functions in N variables by a modification
//    of the Powell hybrid method. 
//
//    The user must provide FCN, which calculates the functions. 
//
//    The jacobian is calculated by a forward-difference approximation.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2010
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//       fcn is the name of the user-supplied subroutine which
//         calculates the functions. fcn must be declared
//         in an external statement in the user calling
//         program, and should be written as follows.
//
//         subroutine fcn(n,x,fvec,iflag)
//         integer n,iflag
//         double precision x(n),fvec(n)
//         ----------
//         calculate the functions at x and
//         return this vector in fvec.
//         ---------
//         return
//         end
//
//         the value of iflag should not be changed by fcn unless
//         the user wants to terminate execution of hybrd.
//         in this case set iflag to a negative integer.
//
//    Input, int N, the number of functions and variables.
//
//    Input/output, double X[N].  On input an initial estimate of the solution.
//    On output, the final estimate of the solution.
//
//    Output, double FVEC[N], the functions evaluated at the output value of X.
//
//    Input, double XTOL, a nonnegative value.  Termination occurs when the 
//    relative error between two consecutive iterates is at most XTOL.
//
//    Input, int MAXFEV.  Termination occurs when the number of calls to FCN 
//    is at least MAXFEV by the end of an iteration.
//
//    Input, int ML, specifies the number of subdiagonals within the band of 
//    the jacobian matrix.  If the jacobian is not banded, set
//    ml to at least n - 1.
//
//       mu is a nonnegative integer input variable which specifies
//         the number of superdiagonals within the band of the
//         jacobian matrix. if the jacobian is not banded, set
//         mu to at least n - 1.
//
//       epsfcn is an input variable used in determining a suitable
//         step length for the forward-difference approximation. this
//         approximation assumes that the relative errors in the
//         functions are of the order of epsfcn. if epsfcn is less
//         than the machine precision, it is assumed that the relative
//         errors in the functions are of the order of the machine
//         precision.
//
//       diag is an array of length n. if mode = 1 (see
//         below), diag is internally set. if mode = 2, diag
//         must contain positive entries that serve as
//         multiplicative scale factors for the variables.
//
//       mode is an integer input variable. if mode = 1, the
//         variables will be scaled internally. if mode = 2,
//         the scaling is specified by the input diag. other
//         values of mode are equivalent to mode = 1.
//
//       factor is a positive input variable used in determining the
//         initial step bound. this bound is set to the product of
//         factor and the euclidean norm of diag*x if nonzero, or else
//         to factor itself. in most cases factor should lie in the
//         interval (.1,100.). 100. is a generally recommended value.
//
//       nprint is an integer input variable that enables controlled
//         printing of iterates if it is positive. in this case,
//         fcn is called with iflag = 0 at the beginning of the first
//         iteration and every nprint iterations thereafter and
//         immediately prior to return, with x and fvec available
//         for printing. if nprint is not positive, no special calls
//         of fcn with iflag = 0 are made.
//
//       info is an integer output variable. if the user has
//         terminated execution, info is set to the (negative)
//         value of iflag. see description of fcn. otherwise,
//         info is set as follows.
//
//         info = 0   improper input parameters.
//
//         info = 1   relative error between two consecutive iterates
//                    is at most xtol.
//
//         info = 2   number of calls to fcn has reached or exceeded
//                    maxfev.
//
//         info = 3   xtol is too small. no further improvement in
//                    the approximate solution x is possible.
//
//         info = 4   iteration is not making good progress, as
//                    measured by the improvement from the last
//                    five jacobian evaluations.
//
//         info = 5   iteration is not making good progress, as
//                    measured by the improvement from the last
//                    ten iterations.
//
//       nfev is an integer output variable set to the number of
//         calls to fcn.
//
//       fjac is an output n by n array which contains the
//         orthogonal matrix q produced by the qr factorization
//         of the final approximate jacobian.
//
//       ldfjac is a positive integer input variable not less than n
//         which specifies the leading dimension of the array fjac.
//
//       r is an output array of length lr which contains the
//         upper triangular matrix produced by the qr factorization
//         of the final approximate jacobian, stored rowwise.
//
//       lr is a positive integer input variable not less than
//         (n*(n+1))/2.
//
//       qtf is an output array of length n which contains
//         the vector (q transpose)*fvec.
//
//       wa1, wa2, wa3, and wa4 are work arrays of length n.
//
{
  double actred;
  double delta;
  double epsmch;
  double fnorm;
  double fnorm1;
  int i;
  int iflag;
  int info;
  int iter;
  int iwa[1];
  int j;
  bool jeval;
  int l;
  int msum;
  int ncfail;
  int ncsuc;
  int nslow1;
  int nslow2;
  const double p001 = 0.001;
  const double p0001 = 0.0001;
  const double p1 = 0.1;
  const double p5 = 0.5;
  double pnorm;
  double prered;
  double ratio;
  double sum;
  double temp;
  double xnorm;
//
//  Certain loops in this function were kept closer to their original FORTRAN77
//  format, to avoid confusing issues with the array index L.  These loops are
//  marked "DO NOT ADJUST", although they certainly could be adjusted (carefully)
//  once the initial translated code is tested.
//

//
//  EPSMCH is the machine precision.
//
  epsmch = r8_epsilon ( );

  info = 0;
  iflag = 0;
  nfev = 0;
//
//  Check the input parameters.
//
  if ( n <= 0 )
  {
    info = 0;
    return info;
  }
  if ( xtol < 0.0 )
  {
    info = 0;
    return info;
  }
  if ( maxfev <= 0 )
  {
    info = 0;
    return info;
  }
  if ( ml < 0 )
  {
    info = 0;
    return info;
  }
  if ( mu < 0 )
  {
    info = 0;
    return info;
  }
  if ( factor <= 0.0 )
  {
    info = 0;
    return info;
  }
  if ( ldfjac < n )
  {
    info = 0;
    return info;
  }
  if ( lr < ( n * ( n + 1 ) ) / 2 )
  {
    info = 0;
    return info;
  }
  if ( mode == 2 )
  {
    for ( j = 0; j < n; j++ )
    {
      if ( diag[j] <= 0.0 )
      {
        info = 0;
        return info;
      }
    }
  }
//
//  Evaluate the function at the starting point and calculate its norm.
//
  iflag = 1;
  fcn ( n, x, fvec, iflag );
  nfev = 1;
  if ( iflag < 0 )
  {
    info = iflag;
    return info;
  }

  fnorm = enorm ( n, fvec );
//
//  Determine the number of calls to FCN needed to compute the jacobian matrix.
//
  msum = i4_min ( ml + mu + 1, n );
//
//  Initialize iteration counter and monitors.
//
  iter = 1;
  ncsuc = 0;
  ncfail = 0;
  nslow1 = 0;
  nslow2 = 0;
//
//  Beginning of the outer loop.
//
  for ( ; ; )
  {
    jeval = true;
//
//  Calculate the jacobian matrix.
//
    iflag = 2;
    fdjac1 ( fcn, n, x, fvec, fjac, ldfjac, iflag, ml, mu, epsfcn, wa1, wa2 );

    nfev = nfev + msum;
    if ( iflag < 0 )
    {
      info = iflag;
      return info;
    }
//
//  Compute the QR factorization of the jacobian.
//
    qrfac ( n, n, fjac, ldfjac, false, iwa, 1, wa1, wa2 );
//
//  On the first iteration and if MODE is 1, scale according
//  to the norms of the columns of the initial jacobian.
//
    if ( iter == 1 )
    {
      if ( mode == 1 )
      {
        for ( j = 0; j < n; j++ )
        {
          if ( wa2[j] != 0.0 )
          {
            diag[j] = wa2[j];
          }
          else
          {
            diag[j] = 1.0;
          }
        }
      }
//
//  On the first iteration, calculate the norm of the scaled X
//  and initialize the step bound DELTA.
//
      for ( j = 0; j < n; j++ )
      {
        wa3[j] = diag[j] * x[j];
      }
      xnorm = enorm ( n, wa3 );

      if ( xnorm == 0.0 )
      {
        delta = factor;
      }
      else
      {
        delta = factor * xnorm;
      }
    }
//
//  Form Q' * FVEC and store in QTF.
//
    for ( i = 0; i < n; i++ )
    {
      qtf[i] = fvec[i];
    }
    for ( j = 0; j < n; j++ )
    {
      if ( fjac[j+j*ldfjac] != 0.0 )
      {
        sum = 0.0;
        for ( i = j; i < n; i++ )
        {
          sum = sum + fjac[i+j*ldfjac] * qtf[i];
        }
        temp = - sum / fjac[j+j*ldfjac];
        for ( i = j; i < n; i++ )
        {
          qtf[i] = qtf[i] + fjac[i+j*ldfjac] * temp;
        }
      }
    }
//
//  Copy the triangular factor of the QR factorization into R.
//
//  DO NOT ADJUST THIS LOOP, BECAUSE OF L.
//
    for ( j = 1; j <= n; j++ )
    {
      l = j;
      for ( i = 1; i <= j - 1; i++ )
      {
        r[l-1] = fjac[(i-1)+(j-1)*ldfjac];
        l = l + n - i;
      }
      r[l-1] = wa1[j-1];
      if ( wa1[j-1] == 0.0 )
      {
        cout << "  Matrix is singular.\n";
      }
    }
//
//  Accumulate the orthogonal factor in FJAC.
//
    qform ( n, n, fjac, ldfjac );
//
//  Rescale if necessary.
//
    if ( mode == 1 )
    {
      for ( j = 0; j < n; j++ )
      {
        diag[j] = r8_max ( diag[j], wa2[j] );
      }
    }
//
//  Beginning of the inner loop.
//
    for ( ; ; )
    {
//
//  If requested, call FCN to enable printing of iterates.
//
      if ( 0 < nprint )
      {
        if ( ( iter - 1 ) % nprint == 0 )
        {
          iflag = 0;
          fcn ( n, x, fvec, iflag );
          if ( iflag < 0 )
          {
            info = iflag;
            return info;
          }
        }
      }
//
//  Determine the direction P.
//
      dogleg ( n, r, lr, diag, qtf, delta, wa1, wa2, wa3 );
//
//  Store the direction P and X + P.  Calculate the norm of P.
//
      for ( j = 0; j < n; j++ )
      {
        wa1[j] = - wa1[j];
        wa2[j] = x[j] + wa1[j];
        wa3[j] = diag[j] * wa1[j];
      }
      pnorm = enorm ( n, wa3 );
//
//  On the first iteration, adjust the initial step bound.
//
      if ( iter == 1 )
      {
        delta = r8_min ( delta, pnorm );
      }
//
//  Evaluate the function at X + P and calculate its norm.
//
      iflag = 1;
      fcn ( n, wa2, wa4, iflag );
      nfev = nfev + 1;
      if ( iflag < 0 )
      {
        info = iflag;
        return info;
      }
      fnorm1 = enorm ( n, wa4 );
//
//  Compute the scaled actual reduction.
//
      if ( fnorm1 < fnorm )
      {
        actred = 1.0 - ( fnorm1 / fnorm ) * ( fnorm1 / fnorm );
      }
      else
      {
        actred = - 1.0;
      }
//
//  Compute the scaled predicted reduction.
//
//  DO NOT ADJUST THIS LOOP, BECAUSE OF L.
//
      l = 1;
      for ( i = 1; i <= n; i++ )
      {
        sum = 0.0;
        for ( j = i; j <= n; j++ )
        {
          sum = sum + r[l-1] * wa1[j-1];
          l = l + 1;
        }
        wa3[i-1] = qtf[i-1] + sum;
      }
      temp = enorm ( n, wa3 );

      if ( temp < fnorm )
      {
        prered = 1.0 - ( temp / fnorm ) * ( temp / fnorm );
      }
      else
      {
        prered = 0.0;
      }
//
//  Compute the ratio of the actual to the predicted reduction.
//
      if ( 0.0 < prered )
      {
        ratio = actred / prered;
      }
      else
      {
        ratio = 0.0;
      }
//
//  Update the step bound.
//
      if ( ratio < p1 )
      {
        ncsuc = 0;
        ncfail = ncfail + 1;
        delta = p5 * delta;
      }
      else
      {
        ncfail = 0;
        ncsuc = ncsuc + 1;
        if ( p5 <= ratio || 1 < ncsuc )
        {
          delta = r8_max ( delta, pnorm / p5 );
        }
        if ( fabs ( ratio - 1.0 ) <= p1 )
        {
          delta = pnorm / p5;
        }
      }
//
//  On successful iteration, update X, FVEC, and their norms.
//
      if ( p0001 <= ratio )
      {
        for ( j = 0; j < n; j++ )
        {
          x[j] = wa2[j];
          wa2[j] = diag[j] * x[j];
          fvec[j] = wa4[j];
        }
        xnorm = enorm ( n, wa2 );
        fnorm = fnorm1;
        iter = iter + 1;
      }
//
//  Determine the progress of the iteration.
//
      nslow1 = nslow1 + 1;
      if ( p001 <= actred )
      {
        nslow1 = 0;
      }
      if ( jeval )
      {
        nslow2 = nslow2 + 1;
      }
      if ( p1 <= actred )
      {
        nslow2 = 0;
      }
//
//  Test for convergence.
//
      if ( delta <= xtol * xnorm || fnorm == 0.0 )
      {
        info = 1;
        return info;
      }
//
//  Tests for termination and stringent tolerances.
//
      if ( maxfev <= nfev )
      {
        info = 2;
        return info;
      }
      if ( p1 * r8_max ( p1 * delta, pnorm ) <= epsmch * xnorm )
      {
        info = 3;
        return info;
      }
      if ( nslow2 == 5 )
      {
        info = 4;
        return info;
      }
      if ( nslow1 == 10 )
      {
        info = 5;
        return info;
      }
//
//  Criterion for recalculating jacobian approximation by forward differences.
//
      if ( ncfail == 2 )
      {
        break;
      }
//
//  Calculate the rank one modification to the jacobian
//  and update QTF if necessary.
//
      for ( j = 0; j < n; j++ )
      {
        sum = 0.0;
        for ( i = 0; i < n; i++ )
        {
          sum = sum + fjac[i+j*ldfjac] * wa4[i];
        }
        wa2[j] = ( sum - wa3[j] ) / pnorm;
        wa1[j] = diag[j] * ( ( diag[j] * wa1[j] ) / pnorm );
        if ( p0001 <= ratio )
        {
          qtf[j] = sum;
        }
      }
//
//  Compute the QR factorization of the updated jacobian.
//
      r1updt ( n, n, r, lr, wa1, wa2, wa3 );
      r1mpyq ( n, n, fjac, ldfjac, wa2, wa3 );
      r1mpyq ( 1, n, qtf, 1, wa2, wa3 );

      jeval = false;
    }
//
//  End of the inner loop.
//
  }
//
//  End of the outer loop.
//
}
//****************************************************************************80

int hybrd1 ( void fcn ( int n, double x[], double fvec[], int &iflag ), int n,
  double x[], double fvec[], double tol, double wa[], int lwa )

//****************************************************************************80
//
//  Purpose:
//
//    hybrd1() finds a zero of a system of N nonlinear equations. 
//
//  Discussion:
//
//    The purpose of HYBRD1 is to find a zero of a system of
//    N nonlinear functions in N variables by a modification
//    of the Powell hybrid method.  
//
//    This is done by using the more general nonlinear equation solver HYBRD.  
//
//    The user must provide FCN, which calculates the functions.
//
//    The jacobian is calculated by a forward-difference approximation.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    26 July 2014
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//       fcn is the name of the user-supplied subroutine which
//         calculates the functions. fcn must be declared
//         in an external statement in the user calling
//         program, and should be written as follows.
//
//         subroutine fcn(n,x,fvec,iflag)
//         integer n,iflag
//         double precision x(n),fvec(n)
//         ----------
//         calculate the functions at x and
//         return this vector in fvec.
//         ---------
//         return
//         end
//
//         the value of iflag should not be changed by fcn unless
//         the user wants to terminate execution of hybrd1.
//         in this case set iflag to a negative integer.
//
//    Input, int N, the number of functions and variables.
//
//    Input/output, double X[N].  On input, an initial estimate of the solution.
//    On output, the final estimate of the solution.
//
//    Output, double FVEC[N], the functions evaluated at the output X.
//
//    Input, double TOL, a nonnegative variable. tTermination occurs when the 
//    algorithm estimates that the relative error between X and the solution 
//    is at most TOL.
//
//       info is an integer output variable. if the user has
//         terminated execution, info is set to the (negative)
//         value of iflag. see description of fcn. otherwise,
//         info is set as follows.
//         info = 0   improper input parameters.
//         info = 1   algorithm estimates that the relative error
//                    between x and the solution is at most tol.
//         info = 2   number of calls to fcn has reached or exceeded
//                    200*(n+1).
//         info = 3   tol is too small. no further improvement in
//                    the approximate solution x is possible.
//         info = 4   iteration is not making good progress.
//
//    Workspace, double WA[LWA].
//
//       lwa is a positive integer input variable not less than
//         (n*(3*n+13))/2.
//
{
  double epsfcn;
  double factor;
  int index;
  int info;
  int j;
  int lr;
  int maxfev;
  int ml;
  int mode;
  int mu;
  int nfev;
  int nprint;
  double xtol;

  info = 0;
//
//  Check the input.
//
  if ( n <= 0 )
  {
    return info;
  }
  if ( tol <= 0.0 )
  {
    return info;
  }
  if ( lwa < ( n * ( 3 * n + 13 ) ) / 2 )
  {
    return info;
  }
//
//  Call HYBRD.
//
  xtol = tol;
  maxfev = 200 * ( n + 1 );
  ml = n - 1;
  mu = n - 1;
  epsfcn = 0.0;
  for ( j = 0; j < n; j++ )
  {
    wa[j] = 1.0;
  }
  mode = 2;
  factor = 100.0;
  nprint = 0;
  nfev = 0;
  lr = ( n * ( n + 1 ) ) / 2;
  index = 6 * n + lr;

  info = hybrd ( fcn, n, x, fvec, xtol, maxfev, ml, mu, epsfcn, wa, mode,
    factor, nprint, nfev, wa+index, n, wa+6*n, lr,
    wa+n, wa+2*n, wa+3*n, wa+4*n, wa+5*n );

  if ( info == 5 )
  {
    info = 4;
  }
  return info;
}
//****************************************************************************80

int i4_max ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    i4_max() returns the maximum of two I4's.
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
//****************************************************************************80

int i4_min ( int i1, int i2 )

//****************************************************************************80
//
//  Purpose:
//
//    i4_min() returns the minimum of two I4's.
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
//  Input:
//
//    int I1, I2, two integers to be compared.
//
//  Output:
//
//    int I4_MIN, the smaller of I1 and I2.
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
//****************************************************************************80

void qform ( int m, int n, double q[], int ldq )

//****************************************************************************80
//
//  Purpose:
//
//    qform() constructs the standard form of Q from its factored form.
//
//  Discussion:
//
//    This function proceeds from the computed QR factorization of
//    an M by N matrix A to accumulate the M by M orthogonal matrix
//    Q from its factored form.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 January 2018
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//    Input, int M, the number of rows of A, and the order of Q.
//
//    Input, int N, the number of columns of A.
//
//    Input/output, double Q[LDQ*N].  On input, the full lower trapezoid in
//    the first min(M,N) columns of Q contains the factored form.
//    On output Q has been accumulated into a square matrix.
//
//    Input, int LDQ, the leading dimension of the array Q.
//
{
  int i;
  int j;
  int k;
  int minmn;
  double sum;
  double temp;
  double *wa;
//
//  Zero out the upper triangle of Q in the first min(M,N) columns.
//
  minmn = i4_min ( m, n );

  for ( j = 1; j < minmn; j++ )
  {
    for ( i = 0; i <= j - 1; i++ )
    {
      q[i+j*ldq] = 0.0;
    }
  }
//
//  Initialize remaining columns to those of the identity matrix.
//
  for ( j = n; j < m; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      q[i+j*ldq] = 0.0;
    }
    q[j+j*ldq] = 1.0;
  }
//
//  Accumulate Q from its factored form.
//
  wa = new double[m];

  for ( k = minmn - 1; 0 <= k; k-- )
  {
    for ( i = k; i < m; i++ )
    {
      wa[i] = q[i+k*ldq];
      q[i+k*ldq] = 0.0;
    }
    q[k+k*ldq] = 1.0;

    if ( wa[k] != 0.0 )
    {
      for ( j = k; j < m; j++ )
      {
        sum = 0.0;
        for ( i = k; i < m; i++ )
        {
          sum = sum + q[i+j*ldq] * wa[i];
        }
        temp = sum / wa[k];
        for ( i = k; i < m; i++ )
        {
          q[i+j*ldq] = q[i+j*ldq] - temp * wa[i];
        }
      }
    }
  }
//
//  Free memory.
//
  delete [] wa;

  return;
}
//****************************************************************************80

void qrfac ( int m, int n, double a[], int lda, bool pivot, int ipvt[],
  int lipvt, double rdiag[], double acnorm[] )

//****************************************************************************80
//
//  Purpose:
//
//    qrfac() computes the QR factorization of an M by N matrix.
//
//  Discussion:
//
//    This function uses Householder transformations with optional column
//    pivoting to compute a QR factorization of the M by N matrix A. 
//
//    That is, QRFAC determines an orthogonal
//    matrix Q, a permutation matrix P, and an upper trapezoidal
//    matrix R with diagonal elements of nonincreasing magnitude,
//    such that A*P = Q*R. 
//
//    The Householder transformation for
//    column k, k = 1,2,...,min(m,n), is of the form
//
//      i - (1/u(k))*u*u'
//
//    where U has zeros in the first K-1 positions. 
//
//    The form of this transformation and the method of pivoting first
//    appeared in the corresponding LINPACK function.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 January 2017
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//    Input, int M, the number of rows of A.
//
//    Input, int N, the number of columns of A.
//
//    Input/output, double A[M*N].  On input, the matrix for which the QR 
//    factorization is to be computed.  On output, the strict upper trapezoidal 
//    part contains the strict upper trapezoidal part of the R factor, and 
//    the lower trapezoidal part contains a factored form of Q, the non-trivial
//    elements of the U vectors described above.
//
//    Input, int LDA, a positive value not less than M which specifies the 
//    leading dimension of the array A.
//
//    Input, bool PIVOT.  If true, then column pivoting is enforced.
//
//    Output, integer IPVT[LIPVT].  If PIVOT is true, then on output IPVT 
//    defines the permutation matrix P such that A*P = Q*R.  Column J of P
//    is column IPVT[J] of the identity matrix.
//
//       lipvt is a positive integer input variable. if pivot is false,
//         then lipvt may be as small as 1. if pivot is true, then
//         lipvt must be at least n.
//
//       rdiag is an output array of length n which contains the
//         diagonal elements of r.
//
//       acnorm is an output array of length n which contains the
//         norms of the corresponding columns of the input matrix a.
//         if this information is not needed, then acnorm can coincide
//         with rdiag.
//
{
  double ajnorm;
  double epsmch;
  int i;
  int j;
  int k;
  int kmax;
  int minmn;
  const double p05 = 0.05;
  double sum;
  double temp;
  double *wa;
//
//  EPSMCH is the machine precision.
//
  epsmch = r8_epsilon ( );
//
//  Compute the initial column norms and initialize several arrays.
//
  wa = new double[n];

  for ( j = 0; j < n; j++ )
  {
    acnorm[j] = enorm ( m, a+j*lda );
    rdiag[j] = acnorm[j];
    wa[j] = rdiag[j];
    if ( pivot )
    {
      ipvt[j] = j;
    }
  }
//
//  Reduce A to R with Householder transformations.
//
  minmn = i4_min ( m, n );

  for ( j = 0; j < minmn; j++ )
  {
    if ( pivot )
    {
//
//  Bring the column of largest norm into the pivot position.
//
      kmax = j;
      for ( k = j; k < n; k++ )
      {
        if ( rdiag[kmax] < rdiag[k] )
        {
          kmax = k;
        }
      }
      if ( kmax != j )
      {
        for ( i = 0; i < m; i++ )
        {
          temp          = a[i+j*lda];
          a[i+j*lda]    = a[i+kmax*lda];
          a[i+kmax*lda] = temp;
        }
        rdiag[kmax] = rdiag[j];
        wa[kmax]    = wa[j];
        k          = ipvt[j];
        ipvt[j]    = ipvt[kmax];
        ipvt[kmax] = k;
      }
    }
//
//  Compute the Householder transformation to reduce the
//  J-th column of A to a multiple of the J-th unit vector.
//
    ajnorm = enorm ( m - j, a+j+j*lda );

    if ( ajnorm != 0.0 )
    {
      if ( a[j+j*lda] < 0.0 )
      {
        ajnorm = - ajnorm;
      }
      for ( i = j; i < m; i++ )
      {
        a[i+j*lda] = a[i+j*lda] / ajnorm;
      }
      a[j+j*lda] = a[j+j*lda] + 1.0;
//
//  Apply the transformation to the remaining columns and update the norms.
//
      for ( k = j + 1; k < n; k++ )
      {
        sum = 0.0;
        for ( i = j; i < m; i++ )
        {
          sum = sum + a[i+j*lda] * a[i+k*lda];
        }
        temp = sum / a[j+j*lda];
        for ( i = j; i < m; i++ )
        {
          a[i+k*lda] = a[i+k*lda] - temp * a[i+j*lda];
        }
        if ( pivot && rdiag[k] != 0.0 )
        {
          temp = a[j+k*lda] / rdiag[k];
          rdiag[k] = rdiag[k] * sqrt ( r8_max ( 0.0, 1.0 - temp * temp ) );
          if ( p05 * ( rdiag[k] / wa[k] ) * ( rdiag[k] / wa[k] ) <= epsmch )
          {
            rdiag[k] = enorm ( m - 1 - j, a+(j+1)+k*lda );
            wa[k] = rdiag[k];
          }
        }
      }
    }
    rdiag[j] = - ajnorm;
  }
//
//  Free memory.
//
  delete [] wa;

  return;
}
//****************************************************************************80

void qrsolv ( int n, double r[], int ldr, int ipvt[], double diag[], 
  double qtb[], double x[], double sdiag[] )

//****************************************************************************80
//
//  Purpose:
//
//    qrsolv() solves a rectangular linear system A*x=b in the least squares sense.
//
//  Discussion:
//
//    Given an M by N matrix A, an N by N diagonal matrix D,
//    and an M-vector B, the problem is to determine an X which
//    solves the system
//
//      A*X = B
//      D*X = 0
//
//    in the least squares sense.
//
//    This function completes the solution of the problem
//    if it is provided with the necessary information from the
//    QR factorization, with column pivoting, of A.  That is, if
//    A*P = Q*R, where P is a permutation matrix, Q has orthogonal
//    columns, and R is an upper triangular matrix with diagonal
//    elements of nonincreasing magnitude, then QRSOLV expects
//    the full upper triangle of R, the permutation matrix p,
//    and the first N components of Q'*B.
//
//    The system is then equivalent to
//
//      R*Z = Q'*B
//      P'*D*P*Z = 0
//
//    where X = P*Z.  If this system does not have full rank,
//    then a least squares solution is obtained.  On output QRSOLV
//    also provides an upper triangular matrix S such that
//
//      P'*(A'*A + D*D)*P = S'*S.
//
//    S is computed within QRSOLV and may be of separate interest.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    03 January 2018
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burton Garbow, Kenneth Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//    Input, int N, the order of R.
//
//    Input/output, double R[LDR*N], the N by N matrix.
//    On input the full upper triangle must contain the full upper triangle
//    of the matrix R.  On output the full upper triangle is unaltered, and
//    the strict lower triangle contains the strict upper triangle
//    (transposed) of the upper triangular matrix S.
//
//    Input, int LDR, the leading dimension of R, which must be
//    at least N.
//
//    Input, int IPVT[N], defines the permutation matrix P such 
//    that A*P = Q*R.  Column J of P is column IPVT(J) of the identity matrix.
//
//    Input, double DIAG[N], the diagonal elements of the matrix D.
//
//    Input, double QTB[N], the first N elements of the vector Q'*B.
//
//    Output, double X[N], the least squares solution.
//
//    Output, double SDIAG[N], the diagonal elements of the upper
//    triangular matrix S.
//
{
  double c;
  double cotan;
  int i;
  int j;
  int k;
  int l;
  int nsing;
  double qtbpj;
  double s;
  double sum2;
  double t;
  double temp;
  double *wa;
//
//  Copy R and Q'*B to preserve input and initialize S.
//
//  In particular, save the diagonal elements of R in X.
//
  for ( j = 0; j < n; j++ )
  {
    for ( i = j; i < n; i++ )
    {
      r[i+j*ldr] = r[j+i*ldr];
    }
  }
  for ( j = 0; j < n; j++ )
  {
    x[j]= r[j+j*ldr];
  }

  wa = new double[n];
  for ( j = 0; j < n; j++ )
  {
    wa[j] = qtb[j];
  }
//
//  Eliminate the diagonal matrix D using a Givens rotation.
//
  for ( j = 0; j < n; j++ )
  {
//
//  Prepare the row of D to be eliminated, locating the
//  diagonal element using P from the QR factorization.
//
    l = ipvt[j];

    if ( diag[l] != 0.0 )
    {
      sdiag[j] = diag[l];
      for ( i = j + 1; i < n; i++ )
      {
        sdiag[i] = 0.0;
      }
//
//  The transformations to eliminate the row of D
//  modify only a single element of Q'*B
//  beyond the first N, which is initially zero.
//
      qtbpj = 0.0;

      for ( k = j; k < n; k++ )
      {
//
//  Determine a Givens rotation which eliminates the
//  appropriate element in the current row of D.
//
        if ( sdiag[k] != 0.0 )
        {
          if ( fabs ( r[k+k*ldr] ) < fabs ( sdiag[k] ) )
          {
            cotan = r[k+k*ldr] / sdiag[k];
            s = 0.5 / sqrt ( 0.25 + 0.25 * cotan * cotan );
            c = s * cotan;
          }
          else
          {
            t = sdiag[k] / r[k+k*ldr];
            c = 0.5 / sqrt ( 0.25 + 0.25 * t * t );
            s = c * t;
          }
//
//  Compute the modified diagonal element of R and
//  the modified element of (Q'*B,0).
//
          r[k+k*ldr] = c * r[k+k*ldr] + s * sdiag[k];
          temp = c * wa[k] + s * qtbpj;
          qtbpj = - s * wa[k] + c * qtbpj;
          wa[k] = temp;
//
//  Accumulate the tranformation in the row of S.
//
          for ( i = k + 1; i < n; i++ )
          {
            temp = c * r[i+k*ldr] + s * sdiag[i];
            sdiag[i] = - s * r[i+k*ldr] + c * sdiag[i];
            r[i+k*ldr] = temp;
          }
        }
      }
    }
//
//  Store the diagonal element of S and restore
//  the corresponding diagonal element of R.
//
    sdiag[j] = r[j+j*ldr];
    r[j+j*ldr] = x[j];
  }
//
//  Solve the triangular system for Z.  If the system is
//  singular, then obtain a least squares solution.
//
  nsing = n;

  for ( j = 0; j < n; j++ )
  {
    if ( sdiag[j] == 0.0 && nsing == n )
    {
      nsing = j;
    }

    if ( nsing < n )
    {
      wa[j] = 0.0;
    }
  }

  for ( j = nsing - 1; 0 <= j; j-- )
  {
    sum2 = 0.0;
    for ( i = j + 1; i < nsing; i++ )
    {
      sum2 = sum2 + wa[i] *r[i+j*ldr];
    }
    wa[j] = ( wa[j] - sum2 ) / sdiag[j];
  }
//
//  Permute the components of Z back to components of X.
//
  for ( j = 0; j < n; j++ )
  {
    l = ipvt[j];
    x[l] = wa[j];
  }
//
//  Free memory.
//
  delete [] wa;

  return;
}
//****************************************************************************80

void r1mpyq ( int m, int n, double a[], int lda, double v[], double w[] )

//****************************************************************************80
//
//  Purpose:
//
//    r1mpyq() multiplies an M by N matrix A by the Q factor.
//
//  Discussion:
//
//    Given an M by N matrix A, this function computes a*q where
//    q is the product of 2*(n - 1) transformations
//
//      gv(n-1)*...*gv(1)*gw(1)*...*gw(n-1)
//
//    and gv(i), gw(i) are givens rotations in the (i,n) plane which
//    eliminate elements in the i-th and n-th planes, respectively.
//
//    Q itself is not given, rather the information to recover the
//    GV and GW rotations is supplied.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    05 April 2010
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//    Input, int M, the number of rows of A.
//
//    Input, int N, the number of columns of A.
//
//    Input/output, double A[M*N].  On input, the matrix to be postmultiplied 
//    by the orthogonal matrix Q described above.  On output, the value of A*Q.
//
//    Input, int LDA, a positive value not less than M
//    which specifies the leading dimension of the array A.
//
//    Input, double V[N].  V(I) must contain the information necessary to 
//    recover the givens rotation GV(I) described above.
//
//    Input, double W[N], contains the information necessary to recover the
//    Givens rotation gw(i) described above.
//
{
  double c;
  int i;
  int j;
  double s;
  double temp;
//
//  Apply the first set of Givens rotations to A.
//
  for ( j = n - 2; 0 <= j; j-- )
  {
    if ( 1.0 < fabs ( v[j] ) )
    {
      c = 1.0 / v[j];
      s = sqrt ( 1.0 - c * c );
    }
    else
    {
      s = v[j];
      c = sqrt ( 1.0 - s * s );
    }
    for ( i = 0; i < m; i++ )
    {
      temp           = c * a[i+j*lda] - s * a[i+(n-1)*lda];
      a[i+(n-1)*lda] = s * a[i+j*lda] + c * a[i+(n-1)*lda];
      a[i+j*lda]     = temp;
    }
  }
//
//  Apply the second set of Givens rotations to A.
//
  for ( j = 0; j < n - 1; j++ )
  {
    if ( 1.0 < fabs ( w[j] ) )
    {
      c = 1.0 / w[j];
      s = sqrt ( 1.0 - c * c );
    }
    else
    {
      s = w[j];
      c = sqrt ( 1.0 - s * s );
    }
    for ( i = 0; i < m; i++ )
    {
      temp           =   c * a[i+j*lda] + s * a[i+(n-1)*lda];
      a[i+(n-1)*lda] = - s * a[i+j*lda] + c * a[i+(n-1)*lda];
      a[i+j*lda]     = temp;
    }
  }

  return;
}
//****************************************************************************80

bool r1updt ( int m, int n, double s[], int ls, double u[], double v[],
  double w[] )

//****************************************************************************80
//
//  Purpose:
//
//    r1upd() updates the Q factor after a rank one update of the matrix.
//
//  Discussion:
//
//    Given an M by N lower trapezoidal matrix S, an M-vector U,
//    and an N-vector V, the problem is to determine an
//    orthogonal matrix Q such that
//
//      (S + U*V') * Q
//
//    is again lower trapezoidal.
//
//    This function determines q as the product of 2*(n - 1) transformations
//
//      gv(n-1)*...*gv(1)*gw(1)*...*gw(n-1)
//
//    where gv(i), gw(i) are givens rotations in the (i,n) plane
//    which eliminate elements in the i-th and n-th planes,
//    respectively. 
//
//    Q itself is not accumulated, rather the
//    information to recover the gv, gw rotations is returned.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 April 2010
//
//  Author:
//
//    Original FORTRAN77 version by Jorge More, Burt Garbow, Ken Hillstrom.
//    C++ version by John Burkardt.
//
//  Reference:
//
//    Jorge More, Burton Garbow, Kenneth Hillstrom,
//    User Guide for MINPACK-1,
//    Technical Report ANL-80-74,
//    Argonne National Laboratory, 1980.
//
//  Parameters:
//
//    Input, int M, the number of rows of S.
//
//    Input, int N, the number of columns of S.  N must not exceed M.
//
//    Input/output, double S[LS].  On input, the lower trapezoidal matrix S 
//    stored by columns.  On output, the lower trapezoidal matrix produced 
//    as described above.
//
//    Input, int LS, a positive value not less than (N*(2*M-N+1))/2.
//
//    Input, double U[M], contains the vector U.
//
//    Input/output, double V[N].  On input, the vector v.  On output,
//    information necessary to recover the givens rotation gv(i) described above.
//
//       w is an output array of length m. w(i) contains information
//         necessary to recover the givens rotation gw(i) described
//         above.
//
//       sing is a logical output variable. sing is set true if any
//         of the diagonal elements of the output s are zero. otherwise
//         sing is set false.
//
{
  double cotan;
  double cs;
  double giant;
  int i;
  int j;
  int jj;
  int l;
  int nm1;
  const double p25 = 0.25;
  const double p5 = 0.5;
  double sn;
  bool sing;
  double tan;
  double tau;
  double temp;
//
//  Because of the computation of the pointer JJ, this function was
//  converted from FORTRAN77 to C++ in a conservative way.  All computations
//  are the same, and only array indexing is adjusted.
//
//  GIANT is the largest magnitude.
//
  giant = r8_huge ( );
//
//  Initialize the diagonal element pointer.
//
  jj = ( n * ( 2 * m - n + 1 ) ) / 2 - ( m - n );
//
//  Move the nontrivial part of the last column of S into W.
//
  l = jj;
  for ( i = n; i <= m; i++ )
  {
    w[i-1] = s[l-1];
    l = l + 1;
  }
//
//  Rotate the vector V into a multiple of the N-th unit vector
//  in such a way that a spike is introduced into W.
//
  nm1 = n - 1;

  for ( j = n - 1; 1 <= j; j-- )
  {
    jj = jj - ( m - j + 1 );
    w[j-1] = 0.0;

    if ( v[j-1] != 0.0 )
    {
//
//  Determine a Givens rotation which eliminates the J-th element of V.
//
      if ( fabs ( v[n-1] ) < fabs ( v[j-1] ) )
      {
        cotan = v[n-1] / v[j-1];
        sn = p5 / sqrt ( p25 + p25 * cotan * cotan );
        cs = sn * cotan;
        tau = 1.0;
        if ( 1.0 < fabs ( cs ) * giant )
        {
          tau = 1.0 / cs;
        }
      }
      else
      {
        tan = v[j-1] / v[n-1];
        cs = p5 / sqrt ( p25 + p25 * tan * tan );
        sn = cs * tan;
        tau = sn;
      }
//
//  Apply the transformation to V and store the information
//  necessary to recover the Givens rotation.
//
      v[n-1] = sn * v[j-1] + cs * v[n-1];
      v[j-1] = tau;
//
//  Apply the transformation to S and extend the spike in W.
//
      l = jj;
      for ( i = j; i <= m; i++ )
      {
        temp   = cs * s[l-1] - sn * w[i-1];
        w[i-1] = sn * s[l-1] + cs * w[i-1];
        s[l-1] = temp;
        l = l + 1;
      }
    }
  }
//
//  Add the spike from the rank 1 update to W.
//
  for ( i = 1; i <= m; i++ )
  {
     w[i-1] = w[i-1] + v[n-1] * u[i-1];
  }
//
//  Eliminate the spike.
//
  sing = false;

  for ( j = 1; j <= nm1; j++ )
  {
//
//  Determine a Givens rotation which eliminates the
//  J-th element of the spike.
//
    if ( w[j-1] != 0.0 )
    {

      if ( fabs ( s[jj-1] ) < fabs ( w[j-1] ) )
      {
        cotan = s[jj-1] / w[j-1];
        sn = p5 / sqrt ( p25 + p25 * cotan * cotan );
        cs = sn * cotan;
        tau = 1.0;
        if ( 1.0 < fabs ( cs ) * giant )
        {
          tau = 1.0 / cs;
        }
      }
      else
      {
        tan = w[j-1] / s[jj-1];
        cs = p5 / sqrt ( p25 + p25 * tan * tan );
        sn = cs * tan;
        tau = sn;
      }
//
//  Apply the transformation to s and reduce the spike in w.
//
      l = jj;

      for ( i = j; i <= m; i++ )
      {
        temp   =   cs * s[l-1] + sn * w[i-1];
        w[i-1] = - sn * s[l-1] + cs * w[i-1];
        s[l-1] = temp;
        l = l + 1;
      }
//
//  Store the information necessary to recover the givens rotation.
//
      w[j-1] = tau;
    }
//
//  Test for zero diagonal elements in the output s.
//
    if ( s[jj-1] == 0.0 )
    {
      sing = true;
    }
    jj = jj + ( m - j + 1 );
  }
//
//  Move W back into the last column of the output S.
//
  l = jj;
  for ( i = n; i <= m; i++ )
  {
    s[l-1] = w[i-1];
    l = l + 1;
  }
  if ( s[jj-1] == 0.0 )
  {
    sing = true;
  }
  return sing;
}
//****************************************************************************80

double r8_epsilon ( )

//****************************************************************************80
//
//  Purpose:
//
//    r8_epsilon() returns the roundoff unit.
//
//  Discussion:
//
//    The roundoff unit is a number R which is a power of 2 with the
//    property that, to the precision of the computer's arithmetic,
//      1 < 1 + R
//    but
//      1 = ( 1 + R / 2 )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    01 September 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Output, double R8_EPSILON, the R8 round-off unit.
//
{
  const double value = 2.220446049250313E-016;

  return value;
}
//****************************************************************************80

double r8_huge ( )

//****************************************************************************80
//
//  Purpose:
//
//    r8_huge() returns a "huge" R8.
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
//  Output:
//
//    double R8_HUGE, a "huge" R8 value.
//
{
  double value;

  value = 1.0E+30;

  return value;
}
//****************************************************************************80

double r8_max ( double x, double y )

//****************************************************************************80
//
//  Purpose:
//
//    r8_max() returns the maximum of two R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, Y, the quantities to compare.
//
//    Output, double R8_MAX, the maximum of X and Y.
//
{
  double value;

  if ( y < x )
  {
    value = x;
  }
  else
  {
    value = y;
  }
  return value;
}
//****************************************************************************80

double r8_min ( double x, double y )

//****************************************************************************80
//
//  Purpose:
//
//    r8_min() returns the minimum of two R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, Y, the quantities to compare.
//
//    Output, double R8_MIN, the minimum of X and Y.
//
{
  double value;

  if ( y < x )
  {
    value = y;
  }
  else
  {
    value = x;
  }
  return value;
}
//****************************************************************************80

double r8_tiny ( )

//****************************************************************************80
//
//  Purpose:
//
//    r8_tiny() returns a "tiny" R8.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    08 March 2007
//
//  Author:
//
//    John Burkardt
//
//  Output:
//
//    double R8_TINY, a "tiny" R8 value.
//
{
  double value;

  value = 0.4450147717014E-307;

  return value;
}
//****************************************************************************80

double r8_uniform_01 ( int &seed )

//****************************************************************************80
//
//  Purpose:
//
//    r8_uniform_01() returns a unit pseudorandom R8.
//
//  Discussion:
//
//    This routine implements the recursion
//
//      seed = ( 16807 * seed ) mod ( 2^31 - 1 )
//      u = seed / ( 2^31 - 1 )
//
//    The integer arithmetic never requires more than 32 bits,
//    including a sign bit.
//
//    If the initial seed is 12345, then the first three computations are
//
//      Input     Output      R8_UNIFORM_01
//      SEED      SEED
//
//         12345   207482415  0.096616
//     207482415  1790989824  0.833995
//    1790989824  2035175616  0.947702
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Second Edition,
//    Springer, 1987,
//    ISBN: 0387964673,
//    LC: QA76.9.C65.B73.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, December 1986, pages 362-376.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998,
//    ISBN: 0471134031,
//    LC: T57.62.H37.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, Number 2, 1969, pages 136-143.
//
//  Parameters:
//
//    Input/output, int &SEED, the "seed" value.  Normally, this
//    value should not be 0.  On output, SEED has been updated.
//
//    Output, double R8_UNIFORM_01, a new pseudorandom variate, 
//    strictly between 0 and 1.
//
{
  const int i4_huge = 2147483647;
  int k;
  double r;

  if ( seed == 0 )
  {
    cerr << "\n";
    cerr << "R8_UNIFORM_01 - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit ( 1 );
  }

  k = seed / 127773;

  seed = 16807 * ( seed - k * 127773 ) - k * 2836;

  if ( seed < 0 )
  {
    seed = seed + i4_huge;
  }
  r = ( double ) ( seed ) * 4.656612875E-10;

  return r;
}
//****************************************************************************80

double *r8mat_mm_new ( int n1, int n2, int n3, double a[], double b[] )

//****************************************************************************80
//
//  Purpose:
//
//    r8mat_mm_new() multiplies two matrices.
//
//  Discussion:
//
//    An R8MAT is a doubly dimensioned array of R8 values, stored as a vector
//    in column-major order.
//
//    For this routine, the result is returned as the function value.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    18 October 2005
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N1, N2, N3, the order of the matrices.
//
//    Input, double A[N1*N2], double B[N2*N3], the matrices to multiply.
//
//    Output, double R8MAT_MM_NEW[N1*N3], the product matrix C = A * B.
//
{
  double *c;
  int i;
  int j;
  int k;

  c = new double[n1*n3];

  for ( i = 0; i < n1; i++ )
  {
    for ( j = 0; j < n3; j++ )
    {
      c[i+j*n1] = 0.0;
      for ( k = 0; k < n2; k++ )
      {
        c[i+j*n1] = c[i+j*n1] + a[i+k*n1] * b[k+j*n2];
      }
    }
  }

  return c;
}
//****************************************************************************80

void r8mat_print ( int m, int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    r8mat_print() prints an R8MAT.
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
//  Input:
//
//    int M, the number of rows in A.
//
//    int N, the number of columns in A.
//
//    double A[M*N], the M by N matrix.
//
//    string TITLE, a title.
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
//    r8mat_print_some() prints some of an R8MAT.
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
//    10 September 2009
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
//
//  Print the columns of the matrix, in strips of 5.
//
  for ( j2lo = jlo; j2lo <= jhi; j2lo = j2lo + INCX )
  {
    j2hi = j2lo + INCX - 1;
    j2hi = i4_min ( j2hi, n );
    j2hi = i4_min ( j2hi, jhi );

    cout << "\n";
//
//  For each column J in the current range...
//
//  Write the header.
//
    cout << "  Col:    ";
    for ( j = j2lo; j <= j2hi; j++ )
    {
      cout << setw(7) << j << "       ";
    }
    cout << "\n";
    cout << "  Row\n";
    cout << "\n";
//
//  Determine the range of the rows in this strip.
//
    i2lo = i4_max ( ilo, 1 );
    i2hi = i4_min ( ihi, m );

    for ( i = i2lo; i <= i2hi; i++ )
    {
//
//  Print out (up to) 5 entries in row I, that lie in the current strip.
//
      cout << setw(5) << i << "  ";
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

void r8vec_print ( int n, double a[], string title )

//****************************************************************************80
//
//  Purpose:
//
//    r8vec_print() prints an R8VEC.
//
//  Discussion:
//
//    An R8VEC is a vector of R8's.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 August 2004
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int N, the number of components of the vector.
//
//    Input, double A[N], the vector to be printed.
//
//    Input, string TITLE, a title.
//
{
  int i;

  cout << "\n";
  cout << title << "\n";
  cout << "\n";
  for ( i = 0; i < n; i++ )
  {
    cout << "  " << setw(8)  << i
         << "  " << setw(14) << a[i]  << "\n";
  }

  return;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    timestamp() prints the current YMDHMS date as a time stamp.
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
 
