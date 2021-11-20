#! /bin/bash
#
g++ -c -Wall -I/$HOME/include llsq_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ llsq_test.o /$HOME/libcpp/llsq.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm llsq_test.o
#
mv a.out llsq_test
./llsq_test > llsq_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm llsq_test
#
echo "Normal end of execution."
