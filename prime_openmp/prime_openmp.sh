#! /bin/bash
#
g++ -c -Wall -fopenmp prime_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp prime_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/prime_openmp
#
echo "Normal end of execution."
