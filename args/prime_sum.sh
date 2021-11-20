#! /bin/bash
#
g++ -c -Wall prime_sum.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ prime_sum.o
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm prime_sum.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/prime_sum
#
echo "Normal end of execution."
