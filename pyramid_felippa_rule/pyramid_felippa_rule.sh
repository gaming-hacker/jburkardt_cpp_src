#! /bin/bash
#
cp pyramid_felippa_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include pyramid_felippa_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv pyramid_felippa_rule.o ~/libcpp/pyramid_felippa_rule.o
#
echo "Normal end of execution."
