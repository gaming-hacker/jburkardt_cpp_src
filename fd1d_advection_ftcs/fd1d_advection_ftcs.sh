#! /bin/bash
#
g++ -c -Wall fd1d_advection_ftcs.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fd1d_advection_ftcs.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fd1d_advection_ftcs.o
mv a.out ~/bincpp/fd1d_advection_ftcs
#
echo "Normal end of execution."
