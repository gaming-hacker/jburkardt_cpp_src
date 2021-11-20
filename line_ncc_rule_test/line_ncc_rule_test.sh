#! /bin/bash
#
g++ -c -Wall -I/$HOME/include line_ncc_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ line_ncc_rule_test.o /$HOME/libcpp/line_ncc_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm line_ncc_rule_test.o
#
mv a.out line_ncc_rule_test
./line_ncc_rule_test > line_ncc_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm line_ncc_rule_test
#
echo "Normal end of execution."
