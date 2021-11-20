#! /bin/bash
#
g++ -c -Wall -I/$HOME/include wishart_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ wishart_test.o \
  /$HOME/libcpp/wishart.o \
  /$HOME/libcpp/pdflib.o \
  /$HOME/libcpp/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm wishart_test.o
#
mv a.out wishart_test
./wishart_test > wishart_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm wishart_test
#
echo "Normal end of execution."
