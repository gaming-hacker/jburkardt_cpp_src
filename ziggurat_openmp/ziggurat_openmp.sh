#! /bin/bash
#
g++ -c -Wall -fopenmp ziggurat_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o ziggurat_openmp -fopenmp ziggurat_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ziggurat_openmp.o
#
mv ziggurat_openmp $HOME/bincpp/ziggurat_openmp
#
echo "Normal end of execution."
