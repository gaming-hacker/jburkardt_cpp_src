#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_nint_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ test_nint_test.o /$HOME/libcpp/test_nint.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_nint_test.o
#
mv a.out test_nint_test
./test_nint_test > test_nint_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_nint_test
#
echo "Normal end of execution."
