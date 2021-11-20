#! /bin/bash
#
cp simplex_gm_rule.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include simplex_gm_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv simplex_gm_rule.o ~/libcpp/simplex_gm_rule.o
#
echo "Normal end of execution."
