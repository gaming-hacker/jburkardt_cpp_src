#! /bin/bash
#
mpicxx -c -Wall quadrature_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx quadrature_mpi.o  -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quadrature_mpi.o
mv a.out quadrature_mpi
#
mpirun -v -np 4 ./quadrature_mpi > quadrature_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadrature_mpi
#
echo "Normal end of execution."
