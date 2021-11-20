#! /bin/bash
#
cp r8ut.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r8ut.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8ut.o ~/libcpp/r8ut.o
#
echo "Normal end of execution."
