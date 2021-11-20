#! /bin/bash
#
cp asa183.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa183.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa183.o ~/libcpp/asa183.o
#
echo "Normal end of execution."
