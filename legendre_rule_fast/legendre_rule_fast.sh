#! /bin/bash
#
g++ -c -Wall legendre_rule_fast.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ legendre_rule_fast.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm legendre_rule_fast.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/legendre_rule_fast
#
echo "Normal end of execution."
