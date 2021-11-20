#! /bin/bash
#
cp ellipsoid_grid.hpp /$HOME/include
#
g++ -c -Wall ellipsoid_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv ellipsoid_grid.o ~/libcpp/ellipsoid_grid.o
#
echo "Normal end of execution."
