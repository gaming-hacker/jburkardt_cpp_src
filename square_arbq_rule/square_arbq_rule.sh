#! /bin/bash
#
cp square_arbq_rule.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include square_arbq_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv square_arbq_rule.o ~/libcpp/square_arbq_rule.o
#
echo "Normal end of execution."
