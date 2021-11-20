#! /bin/bash
#
g++ -c -Wall -O0 -I/$HOME/include machar_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ machar_test.o /$HOME/libcpp/machar.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm machar_test.o
#
mv a.out machar_test
./machar_test > machar_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm machar_test
#
echo "Normal end of execution."
