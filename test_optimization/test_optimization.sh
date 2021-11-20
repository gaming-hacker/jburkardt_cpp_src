#! /bin/bash
#
cp test_optimization.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_optimization.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_optimization.o ~/libcpp/test_optimization.o
#
echo "Normal end of execution."
