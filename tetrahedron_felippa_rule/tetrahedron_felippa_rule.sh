#! /bin/bash
#
cp tetrahedron_felippa_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include tetrahedron_felippa_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv tetrahedron_felippa_rule.o ~/libcpp/tetrahedron_felippa_rule.o
#
echo "Normal end of execution."
