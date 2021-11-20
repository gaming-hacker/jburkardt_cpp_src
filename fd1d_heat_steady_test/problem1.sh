#! /bin/bash
#
g++ -c -Wall -I$HOME/include problem1.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ problem1.o $HOME/libcpp/fd1d_heat_steady.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm problem1.o
#
mv a.out problem1
./problem1 > problem1.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem1
#
echo "Normal end of execution."
