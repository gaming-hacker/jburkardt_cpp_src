#! /bin/bash
#
g++ -c -Wall -I/$HOME/include pdflib_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ pdflib_test.o /$HOME/libcpp/pdflib.o /$HOME/libcpp/rnglib.o -lm
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm pdflib_test.o
#
mv a.out pdflib_test
./pdflib_test > pdflib_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm pdflib_test
#
echo "Normal end of execution."
