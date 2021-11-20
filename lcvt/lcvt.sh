#! /bin/bash
#
cp lcvt.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include lcvt.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lcvt.o ~/libcpp/lcvt.o
#
echo "Normal end of execution."
