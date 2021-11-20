#! /bin/bash
#
g++ -c -Wall -I/$HOME/include latin_center_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ latin_center_test.o /$HOME/libcpp/latin_center.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm latin_center_test.o
#
mv a.out latin_center_test
./latin_center_test > latin_center_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm latin_center_test
#
echo "Normal end of execution."
