#! /bin/bash
#
cp cube_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include cube_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_grid.o ~/libcpp/cube_grid.o
#
echo "Normal end of execution."
