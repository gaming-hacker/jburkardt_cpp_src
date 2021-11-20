#! /bin/bash
#
cp walker_sample.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include walker_sample.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv walker_sample.o ~/libcpp/walker_sample.o
#
echo "Normal end of execution."
