#! /bin/bash
#
cp test_lls.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_lls.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_lls.o ~/libcpp/test_lls.o
#
echo "Normal end of execution."
