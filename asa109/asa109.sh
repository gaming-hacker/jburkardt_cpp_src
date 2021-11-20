#! /bin/bash
#
cp asa109.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa109.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa109.o ~/libcpp/asa109.o
#
echo "Normal end of execution."
