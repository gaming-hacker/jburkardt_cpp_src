#! /bin/bash
#
g++ -c -Wall -I/$HOME/include triangle_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_grid_test.o /$HOME/libcpp/triangle_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_grid_test.o
#
mv a.out triangle_grid_test
./triangle_grid_test > triangle_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_grid_test
#
echo "Normal end of execution."
