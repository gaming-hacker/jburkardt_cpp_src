#! /bin/bash
#
cp sine_transform.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include sine_transform.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv sine_transform.o ~/libcpp/sine_transform.o
#
echo "Normal end of execution."
