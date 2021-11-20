#! /bin/bash
#
cp knapsack_01.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include knapsack_01.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv knapsack_01.o ~/libcpp/knapsack_01.o
#
echo "Normal end of execution."
