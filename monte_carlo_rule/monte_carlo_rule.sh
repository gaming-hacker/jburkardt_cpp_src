#! /bin/bash
#
g++ -c -Wall monte_carlo_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ monte_carlo_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm monte_carlo_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/monte_carlo_rule
#
echo "Normal end of execution."
