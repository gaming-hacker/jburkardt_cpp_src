#! /bin/bash
#
cp circle_arc_grid.hpp /$HOME/include
#
g++ -c -Wall circle_arc_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_arc_grid.o ~/libcpp/circle_arc_grid.o
#
echo "Normal end of execution."
