#! /bin/bash
#
rm -f quad2d_openmp_test.txt
#
for threads in 1 2 4 8
do
  echo "Run with "$threads" threads."
  export OMP_NUM_THREADS=$threads
  $HOME/bincpp/quad2d_openmp >> quad2d_openmp_test.txt
  if [ $? -ne 0 ]; then
    echo "Run error."
    exit
  fi
done
#
echo "Normal end of execution."
