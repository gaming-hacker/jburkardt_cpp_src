#! /bin/bash
#
g++ -c -Wall -I/$HOME/include st_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ st_io_test.o /$HOME/libcpp/st_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm st_io_test.o
#
mv a.out st_io_test
./st_io_test > st_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm st_io_test
#
echo "Normal end of execution."
