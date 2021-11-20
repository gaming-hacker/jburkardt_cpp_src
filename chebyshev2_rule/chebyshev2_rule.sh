#! /bin/bash
#
g++ -c -Wall chebyshev2_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ chebyshev2_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm chebyshev2_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/chebyshev2_rule
#
echo "Normal end of execution."
