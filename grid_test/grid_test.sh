#! /bin/bash
#
g++ -c -Wall -I/$HOME/include grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ grid_test.o /$HOME/libcpp/grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm grid_test.o
#
mv a.out grid_test
./grid_test > grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm grid_test
#
echo "Normal end of execution."
