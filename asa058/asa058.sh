#! /bin/bash
#
cp asa058.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa058.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa058.o ~/libcpp/asa058.o
#
echo "Normal end of execution."
