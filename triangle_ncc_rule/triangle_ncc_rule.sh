#! /bin/bash
#
cp triangle_ncc_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_ncc_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_ncc_rule.o ~/libcpp/triangle_ncc_rule.o
#
echo "Normal end of execution."
