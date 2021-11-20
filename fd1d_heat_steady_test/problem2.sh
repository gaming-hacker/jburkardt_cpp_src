#! /bin/bash
#
g++ -c -Wall -I$HOME/include problem2.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
g++ problem2.o $HOME/libcpp/fd1d_heat_steady.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm problem2.o
#
mv a.out problem2
./problem2 > problem2.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm problem2
#
echo "Normal end of execution."
