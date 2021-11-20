#! /bin/bash
#
g++ -c -Wall -I/$HOME/include clapack_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ clapack_test.o -L$HOME/libc -lclapack -lcblas -lf2c -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm clapack_test.o
#
mv a.out clapack_test
./clapack_test > clapack_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm clapack_test
#
echo "Normal end of execution."

