#! /bin/bash
#
g++ -c -Wall -I/$HOME/include lagrange_nd_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ lagrange_nd_test.o /$HOME/libcpp/lagrange_nd.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lagrange_nd_test.o
#
mv a.out lagrange_nd_test
./lagrange_nd_test > lagrange_nd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lagrange_nd_test
#
echo "Normal end of execution."
