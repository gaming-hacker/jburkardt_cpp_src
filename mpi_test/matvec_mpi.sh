#! /bin/bash
#
mpicxx -c -Wall matvec_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx matvec_mpi.o  -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm matvec_mpi.o
mv a.out matvec_mpi
#
mpirun -v -np 4 ./matvec_mpi > matvec_mpi.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm matvec_mpi
#
echo "Normal end of execution."
