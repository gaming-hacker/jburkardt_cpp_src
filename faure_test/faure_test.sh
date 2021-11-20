#! /bin/bash
#
g++ -c -Wall -I/$HOME/include faure_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ faure_test.o /$HOME/libcpp/faure.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm faure_test.o
#
mv a.out faure_test
./faure_test > faure_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm faure_test
#
echo "Normal end of execution."
