#! /bin/bash
#
cp toms446.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include toms446.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv toms446.o ~/libcpp/toms446.o
#
echo "Normal end of execution."
