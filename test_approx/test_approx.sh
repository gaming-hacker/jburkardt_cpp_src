#! /bin/bash
#
cp test_approx.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_approx.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_approx.o ~/libcpp/test_approx.o
#
echo "Normal end of execution."
