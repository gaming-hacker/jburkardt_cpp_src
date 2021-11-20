#! /bin/bash
#
g++ -c -Wall legendre_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ legendre_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm legendre_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/legendre_exactness
#
echo "Normal end of execution."
