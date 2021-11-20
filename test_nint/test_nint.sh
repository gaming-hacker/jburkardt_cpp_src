#! /bin/bash
#
cp test_nint.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_nint.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_nint.o ~/libcpp/test_nint.o
#
echo "Normal end of execution."
