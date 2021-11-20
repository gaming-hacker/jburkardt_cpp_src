#! /bin/bash
#
cp prime.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include prime.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv prime.o ~/libcpp/prime.o
#
echo "Normal end of execution."
