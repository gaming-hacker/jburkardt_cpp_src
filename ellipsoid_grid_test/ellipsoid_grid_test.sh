#! /bin/bash
#
g++ -c -Wall -I$HOME/include ellipsoid_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ ellipsoid_grid_test.o /$HOME/libcpp/ellipsoid_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ellipsoid_grid_test.o
#
mv a.out ellipsoid_grid_test
./ellipsoid_grid_test > ellipsoid_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ellipsoid_grid_test
#
echo "Normal end of execution."
