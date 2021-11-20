#! /bin/bash
#
cp box_behnken.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include box_behnken.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv box_behnken.o ~/libcpp/box_behnken.o
#
echo "Normal end of execution."
