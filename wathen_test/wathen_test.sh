#! /bin/bash
#
g++ -c -Wall -I/$HOME/include wathen_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ wathen_test.o /$HOME/libcpp/wathen.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wathen_test.o
#
mv a.out wathen_test
./wathen_test > wathen_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wathen_test
#
echo "Normal end of execution."
