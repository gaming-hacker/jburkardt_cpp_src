#! /bin/bash
#
g++ -c -Wall -I/$HOME/include divdif_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ divdif_test.o /$HOME/libcpp/divdif.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm divdif_test.o
#
mv a.out divdif_test
./divdif_test > divdif_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm divdif_test
#
echo "Normal end of execution."
