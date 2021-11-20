#! /bin/bash
#
g++ -c -Wall jacobi_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ jacobi_rule.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm jacobi_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/jacobi_rule
#
echo "Normal end of execution."
