#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ppma_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ppma_io_test.o /$HOME/libcpp/ppma_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm ppma_io_test.o
#
mv a.out ppma_io_test
./ppma_io_test > ppma_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ppma_io_test
#
echo "Normal end of execution."
