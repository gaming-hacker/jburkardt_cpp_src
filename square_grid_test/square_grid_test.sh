#! /bin/bash
#
g++ -c -Wall -I/$HOME/include square_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o square_grid_test square_grid_test.o /$HOME/libcpp/square_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm square_grid_test.o
#
./square_grid_test > square_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm square_grid_test
#
echo "Normal end of execution."
