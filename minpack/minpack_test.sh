#! /bin/bash
#
g++ -c -Wall -I/$HOME/include minpack_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ minpack_test.o /$HOME/libcpp/minpack.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm minpack_test.o
#
mv a.out minpack_test
./minpack_test > minpack_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm minpack_test
#
echo "Normal end of execution."
