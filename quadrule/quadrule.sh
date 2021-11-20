#! /bin/bash
#
cp quadrule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include quadrule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv quadrule.o ~/libcpp/quadrule.o
#
echo "Normal end of execution."
