#! /bin/bash
#
g++ -c -Wall rand_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ rand_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm rand_test.o
#
mv a.out rand_test
./rand_test > rand_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rand_test
#
echo "Normal end of execution."
