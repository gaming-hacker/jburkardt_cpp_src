#! /bin/bash
#
cp randlc.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include randlc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv randlc.o ~/libcpp/randlc.o
#
echo "Normal end of execution."
