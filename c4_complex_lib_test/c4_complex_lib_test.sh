#! /bin/bash
#
g++ -c -Wall -I/$HOME/include c4_complex_lib_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ c4_complex_lib_test.o /$HOME/libcpp/c4_complex_lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm c4_complex_lib_test.o
#
mv a.out c4_complex_lib_test
./c4_complex_lib_test > c4_complex_lib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm c4_complex_lib_test
#
echo "Normal end of execution."
