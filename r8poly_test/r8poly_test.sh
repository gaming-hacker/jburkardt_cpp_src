#! /bin/bash
#
g++ -c -I/$HOME/include r8poly_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o r8poly_test r8poly_test.o /$HOME/libcpp/r8poly.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm r8poly_test.o
#
./r8poly_test > r8poly_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8poly_test
#
echo "Normal end of execution."
