#! /bin/bash
#
g++ -c -I/$HOME/include -Wall clenshaw_curtis_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ clenshaw_curtis_grid_test.o /$HOME/libcpp/clenshaw_curtis_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm clenshaw_curtis_grid_test.o
#
mv a.out clenshaw_curtis_grid_test
./clenshaw_curtis_grid_test > clenshaw_curtis_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm clenshaw_curtis_grid_test
#
echo "Normal end of execution."
