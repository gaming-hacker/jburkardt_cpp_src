#! /bin/bash
#
cp r8lt.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r8lt.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8lt.o ~/libcpp/r8lt.o
#
echo "Normal end of execution."
