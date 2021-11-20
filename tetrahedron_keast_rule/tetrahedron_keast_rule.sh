#! /bin/bash
#
cp tetrahedron_keast_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include tetrahedron_keast_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_keast_rule.o ~/libcpp/tetrahedron_keast_rule.o
#
echo "Normal end of execution."
