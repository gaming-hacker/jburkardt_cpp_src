#! /bin/bash
#
cp asa152.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa152.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa152.o ~/libcpp/asa152.o
#
echo "Normal end of execution."
