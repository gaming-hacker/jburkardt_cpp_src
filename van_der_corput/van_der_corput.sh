#! /bin/bash
#
cp van_der_corput.hpp /$HOME/include
#
g++ -c -Wall -I /$HOME/include van_der_corput.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv van_der_corput.o ~/libcpp/van_der_corput.o
#
echo "Normal end of execution."
