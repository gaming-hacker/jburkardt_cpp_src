#! /bin/bash
#
g++ -c -Wall -I/$HOME/include haar_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ haar_test.o /$HOME/libcpp/haar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm haar_test.o
#
mv a.out haar_test
./haar_test > haar_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm haar_test
#
echo "Normal end of execution."
