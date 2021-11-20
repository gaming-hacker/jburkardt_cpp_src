#! /bin/bash
#
cp quadrature_golub_welsch.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include quadrature_golub_welsch.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrature_golub_welsch.o ~/libcpp/quadrature_golub_welsch.o
#
echo "Normal end of execution."
