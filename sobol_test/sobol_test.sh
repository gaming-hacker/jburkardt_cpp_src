#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sobol_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ sobol_test.o /$HOME/libcpp/sobol.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sobol_test.o
#
mv a.out sobol_test
./sobol_test > sobol_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sobol_test
#
echo "Normal end of execution."
