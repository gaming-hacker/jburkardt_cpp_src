#! /bin/bash
#
g++ -c -Wall -I/$HOME/include gegenbauer_cc_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o gegenbauer_cc_test gegenbauer_cc_test.o /$HOME/libcpp/gegenbauer_cc.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gegenbauer_cc_test.o
#
./gegenbauer_cc_test > gegenbauer_cc_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm gegenbauer_cc_test
#
echo "Normal end of execution."
