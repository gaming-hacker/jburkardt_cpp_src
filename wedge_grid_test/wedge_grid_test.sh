#! /bin/bash
#
g++ -c -Wall -I/$HOME/include wedge_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o wedge_grid_test wedge_grid_test.o /$HOME/libcpp/wedge_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wedge_grid_test.o
#
./wedge_grid_test > wedge_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wedge_grid_test
#
echo "Normal end of execution."
