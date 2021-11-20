#! /bin/bash
#
g++ -c -Wall -I/$HOME/include test_approx_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ test_approx_test.o /$HOME/libcpp/test_approx.o /$HOME/libcpp/spline.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm test_approx_test.o
#
mv a.out test_approx_test
./test_approx_test > test_approx_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm  test_approx_test
#
echo "Normal end of execution."
