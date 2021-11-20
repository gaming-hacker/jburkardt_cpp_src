#! /bin/bash
#
cp line_nco_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include line_nco_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_nco_rule.o ~/libcpp/line_nco_rule.o
#
echo "Normal end of execution."
