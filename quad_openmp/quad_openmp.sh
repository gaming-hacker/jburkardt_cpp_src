#! /bin/bash
#
g++ -c -Wall -fopenmp quad_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp quad_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/quad_openmp
#
echo "Normal end of execution."
