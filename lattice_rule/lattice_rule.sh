#! /bin/bash
#
cp lattice_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include lattice_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv lattice_rule.o ~/libcpp/lattice_rule.o
#
echo "Normal end of execution."
