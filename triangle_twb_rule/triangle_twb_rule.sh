#! /bin/bash
#
cp triangle_twb_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include triangle_twb_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv triangle_twb_rule.o ~/libcpp/triangle_twb_rule.o
#
echo "Normal end of execution."
