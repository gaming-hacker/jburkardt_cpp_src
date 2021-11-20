#! /bin/bash
#
g++ -c -Wall -I/$HOME/include timestamp_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ timestamp_test.o /$HOME/libcpp/timestamp.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm timestamp_test.o
#
mv a.out timestamp_test
./timestamp_test > timestamp_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm timestamp_test
#
echo "Normal end of execution."
