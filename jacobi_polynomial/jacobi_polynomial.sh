#! /bin/bash
#
cp jacobi_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include jacobi_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv jacobi_polynomial.o ~/libcpp/jacobi_polynomial.o
#
echo "Normal end of execution."
