#! /bin/bash
#
g++ -c -Wall -I/$HOME/include r8col_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ r8col_test.o /$HOME/libcpp/r8col.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm r8col_test.o
#
mv a.out r8col_test
./r8col_test > r8col_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm r8col_test
#
echo "Normal end of execution."
