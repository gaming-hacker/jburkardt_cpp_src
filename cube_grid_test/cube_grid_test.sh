#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cube_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o cube_grid_test cube_grid_test.o /$HOME/libcpp/cube_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cube_grid_test.o
#
./cube_grid_test > cube_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cube_grid_test
#
echo "Normal end of execution."
