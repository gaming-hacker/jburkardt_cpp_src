#! /bin/bash
#
g++ -c -Wall laguerre_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ laguerre_rule.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm laguerre_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/laguerre_rule
#
echo "Normal end of execution."
