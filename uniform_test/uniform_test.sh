#! /bin/bash
#
g++ -c -Wall -I/$HOME/include uniform_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ uniform_test.o /$HOME/libcpp/uniform.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm uniform_test.o
#
mv a.out uniform_test
./uniform_test > uniform_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm uniform_test
#
echo "Normal end of execution."
