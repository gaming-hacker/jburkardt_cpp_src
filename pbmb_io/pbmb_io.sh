#! /bin/bash
#
cp pbmb_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pbmb_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pbmb_io.o ~/libcpp/pbmb_io.o
#
echo "Normal end of execution."
