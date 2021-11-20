#! /bin/bash
#
cp byname.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include byname.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv byname.o ~/libcpp/byname.o
#
echo "Normal end of execution."
