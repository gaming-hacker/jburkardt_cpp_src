#! /bin/bash
#
cp tetrahedron_grid.hpp /$HOME/include
#
g++ -c -Wall tetrahedron_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_grid.o ~/libcpp/tetrahedron_grid.o
#
echo "Normal end of execution."
