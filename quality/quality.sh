#! /bin/bash
#
cp quality.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include quality.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quality.o ~/libcpp/quality.o
#
echo "Normal end of execution."
