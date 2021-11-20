#! /bin/bash
#
g++ -c -Wall blas_osx_test.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
g++ blas_osx_test.o -lm -framework Accelerate
if [ $? -ne 0 ]; then
  echo "Load error."
  exit
fi
rm blas_osx_test.o
#
mv a.out blas_osx_test
./blas_osx_test > blas_osx_test.txt
if [ $? -ne 0 ]; then
  echo "Run error."
  exit
fi
rm blas_osx_test
#
echo "Normal end of execution."
