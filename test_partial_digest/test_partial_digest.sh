#! /bin/bash
#
cp test_partial_digest.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include test_partial_digest.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv test_partial_digest.o ~/libcpp/test_partial_digest.o
#
echo "Normal end of execution."
