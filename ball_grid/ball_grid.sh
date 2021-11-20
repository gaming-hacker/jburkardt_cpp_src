#! /bin/bash
#
cp ball_grid.hpp /$HOME/include
#
g++ -c -Wall ball_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv ball_grid.o ~/libcpp/ball_grid.o
#
echo "Normal end of execution."
