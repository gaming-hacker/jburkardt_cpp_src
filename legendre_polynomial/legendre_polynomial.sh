#! /bin/bash
#
cp legendre_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include legendre_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv legendre_polynomial.o ~/libcpp/legendre_polynomial.o
#
echo "Normal end of execution."
