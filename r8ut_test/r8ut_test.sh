#! /bin/bash
#
g++ -c -Wall -I/$HOME/include r8ut_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ r8ut_test.o /$HOME/libcpp/r8ut.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r8ut_test.o
#
mv a.out r8ut_test
./r8ut_test > r8ut_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8ut_test
#
echo "Normal end of execution."
