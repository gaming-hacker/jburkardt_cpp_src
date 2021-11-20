#! /bin/bash
#
g++ -c -Wall fd1d_burgers_lax.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fd1d_burgers_lax.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fd1d_burgers_lax.o
#
mv a.out ~/bincpp/fd1d_burgers_lax
#
echo "Normal end of execution."
