#! /bin/bash
#
cp asa299.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa299.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa299.o ~/libcpp/asa299.o
#
echo "Normal end of execution."
