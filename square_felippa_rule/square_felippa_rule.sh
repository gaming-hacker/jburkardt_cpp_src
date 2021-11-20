#! /bin/bash
#
cp square_felippa_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include square_felippa_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_felippa_rule.o ~/libcpp/square_felippa_rule.o
#
echo "Normal end of execution."
