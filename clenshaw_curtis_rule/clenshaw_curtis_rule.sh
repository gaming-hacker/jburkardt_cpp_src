#! /bin/bash
#
g++ -c -Wall clenshaw_curtis_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ clenshaw_curtis_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm clenshaw_curtis_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/clenshaw_curtis_rule
#
echo "Normal end of execution."
