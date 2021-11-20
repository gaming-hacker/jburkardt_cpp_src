#! /bin/bash
#
g++ -c -Wall -I/$HOME/include simplex_gm_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ simplex_gm_rule_test.o /$HOME/libcpp/simplex_gm_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm simplex_gm_rule_test.o
#
mv a.out simplex_gm_rule_test
./simplex_gm_rule_test > simplex_gm_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm simplex_gm_rule_test
#
echo "Normal end of execution."
