#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cvt_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cvt_test.o /$HOME/libcpp/cvt.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cvt_test.o
#
mv a.out cvt_test
./cvt_test > cvt_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cvt_test
#
echo "Normal end of execution."
