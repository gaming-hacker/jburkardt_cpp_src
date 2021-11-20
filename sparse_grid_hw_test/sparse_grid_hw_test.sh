#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sparse_grid_hw_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sparse_grid_hw_test.o /$HOME/libcpp/sparse_grid_hw.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sparse_grid_hw_test.o
#
mv a.out sparse_grid_hw_test
./sparse_grid_hw_test > sparse_grid_hw_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sparse_grid_hw_test
#
echo "Normal end of execution."
