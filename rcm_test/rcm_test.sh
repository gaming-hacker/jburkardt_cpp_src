#! /bin/bash
#
g++ -c -Wall -I/$HOME/include rcm_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ rcm_test.o /$HOME/libcpp/rcm.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm rcm_test.o
#
mv a.out rcm_test
./rcm_test > rcm_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm rcm_test
#
echo "Normal end of execution."
