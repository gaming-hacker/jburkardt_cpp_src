#! /bin/bash
#
g++ -c -Wall -I/$HOME/include halton_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o halton_test halton_test.o /$HOME/libcpp/halton.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm halton_test.o
#
./halton_test > halton_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm halton_test
#
echo "Normal end of execution."
