#! /bin/bash
#
cp quaternions.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include quaternions.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quaternions.o ~/libcpp/quaternions.o
#
echo "Normal end of execution."
