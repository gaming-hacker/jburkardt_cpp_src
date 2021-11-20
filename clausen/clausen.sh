#! /bin/bash
#
cp clausen.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include clausen.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv clausen.o ~/libcpp/clausen.o
#
echo "Normal end of execution."
