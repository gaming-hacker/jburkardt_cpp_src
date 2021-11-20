// File recommented by recomment.cpp
// on Jan 22 2017 at 09:01:50.
//
# include <cmath>
# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "quaternions.hpp"

int main ( );
void q8_conjugate_test ( );
void q8_exponentiate_test ( );
void q8_inverse_test ( );
void q8_multiply_test ( );
void q8_multiply2_test ( );
void q8_norm_test ( );
void q8_normal_01_test ( );
void q8_transpose_print_test ( );
void r8_acos_test ( );
void r8mat_print_test ( );
void r8mat_print_some_test ( );
void r8vec_print_test ( );
void r8vec_uniform_01_new_test ( );
void rotation_axis_vector_test ( );
void rotation_axis2mat_test ( );
void rotation_axis2quat_test ( );
void rotation_mat_vector_test ( );
void rotation_mat2axis_test ( );
void rotation_mat2quat_test ( );
void rotation_quat_vector_test ( );
void rotation_quat2axis_test ( );
void rotation_quat2mat_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for QUATERNIONS_TEST.
//
//  Discussion:
//
//    QUATERNIONS_TEST tests the QUATERNIONS library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "QUATERNIONS_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the QUATERNIONS library.\n";

  q8_conjugate_test ( );
  q8_exponentiate_test ( );
  q8_inverse_test ( );
  q8_multiply_test ( );
  q8_multiply2_test ( );
  q8_norm_test ( );
  q8_normal_01_test ( );
  q8_transpose_print_test ( );

  r8_acos_test ( );

  r8mat_print_test ( );
  r8mat_print_some_test ( );

  r8vec_print_test ( );
  r8vec_uniform_01_new_test ( );

  rotation_axis_vector_test ( );
  rotation_axis2mat_test ( );
  rotation_axis2quat_test ( );

  rotation_mat_vector_test ( );
  rotation_mat2axis_test ( );
  rotation_mat2quat_test ( );

  rotation_quat_vector_test ( );
  rotation_quat2axis_test ( );
  rotation_quat2mat_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "QUATERNIONS_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void q8_conjugate_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Q8_CONJUGATE_TEST tests Q8_CONJUGATE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int seed;
  double *q1;
  double *q2;

  seed = 123456789;

  cout << "\n";
  cout << "Q8_CONJUGATE_TEST\n";
  cout << "  Q8_CONJUGATE conjugates a quaternion;\n";

  for ( i = 1; i <= 5; i++ )
  {
    q1 = q8_normal_01 ( seed );
    q2 = q8_conjugate ( q1 );

    cout << "\n";
    q8_transpose_print ( q1, "  q1 = q8_normal_01 ( seed ):" );
    q8_transpose_print ( q2, "  q2 = q8_conjugate ( q1 ):  " );

    delete [] q1;
    delete [] q2;
  }

  return;
}
//****************************************************************************80

void q8_exponentiate_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Q8_EXPONENTIATE_TEST tests Q8_EXPONENTIATE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double *q1;
  double *q2;
  int seed;

  seed = 123456789;

  cout << "\n";
  cout << "Q8_EXPONENTIATE_TEST\n";
  cout << "  Q8_EXPONENTIATE exponentiates a quaternion\n";

  for ( i = 1; i <= 5; i++ )
  {
    q1 = q8_normal_01 ( seed );
    q2 = q8_exponentiate ( q1 );

    cout << "\n";
    q8_transpose_print ( q1, "  q1 = q8_normal_01 ( seed ):" );
    q8_transpose_print ( q2, "  q2 = q8_exponentiate ( q1 ):" ); 

    delete [] q1;
    delete [] q2; 
  }

  return;
}
//****************************************************************************80

