#! /bin/bash
#
g++ -c -Wall -I/usr/local/include umfpack_simple.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
#g++ umfpack_simple.o -L/usr/local/lib -L/$HOME/lib -lumfpack -lamd -lcholmod -lcolamd -lm \
#  -lsuitesparseconfig -lblas
gfortran umfpack_simple.o -L/usr/local/lib -L/$HOME/lib -lumfpack -lamd -lcholmod \
  -lcolamd -lm -lsuitesparseconfig -lblas -lstdc++
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm umfpack_simple.o
mv a.out umfpack_simple
#
./umfpack_simple > umfpack_simple.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm umfpack_simple
#
echo "Normal end of execution."
