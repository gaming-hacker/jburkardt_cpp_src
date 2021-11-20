#! /bin/bash
#
g++ -c -Wall -fopenmp mxm_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp mxm_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/mxm_openmp
#
echo "Normal end of execution."
