#! /bin/bash
#
cp asa310.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa310.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa310.o ~/libcpp/asa310.o
#
echo "Normal end of execution."
