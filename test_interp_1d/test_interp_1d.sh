#! /bin/bash
#
cp test_interp_1d.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_interp_1d.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_interp_1d.o ~/libcpp/test_interp_1d.o
#
echo "Normal end of execution."
