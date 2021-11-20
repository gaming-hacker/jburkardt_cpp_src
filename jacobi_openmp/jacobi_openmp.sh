#! /bin/bash
#
g++ -c -Wall -fopenmp jacobi_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp -o jacobi_openmp jacobi_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm jacobi_openmp.o
#
mv jacobi_openmp $HOME/bincpp
#
echo "Normal end of execution."
