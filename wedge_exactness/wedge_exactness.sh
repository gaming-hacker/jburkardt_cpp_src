#! /bin/bash
#
g++ -c -Wall wedge_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ wedge_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm wedge_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/wedge_exactness
#
echo "Normal end of execution."
