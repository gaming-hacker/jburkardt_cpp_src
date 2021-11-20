#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hermite_cubic_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hermite_cubic_test.o /$HOME/libcpp/hermite_cubic.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hermite_cubic_test.o
#
mv a.out hermite_cubic_test
./hermite_cubic_test > hermite_cubic_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hermite_cubic_test
#
echo "Normal end of execution."
