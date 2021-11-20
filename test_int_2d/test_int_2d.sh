#! /bin/bash
#
cp test_int_2d.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_int_2d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_int_2d.o ~/libcpp/test_int_2d.o
#
echo "Normal end of execution."
