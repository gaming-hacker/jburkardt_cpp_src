#! /bin/bash
#
cp asa226.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa226.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa226.o ~/libcpp/asa226.o
#
echo "Normal end of execution."
