#! /bin/bash
#
g++ -c -Wall -I $HOME/include linpack_bench.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ linpack_bench.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm linpack_bench.o
#
chmod ugo+x a.out
mv a.out ~/bincpp/linpack_bench
#
echo "Normal end of execution."
