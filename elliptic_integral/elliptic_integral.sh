#! /bin/bash
#
cp elliptic_integral.hpp /$HOME/include
#
g++ -c -I/$HOME/include elliptic_integral.cpp
if [ $? -ne 0 ]; then
  echo "Compile error."
  exit
fi
#
mv elliptic_integral.o ~/libcpp/elliptic_integral.o
#
echo "Normal end of execution."
