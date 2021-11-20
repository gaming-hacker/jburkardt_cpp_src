#! /bin/bash
#
cp condition.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include condition.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv condition.o ~/libcpp/condition.o
#
echo "Normal end of execution."
