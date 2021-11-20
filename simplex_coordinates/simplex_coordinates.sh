#! /bin/bash
#
cp simplex_coordinates.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include simplex_coordinates.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_coordinates.o ~/libcpp/simplex_coordinates.o
#
echo "Normal end of execution."
