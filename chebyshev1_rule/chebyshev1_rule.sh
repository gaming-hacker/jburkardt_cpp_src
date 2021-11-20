#! /bin/bash
#
g++ -c -Wall chebyshev1_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ chebyshev1_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm chebyshev1_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/chebyshev1_rule
#
echo "Normal end of execution."
