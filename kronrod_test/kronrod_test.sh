#! /bin/bash
#
g++ -c -Wall -I/$HOME/include kronrod_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ kronrod_test.o /$HOME/libcpp/kronrod.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm kronrod_test.o
#
mv a.out kronrod_test
./kronrod_test > kronrod_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm kronrod_test
#
echo "Normal end of execution."
