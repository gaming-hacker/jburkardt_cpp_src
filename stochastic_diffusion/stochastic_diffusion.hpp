double *diffusivity_1d_pwc ( int nc, double xc[], double vc[], int np, 
  double xp[] );
double *diffusivity_1d_xk ( double dc0, int m, double omega[], int n,
  double x[] );
double *diffusivity_2d_bnt ( double dc0, double omega[], int n, double x[], 
  double y[] );
double *diffusivity_2d_elman ( double a, double cl, double dc0, int m_1d, 
  double omega[], int n1, int n2, double x[], double y[] );
double *diffusivity_2d_ntw ( double cl, double dc0, int m, double omega[], 
  int n, double x[], double y[] );
double *diffusivity_2d_pwc ( int h, int w, double a, double b, double c, 
  double d, double omega[], int n, double x[], double y[] );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
double r8_epsilon ( );
double r8_max ( double x, double y );
double r8_uniform_01 ( int &seed );
double r8mat_max ( int m, int n, double a[] );
double *r8vec_linspace_new ( int n, double a, double b );
double r8vec_max ( int n, double r8vec[] );
void r8vec_mesh_2d ( int nx, int ny, double xvec[], double yvec[], 
  double xmat[], double ymat[] );
double *r8vec_normal_01_new ( int n, int &seed );
double *r8vec_normal_ab_new ( int n, double a, double b, int &seed );
void r8vec_print ( int n, double a[], string title );
void r8vec_uniform_01 ( int n, int &seed, double r[] );
double *r8vec_uniform_01_new ( int n, int &seed );
double *r8vec_uniform_ab_new ( int n, double a, double b, int &seed );
double *theta_solve ( double a, double cl, int m );
void timestamp ( );

