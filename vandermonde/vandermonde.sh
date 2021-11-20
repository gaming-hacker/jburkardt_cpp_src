#! /bin/bash
#
cp vandermonde.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include vandermonde.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv vandermonde.o ~/libcpp/vandermonde.o
#
echo "Normal end of execution."
