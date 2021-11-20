#! /bin/bash
#
g++ -c -Wall -I/$HOME/include naca_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ naca_test.o /$HOME/libcpp/naca.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm naca_test.o
#
mv a.out naca_test
./naca_test > naca_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm naca_test
#
echo "Normal end of execution."
