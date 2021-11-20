double *hankel_cholesky_upper ( int n, double h[] );
double *hankel_spd_cholesky_lower ( int n, double lii[], double liim1[] );
double r8_epsilon ( );
double *r8mat_cholesky_factor ( int n, double a[], int &flag );
double *r8mat_cholesky_factor_upper ( int n, double a[], int &flag );
double *r8mat_copy_new ( int m, int n, double a1[] );
double *r8mat_mmt_new ( int n1, int n2, int n3, double a[], double b[] );
void r8mat_print ( int m, int n, double a[], string title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi,
  int jhi, string title );
double *r8mat_zeros_new ( int m, int n );
double *r8vec_uniform_01_new ( int n, int &seed );
void timestamp ( );