void q8_inverse_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Q8_INVERSE_TEST tests Q8_INVERSE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double *q1;
  double *q2;
  double *q3;
  int seed;

  seed = 123456789;

  cout << "\n";
  cout << "Q8_INVERSE_TEST\n";
  cout << "  Q8_INVERSE inverts a quaternion\n";

  for ( i = 1; i <= 5; i++ )
  {
    q1 = q8_normal_01 ( seed );
    q2 = q8_inverse ( q1 );
    q3 = q8_multiply ( q1, q2 );

    cout << "\n";
    q8_transpose_print ( q1, "  q1 = q8_normal_01 ( seed ):" );
    q8_transpose_print ( q2, "  q2 = q8_inverse ( q1 ):    " );
    q8_transpose_print ( q3, "  q3 = q8_multiply ( q1, q2 ):    " );

    delete [] q1;
    delete [] q2;
    delete [] q3; 
  }

  return;
}
//****************************************************************************80

void q8_multiply_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Q8_MULTIPLY_TEST tests Q8_MULTIPLY.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double *q1;
  double *q2;
  double *q3;
  int seed;

  seed = 123456789;

  cout << "\n";
  cout << "Q8_MULTIPLY_TEST\n";
  cout << "  Q8_MULTIPLY multiplies two quaternions\n";

  for ( i = 1; i <= 5; i++ )
  {
    q1 = q8_normal_01 ( seed );
    q2 = q8_normal_01 ( seed );
    q3 = q8_multiply ( q1, q2 );

    cout << "\n";
    q8_transpose_print ( q1, "  q1 = q8_normal_01 ( seed ) :" );
    q8_transpose_print ( q2, "  q2 = q8_normal_01 ( seed ) :" );
    q8_transpose_print ( q3, "  q3 = q8_multiply ( q1, q2 ):" );

    delete [] q1;
    delete [] q2;
    delete [] q3;  
  }

  return;
}
//****************************************************************************80

void q8_multiply2_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Q8_MULTIPLY2_TEST tests Q8_MULTIPLY2.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double *q1;
  double *q2;
  double *q3;
  int seed;

  seed = 123456789;

  cout << "\n";
  cout << "Q8_MULTIPLY2_TEST\n";
  cout << "  Q8_MULTIPLY2 multiplies two quaternions using a matrix\n";

  for ( i = 1; i <= 5; i++ )
  {
    q1 = q8_normal_01 ( seed );
    q2 = q8_normal_01 ( seed );
    q3 = q8_multiply2 ( q1, q2 );

    cout << "\n";
    q8_transpose_print ( q1, "  q1 = q8_normal_01 ( seed )  :" );
    q8_transpose_print ( q2, "  q2 = q8_normal_01 ( seed )  :" );
    q8_transpose_print ( q3, "  q3 = q8_multiply2 ( q1, q2 ):" );

    delete [] q1;
    delete [] q2;
    delete [] q3;  
  }

  return;
}
//****************************************************************************80

void q8_normal_01_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Q8_NORMAL_01_TEST tests Q8_NORMAL_01.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double *q;
  int seed;

  seed = 123456789;

  cout << "\n";
  cout << "Q8_NORMAL_01_TEST\n";
  cout << "  Q8_NORMAL_01 computes a normally distributed quaternion.\n";
  cout << "\n";

  for ( i = 1; i <= 5; i++ )
  {
    q = q8_normal_01 ( seed );
    q8_transpose_print ( q, "Sample quaternion:" );
    delete [] q;
  }

  return;
}
//****************************************************************************80

void q8_norm_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Q8_NORM_TEST tests Q8_NORM.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  double *q;
  int seed;
  double value;

  seed = 123456789;

  cout << "\n";
  cout << "Q8_NORM_TEST\n";
  cout << "  Q8_NORM computes the norm of a quaternion.\n";

  for ( i = 1; i <= 5; i++ )
  {
    cout << "\n";
    q = q8_normal_01 ( seed );
    q8_transpose_print ( q, "  q = q8_normal_01(seed):" );
    value = q8_norm ( q );
    cout << "  q8_norm(q) = " << value << "\n";
    delete [] q;
  }

  return;
}
//****************************************************************************80

