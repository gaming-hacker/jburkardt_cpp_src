#! /bin/bash
#
cp wedge_felippa_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include wedge_felippa_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv wedge_felippa_rule.o ~/libcpp/wedge_felippa_rule.o
#
echo "Normal end of execution."
