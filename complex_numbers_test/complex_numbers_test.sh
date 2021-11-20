#! /bin/bash
#
g++ -c -Wall complex_numbers_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o complex_numbers_test complex_numbers_test.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm complex_numbers_test.o
#
./complex_numbers_test > complex_numbers_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm complex_numbers_test
#
echo "Normal end of execution."
