#! /bin/bash
#
cp cycle_brent.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cycle_brent.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cycle_brent.o ~/libcpp/cycle_brent.o
#
echo "Normal end of execution."
