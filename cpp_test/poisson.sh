#! /bin/bash
#
g++ -c poisson.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ poisson.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm poisson.o
#
mv a.out poisson
./poisson > poisson.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm poisson
#
echo "Normal end of execution."
