#! /bin/bash
#
cp disk_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include disk_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv disk_rule.o ~/libcpp/disk_rule.o
#
echo "Normal end of execution."
