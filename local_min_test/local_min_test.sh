#! /bin/bash
#
g++ -c -Wall -I/$HOME/include local_min_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ local_min_test.o /$HOME/libcpp/local_min.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm local_min_test.o
#
mv a.out local_min_test
./local_min_test > local_min_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm local_min_test
#
echo "Normal end of execution."
