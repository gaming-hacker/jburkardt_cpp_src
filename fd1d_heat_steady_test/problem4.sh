#! /bin/bash
#
g++ -c -Wall -I$HOME/include problem4.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ problem4.o $HOME/libcpp/fd1d_heat_steady.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm problem4.o
#
mv a.out problem4
./problem4 > problem4.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem4
#
echo "Normal end of execution."
