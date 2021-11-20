#! /bin/bash
#
g++ -c -Wall ccn_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ccn_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ccn_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/ccn_rule
#
echo "Normal end of execution."
