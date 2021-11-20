#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hankel_cholesky_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hankel_cholesky_test.o /$HOME/libcpp/hankel_cholesky.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hankel_cholesky_test.o
#
mv a.out hankel_cholesky_test
./hankel_cholesky_test > hankel_cholesky_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hankel_cholesky_test
#
echo "Normal end of execution."
