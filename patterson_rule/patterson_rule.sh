#! /bin/bash
#
g++ -c -Wall patterson_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ patterson_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm patterson_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/patterson_rule
#
echo "Normal end of execution."
