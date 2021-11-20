double *monomial_value ( int m, int n, int e[], double x[] );
double r8ge_det ( int n, double a_lu[], int pivot[] );
int r8ge_fa ( int n, double a[], int pivot[] );
double r8vec_sum ( int n, double a[] );
double *r8vec_uniform_01_new ( int n, int &seed );
double *simplex_general_sample ( int m, int n, double t[], int &seed );
double simplex_general_volume ( int m, double t[] );
double simplex_unit_monomial_integral ( int m, int e[] );
double *simplex_unit_sample ( int m, int n, int &seed );
void simplex_unit_to_general ( int m, int n, double t[], double ref[],
  double phy[] );
double simplex_unit_volume ( int m );
void timestamp ( );
