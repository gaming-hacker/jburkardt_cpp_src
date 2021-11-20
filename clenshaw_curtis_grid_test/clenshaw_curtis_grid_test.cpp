# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <cmath>
# include <ctime>

using namespace std;

# include "clenshaw_curtis_grid.hpp"

int main ( );
void test005 ( );
void test01 ( );
void test015 ( );
void test02 ( );
void test025 ( );
void test03 ( );
void test035 ( );
void test04 ( );
void test045 ( );
void test05 ( );
void test06 ( );
void test07 ( );
void test08 ( );
void test09 ( );
void test10 ( );
void test11 ( );
void test12 ( );
void test13 ( );
double f1 ( double x );
double f2 ( double x );
double f3 ( double x );

//****************************************************************************80

int main ( )

//****************************************************************************80*
//
//  Purpose:
//
//    MAIN is the main program for CLENSHAW_CURTIS_GRID_TEST.
//
//  Discussion:
//
//    CLENSHAW_CURTIS_TEST tests the CLENSHAW_CURTIS routines.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );

  cout << "\n";
  cout << "CLENSHAW_CURTIS_GRID_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the routines in the CLENSHAW_CURTIS_GRID library.\n";

  test005 ( );
  test01 ( );
  test015 ( );
  test02 ( );
  test025 ( );
  test03 ( );
  test035 ( );
  test04 ( );
  test045 ( );
  test05 ( );
  test06 ( );
  test07 ( );
  test08 ( );
  test09 ( );
  test10 ( );
  test11 ( );
  test12 ( );
  test13 ( );

  cout << "\n";
  cout << "CLENSHAW_CURTIS_GRID_TEST\n";
  cout << "  Normal end of execution.\n";

  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void test005 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST005 calls CC_GRID for the 1D problem.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    03 November 2006
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 1

  int dim;
  double *grid_point;
  int i;
  int j;
  int order_1d[DIM_NUM];
  int order_nd;

  cout << "\n";
  cout << "TEST005:\n";
  cout << "  CC_GRID returns a grid of Clenshaw-Curtis points.\n";
  cout << "  Here, we simply call for grids in the 1D case\n";
  cout << "\n";
  cout << "  Spatial dimension of grid = " << DIM_NUM << "\n";

  for ( i = 1; i <= 10; i++ )
  {
    cout << "\n";

    order_1d[0] = i;
    order_nd = order_1d[0];

    grid_point = new double[order_nd];

    cc_grid ( DIM_NUM, order_1d, order_nd, grid_point );

    for ( j = 0; j < order_nd; j++ )
    {
      cout << "  " << setw(8) << j + 1;
      for ( dim = 0; dim < DIM_NUM; dim++ )
      {
        cout << "  " << setw(12) << grid_point[dim+j*DIM_NUM];
      }
      cout << "\n";
    }
    delete [] grid_point;
  }

  return;
# undef DIM_NUM
}
//****************************************************************************80

void test01 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST01 simply calls CC_GRID once.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 October 2006
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 3

  int dim;
  double *grid_point;
  int j;
  int order_1d[DIM_NUM] = { 3, 4, 2 };
  int order_nd;
  int q;

  cout << "\n";
  cout << "TEST01:\n";
  cout << "  CC_GRID returns a grid of Clenshaw-Curtis points.\n";
  cout << "  Here, we simply call for a specific grid.\n";
  cout << "\n";
  cout << "  Spatial dimension of grid = " << DIM_NUM << "\n";

  order_nd = 1;
  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    order_nd = order_nd * order_1d[dim];
  }

  grid_point = new double[DIM_NUM*order_nd];

  cout << "\n";
  cout << "  Total number of points in the grid = " << order_nd << "\n";
  cout << "\n";

  cc_grid ( DIM_NUM, order_1d, order_nd, grid_point );

  j = 1;
  q = 0;
  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    q = q + order_1d[dim];
  }

  cout << "\n";
  cout << "         I         Q          Grid orders:\n";
  cout << "\n";

  cout << "  " << setw(8) << j
       << "  " << setw(8) << q;
  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    cout << "  " << setw(8) << order_1d[dim];
  }
  cout << "\n";

  cout << "\n";
  cout << "  Grid points:\n";
  cout << "\n";

  for ( j = 0; j < order_nd; j++ )
  {
    cout << "  " << setw(8) << j + 1;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      cout << "  " << setw(12) << grid_point[dim+j*DIM_NUM];
    }
    cout << "\n";
  }

  delete [] grid_point;

  return;
# undef DIM_NUM
}
//****************************************************************************80

