#! /bin/bash
#
cp unicycle.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include unicycle.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv unicycle.o ~/libcpp/unicycle.o
#
echo "Normal end of execution."
