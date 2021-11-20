#! /bin/bash
#
cp constants.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include constants.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv constants.o ~/libcpp/constants.o
#
echo "Normal end of execution."
