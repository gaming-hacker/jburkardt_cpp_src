#! /bin/bash
#
cp r8ge.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r8ge.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8ge.o ~/libcpp/r8ge.o
#
echo "Normal end of execution."
