#! /bin/bash
#
cp lobatto_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include lobatto_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lobatto_polynomial.o ~/libcpp/lobatto_polynomial.o
#
echo "Normal end of execution."
