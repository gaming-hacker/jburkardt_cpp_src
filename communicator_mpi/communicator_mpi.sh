#! /bin/bash
#
mpicxx -c -Wall communicator_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx communicator_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm communicator_mpi.o
mv a.out $HOME/bincpp/communicator_mpi
#
echo "Normal end of execution."
