#! /bin/bash
#
g++ -c -Wall -I$HOME/include hypercube_exactness.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hypercube_exactness.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hypercube_exactness.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/hypercube_exactness
#
echo "Normal end of execution."
