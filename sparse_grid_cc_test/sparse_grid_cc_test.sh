#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sparse_grid_cc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sparse_grid_cc_test.o /$HOME/libcpp/sparse_grid_cc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sparse_grid_cc_test.o
#
mv a.out sparse_grid_cc_test
./sparse_grid_cc_test > sparse_grid_cc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sparse_grid_cc_test
#
echo "Normal end of execution."