void q8_transpose_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    Q8_TRANSPOSE_PRINT_TEST tests Q8_TRANSPOSE_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  int seed;
  double *q;

  seed = 123456789;

  cout << "\n";
  cout << "Q8_TRANSPOSE_PRINT_TEST\n";
  cout << "  Q8_TRANSPOSE_PRINT prints a quaternion 'transposed',\n";
  cout << "  that is, writing it as a row vector.\n";

  q = q8_normal_01 ( seed );

  q8_transpose_print ( q, "  The quaternion:" );

  delete [] q;

  return;
}
//****************************************************************************80

void r8_acos_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8_ACOS_TEST tests R8_ACOS.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 July 2014
//
//  Author:
//
//    John Burkardt
//
{
  double c;
  int test;

  cout << "\n";
  cout << "R8_ACOS_TEST\n";
  cout << "  R8_ACOS computes the arc-cosine of an angle.\n"; 
  cout << "\n";
  cout << "          C            R8_ACOS(C)        ACOS(C)\n";
  cout << "\n";

  for ( test = -1; test <= 13; test++ )
  {
    c = ( double ) ( test - 6 ) / ( double ) ( 6 );

    cout << setw(14) << c << "  "
         << setw(14) << r8_acos ( c );

    if ( -1.0 <= c && c <= 1.0 )
    {
      cout << "  " << setw(14) << acos ( c );
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void r8mat_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT_TEST tests R8MAT_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
# define M 6
# define N 4

  double a[M*N];
  int i;
  int j;
  int m = M;
  int n = N;

  cout << "\n";
  cout << "R8MAT_PRINT_TEST\n";
  cout << "  R8MAT_PRINT prints an R8MAT.\n";

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
  r8mat_print ( m, n, a, "  The matrix:" );

  return;
# undef M
# undef N
}
//****************************************************************************80

void r8mat_print_some_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8MAT_PRINT_SOME_TEST tests R8MAT_PRINT_SOME.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
# define M 6
# define N 4

  double a[M*N];
  int i;
  int j;
  int m = M;
  int n = N;

  cout << "\n";
  cout << "R8MAT_PRINT_SOME_TEST\n";
  cout << "  R8MAT_PRINT_SOME prints some of an R8MAT.\n";

  for ( j = 0; j < n; j++ )
  {
    for ( i = 0; i < m; i++ )
    {
      a[i+j*m] = ( double ) ( ( i + 1 ) * 10 + ( j + 1 ) );
    }
  }
  r8mat_print_some ( m, n, a, 2, 1, 4, 2, "  Rows 2:4, Cols 1:2:" );

  return;
# undef M
# undef N
}
//****************************************************************************80

void r8vec_print_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_PRINT_TEST tests R8VEC_PRINT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    31 August 2014
//
//  Author:
//
//    John Burkardt
//
{
  double a[4] = { 123.456, 0.000005, -1.0E+06, 3.14159265 };
  int n = 4;

  cout << "\n";
  cout << "R8VEC_PRINT_TEST\n";
  cout << "  R8VEC_PRINT prints an R8VEC.\n";

  r8vec_print ( n, a, "  The R8VEC:" );

  return;
}
//****************************************************************************80

void r8vec_uniform_01_new_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    R8VEC_UNIFORM_01_NEW_TEST tests R8VEC_UNIFORM_01_NEW.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    16 October 2006
//
//  Author:
//
//    John Burkardt
//
{
# define N 10

  int j;
  double *r;
  int seed;

  cout << "\n";
  cout << "R8VEC_UNIFORM_01_NEW_TEST\n";
  cout << "  R8VEC_UNIFORM_01_NEW returns a random R8VEC\n";
  cout << "  with entries in [ 0.0, 1.0 ]\n";

  seed = 123456789;

  for ( j = 1; j <= 3; j++ )
  {
    cout << "\n";
    cout << "  Input SEED = " << seed << "\n";
    cout << "\n";

    r = r8vec_uniform_01_new ( N, seed );

    r8vec_print ( N, r, "  Random R8VEC:" );

    delete [] r;
  }

  return;
# undef N
}
//****************************************************************************80

void rotation_axis2mat_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_AXIS2MAT_TEST tests ROTATION_AXIS2MAT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double angle;
  double axis1[3] = { 0.2361737, -0.8814124, -0.4090649 };
  double axis2[3] = { 0.0, 0.0, 2.0 };
  double v1[3] = { 1.0, 4.0, 10.0 };
  double v2[3] = { 1.0, 1.0, 1.0 };
  double *w;

  cout << "\n";
  cout << "ROTATION_AXIS2MAT_TEST\n";
  cout << "  ROTATION_AXIS2MAT converts a rotation axis to a matrix.\n";

  r8vec_print ( 3, v1, "  The vector V:" );
  r8vec_print ( 3, axis1, "  The rotation axis:" );
  angle = 1.159804;
  cout << "\n";
  cout << "  The rotation angle is " << angle << "\n";

  a = rotation_axis2mat ( axis1, angle );

  r8mat_print ( 3, 3, a, "  The rotation matrix A:" );

  w = r8mat_mv_new ( 3, 3, a, v1 );

  r8vec_print ( 3, w, "  The rotated vector W = A * V:" );

  delete [] a;
  delete [] w;
//
//  Test an axis vector that does not have unit length.
//
  r8vec_print ( 3, v2, "  The vector V:" );
  r8vec_print ( 3, axis2, "  The rotation axis:" );

  angle = 90.0;
  angle = degrees_to_radians ( angle );

  cout << "\n";
  cout << "  The rotation angle is " << angle << "\n";

  a = rotation_axis2mat ( axis2, angle );

  r8mat_print ( 3, 3, a, "  The rotation matrix A:" );

  w = r8mat_mv_new ( 3, 3, a, v2 );

  r8vec_print ( 3, w, "  The rotated vector W = A * V:" );

  delete [] a;
  delete [] w;

  return;
}
//****************************************************************************80

