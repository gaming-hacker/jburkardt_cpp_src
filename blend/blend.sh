#! /bin/bash
#
cp blend.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include blend.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv blend.o ~/libcpp/blend.o
#
echo "Normal end of execution."
