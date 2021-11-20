#! /bin/bash
#
cp test_eigen.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_eigen.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv test_eigen.o ~/libcpp/test_eigen.o
#
echo "Normal end of execution."
