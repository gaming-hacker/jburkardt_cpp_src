#! /bin/bash
#
cp asa103.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa103.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa103.o ~/libcpp/asa103.o
#
echo "Normal end of execution."
