#! /bin/bash
#
cp asa243.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa243.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa243.o ~/libcpp/asa243.o
#
echo "Normal end of execution."
