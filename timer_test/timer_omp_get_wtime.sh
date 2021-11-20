#! /bin/bash
#
g++ -c -Wall -fopenmp timer_omp_get_wtime.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp -o timer_omp_get_wtime timer_omp_get_wtime.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm timer_omp_get_wtime.o
#
./timer_omp_get_wtime > timer_omp_get_wtime.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm timer_omp_get_wtime
#
echo "Normal end of execution."
