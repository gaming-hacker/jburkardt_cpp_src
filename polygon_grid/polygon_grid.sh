#! /bin/bash
#
cp polygon_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include polygon_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv polygon_grid.o ~/libcpp/polygon_grid.o
#
echo "Normal end of execution."
