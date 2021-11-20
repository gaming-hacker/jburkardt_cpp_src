#! /bin/bash
#
g++ -c -Wall -fopenmp fft_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ -fopenmp fft_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error"
  exit
fi
mv a.out $HOME/bincpp/fft_openmp
#
echo "Normal end of execution."
