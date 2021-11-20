#! /bin/bash
#
cp upc.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include upc.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv upc.o ~/libcpp/upc.o
#
echo "Normal end of execution."
