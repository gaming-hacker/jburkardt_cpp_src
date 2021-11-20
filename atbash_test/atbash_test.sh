#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall atbash_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ atbash_test.o /$HOME/libcpp/atbash.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm atbash_test.o
#
mv a.out atbash_test
./atbash_test > atbash_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm atbash_test
#
echo "Normal end of execution."
