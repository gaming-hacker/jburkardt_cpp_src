#! /bin/bash
#
mpicxx -c -Wall prime_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx prime_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm prime_mpi.o
mv a.out $HOME/bincpp/prime_mpi
#
echo "Normal end of execution."

