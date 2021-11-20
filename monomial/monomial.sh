#! /bin/bash
#
cp monomial.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include monomial.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv monomial.o ~/libcpp/monomial.o
#
echo "Normal end of execution."
