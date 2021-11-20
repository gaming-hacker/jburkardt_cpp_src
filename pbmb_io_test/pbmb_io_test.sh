#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pbmb_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pbmb_io_test.o /$HOME/libcpp/pbmb_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pbmb_io_test.o
#
mv a.out pbmb_io_test
./pbmb_io_test > pbmb_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pbmb_io_test
#
echo "Normal end of execution."
