#! /bin/bash
#
cp llsq.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include llsq.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv llsq.o ~/libcpp/llsq.o
#
echo "Normal end of execution."
