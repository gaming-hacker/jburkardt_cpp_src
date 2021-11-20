#! /bin/bash
#
cp timestamp.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include timestamp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv timestamp.o ~/libcpp/timestamp.o
#
echo "Normal end of execution."
