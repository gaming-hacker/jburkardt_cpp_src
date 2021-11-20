#! /bin/bash
#
g++ -c -Wall -fopenmp schedule_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp schedule_openmp.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/schedule_openmp
#
echo "Normal end of execution."
