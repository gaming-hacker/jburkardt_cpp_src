#! /bin/bash
#
g++ -c -Wall -I/$HOME/include toms446_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ toms446_test.o /$HOME/libcpp/toms446.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms446_test.o
#
mv a.out toms446_test
./toms446_test > toms446_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms446_test
#
echo "Normal end of execution."
