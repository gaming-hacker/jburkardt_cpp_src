#! /bin/bash
#
g++ -c -Wall -I/$HOME/include walsh_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ walsh_test.o /$HOME/libcpp/walsh.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm walsh_test.o
#
mv a.out walsh_test
./walsh_test > walsh_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm walsh_test
#
echo "Normal end of execution."
