#! /bin/bash
#
cp toms243.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include toms243.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms243.o ~/libcpp/toms243.o
#
echo "Normal end of execution."
