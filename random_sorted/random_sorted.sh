#! /bin/bash
#
cp random_sorted.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include random_sorted.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv random_sorted.o ~/libcpp/random_sorted.o
#
echo "Normal end of execution."
