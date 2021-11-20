#! /bin/bash
#
cp faure.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include faure.cpp
if [ $? -ne 0 ]; then
  echo "Compile error"
  exit
fi
#
mv faure.o ~/libcpp/faure.o
#
echo "Normal end of execution."
