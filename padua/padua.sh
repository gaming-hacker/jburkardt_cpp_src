#! /bin/bash
#
cp padua.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include padua.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv padua.o ~/libcpp/padua.o
#
echo "Normal end of execution."
