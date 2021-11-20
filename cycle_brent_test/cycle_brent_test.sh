#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cycle_brent_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cycle_brent_test.o /$HOME/libcpp/cycle_brent.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cycle_brent_test.o
#
mv a.out cycle_brent_test
./cycle_brent_test > cycle_brent_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cycle_brent_test
#
echo "Normal end of execution."
