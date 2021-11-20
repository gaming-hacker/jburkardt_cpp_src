#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_lls_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ test_lls_test.o /$HOME/libcpp/test_lls.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_lls_test.o
#
mv a.out test_lls_test
./test_lls_test > test_lls_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_lls_test
#
echo "Normal end of execution."
