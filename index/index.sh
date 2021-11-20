#! /bin/bash
#
cp index.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include index.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv index.o ~/libcpp/index.o
#
echo "Normal end of execution."
