#! /bin/bash
#
cp cvt.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cvt.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cvt.o ~/libcpp/cvt.o
#
echo "Normal end of execution."
