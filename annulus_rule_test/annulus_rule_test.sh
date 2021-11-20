#! /bin/bash
#
g++ -c -Wall -I/$HOME/include annulus_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o annulus_rule_test annulus_rule_test.o /$HOME/libcpp/annulus_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm annulus_rule_test.o
#
./annulus_rule_test > annulus_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm annulus_rule_test
#
echo "Normal end of execution."
