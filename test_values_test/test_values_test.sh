#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_values_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ test_values_test.o /$HOME/libcpp/test_values.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_values_test.o
#
mv a.out test_values_test
./test_values_test > test_values_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_values_test
#
echo "Normal end of execution."
