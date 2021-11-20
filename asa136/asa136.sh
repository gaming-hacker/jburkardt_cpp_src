#! /bin/bash
#
cp asa136.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa136.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa136.o ~/libcpp/asa136.o
#
echo "Normal end of execution."
