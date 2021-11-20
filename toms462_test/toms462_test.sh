#! /bin/bash
#
g++ -c -Wall -I/$HOME/include toms462_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ toms462_test.o /$HOME/libcpp/toms462.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms462_test.o
#
mv a.out toms462_test
./toms462_test > toms462_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms462_test
#
echo "Normal end of execution."
