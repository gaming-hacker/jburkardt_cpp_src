#! /bin/bash
#
cp test_interp.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_interp.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_interp.o ~/libcpp/test_interp.o
#
echo "Normal end of execution."
