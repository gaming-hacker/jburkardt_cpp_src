#! /bin/bash
#
cp i8lib.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include i8lib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv i8lib.o ~/libcpp/i8lib.o
#
echo "Normal end of execution."
