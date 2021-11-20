#! /bin/bash
#
cp toms178.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include toms178.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms178.o ~/libcpp/toms178.o
#
echo "Normal end of execution."
