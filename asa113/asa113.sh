#! /bin/bash
#
cp asa113.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa113.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa113.o ~/libcpp/asa113.o
#
echo "Normal end of execution."
