#! /bin/bash
#
cp asa091.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa091.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa091.o ~/libcpp/asa091.o
#
echo "Normal end of execution."
