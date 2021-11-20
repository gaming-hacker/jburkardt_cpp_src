#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cg_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cg_test.o /$HOME/libcpp/cg.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cg_test.o
#
mv a.out cg_test
./cg_test > cg_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cg_test
#
echo "Normal end of execution."
