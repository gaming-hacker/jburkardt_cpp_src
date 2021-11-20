#! /bin/bash
#
cp tetrahedron_nco_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include tetrahedron_nco_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_nco_rule.o ~/libcpp/tetrahedron_nco_rule.o
#
echo "Normal end of execution."
