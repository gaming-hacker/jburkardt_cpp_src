#! /bin/bash
#
cp asa241.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa241.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa241.o ~/libcpp/asa241.o
#
echo "Normal end of execution."
