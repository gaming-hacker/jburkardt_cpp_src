#! /bin/bash
#
cp r8col.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r8col.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8col.o ~/libcpp/r8col.o
#
echo "Normal end of execution."
