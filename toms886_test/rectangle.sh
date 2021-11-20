#! /bin/bash
#
g++ -c -Wall -I$HOME/include rectangle.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ rectangle.o $HOME/libcpp/toms886.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm rectangle.o
#
mv a.out rectangle
./rectangle > rectangle.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rectangle
#
echo "Normal end of execution."