void rotation_axis2quat_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_AXIS2QUAT_TEST tests ROTATION_AXIS2QUAT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double angle;
  double axis1[3] = { 0.2361737, -0.8814124, -0.4090649 };
  double axis2[3] = { 0.0, 0.0, 2.0 };
  double *q;
  double v1[3] = { 1.0, 4.0, 10.0 };
  double v2[3] = { 1.0, 1.0, 1.0 };
  double *w;

  cout << "\n";
  cout << "ROTATION_AXIS2QUAT_TEST\n";
  cout << "  ROTATION_AXIS2QUAT converts a rotation axis to a quaternion.\n";
 
  r8vec_print ( 3, v1, "  The vector V:" );
  r8vec_print ( 3, axis1, "  The rotation axis:" );

  angle = 1.159804;
  cout << "\n";
  cout << "  The rotation angle is " << angle << "\n";

  q = rotation_axis2quat ( axis1, angle );

  r8vec_print ( 4, q, "  The rotation quaternion Q:" );

  w = rotation_quat_vector ( q, v1 );

  r8vec_print ( 3, w, "  The rotated vector W:" );

  delete [] q;
  delete [] w;
//
//  Another test of ROTATION_AXIS_VECTOR with an axis vector
//  that does not have unit length.
//
  r8vec_print ( 3, v2, "  The vector V:" );
  r8vec_print ( 3, axis2, "  The rotation axis:" );

  angle = 90.0;
  angle = degrees_to_radians ( angle );

  cout << "\n";
  cout << "  The rotation angle is " << angle << "\n";
  q = rotation_axis2quat ( axis2, angle );

  r8vec_print ( 4, q, "  The rotation quaternion Q:" );

  w = rotation_quat_vector ( q, v2 );

  r8vec_print ( 3, w, "  The rotated vector W:" );

  delete [] q;
  delete [] w;

  return;
}
//****************************************************************************80

