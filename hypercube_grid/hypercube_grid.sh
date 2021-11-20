#! /bin/bash
#
cp hypercube_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include hypercube_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hypercube_grid.o ~/libcpp/hypercube_grid.o
#
echo "Normal end of execution."
