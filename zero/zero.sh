#! /bin/bash
#
cp zero.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include zero.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv zero.o ~/libcpp/zero.o
#
echo "Normal end of execution."
