#! /bin/bash
#
g++ -c -Wall fd1d_heat_implicit.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fd1d_heat_implicit.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm fd1d_heat_implicit.o
#
mv a.out ~/bincpp/fd1d_heat_implicit
#
echo "Normal end of execution."
