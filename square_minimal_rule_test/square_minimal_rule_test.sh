#! /bin/bash
#
g++ -c -Wall -I/$HOME/include square_minimal_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ square_minimal_rule_test.o /$HOME/libcpp/square_minimal_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm square_minimal_rule_test.o
#
mv a.out square_minimal_rule_test
./square_minimal_rule_test > square_minimal_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm square_minimal_rule_test
#
echo "Normal end of execution."
