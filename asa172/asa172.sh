#! /bin/bash
#
cp asa172.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa172.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa172.o ~/libcpp/asa172.o
#
echo "Normal end of execution."
