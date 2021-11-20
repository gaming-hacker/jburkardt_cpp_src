#! /bin/bash
#
g++ -c -Wall drand48_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ drand48_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm drand48_test.o
#
mv a.out drand48_test
./drand48_test > drand48_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm drand48_test
#
echo "Normal end of execution."
