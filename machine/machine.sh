#! /bin/bash
#
cp machine.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include machine.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv machine.o ~/libcpp/machine.o
#
echo "Normal end of execution."
