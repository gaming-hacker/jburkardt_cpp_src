#! /bin/bash
#
g++ -c -Wall -I/$HOME/include lattice_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ lattice_rule_test.o /$HOME/libcpp/lattice_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm lattice_rule_test.o
#
mv a.out lattice_rule_test
./lattice_rule_test > lattice_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm lattice_rule_test
#
echo "Normal end of execution."
