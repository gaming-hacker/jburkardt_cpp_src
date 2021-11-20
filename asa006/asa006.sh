#! /bin/bash
#
cp asa006.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa006.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa006.o ~/libcpp/asa006.o
#
echo "Normal end of execution."
