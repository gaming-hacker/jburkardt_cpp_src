#! /bin/bash
#
g++ -c -Wall legendre_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ legendre_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm legendre_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/legendre_rule
#
echo "Normal end of execution."
