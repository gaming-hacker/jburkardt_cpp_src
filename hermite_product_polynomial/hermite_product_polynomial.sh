#! /bin/bash
#
cp hermite_product_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include hermite_product_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv hermite_product_polynomial.o ~/libcpp/hermite_product_polynomial.o
#
echo "Normal end of execution."
