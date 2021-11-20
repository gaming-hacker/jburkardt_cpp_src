#! /bin/bash
#
mpicxx -c -Wall random_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx random_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm random_mpi.o
mv a.out $HOME/bincpp/random_mpi
#
echo "Normal end of execution."

