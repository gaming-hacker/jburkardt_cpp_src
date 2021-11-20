#! /bin/bash
#
g++ -c -Wall -I$HOME/include blas3_s_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ blas3_s_test.o $HOME/libcpp/blas0.o $HOME/libcpp/blas3_s.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm blas3_s_test.o
#
mv a.out blas3_s_test
./blas3_s_test > blas3_s_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas3_s_test
#
echo "Normal end of execution."
