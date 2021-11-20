#! /bin/bash
#
cp euler.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include euler.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv euler.o ~/libcpp/euler.o
#
echo "Normal end of execution."
