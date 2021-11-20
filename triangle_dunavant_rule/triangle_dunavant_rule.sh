#! /bin/bash
#
cp triangle_dunavant_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_dunavant_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_dunavant_rule.o ~/libcpp/triangle_dunavant_rule.o
#
echo "Normal end of execution."
