#! /bin/bash
#
cp set_theory.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include set_theory.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv set_theory.o ~/libcpp/set_theory.o
#
echo "Normal end of execution."
