#! /bin/bash
#
g++ -c -Wall -fopenmp random_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp random_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/random_openmp
#
echo "Normal end of execution."
