#! /bin/bash
#
g++ -c -Wall -I/$HOME/include crc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ crc_test.o /$HOME/libcpp/crc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm crc_test.o
#
mv a.out crc_test
./crc_test > crc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm crc_test
#
echo "Normal end of execution."