void test015 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST015 calls CC_GRID_INDEX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 March 2007
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 3

  int dim;
  int *grid_index;
  int j;
  int order_1d[DIM_NUM] = { 3, 4, 2 };
  int order_nd;
  int q;

  cout << "\n";
  cout << "TEST015:\n";
  cout << 
    "  CC_GRID_INDEX returns an indexed grid of Clenshaw-Curtis points.\n";
  cout << "\n";
  cout << "  Spatial dimension of grid = " << DIM_NUM << "\n";

  order_nd = 1;
  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    order_nd = order_nd * order_1d[dim];
  }

  grid_index = new int[DIM_NUM*order_nd];

  cout << "\n";
  cout << "  Total number of points in the grid = " << order_nd << "\n";
  cout << "\n";

  cc_grid_index ( DIM_NUM, order_1d, order_nd, grid_index );

  j = 1;
  q = 0;
  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    q = q + order_1d[dim];
  }

  cout << "\n";
  cout << "         I         Q          Grid orders:\n";
  cout << "\n";

  cout << "  " << setw(8) << j
       << "  " << setw(8) << q << "  ";
  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    cout << "  " << setw(4) << order_1d[dim];
  }
  cout << "\n";

  cout << "\n";
  cout << "  Grid indexed points:\n";
  cout << "\n";

  for ( j = 0; j < order_nd; j++ )
  {
    cout << "  " << setw(8) << j + 1 << "            ";
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      cout << "  " << setw(4) << grid_index[dim+j*DIM_NUM];
    }
    cout << "\n";
  }

  delete [] grid_index;

  return;
# undef DIM_NUM
}
//****************************************************************************80

void test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST02 calls CC_GRIDS_MINMAX to collect all points on 2D grids for Q = 3 to 5.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    11 October 2006
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 2

  int dim;
  int grid_num;
  int *grid_order;
  double *grid_point;
  int j;
  int point_num;
  int q;
  int q_max = 5;
  int q_min = 3;

  cout << "\n";
  cout << "TEST02:\n";
  cout << "  CC_GRIDS_MINMAX returns all Clenshaw Curtis grids\n";
  cout << "  whose Q value satisfies Q_MIN <= Q <= Q_MAX.\n";
  cout << "  Here, Q is the sum of the orders of the 1D rules, and\n";
  cout << "  Q_MIN = " << q_min << "\n";
  cout << "  Q_MAX = " << q_max << "\n";
  cout << "\n";
  cout << "  Spatial dimension of grids = " << DIM_NUM << "\n";

  cc_grids_minmax_size ( DIM_NUM, q_min, q_max, &grid_num, &point_num );

  cout << "\n";
  cout << "  Number of grids = " << grid_num << "\n";
  cout << "  Number of points in the grids = " << point_num << "\n";
//
//  Allocate the space.
//
  grid_order = new int[DIM_NUM*grid_num];
  grid_point = new double[DIM_NUM*point_num];
//
//  Compute the orders and points.
//
  cc_grids_minmax ( DIM_NUM, q_min, q_max, grid_num, point_num, 
    grid_order, grid_point );
//
//  Now we're done.  Print the merged grid data.
//
  cout << "\n";
  cout << "         I         Q          Grid orders:\n";
  cout << "\n";
  for ( j = 0; j < grid_num; j++ )
  {
    q = 0;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      q = q + grid_order[dim+j*DIM_NUM];
    }
    cout << "  " << setw(8) << j+1
         << "  " << setw(8) << q;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      cout << "  " << setw(8) << grid_order[dim+j*DIM_NUM];
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "  Grid points:\n";
  cout << "\n";

  for ( j = 0; j < point_num; j++ )
  {
    cout << "  " << setw(8) << j + 1;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      cout << "  " << setw(12) << grid_point[dim+j*DIM_NUM];
    }
    cout << "\n";
  }

  delete [] grid_order;
  delete [] grid_point;

  return;
# undef DIM_NUM
}
//****************************************************************************80

