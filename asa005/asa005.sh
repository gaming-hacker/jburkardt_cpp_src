#! /bin/bash
#
cp asa005.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa005.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa005.o ~/libcpp/asa005.o
#
echo "Normal end of execution."
