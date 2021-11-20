#! /bin/bash
#
rm -f sgefa_openmp_test.txt
#
for threads in 1 2 4 8
do
  echo "Run with "$threads" threads."
  export OMP_NUM_THREADS=$threads
  $HOME/bincpp/sgefa_openmp >> sgefa_openmp_test.txt
  if [ $? -ne 0 ]; then
    echo "Run error."
    exit
  fi
done
#
echo "Normal end of execution."
