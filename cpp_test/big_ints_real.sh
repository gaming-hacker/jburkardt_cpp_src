#! /bin/bash
#
g++ -c big_ints_real.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ big_ints_real.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm big_ints_real.o
#
mv a.out big_ints_real
./big_ints_real > big_ints_real.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm big_ints_real
#
echo "Normal end of execution."
