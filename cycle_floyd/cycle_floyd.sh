#! /bin/bash
#
cp cycle_floyd.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cycle_floyd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cycle_floyd.o ~/libcpp/cycle_floyd.o
#
echo "Normal end of execution."
