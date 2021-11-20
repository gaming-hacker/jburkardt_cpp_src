#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pink_noise_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pink_noise_test.o /$HOME/libcpp/pink_noise.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pink_noise_test.o
#
mv a.out pink_noise_test
./pink_noise_test > pink_noise_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pink_noise_test
#
echo "Normal end of execution."
