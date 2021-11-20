#! /bin/bash
#
g++ -c -Wall -I/$HOME/include hankel_spd_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ hankel_spd_test.o /$HOME/libcpp/hankel_spd.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm hankel_spd_test.o
#
mv a.out hankel_spd_test
./hankel_spd_test > hankel_spd_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm hankel_spd_test
#
echo "Normal end of execution."
