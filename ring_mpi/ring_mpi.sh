#! /bin/bash
#
mpicxx -c -Wall ring_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx ring_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ring_mpi.o
mv a.out $HOME/bincpp/ring_mpi
#
echo "Normal end of execution."