void test025 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST025 calls CC_LEVELS_MINMAX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    06 November 2006
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 2
# define TEST_NUM 3

  int dim;
  int grid_num;
  int *grid_level;
  int *grid_order;
  double *grid_point;
  int j;
  int level;
  int level_max;
  int level_max_test[TEST_NUM] = { 2, 3, 3 };
  int level_min;
  int level_min_test[TEST_NUM] = { 2, 0, 3 };
  int point_num;
  int test;

  cout << "\n";
  cout << "TEST025:\n";
  cout << "  CC_LEVELS_MINMAX returns all Clenshaw Curtis grids\n";
  cout << "  whose LEVEL value satisfies\n";
  cout << "    LEVEL_MIN <= LEVEL <= LEVEL_MAX.\n";
  cout << "  Here, LEVEL is the sum of the levels of the 1D rules,\n";
  cout << "  and the order of the rule is 2**LEVEL - 1.\n";

  for ( test = 0; test < TEST_NUM; test++ )
  {
    level_min = level_min_test[test];
    level_max = level_max_test[test];

    cout << "\n";
    cout << "  LEVEL_MIN = " << level_min << "\n";
    cout << "  LEVEL_MAX = " << level_max << "\n";
    cout << "\n";
    cout << "  Spatial dimension of grids = " << DIM_NUM << "\n";

    cc_levels_minmax_size ( DIM_NUM, level_min, level_max, &grid_num, 
      &point_num );

    cout << "\n";
    cout << "  Number of grids = " << grid_num << "\n";
    cout << "  Number of points in the grids = " << point_num << "\n";
//
//  Allocate the space.
//
    grid_level = new int[DIM_NUM*grid_num];
    grid_order = new int[DIM_NUM*grid_num];
    grid_point = new double[DIM_NUM*point_num];
//
//  Compute the orders and points.
//
    cc_levels_minmax ( DIM_NUM, level_min, level_max, grid_num, point_num, 
      grid_level, grid_order, grid_point );
//
//  Now we're done.  Print the merged grid data.
//
    cout << "\n";
    cout << "      Grid     Level           Grid Levels         Grid orders:\n";
    cout << "      ----     -----          ------------        ------------\n";
    cout << "\n";
    for ( j = 0; j < grid_num; j++ )
    {
      level = 0;
      for ( dim = 0; dim < DIM_NUM; dim++ )
      {
        level = level + grid_level[dim+j*DIM_NUM];
      }
      cout << "  " << setw(8) << j+1
           << "  " << setw(8) << level;
      for ( dim = 0; dim < DIM_NUM; dim++ )
      {
        cout << "  " << setw(8) << grid_level[dim+j*DIM_NUM];
      }
      for ( dim = 0; dim < DIM_NUM; dim++ )
      {
        cout << "  " << setw(8) << grid_order[dim+j*DIM_NUM];
      }
      cout << "\n";
    }

    cout << "\n";
    cout << "  Grid points:\n";
    cout << "\n";

    for ( j = 0; j < point_num; j++ )
    {
      cout << "  " << setw(8) << j + 1;
      for ( dim = 0; dim < DIM_NUM; dim++ )
      {
        cout << "  " << setw(12) << grid_point[dim+j*DIM_NUM];
      }
      cout << "\n";
    }

    delete [] grid_level;
    delete [] grid_order;
    delete [] grid_point;
  }

  return;
# undef DIM_NUM
# undef TEST_NUM
}
//****************************************************************************80

void test03 ( )

//****************************************************************************80*
//
//  Purpose:
//
//    TEST03 calls CC_GRIDS_CONSTRAINED to collect constrained grids.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    10 October 2006
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 2

  double alpha[DIM_NUM] = { 2.0, 3.0 };
  int dim;
  int grid_num;
  int *grid_order;
  double *grid_point;
  int j;
  int order_max[DIM_NUM];
  int order_min[DIM_NUM];
  int point_num;
  double q;
  double q_max = 13.0;

  cout << "\n";
  cout << "TEST03:\n";
  cout << "  CC_GRIDS_CONSTRAINED returns all Clenshaw Curtis grids\n";
  cout << "  satisfying a set of constraints.\n";
  cout << "\n";
  cout << "  ORDER(I), the order of the 1D rule in dimension I,\n";
  cout << "  is constrained by \n";
  cout << "\n";
  cout << "    ORDER_MIN(I) <= ORDER(I) <= ORDER_MAX(I)\n";
  cout << "\n";
  cout << "  We also define the total weighted order Q\n";
  cout << "\n";
  cout << "    Q = ALPHA(1) * ORDER(1) + ... + ALPHA(N) * ORDER(N)\n";
  cout << "\n";
  cout << "  and further constrain our grids to satisfy\n";
  cout << "\n";
  cout << "    Q <= Q_MAX = " << q_max << "\n";
  cout << "\n";
  cout << "  Spatial dimension of grids = " << DIM_NUM << "\n";

  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    order_min[dim] = 1;
  }
  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    order_max[dim] = 5;
  }

  cout << "\n";
  cout << " Dimension Order_min Order_max     Alpha\n";
  cout << "\n";

  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    cout << "  " << setw(8) << dim+1
         << "  " << setw(8) << order_min[dim]
         << "  " << setw(8) << order_max[dim]
         << "  " << setw(14) << alpha[dim] << "\n";
  }
  cc_grids_constrained_size ( DIM_NUM, q_max, alpha, 
    order_min, order_max, &grid_num, &point_num );

  cout << "\n";
  cout << "  Number of grids = " << grid_num << "\n";
  cout << "  Number of points in the grids = " << point_num << "\n";
//
//  Allocate the space.
//
  grid_order = new int[DIM_NUM*grid_num];
  grid_point = new double[DIM_NUM*point_num];

  cc_grids_constrained ( DIM_NUM, q_max, alpha, 
    order_min, order_max, grid_num, point_num, grid_order, grid_point );
//
//  Now we're done.  Print the merged grid data.
//
  cout << "\n";
  cout << "         I               Q          Grid orders:\n";
  cout << "\n";
  for ( j = 0; j < grid_num; j++ )
  {
    q = 0.0;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      q = q + alpha[dim] * grid_order[dim+j*DIM_NUM];
    }
    cout << "  " << setw(8) << j+1
         << "  " << setw(14) << q;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      cout << "  " << setw(8) << grid_order[dim+j*DIM_NUM];
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "  Grid points:\n";
  cout << "\n";
  for ( j = 0; j < point_num; j++ )
  {
    cout << "  " << setw(8) << j + 1;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      cout << "  " << setw(12) << grid_point[dim+j*DIM_NUM];
    }
    cout << "\n";
  }

  delete [] grid_point;
  delete [] grid_order;

  return;
