#! /bin/bash
#
cp line_felippa_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include line_felippa_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_felippa_rule.o ~/libcpp/line_felippa_rule.o
#
echo "Normal end of execution."
