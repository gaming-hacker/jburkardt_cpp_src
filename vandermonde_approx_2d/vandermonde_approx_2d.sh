#! /bin/bash
#
cp vandermonde_approx_2d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include vandermonde_approx_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv vandermonde_approx_2d.o ~/libcpp/vandermonde_approx_2d.o
#
echo "Normal end of execution."
