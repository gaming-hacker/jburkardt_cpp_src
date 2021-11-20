#! /bin/bash
#
g++ -c -Wall -I/$HOME/include alpert_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o alpert_rule_test alpert_rule_test.o /$HOME/libcpp/alpert_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm alpert_rule_test.o
#
./alpert_rule_test > alpert_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm alpert_rule_test
#
echo "Normal end of execution."
