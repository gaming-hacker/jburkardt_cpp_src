#! /bin/bash
#
g++ -c -Wall -I/$HOME/include prime_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ prime_test.o /$HOME/libcpp/prime.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm prime_test.o
#
mv a.out prime_test
./prime_test > prime_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm prime_test
#
echo "Normal end of execution."
