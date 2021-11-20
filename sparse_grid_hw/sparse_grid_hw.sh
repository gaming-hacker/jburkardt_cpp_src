#! /bin/bash
#
cp sparse_grid_hw.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include sparse_grid_hw.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_grid_hw.o ~/libcpp/sparse_grid_hw.o
#
echo "Normal end of execution."
