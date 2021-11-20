#! /bin/bash
#
cp disk01_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include disk01_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk01_rule.o ~/libcpp/disk01_rule.o
#
echo "Normal end of execution."
