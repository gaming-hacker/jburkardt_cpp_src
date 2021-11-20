#! /bin/bash
#
cp triangle_fekete_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_fekete_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_fekete_rule.o ~/libcpp/triangle_fekete_rule.o
#
echo "Normal end of execution."
