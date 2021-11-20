#! /bin/bash
#
g++ -c -Wall -fopenmp heated_plate_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp heated_plate_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm heated_plate_openmp.o
#
mv a.out $HOME/bincpp/heated_plate_openmp
#
echo "Normal end of execution."
