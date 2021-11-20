#! /bin/bash
#
g++ -c -Wall gen_laguerre_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gen_laguerre_rule.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm gen_laguerre_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/gen_laguerre_rule
#
echo "Normal end of execution."
