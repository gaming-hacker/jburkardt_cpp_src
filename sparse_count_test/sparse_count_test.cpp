# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

# include "sparse_count.hpp"

int main ( );
void test01 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test02 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test03 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test04 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test05 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test06 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test07 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test08 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test09 ( int dim_min, int dim_max, int level_max_min, int level_max_max );
void test10 ( int dim_min, int dim_max, int level_max_min, int level_max_max );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for SPARSE_COUNT_TEST.
//
//  Discussion:
//
//    SPARSE_COUNT_TEST tests the SPARSE_COUNT library.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    11 September 2012
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Fabio Nobile, Raul Tempone, Clayton Webster,
//    A Sparse Grid Stochastic Collocation Method for Partial Differential
//    Equations with Random Input Data,
//    SIAM Journal on Numerical Analysis,
//    Volume 46, Number 5, 2008, pages 2309-2345.
//
{
  int dim_max;
  int dim_min;
  int level_max_max;
  int level_max_min;

  timestamp ( );
  cout << "\n";
  cout << "SPARSE_COUNT_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the SPARSE_COUNT library.\n";
//
//  CC_SE
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test01 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test01 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  CFN_E
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test02 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test02 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  F2_SE
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test03 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test03 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  GP_SE
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test04 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test04 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  OFN_E
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test05 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test05 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  ONN_E
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test06 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test06 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  ONN_L
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test07 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test07 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  OWN_E
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test08 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test08 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  OWN_L2
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test09 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test09 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  OWN_LS
//
  dim_min = 1;
  dim_max = 5;
  level_max_min = 0;
  level_max_max = 10;
  test10 ( dim_min, dim_max, level_max_min, level_max_max );

  dim_min = 6;
  dim_max = 10;
  level_max_min = 0;
  level_max_max = 10;
  test10 ( dim_min, dim_max, level_max_min, level_max_max );
//
//  Terminate.
//
  cout << "\n";
  cout << "SPARSE_COUNT_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test01 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 tests CC_SE_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST01\n";
  cout << "  CC_SE_SIZE returns the number of \n";
  cout << "  distinct points in a sparse grid made from \n";
  cout << "  * CC_SE, Clenshaw Curtis Slow Exponential Growth family.\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = cc_se_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test02 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 tests CFN_E_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST02\n";
  cout << "  CFN_E_SIZE returns the number of \n";
  cout << "  distinct points in a CFN_E sparse grid made from \n";
  cout << "  any closed fully nested family of 1D quadrature\n";
  cout << "  rules with exponential growth, including:\n";
  cout << "  * CC_E, the Clenshaw Curtis Exponential Growth family;\n";
  cout << "  * NCC_E, the Newton Cotes Closed Exponential Growth family.\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = cfn_e_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test03 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST03 tests F2_SE_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST03\n";
  cout << "  F2_SE_SIZE returns the number of \n";
  cout << "  distinct points in a sparse grid made from \n";
  cout << "  * F2_SE, Fejer Type 2 Slow Exponential Growth family.\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = f2_se_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test04 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST04 tests GP_SE_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST04\n";
  cout << "  GP_SE_SIZE returns the number of \n";
  cout << "  distinct points in a sparse grid made from \n";
  cout << "  * GP_SE, Gauss Patterson Slow Exponential Growth family.\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = gp_se_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test05 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST05 tests OFN_E_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST05\n";
  cout << "  OFN_E_SIZE returns the number of \n";
  cout << "  distinct points in an OFN_E sparse grid made from \n";
  cout << "  product grids formed from open fully nested \n";
  cout << "  quadrature rules with Exponential Growth, including\n";
  cout << "  * F2_E, the Fejer Type 2 Exponential Growth Family;\n";
  cout << "  * GP_E, the Gauss Patterson Exponential Growth Family;\n";
  cout << "  * NCO_E, the Newton Cotes Open Exponential Growth Family.\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = ofn_e_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test06 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST06 tests ONN_E_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST06\n";
  cout << "  ONN_E_SIZE returns the number of \n";
  cout << "  distinct points in an ONN_E sparse grid made from \n";
  cout << "  product grids formed from open non-nested \n";
  cout << "  quadrature rules with exponential growth, including:\n";
  cout << "  * LG_E, the Gauss Laguerre Exponential Growth Family;\n";
  cout << "  * GJ_E, the Gauss Jacobi Exponential Growth Family;\n";
  cout << "  * GLG_E, the Generalized Gauss Laguerre Exponential Growth Family\n";
  cout << "  * GW_E, any Golub Welsch Exponential Growth Family;\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = onn_e_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test07 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST07 tests ONN_L_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST07\n";
  cout << "  ONN_L_SIZE returns the number of \n";
  cout << "  distinct points in an ONN_L sparse grid made from \n";
  cout << "  product grids formed from open non-nested \n";
  cout << "  quadrature rules with linear growth, including:\n";
  cout << "  * LG_L, the Gauss Laguerre Linear Growth Family;\n";
  cout << "  * GJ_L, the Gauss Jacobi Linear Growth Family;\n";
  cout << "  * GLG_L, the Generalized Gauss Laguerre Linear Growth Family;\n";
  cout << "  * GW_L, any Golub Welsch Linear Growth Family;\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = onn_l_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test08 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST08 tests OWN_E_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    15 January 2010
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST08\n";
  cout << "  OWN_E_SIZE returns the number of \n";
  cout << "  distinct points in an OWN_E sparse grid made from \n";
  cout << "  product grids formed from open weakly nested \n";
  cout << "  quadrature rules with exponential growth, including:\n";
  cout << "  * GGH_E, the Generalized Gauss-Hermite Exponential Growth Family;\n";
  cout << "  * GH_E, the Gauss-Hermite Exponential Growth Family;\n";
  cout << "  * LG_E, the Gauss-Legendre Exponential Growth Family;\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = own_e_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test09 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST09 tests OWN_L2_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 April 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST09\n";
  cout << "  OWN_L2_SIZE returns the number of \n";
  cout << "  distinct points in an OWN_L2 sparse grid made from \n";
  cout << "  product grids formed from open weakly nested \n";
  cout << "  quadrature rules with linear growth, including:\n";
  cout << "  * GGH_L2, the Generalized Gauss-Hermite Linear Growth Family;\n";
  cout << "  * GH_L2, the Gauss-Hermite Linear Growth Family;\n";
  cout << "  * LG_L2, the Gauss-Legendre Linear Growth Family;\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = own_l2_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
//****************************************************************************80

void test10 ( int dim_min, int dim_max, int level_max_min, int level_max_max )

//****************************************************************************80
//
//  Purpose:
//
//    TEST10 tests OWN_O_SIZE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    25 April 2014
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int DIM_MIN, the minimum spatial dimension to consider.
//
//    Input, int DIM_MAX, the maximum spatial dimension to consider.
//
//    Input, int LEVEL_MAX_MIN, the minimum value of LEVEL_MAX to consider.
//
//    Input, int LEVEL_MAX_MAX, the maximum value of LEVEL_MAX to consider.
//
{
  int dim_num;
  int level_max;
  int point_num;

  cout << "\n";
  cout << "TEST10\n";
  cout << "  OWN_O_SIZE returns the number of \n";
  cout << "  distinct points in an OWN_O sparse grid made from \n";
  cout << "  product grids formed from open weakly nested \n";
  cout << "  quadrature rules with odd growth, including:\n";
  cout << "  * GGH_L, the Generalized Gauss-Hermite Odd Growth Family;\n";
  cout << "  * GH_L, the Gauss-Hermite Odd Growth Family;\n";
  cout << "  * LG_L, the Gauss-Legendre Odd Growth Family;\n";
  cout << "\n";
  cout << "   DIM: ";
  for ( dim_num = dim_min; dim_num <= dim_max; dim_num++)
  {
    cout << "  " << setw(10) << dim_num;
  }
  cout << "\n";
  cout << "\n";
  cout << "   LEVEL_MAX\n";
  cout << "\n";

  for ( level_max = level_max_min; level_max <= level_max_max; level_max++ )
  {
    cout << "    " << setw(4) << level_max;
    for ( dim_num = dim_min; dim_num <= dim_max; dim_num++ )
    {
      point_num = own_o_size ( dim_num, level_max );
      cout << "  " << setw(10) << point_num;
    }
    cout << "\n";
  }

  return;
}
