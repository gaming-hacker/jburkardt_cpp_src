#! /bin/bash
#
cp nintlib.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include nintlib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv nintlib.o ~/libcpp/nintlib.o
#
echo "Normal end of execution."
