#! /bin/bash
#
g++ -c limits.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ limits.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm limits.o
#
mv a.out limits
./limits > limits.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm limits
#
echo "Normal end of execution."
