#! /bin/bash
#
g++ -c -Wall gegenbauer_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gegenbauer_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm gegenbauer_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/gegenbauer_exactness
#
echo "Normal end of execution."
