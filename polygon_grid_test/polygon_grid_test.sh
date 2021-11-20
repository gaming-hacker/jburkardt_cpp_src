#! /bin/bash
#
g++ -c -Wall -I/$HOME/include polygon_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o polygon_grid_test polygon_grid_test.o /$HOME/libcpp/polygon_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm polygon_grid_test.o
#
./polygon_grid_test > polygon_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm polygon_grid_test
#
echo "Normal end of execution."
