#! /bin/bash
#
cp line_ncc_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include line_ncc_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_ncc_rule.o ~/libcpp/line_ncc_rule.o
#
echo "Normal end of execution."
