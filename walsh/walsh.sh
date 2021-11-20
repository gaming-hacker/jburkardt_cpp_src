#! /bin/bash
#
cp walsh.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include walsh.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv walsh.o ~/libcpp/walsh.o
#
echo "Normal end of execution."
