#! /bin/bash
#
cp laguerre_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include laguerre_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv laguerre_polynomial.o ~/libcpp/laguerre_polynomial.o
#
echo "Normal end of execution."
