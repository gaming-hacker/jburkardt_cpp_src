#! /bin/bash
#
cp sparse_grid_cc.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sparse_grid_cc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sparse_grid_cc.o ~/libcpp/sparse_grid_cc.o
#
echo "Normal end of execution."
