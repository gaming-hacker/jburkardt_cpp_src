#! /bin/bash
#
cp random_data.hpp /$HOME/include
#
g++ -c -Wall random_data.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv random_data.o ~/libcpp/random_data.o
#
echo "Normal end of execution."
