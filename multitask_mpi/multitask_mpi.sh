#! /bin/bash
#
mpicxx -c -Wall multitask_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx multitask_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm multitask_mpi.o
mv a.out $HOME/bincpp/multitask_mpi
#
echo "Normal end of execution."

