#! /bin/bash
#
cp legendre_product_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include legendre_product_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv legendre_product_polynomial.o ~/libcpp/legendre_product_polynomial.o
#
echo "Normal end of execution."
