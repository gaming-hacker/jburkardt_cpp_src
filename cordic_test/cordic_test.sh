#! /bin/bash
#
g++ -c -Wall -I/$HOME/include cordic_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ cordic_test.o /$HOME/libcpp/cordic.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm cordic_test.o
#
mv a.out cordic_test
./cordic_test > cordic_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm cordic_test
#
echo "Normal end of execution."