# undef DIM_NUM
}
//****************************************************************************80

void test035 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST035 calls CC_LEVELS_CONSTRAINED to collect constrained grids.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 November 2006
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 2

  double alpha[DIM_NUM] = { 2.0, 3.0 };
  int dim;
  int *grid_level;
  int grid_num;
  double *grid_point;
  int j;
  int level_max[DIM_NUM];
  int level_min[DIM_NUM];
  int point_num;
  double q;
  double q_max = 13.0;

  cout << "\n";
  cout << "TEST035:\n";
  cout << "  CC_LEVELS_CONSTRAINED returns all Clenshaw Curtis grids\n";
  cout << "  satisfying a set of constraints.\n";
  cout << "\n";
  cout << "  The constraint on the levels of the 1D Clenshaw Curtis\n";
  cout << "  rule in spatial dimension I is:\n";
  cout << "\n";
  cout << "    LEVEL_MIN(I) <= LEVEL(I) <= LEVEL_MAX(I) \n";
  cout << "\n";
  cout << "  The constraint on the levels making up a rule is:\n";
  cout << "\n";
  cout << "    Sum ( 1 <= I <= DIM_NUM ) ALPHA(I) * LEVEL(I) <= Q_MAX.\n";
  cout << "\n";
  cout << "    where Q_MAX = " << q_max << "\n";
  cout << "\n";
  cout << "  The relationship of level to order is roughly \n";
  cout << "\n";
  cout << "    ORDER = 2^LEVEL+1.\n";
  cout << "\n";
  cout << "  Spatial dimension of grids = " << DIM_NUM << "\n";

  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    level_min[dim] = 1;
  }
  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    level_max[dim] = 5;
  }

  cout << "\n";
  cout << " Dimension Level_min Level_max     Alpha\n";
  cout << "\n";

  for ( dim = 0; dim < DIM_NUM; dim++ )
  {
    cout << "  " << setw(8) << dim+1
         << "  " << setw(8) << level_min[dim]
         << "  " << setw(8) << level_max[dim]
         << "  " << setw(14) << alpha[dim] << "\n";
  }
  cc_levels_constrained_size ( DIM_NUM, q_max, alpha, 
    level_min, level_max, &grid_num, &point_num );

  cout << "\n";
  cout << "  Number of grids = " << grid_num << "\n";
  cout << "  Number of points in the grids = " << point_num << "\n";
//
//  Allocate the space.
//
  grid_level = new int[DIM_NUM*grid_num];
  grid_point = new double[DIM_NUM*point_num];

  cc_levels_constrained ( DIM_NUM, q_max, alpha, 
    level_min, level_max, grid_num, point_num, grid_level, grid_point );
//
//  Now we're done.  Print the merged grid data.
//
  cout << "\n";
  cout << "         I               Q          Grid levels:\n";
  cout << "\n";
  for ( j = 0; j < grid_num; j++ )
  {
    q = 0.0;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      q = q + alpha[dim] * grid_level[dim+j*DIM_NUM];
    }
    cout << "  " << setw(8) << j+1
         << "  " << setw(14) << q;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      cout << "  " << setw(8) << grid_level[dim+j*DIM_NUM];
    }
    cout << "\n";
  }

  cout << "\n";
  cout << "  Grid points:\n";
  cout << "\n";
  for ( j = 0; j < point_num; j++ )
  {
    cout << "  " << setw(8) << j + 1;
    for ( dim = 0; dim < DIM_NUM; dim++ )
    {
      cout << "  " << setw(12) << grid_point[dim+j*DIM_NUM];
    }
    cout << "\n";
  }

  delete [] grid_point;
  delete [] grid_level;

  return;
# undef DIM_NUM
}
//****************************************************************************80

void test04 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST04 tests CLENSHAW_CURTIS_COMPUTE
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 October 2006
//
//  Author:
//
//    John Burkardt
//
{
# define ORDER_MAX 16

  int i;
  int order;
  double w[ORDER_MAX];
  double x[ORDER_MAX];

  cout << "\n";
  cout << "TEST04\n";
  cout << "  CLENSHAW_CURTIS_COMPUTE computes\n";
  cout << "  a Clenshaw-Curtis quadrature rule over [-1,1]\n";
  cout << "  of given order.\n";

  cout << "\n";
  cout << "    Order  W             X\n";
  cout << "\n";

  for ( order = 1; order <= 10; order++ )
  {
    clenshaw_curtis_compute ( order, x, w );

    cout << "\n";
    cout << "  " << setw(8) << order << "\n";

    for ( i = 0; i < order; i++ )
    {
      cout << "          "
           << "  " << setw(14) << w[i]
           << "  " << setw(14) << x[i] << "\n";
    }
  }

  return;
# undef ORDER_MAX
}
//****************************************************************************80

