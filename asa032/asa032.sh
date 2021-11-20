#! /bin/bash
#
cp asa032.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa032.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa032.o ~/libcpp/asa032.o
#
echo "Normal end of execution."
