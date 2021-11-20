#! /bin/bash
#
g++ -c -Wall poisson_serial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ poisson_serial.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm poisson_serial.o
#
mv a.out $HOME/bincpp/poisson_serial
#
echo "Normal end of execution."
