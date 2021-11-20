#! /bin/bash
#
g++ -c -Wall -I/$HOME/include triangle_interpolate_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o triangle_interpolate_test triangle_interpolate_test.o /$HOME/libcpp/triangle_interpolate.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_interpolate_test.o
#
./triangle_interpolate_test > triangle_interpolate_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_interpolate_test
#
echo "Normal end of execution."
