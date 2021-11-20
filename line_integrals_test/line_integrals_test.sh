#! /bin/bash
#
g++ -c -Wall -I/$HOME/include line_integrals_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ line_integrals_test.o /$HOME/libcpp/line_integrals.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm line_integrals_test.o
#
mv a.out line_integrals_test
./line_integrals_test > line_integrals_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_integrals_test
#
echo "Normal end of execution."
