#! /bin/bash
#
g++ -c -Wall -I$HOME/include toms112_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ toms112_test.o /$HOME/libcpp/toms112.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm toms112_test.o
#
mv a.out toms112_test
./toms112_test > toms112_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm toms112_test
#
echo "Normal end of execution."
