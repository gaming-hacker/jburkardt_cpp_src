#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_int_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ test_int_test.o /$HOME/libcpp/test_int.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_int_test.o
#
mv a.out test_int_test
./test_int_test > test_int_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_int_test
#
echo "Normal end of execution."
