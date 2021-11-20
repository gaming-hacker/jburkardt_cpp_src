#! /bin/bash
#
mpicxx -c -Wall search_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx search_mpi.o  -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm search_mpi.o
mv a.out search_mpi
#
mpirun -v -np 4 ./search_mpi > search_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm search_mpi
#
echo "Normal end of execution."
