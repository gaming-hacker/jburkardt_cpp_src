#! /bin/bash
#
cp rkf45.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include rkf45.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv rkf45.o ~/libcpp/rkf45.o
#
echo "Normal end of execution."
