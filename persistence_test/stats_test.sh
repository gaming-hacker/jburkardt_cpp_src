#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall stats_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ stats_test.o /$HOME/libcpp/stats.o /$HOME/libcpp/r8lib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm stats_test.o
#
mv a.out stats_test
./stats_test > stats_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm stats_test
#
echo "Normal end of execution."
