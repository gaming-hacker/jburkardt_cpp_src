#! /bin/bash
#
mpicxx -c -Wall -I/$HOME/include blacs_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mpicxx blacs_test.o -L/opt/local/lib -lscalapack
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm blacs_test.o
mv a.out blacs_test
#
./blacs_test < input.txt > blacs_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blacs_test
#
echo "Normal end of execution."

