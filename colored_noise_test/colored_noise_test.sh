#! /bin/bash
#
g++ -c -Wall -I/$HOME/include colored_noise_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ colored_noise_test.o /$HOME/libcpp/colored_noise.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm colored_noise_test.o
#
mv a.out colored_noise_test
./colored_noise_test > colored_noise_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm colored_noise_test
#
echo "Normal end of execution."
