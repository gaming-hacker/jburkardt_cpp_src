#! /bin/bash
#
cp monomial_value.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include monomial_value.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv monomial_value.o ~/libcpp/monomial_value.o
#
echo "Normal end of execution."
