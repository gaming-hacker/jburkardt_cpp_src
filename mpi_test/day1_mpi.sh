#! /bin/bash
#
mpicxx -c -Wall day1_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx day1_mpi.o  -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm day1_mpi.o
mv a.out day1_mpi
#
mpirun -v -np 4 ./day1_mpi > day1_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm day1_mpi
#
echo "Normal end of execution."
