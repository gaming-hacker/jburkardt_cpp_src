#! /bin/bash
#
cp normal.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include normal.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv normal.o ~/libcpp/normal.o
#
echo "Normal end of execution."
