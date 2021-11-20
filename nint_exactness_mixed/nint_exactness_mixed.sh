#! /bin/bash
#
g++ -c -Wall -I$HOME/include nint_exactness_mixed.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ nint_exactness_mixed.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm nint_exactness_mixed.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/nint_exactness_mixed
#
echo "Normal end of execution."
