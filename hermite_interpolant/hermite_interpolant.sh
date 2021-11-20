#! /bin/bash
#
cp hermite_interpolant.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hermite_interpolant.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_interpolant.o ~/libcpp/hermite_interpolant.o
#
echo "Normal end of execution."
