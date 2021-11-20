#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pyramid_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o pyramid_grid_test pyramid_grid_test.o /$HOME/libcpp/pyramid_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pyramid_grid_test.o
#
./pyramid_grid_test > pyramid_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pyramid_grid_test
#
echo "Normal end of execution."
