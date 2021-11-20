#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_matrix_exponential_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ test_matrix_exponential_test.o /$HOME/libcpp/test_matrix_exponential.o \
                                  /$HOME/libcpp/c8lib.o \
                                  /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_matrix_exponential_test.o
#
mv a.out test_matrix_exponential_test
./test_matrix_exponential_test > test_matrix_exponential_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_matrix_exponential_test
#
echo "Normal end of execution."
