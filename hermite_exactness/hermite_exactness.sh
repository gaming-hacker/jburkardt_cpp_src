#! /bin/bash
#
g++ -c -Wall hermite_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hermite_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm hermite_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/hermite_exactness
#
echo "Normal end of execution."
