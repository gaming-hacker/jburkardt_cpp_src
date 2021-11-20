#! /bin/bash
#
cp toms515.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include toms515.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms515.o ~/libcpp/toms515.o
#
echo "Normal end of execution."
