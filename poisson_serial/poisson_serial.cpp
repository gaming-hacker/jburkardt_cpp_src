# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <cmath>

using namespace std;

# define NX 11
# define NY 11

int main ( int argc, char *argv[] );
double r8mat_rms ( int m, int n, double a[NX][NY] );
void rhs ( int nx, int ny, double f[NX][NY] );
void sweep ( int nx, int ny, double dx, double dy, double f[NX][NY], 
  double u[NX][NY], double unew[NX][NY] );
void timestamp ( );
double u_exact ( double x, double y );
double uxxyy_exact ( double x, double y );

//****************************************************************************80

int main ( int argc, char *argv[] )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for POISSON_SERIAL.
//
//  Discussion:
//
//    POISSON_SERIAL is a program for solving the Poisson problem.
//
//    This program runs serially.  Its output is used as a benchmark for
//    comparison with similar programs run in a parallel environment.
//
//    The Poisson equation
//
//      - DEL^2 U(x,y) = F(x,y)
//
//    is solved on the unit square [0,1] x [0,1] using a grid of NX by
//    NX evenly spaced points.  The first and last points in each direction
//    are boundary points.
//
//    The boundary conditions and F are set so that the exact solution is
//
//      U(x,y) = sin ( pi * x * y )
//
//    so that
//
//      - DEL^2 U(x,y) = pi^2 * ( x^2 + y^2 ) * sin ( pi * x * y )
//
//    The Jacobi iteration is repeatedly applied until convergence is detected.
//
//    For convenience in writing the discretized equations, we assume that NX = NY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 October 2011
//
//  Author:
//
//    John Burkardt
//
{
  bool converged;
  double diff;
  double dx;
  double dy;
  double error;
  double f[NX][NY];
  int i;
  int it;
  int it_max = 1000;
  int j;
  int nx = NX;
  int ny = NY;
  double tolerance = 0.000001;
  double u[NX][NY];
  double u_norm;
  double udiff[NX][NY];
  double uexact[NX][NY];
  double unew[NX][NY];
  double unew_norm;
  double x;
  double y;

  dx = 1.0 / ( double ) ( nx - 1 );
  dy = 1.0 / ( double ) ( ny - 1 );
//
//  Print a message.
//
  timestamp ( );
  cout << "\n";
  cout << "POISSON_SERIAL:\n";
  cout << "  C++ version\n";
  cout << "  A program for solving the Poisson equation.\n";
  cout << "\n";
  cout << "  -DEL^2 U = F(X,Y)\n";
  cout << "\n";
  cout << "  on the rectangle 0 <= X <= 1, 0 <= Y <= 1.\n";
  cout << "\n";
  cout << "  F(X,Y) = pi^2 * ( x^2 + y^2 ) * sin ( pi * x * y )\n";
  cout << "\n";
  cout << "  The number of interior X grid points is " << nx << "\n";
  cout << "  The number of interior Y grid points is " << ny << "\n";
  cout << "  The X grid spacing is " << dx << "\n";
  cout << "  The Y grid spacing is " << dy << "\n";
//
//  Initialize the data.
//
  rhs ( nx, ny, f );
//
//  Set the initial solution estimate.
//  We are "allowed" to pick up the boundary conditions exactly.
//
  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      if ( i == 0 || i == nx - 1 || j == 0 || j == ny - 1 )
      {
        unew[i][j] = f[i][j];
      }
      else
      {
        unew[i][j] = 0.0;
      }
    }
  }
  unew_norm = r8mat_rms ( nx, ny, unew );
//
//  Set up the exact solution.
//
  for ( j = 0; j < ny; j++ )
  {
    y = ( double ) ( j ) / ( double ) ( ny - 1 );
    for ( i = 0; i < nx; i++ )
    {
      x = ( double ) ( i ) / ( double ) ( nx - 1 );
      uexact[i][j] = u_exact ( x, y );
    }
  }
  u_norm = r8mat_rms ( nx, ny, uexact );
  cout << "  RMS of exact solution = " << u_norm << "\n";
//
//  Do the iteration.
//
  converged = false;

  cout << "\n";
  cout << "  Step    ||Unew||     ||Unew-U||     ||Unew-Exact||\n";
  cout << "\n";

  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      udiff[i][j] = unew[i][j] - uexact[i][j];
    }
  }
  error = r8mat_rms ( nx, ny, udiff );
  cout << "  " << setw(4) << 0
       << "  " << setw(14) << unew_norm
       << "  " << "              "
       << "  " << setw(14) << error << "\n";

  for ( it = 1; it <= it_max; it++ )
  {
    for ( j = 0; j < ny; j++ )
    {
      for ( i = 0; i < nx; i++ )
      {
        u[i][j] = unew[i][j];
      }
    }
//
//  UNEW is derived from U by one Jacobi step.
//
    sweep ( nx, ny, dx, dy, f, u, unew );
//
//  Check for convergence.
//
    u_norm = unew_norm;
    unew_norm = r8mat_rms ( nx, ny, unew );

    for ( j = 0; j < ny; j++ )
    {
      for ( i = 0; i < nx; i++ )
      {
        udiff[i][j] = unew[i][j] - u[i][j];
      }
    }
    diff = r8mat_rms ( nx, ny, udiff );

    for ( j = 0; j < ny; j++ )
    {
      for ( i = 0; i < nx; i++ )
      {
        udiff[i][j] = unew[i][j] - uexact[i][j];
      }
    }
    error = r8mat_rms ( nx, ny, udiff );

    cout << "  " << setw(4)  << it
         << "  " << setw(14) << unew_norm
         << "  " << setw(14) << diff
         << "  " << setw(14) << error << "\n";

    if ( diff <= tolerance )
    {
      converged = true;
      break;
    }

  }

  if ( converged )
  {
    cout << "  The iteration has converged.\n";
  }
  else
  {
    cout << "  The iteration has NOT converged.\n";
  }
