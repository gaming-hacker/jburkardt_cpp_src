#! /bin/bash
#
cp asa245.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa245.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa245.o ~/libcpp/asa245.o
#
echo "Normal end of execution."
