#! /bin/bash
#
cp exactness.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv exactness.o ~/libcpp/exactness.o
#
echo "Normal end of execution."
