#! /bin/bash
#
cp asa159.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa159.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa159.o ~/libcpp/asa159.o
#
echo "Normal end of execution."
