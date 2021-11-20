#! /bin/bash
#
cp asa063.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa063.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa063.o ~/libcpp/asa063.o
#
echo "Normal end of execution."
