#! /bin/bash
#
g++ -c -Wall -I$HOME/include power_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ power_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm power_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/power_rule
#
echo "Normal end of execution."
