#! /bin/bash
#
cp asa082.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include asa082.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv asa082.o ~/libcpp/asa082.o
#
echo "Normal end of execution."
