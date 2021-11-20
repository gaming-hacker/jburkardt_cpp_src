#! /bin/bash
#
g++ -c -Wall -fopenmp multitask_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp multitask_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/multitask_openmp
#
echo "Normal end of execution."
