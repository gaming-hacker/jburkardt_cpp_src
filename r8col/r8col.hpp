int i4_log_10 ( int i );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_power ( int i, int j );
int i4_uniform_ab ( int a, int b, int &seed );
int *i4vec_indicator1_new ( int n );
void i4vec_print ( int n, int a[], string title );
void i4vec_transpose_print ( int n, int a[], string title );
bool perm0_check ( int n, int p[] );
double r8_max ( double x, double y );
double r8_min ( double x, double y );
double r8_uniform_ab ( double a, double b, int &seed );
int r8col_compare ( int m, int n, double a[], int i, int j );
double *r8col_duplicates ( int m, int n, int n_unique, int &seed );
int r8col_find ( int m, int n, double a[], double x[] );
int *r8col_first_index ( int m, int n, double a[], double tol );
void r8col_flip ( int m, int n, double a[] );
double *r8col_indicator_new ( int m, int n );
int r8col_insert ( int n_max, int m, int n, double a[], double x[] );
double *r8col_max ( int m, int n, double a[] );
int *r8col_max_index ( int m, int n, double a[] );
void r8col_max_one ( int m, int n, double a[] );
double *r8col_mean ( int m, int n, double a[] );
double *r8col_min ( int m, int n, double a[] );
int *r8col_min_index ( int m, int n, double a[] );
void r8col_normalize_li ( int m, int n, double a[] );
void r8col_part_quick_a ( int m, int n, double a[], int &l, int &r );
void r8col_permute ( int m, int n, int p[], double a[] );
void r8col_print ( int m, int n, double a[], string title );
void r8col_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, string title );
void r8col_reverse ( int m, int n, double a[] );
void r8col_separation ( int m, int n, double a[], double &d_min, double &d_max );
void r8col_sort_heap_a ( int m, int n, double a[] );
int *r8col_sort_heap_index_a ( int m, int n, double a[] );
void r8col_sort_quick_a ( int m, int n, double a[] );
void r8col_sorted_tol_undex ( int m, int n, double a[], int unique_num,
  double tol, int undx[], int xdnu[] );
int r8col_sorted_tol_unique ( int m, int n, double a[], double tol );
int r8col_sorted_tol_unique_count ( int m, int n, double a[], double tol );
void r8col_sorted_undex ( int m, int n, double a[],
  int unique_num, int undx[], int xdnu[] );
int r8col_sorted_unique ( int m, int n, double a[] );
int r8col_sorted_unique_count ( int m, int n, double a[] );
void r8col_sortr_a ( int m, int n, double a[], int key );
double *r8col_sum ( int m, int n, double a[] );
void r8col_swap ( int m, int n, double a[], int j1, int j2 );
double *r8col_to_r8vec ( int m, int n, double a[] );
void r8col_tol_undex ( int x_dim, int x_num, double x_val[], int x_unique_num,
  double tol, int undx[], int xdnu[] );
int r8col_tol_unique_count ( int m, int n, double a[], double tol );
int *r8col_tol_unique_index ( int m, int n, double a[], double tol );
void r8col_transpose_print ( int m, int n, double a[], string title );
void r8col_transpose_print_some ( int m, int n, double a[], int ilo, int jlo,
  int ihi, int jhi, string title );
void r8col_undex ( int x_dim, int x_num, double x_val[], int x_unique_num,
  int undx[], int xdnu[] );
double *r8col_uniform_01_new ( int m, int n, int &seed );
double *r8col_uniform_ab_new ( int m, int n, double a, double b, int &seed );
double *r8col_uniform_abvec_new ( int m, int n, double a[], double b[], int &seed );
int r8col_unique_count ( int m, int n, double a[] );
int *r8col_unique_index ( int m, int n, double a[] );
double *r8col_variance ( int m, int n, double a[] );
int r8vec_compare ( int n, double a[], double b[] );
bool r8vec_eq ( int n, double a1[], double a2[] );
bool r8vec_gt ( int n, double a1[], double a2[] );
bool r8vec_lt ( int n, double a1[], double a2[] );
void r8vec_print ( int n, double a[], string title );
void r8vec_swap ( int n, double a1[], double a2[] );
void sort_heap_external ( int n, int &indx, int &i, int &j, int isgn );
void timestamp ( );
