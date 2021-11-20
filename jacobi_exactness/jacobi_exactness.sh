#! /bin/bash
#
g++ -c -Wall jacobi_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ jacobi_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm jacobi_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/jacobi_exactness
#
echo "Normal end of execution."
