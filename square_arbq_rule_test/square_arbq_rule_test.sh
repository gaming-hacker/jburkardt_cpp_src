#! /bin/bash
#
g++ -c -Wall -I/$HOME/include square_arbq_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o square_arbq_rule_test square_arbq_rule_test.o /$HOME/libcpp/square_arbq_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm square_arbq_rule_test.o
#
./square_arbq_rule_test > square_arbq_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm square_arbq_rule_test
#
echo "Normal end of execution."
