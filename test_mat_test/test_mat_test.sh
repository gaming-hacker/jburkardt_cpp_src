#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_mat_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ test_mat_test.o /$HOME/libcpp/test_mat.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_mat_test.o
#
mv a.out test_mat_test
./test_mat_test > test_mat_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm test_mat_test
#
echo "Normal end of execution."
