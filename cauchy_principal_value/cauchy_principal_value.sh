#! /bin/bash
#
cp cauchy_principal_value.hpp /$HOME/include
#
g++ -c -Wall -I/$HOME/include cauchy_principal_value.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv cauchy_principal_value.o ~/libcpp/cauchy_principal_value.o
#
echo "Normal end of execution."
