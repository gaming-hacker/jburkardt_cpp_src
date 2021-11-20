#! /bin/bash
#
g++ -c -Wall -I/$HOME/include index_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ index_test.o /$HOME/libcpp/index.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm index_test.o
#
mv a.out index_test
./index_test > index_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm index_test
#
echo "Normal end of execution."
