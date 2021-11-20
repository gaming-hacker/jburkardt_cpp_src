#! /bin/bash
#
cp asa007.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa007.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa007.o ~/libcpp/asa007.o
#
echo "Normal end of execution."
