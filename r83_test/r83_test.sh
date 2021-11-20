#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall r83_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ r83_test.o /$HOME/libcpp/r83.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r83_test.o
#
mv a.out r83_test
./r83_test > r83_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r83_test
#
echo "Normal end of execution."
