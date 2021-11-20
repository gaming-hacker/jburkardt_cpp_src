#! /bin/bash
#
g++ -c -Wall -I/$HOME/include grf_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ grf_io_test.o /$HOME/libcpp/grf_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm grf_io_test.o
#
mv a.out grf_io_test
./grf_io_test > grf_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm grf_io_test
#
echo "Normal end of execution."
