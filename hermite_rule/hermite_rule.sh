#! /bin/bash
#
g++ -c -Wall hermite_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hermite_rule.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hermite_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/hermite_rule
#
echo "Normal end of execution."
