#! /bin/bash
#
g++ -c -Wall -fopenmp sgefa_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp sgefa_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/sgefa_openmp
#
echo "Normal end of execution."
