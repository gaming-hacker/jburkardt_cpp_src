#! /bin/bash
#
g++ -c -Wall -I$HOME/include blas2_s_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ blas2_s_test.o $HOME/libcpp/blas2_s.o $HOME/libcpp/blas0.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas2_s_test.o
#
mv a.out blas2_s_test
./blas2_s_test > blas2_s_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas2_s_test
#
echo "Normal end of execution."
