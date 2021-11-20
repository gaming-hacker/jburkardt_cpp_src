#! /bin/bash
#
cp test_mat.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_mat.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_mat.o ~/libcpp/test_mat.o
#
echo "Normal end of execution."
