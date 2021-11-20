#! /bin/bash
#
mpicxx -c -Wall search_mpi.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx search_mpi.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm search_mpi.o
mv a.out $HOME/bincpp/search_mpi
#
echo "Normal end of execution."

