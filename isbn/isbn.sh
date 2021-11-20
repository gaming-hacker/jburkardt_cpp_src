#! /bin/bash
#
cp isbn.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include isbn.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv isbn.o ~/libcpp/isbn.o
#
echo "Normal end of execution."
