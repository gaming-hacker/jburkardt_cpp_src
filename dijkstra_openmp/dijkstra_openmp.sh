#! /bin/bash
#
g++ -c -Wall -fopenmp dijkstra_openmp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -fopenmp dijkstra_openmp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
mv a.out $HOME/bincpp/dijkstra_openmp
#
echo "Normal end of execution."
