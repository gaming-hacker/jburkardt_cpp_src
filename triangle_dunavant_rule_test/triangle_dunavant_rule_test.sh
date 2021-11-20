#! /bin/bash
#
g++ -c -Wall -I/$HOME/include triangle_dunavant_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ triangle_dunavant_rule_test.o /$HOME/libcpp/triangle_dunavant_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm triangle_dunavant_rule_test.o
#
mv a.out triangle_dunavant_rule_test
./triangle_dunavant_rule_test > triangle_dunavant_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm triangle_dunavant_rule_test
#
echo "Normal end of execution."
