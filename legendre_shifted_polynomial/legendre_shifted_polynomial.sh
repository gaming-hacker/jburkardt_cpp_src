#! /bin/bash
#
cp legendre_shifted_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include legendre_shifted_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv legendre_shifted_polynomial.o ~/libcpp/legendre_shifted_polynomial.o
#
echo "Normal end of execution."
