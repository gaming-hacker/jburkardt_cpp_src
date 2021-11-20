#! /bin/bash
#
cp line_fekete_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include line_fekete_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv line_fekete_rule.o ~/libcpp/line_fekete_rule.o
#
echo "Normal end of execution."
