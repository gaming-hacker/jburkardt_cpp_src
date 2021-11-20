#! /bin/bash
#
g++ -c -Wall -I/$HOME/include stokes_2d_exact_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o stokes_2d_exact_test stokes_2d_exact_test.o /$HOME/libcpp/stokes_2d_exact.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stokes_2d_exact_test.o
#
./stokes_2d_exact_test > stokes_2d_exact_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stokes_2d_exact_test
#
echo "Normal end of execution."
