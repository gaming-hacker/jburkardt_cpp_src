#! /bin/bash
#
cp asa239.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include asa239.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa239.o ~/libcpp/asa239.o
#
echo "Normal end of execution."
