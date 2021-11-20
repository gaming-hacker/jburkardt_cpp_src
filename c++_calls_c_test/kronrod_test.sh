#! /bin/bash
#
g++ -c -Wall kronrod_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
gcc -c -Wall kronrod.c
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ kronrod_test.o kronrod.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm kronrod_test.o
rm kronrod.o
#
mv a.out kronrod_test
./kronrod_test > kronrod_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm kronrod_test
#
echo "Normal end of execution."
