#! /bin/bash
#
g++ -c -Wall -I/$HOME/include stla_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ stla_io_test.o /$HOME/libcpp/stla_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stla_io_test.o
#
mv a.out stla_io_test
./stla_io_test > stla_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stla_io_test
#
echo "Normal end of execution."
