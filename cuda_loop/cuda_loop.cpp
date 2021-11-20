# include <ctime>
# include <iomanip>
# include <iostream>

using namespace std;

# include "cuda_loop.hpp"

//****************************************************************************80

void cuda_loop ( int blocks[3], int threads[3], int n )

//****************************************************************************80
//
//  Purpose:
//
//    CUDA_LOOP simulates the behavior of a CUDA loop.
//
//  Discussion:
//
//    A CUDA kernel "kernel()" is invoked by a command of the form
//
//      kernel << blocks, threads >> ( args )
//
//    where blocks and threads are each vectors of up to 3 values,
//    listing the number of blocks and number of threads to be used.
//
//    If a problem involves N tasks, then tasks are allotted to 
//    specific CUDA processes in an organized fashion.  Some processes
//    may get no tasks, one task, or multiple tasks.  
//
//    Each process is given variables that can be used to determine
//    the tasks to be performed:
//
//      gridDim.x, gridDim.y, gridDim.z: the block dimensions as
//      given by the user in "blocks";
//
//      blockDim.x, blockDim.y, blockDim.z: the thread dimensions as
//      given by the user in "threads";
//
//      blockIdx.x, blockIdx.y, blockId.z: the block indices for this process.
//
//      threadIdx.x, threadIdx.y, threadIdx.z: the thread indices for this process.
//
//    Essentially, a process can determine its linear index K by:
//
//      K = threadIdx.x
//        +  blockdim.x  * threadIdx.y
//        +  blockDim.x  *  blockDim.y  * threadIdx.z
//        +  blockDim.x  *  blockDim.y  *  blockDim.z  * blockIdx.x
//        +  blockDim.x  *  blockDim.y  *  blockDim.z  *  gridDim.x  * blockIdx.y
//        +  blockDim.x  *  blockDim.y  *  blockDim.z  *  gridDim.x  *  gridDim.y  * blockIdx.z
//
//    Set task T = K.
//
//    while ( T < N )
//      carry out task T;
//      T = T + blockDim.x * blockDim.y * blockDim.z * gridDim.x * gridDim.y * gridDim.z.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license. 
//
//  Modified:
//
//    28 March 2018
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, int BLOCKS[3], the CUDA block values.  These should be nonnegative.
//    Typically, the third entry is 1.  Generally, the first two values cannot
//    be greater than 35,535.
//
//    Input, int THREADS[3], the CUDA thread values.  These should be nonnegative.
//    Typically, there is a maximum value imposed on these quantities, which
//    depends on the GPU model.
//
//    Input, int N, the number of tasks to be carried out.
//
{
  int blockDimx;
  int blockDimy;
  int blockDimz;
  int blockIdx;
  int blockIdy;
  int blockIdz;
  int chunk;
  int gridDimx;
  int gridDimy;
  int gridDimz;
  int k1;
  int k2;
  int t;
  int threadIdx;
  int threadIdy;
  int threadIdz;

  cout << "\n";
  cout << "CUDA_LOOP:\n";
  cout << "  Simulate the assignment of N tasks to the blocks\n";
  cout << "  and threads of a GPU using CUDA.\n";
  cout << "\n";
  cout << "  Number of tasks is " << n << "\n";
  cout << "  BLOCKS:  { " << blocks[0] << ", " << blocks[1] << ", " << blocks[2] << ")\n";
  cout << "  THREADS: { " << threads[0] << ", " << threads[1] << ", " << threads[2] << ")\n";

  k1 = 0;

  blockDimx = threads[0];
  blockDimy = threads[1];
  blockDimz = threads[2];

  gridDimx = blocks[0];
  gridDimy = blocks[1];
  gridDimz = blocks[2];

  chunk = blocks[1] * blocks[0] * threads[2] * threads[1] * threads[0];
  cout << "  Total threads = " << chunk << "\n";
  cout << "\n";
  cout << "  Process   Process (bx,by,bz) (tx,ty,tz)  Tasks...\n";
  cout << "  Increment Formula\n";
  cout << "\n";

  for ( blockIdz = 0; blockIdz < gridDimz; blockIdz++ )
  {
    for ( blockIdy = 0; blockIdy < gridDimy; blockIdy++ )
    {
      for ( blockIdx = 0; blockIdx < gridDimx; blockIdx++ )
      {
        for ( threadIdz = 0; threadIdz < blockDimz; threadIdz++ )
        {
          for ( threadIdy = 0; threadIdy < blockDimy; threadIdy++ )
          {
            for ( threadIdx = 0; threadIdx < blockDimx; threadIdx++ )
            {
              t = k1;
              k2 = 
                threadIdx
                + blockDimx * threadIdy
                + blockDimx * blockDimy * threadIdz
                + blockDimx * blockDimy * blockDimz * blockIdx
                + blockDimx * blockDimy * blockDimz * gridDimx * blockIdy
                + blockDimx * blockDimy * blockDimz * gridDimx * gridDimy * blockIdz;

              cout << "  " << setw(7) << k1
                   << "  " << setw(7) << k2
                   << ": (" << setw(2) << blockIdx
                   << "," << setw(2) << blockIdy
                   << "," << setw(2) << blockIdy << ")"
                   << " (" << setw(2) << threadIdx
                   << "," << setw(2) << threadIdy
                   << "," << setw(2) << threadIdy << ")";
              while ( t < n )
              {
                cout << setw(3) << t; 
                t = t + chunk;
              }
              cout << "\n";
              k1 = k1 + 1;
            }
          }
        }
      }
    }
  }

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
//    19 March 2018
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
  std::time_t now;

  now = std::time ( NULL );
  tm_ptr = std::localtime ( &now );

  std::strftime ( time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm_ptr );

  std::cout << time_buffer << "\n";

  return;
# undef TIME_SIZE
}
