#! /bin/bash
#
cp r83.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r83.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r83.o ~/libcpp/r83.o
#
echo "Normal end of execution."
