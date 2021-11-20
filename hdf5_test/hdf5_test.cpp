# include <ctime>
# include <iostream>
# include <string>

# include "hdf5.h"

using namespace std;

int main ( );
void hdf5_test01 ( );
void hdf5_test02 ( );
void hdf5_test03 ( );
void hdf5_test04 ( );
void timestamp ( );

//****************************************************************************80

int main ( )

//****************************************************************************80
//
//  Purpose:
//
//    MAIN is the main program for HDF5_TEST.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 February 2017
//
//  Author:
//
//    John Burkardt
//
{
  timestamp ( );
  cout << "\n";
  cout << "HDF5_TEST:\n";
  cout << "  C++ version\n";
  cout << "  Test the HDF5 library.\n";

  hdf5_test01 ( );
  hdf5_test02 ( );
  hdf5_test03 ( );
  hdf5_test04 ( );
//
//  Terminate.
//
  cout << "\n";
  cout << "HDF5_TEST:\n";
  cout << "  Normal end of execution.\n";
  cout << "\n";
  timestamp ( );

  return 0;
}
//****************************************************************************80

void hdf5_test01 ( )

//****************************************************************************80
//
//  Purpose:
//
//    HDF5_TEST01 creates an HDF5 file.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    20 February 2017
//
//  Author:
//
//    John Burkardt
//
{
  hid_t  file_id;
  herr_t status;

  cout << "\n";
  cout << "HDF5_TEST01:\n";
  cout << "  Create an HDF5 file 'test01.h5'.\n";
//
//  Get the file id.
//
  file_id = H5Fcreate ( "test01.h5", H5F_ACC_TRUNC, H5P_DEFAULT,
    H5P_DEFAULT );
//
//  Close the file.
//
  status = H5Fclose ( file_id );

  return;
}
//****************************************************************************80

void hdf5_test02 ( )

//****************************************************************************80
//
//  Purpose:
//
//    HDF5_TEST02 creates a dataset.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 February 2017
//
//  Author:
//
//    John Burkardt
//
{
  hid_t   dataset_id;
  hid_t   dataspace_id;
  hsize_t dims[2] = { 4, 6 };
  hid_t   file_id;
  herr_t  status;

  cout << "\n";
  cout << "HDF5_TEST02:\n";
  cout << "  Create an HDF file 'test02.h5'\n";
  cout << "  Create a dataset.\n";
//
//  Get the file id.
//
  file_id = H5Fcreate ( "test02.h5", H5F_ACC_TRUNC, H5P_DEFAULT,
    H5P_DEFAULT );

  dataspace_id = H5Screate_simple ( 2, dims, NULL );

  dataset_id = H5Dcreate ( file_id, "/dset", H5T_STD_I32BE,
    dataspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT );

  status = H5Dclose ( dataset_id );
  status = H5Sclose ( dataspace_id );
//
//  Close the file.
//
  status = H5Fclose ( file_id );

  return;
}
//****************************************************************************80

void hdf5_test03 ( )

