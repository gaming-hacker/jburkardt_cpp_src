#! /bin/bash
#
cp differ.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include differ.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv differ.o ~/libcpp/differ.o
#
echo "Normal end of execution."
