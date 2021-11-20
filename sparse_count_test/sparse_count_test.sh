#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sparse_count_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sparse_count_test.o /$HOME/libcpp/sparse_count.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sparse_count_test.o
#
mv a.out sparse_count_test
./sparse_count_test > sparse_count_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sparse_count_test
#
echo "Normal end of execution."
