#! /bin/bash
#
cp pbma_io.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pbma_io.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pbma_io.o ~/libcpp/pbma_io.o
#
echo "Normal end of execution."
