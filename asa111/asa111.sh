#! /bin/bash
#
cp asa111.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa111.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa111.o ~/libcpp/asa111.o
#
echo "Normal end of execution."
