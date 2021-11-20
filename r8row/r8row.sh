#! /bin/bash
#
cp r8row.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r8row.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r8row.o ~/libcpp/r8row.o
#
echo "Normal end of execution."
