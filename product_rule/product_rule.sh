#! /bin/bash
#
g++ -c -Wall -I$HOME/include product_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ product_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm product_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/product_rule
#
echo "Normal end of execution."
