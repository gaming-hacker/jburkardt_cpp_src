#! /bin/bash
#
cp correlation.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include correlation.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv correlation.o ~/libcpp/correlation.o
#
echo "Normal end of execution."
