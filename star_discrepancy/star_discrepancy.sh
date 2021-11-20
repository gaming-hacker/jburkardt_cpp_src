#! /bin/bash
#
g++ -c -Wall star_discrepancy.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ star_discrepancy.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm star_discrepancy.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/star_discrepancy
#
echo "Normal end of execution."