void test045 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST045 tests CC_ABSCISSA and CC_WEIGHT.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    14 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int i;
  int order = 10;
  double w;
  double x;

  cout << "\n";
  cout << "TEST045\n";
  cout << "  To compute a single Clenshaw Curtis weight or abscissa,\n";
  cout << "  CC_ABSCISSA computes one abscissa,\n";
  cout << "  CC_WEIGHT computes one weight.\n";
  cout << "\n";
  cout << "  We use these routines wastefully,\n";
  cout << "  to compute the order 10 rule one value at a time.\n";
  cout << "\n";
  cout << "     Order       W               X\n";
  cout << "\n";
  cout << "  " << setw(8) << order << "\n";

  for ( i = 1; i <= order; i++ )
  {
    x = cc_abscissa ( order, i );
    w = cc_weight ( order, i );

    cout << "          "
         << "  " << setw(14) << w
         << "  " << setw(14) << x << "\n";
  }

  return;
# undef ORDER_MAX
}
//****************************************************************************80

void test05 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST05 tests CLENSHAW_CURTIS_COMPUTE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define ORDER_MAX 16

  int i;
  int j;
  int order;
  double result[3];
  double weight[ORDER_MAX];
  double xtab[ORDER_MAX];

  cout << "\n";
  cout << "TEST05\n";
  cout << "  CLENSHAW_CURTIS_COMPUTE computes a Clenshaw-Curtis rule;\n";
  cout << "\n";
  cout << "  The integration interval is [-1,1].\n";
  cout << "  Quadrature order will vary.\n";
  cout << "  Integrand will vary.\n";
  cout << "\n";
  cout << "      Order     F1              F2              F3\n";
  cout << "\n";

  for ( order = 1; order <= ORDER_MAX; order++ )
  {
    clenshaw_curtis_compute ( order, xtab, weight );
 
    result[0] = 0.0;
    for ( i = 0; i < order; i++ )
    {
      result[0] = result[0] + weight[i] * f1 ( xtab[i] );
    }
 
    result[1] = 0.0;
    for ( i = 0; i < order; i++ )
    {
      result[1] = result[1] + weight[i] * f2 ( xtab[i] );
    }

    result[2] = 0.0;
    for ( i = 0; i < order; i++ )
    {
      result[2] = result[2] + weight[i] * f3 ( xtab[i] );
    }

    cout << "  " << setw(6) << order;
    for ( j = 0; j < 3; j++ )
    {
      cout << "  " << setw(14) << result[j];
    }
    cout << "\n";
  }
 
  cout << "\n";

  result[0] = 46.0 * sinh ( 1.0 ) / 25.0 - 2.0 * sin ( 1.0 );
  result[1] = 1.5822329637296729331;
  result[2] = ( sqrt ( 2.0 ) + 3.0 * sqrt ( 6.0 ) ) / 6.0;

  cout << "  " << "Exact ";
  for ( j = 0; j < 3; j++ )
  {
    cout << "  " << setw(14) << result[j];
  }
  cout << "\n";

  return;
# undef ORDER_MAX
}
//****************************************************************************80

void test06 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST06 tests CLENSHAW_CURTIS_SET.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    16 May 2006
//
//  Author:
//
//    John Burkardt
//
{
# define ORDER_MAX 16

  int i;
  int j;
  int order;
  double result[3];
  double weight[ORDER_MAX];
  double xtab[ORDER_MAX];

  cout << "\n";
  cout << "TEST06\n";
  cout << "  CLENSHAW_CURTIS_SET sets up a Clenshaw-Curtis rule;\n";
  cout << "\n";
  cout << "  The integration interval is [-1,1].\n";
  cout << "  Quadrature order will vary.\n";
  cout << "  Integrand will vary.\n";
  cout << "\n";
  cout << "  Order     F1              F2              F3\n";
  cout << "\n";

  for ( order = 1; order <= ORDER_MAX; order++ )
  {
    clenshaw_curtis_set ( order, xtab, weight );
 
    result[0] = 0.0;
    for ( i = 0; i < order; i++ )
    {
      result[0] = result[0] + weight[i] * f1 ( xtab[i] );
    }
 
    result[1] = 0.0;
    for ( i = 0; i < order; i++ )
    {
      result[1] = result[1] + weight[i] * f2 ( xtab[i] );
    }

    result[2] = 0.0;
    for ( i = 0; i < order; i++ )
    {
      result[2] = result[2] + weight[i] * f3 ( xtab[i] );
    }

    cout << "  " << setw(6) << order;
    for ( j = 0; j < 3; j++ )
    {
      cout << "  " << setw(14) << result[j];
    }
    cout << "\n";

  }
 
  cout << "\n";

  result[0] = 46.0 * sinh ( 1.0 ) / 25.0 - 2.0 * sin ( 1.0 );
  result[1] = 1.5822329637296729331;
  result[2] = ( sqrt ( 2.0 ) + 3.0 * sqrt ( 6.0 ) ) / 6.0;

  cout << "  " << "Exact ";
  for ( j = 0; j < 3; j++ )
  {
    cout << "  " << setw(14) << result[j];
  }
  cout << "\n";

  return;
# undef ORDER_MAX
}
//****************************************************************************80

