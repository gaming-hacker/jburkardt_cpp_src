#! /bin/bash
#
cp hermite_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hermite_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_polynomial.o ~/libcpp/hermite_polynomial.o
#
echo "Normal end of execution."
