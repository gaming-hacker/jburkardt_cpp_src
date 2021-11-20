double cc_abscissa ( int order, int i );
int *cc_abscissa_level_1d ( int level_max, int test_num, int test_val[] );
int *cc_abscissa_level_nd ( int level_max, int dim_num, int test_num, 
  int test_val[] );
void cc_grid ( int dim_num, int order_1d[], int point_num, double point[] );
void cc_grid_index ( int dim_num, int order_1d[], int order_nd, int indx[] );
void cc_grids_constrained ( int dim_num, double q_max, double alpha[], 
  int order_min[], int order_max[], int grid_num, int point_num, 
  int grid_order[], double grid_point[] );
void cc_grids_constrained_size ( int dim_num, double q_max, double alpha[], 
  int order_min[], int order_max[], int *grid_num, int *point_num );
void cc_grids_minmax ( int dim_num, int q_min, int q_max, int grid_num, 
  int point_num, int grid_order[], double grid_point[] );
void cc_grids_minmax_size ( int dim_num, int q_min, int q_max, int *grid_num, 
  int *point_num );
void cc_level_to_order ( int dim_num, int level[], int order[] );
void cc_levels_constrained ( int dim_num, double q_max, double alpha[], 
  int level_min[], int level_max[], int grid_num, int point_num, 
  int grid_level[], double grid_point[] );
void cc_levels_constrained_size ( int dim_num, double q_max, double alpha[], 
  int level_min[], int level_max[], int *grid_num, int *point_num );
void cc_levels_minmax ( int dim_num, int level_min, int level_max, 
  int grid_num, int point_num, int grid_level[], int grid_order[], 
  double grid_point[] );
void cc_levels_minmax_size ( int dim_num, int level_min, int level_max, 
  int *grid_num, int *point_num );
double cc_weight ( int order, int i );
void clenshaw_curtis_compute ( int n, double x[], double w[] );
void clenshaw_curtis_compute_nd ( int dim_num, int order_1d[], double point[], 
  double weight[] );
void clenshaw_curtis_set ( int order, double xtab[], double weight[] );
void comp_next ( int n, int k, int a[], bool *more, int *h, int *t );
void compnz_next ( int n, int k, int a[], bool *more );
void dtable_write0 ( string output_filename, int m, int n, double table[] );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_modp ( int i, int j );
int i4_power ( int i, int j );
int i4vec_product ( int n, int a[] );
int *i4vec_uniform ( int n, int a, int b, int *seed );
float r4_abs ( float x );
int r4_nint ( float x );
double r8_epsilon ( );
double r8_huge ( );
double r8vec_sum ( int n, double a[] );
void timestamp ( );
void vec_next_gray ( int n, int base[], int a[], bool *done, int *maxact );
void vector_constrained_next4 ( int n, double alpha[], int x_min[], 
  int x_max[], int x[], double q, bool *more );
