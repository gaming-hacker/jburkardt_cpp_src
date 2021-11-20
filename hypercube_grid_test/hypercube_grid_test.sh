#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hypercube_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o hypercube_grid_test hypercube_grid_test.o /$HOME/libcpp/hypercube_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hypercube_grid_test.o
#
./hypercube_grid_test > hypercube_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hypercube_grid_test
#
echo "Normal end of execution."
