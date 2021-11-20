#! /bin/bash
#
cp quadrature_weights_vandermonde_2d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include quadrature_weights_vandermonde_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrature_weights_vandermonde_2d.o ~/libcpp/quadrature_weights_vandermonde_2d.o
#
echo "Normal end of execution."
