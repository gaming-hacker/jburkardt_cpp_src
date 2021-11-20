#! /bin/bash
#
cp simplex_grid.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include simplex_grid.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_grid.o ~/libcpp/simplex_grid.o
#
echo "Normal end of execution."
