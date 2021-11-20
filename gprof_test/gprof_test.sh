#! /bin/bash
#
g++ -c -Wall -pg linpack_bench.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -pg linpack_bench.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm linpack_bench.o
#
mv a.out linpack_bench
#
./linpack_bench > linpack_bench.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
#
gprof linpack_bench >> gprof_test.txt
#
rm linpack_bench
rm gmon.out
#
echo "Normal end of execution."
