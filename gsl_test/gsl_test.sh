#! /bin/bash
#
g++ -c -Wall gsl_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ gsl_test.o -lm -lgsl -lgslcblas
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
#
rm gsl_test.o
#
mv a.out gsl_test
./gsl_test > gsl_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm gsl_test
#
echo "Normal end of execution."
