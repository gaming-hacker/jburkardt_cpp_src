#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ball_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ball_grid_test.o /$HOME/libcpp/ball_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ball_grid_test.o
#
mv a.out ball_grid_test
./ball_grid_test > ball_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ball_grid_test
#
echo "Normal end of execution."