void rotation_axis_vector_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_AXIS_VECTOR_TEST tests ROTATION_AXIS_VECTOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double angle;
  double axis1[3] = { 0.2361737, -0.8814124, -0.4090649 };
  double axis2[3] = { 0.0, 0.0, 2.0 };
  double v1[3] = { 1.0, 4.0, 10.0 };
  double v2[3] = { 1.0, 1.0, 1.0 };
  double *w;

  angle = 1.159804;

  cout << "\n";
  cout << "ROTATION_AXIS_VECTOR_TEST\n";
  cout << "  ROTATION_AXIS_VECTOR applies an axis\n";
  cout << "  rotation to a vector.\n";

  r8vec_print ( 3, v1, "  The vector:" );

  r8vec_print ( 3, axis1, "  The rotation axis:" );

  cout << "\n";
  cout << "  The rotation angle is " << angle << "\n";

  w = rotation_axis_vector ( axis1, angle, v1 );

  r8vec_print ( 3, w, "  The rotated vector:" );

  delete [] w;
//
//  Another test of ROTATION_AXIS_VECTOR with an axis vector
//  that does not have unit length.
//
  r8vec_print ( 3, v2, "  The vector:" );
  r8vec_print ( 3, axis2, "  The rotation axis:" );

  angle = 90.0;
  angle = degrees_to_radians ( angle );

  cout << "\n";
  cout << "  The rotation angle is " << angle << "\n";

  w = rotation_axis_vector ( axis2, angle, v2 );

  r8vec_print ( 3, w, "  The rotated vector:" );

  delete [] w;

  return;
}
//****************************************************************************80

void rotation_mat2axis_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_MAT2AXIS_TEST tests ROTATION_MAT2AXIS.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double a[3*3] = {
    0.43301269, -0.5,        0.75,
    0.25,        0.86602539, 0.43301269,
   -0.86602539,  0.0,        0.5 };
  double *a2;
  double angle;
  double *axis;

  cout << "\n";
  cout << "ROTATION_MAT2AXIS_TEST\n";
  cout << "  ROTATION_MAT2AXIS computes a rotation axis\n";
  cout << "  and angle from a rotation matrix.\n";
  cout << "  ROTATION_AXIS2MAT computes a rotation matrix\n";
  cout << "  from a rotation axis and angle.\n";

  r8mat_print ( 3, 3, a, "  The rotation matrix:" );

  axis = new double[3];
  rotation_mat2axis ( a, axis, angle );

  r8vec_print ( 3, axis, "  The rotation axis:" );

  cout << "\n";
  cout << "  The rotation angle is " << angle << "\n";

  a2 = rotation_axis2mat ( axis, angle );

  r8mat_print ( 3, 3, a, "  The recovered rotation matrix:" );

  delete [] a2;
  delete [] axis;

  return;
}
//****************************************************************************80

void rotation_mat2quat_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_MAT2QUAT_TEST tests ROTATION_MAT2QUAT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double a[3*3] = {
    0.43301269, -0.5,        0.75,
    0.25,        0.86602539, 0.43301269,
   -0.86602539,  0.0,        0.5 };
  double *a2;
  double *q;

  cout << "\n";
  cout << "ROTATION_MAT2QUAT_TEST\n";
  cout << "  ROTATION_MAT2QUAT computes a quaternion\n";
  cout << "  from a rotation matrix.\n";
  cout << "  ROTATION_QUAT2MAT computes a rotation matrix\n";
  cout << "  from a quaternion.\n";

  r8mat_print ( 3, 3, a, "  The rotation matrix:" );

  q = rotation_mat2quat ( a );

  r8vec_print ( 4, q, "  The rotation quaternion Q:" );

  a2 = rotation_quat2mat ( q );

  r8mat_print ( 3, 3, a2, "  The recovered rotation matrix:" );

  delete [] a2;
  delete [] q;

  return;
}
//****************************************************************************80

