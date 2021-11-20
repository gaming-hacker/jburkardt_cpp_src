#! /bin/bash
#
cp vandermonde_interp_1d.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include vandermonde_interp_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv vandermonde_interp_1d.o ~/libcpp/vandermonde_interp_1d.o
#
echo "Normal end of execution."
