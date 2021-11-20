#! /bin/bash
#
cp circle_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include circle_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv circle_rule.o ~/libcpp/circle_rule.o
#
echo "Normal end of execution."
