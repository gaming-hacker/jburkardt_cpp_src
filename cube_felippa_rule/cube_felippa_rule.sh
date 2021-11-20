#! /bin/bash
#
cp cube_felippa_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include cube_felippa_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_felippa_rule.o ~/libcpp/cube_felippa_rule.o
#
echo "Normal end of execution."
