#! /bin/bash
#
g++ -c -Wall -fopenmp poisson_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp poisson_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/poisson_openmp
#
echo "Normal end of execution."
