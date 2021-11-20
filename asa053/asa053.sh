#! /bin/bash
#
cp asa053.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include asa053.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa053.o ~/libcpp/asa053.o
#
echo "Normal end of execution."
