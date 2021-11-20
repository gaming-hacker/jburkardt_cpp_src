#! /bin/bash
#
g++ -c -Wall -I/$HOME/include simplex_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o simplex_grid_test simplex_grid_test.o /$HOME/libcpp/simplex_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simplex_grid_test.o
#
./simplex_grid_test > simplex_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simplex_grid_test
#
echo "Normal end of execution."
