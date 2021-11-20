#! /bin/bash
#
g++ -c -Wall -I $HOME/include collatz_recursive_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ collatz_recursive_test.o /$HOME/libcpp/collatz_recursive.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm collatz_recursive_test.o
#
mv a.out collatz_recursive_test
./collatz_recursive_test > collatz_recursive_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm collatz_recursive_test
#
echo "Normal end of execution."
