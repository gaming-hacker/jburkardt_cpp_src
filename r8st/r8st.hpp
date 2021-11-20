//
//  I4 Utilities.
//
int i4_log_10 ( int i );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_power ( int i, int j );
//
//  Real double precision General.
//
void r8ge_print ( int m, int n, double a[], string title );
void r8ge_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, string title );
//
//  Real double precision Nonsymmetric Coordinate Format.
//
void r8ncf_print ( int m, int n, int nz_num, int rowcol[], double a[], 
  string title );
void r8ncf_print_some ( int m, int n, int nz_num, int rowcol[], 
  double a[], int ilo, int jlo, int ihi, int jhi, string title );
//
//  Real double precision Sparse storage.
//
void r8st_cg ( int n, int nz_num, int row[], int col[], double a[], 
  double b[], double x[] );
bool r8st_check ( int m, int n, int nz_num, int row[], int col[] );
void r8st_diagonal ( int m, int n, int nz_num, int row[], int col[], double a[] );
double *r8st_dif2 ( int m, int n, int nz_num, int row[], int col[] );
int r8st_ij_to_k ( int nz_num, int row[], int col[], int i, int j );
double *r8st_indicator ( int m, int n, int nz_num, int row[], int col[] );
void r8st_jac_sl ( int n, int nz_num, int row[], int col[], 
  double a[], double b[], double x[], int it_max );
double *r8st_mtv ( int m, int n, int nz_num, int row[], int col[], 
  double a[], double x[] );
double *r8st_mv ( int m, int n, int nz_num, int row[], int col[], 
  double a[], double x[] );
void r8st_print ( int m, int n, int nz_num, int row[], int col[], 
  double a[], string title );
void r8st_print_some ( int m, int n, int nz_num, int row[], int col[], 
  double a[], int ilo, int jlo, int ihi, int jhi, string title );
double *r8st_random ( int m, int n, int nz_num, int row[], int col[], 
  int &seed );
void r8st_read ( string input_file, int m, int n, int nz_num, int row[], 
  int col[], double a[] );
void r8st_read_size ( string input_file, int &m, int &n, int &nz_num );
double *r8st_res ( int m, int n, int nz_num, int row[], int col[], double a[], 
  double x[], double b[] );
double *r8st_to_r8ge ( int m, int n, int nz_num, int row[], int col[], 
  double a[] );
void r8st_to_r8ncf ( int m, int n, int nz_num, int row[], int col[], 
  double a[], int rowcol[] );
void r8st_write ( int m, int n, int nz_num, int row[], int col[], double a[], 
  string output_file );
double *r8st_zeros ( int m, int n, int nz_num, int row[], int col[] );
//
//  R8VEC utilities.
//
double r8vec_dot_product ( int n, double x[], double y[] );
double *r8vec_indicator1_new ( int n );
double r8vec_norm ( int n, double a[] );
double r8vec_norm_affine ( int n, double v0[], double v1[] );
void r8vec_print ( int n, double a[], string title );
double *r8vec_uniform_01_new ( int n, int &seed );
double *r8vec_zeros_new ( int n );
//
//  Utility to print the time.
//
void timestamp ( );
