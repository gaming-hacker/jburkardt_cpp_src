#! /bin/bash
#
g++ -c -Wall -I/$HOME/include sparse_display_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ -o sparse_display_test sparse_display_test.o /$HOME/libcpp/sparse_display.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm sparse_display_test.o
#
./sparse_display_test > sparse_display_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm sparse_display_test
#
echo "Normal end of execution."