void test07 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST07 tests DTABLE_WRITE0.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    29 June 2009
//
//  Author:
//
//    John Burkardt
//
{
# define DIM_NUM 1
# define ORDER 9

  string r_file = "cc_r_d1_o9.txt";
  double r[DIM_NUM*2];
  string w_file = "cc_w_d1_o9.txt";
  double w[ORDER];
  string x_file = "cc_x_d1_o9.txt";
  double x[DIM_NUM*ORDER];

  cout << "\n";
  cout << "TEST07\n";
  cout << "  DTABLE_WRITE0 writes a Clenshaw-Curtis\n";
  cout << "  quadrature rule to a file.\n";

  cout << "\n";
  cout << "  Spatial dimension = " << DIM_NUM << "\n";
  cout << "  Computing the rule of order = " << ORDER << "\n";

  clenshaw_curtis_compute ( ORDER, x, w );

  cout << "\n";
  cout << "  Write abscissas to file \"" << x_file << "\".\n";

  dtable_write0 ( x_file, DIM_NUM, ORDER, x );

  cout << "  Write weights to file \"" << w_file << "\".\n";

  dtable_write0 ( w_file, 1, ORDER, w );

  cout << "  Write region to file \"" << r_file << "\".\n";

  r[0+0*DIM_NUM] = -1.0;
  r[0+1*DIM_NUM] = +1.0;

  dtable_write0 ( r_file, DIM_NUM, 2, r );

  return;
# undef DIM_NUM
# undef ORDER
}
//****************************************************************************80

void test08 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST08 tests CLENSHAW_CURTIS_COMPUTE_ND.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int dim;
  int dim_num;
  int order;
  int *order_1d;
  int order_nd;
  double *point;
  double *weight;
  double weight_sum;

  cout << "\n";
  cout << "TEST08\n";
  cout << "  CLENSHAW_CURTIS_COMPUTE_ND computes\n";
  cout << "  a multidimensional Clenshaw-Curtis quadrature rule\n";
  cout << "  over the hypercube [-1,1]^ND of given\n";
  cout << "  (possibly different) orders in each dimension.\n";

  dim_num = 2;

  order_1d = new int[dim_num];
  for ( dim = 0; dim < dim_num; dim++ )
  {
    order_1d[dim] = 5;
  }

  order_nd = i4vec_product ( dim_num, order_1d );

  point = new double[dim_num*order_nd];
  weight = new double[order_nd];

  cout << "\n";
  cout << "  In this example, we use the SAME ORDER\n";
  cout << "  in all dimensions.\n";
  cout << "\n";
  cout << "  Spatial dimension DIM_NUM = " << dim_num << "\n";
  cout << "  1D orders = ";
  for ( dim = 0; dim < dim_num; dim++ )
  {
    cout << "  " << order_1d[dim];
  }
  cout << "\n";
  cout << "  Number of points = " << order_nd << "\n";

  clenshaw_curtis_compute_nd ( dim_num, order_1d, point, weight );

  cout << "\n";
  cout << "      Weight           X(1)           X(2)\n";
  cout << "  --------------  --------------  --------------\n";
  cout << "\n";

  for ( order = 0; order < order_nd; order++ )
  {
    cout << "  " << setw(14) << weight[order];
    for ( dim = 0; dim < dim_num; dim++ )
    {
      cout << "  " << setw(14) << point[dim+order*dim_num];
    }
    cout << "\n";
  }

  weight_sum = r8vec_sum ( order_nd, weight );

  cout << "\n";
  cout << "  " << setw(14) << weight_sum << "\n";

  delete [] order_1d;
  delete [] point;
  delete [] weight;

  return;
}
//****************************************************************************80

