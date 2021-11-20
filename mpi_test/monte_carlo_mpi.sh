#! /bin/bash
#
mpicxx -c -Wall monte_carlo_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx monte_carlo_mpi.o  -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm monte_carlo_mpi.o
mv a.out monte_carlo_mpi
#
mpirun -v -np 4 ./monte_carlo_mpi > monte_carlo_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm monte_carlo_mpi
#
echo "Normal end of execution."
