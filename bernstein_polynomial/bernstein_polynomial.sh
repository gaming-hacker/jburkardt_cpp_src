#! /bin/bash
#
cp bernstein_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include bernstein_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv bernstein_polynomial.o ~/libcpp/bernstein_polynomial.o
#
echo "Normal end of execution."
