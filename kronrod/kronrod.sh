#! /bin/bash
#
cp kronrod.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include kronrod.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv kronrod.o ~/libcpp/kronrod.o
#
echo "Normal end of execution."
