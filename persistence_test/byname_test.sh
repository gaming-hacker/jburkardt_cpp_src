#! /bin/bash
#
g++ -c -Wall -I/$HOME/include -Wall byname_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ byname_test.o /$HOME/libcpp/byname.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm byname_test.o
#
mv a.out byname_test
./byname_test > byname_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm byname_test
#
echo "Normal end of execution."