void rotation_mat_vector_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_MAT_VECTOR_TEST tests ROTATION_MAT_VECTOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double a[3*3] = {
    0.43301269, -0.5,        0.75,
    0.25,        0.86602539, 0.43301269,
   -0.86602539,  0.0,        0.5 };
  double v[3] = { 1.0, 4.0, 10.0 };
  double *w;

  cout << "\n";
  cout << "ROTATION_MAT_VECTOR_TEST\n";
  cout << "  ROTATION_MAT_VECTOR applies a matrix\n";
  cout << "  rotation to a vector.\n";

  r8mat_print ( 3, 3, a, "  The rotation matrix:" );
  r8vec_print ( 3, v, "  The vector V:" );

  w = rotation_mat_vector ( a, v );
  r8vec_print ( 3, w, "  The rotated vector W = A * V:" );

  delete [] w;

  return;
}
//****************************************************************************80

void rotation_quat2axis_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_QUAT2AXIS_TEST tests ROTATION_QUAT2AXIS.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double angle;
  double *axis;
  double q[4] = { 0.836516, 0.12941, -0.482963, -0.224144 };
  double *q2;

  cout << "\n";
  cout << "ROTATION_QUAT2AXIS_TEST\n";
  cout << "  ROTATION_QUAT2AXIS computes a rotation axis\n";
  cout << "  and angle from a rotation quaternion.\n";
  cout << "  ROTATION_AXIS2QUAT computes a rotation\n";
  cout << "  quaternion from a rotation axis and angle.\n";

  r8vec_print ( 4, q, "  The rotation quaternion:" );

  axis = new double[3];
  rotation_quat2axis ( q, axis, angle );

  r8vec_print ( 3, axis, "  The rotation axis:" );

  cout << "\n";
  cout << "  The rotation angle is " << angle << "\n";

  q2 = rotation_axis2quat ( axis, angle );

  r8vec_print ( 4, q2, "  The recovered rotation quaternion:" );

  delete [] axis;
  delete [] q2;

  return;
}
//****************************************************************************80

void rotation_quat2mat_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_QUAT2MAT_TEST tests ROTATION_QUAT2MAT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double *a;
  double q[4] = { 0.836516, 0.12941, -0.482963, -0.224144 };
  double *q2;

  cout << "\n";
  cout << "ROTATION_QUAT2MAT_TEST\n";
  cout << "  ROTATION_QUAT2MAT computes a rotation axis\n";
  cout << "  from a rotation quaternion.\n";
  cout << "  ROTATION_MAT2QUAT computes a rotation\n";
  cout << "  quaternion from a rotation matrix.\n";

  r8vec_print ( 4, q, "  The rotation quaternion:" );

  a = rotation_quat2mat ( q );

  r8mat_print ( 3, 3, a, "  The rotation matrix:" );

  q2 = rotation_mat2quat ( a );

  r8vec_print ( 4, q2, "  The recovered rotation quaternion:" );

  delete [] a;
  delete [] q2;

  return;
}
//****************************************************************************80

void rotation_quat_vector_test ( )

//****************************************************************************80
//
//  Purpose:
//
//    ROTATION_QUAT_VECTOR_TEST tests ROTATION_QUAT_VECTOR.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//   06 August 2018
//
//  Author:
//
//    John Burkardt
//
{
  double q[4] = { 0.836516, 0.12941, -0.482963, -0.224144 };
  double v[3] = { 1.0, 4.0, 10.0 };
  double *w;

  cout << "\n";
  cout << "ROTATION_QUAT_VECTOR_TEST\n";
  cout << "  ROTATION_QUAT_VECTOR applies a quaternion\n";
  cout << "  rotation to a vector.\n";

  r8vec_print ( 4, q, "  The rotation quaternion:" );

  r8vec_print ( 3, v, "  The vector V:" );

  w = rotation_quat_vector ( q, v );
  r8vec_print ( 3, w, "  The rotated vector:" );

  delete [] w;

  return;
}

