#! /bin/bash
#
cp glomin.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include glomin.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv glomin.o ~/libcpp/glomin.o
#
echo "Normal end of execution."
