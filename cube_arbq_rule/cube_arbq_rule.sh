#! /bin/bash
#
cp cube_arbq_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include cube_arbq_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cube_arbq_rule.o ~/libcpp/cube_arbq_rule.o
#
echo "Normal end of execution."
