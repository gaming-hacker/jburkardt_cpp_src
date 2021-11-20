#! /bin/bash
#
g++ -c -Wall -I/$HOME/include niederreiter_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ niederreiter_test.o /$HOME/libcpp/niederreiter.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm niederreiter_test.o
#
mv a.out niederreiter_test
#
$HOME/bincpp/gfarit > niederreiter_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
$HOME/bincpp/gfplys >> niederreiter_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
./niederreiter_test >> niederreiter_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm niederreiter_test
#
echo "Normal end of execution."
