#! /bin/bash
#
g++ -c -Wall -I/$HOME/include van_der_corput_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ van_der_corput_test.o /$HOME/libcpp/van_der_corput.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm van_der_corput_test.o
#
mv a.out van_der_corput_test
./van_der_corput_test > van_der_corput_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm van_der_corput_test
#
echo "Normal end of execution."
