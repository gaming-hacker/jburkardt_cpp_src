#! /bin/bash
#
g++ -c -Wall -I/$HOME/include quality_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ quality_test.o /$HOME/libcpp/quality.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm quality_test.o
#
mv a.out quality_test
./quality_test > quality_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm quality_test
#
echo "Normal end of execution."
