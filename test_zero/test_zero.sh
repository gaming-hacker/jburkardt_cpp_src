#! /bin/bash
#
cp test_zero.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_zero.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_zero.o ~/libcpp/test_zero.o
#
echo "Normal end of execution."
