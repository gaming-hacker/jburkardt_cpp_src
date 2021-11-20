#! /bin/bash
#
mpicxx -c -Wall satisfy_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx satisfy_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm satisfy_mpi.o
mv a.out $HOME/bincpp/satisfy_mpi
#
echo "Normal end of execution."

