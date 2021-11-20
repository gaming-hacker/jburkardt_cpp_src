#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sphere_llq_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o sphere_llq_grid_test sphere_llq_grid_test.o /$HOME/libcpp/sphere_llq_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sphere_llq_grid_test.o
#
./sphere_llq_grid_test > sphere_llq_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sphere_llq_grid_test
#
echo "Normal end of execution."
