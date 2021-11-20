#! /bin/bash
#
g++ -c -Wall i2_binary_to_ascii.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ i2_binary_to_ascii.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm i2_binary_to_ascii.o
#
mv a.out ~/bincpp/i2_binary_to_ascii
#
echo "Normal end of execution."
