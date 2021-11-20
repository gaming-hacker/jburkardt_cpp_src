#! /bin/bash
#
cp pwl_product_integral.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pwl_product_integral.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pwl_product_integral.o ~/libcpp/pwl_product_integral.o
#
echo "Normal end of execution."
