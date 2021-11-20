#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hammersley_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hammersley_test.o /$HOME/libcpp/hammersley.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hammersley_test.o
#
mv a.out hammersley_test
./hammersley_test > hammersley_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hammersley_test
#
echo "Normal end of execution."
