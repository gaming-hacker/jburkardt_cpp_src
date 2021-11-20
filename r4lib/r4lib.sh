#! /bin/bash
#
cp r4lib.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include r4lib.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv r4lib.o ~/libcpp/r4lib.o
#
echo "Normal end of execution."
