#! /bin/bash
#
g++ -c -Wall gegenbauer_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gegenbauer_rule.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm gegenbauer_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/gegenbauer_rule
#
echo "Normal end of execution."
