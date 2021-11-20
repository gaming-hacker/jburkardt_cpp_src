#! /bin/bash
#
cp quadrature_weights_vandermonde.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include quadrature_weights_vandermonde.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrature_weights_vandermonde.o ~/libcpp/quadrature_weights_vandermonde.o
#
echo "Normal end of execution."
