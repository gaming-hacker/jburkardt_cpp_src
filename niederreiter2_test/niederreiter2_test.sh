#! /bin/bash
#
g++ -c -Wall -I/$HOME/include niederreiter2_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ niederreiter2_test.o /$HOME/libcpp/niederreiter2.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm niederreiter2_test.o
#
mv a.out niederreiter2_test
./niederreiter2_test > niederreiter2_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm niederreiter2_test
#
echo "Normal end of execution."
