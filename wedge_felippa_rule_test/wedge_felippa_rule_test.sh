#! /bin/bash
#
g++ -c -Wall -I/$HOME/include wedge_felippa_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o wedge_felippa_rule_test wedge_felippa_rule_test.o /$HOME/libcpp/wedge_felippa_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wedge_felippa_rule_test.o
#
./wedge_felippa_rule_test > wedge_felippa_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wedge_felippa_rule_test
#
echo "Normal end of execution."
