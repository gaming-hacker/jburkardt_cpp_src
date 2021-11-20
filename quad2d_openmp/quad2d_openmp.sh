#! /bin/bash
#
g++ -c -Wall -fopenmp quad2d_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp quad2d_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/quad2d_openmp
#
echo "Normal end of execution."
