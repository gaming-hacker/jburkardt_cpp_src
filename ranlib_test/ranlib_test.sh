#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ranlib_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ranlib_test.o /$HOME/libcpp/ranlib.o /$HOME/libcpp/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ranlib_test.o
#
mv a.out ranlib_test
./ranlib_test > ranlib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ranlib_test
#
echo "Normal end of execution."
