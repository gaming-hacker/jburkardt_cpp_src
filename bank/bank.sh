#! /bin/bash
#
cp bank.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include bank.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bank.o ~/libcpp/bank.o
#
echo "Normal end of execution."