void test09 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST09 tests CLENSHAW_CURTIS_COMPUTE_ND.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int dim;
  int dim_num;
  int order;
  int *order_1d;
  int order_nd;
  double *point;
  double *weight;
  double weight_sum;

  cout << "\n";
  cout << "TEST09\n";
  cout << "  CLENSHAW_CURTIS_COMPUTE_ND computes\n";
  cout << "  a multidimensional Clenshaw-Curtis quadrature rule\n";
  cout << "  over the hypercube [-1,1]^ND of given\n";
  cout << "  (possibly different) orders in each dimension.\n";

  dim_num = 3;

  order_1d = new int[dim_num];

  order_1d[0] = 2;
  order_1d[1] = 4;
  order_1d[2] = 3;

  order_nd = i4vec_product ( dim_num, order_1d );

  point = new double[dim_num*order_nd];
  weight = new double[order_nd];

  cout << "\n";
  cout << "  In this example, we use DIFFERENT ORDERS\n";
  cout << "  in each dimension.\n";
  cout << "\n";
  cout << "  Spatial dimension DIM_NUM = " << dim_num << "\n";
  cout << "  1D orders = ";
  for ( dim = 0; dim < dim_num; dim++ )
  {
    cout << "  " << order_1d[dim];
  }
  cout << "\n";
  cout << "  Number of points = " << order_nd << "\n";

  clenshaw_curtis_compute_nd ( dim_num, order_1d, point, weight );

  cout << "\n";
  cout << "      Weight           X(1)           X(2)           X(3)\n";
  cout << "  --------------  --------------  --------------  --------------\n";
  cout << "\n";

  for ( order = 0; order < order_nd; order++ )
  {
    cout << "  " << setw(14) << weight[order];
    for ( dim = 0; dim < dim_num; dim++ )
    {
      cout << "  " << setw(14) << point[dim+order*dim_num];
    }
    cout << "\n";
  }

  weight_sum = r8vec_sum ( order_nd, weight );

  cout << "\n";
  cout << "  " << setw(14) << weight_sum << "\n";

  delete [] order_1d;
  delete [] point;
  delete [] weight;

  return;
}
//****************************************************************************80

void test10 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST10 uses DTABLE_WRITE0 to write out a multidimensional CC rule.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int dim;
  int dim_num;
  int *order_1d;
  int order_nd;
  double *point;
  string r_file = "cc_r_d4_o81.txt";
  double *r;
  string w_file = "cc_w_d4_o81.txt";
  double *weight;
  string x_file = "cc_x_d4_o81.txt";

  cout << "\n";
  cout << "TEST10\n";
  cout << "  Use DTABLE_WRITE0 to write out a multidimensional rule.\n";
  cout << "  CLENSHAW_CURTIS_COMPUTE_ND computes\n";
  cout << "  a multidimensional Clenshaw-Curtis quadrature rule\n";
  cout << "  over the hypercube [-1,1]^ND of given\n";
  cout << "  (possibly different) orders in each dimension.\n";

  dim_num = 4;

  order_1d = new int[dim_num];
  for ( dim = 0; dim < dim_num; dim++ )
  {
    order_1d[dim] = 3;
  }

  order_nd = i4vec_product ( dim_num, order_1d );

  point = new double[dim_num*order_nd];
  weight = new double[order_nd];
  r = new double[dim_num*2];

  cout << "\n";
  cout << "  In this example, we use the SAME ORDER\n";
  cout << "  in all dimensions.\n";
  cout << "\n";
  cout << "  Spatial dimension DIM_NUM = " << dim_num << "\n";
  cout << "  1D orders = ";
  for ( dim = 0; dim < dim_num; dim++ )
  {
    cout << "  " << order_1d[dim];
  }
  cout << "\n";
  cout << "  Number of points = " << order_nd << "\n";

  clenshaw_curtis_compute_nd ( dim_num, order_1d, point, weight );

  for ( dim = 0; dim < dim_num; dim++ )
  {
    r[dim+0*dim_num] = -1.0;
    r[dim+1*dim_num] = +1.0;
  }

  cout << "\n";
  cout << "  Write abscissas to file \"" << x_file << "\".\n";

  dtable_write0 ( x_file, dim_num, order_nd, point );

  cout << "  Write weights to file \"" << w_file << "\".\n";

  dtable_write0 ( w_file, 1, order_nd, weight );

  cout << "  Write region to file \"" << r_file << "\".\n";

  dtable_write0 ( r_file, dim_num, 2, r );

  delete [] order_1d;
  delete [] point;
  delete [] r;
  delete [] weight;

  return;
}
//****************************************************************************80

void test11 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST11 tests CC_ABSCISSA_LEVEL_1D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int base;
  int i;
  int order;
  int *test_level;
  int test_num;
  int *test_val;

  cout << "\n";
  cout << "TEST11\n";
  cout << "  CC_ABSCISSA_LEVEL_1D reports the level on which\n";
  cout << "  a Clenshaw Curtis abscissa of given index will first\n";
  cout << "  be generated, assuming a series of grids that grow\n";
  cout << "  in order as 2^LEVEL+1.\n";

  base = 5;
  order = i4_power ( 2, base ) + 1;
  test_num = i4_power ( 2, base ) + 1;

  cout << "\n";
  cout << "  Base B = " << base << "\n";
  cout << "  ORDER 2^B+1 = " << order << "\n";

  test_val = new int[test_num];

  for ( i = 0; i < test_num; i++ )
  {
    test_val[i] = i;
  }

  test_level = cc_abscissa_level_1d ( base, test_num, test_val );

  cout << "\n";
  cout << "         I  Level(I)\n";
  cout << "\n";

  for ( i = 0; i < test_num; i++ )
  {
    cout << "  " << setw(8) << test_val[i]
         << "  " << setw(8) << test_level[i] << "\n";
  }

  delete [] test_level;
  delete [] test_val;

  return;
}
//****************************************************************************80

