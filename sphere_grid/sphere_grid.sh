#! /bin/bash
#
cp sphere_grid.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sphere_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sphere_grid.o ~/libcpp/sphere_grid.o
#
echo "Normal end of execution."