//****************************************************************************80
//
//  Purpose:
//
//    HDF5_TEST03 creates a dataset.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    21 February 2017
//
//  Author:
//
//    John Burkardt
//
{
  int     dset_data[4*6];
  hsize_t dset_dims[2] = { 4, 6 };
  hid_t   dset_id;
  int     dset_rank = 2;
  hid_t   dspace_id;
  hid_t   file_id;
  int     i;
  int     j;
  herr_t  status;

  cout << "\n";
  cout << "HDF5_TEST03:\n";
  cout << "  Create an HDF file 'test03.h5'\n";
  cout << "  Create a dataset.\n";
  cout << "  Put data into the dataset.\n";
//
//  Get the file id.
//
  file_id = H5Fcreate ( "test03.h5", H5F_ACC_TRUNC, H5P_DEFAULT,
    H5P_DEFAULT );
//
//  Get the data space id.
//
  dspace_id = H5Screate_simple ( dset_rank, dset_dims, NULL );
//
//  Return a data set identifier.
//
  dset_id = H5Dcreate ( file_id, "/dset", H5T_STD_I32BE,
    dspace_id, H5P_DEFAULT, H5P_DEFAULT, H5P_DEFAULT );
//
//  Create the data.
//
  cout << "\n";
  cout << "  Dataset /dset read from test03.h5\n";
  cout << "\n";
  for ( i = 0; i < 4; i++ )
  {
    for ( j = 0; j < 6; j++ )
    {
      dset_data[j+i*6] = 6 * i + j + 1;
      cout << "  dset_data[" << i << "][" << j << "] = " << dset_data[6*i+j] << "\n";
    }
  }
//
//  Write the data to the dataset.
//
  status = H5Dwrite ( dset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT,
    dset_data );
//
//  Close the data set.
//
  status = H5Dclose ( dset_id );
//
//  Close the data space.
//
  status = H5Sclose ( dspace_id );
//
//  Close the file.
//
  status = H5Fclose ( file_id );

  return;
}
//****************************************************************************80

void hdf5_test04 ( )

//****************************************************************************80
//
//  Purpose:
//
//    HDF5_TEST04 reads the data from the dataset created by HDF_TEST03.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    24 February 2017
//
//  Author:
//
//    John Burkardt
//
{
  int    **dset_data;
  hsize_t *dset_dims;
  hid_t    dset_id;
  int      dset_rank;
  int      dset_size;
  hid_t    dspace_id;
  hid_t    file_id;
  int      i;
  int      j;
  herr_t   status;

  cout << "\n";
  cout << "HDF5_TEST04:\n";
  cout << "  Open the HDF file 'test03.h5'\n";
  cout << "  Access a dataset.\n";
  cout << "  Read the data from the dataset.\n";
//
//  Get the file id.
//
  file_id = H5Fopen ( "test03.h5", H5F_ACC_RDONLY, H5P_DEFAULT );
//
//  Get the data set id.
//
  dset_id = H5Dopen2 ( file_id, "/dset", H5P_DEFAULT );
//
//  Get the data space ID for the given data set.
//
  dspace_id = H5Dget_space ( dset_id );
//
//  Get the rank of the data set.
//
  dset_rank = H5Sget_simple_extent_ndims ( dspace_id );
//
//  Get the dimensions of the data set.
//
  dset_dims = new hsize_t[dset_rank];

  status = H5Sget_simple_extent_dims ( dspace_id, dset_dims, NULL );
//
//  Set up pointers for 2D dynamic array.
//
  dset_size = 1;
  for ( i = 0; i < dset_rank; i++ )
  {
    dset_size = dset_size * dset_dims[i];
  }
  dset_data = new int*[ dset_dims[0]];

  dset_data[0] = new int[dset_size];
  for ( i = 1; i < dset_dims[0]; i++ )
  {
    dset_data[i] = dset_data[0] + i * dset_dims[1];
  }
//
//  Read the data from the dataset.
//
  status = H5Dread ( dset_id, H5T_NATIVE_INT, H5S_ALL, H5S_ALL, H5P_DEFAULT,
    &dset_data[0][0] );
//
//  Print the data.
//
  cout << "\n";
  cout << "  Dataset /dset read from test03.h5\n";
  cout << "\n";
  for ( i = 0; i < 4; i++ )
  {
    for ( j = 0; j < 6; j++ )
    {
      cout << "  dset_data[" << i << "][" << j << "] = " << dset_data[i][j] << "\n";
    }
  }
//
//  Close the data set.
//
  status = H5Dclose ( dset_id ); 
//
//  Close the data space.
//
  status = H5Sclose ( dspace_id );
//
//  Close the file.
//
  status = H5Fclose ( file_id );
//
//  Free memory.
//
  delete [] dset_data;
  delete [] dset_dims;

  return;
}
//****************************************************************************80

void timestamp ( )

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    31 May 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    08 July 2009
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    None
//
{
# define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct std::tm *tm_ptr;
  size_t len;
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  len = std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
