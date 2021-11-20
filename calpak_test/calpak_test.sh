#! /bin/bash
#
g++ -c -I/$HOME/include -Wall calpak_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ calpak_test.o /$HOME/libcpp/calpak.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm calpak_test.o
#
mv a.out calpak_test
./calpak_test > calpak_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm calpak_test
#
echo "Normal end of execution."
