#! /bin/bash
#
g++ -c -Wall -fopenmp md_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp md_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/md_openmp
#
echo "Normal end of execution."
