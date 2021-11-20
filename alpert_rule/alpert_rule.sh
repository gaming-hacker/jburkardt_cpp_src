#! /bin/bash
#
cp alpert_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include alpert_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv alpert_rule.o ~/libcpp/alpert_rule.o
#
echo "Normal end of execution."
