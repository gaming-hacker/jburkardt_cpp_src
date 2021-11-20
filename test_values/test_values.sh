#! /bin/bash
#
cp test_values.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_values.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_values.o ~/libcpp/test_values.o
#
echo "Normal end of execution."
