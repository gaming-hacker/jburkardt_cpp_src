#! /bin/bash
#
g++ -c -Wall -I/$HOME/include normal_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ normal_test.o /$HOME/libcpp/normal.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm normal_test.o
#
mv a.out normal_test
./normal_test > normal_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm normal_test
#
echo "Normal end of execution."
