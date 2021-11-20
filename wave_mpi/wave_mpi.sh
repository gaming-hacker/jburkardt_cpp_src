#! /bin/bash
#
mpicxx -c -Wall wave_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx wave_mpi.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm wave_mpi.o
mv a.out $HOME/bincpp/wave_mpi
#
echo "Normal end of execution."
