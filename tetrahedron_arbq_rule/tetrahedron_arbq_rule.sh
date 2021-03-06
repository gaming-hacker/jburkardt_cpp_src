#! /bin/bash
#
cp tetrahedron_arbq_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include tetrahedron_arbq_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_arbq_rule.o ~/libcpp/tetrahedron_arbq_rule.o
#
echo "Normal end of execution."
