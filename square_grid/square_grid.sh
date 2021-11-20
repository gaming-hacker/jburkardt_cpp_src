#! /bin/bash
#
cp square_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include square_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_grid.o ~/libcpp/square_grid.o
#
echo "Normal end of execution."
