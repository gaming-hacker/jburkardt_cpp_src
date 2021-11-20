#! /bin/bash
#
cp annulus_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include annulus_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv annulus_rule.o ~/libcpp/annulus_rule.o
#
echo "Normal end of execution."
