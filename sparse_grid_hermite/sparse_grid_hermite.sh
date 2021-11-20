#! /bin/bash
#
cp sparse_grid_hermite.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sparse_grid_hermite.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_grid_hermite.o ~/libcpp/sparse_grid_hermite.o
#
echo "Normal end of execution."
