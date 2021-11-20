# include <cstring>
# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "levenshtein.hpp"

int main ( );
void levenshtein_distance_test ( );
void levenshtein_matrix_test ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//   MAIN is the main program for LEVENSHTEIN_TEST.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    19 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "LEVENSHTEIN_TEST\n";
  cout << "  C++ version\n";
  cout << "  Test the LEVENSHTEIN library.\n";

  levenshtein_distance_test ( );
  levenshtein_matrix_test ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "LEVENSHTEIN_TEST\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void levenshtein_distance_test ( )

//****************************************************************************80
//
//  Purpose:
//
//   LEVENSHTEIN_DISTANCE_TEST tests LEVENSHTEIN_DISTANCE.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  int d1;
  int d2;
  int m;
  int n;
  string s1 = "water";
  string s2 = "kitten";
  string s3 = "saturday";
  string s4 = "pheromones";
  string t1 = "wine";
  string t2 = "sitting";
  string t3 = "sunday";
  string t4 = "photographer";

  cout << "\n";
  cout << "LEVENSHTEIN_DISTANCE_TEST:\n";
  cout << "  LEVENSHTEIN_DISTANCE computes the Levenshtein distance\n";
  cout << "  between two strings.\n";

  m = s1.length ( );
  n = t1.length ( );
  d1 = levenshtein_distance ( m, s1, n, t1 );
  d2 = 3;
  cout << "\n";
  cout << "  S = '" << s1 << "'\n";
  cout << "  T = '" << t1 << "'\n";
  cout << "  Computed distance = " << d1 << "\n";
  cout << "  Correct distance  = " << d2 << "\n";

  m = s2.length ( );
  n = t2.length ( );
  d1 = levenshtein_distance ( m, s2, n, t2 );
  d2 = 3;
  cout << "\n";
  cout << "  S = '" << s2 << "'\n";
  cout << "  T = '" << t2 << "'\n";
  cout << "  Computed distance = " << d1 << "\n";
  cout << "  Correct distance  = " << d2 << "\n";

  m = s3.length ( );
  n = t3.length ( );
  d1 = levenshtein_distance ( m, s3, n, t3 );
  d2 = 3;
  cout << "\n";
  cout << "  S = '" << s3 << "'\n";
  cout << "  T = '" << t3 << "'\n";
  cout << "  Computed distance = " << d1 << "\n";
  cout << "  Correct distance  = " << d2 << "\n";

  m = s4.length ( );
  n = t4.length ( );
  d1 = levenshtein_distance ( m, s4, n, t4 );
  d2 = 8;
  cout << "\n";
  cout << "  S = '" << s4 << "'\n";
  cout << "  T = '" << t4 << "'\n";
  cout << "  Computed distance = " << d1 << "\n";
  cout << "  Correct distance  = " << d2 << "\n";

  return;
}
//****************************************************************************80

void levenshtein_matrix_test ( )

//****************************************************************************80
//
//  Purpose:
//
// -  LEVENSHTEIN_MATRIX_TEST tests LEVENSHTEIN_MATRIX.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    19 March 2018
//
//  Author:
//
//    John Burkardt
//
{
  int *d;
  int i;
  int j;
  int m;
  int n;
  string s1 = "water";
  string s2 = "kitten";
  string s3 = "saturday";
  string s4 = "pheromones";
  string t1 = "wine";
  string t2 = "sitting";
  string t3 = "sunday";
  string t4 = "photographer";

  cout << "\n";
  cout << "LEVENSHTEIN_MATRIX_TEST:\n";
  cout << "  LEVENSHTEIN_MATRIX computes the Levenshtein matrix\n";
  cout << "  associated with the computation of the Levenshtein\n";
  cout << "  distance between two strings.\n";

  m = s1.length ( );
  n = t1.length ( );
  d = levenshtein_matrix ( m, s1, n, t1 );
  cout << "\n";
  cout << "  S = '" << s1 << "'\n";
  cout << "  T = '" << t1 << "'\n";
  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      cout << " " << setw(2) << d[i+j*(m+1)];
    }
    cout << "\n";
  }
  delete [] d;

  m = s2.length ( );
  n = t2.length ( );
  d = levenshtein_matrix ( m, s2, n, t2 );
  cout << "\n";
  cout << "  S = '" << s2 << "'\n";
  cout << "  T = '" << t2 << "'\n";
  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      cout << " " << setw(2) << d[i+j*(m+1)];
    }
    cout << "\n";
  }
  delete [] d;

  m = s3.length ( );
  n = t3.length ( );
  d = levenshtein_matrix ( m, s3, n, t3 );
  cout << "\n";
  cout << "  S = '" << s3 << "'\n";
  cout << "  T = '" << t3 << "'\n";
  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      cout << " " << setw(2) << d[i+j*(m+1)];
    }
    cout << "\n";
  }
  delete [] d;

  m = s4.length ( );
  n = t4.length ( );
  d = levenshtein_matrix ( m, s4, n, t4 );
  cout << "\n";
  cout << "  S = '" << s4 << "'\n";
  cout << "  T = '" << t4 << "'\n";
  for ( i = 0; i <= m; i++ )
  {
    for ( j = 0; j <= n; j++ )
    {
      cout << " " << setw(2) << d[i+j*(m+1)];
    }
    cout << "\n";
  }
  delete [] d;

  return;
}

