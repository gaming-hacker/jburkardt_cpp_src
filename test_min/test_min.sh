#! /bin/bash
#
cp test_min.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_min.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_min.o ~/libcpp/test_min.o
#
echo "Normal end of execution."
