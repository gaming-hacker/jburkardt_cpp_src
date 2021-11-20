#! /bin/bash
#
g++ -c -Wall -I$HOME/include ellipse_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ ellipse_grid_test.o /$HOME/libcpp/ellipse_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ellipse_grid_test.o
#
mv a.out ellipse_grid_test
./ellipse_grid_test > ellipse_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ellipse_grid_test
#
echo "Normal end of execution."
