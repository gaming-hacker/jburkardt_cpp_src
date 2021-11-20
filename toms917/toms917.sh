#! /bin/bash
#
cp toms917.hpp /$HOME/include
#
g++ -c -Wall -std=gnu++0x -I/$HOME/include toms917.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms917.o ~/libcpp/toms917.o
#
echo "Normal end of execution."
