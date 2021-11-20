#! /bin/bash
#
cp asa047.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa047.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa047.o ~/libcpp/asa047.o
#
echo "Normal end of execution."
