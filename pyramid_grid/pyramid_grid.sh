#! /bin/bash
#
cp pyramid_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include pyramid_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pyramid_grid.o ~/libcpp/pyramid_grid.o
#
echo "Normal end of execution."
