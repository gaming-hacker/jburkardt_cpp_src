#! /bin/bash
#
g++ -c -Wall laguerre_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ laguerre_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm laguerre_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/laguerre_exactness
#
echo "Normal end of execution."
