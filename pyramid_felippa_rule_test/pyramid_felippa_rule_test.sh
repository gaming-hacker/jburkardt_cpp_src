#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pyramid_felippa_rule_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pyramid_felippa_rule_test.o /$HOME/libcpp/pyramid_felippa_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pyramid_felippa_rule_test.o
#
mv a.out pyramid_felippa_rule_test
./pyramid_felippa_rule_test > pyramid_felippa_rule_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pyramid_felippa_rule_test
#
echo "Normal end of execution."
