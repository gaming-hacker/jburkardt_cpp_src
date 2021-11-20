#! /bin/bash
#
cp asa147.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa147.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa147.o ~/libcpp/asa147.o
#
echo "Normal end of execution."
