#! /bin/bash
#
g++ -c -Wall -I/$HOME/include quadrature_golub_welsch_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ quadrature_golub_welsch_test.o /$HOME/libcpp/quadrature_golub_welsch.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm quadrature_golub_welsch_test.o
#
mv a.out quadrature_golub_welsch_test
./quadrature_golub_welsch_test > quadrature_golub_welsch_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quadrature_golub_welsch_test
#
echo "Normal end of execution."
