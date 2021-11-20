#! /bin/bash
#
cp haar.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include haar.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv haar.o ~/libcpp/haar.o
#
echo "Normal end of execution."
