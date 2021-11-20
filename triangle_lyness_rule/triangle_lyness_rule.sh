#! /bin/bash
#
cp triangle_lyness_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_lyness_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_lyness_rule.o ~/libcpp/triangle_lyness_rule.o
#
echo "Normal end of execution."
