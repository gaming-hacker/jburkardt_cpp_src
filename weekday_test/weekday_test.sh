#! /bin/bash
#
g++ -c -Wall -I/$HOME/include weekday_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ weekday_test.o /$HOME/libcpp/weekday.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm weekday_test.o
#
mv a.out weekday_test
./weekday_test > weekday_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm weekday_test
#
echo "Normal end of execution."
