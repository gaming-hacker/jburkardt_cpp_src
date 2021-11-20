#! /bin/bash
#
g++ -c -Wall -I $HOME/include disk_grid_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ disk_grid_test.o /$HOME/libcpp/disk_grid.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm disk_grid_test.o
#
mv a.out disk_grid_test
./disk_grid_test > disk_grid_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm disk_grid_test
#
echo "Normal end of execution."
