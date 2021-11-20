#! /bin/bash
#
g++ -c -Wall -I$HOME/include correlation_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ correlation_test.o ~/libcpp/correlation.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm correlation_test.o
#
mv a.out correlation_test
./correlation_test > correlation_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm correlation_test
#
echo "Normal end of execution."
