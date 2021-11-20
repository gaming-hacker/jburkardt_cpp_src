#! /bin/bash
#
cp caesar.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include caesar.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv caesar.o ~/libcpp/caesar.o
#
echo "Normal end of execution."
