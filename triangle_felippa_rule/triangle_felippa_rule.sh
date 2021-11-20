#! /bin/bash
#
cp triangle_felippa_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_felippa_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_felippa_rule.o ~/libcpp/triangle_felippa_rule.o
#
echo "Normal end of execution."
