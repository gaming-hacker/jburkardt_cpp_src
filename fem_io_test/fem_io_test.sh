#! /bin/bash
#
g++ -c -Wall -I/$HOME/include fem_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ fem_io_test.o /$HOME/libcpp/fem_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm fem_io_test.o
#
mv a.out fem_io_test
./fem_io_test > fem_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm fem_io_test
#
echo "Normal end of execution."
