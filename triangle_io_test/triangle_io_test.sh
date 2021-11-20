#! /bin/bash
#
g++ -c -Wall -I$HOME/include triangle_io_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_io_test.o /$HOME/libcpp/triangle_io.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_io_test.o
#
mv a.out triangle_io_test
./triangle_io_test > triangle_io_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_io_test
#
echo "Normal end of execution."
