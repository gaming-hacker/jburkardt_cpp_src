#! /bin/bash
#
g++ -fopenmp -g -Wall mandelbrot_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
mv a.out $HOME/bincpp/mandelbrot_openmp
#
echo "Normal end of execution."
