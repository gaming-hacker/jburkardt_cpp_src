#! /bin/bash
#
cp quadrature_least_squares.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include quadrature_least_squares.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrature_least_squares.o ~/libcpp/quadrature_least_squares.o
#
echo "Normal end of execution."
