#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall abc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ abc_test.o /$HOME/libcpp/abc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm abc_test.o
#
mv a.out abc_test
./abc_test > abc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm abc_test
#
echo "Normal end of execution."
