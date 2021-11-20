#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cities_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cities_test.o /$HOME/libcpp/cities.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cities_test.o
#
mv a.out cities_test
./cities_test > cities_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cities_test
#
echo "Normal end of execution."
