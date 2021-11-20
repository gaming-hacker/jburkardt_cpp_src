#! /bin/bash
#
cp asa144.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa144.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa144.o ~/libcpp/asa144.o
#
echo "Normal end of execution."
