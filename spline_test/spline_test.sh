#! /bin/bash
#
g++ -c -Wall -I/$HOME/include spline_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ spline_test.o /$HOME/libcpp/spline.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm spline_test.o
#
mv a.out spline_test
./spline_test > spline_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm spline_test
#
echo "Normal end of execution."
