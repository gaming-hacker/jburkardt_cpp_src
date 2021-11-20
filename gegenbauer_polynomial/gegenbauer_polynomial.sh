#! /bin/bash
#
cp gegenbauer_polynomial.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include gegenbauer_polynomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv gegenbauer_polynomial.o ~/libcpp/gegenbauer_polynomial.o
#
echo "Normal end of execution."
