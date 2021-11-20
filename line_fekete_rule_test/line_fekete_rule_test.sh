#! /bin/bash
#
g++ -c -Wall -I/$HOME/include line_fekete_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ line_fekete_rule_test.o /$HOME/libcpp/line_fekete_rule.o /$HOME/libcpp/qr_solve.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm line_fekete_rule_test.o
#
mv a.out line_fekete_rule_test
./line_fekete_rule_test > line_fekete_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_fekete_rule_test
#
echo "Normal end of execution."
