#! /bin/bash
#
g++ -c -Wall -fopenmp satisfy_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp satisfy_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/satisfy_openmp
#
echo "Normal end of execution."
