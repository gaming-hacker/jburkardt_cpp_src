#! /bin/bash
#
g++ -c -Wall -I/$HOME/include circle_arc_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ circle_arc_grid_test.o /$HOME/libcpp/circle_arc_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm circle_arc_grid_test.o
#
mv a.out circle_arc_grid_test
./circle_arc_grid_test > circle_arc_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm circle_arc_grid_test
#
echo "Normal end of execution."
