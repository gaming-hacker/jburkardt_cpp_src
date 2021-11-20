#! /bin/bash
#
g++ -c -Wall -I/$HOME/include line_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o line_grid_test line_grid_test.o /$HOME/libcpp/line_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm line_grid_test.o
#
./line_grid_test > line_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_grid_test
#
echo "Normal end of execution."
