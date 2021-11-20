#! /bin/bash
#
g++ -c -Wall -I/$HOME/include ornstein_uhlenbeck_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ ornstein_uhlenbeck_test.o /$HOME/libcpp/ornstein_uhlenbeck.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm ornstein_uhlenbeck_test.o
#
mv a.out ornstein_uhlenbeck_test
./ornstein_uhlenbeck_test > ornstein_uhlenbeck_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm ornstein_uhlenbeck_test
#
echo "Normal end of execution."
