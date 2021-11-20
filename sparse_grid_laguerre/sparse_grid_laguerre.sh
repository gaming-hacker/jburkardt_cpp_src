#! /bin/bash
#
cp sparse_grid_laguerre.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sparse_grid_laguerre.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_grid_laguerre.o ~/libcpp/sparse_grid_laguerre.o
#
echo "Normal end of execution."
