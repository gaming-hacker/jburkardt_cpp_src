#! /bin/bash
#
cp wedge_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include wedge_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wedge_grid.o ~/libcpp/wedge_grid.o
#
echo "Normal end of execution."
