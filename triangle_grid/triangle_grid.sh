#! /bin/bash
#
cp triangle_grid.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_grid.o ~/libcpp/triangle_grid.o
#
echo "Normal end of execution."
