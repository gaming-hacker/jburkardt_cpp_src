#! /bin/bash
#
cp r8lib.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r8lib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8lib.o ~/libcpp/r8lib.o
#
echo "Normal end of execution."
