#! /bin/bash
#
cp floyd.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include floyd.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv floyd.o ~/libcpp/floyd.o
#
echo "Normal end of execution."
