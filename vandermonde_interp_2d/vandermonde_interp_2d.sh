#! /bin/bash
#
cp vandermonde_interp_2d.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include vandermonde_interp_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv vandermonde_interp_2d.o ~/libcpp/vandermonde_interp_2d.o
#
echo "Normal end of execution."
