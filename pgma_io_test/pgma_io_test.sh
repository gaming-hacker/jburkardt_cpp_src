#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pgma_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pgma_io_test.o /$HOME/libcpp/pgma_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pgma_io_test.o
#
mv a.out pgma_io_test
./pgma_io_test > pgma_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pgma_io_test
#
echo "Normal end of execution."
