#! /bin/bash
#
g++ -c -Wall -g truncated_normal_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ truncated_normal_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm truncated_normal_rule.o
mv a.out ~/bincpp/truncated_normal_rule
#
echo "Normal end of execution."
