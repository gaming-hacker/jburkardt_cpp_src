#! /bin/bash
#
cp triangle_wandzura_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_wandzura_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_wandzura_rule.o ~/libcpp/triangle_wandzura_rule.o
#
echo "Normal end of execution."