//
//  Terminate.
//
  cout << "\n";
  cout << "POISSON_SERIAL:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

double r8mat_rms ( int nx, int ny, double a[NX][NY] )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_RMS returns the RMS norm of a vector stored as a matrix.
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
//    Input, int NX, NY, the number of rows and columns in A.
//
//    Input, double A[NX][NY], the vector.
//
//    Output, double R8MAT_RMS, the root mean square of the entries of A.
//
{
  int i;
  int j;
  double v;

  v = 0.0;

  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      v = v + a[i][j] * a[i][j];
    }
  }
  v = sqrt ( v / ( double ) ( nx * ny )  );

  return v;
}
//****************************************************************************80

void rhs ( int nx, int ny, double f[NX][NY] )

//****************************************************************************80
//
//  Purpose:
//
//    RHS initializes the right hand side "vector".
//
//  Discussion:
//
//    It is convenient for us to set up RHS as a 2D array.  However, each
//    entry of RHS is really the right hand side of a linear system of the
//    form
//
//      A * U = F
//
//    In cases where U(I,J) is a boundary value, then the equation is simply
//
//      U(I,J) = F(i,j)
//
//    and F(I,J) holds the boundary data.
//
//    Otherwise, the equation has the form
//
//      (1/DX^2) * ( U(I+1,J)+U(I-1,J)+U(I,J-1)+U(I,J+1)-4*U(I,J) ) = F(I,J)
//
//    where DX is the spacing and F(I,J) is the value at X(I), Y(J) of
//
//      pi^2 * ( x^2 + y^2 ) * sin ( pi * x * y )
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NX, NY, the X and Y grid dimensions.
//
//    Output, double F[NX][NY], the initialized right hand side data.
//
{
  double fnorm;
  int i;
  int j;
  double x;
  double y;
//
//  The "boundary" entries of F store the boundary values of the solution.
//  The "interior" entries of F store the right hand sides of the Poisson equation.
//
  for ( j = 0; j < ny; j++ )
  {
    y = ( double ) ( j ) / ( double ) ( ny - 1 );
    for ( i = 0; i < nx; i++ )
    {
      x = ( double ) ( i ) / ( double ) ( nx - 1 );
      if ( i == 0 || i == nx - 1 || j == 0 || j == ny - 1 )
      {
        f[i][j] = u_exact ( x, y );
      }
      else
      {
        f[i][j] = - uxxyy_exact ( x, y );
      }
    }
  }

  fnorm = r8mat_rms ( nx, ny, f );

  cout << "  RMS of F = " << fnorm << "\n";

  return;
}
//****************************************************************************80

void sweep ( int nx, int ny, double dx, double dy, double f[NX][NY], 
  double u[NX][NY], double unew[NX][NY] )

//****************************************************************************80
//
//  Purpose:
//
//   SWEEP carries out one step of the Jacobi iteration.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    26 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int NX, NY, the X and Y grid dimensions.
//
//    Input, double DX, DY, the spacing between grid points.
//
//    Input, double F[NX][NY], the right hand side data.
//
//    Input, double U[NX][NY], the previous solution estimate.
//
//    Output, double UNEW[NX][NY], the updated solution estimate.
//
{
  int i;
  int j;

  for ( j = 0; j < ny; j++ )
  {
    for ( i = 0; i < nx; i++ )
    {
      if ( i == 0 || j == 0 || i == nx - 1 || j == ny - 1 )
      {
        unew[i][j] = f[i][j];
      }
      else
      { 
        unew[i][j] = 0.25 * ( 
          u[i-1][j] + u[i][j+1] + u[i][j-1] + u[i+1][j] + f[i][j] * dx * dy );
      }
    }
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
//****************************************************************************80

double u_exact ( double x, double y )

//****************************************************************************80
//
//  Purpose:
//
//    U_EXACT evaluates the exact solution.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, Y, the coordinates of a point.
//
//    Output, double U_EXACT, the value of the exact solution 
//    at (X,Y).
//
{
  double r8_pi = 3.141592653589793;
  double value;

  value = sin ( r8_pi * x * y );

  return value;
}
//****************************************************************************80

double uxxyy_exact ( double x, double y )

//****************************************************************************80
//
//  Purpose:
//
//    UXXYY_EXACT evaluates ( d/dx d/dx + d/dy d/dy ) of the exact solution.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 October 2011
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double X, Y, the coordinates of a point.
//
//    Output, double UXXYY_EXACT, the value of 
//    ( d/dx d/dx + d/dy d/dy ) of the exact solution at (X,Y).
//
{
  double r8_pi = 3.141592653589793;
  double value;

  value = - r8_pi * r8_pi * ( x * x + y * y ) * sin ( r8_pi * x * y );

  return value;
}
# undef NX
# undef NY
