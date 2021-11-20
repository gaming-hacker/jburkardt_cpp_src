#! /bin/bash
#
cp asa314.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include asa314.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa314.o ~/libcpp/asa314.o
#
echo "Normal end of execution."
