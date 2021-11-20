#! /bin/bash
#
cp sparse_grid_gl.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sparse_grid_gl.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_grid_gl.o ~/libcpp/sparse_grid_gl.o
#
echo "Normal end of execution."
