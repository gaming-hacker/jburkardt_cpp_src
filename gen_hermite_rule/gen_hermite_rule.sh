#! /bin/bash
#
g++ -c -Wall gen_hermite_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gen_hermite_rule.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm gen_hermite_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/gen_hermite_rule
#
echo "Normal end of execution."
