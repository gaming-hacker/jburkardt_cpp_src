#! /bin/bash
#
cp toms743.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include toms743.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms743.o ~/libcpp/toms743.o
#
echo "Normal end of execution."
