#! /bin/bash
#
g++ -c -Wall pyramid_rule.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pyramid_rule.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm pyramid_rule.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/pyramid_rule
#
echo "Normal end of execution."
