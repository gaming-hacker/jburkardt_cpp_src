#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pwl_product_integral_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pwl_product_integral_test.o /$HOME/libcpp/pwl_product_integral.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pwl_product_integral_test.o
#
mv a.out pwl_product_integral_test
./pwl_product_integral_test > pwl_product_integral_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pwl_product_integral_test
#
echo "Normal end of execution."
