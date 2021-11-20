#! /bin/bash
#
cp triangle_symq_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include triangle_symq_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_symq_rule.o ~/libcpp/triangle_symq_rule.o
#
echo "Normal end of execution."
