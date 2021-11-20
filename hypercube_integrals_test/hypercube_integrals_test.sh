#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hypercube_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hypercube_integrals_test.o /$HOME/libcpp/hypercube_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hypercube_integrals_test.o
#
mv a.out hypercube_integrals_test
./hypercube_integrals_test > hypercube_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hypercube_integrals_test
#
echo "Normal end of execution."
