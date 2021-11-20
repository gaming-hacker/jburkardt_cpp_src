#! /bin/bash
#
g++ -c -Wall -I/$HOME/include bvec_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ bvec_test.o /$HOME/libcpp/bvec.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm bvec_test.o
#
mv a.out bvec_test
./bvec_test > bvec_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm bvec_test
#
echo "Normal end of execution."
