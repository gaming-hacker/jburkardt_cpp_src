#! /bin/bash
#
cp asa121.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa121.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa121.o ~/libcpp/asa121.o
#
echo "Normal end of execution."
