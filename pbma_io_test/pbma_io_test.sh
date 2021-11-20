#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pbma_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pbma_io_test.o /$HOME/libcpp/pbma_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pbma_io_test.o
#
mv a.out pbma_io_test
./pbma_io_test > pbma_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pbma_io_test
#
echo "Normal end of execution."
