#! /bin/bash
#
cp asa266.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa266.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa266.o ~/libcpp/asa266.o
#
echo "Normal end of execution."
