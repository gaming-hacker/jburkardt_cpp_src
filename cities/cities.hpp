char ch_cap ( char ch );
bool ch_eqi ( char ch1, char ch2 );
int ch_to_digit ( char ch );
double degrees_to_radians ( double degrees );
int dist_table_check ( int n, double dist_table[] );
void dms_print ( int n, int lat_dms[], int long_dms[], string title );
void dms_read ( string file_name, int n, int lat_dms[], int long_dms[] );
double *dms_to_dist ( int n, int lat_dms[], int long_dms[] );
double dms_to_distance_earth ( int lat1_dms[], int long1_dms[],
  int lat2_dms[], int long2_dms[] );
double dms_to_radians ( int dms[] );
double *dms_to_xy ( int n, int lat_dms[], int long_dms[] );
void dms_write ( string file_name, int n, int lat_dms[], int long_dms[] );
int file_column_count ( string filename );
bool file_exist ( string filename );
int file_row_count ( string input_filename );
int i4_huge ( );
int i4_max ( int i1, int i2 );
int i4_min ( int i1, int i2 );
int i4_sign ( int i );
char lat_char ( int i );
double *ll_degrees_to_dist ( int n, double lat[], double lon[] );
double ll_degrees_to_distance_earth ( double lat1, double lon1, double lat2, 
  double lon2 );
void ll_degrees_to_xy ( int n, double lat[], double lon[], double x[], 
  double y[] );
double ll_rad_dist_sphere ( double lat1,double  long1, double lat2, 
  double long2, double radius );
char long_char ( int i );
string main_read_code ( string file_main );
string main_read_dist ( string file_main );
string main_read_dms ( string file_main );
string main_read_geom ( string file_main );
string main_read_name ( string file_main );
int main_read_size ( string file_main );
string main_read_xy ( string file_main );
double *point_to_dist_table ( int dim_num, int point_num, double point[] );
double r8_abs ( double x );
double *r8mat_data_read ( string input_filename, int m, int n );
void r8mat_header_read ( string input_filename, int *m, int *n );
void r8mat_nint ( int m, int n, double a[] );
void r8mat_print ( int m, int n, double a[], string title );
void r8mat_print_some ( int m, int n, double a[], int ilo, int jlo, int ihi, 
  int jhi, string title );
void r8mat_transpose_print ( int m, int n, double a[], string title );
void r8mat_transpose_print_some ( int m, int n, double a[], int ilo, int jlo, 
  int ihi, int jhi, string title );
void r8mat_write ( string output_filename, int m, int n, double table[] );
void r8vec_print ( int n, double a[], string title );
bool s_eqi ( string s1, string s2 );
int s_len_trim ( string s );
int s_to_i4 ( string s, int *last, bool *error );
double s_to_r8 ( string s, int *lchar, bool *error );
bool s_to_r8vec ( string s, int n, double rvec[] );
int s_word_count ( string s );
void timestamp ( );
string word_next_read ( string s, bool *done );
