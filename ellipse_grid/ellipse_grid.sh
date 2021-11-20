#! /bin/bash
#
cp ellipse_grid.hpp /$HOME/include
#
g++ -c -Wall ellipse_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv ellipse_grid.o ~/libcpp/ellipse_grid.o
#
echo "Normal end of execution."
