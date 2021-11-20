#! /bin/bash
#
cp test_int.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_int.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_int.o ~/libcpp/test_int.o
#
echo "Normal end of execution."