void test12 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST12 tests CC_ABSCISSA_LEVEL_1D.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    23 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int base;
  int i;
  int order;
  int seed;
  int *test_level;
  int test_num;
  int *test_val;

  cout << "\n";
  cout << "TEST12\n";
  cout << "  CC_ABSCISSA_LEVEL_1D can also be called for values\n";
  cout << "  outside the standard range of 0 through 2^LEVEL_MAX.\n";
  cout << "  In that case, a MOD operation is applied first,\n";
  cout << "  to make a sensible result.\n";

  base = 5;
  order = i4_power ( 2, base ) + 1;
  seed = 123456789;
  test_num = 20;

  cout << "\n";
  cout << "  Base B = " << base << "\n";
  cout << "  ORDER = 2^B+1 = " << order << "\n";

  test_val = i4vec_uniform ( test_num, -20, 100, &seed );

  test_level = cc_abscissa_level_1d ( base, test_num, test_val );

  cout << "\n";
  cout << "         I  Mod(I,O)  Level(I)\n";
  cout << "\n";

  for ( i = 0; i < test_num; i++ )
  {
    cout << "  " << setw(8) << test_val[i]
         << "  " << setw(8) << i4_modp ( test_val[i], order )
         << "  " << setw(8) << test_level[i] << "\n";
  }

  delete [] test_level;
  delete [] test_val;

  return;
}
//****************************************************************************80

void test13 ( )

//****************************************************************************80
//
//  Purpose:
//
//    TEST13 tests CC_ABSCISSA_LEVEL_ND.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    25 March 2007
//
//  Author:
//
//    John Burkardt
//
{
  int base;
  int dim_num;
  int i;
  int j;
  int k;
  int order;
  int *test_level;
  int test_num;
  int *test_val;

  cout << "\n";
  cout << "TEST13\n";
  cout << "  CC_ABSCISSA_LEVEL_ND reports the level on which\n";
  cout << "  a Clenshaw Curtis abscissa of given index will first\n";
  cout << "  be generated, assuming a series of grids that grow\n";
  cout << "  in order as 2^LEVEL+1.\n";
  cout << "\n";
  cout << "  This routine is applied for multidimensional cases.\n";

  base = 3;
  order = i4_power ( 2, base ) + 1;
  dim_num = 2;
  test_num = order * order;

  cout << "\n";
  cout << "  Base B = " << base << "\n";
  cout << "  ORDER 2^B+1 = " << order << "\n";
  cout << "  DIM_NUM = " << dim_num << "\n";

  test_val = new int[dim_num*test_num];

  k = 0;
  for ( i = 0; i < order; i++ )
  {
    for ( j = 0; j < order; j++ )
    {
      test_val[0+k*dim_num] = i;
      test_val[1+k*dim_num] = j;
      k = k + 1;
    }
  }

  test_level = cc_abscissa_level_nd ( base, dim_num, test_num, test_val );

  cout << "\n";
  cout << "         I         J  Level(I,J)\n";
  cout << "\n";

  for ( k = 0; k < test_num; k++ )
  {
    cout << "  " << setw(8) << test_val[0+k*dim_num]
         << "  " << setw(8) << test_val[1+k*dim_num]
         << "  " << setw(8) << test_level[k] << "\n";
  }

  delete [] test_level;
  delete [] test_val;

  return;
}
//****************************************************************************80

double f1 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F1 evaluates F1(X) = 23 * cosh ( x ) / 25 - cos ( x ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 October 2006
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Charles Clenshaw, Alan Curtis,
//    A Method for Numerical Integration on an Automatic Computer,
//    Numerische Mathematik,
//    Volume 2, Number 1, December 1960, pages 197-205.
//
//  Parameters:
//
//    Input, double X, the argument.
//
//    Output, double F1, the value of the function.
//
{
  double value;

  value = 23.0 * cosh ( x ) / 25.0 - cos ( x );

  return value;
}
//****************************************************************************80

double f2 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F2 evaluates F2(X) = 1 / ( x^4 + x^2 + 0.9 ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 October 2006
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Charles Clenshaw, Alan Curtis,
//    A Method for Numerical Integration on an Automatic Computer,
//    Numerische Mathematik,
//    Volume 2, Number 1, December 1960, pages 197-205.
//
//  Parameters:
//
//    Input, double X, the argument.
//
//    Output, double F2, the value of the function.
//
{
  double value;

  value = 1.0 / ( pow ( x, 4 ) + pow ( x, 2 ) + 0.9 );

  return value;
}
//****************************************************************************80

double f3 ( double x )

//****************************************************************************80
//
//  Purpose:
//
//    F3 evaluates F3(X) = sqrt ( abs ( x + 1/2 ) ).
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    18 October 2006
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Charles Clenshaw, Alan Curtis,
//    A Method for Numerical Integration on an Automatic Computer,
//    Numerische Mathematik,
//    Volume 2, Number 1, December 1960, pages 197-205.
//
//  Parameters:
//
//    Input, double X, the argument.
//
//    Output, double F3, the value of the function.
//
{
  double value;

  value = sqrt ( abs ( x + 0.5 ) );

  return value;
}
