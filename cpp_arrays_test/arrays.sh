#! /bin/bash
#
g++ -c -Wall arrays.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ arrays.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm arrays.o
#
mv a.out arrays
./arrays > arrays.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm arrays
#
echo "Normal end of execution."
