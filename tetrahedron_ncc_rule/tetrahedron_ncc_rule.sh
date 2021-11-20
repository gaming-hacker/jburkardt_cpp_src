#! /bin/bash
#
cp tetrahedron_ncc_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include tetrahedron_ncc_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_ncc_rule.o ~/libcpp/tetrahedron_ncc_rule.o
#
echo "Normal end of execution."
